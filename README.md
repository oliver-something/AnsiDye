Here's a description you can use for the markdown file of your library:

---

# **AnsiDye**

AnsiDye is a lightweight cross-platform C++ library designed to make colorizing console text easy and efficient using ANSI escape codes. Whether you're looking to add vibrant foreground and background colors or apply styles like bold and underline, AnsiDye provides an intuitive interface for formatting text with both standard and 256-color options.

## **Features**

- **Cross-Platform**: Works seamlessly on Linux, macOS, and Windows (with ANSI support).
- **Foreground and Background Colors**: Apply 16 basic and bright colors to your text or backgrounds.
- **256-color Support**: Use any of the 256 ANSI colors by specifying their code.
- **Bold and Underline Text**: Style your text with additional emphasis.
- **Color Caching**: Efficiently reuse preformatted color codes for faster performance.
- **Reset Formatting**: Easily reset text back to default styles.
- **Simple Integration**: Just include the header file in your project to get started.

## **Example Usage**

```cpp
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
    std::cout << dye::GetBoldText(dye::Color::Yellow) + "This is bold yellow text!" + dye::RESET_CODE << std::endl;

    // Underlined text example with custom color code
    std::cout << dye::GetUnderlinedText(196) + "This is underlined red text (256-color palette)!" + dye::RESET_CODE << std::endl;

    // Background color example
    std::cout << dye::GetStyledText(dye::Color::White, dye::BackgroundColor::Blue)
              << "White text on blue background" << dye::RESET_CODE << std::endl;

    // Custom color with 256-color palette
    std::cout << dye::GetColorText(82) + "This is green text from the 256-color palette!" + dye::RESET_CODE << std::endl;

    // Reset color formatting
    std::cout << "This is normal text again." << std::endl;

    return 0;
}

```

---

AnsiDye is open-source and licensed under the MIT License.

