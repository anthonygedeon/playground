class Clue 
  def self.make(code, guess)
    secret = code.clone
    secret.each_index do |i|
      if secret[i] == guess[i]
        secret[i]  = :fill 
        guess[i] = :fill 
      end
    end
    
    guess.each_with_index do |g_val, i| 
      secret.each_with_index do |c_val, j|
        if g_val == c_val && j != i && g_val != :fill
          secret[j] = :empty
          break
        end
      end
    end

    pp "secret: #{secret}"

    secret.reject{ |item| item.is_a? Numeric }
  end

  private 
end
