import matplotlib.pyplot as plt

# Data
heights = [135, 140, 145, 150] # Lower limits of the classes
frequencies = [4, 12, 16, 8]

# Plotting
plt.bar(heights, frequencies, width=5, align='edge', edgecolor='black')
plt.xlabel("Height of students")
plt.ylabel("Number of students")
plt.title("Histogram of Height Distribution")
plt.show()
