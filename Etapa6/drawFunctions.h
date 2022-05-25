#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>
#include <SOIL.h>
#include <glm/glm.hpp>

GLfloat ambient[] = {0.0f, 0.0f, 0.0f, 1.0f };
GLfloat diffuse[] = {0.8f,0.8f, 0.8f, 1.0f };
GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
glm::vec3 lightPos = glm::vec3(0.0f,0.0f,0.0f);
GLbyte imagen[256][256][3];

void referenceAxis();

void draw3dRectangle(GLfloat width,GLfloat height,GLfloat depth);

void drawTwo3DRectangles(GLfloat angle,GLfloat height, GLfloat thickness);

void drawCylinder(GLfloat base, GLfloat height);

void drawLampShade(GLfloat base,GLfloat height,GLfloat rotation);

void drawScrew(GLfloat base, GLfloat height);

void drawBase();

void drawLamp(GLfloat fAnguloRotacion,GLfloat fAnguloInferior);