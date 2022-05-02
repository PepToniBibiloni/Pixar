// Etapa6.h
////////////////////////////////////////////////////
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "drawFunctions.cpp"
#include <glm/glm.hpp>
#include <string>

// Ventana
const int W_WIDTH = 500; 
const int W_HEIGHT = 500;
int height, width;

// Angulos Lampara
GLfloat fAngRotacion=0.0f, fAnguloInferior=90.0f,fAnguloLampara=0.0f;

// Cámara
glm::vec3 pos = glm::vec3(0.0f,1.5f,5.0f);
glm::vec3 front = glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f);
GLfloat pitch = 0.0f;
GLfloat yaw = 90.0f;

//Perspectivas
enum Perspective {Cenital,Picado,Normal,Contrapicado,Nadir};
Perspective perspective;
bool perspAct = false;

//Luces
GLfloat ambient[] = {0.0f, 0.0f, 0.0f, 1.0f };
GLfloat diffuse[] = {0.8f,0.8f, 0.8f, 1.0f };
GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat position[]={1.0f, 1.0f, 1.0f };
bool shade = false; 

void reshape(int w, int h);
void perspectiva(Perspective p);
void Display();
void move(GLfloat speed);
void turn();
void inputKeyboard(unsigned char key, int x, int y);
void inputSpecialKeyboard(int key, int x, int y);
void Idle (void);