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
	glTranslatef(-0.13f,0.3f,0.0f);
	glRotatef(90.0,1.0f,0.0f,0.0f);
	glutWireCone(base,height,200,200); // Cono
	glRotatef(90.0,-1.0f,0.0f,0.0f);
	glTranslatef(0.0f,-base/3,0.0f);
	glColor3f(1.0f,1.0f,0.0f);
	glutSolidSphere(base/3,50,50); // Bombilla
	glTranslatef(0.0f,base/3,0.0f);
	glTranslatef(0.13f,-0.3f,0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
}
void readTexture(const char *nombreFichero) {
	FILE *f;
	f = fopen(nombreFichero, "rb");
	if (f == NULL) {
		printf("Error al abrir el fichero %s\n", nombreFichero);
		exit(1);
	}
	fread(imagen, sizeof(unsigned char), 256*256*3, f);
	fclose(f);
}

// Textura esfera
void cargarTextura(GLuint &textura, const char *nombreFichero) {
	readTexture(nombreFichero);
	glGenTextures(1, &textura);
	glBindTexture(GL_TEXTURE_2D, textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen);
}
GLuint textura;

// Funcion para dibujar pelota pixar
void drawPixarBall(){
	cargarTextura(textura, "wood.bmp");
	glBindTexture(GL_TEXTURE_2D,textura);
	// Create the sphere
	glTranslatef(0.5f,0.2f,0.0f);
	glutSolidTeapot(0.1);
	/*glPushMatrix();
	glColor3f(0.0f,1.0f,0.0f);
	glTranslatef(0.5f,0.2f,0.0f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluQuadricTexture(quadric, GL_TRUE);
	gluSphere(quadric, 0.2f, 20, 20);
	gluDeleteQuadric(quadric);
	glPopMatrix();*/
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