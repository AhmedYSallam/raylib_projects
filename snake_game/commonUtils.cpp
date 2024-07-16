#include "commonUtils.h"


Color background = {255, 211, 90, 255};
Color dark_green = {43, 150, 24, 255};

Rectangle rectangle = {(float)offset-5, (float)offset-5, (float)cell_size*num_cells+10, (float)cell_size*num_cells+10};

int cell_size = 30;
int num_cells = 25;
int offset = 75;
int window_size = 2*offset + cell_size*num_cells;
double lastUpdateTime = 0;
double interval = 0.2; // default is seconds
//std::chrono::duration<double, std::milli> duration_ms(200); //lets try with milli in this way


position addPosition(position pos1, position pos2)
{
    position tmp;
    tmp.x = pos1.x + pos2.x;
    tmp.y = pos1.y + pos2.y;
    return tmp;
}

/*different ways to call evenTriggered

bool result = eventTriggered(std::chrono::seconds(0.2))
std::chrono::seconds sec(0.2);
bool result = eventTriggered(0.2s)

*/
bool eventTriggered(double sec)
{
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTimePoint = std::chrono::high_resolution_clock::now();
    auto durationSinceEpoch = currentTimePoint.time_since_epoch();
    double currentTime = std::chrono::duration_cast<std::chrono::duration<double>>(durationSinceEpoch).count();
    double elapsedTime = currentTime - lastUpdateTime;
    if(elapsedTime>=sec)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool isPositionEqual(position pos1, position pos2)
{
    if(pos1.x == pos2.x && pos1.y == pos2.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isDequeinPos(std::deque<position> deq, position pos)
{
    for(int i=0; i<deq.size(); i++)
    {
        if(isPositionEqual(deq[i], pos))
        {
            return true;
        }
    }
    return false;
}