//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_MALLARD_DUCK_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_MALLARD_DUCK_HPP_

#include "../fly/fly_with_wings.hpp"
#include "../quack/quack.hpp"
#include "duck.hpp"

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

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_MALLARD_DUCK_HPP_
