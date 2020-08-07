#ifndef KOUKY3D_EVENT_DISPATCHER
#define KOUKY3D_EVENT_DISPATCHER

#include <functional>
#include "Event.h"

namespace Kouky3d
{
    class EventDispatcher
    {
        template<typename T> using EventFunction = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& event) : m_event(event) {}
        ~EventDispatcher() {}

        template<typename T> bool Dispatch(EventFunction<T> f)
        {
            if(m_event.GetEventType() == T::GetStaticType())
            {
                m_event.SetHandled( f(*(T*)&m_event) );
                return true;
            }
            return false;
        }
        
    private:
        Event& m_event;
    };
}

#endif