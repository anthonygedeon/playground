class Code
  attr_reader :master_code

  def initialize
    @master_code = (1..6).to_a.sample(4)
  end
 
  def exist_in_wrong_spot?(number)
    @master_code.include?(number)
  end

  def exist_in_correct_spot?(numbers)
  end

  private
end

def main
  code = Code.new
  puts "The computer has generated the code #{code.master_code}"

  loop do 
    puts "Type in four numbers (1-6) to guess the code"

    guess = gets.chomp.split('').map(&:to_i)
    
    guess.each do |number| 
      if code.exist_in_wrong_spot?(number)
        print "○"
      end
    end
    
    puts "Code: #{code.master_code} Guess: #{guess}"

    #puts "#{res} clues: #{clues}"

  end
end

main
