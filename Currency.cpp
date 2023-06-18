#include "Currency.h"

Currency::Currency(const std::string &code) : code(code) {}

std::string Currency::getCode() const {
    return code;
}

