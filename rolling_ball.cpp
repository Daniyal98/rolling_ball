#include <iostream>
#include <GLUT/glut.h>
using namespace std;

#define PI 3.14

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 0.1; // to set the radius of the circle

void drawFilledCircle()
{
    glMatrixMode(GL_MODELVIEW);   // clears the identity matrix
    glClear(GL_COLOR_BUFFER_BIT); // clears the buffer drawing

    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0, 0.0, -5.0);

    glColor3f(0.9, 0.0, 0.9); // Red color used to draw.
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated, 1.0, 0.0, 0.0);

    glRotatef(yRotated, 0.0, 1.0, 0.0); // rotation about Y axis

    glRotatef(zRotated, 0.0, 0.0, 1.0); // rotation about Z axis

    glScalef(1.0, 1.0, 1.0); // scaling transfomation
    // NOTE: built-in (glut library) function , draw you a sphere.
    glutSolidSphere(radius, 20, 20);

    glFlush(); // This makes the drawing happen as soon as possible
}

// Program to create an empty Widdow
void init(int x, int y)
{
    if (y == 0 || x == 0)
        return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0, (GLdouble)x / (GLdouble)y, 0.6, 21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y); // Use the whole window for rendering
}

void display()
{
    drawFilledCircle();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rolling Ball");
    glutDisplayFunc(display);
    glutReshapeFunc(init);
    glutMainLoop();

    return 0;
}