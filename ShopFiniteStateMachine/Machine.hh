//
//  Machine.hpp
//  ShopFiniteStateMachine
//
//  Created by Smruti  Ranjan Panda on 15/07/17.
//  Copyright © 2017 Smruti  Ranjan Panda. All rights reserved.
//
#pragma once

#include<iostream>
#include "MachineStates.hh"
#include <stdexcept>

class AbstractState;

class Machine
{
public:
    Machine(int stockQuantity);
    void sell(int quantity);
    void refill(int refill);
    void setCurrentState(AbstractState* currState);
    void updateStock(int quantity);
    
    int getCurrentStock();
    
    ~Machine();
    
private:
    int mStockQuantity;
    AbstractState* mState;
};
