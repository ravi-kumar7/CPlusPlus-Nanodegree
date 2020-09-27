#include <iostream>
#include <string>
#include <assert.h>

class Animal {
public:
    double age;
};

class Pet {
public:
    std::string name;
};

// Dog derives from *both* Animal and Pet
class Dog : public Animal, public Pet {
public:
    std::string breed;
};

class Cat: public Animal, public Pet {
    public:
     std::string color;
     Cat(std::string name, int age, std::string color): color(color){
         name = name;
         age = age;
     }
};

int main()
{
    Cat cat("Max",10,"black");
    assert(cat.color == "black");
    assert(cat.age == 10);
    assert(cat.name == "Max");
}