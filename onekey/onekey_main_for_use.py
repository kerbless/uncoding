import keyboard
import time


def clock():
    return time.perf_counter() * 1000


delay_max_threshold = 300
delay_min_threshold = 10
press_counter = 0
last_call_time_press = 0
ready = False


def out():
    global press_counter, ready
    dict_first = {
        1: "1",
        2: "down arrow",
        3: "up arrow",
        4: "4",
        5: "5"
    }
    if press_counter > 5:
        press_counter = 5
    keyboard.send(dict_first[press_counter], do_press=True, do_release=True)
    press_counter = 0
    ready = False


def press_callback(event):
    global last_call_time_press, ready, press_counter
    last_call_time_press = clock()
    press_counter += 1
    ready = True


keyboard.on_press_key("enter", press_callback, suppress=True)


i = 0
while keyboard.is_pressed("esc") is False:
    i += 1
    if ready is True:
        if clock() - last_call_time_press > delay_max_threshold:
            out()
        else:
            time.sleep(delay_max_threshold / 1000)
    else:
        time.sleep(0.05)
