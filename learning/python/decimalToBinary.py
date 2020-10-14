print("\tFROM DECIMAL TO BINARY") #TITLE

while(True): #getting decimal, it will ask for it again if int() returns a ValueError (improper value) 
    try:
        decimal = int(input("Isert and integer decimal number: "))
        break
    except ValueError:
        print("You didn't enter a valid number")
print("Inserted number: " + str(decimal))

rests = [] #declare list
while(True): #wait for decimal to be 0
    rest = decimal % 2
    decimal = decimal // 2 # // is the integer division, no rest.
    rests.append(rest)
    if(decimal == 0):
        break #emulates a do-while loop

rests.reverse() #reverse the list
print(f"Binary: {rests}")

'''
Because int are stored as binary, we don't really need 
to do all that and just print directly the binary value with:
print(bin(a))
'''
