// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

// TODO: Define pi
#define pi 3.14;
// TODO: Define the abstract class Shape
  // TODO: Define public virtual functions Area() and Perimeter()
  // TODO: Append the declarations with = 0 to specify pure virtual functions
class Shape{
    public:
        virtual double Area() = 0;
        virtual double Perimeter() = 0;
};
// TODO: Define Rectangle to inherit publicly from Shape
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()
  // TODO: Declare private attributes width and height
class Rectangle : public Shape {
    public:
        Rectangle(int l, int w): length(l), width(w){

        }
        double Area(){
            return length*width;
        }
        double Perimeter() {
            return 2*(length+width);
        }
    private:
        int length;
        int width;

};
// TODO: Define Circle to inherit from Shape
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()
  // TODO: Declare private member variable radius
class Circle: Shape {
    public:
        Circle(int r):radius(r){
        }
        double Area(){
            return pow(radius,2)*pi;
        }
        double Perimeter(){
            return 2 * pi * &radius;
        }
    private:
        int radius;
};
// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}