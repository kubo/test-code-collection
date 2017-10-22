from struct import *

n = 0x3ff0000000000000

print("  double in binary => text representation")
for _ in range(1000):
    float_value = unpack('d', pack('Q', n))[0]
    print("  %016x => %s" % (n, float_value))
    n += 1
