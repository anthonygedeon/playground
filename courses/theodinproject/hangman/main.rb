remaining_guesses = 10

module Util
  def self.random_word
    file = File.open("words.txt", "r")
    word = file.readlines.select { |word| (5..12).include? word.size }.sample
    file.close
    word
  end

  def self.find_indexes(string, char)
    all_indexes = []
    string.chars.each_with_index {|ch, index| all_indexes << index if ch == char}
    all_indexes
  end
end

class Game
  
  def initialize
     
  end

  def run 

  end

end

class Word
  attr_reader :word

  def initialize(word)
    @word = word
    @secret = ""
  end

  def hide
    @secret = ["_"] * @word.chomp.size
  end

  def unhide
    @word
  end

  def insert_at(index, with: char)
    @secret[index] = with
  end
  
  def complete?
    !@secret.any? "_" 
  end

  private

  attr_accessor :secret
end

word = Word.new(Util::random_word)
hide_word = word.hide

puts "INFO: #{word.word}"

wrong_letters = []

while remaining_guesses != 0 do
  if word.complete?
    puts "You guessed the word!"
    puts word.unhide
    break
  end
  unless wrong_letters.empty?
    puts "Letters guess: #{wrong_letters.join(" ")}" 
  end
  puts "Incorrect guesses remaining: #{remaining_guesses}"
  puts hide_word.join("")
  print "Enter a letter, or type \"save\" to save your progress: "
  char = gets.chomp.downcase[0]
  indexes = Util::find_indexes(word.word, char)

  remaining_guesses -= 1 if indexes.empty?
  wrong_letters << char if indexes.empty?
  indexes.each { |index| word.insert_at(index, with: char) }
end

