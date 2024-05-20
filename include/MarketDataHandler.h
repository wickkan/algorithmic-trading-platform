#ifndef MARKETDATAHANDLER_H
#define MARKETDATAHANDLER_H

#include "OrderBook.h"

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
public:
    void handleMarketData(const MarketData &data, OrderBook &orderBook);
};

#endif // MARKETDATAHANDLER_H
