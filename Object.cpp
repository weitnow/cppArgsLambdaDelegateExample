#include "Object.h"
#include "HealthComponent.h"

Object::Object()
{
    std::cout << "Object constructed" << std::endl;
    std::cout << "-----------------" << std::endl;
    healthcomponent = new HealthComponent();
}

Object::~Object()
{
    std::cout << "-----------------" << std::endl;
    std::cout << "Object destructed" << std::endl;
}

void Object::init()
{
    std::weak_ptr<Object> selfRef = GetWeakRef();

    healthcomponent->onHealthChanged.BindAction(GetWeakRef(), &Object::OnHealthChanged);

    healthcomponent->onHealthChanged.Broadcast(11, 89, 100);
}


void Object::OnHealthChanged(float amt, float health, float maxHealth)
{
    
    std::cout << "Amt:" << amt << ", health:" << health << ", maxHealth:" << maxHealth << std::endl;
    
}

