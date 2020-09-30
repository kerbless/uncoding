import keyboard
import time


# TODO add hotkey to pause/resume program
# TODO configure to start/shutdown automatically with ableton (shortcut + exit() condition?)


def clock():
    return time.perf_counter() * 1000  # conversion to milliseconds


delay_max_threshold = 300  # in milliseconds # modify this as you need
delay_min_threshold = 10  # to avoid long press multiple input #TODO
press_counter = 0
release_counter = 0
last_call_time_press = 0
last_call_time_release = 0  # not that useful now
second_call = False
ready = False


def out():
    print("[invoked]", out.__name__)
    global press_counter, release_counter, ready, second_call
    dict_first = {
        1: "1",
        2: "2",
        3: "3",
        4: "4",
        5: "5"
    }
    dict_second = {
        1: "6",
        2: dict_first[2],
        3: dict_first[3],
        4: dict_first[4],
        5: dict_first[5],
    }
    if press_counter > 5 or release_counter > 5:  # avoid getting more than 5 clicks
        press_counter = 5
        release_counter = 5
    if second_call is False:
        keyboard.send(dict_first[press_counter], do_press=True, do_release=True)
        second_call = True
    elif second_call is True:
        keyboard.send(dict_second[press_counter], do_press=True, do_release=True)
        second_call = False
    if press_counter > 1:
        '''
        This if makes the second_call feature work only when you press one time.
        So you won't find yourself in the second_press state after a triple click.
        '''
        second_call = False
    # second_call = False  # Uncomment to disable second_call feature
    press_counter = 0
    ready = False


def press_callback(event):
    """
    the "event" parameter is type "object"
    this code doesn't generate error:
    obj = keyboard.KeyboardEvent('enter', 1)
    press_callback(obj)
    would be cool to investigate more
    """
    print("[invoked]", press_callback.__name__)

    global last_call_time_press, ready, press_counter
    last_call_time_press = clock()
    press_counter += 1
    ready = True


'''
def release_callback(event):
    print("[invoked]", release_callback.__name__)
    global release_counter, last_call_time_release, ready
    release_counter += 1
    last_call_time_release = clock()
    ready = True
'''

keyboard.on_press_key("enter", press_callback, suppress=True)  # callback does not want brackets
# keyboard.on_release_key("enter", release_callback, suppress=True)

# MAIN
i = 0
while keyboard.is_pressed("esc") is False:
    i += 1
    if ready is True:  # Ready to output values, checks if time since last call is ok and proceeds to out()
        if clock() - last_call_time_press > delay_max_threshold:
            out()
        else:
            time.sleep(delay_max_threshold / 1000)
    elif keyboard.is_pressed("i") is True:  # Lists some useful info
        print("_____________________________")
        print("Iterations:", i)
        print("press_counter:", press_counter)
        print("release_counter:", release_counter)
        print("last_call_time:", last_call_time_press)
        print("ready:", ready)
        print("last call time difference:", clock() - last_call_time_press)
        print("_____________________________")
        time.sleep(0.2)
    elif keyboard.is_pressed("r") is True:  # Resets second_call state
        second_call = False
        print("second_press set to false")
    else:
        time.sleep(0.1)  # basically reduces polling rate
