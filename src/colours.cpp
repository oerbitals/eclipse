#include <colours.h>

string Colour::red(string text) {
    return "\033[m" + text + "\033[0m";
}

string Colour::green(string text) {
    return "\033[32m" + text + "\033[0m";
}

string Colour::yellow(string text) {
    return "\033[33m" + text + "\033[0m";
}

string Colour::blue(string text) {
    return "\033[34m" + text + "\033[0m";
}

string Colour::magenta(string text) {
    return "\033[35m" + text + "\033[0m";
}

string Colour::cyan(string text) {
    return "\033[36m" + text + "\033[0m";
}

string Colour::orange(string text) {
    return "\033[38;2;255;165;0m" + text + "\033[0m";
}

string Colour::light_gray(string text) {
    return "\033[37m" + text + "\033[0m";
}

string Colour::bright_red(string text) {
    return "\033[91m" + text + "\033[0m";
}

string Colour::bright_green(string text) {
    return "\033[92m" + text + "\033[0m";
}

string Colour::bright_yellow(string text) {
    return "\033[93m" + text + "\033[0m";
}

string Colour::bright_blue(string text) {
    return "\033[94m" + text + "\033[0m";
}

string Colour::bright_magenta(string text) {
    return "\033[95m" + text + "\033[0m";
}

string Colour::bright_cyan(string text) {
    return "\033[96m" + text + "\033[0m";
}

string Colour::white(string text) {
    return "\033[97m" + text + "\033[0m";
}

string Colour::bold(string text) {
    return "\033[1m" + text + "\033[0m";
}

string Colour::dim(string text) {
    return "\033[2m" + text + "\033[0m";
}

string Colour::italic(string text) {
    return "\033[3m" + text + "\033[0m";
}

string Colour::underline(string text) {
    return "\033[4m" + text + "\033[0m";
}

string Colour::strikethrough(string text) {
    return "\033[9m" + text + "\033[0m";
}

string Colour::colour(string text, Code code) {
    return "\033[" + std::to_string(code) + "m" + text + "\033[0m";
}

string Colour::style(string text, Style style) {
    return "\033[" + std::to_string(style) + "m" + text + "\033[0m";
}