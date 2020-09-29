import os
import subprocess
import re

#airmon_ng finding suitable interfaces
airmon_ng = subprocess.run(['sudo', 'airmon-ng'],
    stdout = subprocess.PIPE)
airmon_ng_str = str(object=airmon_ng, encoding='utf-8')
airmon_ng_list = re.split('\W+', airmon_ng_str)

#ls gettting all interfaces
ls_interfaces = subprocess.run(['sudo', 'ls', '-1', '/sys/class/net'],
    stdout = subprocess.PIPE)
ls_interfaces_str = str(object=ls_interfaces, encoding='utf-8')
ls_interfaces_list = re.split('\n', ls_interfaces_str)


for i in range(len(ls_interfaces_list)):
    print(ls_interfaces_list[i])
