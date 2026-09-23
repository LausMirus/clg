import matplotlib.pyplot as plt

continents = ['Africa', 'Asia', 'Europe',
              'North America', 'Oceania', 'South America',
              'Soviet Union']
area = [11.7, 10.4, 1.9, 9.4, 3.3, 8.9, 7.9]
position = [0, 1, 2, 3, 4, 5, 6]

plt.bar(position, area)
plt.xticks(position, continents, rotation=45)
plt.xlabel("continents")
plt.ylabel("Area in million square miles")
plt.title("Area of various continents")
plt.show()
