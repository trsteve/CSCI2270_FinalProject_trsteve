# finalproject-CSCI2270-trsteve
This is a final project of spring2015 CSCI2270, created by Theerarun Tubnonghee.

==== Please Read Me Carefully ====
1. Project Summary
 - Have you ever wonder to travel around the world? Have you ever done some calculation of the cost before taking off? I have been thinking about it for a while.
Since thie semester, I have learnt about the graph data structure, and the assignments. I am kind of want to make something that applied to this knowledge. I wonder
if I would build a travel plan to all cities I want to go, and put them into the travel analyzer to calculate how much of the travel, and time costs. Another question has risen.
What if I select to drive instead of flying, how different would it cost in both travel and time costs. Maybe, I will add the blissfulness along the road into my account.
Firstly, I will use ROADMAP file, and FLIGHTMAP file to insert my primary information. Then, I could add any city later on. I print out the road, flight map.
What if I want to travel to along some cities in the map, not around the world. How much does it cost me, in money and time? What if I want to take the shortest path.
What if I want to drive along the road and visit least number of cities. Breath-first Search could help out what nearby cities are. Depth-first Search could help
out what a possible path to the destination. Dijkstra's algorithm could help out what shortest path I should take. However, that is only the travel cost.
What if there is some choice of taking a plane or driving a car. What if the time is limited. These are the choices that my program want to find out and give
out solutions to users.

2. How to Run
 - "travelAnalyzer" is the main driver program file
 - "travelKit" is the documentation help file
 - Access travelAnalyzer/bin/Debug, and you will found travelAnalyzer compiled file.
 - Run "travelAnalyzer" by using terminal
 - type "./travelAnalyzer roadMap.txt flightMap.txt" (in order to run the program)
 - The program will run by reading a "roadMap.txt" file, and "flightMap.txt" file in command line argument.

 - You can print the map to check the cities, roads, and flights.
 - By selecting Menu, it will calculate and implement each function.
 - There is no other dependent file; other than ROADMAP.txt and FLIGHTMAP.txt which I will provide in the repository folder.
 - link to documentation program: https://github.com/trsteve/CSCI2270_FinalProject_trsteve/tree/master/travelAnalyzer

3. Dependencies
 - There is no other dependent file; other than "roadMap.txt" and "flightMap.txt" which I will provide in the repository folder.

4. System Requirements
 - Since I will build a simple program using terminal, All OS-platform is worked.
 - No additional system requirement.

5. Group Members
 1) Theerarun Tubnonghee CSCI2270-REC112 Spring2015

6. Contributors
 - N/A

7. Open issues/bugs
 - bugs
   	+ 4/26/2015 1:39AM "Add new road for a new recent city: it does not display as road has been added when I printed map. It displays that I added a flight connection but no cost
                       	;however, the program has the road cost as usual, but just not display as Road connection. I have been trying to find the bug and any issue. Debugging*fixed"
   	+ 4/26/2015 1:57AM "Fixed the lastest bug of AddRoad, actually there is no bug in the Add-Road function but the bug in the displayMap function that I have to change the condition of displaying"
   	- 4/26/2015 2.05AM "Sometimes the BESTTRAVEL-function does not work for some path. It stucks in the loop. I have been trying to find the bug and fix it. Debugging"
	- 4/26/2015 3.35AM "Update Delete functions but when I delete a city, the adjacent-road city also get change. Debugging*fixed"
	+ 4/30/2015 10.24PM "Fix the delete city"
 - issues
   	+ 4/26/2015 3.35AM "Working on Delete city from the map" : fixed
	- 4/26/2015 4.08AM "vector.erase() delete and shift the rest of vector one step, this makes my whole connections that contain city after the delete one mix up. -- Need some help or suggestion.
 			-- not sure of making the adjacent city by change it to vector<adjCity*> adj
			-- i just comment the cities.erase() function out just for now"
			-- fixed


==== Copyright 2015 by Theerarun Tubnonghee ====