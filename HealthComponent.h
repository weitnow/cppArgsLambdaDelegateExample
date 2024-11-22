#include "Delegate.h"

#ifndef HEALTHCOMP_H
#define HEALTHCOMP_H

class HealthComponent
{
public:

    Delegate<float,float,float> onHealthChanged;

};

#endif