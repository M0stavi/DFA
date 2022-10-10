import java.io.*;

class DFA {
  public static void main(String U[]) {

    try {

      FileReader r = new FileReader("input.txt");
      int ch;
      String state = "start";
      File file = new File("output.txt");
      FileWriter fw = new FileWriter(file);
      PrintWriter pw = new PrintWriter(fw);
      while ((ch = r.read()) != -1) {

        char c = (char) ch;

        if (state == "start") {
          if ((c >= 'a') && (c <= 'z')) {

            int temp = c - 32;

            pw.print((char) temp);
            state = "inWord";
          } else if (c == ' ')
            state = "start";
          else if ((c >= 'A') && (c <= 'Z')) {

            pw.print(c);
            state = "inWord";
          } else if (c == '\n')
            state = "start";
        }

        else if (state == "inWord") {
          if ((c >= 'A') && (c <= 'Z')) {
            int temp = c + 32;

            pw.print((char) temp);
          }

          else if ((c >= 'a') && (c <= 'z'))

            pw.print(c);

          else if (c == ' ')
            state = "inSpace";

          else if (c == '\n')

            state = "inSpace";
          else if (c == ',')

          {

            pw.print(c);
            state = "inComma";
          } else if ((c == '.') || (c == '?') || (c == '!'))

          {

            pw.print(c);
            state = "inSentence";
          } else

            pw.print(c);
        }

        else if (state == "inSpace") {
          if ((c >= 'A') && (c <= 'Z') && (c != 'I')) {
            char c_sp = ' ';

            pw.print(c_sp);
            int temp = c + 32;

            pw.print((char) temp);
            state = "inWord";
          } else if ((c >= 'a') && (c <= 'z') && (c != 'i')) {
            char c_sp = ' ';

            pw.print(c_sp);

            pw.print(c);
            state = "inWord";
          } else if ((c == 'i') || (c == 'I')) {
            char c_sp = ' ';

            pw.print(c_sp);
            state = "decideI";
          } else if (c == ',')

          {

            pw.print(c);
            state = "inComma";
          }

          else if ((c == '.') || (c == '?') || (c == '!'))

          {

            pw.print(c);
            state = "inSentence";
          } else if (c == '\n')

            state = "inSpace";
          else if (c == ' ')

            state = "inSpace";

          else

            pw.print(c);
        }

        else if (state == "decideI") {
          if ((c >= 'A') && (c <= 'Z')) {
            char c_sp = 'i';

            pw.print(c_sp);
            int temp = c + 32;

            pw.print((char) temp);
            state = "inWord";
          } else if ((c >= 'a') && (c <= 'z')) {
            char c_sp = 'i';

            pw.print(c_sp);

            pw.print(c);
            state = "inWord";
          }

          else if (c == '\n') {
            char c_sp = 'I';

            pw.print(c_sp);
            state = "inSpace";
          } else if (c == ' ') {
            char c_sp = 'I';

            pw.print(c_sp);
            state = "inSpace";
          }

          else if (c == ',') {

            pw.print(c);
            state = "inComma";
          }

          else if ((c == '.') || (c == '?') || (c == '!'))

          {

            pw.print(c);
            state = "inSentence";
          }

          else

            pw.print(c);
        }

        else if (state == "inComma") {
          if ((c >= 'A') && (c <= 'Z')) {
            char c_sp = ' ';

            pw.print(c_sp);
            int temp = c + 32;

            pw.print((char) temp);
            state = "inWord";
          } else if ((c >= 'a') && (c <= 'z')) {
            char c_sp = ' ';

            pw.print(c_sp);

            pw.print(c);
            state = "inWord";
          }

          else if (c == '\n')

            state = "inSpace";
          else if (c == ' ')

            state = "inSpace";

          else

            pw.print(c);
        }

        else if (state == "inSentence") {
          if (c == '\n')

          {
            pw.print(c);
            state = "start";
          } else {
            char c_p = ' ';

            pw.print(c_p);
            state = "start";
          }
        }

      }
    
      pw.close();
    } catch (Exception e) {
    }
  }
}