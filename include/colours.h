#pragma once

#include <string>
using std::string;

namespace Colour {
    enum Code {
        BLACK           = 30,
        RED             = 31,
        GREEN           = 32,
        YELLOW          = 33,
        BLUE            = 34,
        MAGENTA         = 35,
        CYAN            = 36,
        LIGHTGRAY       = 37,
        BRIGHT_RED      = 91,
        BRIGHT_GREEN    = 92,
        BRIGHT_YELLOW   = 93,
        BRIGHT_BLUE     = 94,
        BRIGHT_MAGENTA  = 95,
        BRIGHT_CYAN     = 96,
        WHITE           = 97
    };

    enum Style {
        RESET           = 0,
        BOLD            = 1,
        FAINT           = 2,
        ITALIC          = 3,
        UNDERLINE       = 4,
        STRIKETHROUGH   = 9
    };

    string red(string text);
    string green(string text);
    string yellow(string text);
    string blue(string text);
    string magenta(string text);
    string cyan(string text);
    string light_gray(string text);
    string bright_red(string text);
    string bright_green(string text);
    string bright_yellow(string text);
    string bright_blue(string text);
    string bright_magenta(string text);
    string bright_cyan(string text);
    string white(string text);

    string bold(string text);
    string dim(string text);
    string italic(string text);
    string underline(string text);
    string strikethrough(string text);

    string colour(string text, Code code);
    string style(string text, Style style);    
}