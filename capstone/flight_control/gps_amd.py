#!/usr/bin/env python
from dronekit import connect, VehicleMode, LocationGlobalRelative
import time


"""
Take off
"""
def takeoff(vehicle, aTargetAltitude):
	print "Taking off!"
	vehicle.simple_takeoff(aTargetAltitude)
	while True:
		print "Altitude: ", vehicle.location.global_relative_frame.alt
		if vehicle.location.global_relative_frame.alt >= aTargetAltitude*0.95:
			print "Reached target altitude: ", aTargetAltitude
			break
		time.sleep(1)


"""
GPS based flight
"""
def gpsFlight(vehicle, latitude, longitude, altitude=None, groundSpeed=None):
	print "Going towrad target location... ", 
	point = LocationGlobalRelative(latitude, longitude, altitude)
	vehicle.simple_goto(point, groundSpeed)
	current_lat = vehicle.location.global_relative_frame.lat
	current_lon = vehicle.location.global_relative_frame.lon
	current_alt = vehicle.location.global_relative_frame.alt
	
	latitudeDifference = abs(abs(current_lat)-abs(latitude*0.99999999999999999999))
	longitudeDifference = abs(abs(current_lon) - abs(longitude*0.99999999999999999))
	while True:
		print "Latitude: ", current_lat
		print "Longitude: ", current_lon
		#print "Altitude: ", current_alt
		if latitudeDifference <= 0.01 and longitudeDifference <= 0.01 and current_alt >= altitude*0.95:
			print "Reached destination"
			break
	time.sleep(1)



