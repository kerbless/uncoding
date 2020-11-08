#imports
import os
import time
import output_formatting
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
    out = ""
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
                print('[!]',  error, '[!]')
                print('try again:\n')
            print('Choose the base of the number you want to convert')
            print('1. Decimal')
            print('2. Binary')
            print('3. Octal')
            print('4. Hexadecimal')
            print('_________________________________________________')
            base = int(input('insert choice [1-4]: ')) #If the input is not an input, it jumps to ValueError
            if (base < 1 or base > 4):
                raise(ValueError)
            else:
                return base
            break
        except ValueError:
           error = 'You didn\'t enter a valid number'
def menuConversion():
    error = ''
    while(True):
        try:
            clear()
            print('________________________________________________________')
            if (error != ''):
                print('[!]',  error, '[!]')
                print('try again:\n')
            print('Choose the base you want your number to be converted to:')
            print('1. Decimal')
            print('2. Binary')
            print('3. Octal')
            print('4. Hexadecimal')
            print('________________________________________________________')
            base = int(input('insert choice [1-4]: ')) #If the input is not an input, it jumps to ValueError
            if (base < 1 or base > 4):
                raise(ValueError)
            else:
                return base
            break
        except ValueError:
           error = 'You didn\'t enter a valid number'

#conversion functions
def decToBin():
    '''gets a integer and returns the binary value as TODO(list)'''
    rests = [] #declare list
    while (True): #wait for decimal to be 0
        rest = decimal % 2
        decimal = decimal // 2 # 0// is the integer division, no rest.
        rests.append(rest)
        if (decimal == 0):
            break #emulates a do-while loop
    rests.reverse() #reverse the list
    return rests;
def decToOct():
    pass
def decToHex():
    pass


'''[____MAIN____]'''
base = menuBase()
conversionTo = menuConversion()
#Your choice:
clear() 
slowprint("[OK] Input recieved")
slowprint(f"[INFO] You choose to convert ({menuChoiches[base]}) to ({menuChoiches[conversionTo]})")