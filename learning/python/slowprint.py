import time

def slowprint(string):
    for i in string:
        print(i, end="", flush=True)
        time.sleep(.1)
    print("") #Saves the newline function at the end of every slowprint()
    
text = "Hello, World!"
slowprint(text)