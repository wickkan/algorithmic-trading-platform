#include <iostream>
#include "OrderBook.h"
#include "MarketDataHandler.h"
#include "RiskManager.h"
#include "StrategyEngine.h"
#include "Logger.h"
#include "Simulator.h"

int main()
{
    Logger::init();
    Logger::getLogger()->info("Starting trading platform");

    // Create historical market data
    std::vector<MarketData> historicalData = {
        // AAPL
        {100.0, 10, 'B', "AAPL", 0},
        {101.0, 5, 'B', "AAPL", 1},
        {99.0, 8, 'S', "AAPL", 2},
        {101.0, 12, 'S', "AAPL", 3},
        {102.0, 15, 'B', "AAPL", 4},
        {98.0, 10, 'S', "AAPL", 5},
        {100.0, 20, 'B', "AAPL", 6},
        {99.5, 25, 'S', "AAPL", 7},

        // MSFT
        {210.0, 50, 'B', "MSFT", 0},
        {211.0, 30, 'B', "MSFT", 1},
        {209.0, 40, 'S', "MSFT", 2},
        {212.0, 20, 'S', "MSFT", 3},
        {213.0, 35, 'B', "MSFT", 4},
        {208.0, 45, 'S', "MSFT", 5},
        {211.0, 25, 'B', "MSFT", 6},
        {210.5, 30, 'S', "MSFT", 7},

        // GOOGL
        {1500.0, 5, 'B', "GOOGL", 0},
        {1502.0, 3, 'B', "GOOGL", 1},
        {1498.0, 2, 'S', "GOOGL", 2},
        {1501.0, 4, 'S', "GOOGL", 3},
        {1503.0, 6, 'B', "GOOGL", 4},
        {1497.0, 7, 'S', "GOOGL", 5},
        {1500.0, 8, 'B', "GOOGL", 6},
        {1499.5, 9, 'S', "GOOGL", 7},

        // TSLA
        {700.0, 10, 'B', "TSLA", 0},
        {705.0, 7, 'B', "TSLA", 1},
        {695.0, 5, 'S', "TSLA", 2},
        {710.0, 12, 'S', "TSLA", 3},
        {715.0, 10, 'B', "TSLA", 4},
        {690.0, 15, 'S', "TSLA", 5},
        {700.0, 20, 'B', "TSLA", 6},
        {695.5, 25, 'S', "TSLA", 7},

        // AMZN
        {3100.0, 4, 'B', "AMZN", 0},
        {3105.0, 3, 'B', "AMZN", 1},
        {3090.0, 2, 'S', "AMZN", 2},
        {3110.0, 5, 'S', "AMZN", 3},
        {3120.0, 6, 'B', "AMZN", 4},
        {3080.0, 7, 'S', "AMZN", 5},
        {3100.0, 8, 'B', "AMZN", 6},
        {3095.0, 9, 'S', "AMZN", 7}};

    OrderBook orderBook;
    MarketDataHandler marketDataHandler;

    for (const auto &data : historicalData)
    {
        marketDataHandler.handleMarketData(data, orderBook);
    }

    std::cout << "Order book before matching:" << std::endl;
    orderBook.printOrderBook();

    orderBook.matchOrders();

    std::cout << "Order book after matching:" << std::endl;
    orderBook.printOrderBook();

    Logger::getLogger()->info("Trading platform finished execution");

    return 0;
}
