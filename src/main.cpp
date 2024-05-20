#include <iostream>
#include "OrderBook.h"
#include "MarketDataHandler.h"
#include "RiskManager.h"
#include "StrategyEngine.h"
#include "NetworkLayer.h"

int main()
{
    OrderBook orderBook;
    MarketDataHandler marketDataHandler;
    RiskManager riskManager;
    StrategyEngine strategyEngine;
    NetworkLayer networkLayer;

    // Setup network layer as a publisher
    networkLayer.setupPublisher("tcp://*:5555");

    // Simulate receiving market data
    MarketData data1 = {100.0, 10, 'B', "AAPL", 0};
    MarketData data2 = {101.0, 5, 'B', "AAPL", 0};
    MarketData data3 = {99.0, 8, 'S', "AAPL", 0};
    MarketData data4 = {101.0, 12, 'S', "AAPL", 0};

    marketDataHandler.handleMarketData(data1, orderBook);
    marketDataHandler.handleMarketData(data2, orderBook);
    marketDataHandler.handleMarketData(data3, orderBook);
    marketDataHandler.handleMarketData(data4, orderBook);

    // Execute trading strategy
    strategyEngine.executeStrategy(orderBook, marketDataHandler, riskManager);

    // Send data over the network
    networkLayer.sendData("Market data processed and strategy executed");

    return 0;
}
