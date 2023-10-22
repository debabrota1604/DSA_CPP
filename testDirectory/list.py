print("This program implements list features in python using custom list class")

class Node:
    def __init__(self, data2):
        print("Inside Node constructor")
        self.data = data2
        self.link = None
    
    # def __init__(self, data, next):
    #     self.data = data
    #     self.link = next
    

    def __del__() -> None:
        print("Deleting Node")
    

class List:
    def __init__(self):
        self.head = None

    def __init__(self, data=0):
        head = Node(data)
    
    def insert_atBegin(self, data):
        tempNode = Node(data)

        if self.head is None:
            self.head = tempNode
        else:
            tempNode.link = self.head
            self.head = tempNode

    def dispList(self):
        temp = self.head
        while temp.link != None:
            print(temp.data, end= " ")
            temp = temp.link
        print("\n")
    

list = List
list.insert_atBegin(5)
list.insert_atBegin(2)


    

