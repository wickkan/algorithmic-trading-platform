#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "OrderBook.h"
#include "MarketDataHandler.h"
#include "RiskManager.h"
#include "StrategyEngine.h"
#include "Logger.h"

class Simulator
{
public:
    void runSimulation(const std::vector<MarketData> &historicalData);

private:
    OrderBook orderBook;
    MarketDataHandler marketDataHandler;
    RiskManager riskManager;
    StrategyEngine strategyEngine;
};

#endif // SIMULATOR_H
