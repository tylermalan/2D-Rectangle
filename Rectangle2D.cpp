// CS212 Spring 2018
// Gordon Malan
// Submission date: 24 April 2018

#include "Rectangle2D.h"
#include <iostream>
#include <cmath>

// Construct a rectangle object
Rectangle2D::Rectangle2D() {
    x = 0.0;
    y = 0.0;
    width = 1.0;
    height = 1.0;
}

// Construct a rectangle object with parameters
Rectangle2D::Rectangle2D(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

// Return x-value of rectangle's center
double Rectangle2D::getX() const {
    return x;
}

// Return y-value of rectangle's center
double Rectangle2D::getY() const {
    return y;
}

// Assign x-value of rectangle's center
void Rectangle2D::setX(double x) {
    this->x = x;
}

// Assign y-value of rectangle's center
void Rectangle2D::setY(double y) {
    this->y = y;
}

// Return width of rectangle
double Rectangle2D::getWidth() const {
    return width;
}

// Return height of rectangle
double Rectangle2D::getHeight() const {
    return height;
}

// Assign width of rectangle
void Rectangle2D::setWidth(double width) {
    this->width = width;
}

// Assign height of rectangle
void Rectangle2D::setHeight(double height) {
    this->height = height;
}

// Return area of rectangle
double Rectangle2D::getArea() const {
    return width * height;
}

// Return perimeter of rectangle
double Rectangle2D::getPerimeter() const {
    return width * 2 + height * 2;
}

// Verify whether a given point is inside a rectangle
bool Rectangle2D::contains(double x, double y) const {
    double leftBound = this->x - width / 2;
    double rightBound = this->x + width / 2;
    double bottomBound = this->y - height / 2;
    double topBound = this->y + height / 2;
    return x >= leftBound && x <= rightBound && y >= bottomBound && y <= topBound;
}

// Verify whether a given rectangle is inside another rectangle
bool Rectangle2D::contains(const Rectangle2D &r) const {
    // Establish outer boundaries of implicit rectangle
    double originalLeftBound = this->x - width / 2;
    double originalRightBound = this->x + width / 2;
    double originalBottomBound = this->y - height / 2;
    double originalTopBound = this->y + height / 2;

    // Establish outer boundaries of parameter rectangle
    double newLeftBound = r.getX() - r.getWidth() / 2;
    double newRightBound = r.getX() + r.getWidth() / 2;
    double newBottomBound = r.getY() - r.getHeight() / 2;
    double newTopBound = r.getY() + r.getHeight() / 2;

    return newLeftBound >= originalLeftBound && newRightBound <= originalRightBound &&
           newBottomBound >= originalBottomBound && newTopBound <= originalTopBound;
}

// Verify overlap of two rectangles
bool Rectangle2D::overlaps(const Rectangle2D &r) const {
    // Establish outer boundaries of implicit rectangle
    double originalLeftBound = this->x - width / 2;
    double originalRightBound = this->x + width / 2;
    double originalBottomBound = this->y - height / 2;
    double originalTopBound = this->y + height / 2;

    // Establish outer boundaries of parameter rectangle
    double newLeftBound = r.getX() - r.getWidth() / 2;
    double newRightBound = r.getX() + r.getWidth() / 2;
    double newBottomBound = r.getY() - r.getHeight() / 2;
    double newTopBound = r.getY() + r.getHeight() / 2;

    // Establish boolean variables for different sectors of overlap
    bool bottomLeftOverlap = newLeftBound < originalLeftBound && newRightBound > originalLeftBound &&
                             newBottomBound < originalBottomBound && newTopBound > originalBottomBound;

    bool leftOverlap = newLeftBound < originalLeftBound && newRightBound > originalLeftBound &&
                       newBottomBound >= originalBottomBound && newTopBound <= originalTopBound;

    bool topLeftOverlap = newLeftBound < originalLeftBound && newRightBound > originalLeftBound &&
                          newBottomBound < originalTopBound && newTopBound > originalTopBound;

    bool topOverlap = newLeftBound >= originalLeftBound && newRightBound <= originalRightBound &&
                      newBottomBound < originalTopBound && newTopBound > originalTopBound;

    bool topRightOverlap = newLeftBound < originalRightBound && newRightBound > originalRightBound &&
                           newBottomBound < originalTopBound && newTopBound > originalTopBound;

    bool rightOverlap = newLeftBound < originalRightBound && newRightBound > originalRightBound &&
                        newBottomBound >= originalBottomBound && newTopBound <= originalTopBound;

    bool bottomRightOverlap = newLeftBound < originalRightBound && newRightBound > originalRightBound &&
                              newBottomBound < originalBottomBound && newTopBound > originalBottomBound;

    bool bottomOverlap = newLeftBound >= originalLeftBound && newRightBound <= originalRightBound &&
                         newBottomBound < originalBottomBound && newTopBound > originalTopBound;

    // Alternative way of solving this that uses less memory...

/*    if (newLeftBound < originalLeftBound && newRightBound > originalLeftBound &&
        newBottomBound < originalBottomBound && newTopBound > originalBottomBound) {
        return true;
    } else if (newLeftBound < originalLeftBound && newRightBound > originalLeftBound &&
               newBottomBound >= originalBottomBound && newTopBound <= originalTopBound) {
        return true;
    } else if (newLeftBound < originalLeftBound && newRightBound > originalLeftBound &&
               newBottomBound < originalTopBound && newTopBound > originalTopBound) {
        return true;
    } else if (newLeftBound >= originalLeftBound && newRightBound <= originalRightBound &&
               newBottomBound < originalTopBound && newTopBound > originalTopBound) {
        return true;
    } else if (newLeftBound < originalRightBound && newRightBound > originalRightBound &&
               newBottomBound < originalTopBound && newTopBound > originalTopBound) {
        return true;
    } else if (newLeftBound < originalRightBound && newRightBound > originalRightBound &&
               newBottomBound >= originalBottomBound && newTopBound <= originalTopBound) {
        return true;
    } else if (newLeftBound < originalRightBound && newRightBound > originalRightBound &&
               newBottomBound < originalBottomBound && newTopBound > originalBottomBound) {
        return true;
    } else if (newLeftBound >= originalLeftBound && newRightBound <= originalRightBound &&
               newBottomBound < originalBottomBound && newTopBound > originalTopBound) {
        return true;
    } else {
        return false;
    }
*/
    // Test all conditions and return result
    return bottomLeftOverlap || leftOverlap || topLeftOverlap || topOverlap || topRightOverlap ||
           rightOverlap || bottomRightOverlap || bottomOverlap;
}

Rectangle2D getRectangle(const double points[][SIZE], int n) {
    // Using the "fencepost method" here from CS210/211
    double smallestXValue = points[0][0];
    double largestXValue = points[0][0];
    double smallestYValue = points[0][1];
    double largestYValue = points[0][1];

    // Examine every element of array to find largest and smallest x and y values
    for (int column = 0; column < SIZE; column++) {
        for (int row = 0; row < n; row++) {
            if (column == 0) {
                if (points[row][column] > largestXValue) {
                    largestXValue = points[row][column];
                }
                if (points[row][column] < smallestXValue) {
                    smallestXValue = points[row][column];
                }
            } else {
                if (points[row][column] > largestYValue) {
                    largestYValue = points[row][column];
                }
                if (points[row][column] < smallestYValue) {
                    smallestYValue = points[row][column];
                }
            }
        }
    }
    // Use information gathered above to set parameters for new rectangle
    double width = largestXValue - smallestXValue;
    double height = largestYValue - smallestYValue;
    double x = width / 2 + smallestXValue;
    double y = height / 2 + smallestYValue;
    Rectangle2D result = Rectangle2D(x, y, width, height);
    return result;
}
