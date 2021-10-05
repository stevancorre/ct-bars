#pragma once

#include <stdio.h>
#include <wchar.h>
#include <math.h>

struct CTBar_Rect
{
    const unsigned short x;
    const unsigned short y;
    const unsigned char w;
    const unsigned char h;
};

struct CTBar
{
    struct CTBar_Rect rect;

    const float min;
    const float max;

    float value;
};

struct CTBar CTBar_Init(unsigned short x, unsigned short y, unsigned char w, unsigned char h, float min, float max);
struct CTBar CTBar_InitR(struct CTBar_Rect rect, float min, float max);

void CTBar_Render(struct CTBar bar, int flush);