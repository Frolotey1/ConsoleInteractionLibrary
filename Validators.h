#ifndef VALIDATORS_H
#define VALIDATORS_H
#include <string>
#include <cctype>
#include <type_traits>

inline bool not_empty(const std::string& s) {
    return !s.empty();
}

inline bool is_alnum(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!std::isalnum(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

template<typename T>
inline typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
positive(T x) {
    return x > 0;
}

#endif
