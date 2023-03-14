#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Undefined" << endl;
    }
    virtual ~Animal() {}
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark bark!" << endl;
    }
};

int main() {
    // Static polymorphism
    Animal* animals[2];
    animals[0] = new Cat();
    animals[1] = new Dog();

    for (Animal* animal : animals) {
        animal->makeSound();
    }

    // Dynamic polymorphism
    Animal* animal = new Cat();
    animal->makeSound();

    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog == nullptr) {
        cout << "Failed to cast object to Dog" << endl;
    }
    else {
        dog->makeSound();
    }

    delete animals[0];
    delete animals[1];
    delete animal;

    return 0;
}