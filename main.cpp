#include "GL/freeglut.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include "vecmath.h"
using namespace std;

// Globals

// This is the list of points (3D vectors)
vector<Vector3f> vecv;

// This is the list of normals (also 3D vectors)
vector<Vector3f> vecn;

// This is the list of faces (indices into vecv and vecn)
vector<vector<unsigned> > vecf;


// You will need more global variables to implement color and position changes

//color changing variable
int colorChange = 0;
//GLfloat lightX = 0.0f;
//GLfloat lightY = 0.0f;
GLfloat lightPos[] = {1.0f, 1.0f, 5.0f, 1.0f};
GLfloat rtr = 2.0f;
bool spin = false;
bool fade = false;
int fader = 1;
    GLfloat diffColors[11][4] = { {0.5, 0.5, 0.9, 1.0},
                                 {0.9, 0.5, 0.5, 1.0},
                                 {0.5, 0.9, 0.3, 1.0},
                                 {0.3, 0.8, 0.9, 1.0}, 
                                 {0.4, 0.8, 0.3, 1.0},
                                 {0.7, 0.06, 0.6, 1.0},
                                 {0.9, 0.5, 0.1, 1.0},
                                 {1.0, 1.0, 0.1, 1.0},
                                 {0.3, 0.9, 0.7, 1.0},
                                 {0.4, 0.03, 0.6, 1.0},
                                 {0.4, 0.3, 0.2, 1.0} };
    GLfloat* thisColor = diffColors[colorChange];
int init_mouse_x = 0;
int init_mouse_y = 0;
int cur_mouse_x = 0;
int cur_mouse_y = 0;
float cam_pos[3] = {0.0,0.0,5.0};

// These are convenience functions which allow us to call OpenGL 
// methods on Vec3d objects
//inline void glVertex(const Vector3f &a) 
//{ glVertex3fv(a); }

//inline void glNormal(const Vector3f &a) 
//{ glNormal3fv(a); }

//updates the spin value
void updateSpin(int val){
    cout<<"updateSpin()"<<endl;
    rtr+=2.0f;
    if(rtr >= 360.0f){
        rtr = 0.0f;
    }
    glutTimerFunc(500,updateSpin,100);
    glutPostRedisplay();
}

void updateColor(int val){
    cout<<"updateColor"<<endl;
    fader += 1;
    if (fader ==100){
        fade = false;
        fader = 1; 
        thisColor[0] = diffColors[colorChange][0];
        thisColor[1] = diffColors[colorChange][1];
        thisColor[2] = diffColors[colorChange][2];
        thisColor[3] = diffColors[colorChange][3];
        thisColor[4] = diffColors[colorChange][4];
        thisColor[5] = diffColors[colorChange][5];
        thisColor[6] = diffColors[colorChange][6];
        thisColor[7] = diffColors[colorChange][7];
        thisColor[8] = diffColors[colorChange][8];
        thisColor[9] = diffColors[colorChange][9];
        thisColor[10] = diffColors[colorChange][10];
        cout <<"The Color fades away now"<<endl;
    } else{
        if (colorChange == 0 ){
            float stepsize0 = (diffColors[3][0] - diffColors[colorChange][0])/100.0f;
            float stepsize1 = (diffColors[3][1] - diffColors[colorChange][1])/100.0f;
            float stepsize2 = (diffColors[3][2] - diffColors[colorChange][2])/100.0f;
            float stepsize3 = (diffColors[3][3] - diffColors[colorChange][3])/100.0f;
            float stepsize4 = (diffColors[3][4] - diffColors[colorChange][4])/100.0f;
            float stepsize5 = (diffColors[3][5] - diffColors[colorChange][5])/100.0f;
            float stepsize6 = (diffColors[3][6] - diffColors[colorChange][6])/100.0f;
            float stepsize7 = (diffColors[3][7] - diffColors[colorChange][7])/100.0f;
            float stepsize8 = (diffColors[3][8] - diffColors[colorChange][8])/100.0f;
            float stepsize9 = (diffColors[3][9] - diffColors[colorChange][9])/100.0f;
            float stepsize10 = (diffColors[3][10] - diffColors[colorChange][10])/100.0f;
            thisColor[0] = thisColor[0] + stepsize0;
            thisColor[1] = thisColor[1] + stepsize1;
            thisColor[2] = thisColor[2] + stepsize2;
            thisColor[3] = thisColor[3] + stepsize3;
            thisColor[4] = thisColor[4] + stepsize4;
            thisColor[5] = thisColor[4] + stepsize5;
            thisColor[6] = thisColor[4] + stepsize6;
            thisColor[7] = thisColor[4] + stepsize7;
            thisColor[8] = thisColor[4] + stepsize8;
            thisColor[9] = thisColor[4] + stepsize9;
            thisColor[10] = thisColor[4] + stepsize10;
        } else{
            float stepsize0 = (diffColors[colorChange][0] - diffColors[colorChange-1][0])/100.0f;
            float stepsize1 = (diffColors[colorChange][1] - diffColors[colorChange-1][1])/100.0f;
            float stepsize2 = (diffColors[colorChange][2] - diffColors[colorChange-1][2])/100.0f;
            float stepsize3 = (diffColors[colorChange][3] - diffColors[colorChange-1][3])/100.0f;
            float stepsize4 = (diffColors[colorChange][4] - diffColors[colorChange-1][4])/100.0f;
            float stepsize5 = (diffColors[colorChange][5] - diffColors[colorChange-1][5])/100.0f;
            float stepsize6 = (diffColors[colorChange][6] - diffColors[colorChange-1][6])/100.0f;
            float stepsize7 = (diffColors[colorChange][7] - diffColors[colorChange-1][7])/100.0f;
            float stepsize8 = (diffColors[colorChange][8] - diffColors[colorChange-1][8])/100.0f;
            float stepsize9 = (diffColors[colorChange][9] - diffColors[colorChange-1][9])/100.0f;
            float stepsize10 = (diffColors[colorChange][10] - diffColors[colorChange-1][10])/100.0f;
            thisColor[0] = thisColor[0] + stepsize0;
            thisColor[1] = thisColor[1] + stepsize1;
            thisColor[2] = thisColor[2] + stepsize2;
            thisColor[3] = thisColor[3] + stepsize3;
            thisColor[4] = thisColor[4] + stepsize4;
            thisColor[5] = thisColor[4] + stepsize5;
            thisColor[6] = thisColor[4] + stepsize6;
            thisColor[7] = thisColor[4] + stepsize7;
            thisColor[8] = thisColor[4] + stepsize8;
            thisColor[9] = thisColor[4] + stepsize9;
            thisColor[10] = thisColor[4] + stepsize10;
        }
        glutTimerFunc(10, updateColor, 10);
        glutPostRedisplay();
    }

}

//Mouse Controls

void mouseFunc(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        init_mouse_x = x;
        init_mouse_y = y;
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        cout<<"buttons"<<endl;
    }
}

void mouseMotion (int x,int y){
    cur_mouse_x = x;
    cur_mouse_y = y;
    float angle = (cur_mouse_x-init_mouse_x)/100.0f;
    float zoom = (cur_mouse_y-init_mouse_y)/1000.0f;
    
    if (zoom > 0.0){
        if (cam_pos[2] > 15.0){
        } else {
            cam_pos[2] += zoom;
        }
    } else{
        if (cam_pos[2] < 3.0){
            
        } else{
            cam_pos[2] += zoom;
        }
    }

    rtr += angle;
    glutPostRedisplay();
}

// This function is called whenever a "Normal" key press is received.
void keyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 27: // Escape key
        exit(0);
        break;
    case 'c':
        // add code to change color here
        //RGB MODE
        //colorChange += 1;
        if (!fade){
            fade = true;
            colorChange = (colorChange+1)%3;
            glutTimerFunc(10, updateColor, 10);
        }
        break;
    case 'r':
    //Spin time
    cout<<"spinning!"<<endl;
    spin = true;
    glutTimerFunc(500,updateSpin,100);
    break;
    default:
        cout << "Unhandled key press " << key << "." << endl;        
    }

	// this will refresh the screen so that the user sees the color change
    glutPostRedisplay();
}

// This function is called whenever a "Special" key press is received.
// Right now, it's handling the arrow keys.
void specialFunc( int key, int x, int y )
{
    switch ( key )
    {
    case GLUT_KEY_UP:
        // add code to change light position
        //lightY += 0.5f; 
        //cout << "Unhandled key press: up arrow." << endl;
		lightPos[1] = lightPos[1]-0.5;
		break;

    case GLUT_KEY_DOWN:
        // add code to change light position
        //lightY -= 0.5f; 
		//cout << "Unhandled key press: down arrow." << endl;
        lightPos[1] = lightPos[1]+0.5;
		break;

    case GLUT_KEY_LEFT:
        // add code to change light position
        //lightX -= 0.5f;
		//cout << "Unhandled key press: left arrow." << endl;
        lightPos[0] = lightPos[0]-0.5;
		break;
    case GLUT_KEY_RIGHT:
        // add code to change light position
        //lightX += 0.5f;
		//cout << "Unhandled key press: right arrow." << endl;
        lightPos[0] = lightPos[0]+0.5;
		break;
    }

	// this will refresh the screen so that the user sees the light position
    glutPostRedisplay();
}

// This function is responsible for displaying the object.
void drawScene(void)
{
    int i;

    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Rotate the image
    glMatrixMode( GL_MODELVIEW );  // Current matrix affects objects positions
    glLoadIdentity();              // Initialize to the identity

    // Position the camera at [0,0,5], looking at [0,0,0],
    // with [0,1,0] as the up direction.
    gluLookAt(cam_pos[0], cam_pos[1], cam_pos[2],
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    // Set material properties of object

	// Here are some colors you might use - feel free to add more
  /*  GLfloat diffColors[11][4] = { {0.5, 0.5, 0.9, 1.0},
                                 {0.9, 0.5, 0.5, 1.0},
                                 {0.5, 0.9, 0.3, 1.0},
                                 {0.3, 0.8, 0.9, 1.0}, 
                                 {0.4, 0.8, 0.3, 1.0},
                                 {0.7, 0.06, 0.6, 1.0},
                                 {0.9, 0.5, 0.1, 1.0},
                                 {1.0, 1.0, 0.1, 1.0},
                                 {0.3, 0.9, 0.7, 1.0},
                                 {0.4, 0.03, 0.6, 1.0},
                                 {0.4, 0.3, 0.2, 1.0} };
    */

	// Here we use the first color entry as the diffuse color
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, thisColor );

	// Define specular color and shininess
    GLfloat specColor[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {100.0};

	// Note that the specular color and shininess can stay constant
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
  
    // Set light properties

    // Light color (RGBA)
    GLfloat Lt0diff[] = {1.0,1.0,1.0,1.0};
    // Light position
	//GLfloat Lt0pos[] = {1.0f, 1.0f, 5.0f, 1.0f};
    GLfloat Lt0pos[] = {lightPos[0], lightPos[1], lightPos[2],lightPos[3]};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
    glLightfv(GL_LIGHT0, GL_POSITION, Lt0pos);

	// This GLUT method draws a teapot.  You should replace
	// it with code which draws the object you loaded.
	//glutSolidTeapot(1.0);

    glPushMatrix();
    glRotatef(rtr,0.0f,1.0f,0.0f);

    for (unsigned int k = 0; k < vecf.size(); k++) {
         //do something with v[0], v[1], v[2]
         int a = vecf[k][0];
         int c = vecf[k][1];
         int d = vecf[k][2];
         int f = vecf[k][3];
         int g = vecf[k][4];
         int i = vecf[k][5];
         glBegin(GL_TRIANGLES);
         glNormal3d(vecn[c - 1][0], vecn[c - 1][1], vecn[c - 1][2]);
         glVertex3d(vecv[a - 1][0], vecv[a - 1][1], vecv[a - 1][2]);
         glNormal3d(vecn[f - 1][0], vecn[f - 1][1], vecn[f - 1][2]);
         glVertex3d(vecv[d - 1][0], vecv[d - 1][1], vecv[d - 1][2]);
         glNormal3d(vecn[i - 1][0], vecn[i - 1][1], vecn[i - 1][2]);
         glVertex3d(vecv[g - 1][0], vecv[g - 1][1], vecv[g - 1][2]);
         glEnd();
    }
    
    // Dump the image to the screen.
    glutSwapBuffers();


}

// Initialize OpenGL's rendering modes
void initRendering()
{
    glEnable(GL_DEPTH_TEST);   // Depth testing must be turned on
    glEnable(GL_LIGHTING);     // Enable lighting calculations
    glEnable(GL_LIGHT0);       // Turn on light #0.
}

// Called when the window is resized
// w, h - width and height of the window in pixels.
void reshapeFunc(int w, int h)
{
    // Always use the largest square viewport possible
    if (w > h) {
        glViewport((w - h) / 2, 0, h, h);
    } else {
        glViewport(0, (h - w) / 2, w, w);
    }

    // Set up a perspective view, with square aspect ratio
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 50 degree fov, uniform aspect ratio, near = 1, far = 100
    gluPerspective(50.0, 1.0, 1.0, 100.0);
}



void loadInput()
{
	// load the OBJ file here

      string s;
      int MAX_BUFFER_SIZE = 100;
      char buffer[100];
      Vector3f v;

      while (true){
        cin.getline(buffer, MAX_BUFFER_SIZE);
        stringstream ss(buffer);
        ss >> s;
        if (s == "g"){
            break;
        }
    }

     while (true){
        cin.getline(buffer, MAX_BUFFER_SIZE );
        stringstream ss(buffer);
        if ( ss.rdbuf()->in_avail() == 0 ){
            break;
        }
        ss >> s;
        if (s == "v"){
            ss >> v[0] >> v[1] >> v[2];
            vecv.push_back(Vector3f(v[0],v[1],v[2]));
        } else if (s == "vn") {
            ss >> v[0] >> v[1] >> v[2];
            vecn.push_back(Vector3f(v[0],v[1],v[2]));
        } else if (s == "f") {
            int a, b, c, d, e, f, g, h, i;
            char cHolder; 
            vector<unsigned> vectorHolder;
            ss >> a >> cHolder >> b >> cHolder >> c;
            ss >> d >> cHolder >> e >> cHolder >> f;
            ss >> g >> cHolder >> h >> cHolder >> i;
            vectorHolder.push_back(a);
            vectorHolder.push_back(c);
            vectorHolder.push_back(d);
            vectorHolder.push_back(f);
            vectorHolder.push_back(g);
            vectorHolder.push_back(i);
            vecf.push_back(vectorHolder);
        }
    }
       
          

}

// Main routine.
// Set up OpenGL, define the callbacks and start the main loop
int main( int argc, char** argv )
{
    loadInput();

    glutInit(&argc,argv);

    // We're going to animate it, so double buffer 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    // Initial parameters for window position and size
    glutInitWindowPosition( 60, 60 );
    glutInitWindowSize( 360, 360 );
    glutCreateWindow("Assignment 0");

    // Initialize OpenGL parameters.
    initRendering();

    // Set up callback functions for key presses
    glutKeyboardFunc(keyboardFunc); // Handles "normal" ascii symbols
    glutSpecialFunc(specialFunc);   // Handles "special" keyboard keys

     // Set up callback functions for mouse press
    glutMouseFunc(mouseFunc);

    // Set up callback function for tracking mouse movement
    glutMotionFunc(mouseMotion);

     // Set up the callback function for resizing windows
    glutReshapeFunc( reshapeFunc );

    // Call this whenever window needs redrawing
    glutDisplayFunc( drawScene );

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop( );

    return 0;	// This line is never reached.
}
