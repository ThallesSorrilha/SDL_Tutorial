#include <SDL.h>

class Timer
{
private:
    static Uint32 frameStart;
public:
    Timer();
    ~Timer();
    static void update();
    static Uint32 getGlobal();
    static Uint32 getNewTime();
};