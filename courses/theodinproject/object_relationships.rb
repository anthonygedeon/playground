class Cinema
  attr_accessor :name, :location, :movies

  def initialize(name, location)
    @name = name
    @location = location
    @movies = []
  end

  def add_movie(movie)
    @movies << movie
    movie.cinema = self
  end
end

class Movie
  attr_accessor :title, :showtime, :cinema

  @@all = []

  def initialize(title, showtime)
    @title = title
    @showtime = showtime
    @@all << self
  end
end

cinema1 = Cinema.new("Cobble Hill Cinema", "Court St, Brooklyn")
cinema2 = Cinema.new("New Richmond Cinema", "New Richmond, Town")

puts "=" * 20

movie1 = Movie.new("Spider-Man", "9:00")
movie2 = Movie.new("Deap Pool 3", "7:30")
movie3 = Movie.new("Fast & furious 1 Reboot", "1:00")
movie4 = Movie.new("Hulk", "8:00")

movies = [movie1, movie2, movie3, movie4].each { |movie| cinema1.add_movie(movie) }

cinema2.add_movie(movie1)

pp cinema1

puts "=" * 20
pp cinema2.movies
puts "=" * 20

pp movies.first

puts "=" * 20
