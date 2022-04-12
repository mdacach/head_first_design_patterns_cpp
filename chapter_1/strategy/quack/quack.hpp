//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_QUACK_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_QUACK_HPP_

#include "quack_behavior.hpp"

#include <iostream>

class Quack : public QuackBehavior
{
    void quack() const override { std::cout << "Quack!\n"; }
};

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_QUACK_HPP_
