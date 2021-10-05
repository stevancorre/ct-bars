#include "ctbar.h"

const char *CTBAR_MAP_V[101] = {
    [0] = " ",
    [12] = "\u258F",
    [25] = "\u258E",
    [37] = "\u258D",
    [50] = "\u258C",
    [62] = "\u258B",
    [75] = "\u258A",
    [87] = "\u2589",
    [100] = "\u2588"};

float clamp01(float v)
{
    return v < 0 ? 0 : v > 1 ? 1
                             : v;
}

int plot(float v)
{
    const float stepSize = 1 / 8.0f;
    return (int)(ceilf(v / stepSize) * stepSize * 100 * -1);
}

const char *getLastFill(float v)
{
    int pi = plot(v);
    return (const char *)CTBAR_MAP_V[pi];
}

/*
-- HORIZONTAL
      0.0%  0160  0
     12.5%  258F  1
     25.0%  258E  2
     37.5%  258D  3
     50.0%  258C  4
     62.5%  258B  5
     75.0%  258A  6
     87.5%  2589  7
    100.0%  2588  8

-- VERTICAL

      0.0%  0160
     12.5%  258F
     25.0%  258E
     37.5%  258D
     50.0%  258C
     62.5%  258B
     75.0%  258A
     87.5%  2589
    100.0%  2588

 */

struct CTBar CTBar_InitR(struct CTBar_Rect rect, float min, float max)
{
    struct CTBar bar = {
        .rect = rect,
        .min = min,
        .max = max,
        .value = 0};

    return bar;
}

struct CTBar CTBar_Init(unsigned short x, unsigned short y, unsigned char w, unsigned char h, float min, float max)
{
    // TODO: check if min > max, min = max, max < 0 etc
    struct CTBar_Rect rect = {
        .x = x,
        .y = y,
        .w = w,
        .h = h};

    return CTBar_InitR(rect, min, max);
}

void CTBar_Render(struct CTBar bar, int flush)
{
    float percentage = clamp01((bar.value - bar.min) / (bar.max - bar.min));
    float fill = bar.rect.w * percentage;

    int fill_count = (int)fill;
    float remainder = fill_count - fill;

    const char *lastFill = getLastFill(remainder);

    printf("\r");
    for (int i = 0; i < fill_count; i++)
    {
        printf("%s", CTBAR_MAP_V[100]);
    }

    printf("%s", lastFill);

    for (int i = 0; i < bar.rect.w - fill_count; i++)
    {
        printf("%s", CTBAR_MAP_V[0]);
    }

    printf("%.f%%  ", percentage * 100);

    if(flush) {
        fflush(stdout);
    }
}
