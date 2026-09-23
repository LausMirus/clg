books = {
    "maths": 10,
    "science": 15,
    "English": 25
}

while True:
    print("1. add\n2. update\n3. delete\n4. display\n5. exit")
    choice = int(input("Enter the choice:"))
    
    if choice == 1:
        name = input("Enter the book name:")
        stock = int(input("Enter the stock value:"))
        books[name] = stock
        
    elif choice == 2:
        name = input("Enter book name:")
        if name in books:
            stock = int(input("Enter stock value:"))
            books[name] = stock
            
    elif choice == 3:
        name = input("Enter book name:")
        if name in books:
            del books[name]
        else:
            print("book not found")
            
    elif choice == 4:
        print("Books:\n", books)
        
    else:
        break
