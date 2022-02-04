#include <iostream>
#include <cstdlib>
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "SOIL/src/SOIL.h"
using namespace std;
struct Pointd
{
    int u,v;
};

struct Pointf
{
    int x,y;
};

/////GLOBAL VARIABLE INIT////////
int numObject;
int Wf = 640;
int Hf = 480;
double xMin = -12.0,xMax = 12.0,yMin = -9.0,yMax = 9.0;
float eyex = 2.0,eyey = 1.0,eyez = 2.0;
float ratio = Wf / (float)Hf;
int rotationX,rotationY;
GLuint cube_texture;
bool texture_loaded = false;
////////////////////////////////

void loadTexture(const char* textureName)
{
    int width,height,channels;
    unsigned char* cube_image = SOIL_load_image(textureName, &width, &height,
                &channels, SOIL_LOAD_AUTO );

	if(cube_image == 0)
    {
        cout << "Error,could not load texture!" << endl;

    }
    texture_loaded = true;
    glGenTextures(1, &cube_texture);
    glBindTexture(GL_TEXTURE_2D, cube_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D( GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, cube_image );


}

void initGL(int argc,char * argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize( Wf, Hf );
    glutInitWindowPosition( 10, 10 );
    glutCreateWindow("Project");
    glEnable(GL_DEPTH_TEST);

}
void init()
{

    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    glEnable( GL_DEPTH_TEST );
    glShadeModel( GL_SMOOTH );
    glEnable( GL_NORMALIZE );
    glClearColor( 0.1f, 0.1f, 0.1f, 0.0f);
    glViewport( 0, 0, Wf, Hf );

}


void drawCube()
{
    glBegin(GL_POLYGON);
            glColor3f( 1.0, 1.0, 0.5 );

            glTexCoord2f( 1.0f, 1.0f );
            glVertex3f(  0.5, -0.5, -0.5 );
            glTexCoord2f( 0.0f, 1.0f );
            glVertex3f(  0.5,  0.5, -0.5 );
            glTexCoord2f( 0.0f, 0.0f );
            glVertex3f( -0.5,  0.5, -0.5 );
            glTexCoord2f( 1.0f, 0.0f );
            glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        glBegin(GL_POLYGON);
              glColor3f(   1.0,  1.0, 1.0 );

            glTexCoord2f( 1.0f, 1.0f );
            glVertex3f(  0.5, -0.5, 0.5 );
            glTexCoord2f( 0.0f, 1.0f );
            glVertex3f(  0.5,  0.5, 0.5 );
            glTexCoord2f( 0.0f, 0.0f );
            glVertex3f( -0.5,  0.5, 0.5 );
            glTexCoord2f( 1.0f, 0.0f );
            glVertex3f( -0.5, -0.5, 0.5 );
        glEnd();

        glBegin(GL_POLYGON);
          glColor3f(  1.0,  0.0,  1.0 );

          glTexCoord2f( 1.0f, 1.0f );
          glVertex3f( 0.5, -0.5, -0.5 );
          glTexCoord2f( 0.0f, 1.0f );
          glVertex3f( 0.5,  0.5, -0.5 );
          glTexCoord2f( 0.0f, 0.0f );
          glVertex3f( 0.5,  0.5,  0.5 );
          glTexCoord2f( 1.0f, 0.0f );
          glVertex3f( 0.5, -0.5,  0.5 );
        glEnd();

        glBegin(GL_POLYGON);
          glColor3f(   0.0,  1.0,  0.0 );

          glTexCoord2f( 1.0f, 1.0f );
          glVertex3f( -0.5, -0.5,  0.5 );
          glTexCoord2f( 0.0f, 1.0f );
          glVertex3f( -0.5,  0.5,  0.5 );
          glTexCoord2f( 0.0f, 0.0f );
          glVertex3f( -0.5,  0.5, -0.5 );
          glTexCoord2f( 1.0f, 0.0f );
          glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        glBegin(GL_POLYGON);
          glColor3f(   0.0,  0.0,  1.0 );

          glTexCoord2f( 1.0f, 1.0f );
          glVertex3f(  0.5,  0.5,  0.5 );
          glTexCoord2f( 0.0f, 1.0f );
          glVertex3f(  0.5,  0.5, -0.5 );
          glTexCoord2f( 0.0f, 0.0f );
          glVertex3f( -0.5,  0.5, -0.5 );
          glTexCoord2f( 1.0f, 0.0f );
          glVertex3f( -0.5,  0.5,  0.5 );
        glEnd();

        glBegin(GL_POLYGON);
          glColor3f(   1.0,  0.0,  0.0 );

          glTexCoord2f( 1.0f, 1.0f );
          glVertex3f(  0.5, -0.5, -0.5 );
          glTexCoord2f( 0.0f, 1.0f );
          glVertex3f(  0.5, -0.5,  0.5 );
          glTexCoord2f( 0.0f, 0.0f );
          glVertex3f( -0.5, -0.5,  0.5 );
          glTexCoord2f( 1.0f, 0.0f );
          glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

}

void drawPyramid()
{

glBegin( GL_TRIANGLES );
glColor3f( 1.0f, 0.0f, 0.0f ); glVertex3f( 0.0f, 1.f, 0.0f );
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, 1.0f );
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 1.0f, -1.0f, 1.0f);

glColor3f( 1.0f, 0.0f, 0.0f ); glVertex3f( 0.0f, 1.0f, 0.0f);
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, 1.0f);
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 0.0f, -1.0f, -1.0f);

glColor3f( 1.0f, 0.0f, 0.0f ); glVertex3f( 0.0f, 1.0f, 0.0f);
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f( 0.0f, -1.0f, -1.0f);
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 1.0f, -1.0f, 1.0f);


glColor3f( 1.0f, 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, 1.0f);
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f( 0.0f, -1.0f, -1.0f);
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 1.0f, -1.0f, 1.0f);

glEnd();

}

void drawAxis()
{

glBegin(GL_LINES);

  glColor3f(1, 0, 0);
  glVertex3f(-1, -1, -1);
  glVertex3f( 1, -1, -1);

  glColor3f(0, 1, 0);
  glVertex3f(-1, -1, -1);
  glVertex3f(-1,  1, -1);

  glColor3f(0, 0, 1);
  glVertex3f(-1, -1, -1);
  glVertex3f(-1, -1,  1);
glEnd();

}

void displayFunction()
{

////////SET THE SCENE/////////

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35.0,ratio,0.1,50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 5.0, 3.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0,0.0 );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //setting up some materials
    float ambientMaterial[] = {0.7f,0.7f,0.7f,1.0f };
    float diffuseMaterial[] = { 1.0f,1.6f,1.0,1.0f };
    float specularMaterial[] = { 1.0f,1.0f,1.0f};
    float shininessMaterial[] = {50.0f};
    glMaterialfv(GL_FRONT,GL_AMBIENT,ambientMaterial);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuseMaterial);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specularMaterial);
    glMaterialfv(GL_FRONT,GL_SHININESS,shininessMaterial);
    //setting up some lights

    float lightPosition[] = { 2.0f, 5.0f, 2.0f, 20.0f};
    float lightIntensity[] = {1.0f, 1.0f, 1.0f, 1.0f} ;
    glLightfv(GL_LIGHT0,GL_POSITION,lightPosition);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE,cube_texture);
    glPushMatrix();

        drawAxis();
        glRotatef(rotationX,1,0,0); //apply X rotations
        glRotatef(rotationY,0,1,0); //apply Y rotations
        switch(numObject)
        {
            case 1:drawCube();
                break;
            case 2: drawPyramid();
                break;
           default:drawCube();
        }
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glFlush();
glutSwapBuffers();
}
//Function that will be passed to call back for rotation!
void rotate(int key, int x,int y)
{

    if(key == GLUT_KEY_LEFT)
        rotationY += 5;
    if(key == GLUT_KEY_RIGHT)
        rotationY += -5;
    if(key == GLUT_KEY_UP)
        rotationX += 5;
    if(key == GLUT_KEY_DOWN)
        rotationX += -5;;
    cout << "Coordinates :  " << rotationX << "," << rotationY << endl;
    glutPostRedisplay();
}
void objMenuFunction(int value)
{
    numObject = value;
    glutPostRedisplay();
}
void keyboardFunction(unsigned char key,int x, int y)
{
    switch(key)
    {
       case 'w' : if(!texture_loaded)
       {

           loadTexture("texture.png");
           glutPostRedisplay();
       }

       else {  
            glDeleteTextures(1,&cube_texture);
            glutPostRedisplay();
            texture_loaded = false; 
        }
        break;
    }
}

void taimerFunc(int useless)
{

    glutTimerFunc(useless,taimerFunc,useless);


}

void mainMenuFunction(int i)
{

}
int main(int argc,char * argv[])
{
    /////VARIOUS INITIALISATIONS/////
    initGL( argc, argv);
    init();

    //////////////MENU CREATION/////////////
    cout << "Execution complete!" << endl;

    int objectMenuId = glutCreateMenu(objMenuFunction);
    glutAddMenuEntry("Cube",1);
    glutAddMenuEntry("Pyramid",2);
    glutCreateMenu(mainMenuFunction);
    glutAddSubMenu("Objects",objectMenuId);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

//////////////////////////////////////////////

//////////CALLBACK FUNCTIONS/////////////////
    glutDisplayFunc(displayFunction);
    glutKeyboardFunc(keyboardFunction);
    glutSpecialFunc(rotate);
    //glutTimerFunc(0,taimerFunc,60);
    glutMainLoop();

//////END//////////////////////////////////
    return 0;
}
