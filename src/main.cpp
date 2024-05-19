#include <iostream>
#include "OrderBook.h"

int main()
{
    OrderBook orderBook;

    // id, price, quantity, side, symbol, timestamp
    Order buyOrder1 = {1, 100.0, 10, 'B', "AAPL", 0};
    Order buyOrder2 = {2, 101.0, 5, 'B', "AAPL", 0};
    Order sellOrder1 = {3, 99.0, 8, 'S', "AAPL", 0};
    Order sellOrder2 = {4, 101.0, 12, 'S', "AAPL", 0};

    orderBook.addOrder(buyOrder1);
    orderBook.addOrder(buyOrder2);
    orderBook.addOrder(sellOrder1);
    orderBook.addOrder(sellOrder2);

    orderBook.matchOrders();

    return 0;
}
