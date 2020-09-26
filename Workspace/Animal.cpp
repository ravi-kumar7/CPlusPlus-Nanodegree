#include <iostream>
#include <string>

class Animal {
    public:
        std::string color;
        std::string name;
        int age;
};

class Snake : public Animal {
    public:
        int length;
        void makeSound() {
            std::cout<<"Hiss";
        }
};

class Cat : public Animal {
    public:
     int height;
     void makeSound() {
         std::cout<<"Meow";
     }
};

int main(){
    Snake s;
    Cat c;
    s.makeSound();
    c.makeSound();
}

