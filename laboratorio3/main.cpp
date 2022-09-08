#include <stdlib.h>
#include<windows.h>
#include <gl/glut.h>

void display();
void Menu (int value);
void Figuras (int value);
void cruz();
void display()
{
    glClearColor(0.2,0.2,0.2,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,40,-40,40);
    glFlush();
}

int main (int argc, char ** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,250);
    glutInitWindowSize(500,600);
    glutCreateWindow("Menu");

    int sub1=glutCreateMenu (Menu);

    glutAddMenuEntry("Rojo", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Verde", 3);
    glutAddMenuEntry("Amarillo", 4);
     glutAddMenuEntry("Purpura", 5);

    int sub2=glutCreateMenu (Figuras);

    glutAddMenuEntry("Cometa", 1);
    glutAddMenuEntry("Trebol de tres hojas", 2);
    glutAddMenuEntry("Estrella", 3);
    glutAddMenuEntry("Hexagono", 4);
     glutAddMenuEntry("Luna creciente", 5);
    glutAddMenuEntry("Cruz", 6);
    glutAddMenuEntry("Corazon", 7);
    glutAddMenuEntry("Trebol de cuatro hojas", 8);

    glutCreateMenu (Menu);

    glutAddSubMenu("Colores", sub1);
    glutAddSubMenu ("Figuras", sub2);
    glutAddMenuEntry("Salida", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();

}

void Menu(int value)
{
    switch(value)
    {
    case 1:
        glColor3f(1.0,0.0,0.0);
        break;
    case 2:
        glColor3f(0.0,0.0,1.0);
        break;
            case 3:
        glColor3f(0.0,1.0,0.0);
        break;
         case 4:
        glColor3f(1.0,1.0,0.0);
        break;
        case 5:
        glColor3f(1.0,0.0,1.0);
        break;
            case 6:
        exit (0);
        break;
    }
    glutPostRedisplay();
}

void Figuras (int value)
{
    switch(value)
    {
    case 1:
        glColor3f(1.0,0.0,0.0);
        break;
    case 2:
        glColor3f(0.0,0.0,1.0);
        break;
    case 3:
        glColor3f(0.0,1.0,0.0);
        break;
         case 4:
        glColor3f(1.0,1.0,0.0);
        break;
    case 5:
        glColor3f(1.0,0.0,1.0);
        break;
    case 6:
        cruz();
        break;
    case 7:
        break;
    case 8:
        break;

    }
    glutPostRedisplay();
}

void cruz()
{
    glColor3f(1.0,0.0,0.0);
    glRecti(-2,8,2,-8);
    glRecti(-8,2,8,-2);
    glEnd();
}
