import time

def slowprint(string):
    for i in string:
        print(i, end="", flush=True)
        time.sleep(.1)

text = "Hello, World!"
slowprint(text)