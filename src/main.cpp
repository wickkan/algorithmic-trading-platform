#include <iostream>
#include "OrderBook.h"
#include "MarketDataHandler.h"

int main()
{
    OrderBook orderBook;
    MarketDataHandler marketDataHandler;

    MarketData data1 = {100.0, 10, 'B', "AAPL", 0};
    MarketData data2 = {101.0, 5, 'B', "AAPL", 0};
    MarketData data3 = {99.0, 8, 'S', "AAPL", 0};
    MarketData data4 = {101.0, 12, 'S', "AAPL", 0};
    MarketData data5 = {102.0, 150, 'B', "AAPL", 0}; // Exceeds max order size

    marketDataHandler.handleMarketData(data1, orderBook);
    marketDataHandler.handleMarketData(data2, orderBook);
    marketDataHandler.handleMarketData(data3, orderBook);
    marketDataHandler.handleMarketData(data4, orderBook);
    marketDataHandler.handleMarketData(data5, orderBook); // This order should be rejected

    orderBook.matchOrders();

    return 0;
}
