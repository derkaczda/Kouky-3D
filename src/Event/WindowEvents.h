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

    class WindowResizeEvent : public Event
    {
    public:

        WindowResizeEvent(int width, int height): m_width(width), m_height(height) {}
        ~WindowResizeEvent() {}

        static EventType GetStaticType()
        {
            return EventType::WINDOW_RESIZE;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::WINDOW_RESIZE;
        };

        inline int GetWidth() { return m_width; }
        inline int GetHeight() { return m_height; }

    private:
        int m_width, m_height;
    };

    class WindowMoveEvent : public Event
    {
    public:

        WindowMoveEvent(int xpos, int ypos) {
            m_position.x = xpos;
            m_position.y = ypos;
        }
        ~WindowMoveEvent() {}

        static EventType GetStaticType()
        {
            return EventType::WINDOW_MOVE;
        }

        virtual EventType GetEventType() const override
        {
            return EventType::WINDOW_MOVE;
        };

        inline glm::vec2 GetPosition() { return m_position; }

    private:
        glm::vec2 m_position;
    };
}

#endif