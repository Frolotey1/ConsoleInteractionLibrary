#include "Deletepath.h"

void DeletePath::run(const std::string &&path) {
    if(std::filesystem::exists(path))
        std::filesystem::remove(path);
    std::cout << "Завершение программы" << std::endl;
}
