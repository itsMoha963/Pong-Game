#ifndef _CPUPADDLE_H
#define _CPUPADDLE_H
#include <raylib.h>
#include "Paddle.h"
class CPUPaddle : public Paddle {
public:
    CPUPaddle(float xPos , float yPos);

    void Update(int ball_y);
};
#endif