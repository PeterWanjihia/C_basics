/*
* Draw a ball that moves around the screen
*/
#include <graphics.h>
#define TRUE 1
int
main(void)
{
const int
const int
const int
const int
int
int
int
int
int
PAUSE = 20;
DELTA = 5;
RADIUS = 30;
COLOR = RED;
width;
height;
x; int y;
stepX;
stepY;
/* delay between frames */
/* change in x or y value */
/* ball radius */
/*
/*
/*
/*
/*
width of screen */
height of screen */
center of ball */
increment for x */
increment for y */

/* Open a full-screen window with double buffering */
width = getmaxwidth();
height = getmaxheight();
initwindow(width, height,
“Pong - close window to quit”, 0, 0, TRUE);
x = RADIUS; y = RADIUS;
/* Start ball at top-left corner */
stepX = DELTA; stepY = DELTA; /* Move down and to the right */
/* Draw the moving ball */
while (TRUE)
/* Repeat forever */
{
/* Clear the old frame and draw the new one. */
clearviewport();
setfillstyle(SOLID_FILL, COLOR);
fillellipse(x, y, RADIUS, RADIUS); /* Draw the ball */
/* After drawing the frame, swap the buffers */
swapbuffers();
delay(PAUSE);
/* If ball is too close to window
if (x <= RADIUS)
/*
stepX = DELTA;
/*
else if (x >= width - RADIUS) /*
stepX = -DELTA;
/* edge, change direction
Is ball to close to left edge?
Move right
Is ball to close to right edge?
Move left */
*/
*/
*/
*/
if (y <= RADIUS)
/*
stepY = DELTA;
/*
else if (y >= height - RADIUS) /*
stepY = -DELTA;
/* Is ball to close to top?
Move down
Is ball to close to bottom?
Move up */
*/
*/
*/
/* Move the ball */
x = x + stepX;
y = y + stepY;
}
closegraph();
return (0);
}