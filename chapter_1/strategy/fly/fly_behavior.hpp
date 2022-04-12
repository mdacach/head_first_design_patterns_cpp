//
//

#ifndef HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_FLY_BEHAVIOR_HPP_
#define HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_FLY_BEHAVIOR_HPP_

class FlyBehavior
{
public:
    virtual void fly() const = 0;
    virtual ~FlyBehavior() = default;
};

#endif // HEAD_FIRST_DESIGN_PATTERNS_CHAPTER_1_STRATEGY_FLY_BEHAVIOR_HPP_
