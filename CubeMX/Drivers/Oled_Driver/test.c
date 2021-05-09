/*
 * test.c
 *
 *  Created on: 17-Jun-2019
 *      Author: poe
 */

#include "test.h"
#include "ssd1306.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))

void TestLines(uint8_t color)
{
    uint8_t x1, y1, x2, y2;

    SSD1306_Clear ();

    x1 = y1 = 0;
    y2    = SSD1306_HEIGHT - 1;
    for (x2 = 0; x2 < SSD1306_WIDTH; x2 += 6)
    	{
    		SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
    		HAL_Delay(1);
    		SSD1306_UpdateScreen();
    	}
    x2    = SSD1306_WIDTH - 1;
    for (y2 = 0; y2 < SSD1306_HEIGHT; y2 += 6)
    	{
    		SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
    		HAL_Delay(1);
    		SSD1306_UpdateScreen();
    	}

    HAL_Delay(10);


    SSD1306_Clear ();

    x1    = SSD1306_WIDTH - 1;
    y1    = 0;
    y2    = SSD1306_HEIGHT - 1;
    for (x2 = 0; x2 < SSD1306_WIDTH; x2 += 6)
    	{
    		SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
    		SSD1306_UpdateScreen();
    		HAL_Delay(1);
    	}
    x2    = 0;
    for (y2 = 0; y2 < SSD1306_HEIGHT; y2 += 6)
    	{
    		SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
    		SSD1306_UpdateScreen();
    		HAL_Delay(1);
    	}

    HAL_Delay(10);


    SSD1306_Clear ();

    x1    = 0;
    y1    = SSD1306_HEIGHT - 1;
    y2    = 0;
    for (x2 = 0; x2 < SSD1306_WIDTH; x2 += 6)
    {
    	SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
    	HAL_Delay(1);
    	SSD1306_UpdateScreen();
    }
    x2    = SSD1306_WIDTH - 1;
    for (y2 = 0; y2 < SSD1306_HEIGHT; y2 += 6)
    	{
    		SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
				HAL_Delay(1);
    		SSD1306_UpdateScreen();
    	}

    HAL_Delay(10);


    SSD1306_Clear ();

    x1    = SSD1306_WIDTH - 1;
    y1    = SSD1306_HEIGHT - 1;
    y2    = 0;
    for (x2 = 0; x2 < SSD1306_WIDTH; x2 += 6)
    	{
    		SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
				HAL_Delay(1);
    		SSD1306_UpdateScreen();
    	}
    x2    = 0;
    for (y2 = 0; y2 < SSD1306_HEIGHT; y2 += 6)
    	{
    		SSD1306_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, (SSD1306_COLOR_t)color);
				HAL_Delay(1);
    		SSD1306_UpdateScreen();
    	}
}


void TestRectangles (uint8_t color)
{
    uint8_t n, i, i2;

    SSD1306_Clear ();

    n = min(SSD1306_WIDTH, SSD1306_HEIGHT);

    for (i = 2; i < n; i += 6)
    {
        i2 = i / 2;
        SSD1306_DrawRectangle((uint16_t)((SSD1306_WIDTH/2) - i2), (uint16_t)((SSD1306_HEIGHT/2) - i2), (uint16_t)i, (uint16_t)i, (SSD1306_COLOR_t)color);
        SSD1306_UpdateScreen();
        HAL_Delay (10);
    }
}

void TestFilledRectangles (uint8_t color)
{
    uint8_t n, i, i2,
            cx = SSD1306_WIDTH / 2 - 1,
            cy = SSD1306_HEIGHT / 2 - 1;

    SSD1306_Clear ();

    n = min(SSD1306_WIDTH, SSD1306_HEIGHT);
    for (i = n; i > 0; i -= 6)
    {
        i2    = i / 2;
        SSD1306_DrawFilledRectangle((uint16_t)(cx - i2),(uint16_t)(cy - i2), (uint16_t)i, (uint16_t)i, (SSD1306_COLOR_t)color);
        SSD1306_UpdateScreen();
        HAL_Delay (10);
    }
}

void TestFilledCircles(uint8_t radius, uint16_t color)
{
    uint8_t x, y, w = SSD1306_WIDTH, h = SSD1306_HEIGHT, r2 = radius * 2;

    SSD1306_Clear ();

    for (x = radius; x < w; x += r2)
    {
        for (y = radius; y < h; y += r2)
        {
            SSD1306_DrawFilledCircle((int16_t)x, (int16_t)y, (int16_t)radius, (SSD1306_COLOR_t)color);
            SSD1306_UpdateScreen();
            HAL_Delay (10);
        }
    }
}

void TestCircles(uint8_t radius, uint16_t color)
{
	SSD1306_Clear ();

	uint8_t x, y, r2 = radius * 2,
            w = SSD1306_WIDTH + radius,
            h = SSD1306_HEIGHT + radius;

    for (x = 0; x < w; x += r2)
    {
        for (y = 0; y < h; y += r2)
        {
            SSD1306_DrawCircle((int16_t)x, (int16_t)y, (int16_t)radius, (SSD1306_COLOR_t)color);
            SSD1306_UpdateScreen();
            HAL_Delay (10);
        }
    }
}

void TestTriangles(uint8_t color)
{
    uint8_t n, i, cx = SSD1306_WIDTH  / 2 - 1,
            cy = SSD1306_HEIGHT / 2 - 1;

    SSD1306_Clear ();

    n = min(cx, cy);
    for (i = 0; i < n; i += 5)
    {
        SSD1306_DrawTriangle((uint16_t)(cx) , (uint16_t)(cy - i), (uint16_t)(cx - i), (uint16_t)(cy + i), (uint16_t)(cx + i), (uint16_t)(cy + i), (SSD1306_COLOR_t)color);
        SSD1306_UpdateScreen();
        HAL_Delay (10);
    }

}




