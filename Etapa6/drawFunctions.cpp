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
void drawLamp(GLfloat fAngRot,GLfloat fAngInf,GLfloat fAngRotShade){
    glPushMatrix();         
		glColor3f(1.0f, 1.0f, 1.0f);
		glRotatef(fAngRot,0.0f,1.0f,0.0f);
		drawBase(); //base
		glTranslatef(0.0f,0.1f,0.0f);
		GLfloat fAngInfInicial= 45.0f;
		glRotatef(fAngInfInicial,0.0f,0.0f,1.0f);
		
		// Estructura de la lámpara		
		draw3dRectangle(0.02f,0.2f,0.015f);
		drawTwo3DRectangles(fAngInf,0.15f,0.02f);

		drawScrew(0.01f,0.06);

		glTranslatef(0.0f,0.15f,0.0f);
		drawTwo3DRectangles(-fAngInf,0.2f,0.03f);

		drawScrew(0.01f,0.08);

		glTranslatef(0.0f,0.2f,0.0f);
		drawTwo3DRectangles(-(180-fAngInf),0.15f,0.02f);

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

		drawLampShade(0.3f,0.3f,fAngRotShade); // Lampara
		GLfloat pos[]={0.0f, 0.0f, 0.0f,1.0f };
		glLightfv(GL_LIGHT0, GL_POSITION,pos); // Actualizamos la posici�n de la luz
		drawScrew(0.01f,0.06);
		
		
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

void drawFloor(GLfloat width,GLfloat height){
	glNormal3f(0.0f,1.0f,0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-width,0.0f,-height);
		glVertex3f(-width,0.0f,height);
		glVertex3f(width,0.0f,height);
		glVertex3f(width,0.0f,-height);
	glEnd();
}


void drawWalls(GLfloat width,GLfloat height,GLfloat depth){
	glColor3f(1.0f,1.0f,1.0f);
	glNormal3f(0.0f,1.0f,0.0f);
	float incr = width/10;
	float incrD = depth/10;
	for (GLfloat i = -width; i < width; i+=incr){
		for (GLfloat j = 0.0f; j < depth; j+=incrD){
			glBegin(GL_QUADS);
				glVertex3f(i,j,-height);
				glVertex3f(i,j+incrD,-height);
				glVertex3f(i+incr,j+incrD,-height);
				glVertex3f(i+incr,j,-height);
			glEnd();
			glRotatef(90.0f,0.0f,1.0f,0.0f);
			glBegin(GL_QUADS);
				glVertex3f(i,j,-height);
				glVertex3f(i,j+incrD,-height);
				glVertex3f(i+incr,j+incrD,-height);
				glVertex3f(i+incr,j,-height);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3f(i,j,height);
				glVertex3f(i,j+incrD,height);
				glVertex3f(i+incr,j+incrD,height);
				glVertex3f(i+incr,j,height);
			glEnd();
			glRotatef(90.0f,0.0f,-1.0f,0.0f);
		}
	}
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

// Function draw cone withouth base
void drawCone(GLfloat base, GLfloat height){
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	glRotatef(180.0f,1.0f,0.0f,0.0f);
	glTranslatef(0.0f,0.0f,-height);
	gluCylinder(qobj,0.0f,base,height,50,50); // Cilindro
	glTranslatef(0.0f,0.0f,height);
	glRotatef(180.0f,-1.0f,0.0f,0.0f);
}
	
// Funcion para dibujar parte superior de la lámpara
void drawLampShade(GLfloat base,GLfloat height,GLfloat angleSh){     
	float cx,cy,cz;     

	cx=-0.16f; cy=0.06f; cz=0.0f;    
	glTranslatef(cx,cy,cz);     //rotamos la cabeza de la lámpara     
	glRotatef(-45,0.0f,0.0f,1.0f);
	glRotatef(angleSh,1.0f,0.0f,0.0f);     //rotar cabeza de izquierda a derecha aqui   
	drawCylinder(0.1f,height/2);     
	glTranslatef(0.0f,-0.05f,0.00f);    
	drawCylinder(0.065f,0.05f);      
	glTranslatef(0.0f,0.05f,0.00f);      
	glRotatef(-90.0,1.0f,0.0f,0.0f);     
	glutSolidTorus(0.05f,0.05f,50,50); // Toro     
	glRotatef(90.0f,1.0f,0.0f,0.0f);      
	glTranslatef(0.0f,0.35f,0.00f);     
	glRotatef(90.0,1.0f,0.0f,0.0f);        
	drawCone(base,height*1.3);
	glRotatef(90.0,-1.0f,0.0f,0.0f);     
	glTranslatef(0.0f,-0.35f,0.00f);     
	glRotatef(-angleSh,1.0f,0.0f,0.0f);     
	glRotatef(45,0.0f,0.0f,1.0f);
	glTranslatef(-cx,-cy,-cz);   
}

// Funcion para dibujar pelota pixar
void drawPixarBall(){
	glPushMatrix();
	glTranslatef(0.5f,0.2f,0.0f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluQuadricTexture(quadric, GL_TRUE);
	gluSphere(quadric, 0.2f, 20, 20);
	gluDeleteQuadric(quadric);
	glPopMatrix();
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