//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_WOODEN_DUCK_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_WOODEN_DUCK_HPP_

#include "../fly/no_fly.hpp"
#include "../quack/silence.hpp"
#include "duck.hpp"

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

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_WOODEN_DUCK_HPP_
