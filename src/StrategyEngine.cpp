#include <iostream>
#include "StrategyEngine.h"

void StrategyEngine::executeStrategy(OrderBook &orderBook, MarketDataHandler &marketDataHandler, RiskManager &riskManager)
{
    // Example strategy: simple moving average crossover
    // This is just a placeholder for an actual strategy implementation

    // Create a sample order to simulate strategy execution
    Order sampleOrder = {0, 102.0, 10, 'B', "AAPL", 0}; // Buy 10 shares of AAPL at $102.0

    // Validate the order using the risk manager
    if (riskManager.validateOrder(sampleOrder))
    {
        // Add the order to the order book
        orderBook.addOrder(sampleOrder);
    }
    else
    {
        std::cout << "Order rejected by risk manager" << std::endl;
    }

    // Match orders in the order book
    orderBook.matchOrders();
}
