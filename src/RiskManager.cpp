#include <iostream>
#include "RiskManager.h"

bool RiskManager::validateOrder(const Order &order)
{
    // Implement a basic risk check
    // Example: Maximum order size
    const int maxOrderSize = 100;
    if (order.quantity > maxOrderSize)
    {
        std::cout << "Order rejected: Quantity exceeds maximum order size." << std::endl;
        return false;
    }

    // Add more risk checks as needed
    return true;
}
