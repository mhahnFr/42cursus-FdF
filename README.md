# Welcome to 42cursus-FdF!
This repository contains a project of the [42 school]. The task is to create a
graphical application that displays three dimensional wireframes.

## Approach
In order to display three dimensional wireframes, the data has to be parsed.
After parsing such maps, the text based data has to be transformed to vertices,
with whose calculations are possible. Once everything is loaded, the screen
coordinates are calculated using the vertices. For these calculations, some
matrices are calculated in advance. Changing them, the camera, the model itself
and the projection can be manipulated.

The actual displaying of the wireframe is done using a library provided by the
[42 school], the MiniLibX. In this project, the library is used to open a
window and to draw into this window. Additionally, it provides some events,
such as key events, which can be hooked.

### Parsing
A usual file contains some lines with numbers separated by spaces. The numbers
represent the ```Z```-coordinate and can be followd by a hexadecimal number,
separated by a comma. The hexadecimal number represents the colour code of that
vertex. The ```X```-coordinate is represented by the position in a line, the
```Y```-coordinate is represented by the number of the line.

Each line that is read from a given file is splitted by the whitespaces and
stored. From that list containing the splitted lines the vertices are derived
and stored in a two dimensional array.

### Rendering
Prior to starting the render loop, the matrices to multiply each vertex with
are calculated. There are matrices for the rotation, movement and scaling of
the model, a matrix to transform the model into a camera coordinate system, and
finally there is a projection matrix, which takes informations such as the
screen dimensions into the calculations. All of them are multiplied into a
combined matrix, with which each vertex is multiplied during the render loop.

The render loop iterates over each vertex, calculates a corresponding screen
coordinate and determines wether to draw a line to neighboring vertex. The line
drawing is done using a simple [Bresenham's line algorithm] implementation, in
that loop, the colours between the two intial points are interpolated.

## Usage
To use this application, start it from a shell with the file to display as
argument: ```fdf <path/to/file>```. You can also pass the width and height
of the window: ```fdf <path/to/file width height```. Using the keys described
below, the display of the wireframe can be altered.

- ```W A S D R F``` are used to scale the model in the first layer, in the
  second layer, they rotate the model.

- ```ARROW``` keys and ```NUM_1``` and ```NUM_0``` are used to move the camera
  in the first layer, in the second layer, they move the model.

- ```NUM_PLUS``` and ```NUM_MINUS``` are used to zoom the viewport in the first
  layer, in the second layer they zoom the orthogonal projection if it is used.

- ```P``` toggles between the orthogonal projection (default) and the
  perspective projection.

- ```SPACE``` toggles between the two layers.

- ```H``` displays a short help text in the window.

- ```ESC``` quits the application.

### Final notes
There is surely some room for further improvements, such as clipping invisible
coordinates. This repository however contains my solutions of the exercise, and
will not be developed any further.

© 2021 [mhahnFr](https://www.github.com/mhahnFr)

[42 school]: (https://www.42heilbronn.de/learncoderepeat)
[Bresenham's line algorithm]: (https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
