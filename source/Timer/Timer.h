class Timer
{
private:
    inline static Uint32 frameStart = 0;

public:
    Timer();
    ~Timer();
    
    static void update();
    static Uint32 getGlobal();
    static Uint32 getNewTime();
};