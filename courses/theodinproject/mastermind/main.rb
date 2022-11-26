class Code
  attr_reader :master_code
  
  def initialize
    #@master_code = (1..6).to_a.sample(4)
    @master_code = [1, 2, 1, 4]
  end

  def create_clues_from(guess)
    clues = ("● " * tally_correct_spots(guess)) + ("○ " * tally_wrong_spots(guess))
    clues
  end

  private

  #
  def tally_wrong_spots(guess)
    # the individual number from `guess` exist in @master_code 
    # do not count a empty circle if the number is in the correct spot
    # repeated number in guess should not generate more empty circles
      # i.e Master Code: 1214 Guess: 3111 Answer: ○ ○ ○  which is wrong, it should be ○ ○ 
    count_wrong_spots = 0
    master_code_clone = @master_code.clone
    pp guess
    @master_code.each_index do |idx|
      # delete the numbers that are already in the right spot
      master_code_clone.each_index { |cidx| pp "#{master_code_clone[cidx]},  #{guess[cidx]}"; master_code_clone.delete_at(cidx) if master_code_clone[cidx] == guess[cidx] }
      pp master_code_clone

      if master_code_clone.include?(guess[idx]) 
        count_wrong_spots += 1
      end

    end
    master_code_clone = @master_code
    count_wrong_spots 
  end
  
  # 
  def tally_correct_spots(guess)
    count_correct_spots = 0
    @master_code.each_index { |idx| count_correct_spots += 1 if @master_code[idx] == guess[idx] }
    count_correct_spots
  end

end

def main
  code = Code.new
  puts "The computer has generated the code #{code.master_code}"

  loop do 
    puts "Type in four numbers (1-6) to guess the code"

    guess = gets.chomp.split('').map(&:to_i)

    puts "#{guess} clues: #{code.create_clues_from(guess)}"
  end

end

main
