def decToBin(decimal):
    '''gets a integer and returns the binary value as a list'''
    rests = [] #declare list
    while (True): #wait for decimal to be 0
        rest = decimal % 2
        decimal = decimal // 2 # 0// is the integer division, no rest.
        rests.append(rest)
        if (decimal == 0):
            break #emulates a do-while loop
    rests.reverse() #reverse the list
    return rests

def binToDec(binary):
    '''gets a binary (list) and returns a decimal value as an int'''
    dec = 0
    for i in range(len(binary)): #same as range(0, last list item index, 1)
        weight = len(binary)-i
        dec = dec + (binary[i]*(2**weight))
    return dec

    
def Twos(binary):
    '''Returns the negative binary using the two's complement (https://en.wikipedia.org/wiki/Two%27s_complement)'''
    print(binary)
    binary.insert(0, 0) #add leading 0 if not present
    print(binary)
    for index, item in enumerate(binary): #enumerate returns first the index and then the item.
        if item == 0:
            binary[index] = 1
        elif item == 1:
            binary[index] = 0
    print(binary)
    dec = binToDec(binary)
    print(dec)
    dec += 1
    print(dec)
    binary = decToBin(dec)
    print(binary)
    return binary


def listToStr(list_):
    '''convert list to string'''
    out = ""
    for i in list_:
        out = out+str(i)
    return out

#__________________MAIN____________________
print("\tFROM DECIMAL TO BINARY") #TITLE

#getting decimal, it will ask for it again if int() returns a ValueError (improper value) 
while(True):
    try:
        in_ = int(input("Insert and integer decimal number: "))
        break

    except ValueError:
        print("You didn't enter a valid number")

#controls if the number is positive, negative or 0
if (in_ > 0): # IN > 0
    binary = decToBin(in_)
    out = listToStr(binary)
elif (in_ < 0): #IN < O (manage negative numbers with two's complement)
    in_ = in_*-1
    binary = decToBin(in_)
    binary = Twos(binary)
    out = listToStr(binary)
else: #IN = 0
    out = "0"

#print(f"Binary: {out}")
print("Binary: " + out)
input("Press enter to exit")

'''
Because int are stored as binary, we don't really need 
to do all that and just print directly the binary value with:
print(bin(a))
'''
