//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_SILENCE_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_SILENCE_HPP_

#include "quack_behavior.hpp"

#include <iostream>

class Silence : public QuackBehavior
{
    void quack() const override { std::cout << "<< Silence >>\n"; }
};

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_QUACK_SILENCE_HPP_
