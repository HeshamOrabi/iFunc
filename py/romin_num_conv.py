#!/usr/bin/python3

import sys

def roman_to_int(roman):
	if not roman:
		return None

	roman_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
	total = 0

	for char in reversed(roman):
		value = roman_dict.get(char, 0)

		if value == 0:
			return None  # Invalid Roman numeral
		else:
			total += value if total < value * 5 else -value

	return total

while True:
	try:
		roman_input = input("Enter a Roman numeral to be converted (or 'STOP' to quit): ")

		if roman_input.upper() == "STOP":
			break

		result = roman_to_int(roman_input)

		if result is None:
			print("Enter a valid Roman numeral.")
		else:
			print("The equivalent integer value is:", result)
	except EOFError:
		print("End of input reached. Exiting.")
		sys.exit(0)
