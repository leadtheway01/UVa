#!/usr/bin/python
import cv2
import numpy as np
import math
import time



class CircleDetector(object):



       #analyze_frame - process an frame and look for a bullseye
    #params -child_conn: child pipe connection
    #       -img: raw image to be processed
    #       -craftAttitude: roll and pitch of aircraft
    #return -runtime: time in millis to process an image
    #       -center: tuple(x,y) of the objects position on; 'None' when no target
    #       -distance: distance in meters to the target; -1 when unable to calculate
    #       -targetEllipses: ellipses that compose the detected target 'None' when no target
    def analyze_frame(self, child_conn, img, craftAttitude):
        #start timer
        #start = current_milli_time()


        #blur image and grayscale
        #img = cv2.medianBlur(img,5)

        #grayscale image
        cimg = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)


        #canny edge detector
        edges = cv2.Canny(cimg,100,200,3)

        if edges is not None:

            #locate contours
            contours, hierarchy = cv2.findContours(edges,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

            #turn contours into ellipses
            circles = np.empty((len(contours)),object)
            circlesCnt = 0
            for i in range(0,len(contours)):
                contour = contours[i]
                #make sure contour contains enough point for an ellipse
                if(len(contour) > 4):
                    #detect an ellipse
                    ellipse = cv2.fitEllipse(contour)
                    #only take ellipses which are round
                    if self.checkEccentricity(ellipse,self.eccentricity):
                        circles[circlesCnt] = ellipse
                        circlesCnt += 1


            #if circles were found then we look for nested circles
            if circlesCnt > 0:

                #get rid of null elements
                circles = np.resize(circles,circlesCnt)
                #look for nested ellipses
                nestedCircles = self.detectNested(circles)

                #if at least min_circles circles are nested look for target
                #Times min_circles by two because we haven't removed repeat/stacked circles yet
                if len(nestedCircles) > (self.min_circles * 2):

                    #look for circles with a common center
                    self.finalTarget, center = self.findCommonCenter(nestedCircles)

                    #we found the target position on xy-plane
                    if self.finalTarget is not None:

                        #decode the target rings for a list of ring ratios
                        ratios = self.tagAspectRatio(self.finalTarget)


                        #try to calculate distance to target
                        if ratios is not None:
                            distance = self.calcDistToTarget(self.finalTarget,ratios)

                            stop = current_milli_time()
                            child_conn.send((stop-start,center, distance, self.finalTarget))
                            return

                        #unable to calculate distance due to invalid data
                        else: 
                            stop = current_milli_time()
                            child_conn.send(( stop-start, center, -1, self.finalTarget))
                            return


        #unable to locate target
        #stop = current_milli_time()
        child_conn.send((stop-start,None,-1,None))
        return

    
