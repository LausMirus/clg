from scipy.stats import binom

n = 6
p = 0.25

prob_4 = binom.pmf(4, n, p)

prob_at_least_1 = 1 - binom.pmf(0, n, p)

print(f"(a) P(X = 4): {prob_4:.4f}")
print(f"(b) P(X >= 1): {prob_at_least_1:.4f}")
