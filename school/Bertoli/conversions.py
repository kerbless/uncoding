#imports
import os
from output_formatting import printOk, printInfo, printError, printIn

#useful data
menuChoiches = {
    1 : 'Decimal',
    2 : 'Binary',
    3 : 'Octal',
    4 : 'Hexadecimal'
    }
hexToC = {
    10 : 'A',
    11 : 'B',
    12 : 'C',
    13 : 'D',
    14 : 'E',
    15 : 'F'
    }
cToHex = { #There should be a way to use hexToC with a for cicle without having to re-write it flipped (https://stackoverflow.com/questions/8023306/get-key-by-value-in-dictionary)
    'A' : 10,
    'B' : 11,
    'C' : 12,
    'D' : 13,
    'E' : 14,
    'F' : 15
    }
hexValidChars = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e', 'f','A','B','C','D','E','F','-']
octValidChars = ['0','1','2','3','4','5','6','7','-']
binValidChars = ['0','1','-']

#utility functions
def clear():
    os.system( 'cls' )
def listToStr(list_):
    '''convert list to string'''
    out = ''
    for i in list_:
        out = out+str(i)
    return out
def checkChars(string_, validChars):
    try:
        for char_ in string_: #checks every chars for validity
            charIsValid = False
            for valid in validChars: 
                if char_ == valid:
                    charIsValid = True
                    break
            assert charIsValid == True
        return True
    except AssertionError:
        return False
      
#menu functions
def menuBase():
    error = ''
    while(True):
        try:
            clear()
            print('_________________________________________________')
            if (error != ''):
                printError(error)
                print('try again:\n')
            print('Choose the base of the number you want to convert')
            print('1. Decimal')
            print('2. Binary')
            print('3. Octal')
            print('4. Hexadecimal')
            print('_________________________________________________')
            base = int(input('insert choice [1-4]: ')) #If the input is not an input, it jumps to ValueError

            assert base >= 1 and base <= 4
            return base
        except AssertionError:
            error = 'You didn\'t enter valid number'
        except ValueError:
            error = 'You didn\'t enter a number'
def menuConversion():
    error = ''
    while(True):
        try:
            clear()
            print('________________________________________________________')
            if (error != ''):
                printError(error)
                print('try again:\n')
            print('Choose the base you want your number to be converted to:')
            print('1. Decimal')
            print('2. Binary')
            print('3. Octal')
            print('4. Hexadecimal')
            print('________________________________________________________')
            base = int(input('insert choice [1-4]: ')) #If the input is not an input, it jumps to ValueError
            '''
            #old implementation, replaced with ASSERT
            if (base < 1 or base > 4):
                raise(ValueError)
            else:
                return base
            break
            '''
            assert base >= 1 and base <= 4
            return base #functions as a break
        except AssertionError:
            error = 'You didn\'t enter valid number'
        except ValueError:
           error = 'You didn\'t enter a number'
def printResult(result):
    clear()
    #print('_________________________')
    printOk('Result calculated')
    printInfo(f'Your result is: =>| {result} |<=')
    #print('_________________________')
def getDec():
    while(True):
        try:
            printIn('Insert and integer decimal number: ')
            in_ = int(input()) #will raise a ValueError if casting fails
            return in_
        except ValueError:
            printError('You didn\'t enter a number') 
def getBin():
    while(True):
        try:
            printIn('Insert and integer binary number: ')
            in_ = input()
            assert checkChars(in_, binValidChars) #checks every chars for validity
            return int(in_) #will raise a ValueError if casting fails
        except AssertionError:
            printError('This is not a boolean number!')
        except ValueError:
            printError('You didn\'t enter a number') 
def getOct():
    while(True):
        try:
            printIn('Insert and integer octal number: ')
            in_ = input()
            for inputChar in in_: #checks every chars for validity
                charChecked = False
                for valid in octValidChars: 
                    if inputChar == valid:
                        charChecked = True
                        break
                assert charChecked == True
            return int(in_) #will raise a ValueError if casting fails
        except AssertionError:
            printError('This is not a boolean number!')
        except ValueError:
            printError('You didn\'t enter a number')
def getHex():
    while(True):
        try:
            printIn('Insert and integer hexadecimal number: ')
            in_ = input()
            for inputChar in in_: #checks every chars for validity
                charChecked = False
                for valid in hexValidChars: 
                    if inputChar == valid:
                        charChecked = True
                        break
                assert charChecked == True
            return in_
        except AssertionError:
            printError('This is not an hexadecimal number!')

#conversion functions
def decToBin(decimal):
    '''gets a integer and returns the binary value as string'''
    if (decimal > 0):
        rests = [] #declare list
        while (True): #wait for decimal to be 0
            rest = decimal % 2
            decimal = decimal // 2 # 0// is the integer division, no rest.
            rests.append(rest)
            if (decimal == 0):
                break #emulates a do-while loop
        rests.reverse() #reverse the list
        out = listToStr(rests)
        return out
        
    elif (False): #TODO finish the negative binary setup with no sign
            decimal = -decimal 
            rests = [] #declare list
            while (True): #wait for decimal to be 0
                rest = decimal % 2
                decimal = decimal // 2 # 0// is the integer division, no rest.
                rests.append(rest)
                if (decimal == 0):
                    break #emulates a do-while loop
            rests.reverse() #reverse the list
            binary = [0] + rests #add leading 0 if not present
            print(binary) #TODO remove, develop use
            input()
            for index, item in enumerate(binary): #enumerate returns first the index and then the item.
                if item == 0:
                    binary[index] = 1
                elif item == 1:
                    binary[index] = 0
            print(binary) #TODO remove, develop use
            input()
            temp_decimal = 0
            for i in range(len(binary)):
                temp_decimal += binary[i]*2**(len(binary)-1-i)
            print(temp_decimal)
            input()
            temp_decimal += 1
            binary = decToBin(temp_decimal)
            print(binary)
            input()
            return binary
    elif (decimal < 0):
        decimal = -decimal
        return "-" + decToBin(decimal)
    else:
        return '0'
def decToOct(decimal):
    '''gets a integer and returns the octal value as string'''
    if (decimal > 0):
        rests = [] #declare list
        while (True): #wait for decimal to be 0
            rest = decimal % 8
            decimal = decimal // 8 # 0// is the integer division, no rest.
            rests.append(rest)
            if (decimal == 0):
                break #emulates a do-while loop
        rests.reverse() #reverse the list
        out = listToStr(rests)
        return out
    elif (decimal < 0):
        decimal = -decimal
        return "-" + decToOct(decimal)
    else:
        return '0'
def decToHex(decimal):
    '''gets a decimal int and returns a hexadecimal string'''
    if (decimal > 0):
        rests = [] #declare list
        while (True): #wait for decimal to be 0
            rest = decimal % 16
            decimal = decimal // 16 # 0// is the integer division, no rest.
            if (rest > 9):
                rest = hexToC[rest]
            rests.append(str(rest))
            if (decimal == 0):
                break #emulates a do-while loop
        rests.reverse() #reverse the list
        out = listToStr(rests)
        return out
    elif (decimal < 0):
        decimal = -decimal
        return "-" + decToHex(decimal)
    else:
        return '0'
def binToDec(binary):
    '''gets a binary string and returns a decimal int'''
    if (int(binary) > 0): #i can do this because binary is considered a full int
        decimal = 0
        binary_list = [int(x) for x in str(binary)] #this converts the binary int to a list of digits
        for index, value in enumerate(binary_list):
            #print(f'Index: {index}\nValue: {value}\nDecimal: {decimal}\n(len(binary)-1-index): {(len(binary_list)-1-index)}')
            decimal += value*2**(len(binary_list)-1-index)
        return decimal
    else:
        binary = str(-int(binary))
        return ('-' + str(binToDec(binary)))
def hexToDec(hexadecimal):
    pass


'''[____MAIN____]'''
while(True):
    menu_base = menuBase()
    base = menuChoiches[menu_base]
    conversionTo = menuConversion()
    convert = menuChoiches[conversionTo]
    #Your choice:
    clear()
    printOk('Input recieved')
    printInfo(f'You choose to convert ({base}) to ({convert})')
    if (base == 'Decimal'):
        decimal = getDec()
        if (convert == 'Binary'):
            binary = decToBin(decimal)
            printResult(binary)
        elif (convert == 'Decimal'):
            printResult(decimal)
        elif (convert == 'Octal'):
            octal = decToOct(decimal)
            printResult(octal)
        elif (convert == 'Hexadecimal'):
            hexadecimal = decToHex(decimal)
            printResult(hexadecimal)
        else:
            pass #This should be unreachable code
    elif (base == 'Binary'):
        binary = getBin()
        if (convert == 'Binary'):
            printResult(binary)
        elif (convert == 'Decimal'):
            decimal = binToDec(binary) 
            printResult(decimal)
        elif (convert == 'Octal'):
            decimal = binToDec(binary)
            octal = decToOct(decimal)
            printResult(octal) 
        elif (convert == 'Hexadecimal'):
            decimal = binToDec(binary)
            hexadecimal = decToHex(decimal)
            printResult(hexadecimal)
        else:
            pass #This should be unreachable code
    elif (base == 'Octal'): #TODO
        octal = getOct()
        if (convert == 'Binary'):
            printError("Still working on it ") #TODO
        elif (convert == 'Decimal'):
            printError("Still working on it ") #TODO
        elif (convert == 'Octal'):
            printResult(octal)
        elif (convert == 'Hexadecimal'):
            printError("Still working on it ") #TODO
        else:
            pass #This should be unreachable code
    elif (base == 'Hexadecimal'): #TODO
        hexadecimal = getHex()
        if (convert == 'Binary'):
            printError("Still working on it ") #TODO
        elif (convert == 'Decimal'):
            printError("Still working on it ") #TODO
        elif (convert == 'Octal'):
            printError("Still working on it ") #TODO
        elif (convert == 'Hexadecimal'):
            printResult(hexadecimal)
        else:
            pass #This should be unreachable code
    
    while(True): #Exit menu
        try:
            print('\n')
            printIn("Insert '1' to restart or '0' to exit: ")
            in_ = input() #will raise a ValueError if casting fails
            assert checkChars(in_, ['0', '1'])
            if (int(in_) == 0):
                exit()
            elif (int(in_) == 1):
                break #restart program
        except AssertionError:
            printError('You didn\'t enter a 0 or 1')
        except ValueError:
            printError('You didn\'t enter a number')