def decToBin(decimal):
    '''gets a integer and returns the binary value as a list'''
    rests = [] #declare list
    while (True): #wait for decimal to be 0
        rest = decimal % 2
        decimal = decimal // 2 # // is the integer division, no rest.
        rests.append(rest)
        if (decimal == 0):
            break #emulates a do-while loop
    rests.reverse() #reverse the list
    return rests 

def Twos(binary):
    '''makes a binary number (list) negative (list)'''
    #size = 8 #1 byte 
    #missing = size - len(binary)
    #paddng = []
    #for i in range(missing): #0 to missing
    #    paddng = [0] + paddng
    #binary = paddng + binary
    buff = []
    for i in binary:
        if i == 0:
            buff.append(1)
        else:
            buff.append(0)
    
    '''gets a binary and returns a decimal value as an int so i can add 1'''
    intx = 0
    for i in range(len(buff)): 
        intx = intx + (buff[i]*(2**i))
    intx+1
    
    out = decToBin(intx)
    return out
    
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
