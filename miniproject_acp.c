#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'

char picture[HEIGHT][WIDTH];

/* Clear canvas */
void clearPicture() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            picture[y][x] = EMPTY;
        }
    }
}

/* Display canvas */
void displayPicture() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%c", picture[y][x]);
        }
        printf("\n");
    }
}

/* Draw a single pixel */
void setPixel(int x, int y) {
    if(x >= 0 && x < WIDTH &&
       y >= 0 && y < HEIGHT) {
        picture[y][x] = PIXEL;
    }
}

/* Bresenham Line Algorithm */
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while(1) {
        setPixel(x1, y1);

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

/* Rectangle */
void drawRectangle(int x1, int y1, int x2, int y2) {

    drawLine(x1, y1, x2, y1);
    drawLine(x2, y1, x2, y2);
    drawLine(x2, y2, x1, y2);
    drawLine(x1, y2, x1, y1);
}

/* Circle */
void drawCircle(int cx, int cy, int radius) {

    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {

            int dx = x - cx;
            int dy = y - cy;

            int dist = dx * dx + dy * dy;

            if(abs(dist - radius * radius) <= radius) {
                setPixel(x, y);
            }
        }
    }
}

/* Triangle */
void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3) {

    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

int main() {

    int choice;

    clearPicture();

    printf("=================================\n");
    printf("      2D GRAPHICS EDITOR\n");
    printf("=================================\n");

    printf("Canvas Size : %d x %d\n", WIDTH, HEIGHT);

    while(1) {

        printf("\nMenu\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Circle\n");
        printf("4. Draw Triangle\n");
        printf("5. Display Picture\n");
        printf("6. Clear Picture\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            int x1, y1, x2, y2;

            printf("Enter x1 y1 x2 y2: ");
            scanf("%d %d %d %d",
                  &x1, &y1, &x2, &y2);

            drawLine(x1, y1, x2, y2);
            printf("Line Drawn Successfully!\n");
        } 
        else if(choice == 2)
          {
                    int x1, y1, x2, y2;

        scanf("%d %d %d %d",
              &x1, &y1, &x2, &y2);

        drawRectangle(x1, y1, x2, y2);
    printf("Rectangle Drawn Successfully!\n");
        }

        else if(choice == 3) {

            int cx, cy, radius;

            printf("Enter center x y and radius: ");
            scanf("%d %d %d",
                  &cx, &cy, &radius);

            drawCircle(cx, cy, radius);
            printf("Circle Drawn Successfully!\n");
        }

        else if(choice == 4) {

            int x1, y1, x2, y2, x3, y3;

            printf("Enter x1 y1 x2 y2 x3 y3: ");

            scanf("%d %d %d %d %d %d",
                  &x1, &y1,
                  &x2, &y2,
                  &x3, &y3);

            drawTriangle(x1, y1, x2, y2, x3, y3);
            printf("Triangle Drawn Successfully!\n");
        }

        else if(choice == 5) {

            printf("\nCurrent Picture:\n\n");
            displayPicture();
        }

        else if(choice == 6) {

            clearPicture();
            printf("Canvas Cleared Successfully!\n");
        }

        else if(choice == 0) {

            printf("Exiting Program...\n");
            break;
        }

        else {

            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
