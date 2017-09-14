# This script printed the following:
#
#   Base:
#     CONST => constant of class Base
#     @@class_var => class variable of class Sub
#     self.class.const_get(:CONST) => constant of class Base
#     get_const => constant of class Base
#   Sub:
#     CONST => constant of class Base
#     @@class_var => class variable of class Sub
#     self.class.const_get(:CONST) => constant of class Sub
#     get_const => constant of class Sub
#
# CONST in Base#print_class_values refered CONST in Base
# even when an instance of class Sub called print_class_values.
#
# @@class_var was overwritten in Sub.
#
# The third and forth ways are available to get the class
# value to which an instance belongs.
#
class Base
  CONST = 'constant of class Base'
  CONST2 = 'constant of class Base'
  @@class_var = 'class variable of class Base'
  @class_instance_var = 'class instance variable of class Base'
  @class_instance_var2 = 'class instance variable of class Base'

  def print_class_values
    puts "  CONST => #{CONST}"
    puts "  @@class_var => #{@@class_var}"
    puts "  @class_instance_var => #{self.class.instance_variable_get(:@class_instance_var)}"
    puts "  @class_instance_var2 => #{self.class.instance_variable_get(:@class_instance_var2)}"
    puts "  self.class.const_get(:CONST) => #{self.class.const_get(:CONST)}"
    puts "  self.class.const_get(:CONST2) => #{self.class.const_get(:CONST2)}"
    puts "  get_const => #{get_const}"
    puts "  get_const2 => #{get_const2}"
  end

  def get_const
    CONST
  end

  def get_const2
    CONST
  end
end

class Sub < Base
  CONST = 'constant of class Sub'
  @@class_var = 'class variable of class Sub'
  @class_instance_var = 'class instance variable of class Sub'

  def get_const
    CONST
  end
end

puts "Base:"
Base.new.print_class_values
puts "Sub:"
Sub.new.print_class_values
