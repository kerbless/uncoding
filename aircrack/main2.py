#imports
import os
import subprocess
import re
import sys

#NOTES
'''
[IDEA] Man page --> print whole file (?)
[SEARCH] How other programs work with CLI args and settings and print help

'''

#global settings
min_args = 2
max_args = 3
prog_name = "main2.py"

#text output dict 
def display(text):
    if(text == 'verbosity1'):
        print("\nThis is the selected suitable interface:\n")
        print(interface_selected)
    elif(text == 'verbosity2'):
        print ('Number of arguments:', len(sys.argv))
        print ('Argument List:', str(sys.argv))
        print("\nThe airmon_ng_list:")
        print(airmon_ng_list)
        print("\nFound these interfaces:\n") 
        print(ls_interfaces_list)
    elif(text == 'help'):
        print("Please use: " + prog_name + " [verbosity] [option]\n\n")
        print("Verbosity:\n\t0 = None\n\t1 = Standard\n\t2 = Max")

    else:
        print("")

#sys.exit("Error in parameter\nUse: " + prog_name + " --help")

if((len(sys.argv) < min_args) | (len(sys.argv) > max_args)): #control number of arguments
    display("help")
    sys.exit()
elif((sys.argv[1] == "--help") | (sys.argv[1] == "help")): #check for help command
    display("help")
    sys.exit()
else:
    try:
        verbosity = int(sys.argv[1])
    except:
        exit("Error in parameter \"verbosity\"\nUse: " + prog_name + " --help")
    if((verbosity < 0) | (verbosity > 2)): 
        sys.exit("there is no verbosity \"" + sys.argv[1] + "\"")

#airmon_ng finding suitable interfaces
airmon_ng = subprocess.run(['sudo', 'airmon-ng'],
    stdout = subprocess.PIPE)
airmon_ng_str = str(object=airmon_ng.stdout, encoding='utf-8')
airmon_ng_list = re.split('\W+', airmon_ng_str)
airmon_ng_list = list(filter(None, airmon_ng_list))

#ls gettting all interfaces
ls_interfaces = subprocess.run(['sudo', 'ls', '-1', '/sys/class/net'],
    stdout = subprocess.PIPE)
ls_interfaces_str = str(object=ls_interfaces.stdout, encoding='utf-8')
ls_interfaces_list = re.split('\W+', ls_interfaces_str)
ls_interfaces_list = list(filter(None, ls_interfaces_list)) #https://www.geeksforgeeks.org/iterators-in-python/

#comparing airmon and ls - getting final interface
for i in airmon_ng_list:
    for j in ls_interfaces_list:
        if i == j:
            interface_selected = j

#verbosity
if(verbosity == 1):
    display("verbosity1")
if(verbosity == 2):
    display("verbosity2")
    display("verbosity1")
