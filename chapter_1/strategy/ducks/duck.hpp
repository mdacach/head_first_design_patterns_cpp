#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_DUCK_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_DUCK_HPP_

#include "../fly/fly_behavior.hpp"
#include "../quack/quack_behavior.hpp"

#include <memory>

// Superclass for all kinds of Ducks
class Duck
{
protected:
    std::unique_ptr<FlyBehavior> fly_behavior_{};
    std::unique_ptr<QuackBehavior> quack_behavior_{};

public:
    virtual ~Duck() = default;

    virtual void display() const = 0;

    void fly() const { fly_behavior_->fly(); }

    void quack() const { quack_behavior_->quack(); }
};

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_DUCKS_DUCK_HPP_
