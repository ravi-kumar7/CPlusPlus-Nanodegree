#include <cassert>

// TODO: Declare Vehicle as the base class
class Vehicle{
    public:
    int wheels;
    bool trunk = false;
    int seats;
};
// TODO: Derive Car from Vehicle
class Car :public Vehicle {

};
// TODO: Derive Sedan from Car
class Sedan: public Car {

};
// TODO: Update main to pass the tests
int main() {
  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);
}