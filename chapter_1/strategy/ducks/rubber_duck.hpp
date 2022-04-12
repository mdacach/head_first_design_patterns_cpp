//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_RUBBER_DUCK_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_RUBBER_DUCK_HPP_

#include "../fly/no_fly.hpp"
#include "../quack/squeak.hpp"
#include "duck.hpp"

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

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_RUBBER_DUCK_HPP_
