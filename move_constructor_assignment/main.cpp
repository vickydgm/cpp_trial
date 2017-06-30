//
//  main.cpp
//  move_constructor_assignment
//
//  Created by Smruti  Ranjan Panda on 30/06/17.
//  Copyright © 2017 Smruti  Ranjan Panda. All rights reserved.
//

#include <iostream>

template<class T>
class Auto_ptr4
{
    T* m_ptr;
public:
    Auto_ptr4(T* ptr = nullptr)
    :m_ptr(ptr)
    {
    }
    
    ~Auto_ptr4()
    {
        delete m_ptr;
    }
    
    // Copy constructor
    // Do deep copy of a.m_ptr to m_ptr
    Auto_ptr4(const Auto_ptr4& a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }
    
    // Move constructor
    // Transfer ownership of a.m_mptr to m_ptr
    Auto_ptr4(Auto_ptr4&& a)
    : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
    }
    
    // Copy assignment
    // Do deep copy of a.m_ptr to m_ptr
    Auto_ptr4& operator=(const Auto_ptr4& a)
    {
        // Self-assignment detection
        if (&a == this)
            return *this;
        
        // Release any resource we're holding
        delete m_ptr;
        
        // Copy the resource
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
        
        return *this;
    }
    
    // Move assignment
    // Transfer ownership of a.m_ptr to m_ptr
    Auto_ptr4& operator=(Auto_ptr4&& a)
    {
        // Self-assignment detection
        if (&a == this)
            return *this;
        
        // Release any resource we're holding
        delete m_ptr;
        
        // Transfer ownership of a.m_ptr to m_ptr
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        
        return *this;
    }
    
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr4<Resource> generateResource()
{
    Auto_ptr4<Resource> res(new Resource);
    return res; // this return value will invoke the move constructor
}

int main()
{
    Auto_ptr4<Resource> mainres;
    mainres = generateResource(); // this assignment will invoke the move assignment
    
    return 0;
}
