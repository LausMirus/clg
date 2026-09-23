with open("numbers.txt", "r") as f:
    data = f.read().split()

print("Prime numbers:")
for num in data:
    n = int(num)
    if n < 2:
        continue
    is_prime = True
    for i in range(2, n):
        if n % i == 0:
            is_prime = False
            break
    if is_prime:
        print(n)
