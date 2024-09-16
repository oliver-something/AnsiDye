#pragma once

#include <format>
#include <string>
#include <ostream>
#include <unordered_map>

namespace dye {
    constexpr int MIN_COLOR_CODE = 0;
    constexpr int MAX_COLOR_CODE = 255;
    constexpr const char* RESET_CODE = "\033[0m";

    enum class Color {
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
        BrightBlack,
        BrightRed,
        BrightGreen,
        BrightYellow,
        BrightBlue,
        BrightMagenta,
        BrightCyan,
        BrightWhite
    };

    enum class BackgroundColor {
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White
    };

    std::unordered_map<Color, int> colors {
            {Color::Black , 30},
            {Color::Red , 31},
            {Color::Green , 32},
            {Color::Yellow , 33},
            {Color::Blue , 34},
            {Color::Magenta , 35},
            {Color::Cyan , 36},
            {Color::White , 37},
            {Color::BrightBlack , 90},
            {Color::BrightRed , 91},
            {Color::BrightGreen , 92},
            {Color::BrightYellow , 93},
            {Color::BrightBlue , 94},
            {Color::BrightMagenta , 95},
            {Color::BrightCyan , 96},
            {Color::BrightWhite , 97},
    };

    std::unordered_map<BackgroundColor, int> backgroundColors {
            {BackgroundColor::Black , 40},
            {BackgroundColor::Red , 41},
            {BackgroundColor::Green , 42},
            {BackgroundColor::Yellow ,43},
            {BackgroundColor::Blue , 44},
            {BackgroundColor::Magenta , 45},
            {BackgroundColor::Cyan , 46},
            {BackgroundColor::White , 47},
    };

    std::unordered_map<Color, std::string> colorCache;
    std::unordered_map<BackgroundColor, std::string> backgroundCache;

    std::string GetCachedColorText(Color color) {
        if (colorCache.find(color) == colorCache.end()) {
            colorCache[color] = std::format("\033[{}m", colors[color]);
        }
        return colorCache[color];
    }

    std::string GetCachedBackground(BackgroundColor background) {
        if (backgroundCache.find(background) == backgroundCache.end()) {
            backgroundCache[background] = std::format("\033[{}m", backgroundColors[background]);
        }
        return backgroundCache[background];
    }

    std::string GetColorText(Color color, const std::string &text) {
        return GetCachedColorText(color) + text + RESET_CODE;
    }

    std::string GetBackgroundText(BackgroundColor backgroundColor, const std::string & text) {
        return GetCachedBackground(backgroundColor) + text + RESET_CODE;
    }

    constexpr bool IsValidCode(int code) {
        return MIN_COLOR_CODE <= code && code <= MAX_COLOR_CODE;
    }

    [[maybe_unused]]
    std::string GetColorCode(int code) {
        return IsValidCode(code) ? std::format("\033[38;5;{}m", code) : RESET_CODE;
    }

    [[maybe_unused]]
    std::string GetUnderlinedText(int code = 0) {
        return IsValidCode(code) ? std::format("\033[4;38;5;{}m", code) : RESET_CODE;
    }

    [[maybe_unused]]
    std::ostream& ResetColor(std::ostream &os) {
        return os << RESET_CODE;
    }

    [[maybe_unused]]
    std::string GetBackgroundColorCode(int code = 0) {
        return IsValidCode(code) ? std::format("\033[48;5;{}m", code) : RESET_CODE;
    }

    [[maybe_unused]]
    std::string GetBackgroundColor(BackgroundColor color) {
        return std::format("\033[{}m", backgroundColors[color]);
    }

    [[maybe_unused]]
    std::string GetBoldText(Color color) {
        return std::format("\033[1;{}m", colors[color]);
    }

    [[maybe_unused]]
    std::string GetStyledText(Color fg, BackgroundColor bg) {
        return std::format("\033[{};{}m", colors[fg], backgroundColors[bg]);
    }

    //For all colors
    [[maybe_unused]]
    std::string FormattedColoredText(int code, const std::string & text) {
        return GetColorCode(code) + text + RESET_CODE;
    }

    // Default Colors
    [[maybe_unused]]
    std::string BlackText(const std::string & text) {
        return GetColorText(Color::Black, text);
    }

    [[maybe_unused]]
    std::string RedText(const std::string & text) {
        return GetColorText(Color::Red, text);
    }

    [[maybe_unused]]
    std::string GreenText(const std::string & text) {
        return GetColorText(Color::Green, text);
    }

    [[maybe_unused]]
    std::string YellowText(const std::string & text) {
        return GetColorText(Color::Yellow, text);
    }

    [[maybe_unused]]
    std::string BlueText(const std::string & text) {
        return GetColorText(Color::Blue, text);
    }

    [[maybe_unused]]
    std::string MagentaText(const std::string & text) {
        return GetColorText(Color::Magenta, text);
    }

    [[maybe_unused]]
    std::string CyanText(const std::string & text) {
        return GetColorText(Color::Cyan, text);
    }

    [[maybe_unused]]
    std::string WhiteText(const std::string & text) {
        return GetColorText(Color::White, text);
    }

    [[maybe_unused]]
    std::string BrightBlackText(const std::string & text) {
        return GetColorText(Color::BrightBlack, text);
    }

    [[maybe_unused]]
    std::string BrightRedText(const std::string & text) {
        return GetColorText(Color::BrightRed, text);
    }

    [[maybe_unused]]
    std::string BrightGreenText(const std::string & text) {
        return GetColorText(Color::BrightGreen, text);
    }

    [[maybe_unused]]
    std::string BrightYellowText(const std::string & text) {
        return GetColorText(Color::BrightYellow, text);
    }

    [[maybe_unused]]
    std::string BrightBlueText(const std::string & text) {
        return GetColorText(Color::BrightBlue, text);
    }

    [[maybe_unused]]
    std::string BrightMagentaText(const std::string & text) {
        return GetColorText(Color::BrightMagenta, text);
    }

    [[maybe_unused]]
    std::string BrightCyanText(const std::string & text) {
        return GetColorText(Color::BrightCyan, text);
    }

    [[maybe_unused]]
    std::string BrightWhiteText(const std::string & text) {
        return GetColorText(Color::BrightWhite, text);
    }

    [[maybe_unused]]
    std::string BlackBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::Black , text);
    }

    [[maybe_unused]]
    std::string RedBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::Red, text);
    }


    [[maybe_unused]]
    std::string GreenBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::Green, text);
    }


    [[maybe_unused]]
    std::string YellowBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::Yellow, text);
    }


    [[maybe_unused]]
    std::string BlueBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::Blue, text);
    }


    [[maybe_unused]]
    std::string MagentaBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::Magenta, text);
    }


    [[maybe_unused]]
    std::string CyanBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::Cyan, text);
    }


    [[maybe_unused]]
    std::string WhiteBackGroundText(const std::string & text) {
        return GetBackgroundText(BackgroundColor::White, text);
    }

}