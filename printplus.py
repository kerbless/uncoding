'''
TODO I want this file to be a class with a method printplus()
I want printplus to accept "dinamically" (with overloading? -> you can't do it /w python) these arguments (I included the default value): 
str text, slowprint=True, continue=False, tag=None
tags are the p_info etc you see in the code below

how should I implement this?
'''

import time

colors = {
    'Reset'  : '\033[0m',      # Reset
    'Black'  : '\033[0;30m',   # Black
    'Red'    : '\033[0;31m',   # Red
    'Green'  : '\033[0;32m',   # Green
    'Yellow' : '\033[0;33m',   # Yellow
    'Blue'   : '\033[0;34m',   # Blue
    'Purple' : '\033[0;35m',   # Purple
    'Cyan'   : '\033[0;36m',   # Cyan
    'White'  : '\033[0;37m'    # White
    }

p_info = (colors['Blue'] + '[INFO] ') 
p_ok = (colors['Green'] + '[OK] ') 
p_error = (colors['Red'] + '[ERROR] ') 
p_in = (colors['Yellow'] + '[IN] ')
p_end = ('' + colors['Reset'])

def slowprint(string):
    for i in string:
        print(i, end='', flush=True)
        time.sleep(.02)
    print('') #Saves the newline function at the end of every slowprint()

def print_continue(string):
    print(string, end='', flush=True)

def printInfo(text):
    print(p_info + p_end + text)

def printError(text):
    print(p_error + p_end + text)

def printOk(text):
    print(p_ok + p_end + text)

def printIn(text):
    print_continue(p_in + p_end + text)

def printplus():
    print('you did\'t enter text in a printplus function')

def printplus(text):
    print(text)

def printplus(text):
    print(text)

