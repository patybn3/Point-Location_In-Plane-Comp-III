#  Homework #3

##Student: Patricia Antlitz
##Professor: Dr. Sirong Lin
##Subject: Computing III
##Date: 02/03/2023
##UMASS Lowell - Spring 2023

##Objective:

To create an application that demonstrates the principles learn in class for the usage of classes, constructors and data encapsulation.

##Instructions:

Create a project called hw3 and a source file called hw3.cpp.
The type of Point is a fairly simple data type. Write a definition of a 
class named Point that might be used to store and manipulate the location
of a point in the plane. You will need to declare and
implement the following member functions
• A member function that sets the private data together after an object of this class is created.
• A member function to move the point by an amount along the horizontal and vertical directions
specified by the first and second arguments, e.g., the current coordinate is (3, 4) and moved by
(1, 2), that is, one right, two up.
• A member function to rotate the point by 90 degrees clockwise around the origin.
• Two accessor functions to retrieve the current coordinates of the point.
Document these functions with appropriate comments. Embed your class in a test program (driver) that
requests data for several points from the user, creates the points, and then exercises the member
functions.
Your driver should test all functions above, but leave the code to test the follow cases:
(1) We start with (1, 2). This point is rotated 90 degrees, four times, getting back to the original
point.
(2) The point (3, 4) is set and moved by (1, 1), that is, the point moves one up, one right.
(3) A second point, (5, -4) is set and moved by (-5, 4) 5 left, 4 up. Then we move it back to the origin,
(0, 0).

##Technology:

- C++
- Xcode

##Issues encountered:

I wasn't sure if you wanted the file hw03.cpp to be the main file or not, so I kept both.
Other than that, I did not encounter any major problems while developing this.

##Structure:

- The main fine (main.cpp) contains 2 methods, one as the computer driver, which has pre-set values to test the program without user inputs, and the other is names userTestDriver. The latter takes user inputs to perform the operations as part of the requirement. 
- The file hw03.cpp hosts the class names Point, and its methods.

###Methods and constructors:
- Point() -> default constructor for class Point
- Point(int int) - > value constructor to reset the points
- rotateMatrix(int) -> belongs to Point (class), of type void, rotates the coordinates at 90 degrees.
- moveAxis(int int) -> belongs to Point, type void, adds the value passed as arguments through the parameters to the current coordinates to move the points.
- setXAxis and setYAxis -> mutator
- getXAxis and getYAxis -> accessor


##Sources:
- add another file: https://stackoverflow.com/questions/12733888/regarding-c-include-another-class
 - check rotation calculator:
    https://keisan.casio.com/exec/system/1223522781
 - rotate:
    https://forums.codeguru.com/showthread.php?507478-rotating-a-point-by-an-angle>
- My notebook with lecture's notes.
- Blackboard lecture videos.
