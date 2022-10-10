state = "start"
outfile = open("output.txt", "w")

infile = open("input.txt", "r")

str = infile.read()

infile.close()



for c in str:

  if state == "start":
    if (c >= 'a') and (c <= 'z'):
      temp = ord(c) - 32

      outfile.write(chr(temp))
      state = 'inWord'
    elif c == ' ':

      state = 'start'
    elif (c >= 'A') and (c <= 'Z'):

      outfile.write(c)
      state = 'inWord'
    elif c == "\n":
      state = 'start'

  elif state == "inWord":
    if (c >= 'A') and (c <= 'Z'):
      temp = ord(c) + 32

      outfile.write(chr(temp))

    elif (c >= 'a') and (c <= 'z'):

      outfile.write(c)

    elif c == ' ':
      state = 'inSpace'

    elif c == "\n":

      state = 'inSpace'
    elif c == ',':

      outfile.write(c)
      state = 'inComma'
    elif (c == '.') or (c == '?') or (c == '!'):

      outfile.write(c)
      state = 'inSentence'
    else:

      outfile.write(c)
  elif state == "inSpace":
    if (c >= 'A') and (c <= 'Z') and (c != 'I'):
      c_sp = ' '

      outfile.write(c_sp)
      temp = ord(c) + 32

      outfile.write(chr(temp))
      state = 'inWord'
    elif (c >= 'a') and (c <= 'z') and (c != 'i'):
      c_sp = ' '

      outfile.write(c_sp)

      outfile.write(c)
      state = 'inWord'
    elif (c == 'i') or (c == 'I'):
      c_sp = ' '

      outfile.write(c_sp)
      state = 'decideI'
    elif c == ',':

      outfile.write(c)
      state = 'inComma'

    elif (c == '.') or (c == '?') or (c == '!'):

      outfile.write(c)
      state = 'inSentence'
    elif c == "\n":

      state = 'inSpace'
    elif c == ' ':

      state = 'inSpace'

    else:

      outfile.write(c)
  elif state == "decideI":
    if (c >= 'A') and (c <= 'Z'):
      c_sp = 'i'

      outfile.write(c_sp)
      temp = ord(c) + 32

      outfile.write(chr(temp))
      state = 'inWord'
    elif (c >= 'a') and (c <= 'z'):
      c_sp = 'i'

      outfile.write(c_sp)

      outfile.write(c)
      state = 'inWord'

    elif c == "\n":
      c_sp = 'I'

      outfile.write(c_sp)
      state = 'inSpace'
    elif c == ' ':
      c_sp = 'I'

      outfile.write(c_sp)
      state = 'inSpace'
    elif c == ',':
      outfile.write(c)
      state = "inComma"
    
    elif (c == '.') or (c == '?') or (c == '!'):

      outfile.write(c)
      state = 'inSentence'

    else:

      outfile.write(c)
  elif state == "inComma":
    if (c >= 'A') and (c <= 'Z'):
      c_sp = ' '

      outfile.write(c_sp)
      temp = ord(c) + 32

      outfile.write(chr(temp))
      state = 'inWord'
    elif (c >= 'a') and (c <= 'z'):
      c_sp = ' '

      outfile.write(c_sp)

      outfile.write(c)
      state = 'inWord'

    elif c == "\n":

      state = 'inSpace'
    elif c == ' ':

      state = 'inSpace'

    else:

      outfile.write(c)
  elif state == "inSentence":
    if c == "\n":

      outfile.write(c)
      state = "start"
    else:
      c_p = ' '

      outfile.write(c_p)
      state = 'start'

outfile.close()


