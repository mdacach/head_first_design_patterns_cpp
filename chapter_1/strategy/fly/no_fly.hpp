//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_NO_FLY_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_NO_FLY_HPP_

#include "fly_behavior.hpp"

#include <iostream>

class NoFly : public FlyBehavior
{
    void fly() const override { std::cout << "I do not fly!\n"; }
};

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_NO_FLY_HPP_
