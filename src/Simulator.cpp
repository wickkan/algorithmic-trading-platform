#include "Simulator.h"

void Simulator::runSimulation(const std::vector<MarketData> &historicalData)
{
    Logger::getLogger()->info("Starting simulation");

    for (const auto &data : historicalData)
    {
        marketDataHandler.handleMarketData(data, orderBook);
        strategyEngine.executeStrategy(orderBook, marketDataHandler, riskManager);
    }

    Logger::getLogger()->info("Simulation finished");
}
