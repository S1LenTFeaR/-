//Подключаем библиотеку glut.h и cmath
#include "pch.h"
#include "glut.h"
#include <cmath>
#include <iostream>

using namespace std;

float N = 0.0;

//Начальные данные
double I = 0; //Сила тока [А]
double q = 2 * pow(10, -6); //Заряд конденсатора [Кл]
double R = 200;
double L = 0.5; //Индуктивность [Гн]
double C = 0.5 * pow(10, -6);
double t = 0;
double dt = 0.00001;
double E = 0;
double E_max = 20;
double Beta = 0.0;
double Omega_0 = 0.0;
double Omega = 0.0;

void change_size(GLsizei w, GLsizei h) {
	GLdouble aspect_ratio;
	//Предотвращается деление на 0 
	if (h == 0)
		h = 1;
	//Устанавливается поле просмотра с размерами окна 
	glViewport(0, 0, w, h);
	//Обновляется система координат 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//С помощью плоскостей отсечения (левая, правая, нижняя, //верхняя, ближняя, дальняя) устанавливается объем отсечения 
	aspect_ratio = (GLdouble)w / (GLdouble)h;
	gluPerspective(150.0, aspect_ratio, 1, 100.0);
	glTranslatef(0.0, 0.0, -15.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void initialise() {
	//Задается цвет очистки окна - черный
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void render_scene() {
	//Очищается окно, используя текущий цвет очистки 
	glClear(GL_COLOR_BUFFER_BIT);
	//В качестве текущего цвета рисования задаем красный 
	//R G B 
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(1);
	//Рисуем координатную систему:
	//Рисуем ось Ox
	glBegin(GL_LINES);
	glVertex2f(-100.0, 0.0);
	glVertex2f(100.0, 0.0);
	glEnd();
	//Рисуем ось Оу 
	glBegin(GL_LINES);
	glVertex2f(0.0, -60.0);
	glVertex2f(0.0, 60.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -60.0);
	glVertex3f(0.0, 0.0, 60.0);
	glEnd();

	Beta = R / (2 * L); //Коэффицент затухания
	Omega_0 = sqrt(1 / (L * C));
	Omega = sqrt(Omega_0 * Omega_0 - Beta * Beta);
	I -= (2 * Beta * I + Omega_0 * Omega_0 * q - (E_max * cos(Omega * t) / L)) * (dt / 2.0);
	glPointSize(1);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.42, 1, 0.95);
	while (t <= N) {
		glVertex2d(t * 2500, I * 300);
		//glVertex2d(t * 2500, q * 600000);
		//glVertex2d(t * 2500, E * 1.5);
		I -= (2 * Beta * I + Omega_0 * Omega_0 * q - (E_max * cos(Omega * t) / L)) * dt;
		q = q + I * dt;
		E = E_max * cos(Omega * t);
		t += dt;
	}
	glEnd();
	glFlush();                            //Освобождает буферы
	glutSwapBuffers();                    //смена переднего и заднего буферов
}

void keyboard_func(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		N += 0.1;
		if (N < 10000) render_scene();
		break;
	case 27:	//Escape
		exit(0);
	}
}

static void reshape_view(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Oscillatory circuit");

	glutKeyboardFunc(keyboard_func);
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	initialise();
	glutMainLoop();
	return 0;
}