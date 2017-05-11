 /** \file traveling.cpp
 * \details This program solves Traveling Salesperson problem
 * \author Wright Kim (wdk7bj)
 * \date 12/03/2015
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

/**@brief This is main function
 * \details Receives width, height, number of cities, seed, number of cities to visit as command line parameter
 * \details Computes and stores the minimum total length (cost)
 * \details Prints the route and the total length (cost)
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // to store the list of cities of the least cost
    vector<string> leastCostDests;
    // Dunharrow is the start city
    string startCity = dests[0];
    // to remove start city from the vector
    dests.erase(dests.begin());

    float leastCost = 0;
    float temp = 0;
    //sorts dests in order
    sort(dests.begin(), dests.end());
    // to track the min cost in do while 
    temp = computeDistance(me, startCity, dests);
    // to track the min cost in do while
    leastCost = temp;

    do {
        for (int i = 0; i < dests.size(); i++){
            temp = computeDistance(me, startCity, dests);
        }
        if (temp <= leastCost) {
            leastCost = temp;
            leastCostDests = dests;
        }
    } while (next_permutation(dests.begin(), dests.end()));
    // to print route and total length
    printRoute(startCity, leastCostDests);
    cout << "and will have length " << leastCost << endl;

    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.

/**@brief computes the total cost of travel
 *@return returns float type cost to travel 
 *@param me to use middleearth methods
 *@param start start city to start travel
 *@param dests stores all of the cities to visit
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    //float type distance
    float dist = 0;
    dist += me.getDistance(start, dests[0]);
    // if dests.size() = 5
    // dist from start to dests[3] 
    for (int i = 0; i < dests.size()-1; i++) {
        dist += me.getDistance(dests[i], dests[i+1]);
    }
    //dist from dests[4] to start
    dist += me.getDistance(dests[dests.size()-1], start);
    //return the cost
    return dist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor

/**@brief prints out the route to travel
 *@return void
 *@param start city to start travel
 *@param dests stores all of the cities to visit
 */
void printRoute (string start, vector<string> dests) {
    cout << "Your journey will take you along the path ";
    cout << start << " -> ";
    for (int i = 0; i < dests.size(); i++) {
        cout << dests[i] << " -> ";
    }
    cout << start << endl;
}
