#include "../include/ConsoleInput.h"
#include "../include/ConsoleOutput.h"
#include "../include/MenuRunner.h"

int main() {
    ConsoleOutput output;
    ConsoleInput input;

    MenuRunner runner(output, input);
    runner.test();

    return 0;
}
