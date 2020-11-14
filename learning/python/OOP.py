class Myclass: #class
    def __init__(self, attribute1, attribute2): #constructor
        self.attribute1 = attribute1
        self.attribute2 = attribute2

    def printAttributes(self):
        print('\nValue of "self.attribute1": ', self.attribute1, '\nValue of "self.attribute2":', self.attribute2)

    def updateAttributeValues(self):
        print("\n\n")
        print('Insert new "self.attribute1" value:')
        self.attribute1 = input()
        print('Insert new "self.attribute1" value:')
        self.attribute2 = input()

#Starts exec.
object1 = Myclass("attribute1value_string", 0) 
object1.printAttributes()
object1.updateAttributeValues()
object1.printAttributes()
