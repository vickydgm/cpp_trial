//
//  main.cpp
//  ShopFiniteStateMachine
//
//  Created by Smruti  Ranjan Panda on 15/07/17.
//  Copyright © 2017 Smruti  Ranjan Panda. All rights reserved.
//

#include "Machine.hh"

int main(int argc, const char * argv[]) {
    // insert code here...
    Machine machine(10);
    
    machine.sell(10);
    std::cout << "Sold 10 items" << std::endl;
    
    try {
        machine.sell(1);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    machine.refill(20);
    std::cout << "Refilled 20 items" << std::endl;
    
    machine.sell(10);
    std::cout << "Sold 10 items" << std::endl;
    std::cout << "Remaining " << machine.getCurrentStock() << " items" << std::endl;
    
    machine.sell(5);
    std::cout << "Sold 5 items" << std::endl;
    std::cout << "Remaining " << machine.getCurrentStock() << " items" << std::endl;
    
    try {
        machine.sell(10);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
