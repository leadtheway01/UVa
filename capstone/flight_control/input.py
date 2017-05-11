#!/usr/bin/env python


while True:
	input = raw_input("Up: u, Down: d, Right: r, Left:l, exit: 0")
	if input is "u":
		print "UP"
	elif input is "d":
		print "DONW"
	elif input is "r":
		print "RIGHT"
	elif input is "l":
		print "Left"
	elif input is "0":
		break

