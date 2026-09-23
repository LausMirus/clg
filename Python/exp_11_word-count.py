with open("text.txt", "r") as f:
    text = f.read()

words = len(text.split())
sentence = text.count('.') + text.count('?') + text.count('!')

upper = 0
lower = 0
special = 0

for ch in text:
    if ch.isupper():
        upper += 1
    elif ch.islower():
        lower += 1
    elif not ch.isalnum() and not ch.isspace():
        special += 1

print("words", words)
print("sentence", sentence)
print("uppercase letters", upper)
print("lowercase letters", lower)
print("special symbols", special)
