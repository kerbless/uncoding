colors = {
    'reset' : '\033[0m', # color reset (/)
    'green' : '\033[0;32m', # color good (green)
    'red' : '\033[0;31m', #color bad (red)
    'light blue' : '\033[0;34m', #color info (light blue)
    'data' : '\033[1m' #what  color is thissss
    }
p_info = (colors['light_blue'] + "[INFO] ") 
p_ok = (colors['green'] + "[OK] ") 
p_error = (colors['red'] + "[ERROR] ") 
p_data = (colors['data'] + " -> ")
p_end = ("" + colors['reset'])

def slowprint(string):
    for i in string:
        print(i, end="", flush=True)
        time.sleep(.1)
    print("") #Saves the newline function at the end of every slowprint()

def printInfo(text)
    slowprint()