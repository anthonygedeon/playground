require './lib/calculator'

describe Calculator do
  describe "#add" do
    it "returns the sum of two numbers" do
      calculator = Calculator.new
      expect(calculator.add(5, 2)).to eq(7)
    end

    it "returns the sum of more than two numbers" do
      calculator = Calculator.new
      expect(calculator.add(2, 5, 7)).to eq(14)
    end
  end

  describe "#multiply" do
    it "returns the product of two numbers" do
      calculator = Calculator.new
      expect(calculator.multiply(2, 4)).to eq(8)
    end
  end

  describe "#subtract" do
    it "returns the sum of subtracting two numbers" do
      calculator = Calculator.new
      expect(calculator.subtract(4, 2)).to eq(2)
    end
  end

  describe "#divide" do
    it "returns the result of dividing two numbers" do
      calculator = Calculator.new
      expect(calculator.divide(8, 2)).to eq(4)
    end
  end

end
