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
GLfloat fAngRotacion=0.0f, fAnguloInferior=90.0f,fAngRotacionShade=0.0f;

// Cámara
glm::vec3 pos = glm::vec3(0.0f,1.5f,5.0f);
glm::vec3 front = glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f);
GLfloat pitch = 00.0f;
GLfloat yaw = 89.55f;

//Perspectivas
#define CENITAL 0
#define PICADO 1
#define NORMAL 2
#define CONTRAPICADO 3
#define NADIR 4
int perspective;
bool perspAct = false;

//Luces
GLfloat position[]={1.0f, 1.0f, 1.0f,1.0f };
bool shade = false; 

// Texturas
GLuint textures[2];

int menuNieb,menuPersp,menuL, mainMenu;
int menuFlag = 0;


void reshape(int w, int h);
void perspectiva(int p);
void Display();
void move(GLfloat speed);
void turn();
void inputKeyboard(unsigned char key, int x, int y);
void inputSpecialKeyboard(int key, int x, int y);
void Idle (void);