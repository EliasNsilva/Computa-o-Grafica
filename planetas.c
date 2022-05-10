#include <GL/gl.h>
#include <GL/glut.h>

#include <math.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 750
#define x_position 10
#define y_position 10

float fovy;
float anguloPlanet = 0, anguloLua = 0;

void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'Y':
            case 'y':
                anguloLua += 10.0f;

                if(anguloLua > 360.0f)
                    anguloLua = 0.0f;

                anguloPlanet += 2.0f;

                if(anguloPlanet > 360.0f)
                    anguloPlanet = 0.0f;

    }
    glutPostRedisplay();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // sol
    glTranslatef(0.0f, 0.0f, -100.0f);
    glColor3f(255, 255, 0);//malero
    glutSolidSphere(20.0f, 15, 15);

    //planeta vermelho
    glPushMatrix();
        glRotatef(anguloPlanet, 0.0f, 1.0f, 0.0f);
        glTranslatef(90.0f, 0.0f, 0.0f);
        glColor3f(1, 0, 0);
        glutSolidSphere(6.0f, 15, 15);
    glPopMatrix();

    // planeta verde
    glRotatef(-anguloPlanet, 0.0f, 1.0f, 0.0f);
    glTranslatef(-70.0f, 0.0f, 0.0f);
    glColor3f(0, 1, 0);
    glutSolidSphere(6.0f, 15, 15);

    // lua azul
    glPushMatrix();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(anguloLua, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 25.0f, 0.0f);
        glColor3f(0, 0, 1);
        glutSolidSphere(2.8f, 15, 15);
    glPopMatrix();

    //lua 2
    glPushMatrix();
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(anguloLua, 0.0f, 1.0f, 0.0f);
        glTranslatef(-25.0f, 0.0f, 0.0f);
        glColor3f(0, 1, 1);
        glutSolidSphere(2.8f, 15, 15);
    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Sistema solar - Elias Nogueira");
    
    glutDisplayFunc(display);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    fovy = 100.0f; 
    gluPerspective(fovy, 1.0f * WINDOW_WIDTH / WINDOW_HEIGHT, 0.5f, 500.0f);
	
	glutKeyboardFunc(GerenciaTeclado);
	glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    
    return 0;
}