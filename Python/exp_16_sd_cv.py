import numpy as np

midpoints = np.array([5, 15, 25, 35, 45, 55, 65, 75])
frequencies = np.array([5, 10, 20, 40, 30, 20, 10, 5])

mean = np.sum(frequencies * midpoints) / np.sum(frequencies)

variance = np.sum(frequencies * (midpoints - mean)**2) / np.sum(frequencies)
sd = np.sqrt(variance)

cv = (sd / mean) * 100

print(f"Mean: {mean:.2f}")
print(f"Standard Deviation (S.D.): {sd:.2f}")
print(f"Coefficient of Variation (C.V.): {cv:.2f}%")
