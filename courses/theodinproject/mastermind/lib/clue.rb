class Clue 
  #
  def self.make(code, guess)
    code.each_index do |i|
      if code[i] == guess[i]
        code[i]  = :fill 
        guess[i] = :fill 
      end
    end
    
    guess.each_with_index do |g_val, i| 
      code.each_with_index do |c_val, j|
        if g_val == c_val && j != i && g_val != :fill
          code[j] = :empty
          break
        end
      end
    end

    code.reject{ |item| item.is_a? Numeric }
  end

  private 

end
