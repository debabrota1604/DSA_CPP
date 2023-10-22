from typing import Any


class Animal:
    description = "Animal"
    def __init__(self, age, name):
        self.age = age
        self.name = name
    

    def __str__(self):
        return f"Name: {self.name}, age: {self.age}, description: {self.description}"
    

    def __del__(self):
        print("Deleting Animal Object")

class Plant():
    name = "Plant"
    def __init__(self, color, height) -> None:
        self.color = color
        self.height = height
    
    def __str__(self) -> str:
        return f"Tree color: {self.color}, Tree Height: {self.height}"
    
    def __del__(self):
        print("Deleting plant object")

class Cat(Animal):
    eyes = "golden"
    def __init__(self, eyeColor, age, name):
        super().__init__(self, age, name)
        eyes = eyeColor
    
    def __del__(self):
        print("Deleting Cat Object")
        Animal().__del__()
    
class UnknownLife(Animal, Plant):
    canWalk = False
    def __init__(self, age, name, color, height):
        Animal().__init__(age, name)
        Plant().__init__(color, height)

    def __str__(self):
        Animal().__str__()
        Plant().__str__()
        print("This is UnknownLife descriptions")

    def __del__(self):
        print("Deleting UL Object")
        Plant().__del__()
        Animal().__del__()


dog = Animal(5, "Rocky")
print(dog)

cat = Animal(2, "Tom")
print(cat)

ul = UnknownLife(2, "UL", "Red", "80 Ft")
print(ul)
