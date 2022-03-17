#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class WeaponBehavior
{
public:
    virtual void UseWeapon() const = 0;
    virtual ~WeaponBehavior() = default;
};

class KnifeBehavior : public WeaponBehavior
{
    void UseWeapon() const override { std::cout << "Cutting with Knife!\n"; }
};

class BowAndArrowBehavior : public WeaponBehavior
{
    void UseWeapon() const override { std::cout << "Shooting with a Bow!\n"; }
};

class AxeBehavior : public WeaponBehavior
{
    void UseWeapon() const override { std::cout << "Chopping with an Axe!\n"; }
};

class SwordBehavior : public WeaponBehavior
{
    void UseWeapon() const override { std::cout << "Swinging with a Sword!\n"; }
};

class Character
{
protected:
    std::shared_ptr<WeaponBehavior> weapon_behavior_{};

    virtual void ShowInternalDescription() const = 0;
    virtual ~Character() = default;

public:
    virtual void Fight() const
    {
        ShowInternalDescription();
        if (weapon_behavior_)
            weapon_behavior_->UseWeapon();
    }

    virtual void SetWeapon(std::shared_ptr<WeaponBehavior> weapon_behavior)
    {
        weapon_behavior_ = std::move(weapon_behavior);
    }
};

class Queen : public Character
{
    void ShowInternalDescription() const override { std::cout << "Queen is fighting!\n"; }
};

class King : public Character
{
    void ShowInternalDescription() const override { std::cout << "King is fighting!\n"; }
};

class Troll : public Character
{
    void ShowInternalDescription() const override { std::cout << "Troll is fighting!\n"; }
};

class Knight : public Character
{
    void ShowInternalDescription() const override { std::cout << "Knight is fighting!\n"; }
};

int main()
{
    using WeaponBehaviorPointer = std::shared_ptr<WeaponBehavior>;
    std::vector<WeaponBehaviorPointer> available_weapons{};
    available_weapons.push_back(std::make_unique<KnifeBehavior>());
    available_weapons.push_back(std::make_unique<BowAndArrowBehavior>());
    available_weapons.push_back(std::make_unique<AxeBehavior>());
    available_weapons.push_back(std::make_unique<SwordBehavior>());

    std::unique_ptr<Character> king = std::make_unique<King>();
    auto KingTestWeapon = [&character = king](const auto& weapon)
    {
        character->SetWeapon(std::move(weapon));
        character->Fight();
    };
    std::for_each(std::begin(available_weapons), std::end(available_weapons), KingTestWeapon);

    std::unique_ptr<Character> troll = std::make_unique<Troll>();
    auto TrollTestWeapon = [&character = troll](const auto& weapon)
    {
        character->SetWeapon(std::move(weapon));
        character->Fight();
    };
    std::for_each(std::begin(available_weapons), std::end(available_weapons), TrollTestWeapon);
}
