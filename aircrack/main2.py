import os
import subprocess
import re
import sys
max_args = 2
print ('Number of arguments:', len(sys.argv))
print ('Argument List:', str(sys.argv))

def display(text):
    if(text == 'verbosity1'):
        print("\nThis is the selected suitable interface:\n")
        print(interface_selected)
    elif(text == 'verbosity2'):
        print("\nThe airmon_ng_list:")
        print(airmon_ng_list)
        print("\nFound these interfaces:\n") 
        print(ls_interfaces_list)
    elif(text == 'help'):
        print("TODO")
    else:
        print("")

if((len(sys.argv) == 1) | (len(sys.argv) > max_args)):
    display("help")
else:
    verbosity = int(sys.argv[1])
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
