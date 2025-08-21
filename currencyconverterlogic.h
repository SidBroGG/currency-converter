#ifndef CURRENCYCONVERTERLOGIC_H
#define CURRENCYCONVERTERLOGIC_H

#include <QObject>
#include <unordered_map>

enum class Currency {
    USD = 0,
    EURO = 1,
    BYN = 2
};

class CurrencyConverterLogic : public QObject
{
    Q_OBJECT

public:
    explicit CurrencyConverterLogic(QObject *parent = nullptr);

public slots:
    QString convert(const QString& from, int from_index, int to_index);

private:
    std::unordered_map<Currency, double> _rates;
};

#endif // CURRENCYCONVERTERLOGIC_H
