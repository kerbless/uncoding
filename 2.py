import os
import subprocess
import re

#airmon_ng finding suitable interfaces
airmon_ng = subprocess.run(['sudo', 'airmon-ng'],
    stdout = subprocess.PIPE)
airmon_ng_str = str(object=airmon_ng.stdout, encoding='utf-8')
airmon_ng_list = re.split('\W+', airmon_ng_str)
#airmon_ng_set = set(airmon_ng_list)

#ls gettting all interfaces
ls_interfaces = subprocess.run(['sudo', 'ls', '-1', '/sys/class/net'],
    stdout = subprocess.PIPE)
ls_interfaces_str = str(object=ls_interfaces.stdout, encoding='utf-8')
ls_interfaces_list = re.split('\n', ls_interfaces_str)
#ls_interfaces_set = set(ls_interfaces_list)

#comparing airmon and ls - getting final interface
#interfaces_set = ls_interfaces_set.difference(airmon_ng_set)
#interfaces_list = list(interfaces_set)
found = 0 
interfaces_list = []
for i in range(len(airmon_ng_list)):
    for j in range(len(ls_interfaces_list)):
        if (ls_interfaces_list[j] == airmon_ng_list[i]):
            interfaces_list[found] == ls_interfaces_list[j]
            found += 1

#printing (verbosity)
print("\nThe airmon_ng_list:")
for i in range(len(airmon_ng_list)):
    print(airmon_ng_list[i])
print("\nFound these interfaces:\n") 
for i in range(len(ls_interfaces_list)):
    print(ls_interfaces_list[i])
print("\nThese are the selected suitable interfaces:\n")
for i in range(len(interfaces_list)):
    print(interfaces_list[i])
