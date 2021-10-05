#include "ctbar.h"

// Temporary char map for the bar
// TODO: use a better method to actually store the characters
// TODO: make an option out of this
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

/**
 * @brief Clamp a value between 0 and 1
 * 
 * @param v The target the value
 * @return Value, clamped between 0 and 1
 */
float clamp01(float v)
{
    return v < 0 ? 0 : v > 1 ? 1
                             : v;
}

/**
 * TODO: implement custom step size
 *
 * @brief Get the last character of the bar
 * 
 * @param v Remainder value
 * @return The last character (unicode) that the bar needs to display
 */
const char *getLastFill(float v)
{
    // Step v
    const float stepSize = 1 / 8.0f;
    int i = (int)(ceilf(v / stepSize) * stepSize * 100 * -1);

    // Return corresponding character in the map
    return (const char *)CTBAR_MAP_V[i];
}

struct CTBar CTBar_InitR(struct CTBar_Rect rect, float min, float max)
{
    struct CTBar bar = {
        .rect = rect,
        .min = min,
        .max = max,
        .value = min};

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
    // Calculate the percentage of the bar
    float percentage = clamp01((bar.value - bar.min) / (bar.max - bar.min));
    float fill = bar.rect.w * percentage;

    // Calculate the count of characters we need to display, and the remainer
    // Then, get the last character of the bar
    int fillCount = (int)fill;
    float remainder = fillCount - fill;

    const char *lastFill = getLastFill(remainder);

    // Rewrite on existing bar
    printf("\r");

    // TODO: avoid using loops

    // Write fill
    for (int i = 0; i < fillCount; i++)
    {
        printf("%s", CTBAR_MAP_V[100]);
    }
    printf("%s", lastFill);

    // Write empty
    for (int i = 0; i < bar.rect.w - fillCount; i++)
    {
        printf("%s", CTBAR_MAP_V[0]);
    }

    // Display the percentage
    // TODO: make an option ouf of this
    printf("%.f%%  ", percentage * 100);

    // Flush the stdout if we need to
    // This has to be used if we use like sleep functions
    // TODO: make so the user can decide what output stream he wants
    if (flush)
    {
        fflush(stdout);
    }
}
