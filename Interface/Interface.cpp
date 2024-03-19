


#include<iostream>

using namespace std;

class Animal
{
protected:
    string name;
    int kg;

public:
    Animal() = default;
    Animal(string n, int k)
    {
        name = n;
        kg = k;
    }
    virtual void Print() = 0;
};

struct IAnimal // интерфейс в стиле С++
{
    virtual void Eat() = 0;
    virtual void Move() = 0;
};

struct IBird
{
    virtual void Fly() = 0;
};

struct ISwim
{
    virtual void Swim() = 0;
};

class Cat : public Animal, public IAnimal
{
    string color;

public:
    Cat(string n, int k, string c) : Animal(n, k)
    {
        color = c;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }
    // реализация интерфейса
    void Eat()
    {
        cout << "Cat eats\n";
    }
    void Move()
    {
        cout << "Cat moves\n";
    }
};

class Parrot : public Animal, public IAnimal, public IBird
{
public:
    Parrot(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    // реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Parrot eats\n";
    }
    void Move()
    {
        cout << "Parrot moves\n";
    }
    // реализация интерфейса IBird
    void Fly()
    {
        cout << "Parrot flies\n";
    }
};
class Penguin : public  Animal, public IAnimal, public IBird, public ISwim{
public:
    Penguin(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }

    void Fly() {
        cout << "Penguin is  flying" << endl;
    }
    void Swim() {
        cout << "Penguin is swimming" << endl;
    }
    void Move() {
        cout << "Penguin is moving" << endl;
    }
    void Eat()
    {
        cout << "Penguin eats\n";
    }
    
};
class Elephant: public Animal, public IAnimal  {
public:
    Elephant(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    void Move() {
        cout << "Elephant moves " << endl;
    }
    void Eat()
    {
        cout << "Elephant  eats\n";
    }
};
class Duck: public IAnimal, public Animal, public IBird, public ISwim {
public:
    Duck(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    void Fly() {
        cout << "Duck flyes " << endl;
    }
    void Swim() {
        cout << "Duck swimmes" << endl;
    }
    void Move() {
        cout << "Duck  moves" << endl;
    }
    void Eat()
    {
        cout << "Duck eats\n";
    }
};

int main()
{
    IAnimal* ref = new Cat("Cat", 3, "white");
    ref->Eat();
    ref->Move();

    ref = new Parrot("Ara", 2);
    ref->Eat();
    ref->Move();

   

    IBird* f = new Parrot("Ara", 3);
    f->Fly();
    ref = new Penguin("Sanya", 4);
    
    ref->Eat();
    ref->Move();
    IBird* x = new Penguin("Sanya", 4);
    x->Fly();
    ISwim* y = new Penguin("Sanya", 4);
    y->Swim();
    ref = new Elephant("Vanya", 900);
    ref->Eat();
    ref->Move();
    ref = new Duck("Valya", 65);
    ref->Eat();
    ref->Move();
    IBird* i = new Duck("Valya", 65);
    i->Fly();
    ISwim* p = new Duck("Valya", 90);
    p->Swim();
   
   
}
