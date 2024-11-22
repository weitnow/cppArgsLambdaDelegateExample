#include "Object.h"
#include "HealthComponent.h"

Object::Object()
{
    healthcomponent = new HealthComponent();
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

void Object::Destroy()
{
    //Function which is called when Obj is destroyed
    OnDestroy.Broadcast(this);
}
