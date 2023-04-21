#include <iostream>
#include <GLUT/glut.h>
using namespace std;

// Program to create an empty Widdow
void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(1000, 200);
    glutCreateWindow("Rolling Ball");
}

void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // gluOrtho2D(0.0,100.0,0,100.0);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Line A
    init();                // Line B
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}