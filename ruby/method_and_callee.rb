# This script printed the following:
#
#  test_method1
#  test_method1
#  test_callee1
#  test_callee2
#
# __method__ looks the name of a defined method.
# __callee__ looks the name of a called method.
#
class A
  def test_method1
    __method__
  end

  alias :test_method2 :test_method1

  def test_callee1
    __callee__
  end

  alias :test_callee2 :test_callee1
end

puts A.new.test_method1
puts A.new.test_method2
puts A.new.test_callee1
puts A.new.test_callee2
