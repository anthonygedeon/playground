require 'rainbow'

class Code
  attr_reader :master_code

  def initialize
    #@master_code = (1..6).to_a.sample(4)
    @master_code = [1, 3, 4, 1]
  end

  def create_clues_from(guess)
    correct_spots = tally_correct_spots(guess)
    wrong_spots = tally_wrong_spots(guess).count :empty
    clues = ("● " * correct_spots) + ("○ " * wrong_spots)
    clues
  end

  private

  #
  def tally_wrong_spots(guess)
    # the individual number from `guess` exist in @master_code 
    # do not count a empty circle if the number is in the correct spot
    # repeated number in guess should not generate more empty circles
      # i.e Master Code: 1214 Guess: 3111 Answer: ○ ○ ○  which is wrong, it should be ○ ○ 
    correct_spots_code = @master_code.clone

    # 1. discard any matched numbers and update array with :fill symbol
    guess.each_with_index do |guess_val, guess_idx| 
      @master_code.each_with_index do |code_val, code_idx|
        if guess_val == code_val  && code_idx == guess_idx
          correct_spots_code[code_idx] = :fill
          guess[code_idx] = :fill
        end
      end
    end
    
    guess.each_with_index do |guess_val, guess_idx| 
      correct_spots_code.each_with_index do |code_val, code_idx|
        if guess_val == code_val && code_idx != guess_idx && guess_val != :fill
          correct_spots_code[code_idx] = :empty
          next
        end
      end
    end

    p "Spots: #{correct_spots_code}"

    correct_spots_code
  end
  
  # 
  def tally_correct_spots(guess)
    count_correct_spots = 0
    @master_code.each_index { |idx| count_correct_spots += 1 if @master_code[idx] == guess[idx] }
    count_correct_spots
  end

end

class Game
  
  def initialize
    @code = Code.new
  end

  def draw
    self.begin_tutorial
  end

  def update
    puts "The computer has set the 'master code' and now it's time for you to break the code."
    puts "[DEBUG] Master Code: #{@code.master_code}"
    puts 

    current_turn = 1

    loop do
      puts "Turn ##{current_turn}: Type in four numbers (1-6) to guess the code, or 'q' to quit game."

      guess = gets.chomp.split('').map(&:to_i)

      puts "#{guess} clues: #{@code.create_clues_from(guess)}"
      
      if current_turn == 12
        self.game_over
        puts 
        self.try_again
      end

      current_turn += 1
    end
  end

  private 

  def try_again
    puts "Do you want to play again? Press 'y' for yes (or any other key for no)."
    gets
  end

  def game_over
    puts Rainbow("Game over. That was a hard code to break! ¯\\_(ツ)_/¯").red
    puts
    puts "Here is the 'master code' that you were trying to break:"
    puts "#{@code.master_code}"
  end

  def begin_tutorial
    puts 
    puts Rainbow("How to play Mastermind:").underline
    puts "This is a 1-player game against the computer."
    puts "You can choose to be the code #{Rainbow("maker").underline} or the code #{Rainbow("breaker").underline}."
    puts
    puts "There are six different number/color combinations:" 
    puts "#{Rainbow("  1  ").bg(:khaki)} \
#{Rainbow("  2  ").bg(:maroon)} \
#{Rainbow("  3  ").bg(:blue)} \
#{Rainbow("  4  ").bg(:pink)} \
#{Rainbow("  5  ").bg(:webpurple)} \
#{Rainbow("  6  ").bg(:plum)}"
    puts
    puts "The code maker will choose four to create a 'master code'. For example,"

    puts "#{Rainbow("  1  ").bg(:khaki)} \
#{Rainbow("  3  ").bg(:blue)} \
#{Rainbow("  4  ").bg(:pink)} \
#{Rainbow("  1  ").bg(:khaki)}"

    puts "As you can see, there can be #{Rainbow("more then one").red} of the same number/color."
    puts "In order to win, the code breaker needs to guess the 'master code' in 12 or less turns."
    puts
    puts
    puts Rainbow("Clues:").underline
    puts "After each guess, there will be up to four clues to help crack the code."
    puts " ● This clue means you have 1 correct number in the correct location."
    puts " ○ This clue means you have 1 correct number, but in the wrong location."
    puts 
    puts 
    puts Rainbow("Clue Example:").underline
    puts "To continue the example, using the above 'master code' a guess of \"1463\" would produce 3 clues:"
    puts "#{Rainbow("  1  ").bg(:khaki)} \
#{Rainbow("  4  ").bg(:pink)} \
#{Rainbow("  6  ").bg(:plum)} \
#{Rainbow("  3  ").bg(:blue)} \
Clues: ● ○ ○"

    puts
    puts
    puts "The guess had 1 correct number in the correct location and 2 correct numbers in a wrong location."
    puts
    puts Rainbow("It's time to play!").underline
    puts "Would you like to be the code MAKER or code BREAKER?"
    puts
    puts "Press '1' to be the code MAKER"
    puts "Press '2' to be the code BREAKER"
    gets
  end
end

def main
  mastermind = Game.new

  mastermind.draw

  mastermind.update
end

main
