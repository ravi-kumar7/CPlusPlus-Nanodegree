#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
// public class members
public:
// constructor
Pyramid(int l, int w, int h){
    if(l<0 || w<0 || h<0 )
        throw "Invalid Input";
    length_ = l;
    width_ = w;
    height_ = h;
}
// accessors
  int Length(){ return length_;}
  int Width(){return width_;}
  int Height(){return height_;}
// mutators

  void Length(int l){  
         if(l<0 )
        throw "Invalid Input";
    length_ = l;
    }
  void Width(int w){
          if( w<0)
        throw "Invalid Input";
    width_ = w;

  }
  void Height(int h){
          if(h<0 )
        throw "Invalid Input";

    height_ = h;
  }
// public Volume() function
float Volume(){
    return length_ * width_ * height_/3;
}
// private class members
private:
    int length_;
    int width_;
    int height_;
};

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}