#include <GL/glut.h>
#include <cmath>

// Ball properties
float ballX = 450.0f; // Initial X Position (Center)
float ballY = 300.0f; // Initial Y Position (Center)
float ballRadius = 10.0f;
float xSpeed = 2.0f; // Horizontal speed
float ySpeed = 1.5f; // Vertical speed

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color
    gluOrtho2D(0, 900, 0, 600);       // Set 2D orthographic projection
}



// Function to draw an running truck
void DrawEllipse(float cx, float cy, float rx, float ry, int segments, bool filled) {
    if (filled)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(cx + rx * cos(angle), cy + ry * sin(angle));
    }
    glEnd();
}

// Function to draw a rectanglular feilds
void DrawRectangle(int x1, int y1, int x2, int y2, bool filled) {
    if (filled)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y2);
    glEnd();
}

// Function to draw a circlular feilds
void DrawCircle(float cx, float cy, float radius, int segments, bool filled) {
    if (filled)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd();
}

// Function to update ball position
void UpdateBall(int value) {
    // Update position
    ballX += xSpeed;
    ballY += ySpeed;

    // Collision with stadium boundaries
    if (ballX - ballRadius < 230 || ballX + ballRadius > 670) {
        xSpeed = -xSpeed; // Reverse X direction
    }
    if (ballY - ballRadius < 185 || ballY + ballRadius > 405) {
        ySpeed = -ySpeed; // Reverse Y direction
    }

    glutPostRedisplay(); // Redraw the screen
    glutTimerFunc(16, UpdateBall, 0); // 60 FPS
}

// Function to draw stadium stands
void DrawStadiumStands(float cx, float cy, float innerRadiusX, float innerRadiusY, float outerRadiusX, float outerRadiusY, int segments) {
    glPushMatrix();
    glTranslatef(cx, cy, 0); // Translate to the specified center

    // Draw the elliptical ring
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * i / segments;

        // Outer ring vertex
        glVertex2f(cos(theta) * outerRadiusX, sin(theta) * outerRadiusY);
        // Inner ring vertex
        glVertex2f(cos(theta) * innerRadiusX, sin(theta) * innerRadiusY);
    }
    glEnd();

    // Draw radial lines to segment the ring
    glColor3f(1.0f, 1.0f, 1.0f); // White color for lines
    glLineWidth(6);
    glBegin(GL_LINES);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * i / segments;

        // Line from outer to inner ellipse
        glVertex2f(cos(theta) * outerRadiusX, sin(theta) * outerRadiusY);
        glVertex2f(cos(theta) * innerRadiusX, sin(theta) * innerRadiusY);
    }
    glEnd();

    glPopMatrix();
}

//Function to draw player
void DrawPlayer(float x, float y) {
    // Head
    glColor3f(1.0, 0.8, 0.6); // Skin color
    DrawCircle(x, y + 58, 8, 50,true); // Head centered at (x, y+70)

    // Body
    glColor3f(0.5, 0.5, 0.5);
    DrawRectangle(x - 8, y + 30, x + 8, y + 50,true); // Body rectangle

    // Arms
    glBegin(GL_LINES);
    glVertex2f(x - 8, y + 45); glVertex2f(x - 33, y + 35); // Left arm
    glVertex2f(x + 8, y + 45); glVertex2f(x + 33, y + 35); // Right arm
    glEnd();

    // Legs
    glBegin(GL_LINES);
    glVertex2f(x - 5, y + 30); glVertex2f(x - 15, y); // Left leg
    glVertex2f(x + 5, y + 30); glVertex2f(x + 15, y); // Right leg
    glEnd();
}

//Function to display whole things
void DrawShape() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); // Save the current transformation state

    // Apply scaling
    glTranslatef(450, 300, 0);
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-450, -300, 0);

    
    // Filled Stadium Ellipse
    glColor3f(0.5f, 0.5f, 0.5f);
    DrawEllipse(450, 300, 670, 415, 100, true);
    glColor3f(1.0, 0.25, 0.1);
    DrawEllipse(450, 300, 450, 300, 100, true);
    
    // Multiple Stadium Outlines
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3);
    DrawEllipse(450, 300, 420, 280, 100, false);
    DrawEllipse(450, 300, 390, 250, 100, false);
    DrawEllipse(450, 300, 360, 220, 100, false);
    DrawEllipse(450, 300, 330, 190, 100, false);

    // Field Rectangles
    glColor3f(0.0, 1.0, 0.0);
    DrawRectangle(210, 170, 690, 420, true);
    glColor3f(0.0, 0.8, 0.1);
    DrawRectangle(230, 185, 270, 405, true);
    DrawRectangle(310, 185, 350, 405, true);
    DrawRectangle(390, 185, 430, 405, true);
    DrawRectangle(470, 185, 510, 405, true);
    DrawRectangle(550, 185, 590, 405, true);
    DrawRectangle(630, 185, 670, 405, true);
    glColor3f(1.0, 1.0, 1.0);
    DrawRectangle(230, 185, 670, 405, false); // Outer Field
    DrawRectangle(230, 215, 310, 375, false); // Left Goal Box
    DrawRectangle(590, 215, 670, 375, false); // Right Goal Box
    DrawRectangle(230, 255, 270, 335, false); // Left Small Box
    DrawRectangle(630, 255, 670, 335, false); // Right Small Box
    DrawRectangle(670, 265, 675, 325, false); // Right Small Box
    DrawRectangle(675, 265, 685, 325, false); // Right Small Box
    DrawRectangle(225, 265, 230, 325, false); // Right Small Box
    DrawRectangle(215, 265, 225, 325, false); // Right Small Box
    
    
    // Center Line
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(450, 185);
    glVertex2i(450, 405);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int i=0;i<60;i=i+5){
	    glVertex2i(675, 270+i);
	    glVertex2i(685, 270+i);
	    glVertex2i(215, 270+i);
	    glVertex2i(225, 270+i);
	}
	glVertex2i(678, 265);
    glVertex2i(678, 325);
    glVertex2i(682, 265);
    glVertex2i(682, 325);
    glVertex2i(218, 265);
    glVertex2i(218, 325);
    glVertex2i(222, 265);
    glVertex2i(222, 325);
    glEnd();

    // Center Circle
    glLineWidth(3);
    DrawCircle(450, 300, 35, 100, false);

    // Semi-Circles
    glBegin(GL_LINE_STRIP);
    for (int i = -90; i < 90; i++) {
        float angle = 2 * M_PI * i / 360;
        glVertex2f(310 + 25 * cos(angle), 300 + 25 * sin(angle));
    }
    glEnd();

	glBegin(GL_LINE_STRIP);
    for (int i = 90; i < 270; i++) {
        float angle = 2 * M_PI * i / 360;
        glVertex2f(590 + 25 * cos(angle), 300 + 25 * sin(angle));
    }
    glEnd();

    // Small Circles
    DrawCircle(450, 300, 5, 50, true);
    DrawCircle(290, 300, 3, 50, true);
    DrawCircle(610, 300, 3, 50, true);
    // Draw Bouncing Ball
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(ballX, ballY, ballRadius, 50, true);
    
    //Draw Player
    DrawPlayer(240,250);
    DrawPlayer(660,250);
    DrawPlayer(450,400);
    DrawPlayer(350,200);
    DrawPlayer(550,200);

    glPopMatrix();
    
    glColor3f(0.1,0.3,0.9); // Blue color for the ring
   	DrawStadiumStands(450, 300, 375, 250, 465, 315, 16);
   	glColor3f(0.1, 0.1, 2);
   	DrawStadiumStands(450, 300, 475, 325, 565, 415, 20);
    
    GLint a;
    const char* title = "ASTU STADIUM";

    glColor3f(0.9, 1, 0.1); // Set text color
    glPushMatrix();
    glTranslatef(295, 550, 0); // Position the text
    glScalef(0.3, 0.3, 0.3);   // Scale text for size adjustment
    glLineWidth(2);            // Make text bold by increasing line width
    for (a = 0; title[a] != '\0'; a++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, title[a]);
    }
    
    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
}
//main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("ASTU STADIUM");
    init();
    glutDisplayFunc(DrawShape);
    glutTimerFunc(16, UpdateBall, 0); // Start the timer for ball animation
    glutMainLoop();

    return 0;
}
