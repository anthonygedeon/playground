require_relative 'ui'

class Code
  def initialize
    @master_code = (1..6).to_a.sample(4)
  end

  def create_clues_from(guess)
    Clue.make(@master_code.clone, guess).map { |state| UI::CIRCLE.fetch(state) }.join(" ")
  end
  
  # remove later, only for debugging purposes
  def print_code
    self.master_code
  end

  private
  attr_reader :master_code
end
