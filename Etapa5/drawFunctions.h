#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void referenceAxis();

void draw3dRectangle(GLfloat width,GLfloat height,GLfloat depth);

void drawTwo3DRectangles(GLfloat angle,GLfloat height, GLfloat thickness);

void drawCylinder(GLfloat base, GLfloat height);

void drawLampShade(GLfloat base,GLfloat height);

void drawScrew(GLfloat base, GLfloat height);

void drawBase();

void drawLamp(GLfloat fAnguloRotacion,GLfloat fAnguloInferior);