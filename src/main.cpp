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
        {100.0, 10, 'B', "AAPL", 0},
        {101.0, 5, 'B', "AAPL", 0},
        {99.0, 8, 'S', "AAPL", 0},
        {101.0, 12, 'S', "AAPL", 0}};

    // Run the simulation
    Simulator simulator;
    simulator.runSimulation(historicalData);

    Logger::getLogger()->info("Trading platform finished execution");

    return 0;
}
