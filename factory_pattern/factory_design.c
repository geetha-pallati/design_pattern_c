#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Shape {
    void (*draw) ();
} Shape;

void draw_circle() {
    printf("Drawing a Circle\n");
}
void draw_square() {
    printf("Drawing a Square\n");
}
Shape* create_shape(const char* shape_type) {
    Shape* shape = (Shape*)malloc(sizeof(Shape));
    if (strcmp(shape_type, "circle") == 0) {
        shape->draw = draw_circle;
    } else if (strcmp(shape_type, "square") == 0) {
        shape->draw = draw_square;
    } else {
        free(shape);
        return NULL;
    }
    return shape;
}
int main() {
    Shape* circle = create_shape("circle");
    Shape* square = create_shape("square");

    if (circle) {
        circle->draw();
        free(circle);
    }
    if (square) {
        square->draw();
        free(square);
    }

    return 0;
}
