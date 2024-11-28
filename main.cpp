#include <iostream>
#include <functional>
#include "Object.h"


int main()
{
    
    // generate a shared Object. Objct inherits from a class called std::enalbe_shared_from_this
    auto myObj = std::make_shared<Object>();
    // Objects holds a membervariable of HealthComponent* and in its constructor assigns it with calling healthcomponent = new HealthComponent();
    // HealthComponent has a Delegate<float,float,float> onHealthChanged;

    myObj->init();
    // std::weak_ptr<Object> selfRef = GetWeakRef();
    // healthcomponent->onHealthChanged.BindAction(GetWeakRef(), &Object::OnHealthChanged);
    // healthcomponent->onHealthChanged.Broadcast(11, 89, 100);
    // init first creates a local variable which has a weakptr to itself
    // it takes the onHealthChanged delegate and calls BindAction<Object>(weakself, an a functionptr with no params)

    return 0;
}