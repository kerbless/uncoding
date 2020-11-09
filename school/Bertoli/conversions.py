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
hexValidChars = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F','-']
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
            assert checkChars(in_, hexValidChars) == True
            return in_
        except AssertionError:
            printError('This is not an hexadecimal number!')

#conversion functions
def decToBin(decimal_str):
    '''gets a integer and returns the binary value as string'''
    decimal = int(decimal_str)
    if (decimal > 0):
        rests = [] #declare list
        while (True): #wait for decimal to be 0
            rest = decimal % 2
            decimal = decimal // 2 # 0// is the integer division, no rest.
            rests.append(rest)
            if (decimal == 0):
                break #emulates a do-while loop
        rests.reverse() #reverse the list
        binary = listToStr(rests)
        return binary
        
    elif (False): #TODO this code is unreachable, was first made to implement negative binary with two's complement. Now abandoned.
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
            for index, item in enumerate(binary): #enumerate returns first the index and then the item.
                if item == 0:
                    binary[index] = 1
                elif item == 1:
                    binary[index] = 0
            temp_decimal = 0
            for i in range(len(binary)):
                temp_decimal += binary[i]*2**(len(binary)-1-i)
            temp_decimal += 1
            binary = decToBin(temp_decimal)
            return binary

    elif (decimal < 0):
        decimal = str(-decimal)
        return ('-' + decToBin(decimal))
    else:
        return '0'
def decToOct(decimal_str):
    '''gets a decimal string and returns the octal value as string'''
    decimal = int(decimal_str)
    if (decimal > 0):
        rests = [] #declare list
        while (True): #wait for decimal to be 0
            rest = decimal % 8
            decimal = decimal // 8 # 0// is the integer division, no rest.
            rests.append(rest)
            if (decimal == 0):
                break #emulates a do-while loop
        rests.reverse() #reverse the list
        octal = listToStr(rests)
        return octal
    elif (decimal < 0):
        decimal = str(-decimal)
        return ("-" + decToOct(decimal))
    else:
        return '0'
def decToHex(decimal_str):
    '''gets a decimal string and returns a hexadecimal string'''
    decimal = int(decimal_str)
    if (decimal > 0):
        rests = [] #declare list
        while (True): #wait for decimal to be 0
            rest = decimal % 16
            decimal = decimal // 16 # 0// is the integer division, no rest.
            if (rest > 9):
                rest = hexToC[rest]
            rests.append(str(rest).upper()) #makes sure that letters are uppercase when making an hexadecimal number (TODO: is this useful?)
            if (decimal == 0):
                break #emulates a do-while loop
        rests.reverse() #reverse the list
        hexadecimal = listToStr(rests)
        return hexadecimal
    elif (decimal < 0):
        decimal = str(-decimal)
        return "-" + decToHex(decimal)
    else:
        return '0'
def binToDec(binary):
    '''gets a binary string and returns a string decimal'''
    if (int(binary) > 0): #i can do this because binary is considered a full int
        decimal = 0
        binary_list = [int(x) for x in str(binary)] #this converts the binary int to a list of digits
        for index, value in enumerate(binary_list):
            #print(f'Index: {index}\nValue: {value}\nDecimal: {decimal}\n(len(binary)-1-index): {(len(binary_list)-1-index)}')
            decimal += value*2**(len(binary_list)-1-index)
        return str(decimal)
    elif (int(binary) < 0):
        binary = str(-int(binary))
        return ('-' + str(binToDec(binary)))
    else:
        return '0'
def hexToDec(hexadecimal):
    '''gets an hexadecimal as a string and returns a string decimal'''
    hexadecimal_unsigned = ''
    decimal = 0
    sign_present = False
    for i in hexadecimal: #checks if hex value has a '-' and removes it
        if i == '-':
            sign_present = True #if it's true, we'll add it again after the conversion
        else:
            hexadecimal_unsigned += i
    for index, value in enumerate(hexadecimal_unsigned): #for every char in the unsigned hexadecimal
        try:
            digit_value = int(value) #we add the int value if we can convert it to int
        except ValueError:
            digit_value = cToHex[value.upper()] #we convert a letter to int with the dictionary if the ValueError happens #.upper makes sure it's a capital char like in the dict
        decimal += digit_value*16**(len(hexadecimal_unsigned)-1-index) # we add to the final decimal value the value of the digit multiplied to the base**index reversed

    if sign_present == True:
        return ('-' + str(decimal))
    else:
        return str(decimal)
def octToDec(octal):
    '''gets a octal string and returns a string int'''
    if (int(octal) > 0): #i can do this because octal is considered an int
        decimal = 0
        octal_list = [int(x) for x in str(octal)] #this converts the octal string to a list of digits
        for index, value in enumerate(octal_list):
            #print(f'Index: {index}\nValue: {value}\nDecimal: {decimal}\nOppsite index: {(len(octal_list)-1-index)}') #debugger
            decimal += value*8**(len(octal_list)-1-index)
        return str(decimal)
    elif (int(octal) < 0):
        octal = str(-int(octal))
        return ('-' + str(octToDec(octal)))
    else:
        return '0'

def main():
    while(True):
        global base
        global convert 
        global user_input
        menu_base = menuBase()
        base = menuChoiches[menu_base]
        conversionTo = menuConversion()
        convert = menuChoiches[conversionTo]
        infoChoicheMenu()
        if (base == 'Decimal'):
            decimal = getDec()
            user_input = decimal
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
            user_input = decimal
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
        elif (base == 'Octal'):
            octal = getOct()
            user_input = decimal
            if (convert == 'Binary'):
                decimal = octToDec(octal)
                binary = decToBin(decimal)
                printResult(binary)
            elif (convert == 'Decimal'):
                decimal = octToDec(octal)
                printResult(decimal)
            elif (convert == 'Octal'):
                printResult(octal)
            elif (convert == 'Hexadecimal'):
                decimal = octToDec(octal)
                hexadecimal = decToHex(decimal)
                printResult(hexadecimal)
            else:
                pass #This should be unreachable code
        elif (base == 'Hexadecimal'):
            hexadecimal = getHex()
            user_input = decimal
            if (convert == 'Binary'):
                decimal = hexToDec(hexadecimal)
                binary = decToBin(decimal)
                printResult(binary)
            elif (convert == 'Decimal'):
                decimal = hexToDec(hexadecimal)
                printResult(decimal)
            elif (convert == 'Octal'):
                decimal = hexToDec(hexadecimal)
                octal = decToOct(decimal)
                printResult(octal)
            elif (convert == 'Hexadecimal'):
                printResult(hexadecimal)
            else:
                pass #This should be unreachable code
        exitMenu()
         
def exitMenu():
    while(True): #Exit menu
            try:
                #print('\n')
                print('________________________________________')
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
    
def infoChoicheMenu(): #what you choose
    clear()
    printOk('Input recieved')
    printInfo(f'You choose to convert {base} to {convert}')  

def printResult(result): #I can declare it here using the "main link": if __name__ == '__main__', for more see: (https://stackoverflow.com/questions/3754240/declare-function-at-end-of-file-in-python)
    clear()
    #print('_________________________')
    printOk('Result calculated')
    printInfo(f'You converted from {base} to {convert} the number {user_input}')
    printInfo(f'Your result is: =>| {result} |<=')
    #print('_________________________')

if __name__ == '__main__': #this links to main(), is the start of the program in the end.
    main()