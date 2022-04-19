# Amanda Violet Moore
# SNHU CS 210 Project 3

import re
import string

def printsomething():
	print("Hello from python!")

def PrintMe(v):
	print("You sent me:" + v)
	return 100;

def SquareValue(v):
	return v * v

def DailyItemsPurchased():
	daily_items = {}
	filename = 'CS210_Project_Three_Input_File.txt'
	
	# opens file 
	with open(filename, 'r') as file:
		for item in file.readlines(): 
			item = item.strip()       # removes any spaces
			if item in daily_items:   # increments occurences by 1 if item is already in daily_items dictionary
				daily_items[item] += 1
			else:
				daily_items[item] = 1 # sets occurences to 1 if item is not in daily_items dictionary

	# prints each item and its occurences
	for item, count in daily_items.items():
		print('{}: {}'.format(item, count))

def TimesItemPurchased(itemname):
	daily_items = {}
	occurrences = 0
	filename = 'CS210_Project_Three_Input_File.txt'
	
	# opens file 
	with open(filename, 'r') as file:
		for item in file.readlines(): 
			item = item.strip()       # removes any spaces
			if item in daily_items:   # increments occurences by 1 if item is already in daily_items dictionary
				daily_items[item] += 1
			else:
				daily_items[item] = 1 # sets occurences to 1 if item is not in daily_items dictionary

	# checks if itemname is in the daily_items dictionary and returns occurrences
	for item, count in daily_items.items():
		if itemname in daily_items:
			occurrences = daily_items[itemname]

	return occurrences

def WriteFile():
	daily_items = {}
	filename = 'CS210_Project_Three_Input_File.txt'
	writefile = 'frequency.dat'
	# opens file 
	with open(filename, 'r') as file:
		for item in file.readlines(): 
			item = item.strip()       # removes any spaces
			if item in daily_items:   # increments occurences by 1 if item is already in daily_items dictionary
				daily_items[item] += 1
			else:
				daily_items[item] = 1 # sets occurences to 1 if item is not in daily_items dictionary
	# writes items and times purchased to a new file
	with open('frequency.dat', 'w') as f:
		for item, count in daily_items.items():
			f.write('{} {}'.format(item, count))
	# closes file after written
	writefile.close()
		