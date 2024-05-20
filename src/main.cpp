#include <iostream>
#include "OrderBook.h"
#include "MarketDataHandler.h"
#include "RiskManager.h"
#include "StrategyEngine.h"
#include "Logger.h"

int main()
{
    Logger::init();
    Logger::getLogger()->info("Starting trading platform");

    OrderBook orderBook;
    MarketDataHandler marketDataHandler;
    RiskManager riskManager;
    StrategyEngine strategyEngine;

    MarketData data1 = {100.0, 10, 'B', "AAPL", 0};
    MarketData data2 = {101.0, 5, 'B', "AAPL", 0};
    MarketData data3 = {99.0, 8, 'S', "AAPL", 0};
    MarketData data4 = {101.0, 12, 'S', "AAPL", 0};

    marketDataHandler.handleMarketData(data1, orderBook);
    marketDataHandler.handleMarketData(data2, orderBook);
    marketDataHandler.handleMarketData(data3, orderBook);
    marketDataHandler.handleMarketData(data4, orderBook);

    strategyEngine.executeStrategy(orderBook, marketDataHandler, riskManager);

    Logger::getLogger()->info("Trading platform finished execution");

    return 0;
}
