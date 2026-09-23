import matplotlib.pyplot as plt

height = [135, 140, 145, 150]
frequency = [4, 12, 16, 8]

plt.bar(height, frequency, width=5, align='edge', edgecolor='black')
plt.xlabel("Height of students")
plt.ylabel("Number of students")
plt.title("Histogram of students' Height")
plt.show()
