# import the necessary packages
from collections import deque
import numpy as np
import argparse
#import imutils
import cv2
import os
import time
from bullseyeFunctions import bullseyeFunctions

# construct the argument parse and parse the argument


# initialize the list of tracked points, the frame counter,
# and the coordinate deltas



def image():
    counter = 0
    (dX, dY) = (0, 0)
    direction = ""
    try:
        os.system("./ffmpeg -s 640x480 -f video4linux2 -i /dev/video0 -vframes 1 /home/root/bin/ffmpeg/image.jpeg &>/dev/null")
        time.sleep(500.0/1000.0)
        functionsobj = bullseyeFunctions()
        # grab the current frame

        frame = cv2.imread('image.jpeg')
 
        # if we are viewing a video and we did not grab a frame,
        # then we have reached the end of the video
       
        #frame = imutils.resize(frame, width=600)
        blurred = cv2.GaussianBlur(frame, (11, 11), 0)
        cameraImg = cv2.cvtColor(blurred, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(cameraImg,100,200,3)

        if edges is not None:
            #locate contours
            _,contours, hierarchy = cv2.findContours(edges.copy(),cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

            #trun contours into elipse
            circles = np.empty((len(contours)), object)
            circleCount = 0

            for i in range(0,len(contours)):
                contour = contours[i]
                #make sure contour contains enough points for the elipse
                if(len(contour) > 4):
                    #detect an eclipse
                    elipse = cv2.fitEllipse(contour)
                    #print("This is to test fitellipse", elipse)
                    #only consider the elipse only if they ar round enough
                    if functionsobj.checkEccentric(elipse, 0.6):
                        circles[circleCount] = elipse
                        circleCount += 1
                        #print(circleCount)
                        cv2.drawContours(edges, contour, -1, (0,255,0), 4)

            #if circles were found then we look for nested circles
            if circleCount > 0:
                #print("circleCount", circleCount)

                #get rid of null elements
                circles = np.resize(circles, circleCount)

                #look for nested elipse
                nestedCircles = functionsobj.detectNestedCircles(circles)
                #print("nested circles", len(nestedCircles))
                #if at least min_circles are nested, then look for the traget
                #Times *2 because we haven't removed repeat/stacked circles
                if len(nestedCircles) > (5*2):
                    finalTarget, center = functionsobj.findCommonCenter(nestedCircles)
                    #print("found the final target!!!")
                    if center is not None:
                        dX = 640/2 - center[0]
                        dY = 480/2 - center[1]
                        (dirX, dirY) = ("", "")
 
 
                        # ensure that the center of the image is significancly close to the center of the image
                        # x-direction
                        if np.abs(dX) > 30:
                            dirX = "LEFT" if np.sign(dX) == 1 else "RIGHT"
     
                        # ensure that the center of the image is significancly close to the center of the image
                        # y-direction
                        if np.abs(dY) > 30:
                            dirY = "FORWARD" if np.sign(dY) == 1 else "BACKWARD"
     
                        # handle when both directions are non-empty
                        if dirX != "" and dirY != "":
                            direction = "{}-{}".format(dirY, dirX)

                        #handle when both directions are empty
                        if dirX == "" and dirY == "":
                            direction = "DESCEND"
     
                        # otherwise, only one direction is non-empty
                        else:
                            direction = dirX if dirX != "" else dirY
                        #print(direction)
                        #cv2.putText(edges, direction, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.65, (0, 0, 255), 3)
                        #cv2.putText(edges, "dx: {}, dy: {}".format(dX, dY), (10, edges.shape[0] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.35, (0, 0, 255), 1)

                        #we found the taeget position on xy-plane
                    else:
                        direction = "TARGET_NOT_FOUND"
                    if finalTarget is not None:

                        ratios = functionsobj.tagAspectRatio(finalTarget)
                        #print("ratios ", ratios)
                        #if ratios is not None:
                            #distance = functionsobj.calcDistToTarget(finalTarget, ratios)
                            #calculate the distance
            else:
                direction = "TARGET_NOT_FOUND"
            os.system("rm -f /home/root/bin/ffmpeg/image.jpeg")
        else:
            direction = "TARGET_NOT_FOUND"
    except KeyboardInterrupt:                     
        #cv2.imshow("edges", edges)
        #key = cv2.waitKey(1) & 0xFF
        # if the 'q' key is pressed, stop the loop
        #if key == ord("q"):
        return direction
    return direction

if __name__ == "__main__":
    while True:
        try:
            print(image())
        except KeyboardInterrupt:
            break
            
