# Find all matching occurrences of the substring given a dictionary
#
# @param substring [String] the target
# @param dictionary [Hash] the dictonary of words to use
# @return [Hash] listing each substring
def substrings(substring, dictionary)
  # TODO: Figure out a better to match the word for the dictionary
  # TODO: try to remove flatten
  matched_words = substring.downcase
                           .split(' ')
                           .collect { |word| dictionary.grep(Regexp.new("^[#{word}]+$")) }
                           .flatten
  matched_words.tally.select { |k, _v| dictionary.any? { |substring| k == substring } }
end

dictionary = %w[below down go going horn how howdy it i low own part partner sit]
p substrings('below', dictionary)
p substrings("Howdy partner, sit down! How's it going?", dictionary)

