# The marker that will be on the tic-tac-toe board 
class Piece
  attr_accessor :symbol

  def initialize(symbol)
    @symbol = symbol
  end
end

# Board for Tic-Tac-Toe
class Board
  ROWS = 3
  COLS = 3
  
  attr_accessor :stop_switch
  @stop_switch = false

  def initialize
    @board = Array.new(ROWS) { Array.new(COLS) { nil } }
  end

  def set_pos(pos, marker)
    case pos
    when (1..3) 
      if !@board[0][(pos-1) % 3].nil?
        @stop_switch = false
        return
      end
      @board[0][(pos-1) % 3] = marker
      @stop_switch = true
    when (4..6) 
      if !@board[1][(pos-1) % 3].nil?
        @stop_switch = false
        return
      end
      @board[1][(pos-1) % 3] = marker
      @stop_switch = true
    when (7..9) 
      if !@board[2][(pos-1) % 3].nil?
        @stop_switch = false
        return
      end
      @board[2][(pos-1) % 3] = marker
      @stop_switch = true
    end
  end

  def to_s
    @board.each_with_index do |row, row_idx| 
      row.each_with_index do |col, col_idx|
        print "  #{col.to_s}  #{(0..1).any?(col_idx) ? '|' : ''}"
      end
      puts ""
      print "-" * 16 if (0..1).any?(row_idx)
      puts ""
    end
  end

  def is_full?
    @board.flatten.none?(nil)
  end

  def is_winner?
    [self.check_horizontals, self.check_verticals, self.check_diagonals].any?
  end

  private
  
  def check_horizontals
    @board.each { |row| return true if all_equal?(row) }
    return false
  end

  def check_verticals
    @board.transpose.each { |row| return true if all_equal?(row) }
    return false
  end

  def all_equal?(row)
    return if row.first.nil?
    row.all? { |piece| piece == row.first }
  end

  def check_diagonals
    left_diag  = []
    right_diag = []
    @board.each_index do |idx|
      left_diag << @board[idx][idx] unless @board[idx][idx].nil?
    end

    @board.each_index do |idx|
      diag_piece = @board[idx][(@board.size-1) - idx]
      right_diag << diag_piece unless diag_piece.nil?
    end

    if left_diag.all?('X') && left_diag.size == 3 || right_diag.all?('X') && right_diag.size == 3
      return true
    end
    if right_diag.all?('O') && right_diag.size == 3 || left_diag.all?('O') && left_diag.size == 3
      return true
    end

    return false
  end

end

# Main game, controls the state of the game
class Game
  def self.run
    self.start
    
    loop do
      if @board.is_winner?
        winning_player = @current_player == 1 ? 0 : 1 
        puts "Player #{@pieces[winning_player].symbol} has won!"
        break
      end

      if @board.is_full? 
        puts "Draw!" 
        break
      end

      print "Player #{ @pieces[@current_player].symbol } Enter your position: "
      pos = gets.chomp 
      @board.set_pos(pos.to_i, @pieces[@current_player].symbol)
      puts @board
      
      if @board.stop_switch
        self.switch_player!
      end

    end
  end

  private
  attr_accessor :score, :pieces
  
  @board = Board.new
  
  @score = [0, 0]

  @pieces = [Piece.new('X'), Piece.new('O')]

  @current_player = 0

  def self.switch_player!
      if @current_player == 0 
        @current_player = 1
      else
        @current_player = 0
      end
  end

  def self.start
    puts "" 
    puts " _______ _        _______           _______ \n"
    puts "|__   __(_)      |__   __|         |__   __| \n"
    puts "   | |   _  ___     | | __ _  ___     | | ___   ___ \n"
    puts "   | |  | |/ __|    | |/ _` |/ __|    | |/ _ \\ / _ \\ \n"
    puts "   | |  | | (__     | | (_| | (__     | | (_) |  __/ \n"
    puts "   |_|  |_|\\___|    |_|\\__,_|\\___|    |_|\\___/ \\___| \n\n\n"

    puts "1. The game is played on a grid that's 3 squares by 3 squares(3x3).\n\n"
    puts "2. You are X, player 2 is O. Players take turns putting their marks in empty squares.\n\n"
    puts "3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n\n"
    puts "4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n\n"
    
    puts "  1  |  2  |  3  \n"
    puts "-" * 16
    puts "  4  |  5  |  6  \n"
    puts "-" * 16
    puts "  7  |  8  |  9  \n"

    puts ""

    puts "=" * 100
  end
end

Game.run
