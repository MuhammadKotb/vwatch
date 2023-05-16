#include "SDL2/SDL_opengl.h"
#include <Drawer.h>



void vw::drawScene() {
    glLineWidth(2);
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(10, 20, 0);
    glVertex3f(50, 30, 0);
    glVertex3f(40, 80, 0);
    glEnd();
}

    
void vw::drawTriangle(vw::Triangle triangle, vw::ColorNorm color) {
    glBegin(GL_TRIANGLES);
    glColor3f(color.r, color.g, color.b);
    glVertex2f(triangle.x0, triangle.y0);
    glVertex2f(triangle.x1, triangle.y1);
    glVertex2f(triangle.x2, triangle.y2);
    glEnd();
}