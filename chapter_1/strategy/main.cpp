#include "ducks/duck.hpp"
#include "ducks/mallard_duck.hpp"
#include "ducks/rubber_duck.hpp"
#include "ducks/wooden_duck.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

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