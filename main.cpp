#include <iostream>
#include "ansiDye.hpp"

int main() {
    // Basic color text examples
    std::cout << dye::RedText("This is red text!") << std::endl;
    std::cout << dye::GreenText("This is green text!") << std::endl;
    std::cout << dye::BlueText("This is blue text!") << std::endl;

    // Bright color text examples
    std::cout << dye::BrightRedText("This is bright red text!") << std::endl;
    std::cout << dye::BrightGreenText("This is bright green text!") << std::endl;
    std::cout << dye::BrightBlueText("This is bright blue text!") << std::endl;

    // Bold text example
    std::cout << dye::GetBoldText(dye::Color::Yellow) + "This is bold yellow text!" << dye::ResetColor << std::endl;

    // Underlined text example with custom color code
    std::cout << dye::GetUnderlinedText(196) + "This is underlined red text (256-color palette)!" << dye::ResetColor << std::endl;

    // Background color example
    std::cout << dye::GetStyledText(dye::Color::White, dye::BackgroundColor::Blue)
              << "White text on blue background" << dye::RESET_CODE << std::endl;

    // Custom color with 256-color palette
    std::cout << dye::GetColorText(82) + "This is green text from the 256-color palette!" + dye::RESET_CODE << std::endl;

    // Reset color formatting
    std::cout << "This is normal text again." << '\n';

    return 0;
}
