//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_SQUEAK_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_SQUEAK_HPP_

#include "quack_behavior.hpp"

#include <iostream>

class Squeak : public QuackBehavior
{
    void quack() const override { std::cout << "Squeak!\n"; }
};

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_SQUEAK_HPP_
