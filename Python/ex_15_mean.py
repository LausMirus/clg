import numpy as np

population = [4779736, 710231, 6392017, 2915918, 37253956, 5029196, 3574097, 89924]

mean_val = np.mean(population)
median_val = np.median(population)
variance_val = np.var(population) # Population variance by default in numpy

print(f"Mean: {mean_val}")
print(f"Median: {median_val}")
print(f"Variance: {variance_val}")
