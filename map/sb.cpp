#include <windows.h>
#include <stdlib.h>
#include <gl\glut.h>
#include <gl\GLAUX.H>
#include <stdio.h>
#include <math.h>

#pragma comment (lib, "glaux.lib")
#pragma comment (lib,"legacy_stdio_definitions.lib")
#define NULL 0


GLuint textureID[6] = { -1, -1,-1,-1,-1,-1 }; // 텍스처 배열 선언

struct Vertex { //텍스처 매핑을 위한 구조체 정의
	float tu, tv;
	float x, y, z;
};



static GLfloat Look_x = -0.01f, Look_y = 0.0f, Look_z = 0.01f, Angle_x = 2.0f, Angle_y = 3.0f; //위치이동을 위한변수
static GLfloat Center_x = 0.0f, Center_y = 0.0f; //시점이동을 위한 변수


float mouse_sx; //마우스 시작X좌표
float mouse_sy; //마우스 시작 Y좌표
float mouse_ex; //마우스 드래그 끝 x좌표
float mouse_ey; // 마우스 드래그 끝 y좌표


Vertex backgroundVertices[]= { //배경
	{ -7.0f,-2.5f, -7.0f, -3.0f, -2.0f },
	{ -7.0f,-6.0f,  7.0f, -3.0f, -2.0f },
	{ -4.0f,-6.0f,  7.0f, 6.0f,	-2.0f },
	{ -4.0f,-2.5f, -7.0f, 6.0f,-2.0f }
};




void MyMouseMove(GLint X, GLint Y) {
	mouse_ex = X; //마우스이동 후 좌표
	mouse_ey = Y; //마우스 이동 후 좌표
	Center_x += (mouse_sx - mouse_ex) / 15; //시점 이동이 너무 빠르지 않게하기위해
	Center_y += -(mouse_sy - mouse_ey) / 15;
	glutPostRedisplay();
}

void MyMouseClick(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		mouse_sx = x;
		mouse_sy = y;
	}
}


void loadTexture(void) { //텍스처 로드 함수
	AUX_RGBImageRec *pTextureImage = auxDIBImageLoad("C:\\Users\\아영\\source\\repos\\Project1\\Project1\\w.bmp");
	if (pTextureImage != NULL) {
		glGenTextures(1, &textureID[0]);

		glBindTexture(GL_TEXTURE_2D, textureID[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);

	}

	if (pTextureImage) {
		if (pTextureImage->data)
			free(pTextureImage->data);

		free(pTextureImage);
	}

	pTextureImage = auxDIBImageLoad("C:\\Users\\아영\\source\\repos\\Project1\\Project1\\table.bmp");
	if (pTextureImage != NULL) {
		glGenTextures(1, &textureID[2]);

		glBindTexture(GL_TEXTURE_2D, textureID[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);

	}

	if (pTextureImage) {
		if (pTextureImage->data)
			free(pTextureImage->data);

		free(pTextureImage);
	}

	pTextureImage = auxDIBImageLoad("C:\\Users\\아영\\source\\repos\\Project1\\Project1\\background.bmp");
	if (pTextureImage != NULL) {
		glGenTextures(1, &textureID[3]);
		glBindTexture(GL_TEXTURE_2D, textureID[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);

	}

	if (pTextureImage) {
		if (pTextureImage->data)
			free(pTextureImage->data);

		free(pTextureImage);
	}

	pTextureImage = auxDIBImageLoad("C:\\Users\\아영\\source\\repos\\Project1\\Project1\\bottom.bmp");
	if (pTextureImage != NULL) {
		glGenTextures(1, &textureID[4]);
		glBindTexture(GL_TEXTURE_2D, textureID[4]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);

	}

	if (pTextureImage) {
		if (pTextureImage->data)
			free(pTextureImage->data);

		free(pTextureImage);
	}

	pTextureImage = auxDIBImageLoad("C:\\Users\\아영\\source\\repos\\Project1\\Project1\\mixer1.bmp");
	if (pTextureImage != NULL) {
		glGenTextures(1, &textureID[5]);
		glBindTexture(GL_TEXTURE_2D, textureID[5]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);



	}

	if (pTextureImage) {
		if (pTextureImage->data)
			free(pTextureImage->data);

		free(pTextureImage);
	}


	pTextureImage = auxDIBImageLoad("C:\\Users\\아영\\source\\repos\\Project1\\Project1\\mixer2.bmp");
	if (pTextureImage != NULL) {
		glGenTextures(1, &textureID[6]);
		glBindTexture(GL_TEXTURE_2D, textureID[6]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);



	}

	if (pTextureImage) {
		if (pTextureImage->data)
			free(pTextureImage->data);

		free(pTextureImage);
	}


}

void MyInit() {

	GLfloat light_position[] = { 30.0, 20.0, 70.0, 0.0 };

	loadTexture();
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);


	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

void background() //배경
{
	glBindTexture(GL_TEXTURE_2D, textureID[3]);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glInterleavedArrays(GL_T2F_V3F, 0, backgroundVertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glTranslatef(0, 0, 0);
	glPopMatrix();


}

void watermelon()
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	glBindTexture(GL_TEXTURE_2D, textureID[0]);

	glPushMatrix();
	glTranslated(-1, 0.6, 0.0);
	glRotated(60, 1, 0, 0);
	glRotated(40, 0, 1, 0);
	gluSphere(qobj, 0.5, 50, 50);
	glPopMatrix();

}



void mixerone()
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);

	glBindTexture(GL_TEXTURE_2D, textureID[5]);


	glPushMatrix();
	glTranslated(0.8, 0.4, 1);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.22, 0.25, 0.4, 20, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.8, 0.3, 1);
	glRotated(90, 1, 0, 0);
	gluDisk(qobj, 0, 0.22, 10, 3);
	glPopMatrix();

} 

void mixertwo()
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);


	glBindTexture(GL_TEXTURE_2D, textureID[6]);
	glPushMatrix();
	glTranslated(0.8, 1, 1);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.25, 0.2, 0.6, 20, 8);
	glPopMatrix();

	glPushMatrix();
	//glTranslated(0.15, 0.8, 0.12);
	glTranslated(0.8, 1, 1);
	glRotated(90, 1, 0, 0);
	gluDisk(qobj, 0, 0.27, 20, 3);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, textureID[6]);
	glPushMatrix();
	glTranslated(0.8, 1, 1);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.27, 0.27, 0.08, 20, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.8, 1.05, 1);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.05, 20, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.8, 1, 1);
	glRotated(90, 1, 0, 0);
	gluDisk(qobj, 0, 0.05, 10, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.8, 0.2, 1.25);
	glRotated(0, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.05, 20, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.8, 0.2, 1.28);
	glRotated(0, 1, 0, 0);
	gluDisk(qobj, 0, 0.05, 10, 3);
	glPopMatrix();
	

}

void bottom()
{
	glBindTexture(GL_TEXTURE_2D, textureID[4]);
	glPushMatrix();
	glTranslated(0, -3.0, 0.0);
	glScaled(14, 0.2, 10.0);
	glutSolidCube(1);
	glPopMatrix();
}




void table()
{

	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);

	//테이블
	glPushMatrix();
	glTranslated(0, 0, 0.0);
	glScaled(4, 0.2, 3);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.7, 0, -1.2);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.1, 3, 20, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.7, 0, -1.2);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.1, 3, 20, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.7, 0, 1.2);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.1, 3, 20, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.7, 0, 1.2);
	glRotated(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.1, 3, 20, 8);
	glPopMatrix();




}

void milk()
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	glBindTexture(GL_TEXTURE_2D, textureID[5]);

	glPushMatrix();
	glTranslated(0, 0.2, 0.0);
	glRotated(-30, 0, 1, 0);
	glScaled(0.3, 0.2, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0.75, 0.0);
	glRotated(-30, 0, 1, 0);
	glRotated(45, 1,  0, 0);
	glScaled(0.26, 0.25, 0.22);
	glutSolidCube(1);
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, textureID[5]);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glutSwapBuffers();

	/*
	glPushMatrix();
	glTranslated(0, 0.4, 0.0);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glRotated(-30, 0, 1, 0);
	glScaled(0.5, 0.7, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glutSwapBuffers();
	*/
}



void milktwo()
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);

	glBindTexture(GL_TEXTURE_2D, textureID[6]);
	glPushMatrix();
	glTranslated(0, 0.52, 0.0);
	glRotated(-30, 0, 1, 0);
	glScaled(0.3, 0.45, 0.3);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0, 0.94, 0.0);
	glRotated(-30, 0, 1, 0);
	glScaled(0.25, 0.06, 0.01);
	glutSolidCube(1);
	glPopMatrix();



}


const GLfloat light_pos[] = { -3000.0, 3000.0, 3000.0, 0.7 };

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.0, 1.0, -5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 1, 7.0, 0+ Center_x,1+ Center_y, -4000, 0.0, 1.0, 0.0);
	glTranslated(Look_x, Look_y, Look_z);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	
	background();
	bottom();
	watermelon();
	table();
	mixerone();
	mixertwo();
	milktwo();
	milk();




}

void init_parameter()
{
	Look_x = 0.0f;
	Look_y = 0.0f;
	Look_z = 0.0f;

	Angle_x = 0.0f;
	Angle_y = 0.0f;
}

void reshape(GLint W, GLint H)
{
	if ((GLfloat)W / H > 1.0) glViewport(0, 0, H, H);
	else glViewport(0, 0, W, W);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'a':
		Look_x += 0.1;
		glutPostRedisplay();
		break;
	case 'd':
		Look_x -= 0.1;
		glutPostRedisplay();
		break;
	case 'w':
		Look_z += 0.1;
		glutPostRedisplay();
		break;
	case 's':
		Look_z -= 0.1;
		glutPostRedisplay();
		break;
	case 'z':
		Look_y += 0.1;
		glutPostRedisplay();
		break;
	case 'x':
		Look_y -= 0.1;
		glutPostRedisplay();
		break;
	
	}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Blender");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(MyMouseMove);
	glutMouseFunc(MyMouseClick);

	glutMainLoop();
	return 0;
}