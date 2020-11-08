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

#utility functions
def clear():
    os.system( 'cls' )

def listToStr(list_):
    '''convert list to string'''
    out = ''
    for i in list_:
        out = out+str(i)
    return out

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
            in_ = int(input())
            return in_
        except ValueError:
            printError('You didn\'t enter a number') 
def getBin(): #TODO
    pass
def getOct(): #TODO
    pass
def getHex(): #TODO
    pass

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
    elif (decimal < 0):
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
    else:
        return '0'

def decToOct(): #TODO
    pass
def decToHex(): #TODO
    pass

'''Testing''' #TODO remove, develop use


'''[____MAIN____]'''

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
    binary = decToBin(decimal)
    printResult(binary)
elif (base == 'Binary'): #TODO
    pass
elif (base == 'Octal'): #TODO
    pass
elif (base == 'Hexadecimal'): #TODO
    pass
else:
    printError('Fatal Error')