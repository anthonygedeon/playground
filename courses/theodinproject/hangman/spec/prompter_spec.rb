require "./lib/prompter"

require "stringio"

describe Prompter do
  it "prompt the player to enter a character" do 
    io = StringIO.new
    prompt = Prompter.new(io)
    arg =  "Enter a letter, or type \"save\" to save your progress: " 
  
    prompt.request arg

    puts prompt

  end
end
