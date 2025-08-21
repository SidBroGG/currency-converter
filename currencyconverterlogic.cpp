#include "currencyconverterlogic.h"

CurrencyConverterLogic::CurrencyConverterLogic(QObject *parent)
    : QObject{parent},
    _rates({
              {Currency::USD, 1.0},
              {Currency::EURO, 0.86},
              {Currency::BYN, 3.37}
    })
{}

QString CurrencyConverterLogic::convert(const QString& from, int from_index, int to_index) {
    double from_number = from.toDouble();

    double to_number =
        from_number / _rates[static_cast<Currency>(from_index)] * _rates[static_cast<Currency>(to_index)];

    return QString::number(to_number, 'f', 2);
}
