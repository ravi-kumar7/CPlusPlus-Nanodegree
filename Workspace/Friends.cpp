// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
// Add public constructor to Square, initialize side
     public:
     Square(int side): side(side) {

     }
    // Add friend class Rectangle
    friend class Rectangle;
    // Add private attribute side
    private:
    int side;
};
// Define class Rectangle
class Rectangle{
    public:  
        Rectangle(Square s):width(s.side), length(s.side) {
        
        }
        int Area(){
            return length * width;
        }
    private:
     int width;
     int length;

};
    // Add public function to Rectangle: Area()
    
    // Add private attributes width, height;

// Define a Rectangle constructor that takes a Square

// Define Area() to compute area of Rectangle

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}