#pragma once

class Timer
{
private:
    inline static Uint32 frameStart = 0;

    Uint32 beginEvent;
    Uint32 endEvent;

public:
    static void init();
    static void update();
    static Uint32 getGlobal();
    static Uint32 getNewTime();

    Timer();
    ~Timer();
    // waitToBegin - time to begin event
    // waitToEnd - time of event
    void scheduleEvent(Uint32 waitToBegin, Uint32 waitToEnd);
    bool isEventPresent();
};