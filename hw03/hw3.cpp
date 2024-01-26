//
//  main.cpp
//  hw03
//
//  Created by Patricia Antlitz on 2/3/23.
//
/**
Author: <Patricia Antlitz>
Date: <2/3/23>
Purpose: <This program is an example on how to utilize classes and constructors. It created coordinates (ordered pairs), rotates it at 90 degrees a given amount of times, and moves the points up or down each axis>
Sources of Help: <//add another file https://stackoverflow.com/questions/12733888/regarding-c-include-another-class
 //check rotations:
 //https://keisan.casio.com/exec/system/1223522781
 //rotate
 //https://forums.codeguru.com/showthread.php?507478-rotating-a-point-by-an-angle>
Time Spent: <2hrs~ of research, planning and studying the material learned in class, 30min execution>
**/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: Patricia Antlitz
Name: 02/03/2023
*/

#include <iostream>
using namespace std;

void computerSelfTest();
void userTestDriver();

class Point
{
public:
    //default constructor
    Point();
    //value constructor
    Point(int xAxis, int yAxis);
    //setters
    void setXAxis(int xPoint);
    void setYAxis(int yPoint);
    //accessors
    int getXAxis(void) const;
    int getYAxis(void) const;
    
    //prototypes
    void display(void);
    void rotateMatrix(int rotateTimes);
    void moveAxis(int xAxis, int yAxis);
    
private:
    int pointX;
    int pointY;
};

int main(int argc, const char * argv[])
{
    //user driver
    userTestDriver();
    //set values test
    computerSelfTest();
    return 0;
}

//default constructor will set the value of x and y to (1, 2)
Point::Point()
{
    pointX = 1;
    pointY = 2;
}

//value constructor will reassign the values to whatever is passes through the parameters
Point::Point(int xAxis, int yAxis)
{
    pointX = xAxis;
    pointY = yAxis;
}
//will rotate the points 90 degrees
//uses the parameter rotateTimes to get the amount of times it should be rotated
void Point::rotateMatrix(int rotateTimes)
{
    cout << "Clockwise rotation at 90 degrees, " << rotateTimes << " times:" << endl;
    //runs n amounts of time (parameter)
    for(int i = 0; i < rotateTimes; i++)
    {
        //simple swap algorithm
        //set a temporary point, hold the value given to x
        int tempX = pointX;
        //pointX = pointY;
        //pointY = -tempX;
        /*
         I am calling the setters here instead of reassigning the variables to each other because I want to make sure the swapped coordinates are saved as the new coordinates. This way we can move the rotated coordinate and not the original one
         */
        setXAxis(pointY);
        setYAxis(-tempX);
        
        cout << i+1 << " = New ";
        display();
    }
    cout << endl;
}

void Point::moveAxis(int xAxis, int yAxis)
{
    cout << "Moving (" << getXAxis() << ", " << getYAxis() << ") by x = " << xAxis << " y = " << yAxis << endl;
    //adding whatever coordinate is passed to current coordinate
    pointX += xAxis;
    pointY += yAxis;
}

void Point::setXAxis(int xPoint)
{
    pointX = xPoint;
}

void Point::setYAxis(int yPoint)
{
    pointY = yPoint;
}

int Point::getXAxis() const
{
    return pointX;
}

int Point::getYAxis() const
{
    return pointY;
}

void Point::display()
{
    cout << "Coordinates: (" << getXAxis() << ", " << getYAxis() << ")" << endl;
}

void computerSelfTest()
{
    //built-in testing
    cout << "COMPUTER DRIVER:" << endl;
    //default constructor has a value of (1, 2)
    Point setAxis;
    cout << "Original ";
    setAxis.display();
    cout << endl;
    //rotates 1,2 4 times
    setAxis.rotateMatrix(4);

    //snd constructor, changes the value of private data to 3, 4
    Point changeAxis(3, 4);
    cout << "Updated ";
    changeAxis.display();
    cout << endl;
    
    //moving x by 1 to the right, and moving y by 1 up
    changeAxis.moveAxis(1, 1);
    cout << "New ";
    //new value should be 4,5
    changeAxis.display();
    cout << endl;
    
    //snd constructor, changes the value of private data to 5, -4
    Point change(5, -4);
    cout << "Updated ";
    change.display();
    cout << endl;
    
    //moving the coordinates x 5 to the left, and y 4 up
    change.moveAxis(-5, 4);
    cout << "New ";
    //new value should be 0, 0
    change.display();
    cout << endl;

    //testing setters and getters
    cout << "Mutators and Accessors test:" << endl;
    setAxis.setXAxis(2);
    setAxis.setYAxis(6);
    setAxis.display();

}

void userTestDriver()
{
    //to store user's entries
    int userXPoint;
    int userYPoint;
    //will get the first coordinates for x and y
    cout << "User Driver" << endl;
    cout << "Enter a X coordinate and a Y coordinate:" << endl;
    cin >> userXPoint >> userYPoint;
    //sets the numbers entered as the coordinates
    Point setCoordinates(userXPoint, userYPoint);
    setCoordinates.display();
    
    //points rotation
    cout << "Rotate at 90 degrees." << endl;
    cout << "How many times would you like to rotate the coordinates: " << endl;
    //I am using this variable to temporarily store the value for the loop
    cin >> userYPoint;
    setCoordinates.rotateMatrix(userYPoint);
    
    //moving points, get values
    cout << "Move points." << endl;
    cout << "Enter the coordinates you would like to move your points by:" << endl;
    cin >> userXPoint >> userYPoint;
    //values entered by the user passed to the method
    setCoordinates.moveAxis(userXPoint, userYPoint);
    setCoordinates.display();
    cout << endl << "----------------------------------" << endl << endl;
}
