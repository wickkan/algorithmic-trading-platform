#ifndef STRATEGYENGINE_H
#define STRATEGYENGINE_H

#include "OrderBook.h"
#include "MarketDataHandler.h"
#include "RiskManager.h"

class StrategyEngine
{
public:
    void executeStrategy(OrderBook &orderBook, MarketDataHandler &marketDataHandler, RiskManager &riskManager);
};

#endif // STRATEGYENGINE_H
