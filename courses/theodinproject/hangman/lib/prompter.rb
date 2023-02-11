class Prompter
  attr_accessor :io

  def initialize(io) 
    @io = io
  end

  def request(string)
    @io.puts string
    @io.getc
  end
end
