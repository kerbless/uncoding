import os
import subprocess
import re

def remove_whitespaces(in_list):
    for i in in_list:
        in_list.append(i.strip())
    return in_list

#airmon_ng finding suitable interfaces
airmon_ng = subprocess.run(['sudo', 'airmon-ng'],
    stdout = subprocess.PIPE)
airmon_ng_str = str(object=airmon_ng.stdout, encoding='utf-8')
airmon_ng_list = re.split('\W+', airmon_ng_str)
airmon_ng_list = remove_whitespaces(airmon_ng_list)

#ls gettting all interfaces
ls_interfaces = subprocess.run(['sudo', 'ls', '-1', '/sys/class/net'],
    stdout = subprocess.PIPE)
ls_interfaces_str = str(object=ls_interfaces.stdout, encoding='utf-8')
ls_interfaces_list = re.split('\n', ls_interfaces_str)
ls_interfaces_list = remove_whitespaces(ls_interfaces_list)

#comparing airmon and ls - getting final interface
for i in airmon_ng_list:
    for j in ls_interfaces_list:
        if i == j:
            interface_selected = j
            break
#verbosity
print("\nThe airmon_ng_list:")
print(airmon_ng_list)
print("\nFound these interfaces:\n") 
print(ls_interfaces_list)
print("\nThis is the selected suitable interface:\n" + interface_selected)
print(len(ls_interfaces_list))
print(ls_interfaces_list)
