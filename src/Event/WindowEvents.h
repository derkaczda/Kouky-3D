#ifndef KOUKY3D_WINDOW_EVENTS
#define KOUKY3D_WINDOW_EVENTS

#include "Event.h"

namespace Kouky3d
{
    class WindowCloseEvent : public Event
    {
    public:

        WindowCloseEvent() {}
        ~WindowCloseEvent() {}

        static EventType GetStaticType()
        {
            return EventType::WINDOW_CLOSE;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::WINDOW_CLOSE;
        };
    };
}

#endif