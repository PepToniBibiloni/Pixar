#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Función para dibujar ejes de referencia
void referenceAxis();

void draw3dRectangle(GLfloat width,GLfloat height,GLfloat depth);

void drawTwo(GLfloat angle,GLfloat height, GLfloat thickness);

void drawCylinder(GLfloat base, GLfloat height);

void drawLamp(GLfloat base,GLfloat height);

void drawScrew(GLfloat base, GLfloat height);

void drawBase();

void dibujarLampara(GLfloat fAnguloRotacion,GLfloat fAnguloInferior);