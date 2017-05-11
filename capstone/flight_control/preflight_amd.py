#!/usr/bin/env python

from dronekit import connect, VehicleMode, LocationGlobalRelative
import time

def close(vehicle,sitl):
	"""
	Close vehicle object before exiting the script
	Exit sitl if running
	"""
	print "\nClose vehicle object"
	vehicle.close()
	
	# shut down simulator if it was started
	if sitl is not None:
		sitl.stop()

	print("Completed")

def getAttributes(vehicle):
	"""	
	Get all vehocle attributes (state)
	"""
	print "Autopilot Firmware version: %s" %vehicle.version
	print " Is Armable?: %s" % vehicle.is_armable
	print " System status: %s" % vehicle.system_status.state
	print " Groundspeed: %s" % vehicle.groundspeed    # settable
	print " Airspeed: %s" % vehicle.airspeed    # settable
	print " Mode: %s" % vehicle.mode.name    # settable
	print " Armed: %s" % vehicle.armed    # settable 

def getHomeLocation(vehicle):
	"""
	Get Vehicle Home location - will be "None' until first set by autopilot
	"""
	while not vehicle.home_location:
		# Download the vehicle waypoints(commands)
		# To get attributes, e.g. home_location, must first download the Vehicle.commands()
		cmds = vehicle.commands
		cmds.download()
		cmds.wait_ready() #wait_ready blocks thread until download is complete
        
	if not vehicle.home_location:
		print " Waiting for home location ..."
	# Have home location
	print "\n Home location: %s" %vehicle.home_location


def setVehicleMode(vehicle, mode):
	"""
	Set vehicle mode to [GUIDED, RTL, LAND, etc]
	"""
	print "\nSet Vehicle.mode = %s (currently: %s)" %(mode,vehicle.mode.name)
	vehicle.mode = VehicleMode(mode)
	vehicle.flush() # to make sure cmd is passed
	while not vehicle.mode.name == mode: # wait until mode has changed
		print " Waiting for mode change ..."
		time.sleep(1)


def isArmable(vehicle):
	"""
	Check that vehicle is armable
	"""
	while not vehicle.is_armable:
		print " Waiting for vehicle to initialise..."
		time.sleep(1)

	print "\nSet Vehicle.armed=True (currently: %s)" % vehicle.armed
	vehicle.armed = True
	vehicle.flush()
	while not vehicle.armed:
		print " Waiting for arming..."
		time.sleep(1)
	print " Vehicle is armed: %s" % vehicle.armed

