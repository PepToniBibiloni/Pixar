#include "drawFunctions.h"
// Función para dibujar ejes de referencia
void referenceAxis()
{
	glBegin(GL_LINES);    // x
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES); // y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES); //z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();	
}

void dibujarLampara(GLfloat fAnguloRotacion,GLfloat fAnguloInferior){
    glPushMatrix();         
		glColor3f(1.0f, 1.0f, 1.0f);
		glRotatef(fAnguloRotacion,0.0f,1.0f,0.0f);
		drawBase();
		glTranslatef(0.0f,0.1f,0.0f);
		GLfloat fAnguloInferiorInicial= 45.0f; //blanco
		glRotatef(fAnguloInferiorInicial,0.0f,0.0f,1.0f);
		draw3dRectangle(0.02f,0.2f,0.02f);
		
		drawTwo(fAnguloInferior,0.15f,0.02f);

		drawScrew(0.01f,0.06);

		glTranslatef(0.0f,0.15f,0.0f);
		drawTwo(-fAnguloInferior,0.2f,0.03f);

		drawScrew(0.01f,0.08);

		glTranslatef(0.0f,0.2f,0.0f);
		drawTwo(-(180-fAnguloInferior),0.15f,0.02f);

		drawScrew(0.01f,0.08);
		glTranslatef(0.0f,0.15f,0.0f);
		drawTwo(140,0.2f,0.02f);

		drawScrew(0.01f,0.06);

		glTranslatef(0.0f,0.2f,0.0f);
		glRotatef(30,0.0f,0.0f,-1.0f);
		draw3dRectangle(0.015f,0.25f,0.01f);

		drawScrew(0.01f,0.06);
		glTranslatef(0.0f,0.25f,0.0f);
		drawTwo(45,0.09f,0.02f);

		drawScrew(0.01f,0.06);

		glTranslatef(0.0f,0.09f,0.0f);
		glRotatef(45,0.0f,0.0f,1.0f);
		drawCylinder(0.02f,0.1f);
		glRotatef(45,0.0f,0.0f,-1.0f);

		drawScrew(0.01f,0.06);
		drawLamp(0.3f,0.3f);

		drawTwo(90,0.09f,0.02f);
		glTranslatef(0.0f,0.09f,0.0f);
		drawScrew(0.01f,0.06f);

		glRotatef(45,0.0f,0.0f,-1.0f);
		draw3dRectangle(0.015f,0.25f,0.01f);

	glPopMatrix();
}
void draw3dRectangle(GLfloat width,GLfloat height,GLfloat depth){
	GLfloat extra = 0.02f;
	glBegin(GL_QUADS); 
		glVertex3f(-width,0.0f-extra,-depth);
		glVertex3f(-width,height+extra,-depth);	
		glVertex3f(width,height+extra,-depth);
		glVertex3f(width,0.0f-extra,-depth);
	glEnd();
	glBegin(GL_QUADS); 
		glVertex3f(-width,0-extra,depth);
		glVertex3f(-width,height+extra,depth);	
		glVertex3f(width,height+extra,depth);
		glVertex3f(width,0.0f-extra,depth);
	glEnd();
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	glBegin(GL_QUADS); 
		glVertex3f(-depth,0-extra,-width);
		glVertex3f(-depth,height+extra,-width);	
		glVertex3f(depth,height+extra,-width);
		glVertex3f(depth,0.0f-extra,-width);
	glEnd();
	glBegin(GL_QUADS); 
		glVertex3f(-depth,0-extra,width);
		glVertex3f(-depth,height+extra,width);	
		glVertex3f(depth,height+extra,width);
		glVertex3f(depth,0.0f-extra,width);
	glEnd();
	glRotatef(90.0f,1.0f,0.0f,0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-depth,width,-height-extra);
		glVertex3f(depth,width,-height-extra);	
		glVertex3f(depth,-width,-height-extra);
		glVertex3f(-depth,-width,-height-extra);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-depth,width,0.0f+extra);
		glVertex3f(depth,width,0.0f+extra);	
		glVertex3f(depth,-width,0.0f+extra);
		glVertex3f(-depth,-width,0.0f+extra);
	glEnd();
	glRotatef(90.0f,-1.0f,0.0f,0.0f);
	glRotatef(90.0f,0.0f,-1.0f,0.0f);
}

void drawTwo(GLfloat angle,GLfloat height, GLfloat thickness){
	glRotatef(angle,0.0f,0.0f,-1.0f);
	glTranslatef(0.0f,0.0f,-thickness);
	draw3dRectangle(0.015f,height,0.005f);
	glTranslatef(0.0f,0.0f,thickness*2);
	draw3dRectangle(0.015f,height,0.005f);
	glTranslatef(0.0f,0.0f,-thickness);
}

void drawCylinder(GLfloat base, GLfloat height){
	GLUquadricObj *qobj;
    qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	glRotatef(90.0f,-1.0f,0.0f,0.0f);
	gluDisk(qobj,0.0f,base,50,50);
	gluCylinder(qobj,base,base,height,50,50);
	glTranslatef(0.0f,0.0f,height);
	gluDisk(qobj,0.0f,base,50,50);
	glTranslatef(0.0f,0.0f,-height);
	glRotatef(90.0f,1.0f,0.0f,0.0f);
}

void drawLamp(GLfloat base,GLfloat height){
	glTranslatef(-0.13f,0.3f,0.0f);
	glRotatef(90.0,1.0f,0.0f,0.0f);
	glutWireCone(base,height,50,50);
	glRotatef(90.0,-1.0f,0.0f,0.0f);
	glTranslatef(0.0f,-base/3,0.0f);
	glColor3f(1.0f,1.0f,0.0f); //groc
	glutSolidSphere(base/3,50,50);
	glTranslatef(0.0f,base/3,0.0f);
	glTranslatef(0.13f,-0.3f,0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
}

void drawScrew(GLfloat base, GLfloat height){
	glTranslatef(0.0f,0.0f,-height/2);
	glColor3f(0.752941,0.752941,0.752941);
	GLUquadricObj *qobj;
    qobj = gluNewQuadric();
	glRotatef(90.0f,0.0f,0.0f,1.0f);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluDisk(qobj,0.0f,base,50,50);
	gluCylinder(qobj,base,base,height,50,50);
	glTranslatef(0.0f,0.0f,height);
	gluDisk(qobj,0.0f,base,50,50);
	glTranslatef(0.0f,0.0f,-height);
	glRotatef(90.0f,0.0f,0.0f,-1.0f);
	glTranslatef(0.0f,0.0f,height/2);
	glColor3f(1.0f, 1.0f, 1.0f);
}

void drawBase(){
	drawCylinder(0.245f,0.04f);
	drawCylinder(0.2f,0.04f);
	glTranslatef(0.0f,0.04f,0.0f);
	glRotatef(90.0f,1.0f,0.0f,0.0f);
	glutSolidTorus(0.04f,0.2f,50,50);
	glRotatef(90.0f,-1.0f,0.0f,0.0f);
	glTranslatef(0.0f,0.04f,0.0f);
	glRotatef(90.0f,1.0f,0.0f,0.0f);
	glutSolidTorus(0.02f,0.02f,50,50);
	glRotatef(90.0f,-1.0f,0.0f,0.0f);
	drawCylinder(0.02,0.10f);
}