//
// Created by Parth Parakh on 07/01/21.
//

#include "Design_Pattern.h"

ClearingHouse *ClearingHouse::s_clearingHouse = nullptr;
ClearingHouse &ClearingHouse::getClearingHouse()
{
    if(s_clearingHouse== nullptr)
    {
        s_clearingHouse = new ClearingHouse();
    }
    return *s_clearingHouse;
}
void useClearingHouse()
{
    Trade trade;
    ClearingHouse &ch = ClearingHouse::getClearingHouse();
    ch.clearTrade(trade);
}

