#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

class Currency {
private:
    std::string code;

public:
    Currency(const std::string &code);
    std::string getCode() const;
};

#endif //CURRENCY_H

