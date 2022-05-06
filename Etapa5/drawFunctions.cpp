#include "drawFunctions.h"

// Function para dibujar ejes de referencia
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

// Funcion para dibujar una lámpara
void drawLamp(GLfloat fAnguloRotacion,GLfloat fAnguloInferior){
    glPushMatrix();         
		glColor3f(1.0f, 1.0f, 1.0f);
		glRotatef(fAnguloRotacion,0.0f,1.0f,0.0f);
		drawBase(); //base
		glTranslatef(0.0f,0.1f,0.0f);
		GLfloat fAnguloInferiorInicial= 45.0f;
		glRotatef(fAnguloInferiorInicial,0.0f,0.0f,1.0f);
		
		// Estructura de la lámpara		
		draw3dRectangle(0.02f,0.2f,0.015f);
		drawTwo3DRectangles(fAnguloInferior,0.15f,0.02f);

		drawScrew(0.01f,0.06);

		glTranslatef(0.0f,0.15f,0.0f);
		drawTwo3DRectangles(-fAnguloInferior,0.2f,0.03f);

		drawScrew(0.01f,0.08);

		glTranslatef(0.0f,0.2f,0.0f);
		drawTwo3DRectangles(-(180-fAnguloInferior),0.15f,0.02f);

		drawScrew(0.01f,0.08);
		glTranslatef(0.0f,0.15f,0.0f);
		drawTwo3DRectangles(140,0.2f,0.02f);

		drawScrew(0.01f,0.06);

		glTranslatef(0.0f,0.2f,0.0f);
		glRotatef(30,0.0f,0.0f,-1.0f);
		draw3dRectangle(0.015f,0.25f,0.01f);

		drawScrew(0.01f,0.06);
		glTranslatef(0.0f,0.25f,0.0f);
		drawTwo3DRectangles(45,0.09f,0.02f);

		drawScrew(0.01f,0.06);

		glTranslatef(0.0f,0.09f,0.0f);
		glRotatef(45,0.0f,0.0f,1.0f);
		drawCylinder(0.02f,0.1f);
		glRotatef(45,0.0f,0.0f,-1.0f);

		drawScrew(0.01f,0.06);

		drawLampShade(0.3f,0.3f); // Lampara

		drawTwo3DRectangles(90,0.09f,0.02f);
		glTranslatef(0.0f,0.09f,0.0f);
		drawScrew(0.01f,0.06f);

		glRotatef(45,0.0f,0.0f,-1.0f);
		draw3dRectangle(0.015f,0.25f,0.01f);
	glPopMatrix();
}

// Function para dibujar un rectángulo 3D
void draw3dRectangle(GLfloat width,GLfloat height,GLfloat depth){
	GLfloat extra = 0.02f;
	// Dibujar el rectángulo en el eje z
	glBegin(GL_QUADS); 
		glVertex3f(-width,-extra,-depth); // Abajo izquierda
		glVertex3f(-width,height+extra,-depth);	// Arriba izquierda
		glVertex3f(width,height+extra,-depth);  // Arriba derecha
		glVertex3f(width,-extra,-depth); // Abajo derecha
	glEnd();
	glBegin(GL_QUADS); 
		glVertex3f(-width,-extra,depth); // Abajo izquierda
		glVertex3f(-width,height+extra,depth);	// Arriba izquierda
		glVertex3f(width,height+extra,depth); // Arriba derecha
		glVertex3f(width,-extra,depth); // Abajo derecha
	glEnd();
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	// Dibujamos el rectángulo en el eje x
	glBegin(GL_QUADS); 
		glVertex3f(-depth,-extra,-width); 
		glVertex3f(-depth,height+extra,-width);	
		glVertex3f(depth,height+extra,-width);
		glVertex3f(depth,-extra,-width);
	glEnd();
	glBegin(GL_QUADS); 
		glVertex3f(-depth,-extra,width); 
		glVertex3f(-depth,height+extra,width);	
		glVertex3f(depth,height+extra,width);  
		glVertex3f(depth,-extra,width); 
	glEnd();
	glRotatef(90.0f,1.0f,0.0f,0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-depth,width,-height-extra); 
		glVertex3f(depth,width,-height-extra);	
		glVertex3f(depth,-width,-height-extra);  
		glVertex3f(-depth,-width,-height-extra);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-depth,width,extra); 
		glVertex3f(depth,width,extra);	
		glVertex3f(depth,-width,extra); 
		glVertex3f(-depth,-width,extra);
	glEnd();
	glRotatef(90.0f,-1.0f,0.0f,0.0f);
	glRotatef(90.0f,0.0f,-1.0f,0.0f); 
}

// Funcion para dibujar dos rectángulos 3D
void drawTwo3DRectangles(GLfloat angle,GLfloat height, GLfloat thickness){
	glRotatef(angle,0.0f,0.0f,-1.0f);
	glTranslatef(0.0f,0.0f,-thickness);
	draw3dRectangle(0.015f,height,0.005f); // Rectángulo inferior
	glTranslatef(0.0f,0.0f,thickness*2); 
	draw3dRectangle(0.015f,height,0.005f); // Rectángulo superior
	glTranslatef(0.0f,0.0f,-thickness);
}

// Funciom para dibujar un cilindro
void drawCylinder(GLfloat base, GLfloat height){
	GLUquadricObj *qobj;
    qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL); 
	glRotatef(90.0f,-1.0f,0.0f,0.0f); 
	gluDisk(qobj,0.0f,base,50,50); // Base
	gluCylinder(qobj,base,base,height,50,50); // Cilindro
	glTranslatef(0.0f,0.0f,height); 
	gluDisk(qobj,0.0f,base,50,50); // Capa superior
	glTranslatef(0.0f,0.0f,-height); 
	glRotatef(90.0f,1.0f,0.0f,0.0f); 
}

// Funcion para dibujar parte superior de la lámpara
void drawLampShade(GLfloat base,GLfloat height){
	float cx, cy, cz, angleSh;
	cx = -0.16f;
	cy = 0.06f;
	cz = 0.0f;
	angleSh = -30.0f;
	glTranslatef(cx, cy, cz);
	// rotamos la cabeza de la lámpara
	glRotatef(angleSh, 0.0f, 0.0f, 1.0f);
	// rotar cabeza de izquierda a derecha aqui
	drawCylinder(0.1f, height / 2);
	glTranslatef(0.0f, -0.05f, 0.00f);
	drawCylinder(0.065f, 0.05f);
	glTranslatef(0.0f, 0.05f, 0.00f);

	glRotatef(-90.0, 1.0f, 0.0f, 0.0f);
	glutSolidTorus(0.05f, 0.05f, 50, 50); // Toro
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, 0.35f, 0.00f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	glutSolidCone(base, height * 1.3, 200, 200); // Cono
	glRotatef(90.0, -1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -0.35f, 0.00f);

	//dibujar bombilla de la lámpara
	glTranslatef(0.0f, height*1.1f,0.0f);
	glColor3f(0.99f, 0.99f, 0.58f);	 
	glutSolidSphere(base / 2, 50, 50); // Bombilla   
	glColor3f(1.0f, 1.0f, 1.0f);  
	glTranslatef(0.0f, -height*1.1f,0.0f);

	glRotatef(-angleSh, 0.0f, 0.0f, 1.0f);
	glTranslatef(-cx, -cy, -cz);	
}

// Funcion para dibujar pelota pixar
void drawPixarBall(){
/*	glColor3f(0.0f,1.0f,0.0f);
	GLUquadricObj *sphere=NULL;
	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	//Making a display list
	mysphereID = glGenLists(1);
	glNewList(mysphereID, GL_COMPILE);
	gluSphere(sphere, 1.0, 20, 20);
	glEndList();
	gluDeleteQuadric(sphere);
	glColor3f(1.0f,1.0f,1.0f);*/
}

// Funcion para dibujar tornillo
void drawScrew(GLfloat base, GLfloat height){
	glTranslatef(0.0f,0.0f,-height/2);
	glColor3f(0.752941,0.752941,0.752941);
	GLUquadricObj *qobj;
    qobj = gluNewQuadric();
	glRotatef(90.0f,0.0f,0.0f,1.0f);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluDisk(qobj,0.0f,base,50,50); // Draw the base
	gluCylinder(qobj,base,base,height,50,50); // Draw the cylinder
	glTranslatef(0.0f,0.0f,height); // Move to the top of the cylinder
	gluDisk(qobj,0.0f,base,50,50); // Draw the top
	glTranslatef(0.0f,0.0f,-height);
	glRotatef(90.0f,0.0f,0.0f,-1.0f);
	glTranslatef(0.0f,0.0f,height/2);
	glColor3f(1.0f, 1.0f, 1.0f);
}

// Funcion para dibujar base de la lámpara
void drawBase(){
	drawCylinder(0.24f,0.04f);
	drawCylinder(0.2f,0.08f);
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