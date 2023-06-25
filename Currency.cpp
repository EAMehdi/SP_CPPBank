#include "Currency.h"

Currency::Currency(const std::string& code, double conversionRateToUSD)
        : code(code), conversionRateToUSD(conversionRateToUSD) {}

std::string Currency::getCode() const {
    return this->code;
}

double Currency::getConversionRateToUSD() const {
    return this->conversionRateToUSD;
}
