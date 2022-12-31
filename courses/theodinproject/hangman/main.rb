remaining_guesses = 10

def random_word
  file = File.open("words.txt", "r")
  word = file.readlines.select { |word| (5..12).include? word.size }.sample
  file.close
  word
end

def find_indexes(string, char)
  all_indexes = []
  string.chars.each_with_index {|ch, index| all_indexes << index if ch == char}
  all_indexes
end

secret_word = random_word

puts "INFO: #{secret_word}"

hide_word = secret_word.chomp.chars.map {|_| "_"}
letters = []

while hide_word.any? "_" || remaining_guesses == 0 do
  unless letters.empty?
    puts "Letters guess: #{letters.join(" ")}" 
  end
  puts "Incorrect guesses remaining: #{remaining_guesses}"
  puts hide_word.join("")
  print "Enter a letter, or type \"save\" to save your progress: "
  char = gets.chomp 
  indexes = find_indexes(secret_word, char)
  remaining_guesses -= 1 if indexes.empty?
  letters << char
  indexes.each { |index| hide_word[index] = char }
end

