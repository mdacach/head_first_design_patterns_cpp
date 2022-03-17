#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

// Interfaces for Behaviors
class FlyBehavior
{
public:
    virtual void fly() const = 0;
    virtual ~FlyBehavior() = default;
};

class NoFly : public FlyBehavior
{
    void fly() const override { std::cout << "I do not fly!\n"; }
};

class FlyWithWings : public FlyBehavior
{
    void fly() const override { std::cout << "Flying with Wings!\n"; }
};

class QuackBehavior
{
public:
    virtual void quack() const = 0;
    virtual ~QuackBehavior() = default;
};

class Quack : public QuackBehavior
{
    void quack() const override { std::cout << "Quack!\n"; }
};

class Squeak : public QuackBehavior
{
    void quack() const override { std::cout << "Squeak!\n"; }
};

class Silence : public QuackBehavior
{
    void quack() const override { std::cout << "<< Silence >>\n"; }
};

// Superclass for all kinds of Ducks
class Duck
{
    // can be made a shared pointer to a global object, to save memory
    // we can create a UNIQUE FlyBehavior object for each different behavior, and store shared
    // pointers to those across our uses
protected:
    std::unique_ptr<FlyBehavior> fly_behavior_{};
    std::unique_ptr<QuackBehavior> quack_behavior_{};

public:
    virtual ~Duck() = default;

    virtual void display() const = 0;

    void fly() const { fly_behavior_->fly(); }

    void quack() const { quack_behavior_->quack(); }
};

class MallardDuck : public Duck
{
public:
    MallardDuck()
    {
        fly_behavior_ = std::make_unique<FlyWithWings>();
        quack_behavior_ = std::make_unique<Quack>();
    }

    void display() const override { std::cout << "I am a Mallard Duck!\n"; }
};

class RubberDuck : public Duck
{
public:
    RubberDuck()
    {
        fly_behavior_ = std::make_unique<NoFly>();
        quack_behavior_ = std::make_unique<Squeak>();
    }

    void display() const override { std::cout << "I am a Rubber Duck\n"; }
};

class WoodenDuck : public Duck
{
public:
    WoodenDuck()
    {
        fly_behavior_ = std::make_unique<NoFly>();
        quack_behavior_ = std::make_unique<Silence>();
    }

    void display() const override { std::cout << "I am a Wooden Duck!\n"; }
};

int main()
{
    std::unique_ptr<Duck> some_duck = std::make_unique<MallardDuck>();
    std::unique_ptr<Duck> some_other_duck = std::make_unique<WoodenDuck>();

    std::vector<std::unique_ptr<Duck>> ducks{};
    ducks.push_back(std::move(some_duck));
    ducks.push_back(std::move(some_other_duck));
    ducks.push_back(std::make_unique<RubberDuck>());

    auto ProcessDuck = [](const auto& duck)
    {
        duck->display();
        duck->fly();
        duck->quack();
        std::cout << '\n';
    };
    std::for_each(std::begin(ducks), std::end(ducks), ProcessDuck);
}