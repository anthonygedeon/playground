require_relative 'code'

class Game
  def run
    self.draw
    self.update
  end

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
    puts UI::COLORS.values.join(" ")
    puts
    puts "The code maker will choose four to create a 'master code'. For example,"

    puts "#{UI::COLORS[1]} \
#{UI::COLORS[4]} \
#{UI::COLORS[6]} \
#{UI::COLORS[3]}"

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
    puts "#{UI::COLORS[1]} \
#{UI::COLORS[4]} \
#{UI::COLORS[6]} \
#{UI::COLORS[3]} \
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
  
  private

  def initialize
    @code = Code.new
  end

  def draw
    self.begin_tutorial
  end

  def update
    puts "The computer has set the 'master code' and now it's time for you to break the code."
    puts "[DEBUG] Master Code: #{@code.print_code}"
    puts 

    current_turn = 1

    loop do
      puts "Turn ##{current_turn}: Type in four numbers (1-6) to guess the code, or 'q' to quit game."

      guess = gets.chomp.split('').map(&:to_i)

      if guess.length != 4
        puts Rainbow("Your guess should only be 4 digits between 1-6").red
      end
      
      puts
      puts "#{guess.map { |num| UI::COLORS[num] }.join(" ") } clues: #{@code.create_clues_from(guess)}"
      
      if current_turn == 12
        self.game_over
        puts 
        self.try_again
      end

      current_turn += 1
    end
  end

end

