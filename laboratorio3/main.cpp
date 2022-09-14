#include <stdlib.h>
#include<windows.h>
#include <gl/glut.h>

void display();
void Menu (int value);

void display()
{   glClearColor(0,0,0,0);
    gluOrtho2D(-20,20,-20,20);
    glFlush();
}

void flecha(){
    glClear(GL_COLOR_BUFFER_BIT); //limpia la ventana
    glRecti(-6,2,2,-1);
    glBegin(GL_TRIANGLES);
        glVertex2i(2,4);
        glVertex2f(6,0.5);
        glVertex2i(2,-3);
    glEnd();
    glFlush();
}

void paralelogramo(){
    glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_QUADS);
    glVertex2f(-3,-2);glVertex2f(-1.8,5);
    glVertex2f(3,5);glVertex2f(1.8,-2);
    glEnd();
    glFlush();
}

void trapecio(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        glVertex2f(-4,-3);glVertex2f(-2.4,6);
        glVertex2f(1.4,6);glVertex2f(3,-3);
    glEnd();
    glFlush();
}

void cruz(){
    glClear(GL_COLOR_BUFFER_BIT); //limpia la ventana
    glRecti(-6,2,6,-2);
    glRecti(-2,6,2,-6);
    glFlush();
}

void hexagono(){
    glClear(GL_COLOR_BUFFER_BIT); //limpia la ventana
    glRecti(-6,3,6,-3);
    glBegin(GL_TRIANGLES);
        glVertex2i(-6,3);
        glVertex2i(0,6);
        glVertex2i(6,3);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(-6,-3);
        glVertex2i(0,-6);
        glVertex2i(6,-3);
    glEnd();
    glFlush();
}


int main (int argc, char ** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);

    int x = abs((GetSystemMetrics(SM_CXSCREEN)-600)/2);
    int y = abs((GetSystemMetrics(SM_CYSCREEN)-600)/2);

    glutInitWindowPosition(x,y);

    glutCreateWindow("Menu");

    int sub1=glutCreateMenu (Menu);
        glutAddMenuEntry("Flecha", 11);
        glutAddMenuEntry("Paralelogramo", 12);
        glutAddMenuEntry("Trapecio", 13);
        glutAddMenuEntry("Cruz", 14);
        glutAddMenuEntry("Hexagono", 15);

    int sub2=glutCreateMenu (Menu);
        glutAddMenuEntry("Rojo", 21);
        glutAddMenuEntry("Azul", 22);
        glutAddMenuEntry("Verde", 23);
        glutAddMenuEntry("Amarillo", 24);
        glutAddMenuEntry("Purpura", 25);

        glutCreateMenu (Menu);
        glutAddSubMenu("Figuras", sub1);
        glutAddSubMenu("Colores", sub2);
        glutAddMenuEntry("Salida", 26);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutDisplayFunc(display);
        glutMainLoop();
}

void Menu(int value)
{
    switch(value)
    {
    case 11:
        glutDisplayFunc(flecha);
        break;
    case 12:
        glutDisplayFunc(paralelogramo);
        break;
    case 13:
        glutDisplayFunc(trapecio);
        break;
    case 14:
        glutDisplayFunc(cruz);
        break;
    case 15:
        glutDisplayFunc(hexagono);
        break;


    case 21:
        glColor3f(1.0,0.0,0.0);
        break;
    case 22:
        glColor3f(0.0,0.0,1.0);
        break;
    case 23:
        glColor3f(0.0,1.0,0.0);
        break;
    case 24:
        glColor3f(1.0,1.0,0.0);
        break;
    case 25:
        glColor3f(1.0,0.0,1.0);
        break;
    case 26:
        exit(0);
    }
    glutPostRedisplay();
}
