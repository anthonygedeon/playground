def caesar_cipher(string, shift=0)
	if string.empty? then return string
	result = string.chars.map do |char|		
		if char.between?('A', 'Z')
			(((char.ord+shift)  % 'Z'.ord) + 'A'.ord - 1).chr
		elsif char.between?('a', 'z')
			((char.ord+shift) % 'z'.ord).chr
		else 
			char
		end
	end
	result.join
end

p caesar_cipher("What a string!", 5)

