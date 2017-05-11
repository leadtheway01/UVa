# import the necessary packages
from collections import deque
import numpy as np
import argparse
import imutils
import math
import cv2

class bullseyeFunctions:
        def __init__(self):
                self.target_code = [0.8,0.91,0.76,0.84,0.7,0.66,0.49]

        #distCenters - distance between two ellipses
        def distCenters(self,ellipse1,ellipse2):
                #distance between centers
                distance = math.sqrt(math.pow((ellipse1[0][0]-ellipse2[0][0]),2) + math.pow((ellipse1[0][1] - ellipse2[0][1]),2))
                return distance

        #detectNested- return circles which are nested within other circles
        def detectNestedCircles(self,rawCircles):
                size = len(rawCircles)
                nestedCircles = np.empty(size, object)
                nestedCnt = 0
                for i in range(0,size):
                        nested = False
                        for j in range(i, size):
                                if i != j:
                                        circle1 = rawCircles[i]
                                        circle2 = rawCircles[j]
                                        #average major and minor axises
                                        radius1 = (circle1[1][0] + circle1[1][1]) /2.0
                                        radius2 = (circle2[1][0] + circle2[1][1]) /2.0

                                        distance = self.distCenters(circle1,circle2)
                                                
                                        #check if a circle is nested within another circle
                                        if(distance < math.fabs(radius1 - radius2)):
                                                nested = True
                        #add the base circle if it is nested
                        if nested:
                                nestedCircles[nestedCnt] = rawCircles[i]
                                nestedCnt += 1  
                #remove null objects
                nestedCircles  = np.resize(nestedCircles,nestedCnt)

                return nestedCircles


        #checkEccentricity - checks if an ellipse is 'round' enough
        def checkEccentric(self,ellipse, threshold):
                #threshold = 1 for perfect circles
                if ellipse[1][0] * 1.0/ ellipse[1][1] > threshold:
                        return True
                return False
        #findCommonCenter - locates a group of circles which share a the most common center. Returns the group and the center point 
        def findCommonCenter(self,nestedCircles):

                size = len(nestedCircles)
                #print("Length of the nested circles", size)
                #sort by radius
                for i in range(0,size):
                        baseCircle = nestedCircles[i]
                        smallestRadius = (baseCircle[1][0] + baseCircle[1][1]) /2.0 
                        smallest = i

                        for j in range(i,size):
                                circle = nestedCircles[j]
                                radius = (circle[1][0] + circle[1][1]) /2.0
                                if(radius < smallestRadius):
                                        smallestRadius = radius
                                        #print("small radius",smallestRadius)
                                        smallest = j

                        nestedCircles[i] = nestedCircles[smallest]
                        nestedCircles[smallest] = baseCircle

                #look at all circles
                #add all circles that are within a certain threshold distance
                #compare circle pairs and see which one has the most circles
                concentricCombos = np.empty([size,size],object)


                #start with the largest circle and scan all smaller circles and see if it is concentric with the large circle
                maxConcentricCnt = 1
                maxConcentricIndex = 0

                #stores circle centers
                xSum = np.zeros(size)
                ySum = np.zeros(size)

                for i in range(size-1,0,-1):
                        outer = nestedCircles[i]
                        concentricCombos[i][0] = outer
                        cnt = 1
                        

                        for j in range(i, 0, -1):
                                inner = nestedCircles[j]
                                #outer circle and inner circle have same center, are different
                                #print("outer and inner distinc center ", self.distCenters(outer,inner))
                                if (self.distCenters(outer,inner) < 15) and (i != j):
                                        #check that the circle isn't a repeat(a problem with findContours)
                                        previous = concentricCombos[i][cnt -1]
                                        radPrev = (previous[1][0] + previous[1][1]) /2.0
                                        radCurr = (inner[1][0] + inner[1][1]) /2.0
                                        #if the circle is cocentric and unique, add it
                                        if(radPrev - radCurr) >2:
                                                concentricCombos[i][cnt] = inner

                                                xSum[i] += inner[0][0]
                                                ySum[i] += inner[0][1]

                                                cnt += 1

                        if(cnt > maxConcentricCnt):
                                maxConcentricCnt = cnt
                                maxConcentricIndex = i
                #print("maxCentericcnt", maxConcentricCnt)
                #no concentric circles
                if(maxConcentricCnt < 5):
                        return None,None

                #choose the circle set with the most concentric circles
                mostConcentric = concentricCombos[maxConcentricIndex]
                mostConcentric = np.resize(mostConcentric, maxConcentricCnt)

                #calculate meanCenter
                meanCenter = xSum[maxConcentricIndex] / (maxConcentricCnt - 1), ySum[maxConcentricIndex]/(maxConcentricCnt - 1)

                return mostConcentric, meanCenter

        #tagAspectRatio- processes the final target and calculates the ratio between rings. returns an array of ratios
        def tagAspectRatio(self,target):
                size = len(target)
                #ratios = np.empty((size-1)*size/2.0, float)
                ratios = np.empty(size-1,float)
                cnt = 0

                for i in range(0,size-1):
                        circle1 = target[i]
                        circle2 = target[i+1]
                        radius1 = (circle1[1][0] + circle1[1][1]) /2.0
                        radius2 = (circle2[1][0] + circle2[1][1]) /2.0

                        
                        ratio = radius2 / radius1
                        ratios[cnt] = round(ratio,3)
                        cnt += 1
                return ratios                   

