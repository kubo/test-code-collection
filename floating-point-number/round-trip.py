from struct import *

n = 0x3ff0000000000000
nerr = 0

for _ in range(10000000):
    float_value = unpack('d', pack('Q', n))[0]
    if float(str(float_value)) != float_value:
        print("round trip error: %016x, %s" % (n, float_value))
        nerr += 1
    n += 1

print("error count: %d" % nerr)
