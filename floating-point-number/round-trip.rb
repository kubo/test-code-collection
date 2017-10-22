n = 0x3ff0000000000000
nerr = 0

10000000.times do
  float_value = [n].pack('Q').unpack('d')[0]
  if float_value.to_s.to_f != float_value
    puts format("round trip error: %016x, %s", n, float_value)
    nerr += 1
  end
  n += 1
end
puts "error count: #{nerr}"
