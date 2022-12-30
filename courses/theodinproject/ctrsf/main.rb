require 'yaml'
require 'json'
require 'msgpack'

module BasicSerializable
  
  @@serializer = JSON

  def serialize
    obj = {}
    instance_variables.map do |var|
      obj[var] = self.instance_variable_get(var)
    end

    @@serializer.dump obj
  end

  def unserialize(string)
    obj = @@serializer.parse(string)
    obj.keys.each do |key|
      self.instance_variable_set(key, obj[key])
    end
  end

end

class Person
include BasicSerializable
  attr_accessor :name, :age, :gender

  @@serializer = MessagePack

  def initialize(name, age, gender)
    @name   = name
    @age    = age
    @gender = gender
  end

end

p = Person.new "David", 28, "male"
p p.serialize

p.unserialize(p.serialize)
puts "Name: #{p.name}"
puts "Age:  #{p.age}"
puts "Gender: #{p.gender}"
