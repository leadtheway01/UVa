#!/usr/bin/env python

from dronekit import connect, VehicleMode, LocationGlobalRelative, LocationGlobal
from gps_amd import takeoff, gpsFlight
from preflight_amd import close, getAttributes, getHomeLocation, setVehicleMode, isArmable
from image_amd import condition_yaw, send_ned_velocity
from pymavlink import mavutil
from bullseyeImage import image
import time


################################################################
"""
parameters
"""

# takeoff(vechile, aTargetAltitude)
aTargetAltitude = 4 
# gpsFlight(vechile, latitude, longitude, altitude=None, groundSpeed=None)
gpsLatitude = 38.035241       # testing value. Corner of reactor 38.035241
gpsLongitude = -78.521338     # testing value. Corner of reactor -78.521338
gpsAltitude = aTargetAltitude
gpsGroundSpeed = 1

# image-based flight
image_based = True
# count number of "DOWN" instruction from OpenCV
count = 0

#Set up velocity vector to map to each direction.
# vx > 0 => fly North
# vx < 0 => fly South
NORTH = 0.5
SOUTH = -0.5

# Note for vy:
# vy > 0 => fly East
# vy < 0 => fly West
EAST = 0.5
WEST = -0.5

# Note for vz: 
# vz < 0 => ascend
# vz > 0 => descend
UP = -0.5
DOWN = 0.5

# variable for image based flight
direction = None

"""
end of parameters
"""
################################################################

################################################################
# initialize program
# Set up option parsing to get connection string
# e.g. python ./amd.py --connect /dev/ttyACM0, 57600
import argparse
parser = argparse.ArgumentParser(description='Print out vehicle state information. Connects to SITL on local PC by default.')
parser.add_argument('--connect', help="vehicle connection target string, If not specified, SITL automatically started and used.")
args = parser.parse_args()

connection_string = args.connect
sitl = None

# Start SITL if no connection string specified
if not connection_string:
        import dronekit_sitl
        sitl = dronekit_sitl.start_default()
        connection_string = sitl.connection_string()

# Connect to the vehicle, Iris+
# Set 'wait_ready=True' to ensure defualt attributes are populated before 'connect()' returns
print"\nConnecting to vehicle on: %s" %connection_string

# For all functions with vechile variable, pass object 'vechile'
# Creat vehicle object by connecting
vehicle = connect(connection_string, wait_ready=True)

# Wait unitl vechile is connected
vehicle.wait_ready('autopilot_version')

# Get all predefined vehocle attributes (state)
# Can add more if needed
getAttributes(vehicle)

#Get vehicle home location (gps)
getHomeLocation(vehicle)

# for customized RTL
# set  home location values
RTL_lat =  vehicle.home_location.lat
RTL_lon =  vehicle.home_location.lon
RTL_alt =  vehicle.home_location.alt
########################################################################


########################################################################
"""
Pre-arm checking and arming
"""
# Set vehicle mode to GUIDED	  
setVehicleMode(vehicle, "GUIDED") 
# Check that vehicle is armable	  
isArmable(vehicle)		  

#######################################################################



#######################################################################
"""
Flight starts
"""
# Take off to taret altitude
takeoff(vehicle, aTargetAltitude)

# To go to destination using gps
print("Initiating GPS based flight")
gpsFlight(vehicle, gpsLatitude, gpsLongitude, gpsAltitude, gpsGroundSpeed)

# LEFT RIGHT FORWARD BACKWARD DESCEND  
# Image based control
while image_based:
	direction = image()
	if count != 3:
		if direction is 'FORWARD':
			print("moving forward")
			send_ned_velocity(vehicle, NORTH, 0, 0, 1)
		elif direction is 'BACKWARD':
			print("moving backward")
			send_ned_velocity(vehicle, SOUTH, 0, 0, 1)
		elif direction is 'LEFT':
			print("moving to the left")
			send_ned_velocity(vehicle, 0, WEST, 0, 1)
		elif direction is 'RIGHT':
			print("moving to the right")
			send_ned_velocity(vehicle, 0, EAST, 0, 1)
		elif direction is 'DESEND':
			print("desending")
			send_ned_velocity(vehicle, 0, 0, DOWN, 2)
			count = count + 1
	elif count == 2:
		# to break out of the image flight
		image_based = False
		break
#######################################################################

########################################################################
# Landing on target
print("Landing on target")
while True:
        print "Altitude: ", vehicle.location.global_relative_frame.alt
        if vehicle.location.global_relative_frame.alt < 0.2:
                print "Landed on target"
                break
        else:
        send_ned_velocity(vehicle, 0, 0, DOWN, 7)
########################################################################

# user input flight for testing
# delete later
"""
while image:
	if count < 2:
		input = raw_input("UP: u, DOWN: d, RIGHT: r, LEFT:l, FORWARD: f, BACKWARD: b, exit: 0\n")
        	if input is "u":
               		print "Moving up"
               		send_ned_velocity(vehicle, 0, 0, UP, 2)
        	elif input is "d":
               		print "Moving down"
               		send_ned_velocity(vehicle,0, 0, DOWN, 2)
			count += 1
        	elif input is "r":
               		print "Moving Right"
			send_ned_velocity(vehicle, 0, EAST, 0, 2)
        	elif input is "l":
                	print "Moving Left"
               		send_ned_velocity(vehicle, 0, WEST, 0, 2)
		elif input is "f":
			print "Moving Forward"
			send_ned_velocity(vehicle, NORTH, 0, 0, 2)
		elif input is "b":
			print "Moving Backward"
			send_ned_velocity(vehicle, SOUTH, 0, 0, 2)
        	elif input is "0":
               		print "exiting"
               		break
	elif count == 2:
		while True:
			print "Altitude: ", vehicle.location.global_relative_frame.alt
			if vehicle.location.global_relative_frame.alt < 0.2:
				print "Landed on target"
				image = False
				break
			else:
				send_ned_velocity(vehicle, 0, 0, DOWN, 7)
"""

"""
run servo to drop the mail

once mail is dropped, rtl

"""
# take off to target altitude to rtl
takoff(vehicle, aTargetAltitude)

#######################################################################
# customized RTL
gpsFlight(vehicle, RTL_lat, RTL_lon, aTargetAltitude, gpsGroundSpeed)

while True:
	print "Altitude: ", vehicle.location.global_relative_frame.alt
	if vehicle.location.global_relative_frame.alt < 0.2:
		print "Landed on target"
		break
	else:
	send_ned_velocity(vehicle, 0, 0, DOWN, 7)

print "Mission Accomplished"
#######################################################################

#close the program
close(vehicle,sitl)























 
