print("\tSOLVE A SECOND GRADE EQUATION")
print("Please insert a,b,c like in (ax^2+bx+c=0)")
try:
    a = float(input("Insert a: "))
    b = float(input("Insert b: "))
    c = float(input("Insert c: "))
except ValueError:
    print("You didn't enter a valid number, exiting.")
delta = b*b-4*a*c
print("Delta is: " + str(delta))
if(delta > 0):
    x1 = (-b+(delta**0.5))/(2*a) #delta^0.5 == math.sqrt(delta)
    x2 = (-b-(delta**0.5))/(2*a)    
else:
    x1 = 0
    x2 = -b/(2*a)
print("Solutions are, x1 = %.3lf and x2 = %.3lf" % (x1, x2))

'''
String formatting alternatives:


#print("Solutions are, x1 = " + str(x1) + " and x2 = " + str(x2))


string_a = "Hello"
string_b = "Cena"

# Index based:
print("{0}, John {1}"
      .format(string_a, string_b))
# Object based:
print("{greeting}, John {last_name}"
      .format(greeting=string_a, last_name=string_b))
'''
