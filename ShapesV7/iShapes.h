//Programmer: Ethan Chiang
//Programmer ID: 1538719
#ifndef iShape_H
#define iShape_H

#include <string>
#include <vector>
using namespace std;

struct Shape
{
  virtual void output(ostream&) const  = 0;
  virtual ~Shape() {}
};
ostream& operator<< (ostream&, const Shape* const);

class Square : public Shape
{
  protected:
  const double side;

  public:
  Square(const vector<string>&);
  Square& operator=(const Square&); // parameter is a constant reference
  void output(ostream&) const;
};

namespace comsc
{
	class Rectangle : public Shape
	{
	protected:
		const double length;
		const double width;

	public:
		Rectangle(const vector<string>&);
		Rectangle& operator=(const Rectangle&);
		void output(ostream&) const;
	};
}

class Circle : public Shape
{
  protected:
  const double radius;

  public:
  Circle(const vector<string>&);
  Circle& operator=(const Circle&);
  void output(ostream&) const;
};

class Triangle : public Shape
{
  protected:
  const double side;

  public:
  Triangle(const vector<string>&);
  Triangle& operator=(const Triangle&);
  void output(ostream&) const;
};

class Cube : public Square
{
  public:
  Cube(const vector<string>&);
  Cube& operator=(const Cube&);
  void output(ostream&) const;
};

class Box : public comsc::Rectangle
{
  const double height;

  public:
  Box(const vector<string>&);
  Box& operator=(const Box&);
  void output(ostream&) const;
};

class Cylinder : public Circle
{
  const double height;

  public:
  Cylinder(const vector<string>&);
  Cylinder& operator=(const Cylinder&);
  void output(ostream&) const;
};

class Prism : public Triangle
{
  const double height;

  public:
  Prism(const vector<string>&);
  Prism& operator=(const Prism&);
  void output(ostream&) const;
};

ostream& roundingTwo(ostream&); // rounding manipulator
ostream& roundingOff(ostream&); // turn off manipulator

#endif
