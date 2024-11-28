#include <functional>
#include <vector>

#ifndef DELEGATE_H
#define DELEGATE_H

class Object; //forward decleration

template<typename... Args>
class Delegate
{
public:
    template<typename ClassName>
    void BindAction(std::weak_ptr<Object> obj, void(ClassName::*callback)(Args...))
    {
        // capturing done by value, because obj and callback are pointers and there is no need to capture by reference
        auto callbackFunc = [obj, callback](Args... args)->bool
        {

            if(!obj.expired())
            {
                // obj is an pointer to a Instance of Object but we want the actually Class
                (static_cast<ClassName*>(obj.lock().get())->*callback)(args...);
                //because obj ist not expired
                return true;
            }
            //because obj is expired
            return false;
        };

         mCallbacks.push_back(callbackFunc);
        // if we would have capture by reference instead of value (which makes a copy) the reference would be destroyed here because the } which is the end of the scope

    }

    void Broadcast(Args... args)
        {
            for(auto iter = mCallbacks.begin(); iter != mCallbacks.end();)
            {
                // deference iterator gives us the callbackfunction which will be called with (args...)
                if((*iter)(args...))
                {
                    ++iter;
                }
                else
                {
                    //if (*iter)(args...) return false, it means the weak ptr is expired
                    iter = mCallbacks.erase(iter);
                }
            }
        };
    
private:
    std::vector<std::function<bool(Args...)>> mCallbacks;
};

#endif