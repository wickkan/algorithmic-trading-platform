#ifndef MARKETDATAHANDLER_H
#define MARKETDATAHANDLER_H

#include "OrderBook.h"
#include "RiskManager.h"

struct MarketData
{
    double price;
    int quantity;
    char side; // 'B' for Buy, 'S' for Sell
    std::string symbol;
    long timestamp;
};

class MarketDataHandler
{
private:
    RiskManager riskManager;

public:
    void handleMarketData(const MarketData &data, OrderBook &orderBook);
};

#endif // MARKETDATAHANDLER_H
