import keyboard


def out():
    print("received")
    keyboard.send("1")
    print("sent")


def rec():
    keyboard.wait("enter", False)
    keyboard.hook_key("enter", out(), True)


rec()
