/*There are mainly 6 states in the DFA: start, inWord, inSpace, decideI,
inComma, inSentence

start:
-indicates starting of a new sentence,
-if there are unnecessary spaces or new lines, they are removed
- beginning of a sentence is capitalized.

Input:				transition:
 “space”/”newline”     -		start state
ASCII		          -		inWord state
inWord:
        -builds up words properly

Input:				transition:
 “space”/”newline”     -		inSpace state
ASCII		          -		inWord state
‘,’		          -   	inComma state
‘.’/’?’/’!’                       -    	inSentence state

inSpace:
        -ensures removal of unnecessary spaces and also use of proper spaces
        -pre-stage for deciding capitalization of the character ‘i’

Input:				transition:
 “space”/”newline”          -	inSpace state
ASCII(except for ‘i’ or ‘I’)-	inWord state
‘i’ or ‘I’		              -    	decideI state
‘.’/’?’/’!’                          -    	inSentence state
‘,’			  -	inComma

decideI:
        -ensures proper capitalization, punctuation and spacing after each ‘i’
or ‘I’

Input:				transition:
 “space”/”newline”          -	inSpace state(capital I)
ASCII			   -	inWord state(small i)
‘.’/’?’/’!’                          -    	inSentence state
‘,’			  -	inComma state
inComma:
        -ensures ‘,’ is placed properly and there is necessary space


Input:				transition:
 “space”/”newline”          -	inSpace state
ASCII			   -	inWord state
inSentence:
        -ensures there is proper punctuation at the end of each sentence

Input:				transition:
 “”newline”          -	            start state(with a newline)
other			   -	start state(without a newline)*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  fstream infile, outfile;
  outfile.open("ouput.txt", ios::out);
  ifstream f("input.txt"); // taking file as inputstream
  string str, state = "start";
  if (f) {
    ostringstream ss;
    ss << f.rdbuf(); // reading data
    str = ss.str();
  }
  for (int i = 0; i < str.size(); i++) {

    char c = str[i];

    if (state == "start") // entering start state
    {
      if ((c >= 'a') && (c <= 'z')) {

        int temp = c - 32;

        outfile << (char)temp; // placing proper character
        state = "inWord";      // transition from start state to inWord state
      } else if (c == ' ')
        state = "start";
      else if ((c >= 'A') && (c <= 'Z')) {

        outfile << c;     // placing proper character
        state = "inWord"; // transition from start state to inWord state
      } else if (c == '\n')
        state = "start"; // transition from start state to start state
    }

    else if (state == "inWord") // entering inWord state
    {
      if ((c >= 'A') && (c <= 'Z')) {
        int temp = c + 32;

        outfile << (char)temp; // building up word
      }

      else if ((c >= 'a') && (c <= 'z'))

        outfile << c; // building up word

      else if (c == ' ')
        state = "inSpace"; // transition from inWord state to inSpace state

      else if (c == '\n')

        state = "inSpace"; // transition from inWord state to inSpace state
      else if (c == ',')

      {

        outfile << c;
        state = "inComma"; // transition from inWord state to inComma state
      } else if ((c == '.') || (c == '?') || (c == '!'))

      {

        outfile << c;
        state = "inSentence"; // transition from inWord state to inSentence
                              // state
      } else

        outfile << c;
    }

    else if (state == "inSpace") // entering inSpace state
    {
      if ((c >= 'A') && (c <= 'Z') && (c != 'I')) {
        char c_sp = ' ';

        outfile << c_sp; // ensuring proper spacing
        int temp = c + 32;

        outfile << (char)temp; // start of word
        state = "inWord";      // transition from inSpace state to inWord state
      } else if ((c >= 'a') && (c <= 'z') && (c != 'i')) {
        char c_sp = ' ';

        outfile << c_sp; // ensuring proper spacing

        outfile << c;     // start of word
        state = "inWord"; // transition from inSpace state to inWord state
      } else if ((c == 'i') || (c == 'I')) {
        char c_sp = ' ';

        outfile << c_sp;   // ensuring proper spacing
        state = "decideI"; // transition from inSpace state to decideI state
      } else if (c == ',')

      {

        outfile << c;
        state = "inComma"; // transition from inSpace state to inComma state
      }

      else if ((c == '.') || (c == '?') || (c == '!'))

      {

        outfile << c; // ensuring punctutation
        state =
            "inSentence"; // transition from inSpace state to inSentence state
      } else if (c == '\n')

        state = "inSpace"; // transition from inSpace state to inSpace state
      else if (c == ' ')

        state = "inSpace"; // transition from inSpace state to inSpace state

      else

        outfile << c;
    }

    else if (state == "decideI") // entering decideI state
    {
      if ((c >= 'A') && (c <= 'Z')) {
        char c_sp = 'i';

        outfile << c_sp; // small i
        int temp = c + 32;

        outfile << (char)temp; // start of word
        state = "inWord";      // transition from decideI state to inWord state
      } else if ((c >= 'a') && (c <= 'z')) {
        char c_sp = 'i';

        outfile << c_sp; // small i

        outfile << c;     // start of word
        state = "inWord"; // transition from decideI state to inWord state
      }

      else if (c == '\n') {
        char c_sp = 'I';

        outfile << c_sp;   // capital I
        state = "inSpace"; // transition from decideI state to inSpace state
      } else if (c == ' ') {
        char c_sp = 'I';

        outfile << c_sp;   // capital I
        state = "inSpace"; // transition from decideI state to inSpace state
      }

      else if (c == ',') {
        outfile << c;

        state = "inComma"; // transition from decideI state to inComma state
      }

      else if ((c == '.') || (c == '?') || (c == '!'))

      {

        outfile << c; // punctuation
        state =
            "inSentence"; // transition from decideI state to inSentence state
      }

      else

        outfile << c;
    }

    else if (state == "inComma") // entering inComma state
    {
      if ((c >= 'A') && (c <= 'Z')) {
        char c_sp = ' ';

        outfile << c_sp; // proper spacing
        int temp = c + 32;

        outfile << (char)temp; // start of word
        state = "inWord";      // transition from inComma state to inWord state
      } else if ((c >= 'a') && (c <= 'z')) {
        char c_sp = ' ';

        outfile << c_sp; // proper spacing

        outfile << c;     // start of word
        state = "inWord"; // transition from inComma state to inWord state
      }

      else if (c == '\n')

        state = "inSpace"; // transition from inComma state to inSpace state
      else if (c == ' ')

        state = "inSpace"; // transition from inComma state to inSpace state

      else

        outfile << c;
    }

    else if (state == "inSentence") {
      if (c == '\n')

      {

        outfile << c; // printing newline if there is a new line after end of
                      // sentence

        state = "start"; // transition from inSentence state to start state
      } else {
        char c_p = ' ';

        outfile << c_p;  // proper spacing after end of sentence
        state = "start"; // transition from inSentence state to start state
      }
    }
  }
  outfile.close();
}
