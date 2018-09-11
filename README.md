# MTRN2500Ass2

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415927

/* Initialize OpenGL Graphics */
void initGL() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClearDepth(1.0f);                   // Set background depth to farthest
glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
glShadeModel(GL_SMOOTH);   // Enable smooth shading
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

// Render a color-cube consisting of 6 quads with different colors
glLoadIdentity();                 // Reset the model-view matrix
glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen

glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
// Top face (y = 1.0f)
// Define vertices in counter-clockwise (CCW) order with normal pointing out
glColor3f(0.0f, 1.0f, 0.0f);     // Green
glVertex3f( 1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f,  1.0f);
glVertex3f( 1.0f, 1.0f,  1.0f);

// Bottom face (y = -1.0f)
glColor3f(1.0f, 0.5f, 0.0f);     // Orange
glVertex3f( 1.0f, -1.0f,  1.0f);
glVertex3f(-1.0f, -1.0f,  1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f( 1.0f, -1.0f, -1.0f);

// Front face  (z = 1.0f)
glColor3f(1.0f, 0.0f, 0.0f);     // Red
glVertex3f( 1.0f,  1.0f, 1.0f);
glVertex3f(-1.0f,  1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f( 1.0f, -1.0f, 1.0f);

// Back face (z = -1.0f)
glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
glVertex3f( 1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f,  1.0f, -1.0f);
glVertex3f( 1.0f,  1.0f, -1.0f);

// Left face (x = -1.0f)
glColor3f(0.0f, 0.0f, 1.0f);     // Blue
glVertex3f(-1.0f,  1.0f,  1.0f);
glVertex3f(-1.0f,  1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f,  1.0f);

// Right face (x = 1.0f)
glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
glVertex3f(1.0f,  1.0f, -1.0f);
glVertex3f(1.0f,  1.0f,  1.0f);
glVertex3f(1.0f, -1.0f,  1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
glEnd();  // End of drawing color-cube

// Render a pyramid consists of 4 triangles
glLoadIdentity();                  // Reset the model-view matrix
glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen

glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
// Front
glColor3f(1.0f, 0.0f, 0.0f);     // Red
glVertex3f( 0.0f, 1.0f, 0.0f);
glColor3f(0.0f, 1.0f, 0.0f);     // Green
glVertex3f(-1.0f, -1.0f, 1.0f);
glColor3f(0.0f, 0.0f, 1.0f);     // Blue
glVertex3f(1.0f, -1.0f, 1.0f);

// Right
glColor3f(1.0f, 0.0f, 0.0f);     // Red
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f(0.0f, 0.0f, 1.0f);     // Blue
glVertex3f(1.0f, -1.0f, 1.0f);
glColor3f(0.0f, 1.0f, 0.0f);     // Green
glVertex3f(1.0f, -1.0f, -1.0f);

// Back
glColor3f(1.0f, 0.0f, 0.0f);     // Red
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f(0.0f, 1.0f, 0.0f);     // Green
glVertex3f(1.0f, -1.0f, -1.0f);
glColor3f(0.0f, 0.0f, 1.0f);     // Blue
glVertex3f(-1.0f, -1.0f, -1.0f);

// Left
glColor3f(1.0f,0.0f,0.0f);       // Red
glVertex3f( 0.0f, 1.0f, 0.0f);
glColor3f(0.0f,0.0f,1.0f);       // Blue
glVertex3f(-1.0f,-1.0f,-1.0f);
glColor3f(0.0f,1.0f,0.0f);       // Green
glVertex3f(-1.0f,-1.0f, 1.0f);
glEnd();   // Done drawing the pyramid

glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
// Compute aspect ratio of the new window
if (height == 0) height = 1;                // To prevent divide by 0
GLfloat aspect = (GLfloat)width / (GLfloat)height;

// Set the viewport to cover the new window
glViewport(0, 0, width, height);

// Set the aspect ratio of the clipping volume to match the viewport
glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
glLoadIdentity();             // Reset
// Enable perspective projection with fovy, aspect, zNear and zFar
gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv);            // Initialize GLUT
glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
glutInitWindowSize(640, 480);   // Set the window's initial width & height
glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
glutCreateWindow(title);          // Create window with the given title
glutDisplayFunc(display);       // Register callback handler for window re-paint event
glutReshapeFunc(reshape);       // Register callback handler for window re-size event
initGL();                       // Our own OpenGL initialization
glutMainLoop();                 // Enter the infinite event-processing loop
return 0;
}

/************************** draw_cylinder() **************************
 * This function will draw the cylinder
 *
 *   @parameter1: radius = The radius of cylinder
 *   @parameter2: height = Height of the cylinder
 *   @parameter3: R = Red value of the cylinder's color
 *   @parameter4: G = Green value of the cylinder's color
 *   @parameter5: B = Blue value of the cylinder's color
 *
 *   @return: Nothing
 */
void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
    
    /** Draw the tube */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        glVertex3f(x, y , 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();
    
    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

/**************************** display() ******************************
 * The glut callback function to draw the polygons on the screen.
 *
 *   @parameter1: Nothing
 *
 *   @return: Nothing
 */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0,-0.4,-3.0);
    glRotatef(-40, 1.0, 0.0, 0.0);
    
    draw_cylinder(0.3, 1.0, 255, 160, 100);
    
    glFlush();
}

/**************************** reshape() ******************************
 * The glut callback function that responsible when the window is
 * resized.
 *
 *   @parameter1: width  = Current window's width
 *   @parameter2: height = Current window's height
 *
 *   @return: Nothing
 */
void reshape(int width, int height)
{
    if (width == 0 || height == 0) return;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width/(GLdouble)height,
                   0.5, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
}

int main(int argc, char **argv)
{
    /** Initialize glut */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Create Cylinder");
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}

void triangularPrism()
{
glBegin(GL_QUADS);
glVertex3f(0.5, 0, 0.5);
glVertex3f(0.5, 0, -0.5);
glVertex3f(-0.5, 0, -0.5);
glVertex3f(-0.5, 0, 0.5);

glVertex3f(0.5,0,-0.5);
glVertex3f(0.5,1,-0.5);
glVertex3f(-0.5,1,-0.5);
glVertex3f(-0.5,0,-0.5);

glVertex3f(0.5,1,-0.5);
glVertex3f(-0.5,1,-0.5);
glVertex3f(-0.5,0,0.5);
glVertex3f(0.5,0,0.5);
glEnd();
glBegin(GL_TRIANGLES);
glVertex3f(0.5,0,0.5);
glVertex3f(0.5,1,-0.5);
glVertex3f(0.5,0,-0.5);

glVertex3f(-0.5,0,0.5);
glVertex3f(-0.5,1,-0.5);
glVertex3f(-0.5,0,-0.5);
glEnd();
}

glPushMatrix();
glTranslated(1.5,1.1,2.75);
glRotated(180,0,1,0);
glRotated(flapsDegree, -1,0,0);
glScaled(0.5,0.8,0.1);
triangularPrism();
glPopMatrix();
