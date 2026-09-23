def even_tuple(numbers):
    even = ()
    for num in numbers:
        if num % 2 == 0:
            even += (num,)
    return even

def odd_tuple(numbers):
    odd = ()
    for num in numbers:
        if num % 2 != 0:
            odd += (num,)
    return odd

# Read input from the user
numbers = tuple(map(int, input("Enter numbers separated by spaces: ").split()))

# Print the results using the defined functions
print("Even tuple: ", even_tuple(numbers))
print("Odd tuple: ", odd_tuple(numbers))
