#include <GL/glut.h>

float _angle = 0.0;
float _move = 0.0;


void Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
							/////////////ROAD//////////////////////
							glColor3f(0.09,0.09,0.09 );
									glTranslatef(0.0,0.0,-2.0);
							glBegin(GL_QUADS);
								glVertex3f(-3.75, -5.0, 0.0); //negative y for alligning with the car
								glVertex3f(-0.5, 1.0, 0.0);
								glVertex3f(0.5,1.0, 0.0);
								glVertex3f(3.75, -5.0, 0.0);//negative y for alligning with the car
							glEnd();

							/////////////LINES ON ROAD///////////////////
							glColor3f(1, 1, 1);
								glTranslatef(0.0,0.0,-5.0);
							glBegin(GL_QUADS);
							    glVertex3f(-1.0-_move, -1.0-_move, 0.0);
								glVertex3f(-0.1-_move, 0.0-_move, 0.0);
								glVertex3f(0.1+_move,0.0-_move, 0.0);
								glVertex3f(1.0+_move, -1.0-_move, 0.0);
							glEnd();

							///////////TIRES////////////////////
							float z;
	                        glColor3f(0.8, 0, 0);//Color to all tires

							////////////////LEFT LOWER TIRE////////////////
							glPushMatrix();
									z = 0.0;
									glTranslatef(-4.0,-3.0,-1.0);
										glPushMatrix();
											glRotatef(90, 0.0, 1.0, 0.0);
							  				glRotatef(_angle, 0.0, 0.0, 1.0);
												glPushMatrix();
													glutSolidTorus(0.4, 1.5, 5, 10); // inner radius, outer radius, sides, segments
												glPopMatrix();
										glPopMatrix();
							glPopMatrix();

							///////////////LEFT UPPER TIRE////////////////////
							glPushMatrix();
							        z = 0.0;
									glTranslatef(4.0,-3.0,-1.0);
										glPushMatrix();
											glRotatef(95, 0.0, 1.0, 0.0);
											glRotatef(_angle, 0.0, 0.0, 1.0);
												glPushMatrix();
													glutSolidTorus(0.4, 1.5, 5, 10); // inner radius, outer radius, sides, segments
												glPopMatrix();
										glPopMatrix();
							glPopMatrix();

							/////////////////RIGHT LOWER TIRE////////////////
							glPushMatrix();
							     	z = 0.0;
								    glTranslatef(-32,-3.0,-90.0);
										glPushMatrix();
											glRotatef(90, 0.0, 1.0, 0.0);
										    glRotatef(_angle, 0.0, 0.0, 1.0);
												glPushMatrix();
												    glutSolidTorus(1.9, 10, 5, 10); // inner radius, outer radius, sides, segments
												glPopMatrix();
										glPopMatrix();
							glPopMatrix();

							/////////////RIGHT UPPER TIRE////////////////////
							glPushMatrix();
									z = 0.0;
									glTranslatef(32,-3,-90.0);
	    								glPushMatrix();
										     glRotatef(95, 0.0, 1.0, 0.0);
		       								 glRotatef(_angle, 0.0, 0.0, 1.0);
												glPushMatrix();
												    glutSolidTorus(1.9, 10, 5, 10); // inner radius, outer radius, sides, segments
												glPopMatrix();
										glPopMatrix();
							glPopMatrix();

							///////////////BODY//////////////////

							//BODY MIDDLE ORANGE QUAD
							glColor3f(1, 0.3, 0);
							glTranslatef(0.0,0.0,-2.0);
							glBegin(GL_QUADS);
								glVertex3f(-5.1, -3.7, 0.0);
								glVertex3f(-2.8, .4, 0.0);
								glVertex3f(2.8,.4, 0.0);
								glVertex3f(5.1, -3.7, 0.0);
							glEnd();

							//BODY BLUE QUAD
							glColor3f(0.0, 0.0, 0.45);
							glTranslatef(0.0,0.0,-2.0);
							glBegin(GL_QUADS);
								glVertex3f(-2.8, .8, 0.0);
								glVertex3f(2.8,.8, 0.0);
								glVertex3f(3.5, -1.8, 2.0);
								glVertex3f(-3.5,-1.8, 2.0);
							glEnd();

							//BODY LOWER Magenta QUAD FOR SUPPORTING LIGHT
							glTranslatef(0.0,0.0,0.0);
							glColor3f(0.3, 0, 1);
							glTranslatef(0.0,0.0,-2.0);
							glBegin(GL_QUADS);
								glVertex3f(-5.1, -3.7, 0.0);
								glVertex3f(-5.8, -6, 0.0);
								glVertex3f(5.8,-6, 0.0);
								glVertex3f(5.1, -3.7, 0.0);

							//LIGHTS
							//L.Light
							glPushMatrix();
							glColor3f(0, 1, 1);
							glBegin(GL_QUADS);
							    glVertex3f(-2, 1.7, 0.0);//upper
								glVertex3f(-3, 1.7, 0.0);
								glVertex3f(-3,1, 0.0);//lower
								glVertex3f(-2,1, 0.0);
							  glEnd();
							glPopMatrix();

							//positioned light
							//GL_LIGHT0
							GLfloat lightColor0[] = {0, 1,0, 0.0f};
							GLfloat lightPos0[] = {0, 0, -1, 1.0f};
							glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
							glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

							//L.HeadLight
							glPushMatrix();
							glColor3f(1, 1, 1);
							glBegin(GL_QUADS);
					 		//////LIGTING ON HEADLIGHT USING NORMALS
										glNormal3f(-1.0f, 0.0f, -1.0f);//n1
									glVertex3f(-1.2, 10,0.0);//upper
									    glNormal3f(-1.0f, 0.0f, -1.0f);//n2
									glVertex3f(-3.2, 10, 0.0);
									    glNormal3f(1.0f, 0.0f, 1.0f);//n3
									glVertex3f(-3,1.7, 0.0);//lower
									    glNormal3f(1.0f, 0.0f, 1.0f);//n4
									glVertex3f(-2,1.7, 0.0);

							glEnd();
							glPopMatrix();

							//R.Light
							glPushMatrix();
							glColor3f(0, 1, 1);
							glBegin(GL_QUADS);
								glVertex3f(3, 1.7, 0.0);//upper
								glVertex3f(2, 1.7, 0.0);
								glVertex3f(2, 1, 0.0);//lower
								glVertex3f(3, 1, 0.0);
							glEnd();
							glPopMatrix();

							//positioned light
							//GL_LIGHT1
							GLfloat lightColor1[] = {1, 0,0, 0.0f};
							GLfloat lightPos1[] = {-1, 0, 0, 1.0f};
							glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
							glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

							////R.HeadLight
							glPushMatrix();
							glColor3f(1, 1, 1);
							glBegin(GL_QUADS);
							//////LIGTING ON HEADLIGHT USING NORMALS
									 glNormal3f(1.0f, 0.0f, -1.0f);//n1
								glVertex3f(3.2, 10, 0.0);//upper
									 glNormal3f(1.0f, 0.0f, -1.0f);//n3
								glVertex3f(1.2, 10, 0.0);
							 		 glNormal3f(-1.0f, 0.0f, 1.0f);//n2
								glVertex3f(2,1.7, 0.0);//lower
							 		 glNormal3f(-1.0f, 0.0f, 1.0f);//n4........for not passing the light to the line on road
								glVertex3f(3,1.7, 0.0);

							glEnd();
							glPopMatrix();
		glFlush();
		glutSwapBuffers();
	}

void init()
	{
		glClearColor(0, 0, 0,1.0);
		glMatrixMode(GL_PROJECTION);
		gluPerspective(95, 1.2, 0, 300.0);
		glEnable(GL_COLOR_MATERIAL); //for colorful 3d drawing,not black-white
		glEnable(GL_LIGHTING); //Enable lighting
	    glEnable(GL_LIGHT0); //Enable light #0
		glEnable(GL_LIGHT1); //Enable light #1x
	    glEnable(GL_NORMALIZE); //Automatically normalize normals
		glShadeModel(GL_SMOOTH); //Enable smooth shading
	}

void update(int value)
	{
		_angle -= 0.8;
		_move+=0.02;
		if (_angle > 360)
			{
			_angle = 0.0;
			}
		if (_move > 10.0)
			{
			_move= 0.0;
			}
		glutPostRedisplay();
		glutTimerFunc(4,update,0);
	}

int main(int iArgc, char** cppArgv)
	{
		glutInit(&iArgc, cppArgv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
		glutInitWindowSize(500, 350);
		glutInitWindowPosition(400, 400);
		glutCreateWindow("CAR WITH HEADLIGHTS");
		init();
		glutDisplayFunc(Draw);
		update(2);
		glutMainLoop();
		return 0;
	}
