import keyboard
import time


KEY = 'enter'
counting = False
count = 0
timer = 0
TIMEOUT = 300 # milliseconds

def millis():
    return int(time.time()*1000) # milliseconds

def callback(event):
    print(event)
    print(event.name)
    print(event.event_type)
    global counting, count, timer
    timer = millis()
    if counting:
        count = count + 1
    else: # not counting
        count = 1
        counting = True


# MAIN

keyboard.on_press_key(KEY, callback, suppress=True)

while not keyboard.is_pressed('esc'):
    if counting and (millis() - timer > TIMEOUT):
        print('enter pressed %d times' % count)
        counting = False