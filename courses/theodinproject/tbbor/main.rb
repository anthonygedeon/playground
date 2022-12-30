=begin
fname = "sample.txt"

somefile = File.open(fname, "w+")
somefile.puts "Hello file!"
somefile.close
=end

require "open-uri"
require "rubygems"
require "rest-client"

=begin
remote_base_url = "http://en.wikipedia.org/wiki"

File.open("wiki-page.html", "w") do |f| 
  f.write RestClient.get remote_base_url
end

file = File.open("sample.txt", "r")
while !file.eof?
  content = file.readline
  puts content
end

puts
puts "====================="
puts

url = "http://ruby.bastardsbook.com/files/fundamentals/hamlet.txt"
excerpt = "hamlet.txt"

file = File.open(excerpt, "w")
URI.open(url) { |f| f.each_line {|line| file.write line} }
file.close

file = File.open(excerpt, "r")

file.readlines.each_with_index { |line, idx| puts line if idx % 42 == 41 && line.match?(/^  [h|H]am/)}
=end

=begin
datafile = File.open("sample.txt", "r")
lines = datafile.readlines
datafile.close

lines.each { |line| puts line }
=end

BASE_URL = "https://chart.googleapis.com"

table = Dir.glob("/home/anthony/Downloads/**/*").reduce({}) do |hash, val|
  ext = File.basename(val).split(".").last.to_s.upcase
  hash[ext] ||= [0,0]
  hash[ext][0] += 1
  hash[ext][1] += File.size(val)
  hash 
end

File.open("file-analysis.txt", "w") do |f|
  table.each do |arr|
    metadata = arr.flatten.join("\t")
    f.puts metadata
  end
end

data = File.open("file-analysis.txt", "r").readlines.map { |line| line.chomp.split("\t") }

extensions = []
p data.each { |ext| extensions << ext.first}

tally = []
p data.each { |m| tally << m[1]}

URL = "#{BASE_URL}/chart?cht=p&chd=t:#{tally.join(",")}&chs=500x300&chl=#{extensions.join("|")}"
puts RestClient.get URL
