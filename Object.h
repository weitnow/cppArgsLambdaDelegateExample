#include <memory>
#include <iostream>
#include "Delegate.h"

#ifndef OBJECT_H
#define OBJECT_H

class HealthComponent;

class Object : public std::enable_shared_from_this<Object>
{
    public:

    Object();
    virtual ~Object();
    void init();

    virtual std::weak_ptr<Object> GetWeakRef() {return weak_from_this();};
    virtual void OnHealthChanged(float amt, float health, float maxHealth);
    

    protected:
    HealthComponent* healthcomponent;



    


};

#endif