/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

float rotation_degree=0;
float rotation_degree2=0;
float rotation_degree3=0;


static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void drawTriangle()
{
    glBegin(GL_QUADS);
        glColor3d(1,0,0);
        glVertex3f(2,2,2);
        glVertex3f(0,2,2);
        glVertex3f(0,0,2);
        glVertex3f(2,0,2);

        glColor3d(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(2,2,0);
        glVertex3f(2,0,0);

        glColor3d(0,0,1);
        glVertex3f(2,0,2);
        glVertex3f(2,0,0);
        glVertex3f(2,2,0);
        glVertex3f(2,2,2);

        glColor3d(1,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,2);
        glVertex3f(0,2,2);
        glVertex3f(0,2,0);

        glColor3d(1,1,0);
        glVertex3f(2,2,2);
        glVertex3f(2,2,0);
        glVertex3f(0,2,0);
        glVertex3f(0,2,2);

        glColor3d(0,0,0);
        glVertex3f(0,0,0);
        glVertex3f(2,0,0);
        glVertex3f(2,0,2);
        glVertex3f(0,0,2);

    glEnd();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslated(-2,-2,-6);
        glRotated(rotation_degree,0,1,0);
        glRotated(rotation_degree2,1,0,0);
        glRotated(rotation_degree3,0,0,1);
        glScalef(.5,.5,.5);
        drawTriangle();
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'j':
            rotation_degree += 2.5;
            break;

        case 'l':
            rotation_degree -= 2.5;
            break;

        case 'i':
            rotation_degree2 += 2.5;
            break;

        case 'm':
            rotation_degree2 -= 2.5;
            break;

        case 'a':
            rotation_degree3 += 2.5;
            break;

        case 'd':
            rotation_degree3 -= 2.5;
            break;
        /*case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;*/
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/*const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
*/
/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    /*glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);*/

    glutMainLoop();

    return EXIT_SUCCESS;
}
