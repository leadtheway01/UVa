#!/usr/bin/env python

from dronekit import connect, VehicleMode, LocationGlobal, LocationGlobalRelative
from pymavlink import mavutil
from gps_amd import takeoff
from preflight_amd import close, getAttributes, getHomeLocation, setVehicleMode, isArmable
from image_amd import condition_yaw, send_ned_velocity
import time, math

#Set up option parsing to get connection string
import argparse  
parser = argparse.ArgumentParser(description='Control Copter and send commands in GUIDED mode ')
parser.add_argument('--connect', 
                   help="Vehicle connection target string. If not specified, SITL automatically started and used.")
args = parser.parse_args()

connection_string = args.connect
sitl = None


#Start SITL if no connection string specified
if not connection_string:
    import dronekit_sitl
    sitl = dronekit_sitl.start_default()
    connection_string = sitl.connection_string()


# Connect to the Vehicle
print 'Connecting to vehicle on: %s' % connection_string
vehicle = connect(connection_string, wait_ready=True)

vehicle.wait_ready('autopilot_version')

getAttributes(vehicle)

getHomeLocation(vehicle)
#vehicle.parameters['ARMING_CHECK']= -9

setVehicleMode(vehicle, "GUIDED")
isArmable(vehicle)
time.sleep(1)
print "hi"
#aTargetAltitude = 3 
#takeoff(vehicle, aTargetAltitude)

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

#print("take off")
#send_ned_velocity(0,0,UP,3)
#send_ned_velocity(0,0,0,3)

#print("rotate 180 degrees")
#condition_yaw(vehicle, 180, relative=True)
#send_ned_velocity(vehicle,0,0,0,6)

# to move north
#send_ned_velocity(NORTH,0,0,Duration)

#while True:
#	print "Altitude: ", vehicle.location.global_relative_frame.alt
#	if vehicle.location.global_relative_frame.alt < 0.2:
#		break
#	else:
#		send_ned_velocity(vehicle,0,0,DOWN,7)

#while True:
#	input = raw_input("Up: u, Down: d, Right: r, Left:l, exit: 0")
#	if input is "u":
#		print "Moving up"
#		send_ned_velocity(vehicle, 0, 0, UP, 4)
#        elif input is "d":
#		print "Moving down"
#		send_ned_velocity(vehicle,0, 0, DOWN, 4)
#        elif input is "r":
#		print "Moving Right"
#		send_ned_velocity(vehicle, 0, EAST, 0, 4)
#        elif input is "l":
#                print "Moving Left"
#		send_ned_velocity(vehicle, 0, WEST, 0, 4)
#        elif input is "0":
#		print "exiting"
#		break


def servo():
	msg = vehicle.message_factory.command_long_encode(
    		0, 0,    # target system, target component
    		mavutil.mavlink.MAV_CMD_DO_SET_SERVO, #command
    		0, 		# confirmation
    		10,    	# param 1, Servo number - target servo output pin/channel
    		1700,       # param 2, PWM value 750 ~ 2250 microsecond
    		0,          # param 3, Repeat: Cycle count - number of times to move the servo to the specified PWM value
    		0, 		# param 4, Delay: Cycle time (seconds) - the delay in seconds between each servo movement.
    		0, 0, 0)    # param 5 ~ 7 not used

	# send command to pixhawk
	vehicle.send_mavlink(msg)

print "servo"
servo()
#while True:
#	start = time.clock()
#	if end >= 10:
#		servo()
#		break
#	end = time.clock() - start




close(vehicle, sitl)



















