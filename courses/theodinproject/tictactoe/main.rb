$dont_switch_player = false

class Piece
  attr_accessor :symbol

  def initialize(symbol)
    @symbol = symbol
  end
end

class Board
  ROWS = 3
  COLS = 3

  def initialize
    @board = Array.new(ROWS) { Array.new(COLS) { nil } }
  end

  def is_winner?
    self.check_winner
  end

  def set_pos(pos, marker)
    case pos
    when (0..2) 
      if !@board[0][pos % 3].nil?
        $dont_switch_player = false
        return
      end
      @board[0][pos % 3] = marker
      $dont_switch_player = true
    when (3..5) 
      if !@board[1][pos % 3].nil?
        $dont_switch_player = false
        return
      end
      @board[1][pos % 3] = marker
      $dont_switch_player = true
    when (6..8) 
      if !@board[2][pos % 3].nil?
        $dont_switch_player = false
        return
      end
      @board[2][pos % 3] = marker
      $dont_switch_player = true
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

  private
  
  def check_horizontals
    @board.each do |row| 
      if row.all?('X') 
        puts "Player X Won!"
        return true
      elsif row.all?('O')
        puts "Player O Won!"
        return true
      end
    end
    return false
  end

  def check_verticals
    @board.transpose.each do |row| 
      if row.all?('X') 
        puts "Player X Won!"
        return true
      elsif row.all?('O')
        puts "Player O Won!"
        return true
      end
    end
    return false
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
    if left_diag.all?('X') && left_diag.size == 3
      puts "Player X Won!"
      return true
    end
    if right_diag.all?('X') && right_diag.size == 3
      puts "Player X Won!"
      return true
    end
    if right_diag.all?('O') && right_diag.size == 3
      puts "Player O Won!"
      return true
    end
    if left_diag.all?('O') && left_diag.size == 3
      puts "Player O Won!"
      return true
    end
    return false
  end

  def check_winner
    [self.check_horizontals, self.check_verticals, self.check_diagonals].any?(true)
  end
end

class Game
  def self.run
    self.start
    
    while @is_running
      print "Player #{ @pieces[@current_player].symbol } Enter your position: "
      pos = gets.chomp 
      @board.set_pos(pos.to_i, @pieces[@current_player].symbol)
      puts @board
      
      if $dont_switch_player
        self.switch_player
      end

      if @board.is_winner?
        @is_running = false
      end
    end

  end

  private
  attr_accessor :score, :pieces
  
  @board = Board.new
  
  @score = [0, 0]

  @pieces = [Piece.new('X'), Piece.new('O')]

  @is_running = true

  @current_player = 0

  def self.switch_player
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
    
    puts "  0  |  1  |  2  \n"
    puts "-" * 16
    puts "  3  |  4  |  5  \n"
    puts "-" * 16
    puts "  6  |  7  |  8  \n"

    puts ""

    puts "=" * 100
  end
end

Game.run
