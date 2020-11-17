def dec2bin():
	decimal = int(input("Inserisci un numero decimale, io ti stampo su schermo il suo valore in binario, ottale ed esadecimale\n\n> "))
	binary = []
	while decimal != 0:
		if decimal % 2 == 0:
			binary.append(0)
		else:
			binary.append(1)
		decimal /= 2
		decimal = int(decimal)
	binary.reverse()
	binary = ''.join([str(elem) for elem in binary]) # it converts a list in a string data type
	print("\n" + binary)

dec2bin()

#TODO dec2hex convertion + dec2oct convertion
