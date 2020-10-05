#imports
import os
import subprocess
import re
import sys
import shlex

#TODO add some try except with errors


#output formatting
C_R = '\033[0m' # color reset (/)
C_G = '\033[0;32m' # color good (green)
C_B = '\033[0;31m' #color bad (red)
C_I = '\033[0;34m' #color info (light blue)
C_W = '' #color titles (white)
p_info = (C_I + "[INFO] ") 
p_ok = (C_G + "[OK] ") 
p_error = (C_B + "[ERROR] ") 
p_data = ('\033[1m' + " -> ")
p_end = ("" + C_R)

def execut(command):
    '''
    For more information read:
    https://stackoverflow.com/questions/984941/python-subprocess-popen-from-a-thread
    https://docs.python.org/3/library/subprocess.html#subprocess.Popen.communicate
    https://stackoverflow.com/questions/4417546/constantly-print-subprocess-output-while-process-is-running
    '''
    argsList = shlex.split(command) #automatically splits the command in a list for the subprocess.Popen
    process = subprocess.Popen(argsList, stdout=subrpocess.PIPE, stderr=subprocess.STDOUT) #Popen does not automatically call "communicate" method
    process.communicate #this does not return a tuple because of stderr=STDOUT

    

    process.wait() #waits for the process to end
    exitCode = process.returncode
    
    if (exitCode == 0):
        return output
    else:
        raise ProcessException(command, exitCode, output)

def exit_routine():
    #exiting routine
    print(p_info + "Initializing exiting routine..." + p_end)
    print(p_info + "Restoring network configuration..." + p_end)
    print(p_info + "Restoring card station mode..." + p_end)
    #os.system("sudo airmon-ng stop " + interface_selected + "mon")
    subprocess.run(['sudo', 'airmon-ng', 'stop', interface_selected], stdout = subprocess.PIPE)
    print(p_info + "Restoring network manager..." + p_end)
    os.system("sudo service network-manager start")
    print(p_ok + "Network manager restarted" + p_end)
    print(p_ok + "Exiting script" + p_end)

try: #manages exit routine exceptions, restores the previou network configuration on forced exits
    #airmon_ng finding suitable interfaces
    print(p_info + "Retrieving airmon-ng output list" + p_end)
    airmon_ng = subprocess.run(['sudo', 'airmon-ng'], stdout = subprocess.PIPE)
    airmon_ng_str = str(object=airmon_ng.stdout, encoding='utf-8')
    airmon_ng_list = re.split('\W+', airmon_ng_str)
    airmon_ng_list = list(filter(None, airmon_ng_list)) #https://www.geeksforgeeks.org/iterators-in-python/
    print(p_ok + "Retrieved arimon-ng output" + p_end)

    #ls gettting all interfaces
    print(p_info + "Retrieving interfaces" + p_end)
    ls_interfaces = subprocess.run(['sudo', 'ls', '-1', '/sys/class/net'], stdout = subprocess.PIPE)
    ls_interfaces_str = str(object=ls_interfaces.stdout, encoding='utf-8')
    ls_interfaces_list = re.split('\W+', ls_interfaces_str)
    ls_interfaces_list = list(filter(None, ls_interfaces_list))
    print(p_ok + "Retrieved interfaces list" + p_end) 

    #comparing airmon and ls - getting final interface
    print(p_info + "Comparing lists, getting interface..." + p_end)
    for i in airmon_ng_list:
        for j in ls_interfaces_list:
            if i == j:
                interface_selected = j
    print(p_ok + "Interface selected" + p_end + p_data + interface_selected + p_end)

    #configuring monitor mode
    print(p_info + "Configuring monitor mode" + p_end)
    print(p_info + "Setting up airmon-ng, running 'check kill'..." + p_end)
    subprocess.run(['sudo', 'airmon-ng', 'check', 'kill'], stdout = subprocess.PIPE)
    #print((str(object=airmon_ng_setup.stdout, encoding='utf-8')))
    print(p_info + "Changing card mode to monitor..." + p_end)
    subprocess.run(['sudo', 'airmon-ng', 'start', interface_selected], stdout = subprocess.PIPE)
    print(p_ok + "Done, card ready in monitor mode" + p_end)
    interface_selected = interface_selected+"mon"
    '''
    #getting dumps
    print(p_info + "Running airodump, getting data...")
    airodump = subprocess.run(['sudo', 'airodump-ng', interface_selected], stdout = subprocess.PIPE)
    '''
    exit_routine()
except KeyboardInterrupt: #captures ctrl-C
    exit_routine()
