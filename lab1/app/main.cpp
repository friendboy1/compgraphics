#include <stdio.h>     
#include <gl/glut.h>
#include <math.h>
//#include <stdlib.h> <- �� ��������!
#include <time.h> //for time()

void star();
void shapeLine(double x1, double y1, double x2, double y2);
void shapeDisc(double x, double y, double radius,
	double colorRed = 1.0, double colorGreen = 0.5, double colorBlue = 0.7,
	int accuracy = 1000);
void shapeSquare(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4,
	double colorRed = 1.0, double colorGreen = 0.5, double colorBlue = 0.7);
void shapeTriangle(double x1, double y1, double x2, double y2, double x3, double y3,
	double colorRed = 1.0, double colorGreen = 0.5, double colorBlue = 0.7);
void shapeHouse(double positionCenterX, double positionCenterY, double angles = 0,
	double bodyWeight = 100, double bodyHeight = 70,
	double bodyColorRed = 1.0, double bodyColorGreen = 0.5, double bodyColorBlue = 0.7,
	double windowFrameWeight = 1,
	double windowColorRed = 0.0, double windowColorGreen = 0.5, double windowColorBlue = 0.7,
	double roofWeight = 130, double roofHeight = 80,
	double roofColorRed = 0.8, double roofColorGreen = 0.5, double roofColorBlue = 0.7);
void shapeHouseMini(double x = 100, double y = 100, double size = 50, double angle = 0);

// ������� ���������
void display()
{
	static double angles = 0.0;
	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	glLineWidth(2); //������������� ������ �����
	glColor3f(1.0, 0.0, 0.0); //������������� ���� (RBG)
	//glRotatef(1, 0.0, 0.0, 1.0); //<- ������� ������ �� 1 ������ ������ ���
	//shapeDisc(400, 300, 100, 1.0, 1.0, 0.0);
	//shapeSquare(50, 50, 100, 50, 100, 100, 50, 100, 1.0, 0.5, 0.7);
	//shapeTriangle(50, 50, 100, 50, 100, 100, 1.0, 0.5, 0.7);
	shapeDisc(160, 440, 150, 1.0, 1.0, 0.2);
	shapeDisc(480, 227, 50, 0.2, 0.7, 1.0);
	shapeDisc(760, 40, 30, 0.8, 0.9, 0.8);
	shapeLine(160, 440, 750, 50);
	shapeHouseMini(480, 307, 30, angles);
	star();

	angles += 1.7;
	glFlush();
}

//������
void Timer(int val)
{
	
	//display(); <- ��������� ����� ��� ��� ���
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0); //����� �������� ������
}

// ������� ��� "�����������" ����������� ��� ��������� �������� ����
void Reshape(int Width, int Height)
{
	if (Height == 0)
	{
		Height = 1;
	}
	
	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)Width, 0.0, (GLdouble)Height);

	display();
} 

// ������� �������������
void init() 
{
   glClearColor(0.0, 0.0, 0.0, 1.0); //�������� ���� ���� (?)
}

//������� ��������� ������
void star()
{
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(100, 200);
	glVertex2f(370, 80);
	glVertex2f(720, 490);
	glVertex2f(302, 529);
	glVertex2f(722, 245);
	glVertex2f(518, 328);
	glVertex2f(717, 258);
	glVertex2f(182, 186);
	glEnd();
}

//������� ��������� ���
void shapeLine(double x1, double y1, double x2, double y2)
{
	glEnable(GL_LINE_STIPPLE);

	glLineStipple(2, 0x1C47);
	//glLineStipple(2,58360);
	glBegin(GL_LINES);
	glColor3f(0.2, 0.3, 0.3);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

//������� ��������� �����
void shapeDisc(double x, double y, double radius, 
	double colorRed, double colorGreen, double colorBlue, 
	int accuracy)
{
	glColor3f(colorRed, colorGreen, colorBlue); //������������� ���� (RBG)
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); //����� ����������
	for (int i = 0; i <= accuracy; i++)
	{
		double a = 2.0 * 3.141592653589793238462643 * (double(i) / accuracy); //���� ���� - 2pi, �������� �� �����
		glVertex2f(x + cos(a) * radius, y + sin(a) * radius);
	}
	glEnd();
}

//������� ��������� ��������
void shapeSquare(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4,
	double colorRed, double colorGreen, double colorBlue)
{
	glColor3f(colorRed, colorGreen, colorBlue); //������������� ���� (RBG)
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

//������� ��������� �����������
void shapeTriangle(double x1, double y1, double x2, double y2, double x3, double y3,
	double colorRed, double colorGreen, double colorBlue)
{
	glColor3f(colorRed, colorGreen, colorBlue); //������������� ���� (RBG)
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

//������� ��������� ������
void shapeHouse(double positionCenterX, double positionCenterY, double angles,
	double bodyWeight, double bodyHeight,
	double bodyColorRed, double bodyColorGreen, double bodyColorBlue,
	double windowFrameWeight,
	double windowColorRed, double windowColorGreen, double windowColorBlue,
	double roofWeight, double roofHeight,
	double roofColorRed, double roofColorGreen, double roofColorBlue)
{
	double light = angles * 3.141592653589793238462643 / 180.0;
	if (cos(light) < 0 && sin(light) > 0) { roofColorRed = 0.7; roofColorGreen = 0.3; roofColorBlue = 0.3; }
	if (cos(light) > 0 && sin(light) < 0) { roofColorRed = 1.0; roofColorGreen = 0.4; roofColorBlue = 0.5; }
	glPushMatrix();
	glTranslated(positionCenterX, positionCenterY-80, 0); //������� ���������� ��� (?)
	glRotated(-angles, 0.0, 0.0, 1.0);
	glTranslated(-positionCenterX, -positionCenterY+80, 0);
	shapeSquare( //���� ������
		positionCenterX - bodyWeight / 2.0, positionCenterY - bodyWeight / 2.0,
			positionCenterX + bodyWeight / 2.0, positionCenterY - bodyWeight / 2.0,
			positionCenterX + bodyWeight / 2.0, positionCenterY + bodyWeight / 2.0,
			positionCenterX - bodyWeight / 2.0, positionCenterY + bodyWeight / 2.0,
			bodyColorRed, bodyColorGreen, bodyColorBlue);
	shapeSquare( //������ ������ 1
		positionCenterX - windowFrameWeight - bodyWeight / 5.0, positionCenterY - windowFrameWeight - bodyWeight / 5.0,
		positionCenterX - windowFrameWeight, positionCenterY - windowFrameWeight - bodyWeight / 5.0,
		positionCenterX - windowFrameWeight, positionCenterY - windowFrameWeight,
		positionCenterX - windowFrameWeight - bodyWeight / 5.0, positionCenterY - windowFrameWeight,
		windowColorRed, windowColorGreen, windowColorBlue);
	shapeSquare( //������ ������ 2
		positionCenterX + windowFrameWeight, positionCenterY - windowFrameWeight - bodyWeight / 5.0,
		positionCenterX + windowFrameWeight + bodyWeight / 5.0, positionCenterY - windowFrameWeight - bodyWeight / 5.0,
		positionCenterX + windowFrameWeight + bodyWeight / 5.0, positionCenterY - windowFrameWeight,
		positionCenterX + windowFrameWeight, positionCenterY - windowFrameWeight,
		windowColorRed, windowColorGreen, windowColorBlue);
	shapeSquare( //������ ������ 3
		positionCenterX + windowFrameWeight, positionCenterY + windowFrameWeight,
		positionCenterX + windowFrameWeight + bodyWeight / 5.0, positionCenterY + windowFrameWeight,
		positionCenterX + windowFrameWeight + bodyWeight / 5.0, positionCenterY + windowFrameWeight + bodyWeight / 5.0,
		positionCenterX + windowFrameWeight, positionCenterY + windowFrameWeight + bodyWeight / 5.0,
		windowColorRed, windowColorGreen, windowColorBlue);
	shapeSquare( //������ ������ 4
		positionCenterX - windowFrameWeight - bodyWeight / 5.0, positionCenterY + windowFrameWeight,
		positionCenterX - windowFrameWeight, positionCenterY + windowFrameWeight,
		positionCenterX - windowFrameWeight, positionCenterY + windowFrameWeight + bodyWeight / 5.0,
		positionCenterX - windowFrameWeight - bodyWeight / 5.0, positionCenterY + windowFrameWeight + bodyWeight / 5.0,
		windowColorRed, windowColorGreen, windowColorBlue);
	shapeTriangle( //����� 
		positionCenterX - roofWeight / 2.0, positionCenterY + bodyWeight / 2.0,
		positionCenterX + roofWeight / 2.0, positionCenterY + bodyWeight / 2.0,
		positionCenterX, positionCenterY + + bodyHeight / 2.0 + roofHeight,
		roofColorRed, roofColorGreen, roofColorBlue);
	glPopMatrix();
}

void shapeHouseMini(double x, double y, double size, double angle)
{
	shapeHouse(x, y, angle,
		size * 2.0, size * 2.5,
		1.0, 0.5, 0.7,
		size / 100,
		0.0, 0.5, 0.7,
		size * 2.8, size * 1.4,
		1.0, 0.1, 0.2);
}

// ������� �������
int main(int argc, char **argv)
{
	glutInit(&argc, argv); //�������������� GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //�������� ���� � ��������� �������� ����� (?)
	glutInitWindowPosition(0, 0); //������� ����
	glutInitWindowSize(800, 600); //������ ����
	glutCreateWindow( "Main window" ); //������ ����
	init();
    glutDisplayFunc(display); //������ ������� ��������� ����������� (?)
 	glutReshapeFunc(Reshape); //������ ������� ��������� ��������� �������� ���� (?)
    printf("It's a test app.");
	glutTimerFunc(50, Timer, 0); //��������� ������, 50 ��, � ���������� 0 (?)
	glutMainLoop(); //������ �������� ����� (?)

	return 0;
}

