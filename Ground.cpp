#include "Ground.hpp"


	#include <Windows.h>
	#include <GL/gl.h>



void Ground::draw() {
  
  glBegin(GL_LINES);
  
  for (int i = -1000; i <= 1000; i += 25) {

    glColor3f(i == 0 ? 0.0f : 0.5f, 0.5f, 0.5f);

    glVertex3f(i, 0, -1000);
    glVertex3f(i, 0, 1000);

    glVertex3f(-1000, 0, i);
    glVertex3f(1000, 0, i);
  }
  
  glEnd();

};

