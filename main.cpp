#include <iostream>
#include <functional>
#include "Object.h"


int main()
{
    
    // generate a shared Object. Object inherits from a class called std::enalbe_shared_from_this
    auto myObj = std::make_shared<Object>();
    // Objects holds a membervariable of HealthComponent* and in its constructor assigns it with calling healthcomponent = new HealthComponent();
    // HealthComponent has as a membervariable a Delegate<float,float,float> onHealthChanged;

    myObj->init();
    // std::weak_ptr<Object> selfRef = GetWeakRef();
    // here we create first a weak ref to the Object itself
    
    // healthcomponent->onHealthChanged.BindAction(GetWeakRef(), &Object::OnHealthChanged); 
    // on HealthChanged is a Delegate<float, float, float>. We call the BindAction Methode of the Delegate of healthcomponent
    // BindAction wants a weakRef of the Object and it wants a Functionpointer to the callback function
    // in this case the callback-Function is void Object::OnHealthChanged(float amt, float health, float maxHealth)
    // which expects 3 float as param. Thats why the Delegate on HealthComponent is created like this Delegate<float,float,float> onHealthChanged;
    // BindActions checks if the weakPtr of the Object is not expired. If its still valid, it stores a lambda function in a membervariable
    // of Vector which takes in a std::function<bool(Args...). In this case, because the Delegate (membervariable of healthcomponent) was
    // created with <float, float, float> the stored Lambdafunction expects 3 floats as parameter.

    // healthcomponent->onHealthChanged.Broadcast(11, 89, 100);
    
    // init first creates a local variable which has a weakptr to itself
    // it takes the onHealthChanged delegate and calls BindAction<Object>(weakself, an a functionptr with no params)


   
    return 0;
}