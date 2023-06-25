#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

class Currency {
private:
    std::string code;
    double conversionRateToUSD;

public:
    Currency(const std::string& code, double conversionRateToUSD);

    std::string getCode() const;
    double getConversionRateToUSD() const;
};

#endif //CURRENCY_H
