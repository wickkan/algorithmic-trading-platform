#ifndef RISKMANAGER_H
#define RISKMANAGER_H

#include "OrderBook.h"

class RiskManager
{
public:
    bool validateOrder(const Order &order);
};

#endif // RISKMANAGER_H
