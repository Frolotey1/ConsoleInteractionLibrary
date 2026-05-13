#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H
#include "Input.h"
#include "Output.h"
#include <string>
#include <sstream>

template<typename T>
class InputDialog {
    Output& output;
    Input& input;
    std::size_t count_attempts;
public:
    InputDialog(Output& _output, Input& _input)
        : output(_output), input(_input), count_attempts(5) {}

    T dialog(const std::string& prompt) {
        for (std::size_t repeat_dialog = 0; repeat_dialog < count_attempts; ++repeat_dialog) {
            output.write(prompt + ": ");
            std::string line = input.read_line();

            T value;
            if (parse(line, value)) {
                return value;
            }

            if (repeat_dialog < count_attempts - 1) {
                std::string msg = "Ошибка парсинга. Осталось попыток: " +
                                  std::to_string(count_attempts - repeat_dialog - 1);
                output.write_line(msg);
            }
        }

        output.write_line("Превышено число попыток");
        return T{};
    }

    void change_count_attempts(std::size_t new_attempts) {
        count_attempts = new_attempts;
    }

private:
    bool parse(const std::string& input_str, T& value) {
        if constexpr (std::is_same_v<T, std::string>) {
            value = input_str;
            return true;
        }

        std::istringstream stream(input_str);
        stream >> value;
        if (stream.fail()) {
            return false;
        }

        char leftover;
        if (stream >> leftover) {
            return false;
        }
        return true;
    }
};

#endif
