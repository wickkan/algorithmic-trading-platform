#include "OrderBook.h"
#include <iostream>

void OrderBook::addOrder(const Order &order)
{
    if (order.side == 'B')
    {
        buyOrders[order.price].push_back(order);
    }
    else
    {
        sellOrders[order.price].push_back(order);
    }
}

void OrderBook::matchOrders()
{
    while (!buyOrders.empty() && !sellOrders.empty())
    {
        auto buyIt = buyOrders.rbegin();  // Highest buy price
        auto sellIt = sellOrders.begin(); // Lowest sell price

        if (buyIt->first >= sellIt->first)
        {
            auto &buyOrder = buyIt->second.back();
            auto &sellOrder = sellIt->second.back();

            int quantity = std::min(buyOrder.quantity, sellOrder.quantity);

            buyOrder.quantity -= quantity;
            sellOrder.quantity -= quantity;

            if (buyOrder.quantity == 0)
            {
                buyIt->second.pop_back();
                if (buyIt->second.empty())
                {
                    buyOrders.erase(buyIt->first);
                }
            }

            if (sellOrder.quantity == 0)
            {
                sellIt->second.pop_back();
                if (sellIt->second.empty())
                {
                    sellOrders.erase(sellIt->first);
                }
            }

            // Print matched orders
            std::cout << "Matched Order: Buy ID " << buyOrder.id
                      << " and Sell ID " << sellOrder.id
                      << " Quantity: " << quantity << std::endl;
        }
        else
        {
            break;
        }
    }
}
