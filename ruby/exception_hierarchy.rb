require 'pp'

# Generate the family tree of the Exception Class
#
# @param
# @return
def print_hierarchy(cls)
  puts cls.subclasses
end

print_hierarchy(Exception)
