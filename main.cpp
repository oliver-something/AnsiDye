#include <iostream>
#include "ansiDye.hpp"

class Range final {
public:
    static std::vector<int> range(int start, int end, int step) {
        std::vector<int> result;
        if (step == 0)
            throw std::invalid_argument("Step cannot be zero.");
        if (step > 0) {
            for(auto i = start; i < end; i += step) {
                result.emplace_back(i);
            }
        } else {
            for(auto i = start; i > end; i += step) {
                result.emplace_back(i);
            }
        }
        return result;
    }
    [[maybe_unused]]
    static std::vector<int> range(int end) {
        return range(0, end, 1);
    }
    [[maybe_unused]]
    static std::vector<int> range(int start, int end) {
        return range(start, end, 1);
    }
};

int main() {
    // Basic color text examples
    std::cout << dye::RedText("This is red text!") << '\n';
    std::cout << dye::GreenText("This is green text!") << '\n';
    std::cout << dye::BlueText("This is blue text!") << '\n';

    // Bright color text examples
    std::cout << dye::BrightRedText("This is bright red text!") << '\n';
    std::cout << dye::BrightGreenText("This is bright green text!") << '\n';
    std::cout << dye::BrightBlueText("This is bright blue text!") << '\n';

    // Bold text example
    std::cout << dye::GetBoldText(dye::Color::Yellow) + "This is bold yellow text!" << dye::ResetColor << '\n';

    // Underlined text example with custom color code
    std::cout << dye::GetUnderlinedText(196) + "This is underlined red text (256-color palette)!" << dye::ResetColor << '\n';

    // Background color example
    std::cout << dye::GetStyledText(dye::Color::White, dye::BackgroundColor::Blue)
              << "White text on blue background" << dye::ResetColor << '\n';

    // Custom color with 256-color palette
    std::cout << dye::GetColorCode(82) + "This is green text from the 256-color palette!" << dye::ResetColor << '\n';

    // Reset color formatting
    std::cout << "This is normal text again." << '\n';

    // Using Basic background colors
    std::cout << dye::GetBackgroundText(dye::BackgroundColor::Cyan, "Cyan BackGround text color!") << '\n';

    std::cout << "Normal Text \n";

    std::cout << "\nAll Colors---------------------------\n\n";
    // Text colors
    for (const auto & i: Range::range(256)) {
        std::cout << dye::GetColorCode(i) << "Text\t";
        if ((i + 1) % 8 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\nAll Background Colors---------------------------\n\n";
    for (const auto & i : Range::range(256)) {
        std::cout << dye::GetBackgroundColorCode(i) << "Text\t" << dye::ResetColor;
        if ((i + 1) % 8 == 0) {
            std::cout << "\n";
        }
    }

    return 0;
}
