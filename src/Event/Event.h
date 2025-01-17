#ifndef KOUKY3D_EVENT
#define KOUKY3D_EVENT

namespace Kouky3d
{
    enum EventType
    {
        None = 0,
        WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_MOVE,
        INPUT, KEY_DOWN, KEY_UP
    };

    class Event
    {
    public:
        virtual EventType GetEventType() const = 0;

        inline bool IsHandled() { return m_handled; }
        inline void SetHandled(bool value) { m_handled = value; }

    protected:
        bool m_handled = false;
    };
}

#endif