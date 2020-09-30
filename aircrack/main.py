import os
import subprocess
import re

#airmon_ng finding suitable interfaces
airmon_ng = subprocess.run(['sudo', 'airmon-ng'],
    stdout = subprocess.PIPE)
airmon_ng_str = str(object=airmon_ng.stdout, encoding='utf-8')
airmon_ng_list = re.split('\W+', airmon_ng_str)
#ls gettting all interfaces
ls_interfaces = subprocess.run(['sudo', 'ls', '-1', '/sys/class/net'],
    stdout = subprocess.PIPE)
ls_interfaces_str = str(object=ls_interfaces.stdout, encoding='utf-8')
ls_interfaces_list = re.split('\n', ls_interfaces_str)

#comparing airmon and ls - getting final interface
#interfaces_list = [0, 0, 0, 0] #using this everything works, but why?
interfaces_list = []
f = 0
for i in airmon_ng_list:
    for j in ls_interfaces_list:
        if i == j:
            interfaces_list[f] = j
            f += 1

#verbosity
print("\nThe airmon_ng_list:")
for i in range(len(airmon_ng_list)):
    print(airmon_ng_list[i])
print("\nFound these interfaces:\n") 
for i in range(len(ls_interfaces_list)):
    print(ls_interfaces_list[i])
print("\nThese are the selected suitable interfaces:\n")
for i in range(len(interfaces_list)):
    print(interfaces_list[i])
