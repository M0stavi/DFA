state = 'start'

OutputFile = File.open('output.txt', 'w')
File.open('input.txt', 'r') do |f|
  f.each_char do |c|
    case state
    when 'start'

      if (c >= 'a') && (c <= 'z')
        temp = c.ord - 32
        # a for append
        File.write('output.txt', temp.chr, mode: 'a')
        state = 'inWord'
      elsif c == ' '

        state = 'start'
      elsif (c >= 'A') && (c <= 'Z')
        File.write('output.txt', c, mode: 'a')
        state = 'inWord'
      elsif c == "\n"
        state = 'start'
      end

    when 'inWord'
      if (c >= 'A') && (c <= 'Z')
        temp = c.ord + 32
        File.write('output.txt', temp.chr, mode: 'a')

      elsif (c >= 'a') && (c <= 'z')
        File.write('output.txt', c, mode: 'a')

      elsif c == ' '
        state = 'inSpace'

      elsif c == "\n"
        # c_sp = ' '
        # File.write('output.txt', c_sp, mode: 'a')

        state = 'inSpace'
      elsif c == ','
        File.write('output.txt', c, mode: 'a')
        state = 'inComma'
      elsif (c == '.') || (c == '?') || (c == '!')
        File.write('output.txt', c, mode: 'a')
        state = 'inSentence'
      else

        File.write('output.txt', c, mode: 'a')
      end
    when 'inSpace'
      if (c >= 'A') && (c <= 'Z') && (c != 'I')
        c_sp = ' '
        File.write('output.txt', c_sp, mode: 'a')
        temp = c.ord + 32
        File.write('output.txt', temp.chr, mode: 'a')
        state = 'inWord'
      elsif (c >= 'a') && (c <= 'z') && (c != 'i')
        c_sp = ' '
        File.write('output.txt', c_sp, mode: 'a')
        File.write('output.txt', c, mode: 'a')
        state = 'inWord'
      elsif (c == 'i') || (c == 'I')
        c_sp = ' '
        File.write('output.txt', c_sp, mode: 'a')
        state = 'decideI'
      elsif c == ','
        File.write('output.txt', c, mode: 'a')
        state = 'inComma'

      elsif (c == '.') || (c == '?') || (c == '!')
        File.write('output.txt', c, mode: 'a')
        state = 'inSentence'
      elsif c == "\n"

        state = 'inSpace'
      elsif c == ' '

        state = 'inSpace'

      else

        File.write('output.txt', c, mode: 'a')
      end

    when 'decideI'
      if (c >= 'A') && (c <= 'Z')
        c_sp = 'i'
        File.write('output.txt', c_sp, mode: 'a')
        temp = c.ord + 32
        File.write('output.txt', temp.chr, mode: 'a')
        state = 'inWord'
      elsif (c >= 'a') && (c <= 'z')
        c_sp = 'i'
        File.write('output.txt', c_sp, mode: 'a')
        File.write('output.txt', c, mode: 'a')
        state = 'inWord'

      elsif c == "\n"
        c_sp = 'I'
        File.write('output.txt', c_sp, mode: 'a')
        state = 'inSpace'
      elsif c == ' '
        c_sp = 'I'
        File.write('output.txt', c_sp, mode: 'a')
        state = 'inSpace'

      elsif c == ','
        File.write('output.txt', c, mode: 'a')
        state = 'inComma'
      elsif (c == '.') || (c == '?') || (c == '!')
        File.write('output.txt', c, mode: 'a')
        state = 'inSentence'

      else

        File.write('output.txt', c, mode: 'a')
      end

    when 'inComma'
      if (c >= 'A') && (c <= 'Z')
        c_sp = ' '
        File.write('output.txt', c_sp, mode: 'a')
        temp = c.ord + 32
        File.write('output.txt', temp.chr, mode: 'a')
        state = 'inWord'
      elsif (c >= 'a') && (c <= 'z')
        c_sp = ' '
        File.write('output.txt', c_sp, mode: 'a')
        File.write('output.txt', c, mode: 'a')
        state = 'inWord'

      elsif c == "\n"

        state = 'inSpace'
      elsif c == ' '

        state = 'inSpace'

      else

        File.write('output.txt', c, mode: 'a')
      end

    when 'inSentence'
      if c == "\n"
        File.write('output.txt', c, mode: 'a')
        state = 'start'
      else
        c_p = ' '
        File.write('output.txt', c_p, mode: 'a')
        state = 'start'
      end

      # etc...
    else
      'error'
    end
  end
end
