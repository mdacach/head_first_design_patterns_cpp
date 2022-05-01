//
// Created by matheus on 01/05/22.
//

#include <memory>

// Reference: Meyer's Singleton (https://stackoverflow.com/q/1661529)
class ChocolateBoiler {
private:
    bool m_empty{};
    bool m_boiled{};

private:
    ChocolateBoiler() : m_empty{true}, m_boiled{false} {
    }

public:
    static auto GetInstance() -> ChocolateBoiler & {
        static auto instance = ChocolateBoiler{};
        return instance;
    }

    auto Fill() -> void {
        if (IsEmpty()) {
            m_empty = false;
            m_boiled = false;
            // fill the boiler
        }
        // if it's already full, do nothing
    }

    auto Drain() -> void {
        if (!IsEmpty() && IsBoiled()) {
            // drain the boiled milk and chocolate
            m_empty = true;
        }
    }

    auto Boil() -> void {
        if (!IsEmpty() && !IsBoiled())
            // bring the contents to a boil
            m_boiled = true;
    }

    auto IsEmpty() const -> bool {
        return m_empty;
    }

    auto IsBoiled() const -> bool {
        return m_boiled;
    }
};

int main() {
    auto boiler = ChocolateBoiler::GetInstance();
    boiler.Fill();
    boiler.Drain();
}