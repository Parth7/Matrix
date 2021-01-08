//
// Created by Parth Parakh on 07/01/21.
//

#ifndef OPTIONS_DERIVATIVES_PROGRAMMING_IN_CPP_DESIGN_PATTERN_H
#define OPTIONS_DERIVATIVES_PROGRAMMING_IN_CPP_DESIGN_PATTERN_H

class Trade
{
    //...
};

class ClearingHouse
{
private:  // they are private bc singleton pattern
    ClearingHouse() = default;
    ~ClearingHouse() = default;
    //copy constructor and assignment operator is not implemented
    ClearingHouse ( ClearingHouse &obj);
    ClearingHouse &operator=(const ClearingHouse * obj);

    static ClearingHouse *s_clearingHouse;

public :
    static ClearingHouse &getClearingHouse();
    void clearTrade(const Trade &T);
};



#endif //OPTIONS_DERIVATIVES_PROGRAMMING_IN_CPP_DESIGN_PATTERN_H
