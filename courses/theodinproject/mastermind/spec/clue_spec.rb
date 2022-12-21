require "./lib/clue"

describe Clue do 
  describe "#make" do
    it "return the empty clues from a simple guess" do
      code  = [2, 2, 4, 1] 
      guess = [1, 1, 2, 2]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array [:empty, :empty, :empty]
    end

    it "returns two empty clues from a guess" do
      code  = [1, 1, 2, 3] 
      guess = [2, 2, 1, 6]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array [:empty, :empty]
    end

    it "returns two empty clues from a guess" do
      code  = [5, 6, 7, 2] 
      guess = [1, 4, 7, 2]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array [:fill, :fill]
    end

    it "returns the empty and filled clues from a guess" do
      code  = [1, 3, 4, 1] 
      guess = [1, 4, 6, 3]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array [:fill, :empty, :empty]
    end

    it "returns all filled clues from simple guess" do
      code  = [2, 2, 2, 2] 
      guess = [2, 2, 2, 2]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array [:fill, :fill, :fill, :fill]
    end

    it "returns one filled and three empty from guess" do
      code  = [1, 2, 1, 6] 
      guess = [1, 1, 6, 2]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array [:fill, :empty, :empty, :empty]
    end

    it "returns a clue from a really hard guess" do
      code  = [4, 2, 6, 5] 
      guess = [2, 6, 4, 3]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array [:empty, :empty, :empty]
      
    end

    it "returns an empty clue list since no members exist in code" do
      code  = [1, 1, 3, 5] 
      guess = [2, 2, 4, 6]
      
      clues = Clue.make(code, guess)

      expect(clues).to match_array []
    end

  end
end
