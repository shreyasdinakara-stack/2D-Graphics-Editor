# 2D-Graphics-Editor
# 2D Graphics Editor in C

## Project Description

This project is a simple 2D Graphics Editor developed using the C programming language. The editor uses a two-dimensional character array to represent a drawing canvas. Different geometric shapes can be drawn on the canvas using the '*' character, while empty spaces are represented using the '_' character.

The project demonstrates the use of arrays, functions, loops, structures, and basic computer graphics concepts.

## Features

* Draw Line
* Draw Rectangle
* Draw Circle
* Draw Triangle
* Display the Picture
* Clear the Picture
* Menu Driven Interface

## Technologies Used

* C Programming Language
* Visual Studio Code
* GitHub

## Canvas Details

* Width: 80 characters
* Height: 24 characters
* Drawing Character: '*'
* Empty Character: '_'

## Functions Implemented

### clearPicture()

Clears the entire canvas by filling it with the empty character.

### displayPicture()

Displays the current canvas on the screen.

### setPixel()

Sets a single pixel at a specified coordinate.

### drawLine()

Draws a line between two points.

### drawRectangle()

Draws a rectangle using four lines.

### drawCircle()

Draws a circle using the circle equation.

### drawTriangle()

Draws a triangle by connecting three vertices.

## How to Compile

```bash
gcc graphics_editor.c -o graphics_editor
```

## How to Run

```bash
./graphics_editor
```

## Sample Menu

1. Draw Line
2. Draw Rectangle
3. Draw Circle
4. Draw Triangle
5. Display Picture
6. Clear Picture
7. Exit

## Learning Outcomes

* Understanding 2D arrays
* Function modularization
* Coordinate-based drawing
* Basic graphics algorithms
* GitHub version control

## Author

Shreyas H D

## License

This project is developed for educational purposes as part of a mini project assignment.
