C4_g, A3_g, A4_g = map(int, input().split())
C4 = C4_g * 0.229 * 0.324
A3 = A3_g * 0.297 * 0.42
A4 = A4_g * 0.21 * 0.297
print("%.3f"%(2*C4 + 2*A3 + A4))