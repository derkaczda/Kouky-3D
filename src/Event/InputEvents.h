#ifndef KOUKY3D_INPUT_EVENT
#define KOUKY3D_INPUT_EVENT

#include "Event.h"

namespace Kouky3d
{
    class InputEvent : public Event
    {
    protected:
        InputEvent(int keycode) : m_keycode(keycode) {}
        ~InputEvent() {}

    public:

        static EventType GetStaticType()
        {
            return EventType::INPUT;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::INPUT;
        };

        inline int GetKeycode() { return m_keycode; }
    private:
        int m_keycode;
    };

    class KeyDownEvent : public InputEvent
    {
    public:
        KeyDownEvent(int keycode) : InputEvent(keycode) {}
        ~KeyDownEvent() {}

        static EventType GetStaticType()
        {
            return EventType::KEY_DOWN;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::KEY_DOWN;
        };
    };

    class KeyUpEvent : public InputEvent
    {
    public:
        KeyUpEvent(int keycode) : InputEvent(keycode) {}
        ~KeyUpEvent() {}

        static EventType GetStaticType()
        {
            return EventType::KEY_UP;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::KEY_UP;
        };
    };

};

#endif