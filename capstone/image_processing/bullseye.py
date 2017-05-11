# import the necessary packages
from collections import deque
import numpy as np
import argparse
import imutils
import cv2
from bullseyeFunctions import bullseyeFunctions

# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-v", "--video",
        help="path to the (optional) video file")
ap.add_argument("-b", "--buffer", type=int, default=32,
        help="max buffer size")
args = vars(ap.parse_args())



# initialize the list of tracked points, the frame counter,
# and the coordinate deltas
pts = deque(maxlen=args["buffer"])
counter = 0
(dX, dY) = (0, 0)
direction = ""

# if a video path was not supplied, grab the reference
# to the webcam
if not args.get("video", False):
        camera = cv2.VideoCapture(0)
 
# otherwise, grab a reference to the video file
else:
        camera = cv2.VideoCapture(args["video"])

        # keep looping
while True:
        functionsobj = bullseyeFunctions()
        # grab the current frame
        (grabbed, frame) = camera.read()
 
        # if we are viewing a video and we did not grab a frame,
        # then we have reached the end of the video
        if args.get("video") and not grabbed:
                break
 
        # resize the frame, blur it, and convert it to the HSV
        # color space
        frame = imutils.resize(frame, width=600)
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
                    print("found the final target!!!", center[0])
                    dX = camera.get(3)/2 - center[0]
                    dY = camera.get(4)/2 - center[1]
                    (dirX, dirY) = ("", "")
 
 
                    # ensure there is significant movement in the
                    # x-direction
                    if np.abs(dX) > 20:
                            dirX = "Move Right" if np.sign(dX) == 1 else "Move Left"
 
                    # ensure there is significant movement in the
                    # y-direction
                    if np.abs(dY) > 20:
                            dirY = "Move Down" if np.sign(dY) == 1 else "Move Up"
 
                    # handle when both directions are non-empty
                    if dirX != "" and dirY != "":
                            direction = "{}-{}".format(dirY, dirX)

                    #handle when both directions are empty
                    if dirX == "" and dirY == "":
                            direction = "Decending point!"
 
                    # otherwise, only one direction is non-empty
                    else:
                            direction = dirX if dirX != "" else dirY
                    print(direction)


                    #we found the taeget position on xy-plane
                    if finalTarget is not None:

                        ratios = functionsobj.tagAspectRatio(finalTarget)
                        #print("ratios ", ratios)
                        #if ratios is not None:
                            #distance = functionsobj.calcDistToTarget(finalTarget, ratios)
                            #calculate the distance
    

                             
            cv2.imshow("Frame", edges)
            key = cv2.waitKey(1) & 0xFF
