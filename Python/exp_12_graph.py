import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 300)

plt.figure(figsize=(10, 8))

# 1. y = x
plt.subplot(3, 3, 1)
plt.plot(x, x)
plt.title("y = x")
plt.grid()

# 2. y = 2x + 3
plt.subplot(3, 3, 2)
plt.plot(x, 2*x + 3)
plt.title("y = 2x + 3")
plt.grid()

# 3. y = x^2
plt.subplot(3, 3, 3)
plt.plot(x, x**2)
plt.title("y = x^2")
plt.grid()

# 4. y = x^3
plt.subplot(3, 3, 4)
plt.plot(x, x**3)
plt.title("y = x^3")
plt.grid()

# 5. y = sqrt(x)
x1 = np.linspace(0, 10, 500)
plt.subplot(3, 3, 5)
plt.plot(x1, np.sqrt(x1))
plt.title("y = sqrt(x)")
plt.grid()

# 6. y = sin(x)
plt.subplot(3, 3, 6)
plt.plot(x, np.sin(x))
plt.title("y = sin(x)")
plt.grid()

# 7. y = cos(x)
plt.subplot(3, 3, 7)
plt.plot(x, np.cos(x))
plt.title("y = cos(x)")
plt.grid()

# 8. y = e^x
plt.subplot(3, 3, 8)
plt.plot(x, np.exp(x))
plt.title("y = e^x")
plt.grid()

plt.tight_layout()
plt.show()
