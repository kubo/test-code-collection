n = 0x3ff0000000000000

puts "  double in binary => text representation"
1000.times do
  float_value = [n].pack('Q').unpack('d')[0]
  puts format("  %016x => %s", n, float_value)
  n += 1
end
