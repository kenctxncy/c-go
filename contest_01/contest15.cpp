#include <iostream>
#include <string>

std::string RLE(const std::string& input) {
    if (input.empty()) {
        return "";
    }

    std::string szhatiye = "";
    char cur_char = input[0];
    int count = 1;

    for (size_t i = 1; i < input.length(); i++) {
        if (input[i] == cur_char) {
            count++;
        }
        else {
            szhatiye += cur_char;
            if (count > 1) {
                szhatiye += std::to_string(count);
            }
            cur_char = input[i];
            count = 1;
        }
    }

    szhatiye += cur_char;
    if (count > 1) {
        szhatiye += std::to_string(count);
    }

    return szhatiye;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::string szhatiye = RLE(input);

    std::cout << szhatiye;
}