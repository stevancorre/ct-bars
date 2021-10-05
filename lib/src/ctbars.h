#pragma once

#include <stdio.h>
#include <wchar.h>
#include <math.h>

// Struct that holds informations about the bar's rect
// Currently, only `w` is used
struct CTBar_Rect
{
    // X Position
    const unsigned short x;
    
    // Y Position
    const unsigned short y;
    
    // Width
    const unsigned char w;
    
    // Height
    const unsigned char h;
};

// Struct that holds informations about a bar
struct CTBar
{
    // Rect
    struct CTBar_Rect rect;

    // Minimum value
    const float min;

    // Maximum value
    const float max;

    // Current Value
    float value;
};

/**
 * @brief Initializes a new bar
 * 
 * @param x X Position
 * @param y Y Position
 * @param w Width
 * @param h Height
 * @param min Minimum Value
 * @param max Maximum Value
 * @return A struct that holds all of this datas, with default value = min 
 */
struct CTBar CTBar_Init(unsigned short x, unsigned short y, unsigned char w, unsigned char h, float min, float max);

/**
 * @brief Initializes a new bar
 * 
 * @param rect Destination rectangle of the bar
 * @param min Minimum Value
 * @param max Maximum Value
 * @return A struct that holds all of this datas, with default value = min 
 */
struct CTBar CTBar_InitR(struct CTBar_Rect rect, float min, float max);

/**
 * @brief Render a bar to the terminal
 * 
 * @param bar The bar to render
 * @param flush Defines if you need to call fflush on stdout after the render
 */
void CTBar_Render(struct CTBar bar, int flush);