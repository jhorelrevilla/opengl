#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#endif
#include <iostream>
#define window_x 800
#define window_y 800
using namespace std;

double cam_x=0,cam_y=0;
/////////////////////////////////////////////////////////
void centro(){
	glRotatef( cam_x, 0.0, 0.0, 1.0 );//A-ABA
	glRotatef( cam_y, 0.0, 1.0, 0.0 );//D-I
	cam_x=0;
	cam_y=0;
}
/////////////////////////////////////////////////////////
void displayCoord(){
	glBegin(GL_LINES);
		glColor3d(255,0,0);//x
		glVertex3d(0, 0,0);
		glVertex3d(window_x, 0,0);
		glColor3d(0, 255, 0);//y
		glVertex3d(0, 0,0);
		glVertex3d(0, window_x,0);
		glColor3d(0, 0, 255);//z
		glVertex3d(0, 0,0);
		glVertex3d(0, 0,window_x);
	glEnd();
	glutSwapBuffers();
}
/////////////////////////////////////////////////////////
void Pintar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///colocar_objetos_a_dibujar
	///
	displayCoord();
	centro();	
}
/////////////////////////////////////////////////////////
void specialKeys( int key, int x, int y ) {
	if (key == GLUT_KEY_RIGHT)
		cam_y -= 3;
	else if (key == GLUT_KEY_LEFT)
		cam_y += 3;
	else if (key == GLUT_KEY_UP)
		cam_x += 3;
	else if (key == GLUT_KEY_DOWN)
		cam_x -= 3;
	glutPostRedisplay();
}
/////////////////////////////////////////////////////////
GLvoid window_redraw(GLsizei width, GLsizei height) {
	glViewport(0, 0, window_x, window_y );
	glMatrixMode(GL_PERSPECTIVE_CORRECTION_HINT);
	double over=50;
	double x=(width*-1)-over;
	double y=height+over;
	glOrtho(x,y,x,y,x-200,y+200);
}
/////////////////////////////////////////////////////////
int main (int argc, char **argv) {
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (window_x,window_y);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Plantilla");
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(&window_redraw);
	///
	glutDisplayFunc (Pintar);
	///
	glutSpecialFunc(specialKeys);
	glClearColor(0,0,0,0);
	glutMainLoop();
	return 0;
}
	
	
	
	
	
	
