#ifndef _EVENT_HPP
#define _EVENT_HPP

//When adding a new event class, add name to the enum
enum EventType{
    TEST_EVENT,
};

class Event {
    public:
        EventType id;
    private:
};

class TestEvent: public Event {
    public:
        TestEvent(){id=TEST_EVENT;};
    private:
};

#endif
