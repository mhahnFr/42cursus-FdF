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

### Rendering

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
