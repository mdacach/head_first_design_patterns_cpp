//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_FLY_WITH_WINGS_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_FLY_WITH_WINGS_HPP_

#include "fly_behavior.hpp"

#include <iostream>

class FlyWithWings : public FlyBehavior
{
    void fly() const override { std::cout << "Flying with Wings!\n"; }
};

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_FLY_WITH_WINGS_HPP_
