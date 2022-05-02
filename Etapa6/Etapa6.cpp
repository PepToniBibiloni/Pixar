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
void perspectiva(Perspective p) {
	switch (p){
        case Cenital:
			gluLookAt(0,3,0.15,0,0,0,0,1,0); 
            break;
        case Picado:
            gluLookAt(0,2.5,3,0,0,0,0,1,0);
            break;
        case Normal:
            gluLookAt(0,1.3,4,0,0,0,0,1,0);  
            break;
        case Contrapicado:
            gluLookAt(0,-1.5,3,0,0,0,0,1,0); 
            break;
        case Nadir:
            gluLookAt(0,-2,0.15,0,0,0,0,1,0);
            break;
	}
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
	glTranslatef(position[0], position[1], position[2]); // Trasladamos el objeto
	glLightfv(GL_LIGHT0, GL_POSITION, position); // Actualizamos la posici�n de la luz
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); // Actualizamos el color ambiente
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular); // Actualizamos el color especular	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse); // Actualizamos el color difuso
	glColor3f(1.0f, 1.0f, 0.0f); 
	glutSolidSphere(0.1f, 50, 50); // Dibujamos una esfera
	glPopMatrix(); // Restauramos la matriz de modelado
	referenceAxis(); // Dibujamos los ejes de referencia
    drawLamp(fAngRotacion,fAnguloInferior); // Dibujamos la lampara
	drawPixarBall(); // Dibujamos la bola de pixar
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
		case 'o': // Mover lampara arriba
			fAnguloInferior += 0.5f;
			break;
		case 'l': // Mover lampara abajo
			fAnguloInferior -= 0.5f;
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
        case GLUT_KEY_F1: // Cambiamos a perspectiva Cenital
            perspective = Cenital;
            perspAct = true;
            break;
        case GLUT_KEY_F2: // Cambiamos a perspectiva Picado
            perspAct = true;
            perspective = Picado;
            break;
        case GLUT_KEY_F3: // Cambiamos a perspectiva Normal
            perspAct = true;
            perspective = Normal;
            break;
        case GLUT_KEY_F4: // Cambiamos a perspectiva Contrapicado
            perspAct = true;
            perspective = Contrapicado;
            break;
        case GLUT_KEY_F5: // Cambiamos a perspectiva Nadir
            perspAct = true;
            perspective = Nadir;
            break;
	}
	glutPostRedisplay();
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

	glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    //Renderización de luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Materiales
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// Texturas
	glEnable(GL_TEXTURE_2D);

	// Comienza la ejecuci�n del core de GLUT
	glutMainLoop();
	return 0; 
}