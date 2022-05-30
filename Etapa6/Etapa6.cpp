// Etapa6.cpp
// Fichero principal 
////////////////////////////////////////////////////
#include "Etapa6.h"
// Funci�n que visualiza la escena OpenGL
void reshape(int w, int h) {
    height=h;
    width=w;
	if (h == 0) h = 1;
    glViewport(0, 0, w, h); // Establecemos el viewport
    glMatrixMode(GL_PROJECTION);  // Seleccionamos la matriz de proyecci�n
	glLoadIdentity(); // Reseteamos la matriz de proyecci�n
	gluPerspective(45.0f,(GLfloat)w/(GLfloat)h, 0.1, 1000); // Establecemos la proyecci�n perspectiva
    glMatrixMode(GL_MODELVIEW); // Seleccionamos la matriz de modelado/visionado
}
// Función perspectiva
void perspectiva(int p) {
	switch (p){
        case CENITAL:
			gluLookAt(0,3,0.15,0,0,0,0,1,0); 
            break;
        case PICADO:
            gluLookAt(0,2.5,3,0,0,0,0,1,0);
            break;
        case NORMAL:
            gluLookAt(0,1.3,4,0,0,0,0,1,0);  
            break;
        case CONTRAPICADO:
            gluLookAt(0,-1.5,3,0,0,0,0,1,0); 
            break;
        case NADIR:
            gluLookAt(0,-2,0.15,0,0,0,0,1,0);
            break;
		default:
			perspAct=false;
			break;
	}
}
GLuint texture(const char* file){
	return SOIL_load_OGL_texture(
	file,
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

}

void initTexture(int i){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[i]);
	GLfloat plano_s[4] = {2, 0, 0, 0}; // s=x
	GLfloat plano_t[4] = {0, 2, 0, 0}; // t=y
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glTexGeni (GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv (GL_S, GL_OBJECT_PLANE, plano_s);
	glEnable (GL_TEXTURE_GEN_S);
	glTexGeni (GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv (GL_T, GL_OBJECT_PLANE, plano_t);
	glEnable (GL_TEXTURE_GEN_T);
}

void initTextureSphere(int i){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[i]);
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glTexGeni (GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable (GL_TEXTURE_GEN_S);
	glTexGeni (GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable (GL_TEXTURE_GEN_T);
}

void finishTexture(){
	glBindTexture(GL_TEXTURE_2D,0);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_2D);
}
// Funci�n que visualiza la escena OpenGL
void Display() {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Borramos la escena
    glLoadIdentity(); // Reseteamos la matriz de modelado
    if (!perspAct){ // Si no est� activada la perspectiva
        gluLookAt(pos.x,pos.y,pos.z,pos.x+front.x,pos.y+front.y,pos.z+front.z,up.x,up.y,up.z);
        glTranslatef(0.0, 0.5f, 0.0);
    }else{
        perspectiva(perspective);
    } 
    glPushMatrix(); // Guardamos la matriz de modelado

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); // Actualizamos el color ambiente
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular); // Actualizamos el color especular	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse); // Actualizamos el color difuso
	glPopMatrix(); // Restauramos la matriz de modelado
	//referenceAxis(); // Dibujamos los ejes de referencia
	drawLamp(fAngRotacion,fAnguloInferior,fAngRotacionShade); // Dibujamos la lampara

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	initTexture(0);
	drawFloor(2.0f,2.0f); // Dibujamos el suelo
	finishTexture();
	initTextureSphere(1);
	drawPixarBall(); // Dibujamos la bola de pixar
	finishTexture();
	initTexture(2);
	drawWalls(2.0f,2.0f,4.0f); // Dibujamos las paredes
	finishTexture();
	glutSwapBuffers(); // Intercambiamos los buffers de visualizaci�n
    glFlush(); // Limpiamos el buffer de visualizaci�n
}
// Funcion que mueve el objeto
void move(GLfloat speed){
	pos.x += front.x * speed; 
	pos.y += front.y * speed;
	pos.z += front.z * speed;
}

// Funcion que rota la camara
void turn(){
	front.x = (GLfloat) (sin(pitch)*sin(yaw));
	front.y = (GLfloat) cos(yaw);
	front.z = (GLfloat) (-cos(pitch)*sin(yaw));
}

// Función leer teclado
void inputKeyboard(unsigned char key, int x, int y){
	switch(key){
		case 'i': // Mover lampara arriba
			if(fAnguloInferior>75) fAnguloInferior -= 0.5f;
			break;
		case 'k': // Mover lampara abajo
			if(fAnguloInferior<120) fAnguloInferior += 0.5f;
			break;
		case 'j': // Mover lampara arriba
			if(fAngRotacionShade<100) fAngRotacionShade += 0.5f;
			break;
		case 'l': // Mover lampara abajo
			if(fAngRotacionShade>-100) fAngRotacionShade -= 0.5f;
			break;
		case '+': // Zoom in
			move(0.05f);
			break;
		case '-':  // Zoom out
			move(-0.05f);
			break;
		case '1': // Cambiamos sector especular
			specular[0] -= 0.1f; 
			specular[1] -= 0.1f;
			specular[2] -= 0.1f;
			break;

		case '2': // Cambiamos sector especular
			specular[0] += 0.1f;
			specular[1] += 0.1f;
			specular[2] += 0.1f;
			break;

		case '3': // Cambiamos sector ambiente
			ambient[0] -= 0.1f;
			ambient[1] -= 0.1f;
			ambient[2] -= 0.1f;
			break; 
		case '4': // Cambiamos sector ambiente
			ambient[0] += 0.1f;
			ambient[1] += 0.1f;
			ambient[2] += 0.1f;
			break;
		case '5': // Cambiamos sector difuso
			diffuse[0] -= 0.1f;
			diffuse[1] -= 0.1f;
			diffuse[2] -= 0.1f;
			break;
		case '6': // Cambiamos sector difuso
			diffuse[0] += 0.2f;
			diffuse[1] += 0.2f;
			diffuse[2] += 0.2f;
			break;
		case 'a': // Mover luz hacia la derecha
			position[0] += 0.1;
			break;
		case 'z': // Mover luz hacia la izquierda
			position[0] -= 0.1;
			break;
		case 's': // Mover luz hacia arriba
			position[1] += 0.1;
			break;
		case 'x': // Mover luz hacia abajo
			position[1] -= 0.1;
			break;
		case 'd': // Mover luz hacia atras
			position[2] += 0.1;
			break;
		case 'c': // Mover luz hacia delante
			position[2] -= 0.1;
			break;
		case ' ':  // Cambiamos tipo de sombreado
			shade = !shade; 
			if (shade) {
				glShadeModel(GL_FLAT);
				printf("Flat Shading\n");
			} else {
				glShadeModel(GLU_SMOOTH); 
				printf("Smooth Shading\n");
			}
			break;
	}
	glutPostRedisplay();
}

// Función leer teclado especial
void inputSpecialKeyboard(int key, int x, int y) {
	switch(key){
        case GLUT_KEY_UP:	// Mover camara hacia arriba
            yaw -= 0.02f;
			turn();
            break;
        case GLUT_KEY_DOWN: // Mover camara hacia abajo
            yaw += 0.02f;
			turn();
            break;
		case GLUT_KEY_LEFT: // Mover camara hacia la izquierda
			pitch -= 0.02f;
			turn();
			break;
		case GLUT_KEY_RIGHT: // Mover camara hacia la derecha
			pitch += 0.02f;
			turn();
			break;
	}
	glutPostRedisplay();
}
int xOrigin = -1;
int yOrigin = -1;

// Mouse move
void inputMouse(int x, int y){
	if (xOrigin >= 0){
		pitch -= (x - xOrigin) * 0.001f;
		yaw -= (y - yOrigin) * 0.001f;
	}
	xOrigin = x;
	yOrigin = y;
	turn();
	glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT) {
		if (state == GLUT_UP) {
			xOrigin = -1;
			yOrigin = -1;
		}else {
			xOrigin = x;
			yOrigin = y;
		}
	}
	if (button == 3){
		move(0.05f);
	}
	if (button == 4){
		move(-0.05f);
	}
}

void processMenuStatus(int status, int x, int y) {
	if (status == GLUT_MENU_IN_USE)
		menuFlag = 1;
	else
		menuFlag = 0;
}

void processMainMenu(int option) {
}

void processFillMenu(int option) {
	switch (option) {
		case 1: glEnable(GL_FOG); break;
		case 2: glDisable(GL_FOG); break;
	}
}

void menuPerspectiva(int opcion){
	perspective = opcion;
    if(opcion==-1) perspAct=false;
	else perspAct = true;    
}

void createPopupMenus() {

	fillMenu = glutCreateMenu(processFillMenu);
	glutAddMenuEntry("Con niebla", 1);
	glutAddMenuEntry("Sin niebla", 2);
	menuPersp = glutCreateMenu(menuPerspectiva);
	glutAddMenuEntry("Nadir",NADIR);
	glutAddMenuEntry("Cenital",CENITAL);
	glutAddMenuEntry("Contrapicado",CONTRAPICADO);
	glutAddMenuEntry("Normal",NORMAL);
	glutAddMenuEntry("Picado",PICADO);
	glutAddMenuEntry("Libre",-1);
	mainMenu = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Niebla", fillMenu);
	glutAddSubMenu("Perspectiva", menuPersp);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMenuStatusFunc(processMenuStatus);
}

// Funci�n que se ejecuta cuando el sistema no esta ocupado
void Idle (void)
{
	glutPostRedisplay();
}

// Funci�n principal
int main(int argc, char **argv) 
{
	// Inicializamos la librer�a GLUT
	glutInit (&argc, argv);

	// Indicamos como ha de ser la nueva ventana
	glutInitWindowPosition (100,100);
	glutInitWindowSize (W_WIDTH, W_HEIGHT);
	glutInitDisplayMode (GLUT_DEPTH | GLUT_RGBA | GLUT_SINGLE);

	// Creamos la nueva ventana
	glutCreateWindow ("Mi primera Ventana");

	// Indicamos cuales son las funciones de redibujado e idle
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutIdleFunc(Idle);
	
    glutKeyboardFunc(inputKeyboard);
    glutSpecialFunc(inputSpecialKeyboard);
	glutMotionFunc(inputMouse);
	glutMouseFunc(mouseButton);

	glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    //Renderización de luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	// Materiales
	glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// Niebla
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, 0.1);
	glFogf(GL_FOG_END,8.0);
	glFogf(GL_FOG_DENSITY,0.8);
	glHint(GL_FOG_HINT,GL_NICEST);
	float color[] = { 0.5,0.5,0.5,1.0};
	glFogfv(GL_FOG_COLOR, color);
	
	// Blend
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	createPopupMenus();

	// Texturas
	textures[0] = texture("wood.jpeg");
	textures[1] = texture("lamp.png");
	textures[2] = texture("wall.png");

	// Comienza la ejecuci�n del core de GLUT
	glutMainLoop();
	return 0; 
}