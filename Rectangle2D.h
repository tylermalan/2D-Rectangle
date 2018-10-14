// CS212 Spring 2018
// Gordon Malan
// Submission date: 24 April 2018

#ifndef PROGRAM2_RECTANGLE2D_H
#define PROGRAM2_RECTANGLE2D_H

const int SIZE = 2;

class Rectangle2D {
private:
    double x;
    double y;
    double width;
    double height;

public:
    Rectangle2D();
    Rectangle2D(double, double, double, double);
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    double getWidth() const;
    double getHeight() const;
    void setWidth(double);
    void setHeight(double);
    double getArea() const;
    double getPerimeter() const;
    bool contains(double, double) const;
    bool contains(const Rectangle2D&) const;
    bool overlaps(const Rectangle2D&) const;
};

Rectangle2D getRectangle(const double[][SIZE], int);

#endif //PROGRAM2_RECTANGLE2D_H
