from set import Set
# Menu driven code
def menu():
    set_1 = Set()
    set_2 = Set()
    while True:
        print("==== Set Operations Menu ====")
        print("1. Add element to Set 1")
        print("2. Remove element from Set 1")
        print("3. Check if element is in Set 1")
        print("4. Get size of Set 1")
        print("5. Perform intersection of Set 1 and Set 2")
        print("6. Perform union of Set 1 and Set 2")
        print("7. Get difference between Set 1 and Set 2")
        print("8. Check if Set 1 is a subset of Set 2")
        print("9. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            element = input("Enter the element to add: ")
            set_1.add(element)
            print("Element added to Set 1.")
        elif choice == 2:
            element = input("Enter the element to remove: ")
            set_1.remove(element)
            print("Element removed from Set 1.")
        elif choice == 3:
            element = input("Enter the element to check: ")
            if set_1.contains(element):
                print("Element is in Set 1.")
            else:
                print("Element is not in Set 1.")
        elif choice == 4:
            print("Size of Set 1 is:", set_1.size())
        elif choice == 5:
            intersection = set_1.intersection(set_2)
            print("Intersection of Set 1 and Set 2:", intersection.elements)
        elif choice == 6:
            union = set_1.union(set_2)
            print("Union of Set 1 and Set 2:", union.elements)
        elif choice == 7:
            difference = set_1.difference(set_2)
            print("Difference between Set 1 and Set 2:", difference.elements)
        elif choice == 8:
            if set_1.subset(set_2):
                print("Set 1 is a subset of Set 2.")
            else:
                print("Set 1 is not a subset of Set 2.")
        elif choice == 9:
            print("Exiting the program...")
            break
        else:
            print("Invalid choice. Please try again.")
menu()
