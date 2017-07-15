//
//  Machine.cpp
//  ShopFiniteStateMachine
//
//  Created by Smruti  Ranjan Panda on 15/07/17.
//  Copyright © 2017 Smruti  Ranjan Panda. All rights reserved.
//
#include "Machine.hh"

Machine::Machine(int stockQuantity)
: mStockQuantity(stockQuantity),
mState(new Normal())
{
    std::cout << "Machine ctor called\n";
}

Machine::~Machine() {
    
    std::cout << "Machine dtor called\n";
    
    if(mState) {
        delete mState;
        mState = NULL;
    }
}

void Machine::sell(int stockQuantity) {
    mState->sell(this , stockQuantity);
}

void Machine::refill(int stockQuantity) {
    mState->refill(this , stockQuantity);
}

void Machine::setCurrentState(AbstractState* currState)
{
    mState = currState;
}

void Machine::updateStock(int quantity) {
    mStockQuantity = quantity;
}

int Machine::getCurrentStock() {
    return mStockQuantity;
}
