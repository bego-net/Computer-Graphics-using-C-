#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846


// Function to draw a semi-circle with adjustable width
void drawSemiCircle(float cx, float cy, float outerRadius, float thickness) {
    const int numSegments = 100; // Number of segments for smoothness
    float innerRadius = outerRadius - thickness;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= numSegments; ++i) {
        float theta = M_PI * (float)i / (float)numSegments; // Angle for the semi-circle
        float x = cos(theta), y = sin(theta);

        // Outer edge of the semi-circle
        glVertex2f(cx + x * outerRadius, cy + y * outerRadius);
        // Inner edge of the semi-circle
        glVertex2f(cx + x * innerRadius, cy + y * innerRadius);
    }
    glEnd();
}

// Function to draw a line
void drawLine(float x1, float y1, float x2, float y2, float width) {
    glLineWidth(width); // Set the line width
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}


float carX = 0.0f; // Initial X position of the car
float carSpeed = 2.0f; // Speed of the car



// Function to draw a rectangle (used for the car body)
void drawRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Function to draw a circle (used for car wheels)
void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    const int numSegments = 100;
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= numSegments; ++i) {
        float theta = 2.0f * PI * (float)i / (float)numSegments;
        float x = cos(theta) * radius;
        float y = sin(theta) * radius;
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}


// Function to draw the car
void drawCar(float x) {
    // Draw the car body
    drawRectangle(x, 40.0f, 120.0f, 40.0f, 0.2f, 0.6f, 1.0f); // Main body (blue)
    drawRectangle(x + 20.0f, 70.0f, 80.0f, 30.0f, 0.8f, 0.8f, 0.8f); // Top part (light gray)
    drawRectangle(x + 30.0f, 75.0f, 30.0f, 20.0f, 0.2f, 0.2f, 0.2f); // Window 1 (dark gray)
    drawRectangle(x + 65.0f, 75.0f, 30.0f, 20.0f, 0.2f, 0.2f, 0.2f); // Window 2 (dark gray)

    // Draw the car wheels
    drawCircle(x + 30.0f, 30.0f, 15.0f, 0.0f, 0.0f, 0.0f); // Left wheel (black)
    drawCircle(x + 30.0f, 30.0f, 8.0f, 0.5f, 0.5f, 0.5f);  // Left hubcap (gray)
    drawCircle(x + 90.0f, 30.0f, 15.0f, 0.0f, 0.0f, 0.0f); // Right wheel (black)
    drawCircle(x + 90.0f, 30.0f, 8.0f, 0.5f, 0.5f, 0.5f);  // Right hubcap (gray)

    // Draw the headlights
    drawCircle(x + 115.0f, 60.0f, 5.0f, 1.0f, 1.0f, 0.0f); // Right headlight (yellow)
    drawCircle(x + 5.0f, 60.0f, 5.0f, 1.0f, 1.0f, 0.0f);   // Left headlight (yellow)
}
// Function to draw a tree
void drawTree(float x, float y) {
    // Draw the trunk
    drawRectangle(x-5, y-40, 10.0f, 30.0f, 0.6, 0.5, 0.46); // Brown trunk
    // Draw the canopy (three triangle)
     glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.1f, 0.1f); // Set color 
    
    // Define the vertices of the polygon
    glVertex2f(x, y+20.0);
    glVertex2f(x+15.0, y-10.0);
    glVertex2f(x-15.0, y-10.0);
   
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.9f, 0.9f); // Set color 
    
    // Define the vertices of the polygon
    glVertex2f(x, y+40.0);
    glVertex2f(x+15.0, y);
    glVertex2f(x-15.0, y);
   
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.1f); // Set color 
    
    // Define the vertices of the polygon
    glVertex2f(x, y+50.0);
    glVertex2f(x+13.0, y+10.0);
    glVertex2f(x-13.0, y+10.0);
   
    glEnd();
    
}

//to add text

void drawBitmapText(const char* text, float x, float y) {
    glRasterPos2f(x, y); // Set the position for the text
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// Function to draw a flower
void drawFlower(float x, float y) {
    // Draw petals (circles around a center point)
    drawCircle(x + 5.0f, y + 10.0f, 5.0f, 1.0f, 0.0f, 0.0f);  // Red petal (top right)
    drawCircle(x - 5.0f, y + 10.0f, 5.0f, 1.0f, 0.0f, 0.0f);  // Red petal (top left)
    drawCircle(x + 5.0f, y - 10.0f, 5.0f, 1.0f, 0.0f, 0.0f);  // Red petal (bottom right)
    drawCircle(x - 5.0f, y - 10.0f, 5.0f, 1.0f, 0.0f, 0.0f);  // Red petal (bottom left)
    drawCircle(x + 10.0f, y, 5.0f, 1.0f, 0.0f, 0.0f);         // Red petal (right)
    drawCircle(x - 10.0f, y, 5.0f, 1.0f, 0.0f, 0.0f);         // Red petal (left)

    // Draw the flower center
    drawCircle(x, y, 5.0f, 1.0f, 1.0f, 0.0f); // Yellow center
}
void drawTelecomAntenna() {
    // Draw the base of the tower
    drawRectangle(295.0f, 50.0f, 10.0f, 150.0f, 0.5f, 0.5f, 0.5f); // Tower structure (gray)

    // Draw cross braces
    glColor3f(0.3f, 0.3f, 0.3f); // Darker gray for braces
    glBegin(GL_LINES);
    glVertex2f(295.0f, 50.0f);
    glVertex2f(305.0f, 75.0f);
    glVertex2f(305.0f, 50.0f);
    glVertex2f(295.0f, 75.0f);

    glVertex2f(295.0f, 75.0f);
    glVertex2f(305.0f, 100.0f);
    glVertex2f(305.0f, 75.0f);
    glVertex2f(295.0f, 100.0f);

    glVertex2f(295.0f, 100.0f);
    glVertex2f(305.0f, 125.0f);
    glVertex2f(305.0f, 100.0f);
    glVertex2f(295.0f, 125.0f);

    glVertex2f(295.0f, 125.0f);
    glVertex2f(305.0f, 150.0f);
    glVertex2f(305.0f, 125.0f);
    glVertex2f(295.0f, 150.0f);
    glEnd();

    // Draw platforms
    drawRectangle(280.0f, 150.0f, 40.0f, 10.0f, 0.7f, 0.7f, 0.7f); // Platform 1 (gray)
    drawRectangle(270.0f, 175.0f, 60.0f, 10.0f, 0.7f, 0.7f, 0.7f); // Platform 2 (gray)

    // Draw the dish
    drawCircle(300.0f, 200.0f, 15.0f, 0.9f, 0.9f, 0.9f); // Dish (light gray)
    drawRectangle(298.0f, 185.0f, 4.0f, 15.0f, 0.7f, 0.7f, 0.7f); // Dish arm (gray)

    // Draw signals (optional, for visualization)
    glColor3f(1.0f, 0.0f, 0.0f); // Red signal lines
    glBegin(GL_LINES);
    glVertex2f(300.0f, 200.0f);
    glVertex2f(330.0f, 230.0f); // Signal 1
    glVertex2f(300.0f, 200.0f);
    glVertex2f(270.0f, 230.0f); // Signal 2
    glEnd();
}




// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    // Draw gradient sky
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.98f); // Sky blue (top)
    glVertex2f(0.0f, 400.0f);
    glVertex2f(600.0f, 400.0f);
    glColor3f(0.87f, 0.94f, 1.0f); // Light blue/white (horizon)
    glVertex2f(600.0f, 100.0f);
    glVertex2f(0.0f, 100.0f);
    glEnd();
     //green area
    glColor3f(0.0, 0.50, 0.0); // Set color ); 
    glBegin(GL_QUADS);
        glVertex2f(600.0f, 250.0f);  
        glVertex2f(0.0f, 250.0f);  
        glVertex2f(0.0f, 370.05f);  
        glVertex2f(600.0f, 370.05f); 
    glEnd();

        
        //planting area of trees inside campus
	glColor3f(0.545, 0.271, 0.075); // Set color ); 
    glBegin(GL_QUADS);
        glVertex2f(150.0f, 250.0f);  
        glVertex2f(130.0f, 250.0f);  
        glVertex2f(245.0f, 370.05f);  
        glVertex2f(260.0f, 370.05f); 
    glEnd();
    
    	glColor3f(0.545, 0.271, 0.075); // Set color ); 
    glBegin(GL_QUADS);
        glVertex2f(410.0f, 250.0f);  
        glVertex2f(430.0f, 250.0f);  
        glVertex2f(315.0f, 370.05f);  
        glVertex2f(300.0f, 370.05f); 
    glEnd();
   
    
    
      //Asphalt inside the campus
    glColor3f(0.5, 0.5, 0.5); 
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 100.0f);  
        glVertex2f(560.0f, 100.0f);  
        glVertex2f(300.0f, 370.05f);  
        glVertex2f(260.0f, 370.05f); 
    glEnd();
    
    glEnable(GL_LINE_STIPPLE);
    
    // Set the stipple pattern (0xFF is a full line, 0xF0 is a dashed pattern)
    glLineStipple(4, 0x00FF); // 1 unit on, 1 unit off
    
    // Set the color for the line
    glColor3f(1.0f, 1.0f, 1.0f); 

    // Draw the dashed line
    glBegin(GL_LINES);
        glVertex2f(280.0f, 250.0f);
        glVertex2f(280.0f, 370.0f);
        glEnd();
	 
        
    //inner size trees of campus
	glPushMatrix();
	// Apply scaling transformation to make the tree half the size
    glTranslatef(100.0f, 260.0f, 0.0f); // Move to the position of the tree
    glScalef(0.75f, 0.75f, 0.75f);        // Scale down by half
    glTranslatef(-100.0f, -260.0f, 0.0f); // Move back
// Draw the tree
    drawTree(180.0, 300.0);//1
	drawTree(500.0, 300.0);//1 
// Restore the original transformation matrix
    glPopMatrix();
    
   glPushMatrix();

    // Apply scaling transformation to make the tree half the size
    glTranslatef(100.0f, 260.0f, 0.0f); // Move to the position of the tree
    glScalef(0.5f, 0.5f, 0.5f);        // Scale down by half
    glTranslatef(-100.0f, -260.0f, 0.0f); // Move back

    // Draw the trees
    drawTree(280.0, 380.0);//2
    drawTree(640.0, 380.0);//2
    
    drawTree(350.0, 430.0);//2
    drawTree(580.0, 430.0);//2
    // Restore the original transformation matrix
    glPopMatrix();
	
	 glPushMatrix();
	 
	 
	 

    // Apply scaling transformation to make the tree half the size
    glTranslatef(100.0f, 260.0f, 0.0f); // Move to the position of the tree
    glScalef(0.3f, 0.3f, 0.25f);        // Scale down by half
    glTranslatef(-100.0f, -260.0f, 0.0f); // Move back

    // Draw the tree
    drawTree(630.0, 660.0);//3
    drawTree(800.0, 660.0);//3
    drawTree(580.0, 600.0);//3
    drawTree(830.0, 600.0);//3

    // Restore the original transformation matrix
    glPopMatrix(); 
    
	
    // Draw the sun
    drawCircle(570.0f, 380.0f, 25.0f, 1.0f, 1.0f, 0.0f); // Sun (yellow)
    drawCircle(570.0f, 380.0f, 30.0f, 1.0f, 0.9f, 0.6f); // Sun glow (light yellow)
    drawCircle(500.0f, 380.0f, 2.0f, 1.0f, 1.0f, 1.0f);
	drawCircle(350.0f, 390.0f, 2.0f, 1.0f, 1.0f, 1.0f);
	drawCircle(250.0f, 385.0f, 2.0f, 1.0f, 1.0f, 1.0f);
	drawCircle(300.0f, 390.0f, 2.0f, 1.0f, 1.0f, 1.0f);
	drawCircle(405.0f, 380.0f, 2.0f, 1.0f, 1.0f, 1.0f);
	drawCircle(450.0f, 390.0f, 2.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix(); // Save the current transformation
    glTranslatef(180.0, 180.0, 0.0f); // Move object
    drawTelecomAntenna();
    
    glPopMatrix();
	//fench
    drawRectangle(490.0f, 250.08f, 110.0f, 35.2f, 0.64f, 0.68f, 0.65f);
    drawRectangle(0.0f, 250.08f, 112.0f, 35.2f,  0.64f, 0.68f, 0.65f);
    drawRectangle(490.0f, 260.08f, 110.0f, 4.0f, 0.74f, 0.3f, 0.24f);
    drawRectangle(490.0f, 270.08f, 110.0f, 4.0f, 0.74f, 0.3f, 0.24f);
    drawRectangle(0.0f, 260.08f, 112.0f, 4.0f,  0.74f, 0.3f, 0.24f);
    drawRectangle(0.0f, 270.08f, 112.0f, 4.0f,  0.74f, 0.3f, 0.24f);
    
   

    // Set colors and draw 5 different-sized semi-circles
    glColor3f(0.81f, 0.624f, 0.435f); 
    drawSemiCircle(300.0f, 250.0f, 120.0f, 12.2f);

    glColor3f(0.81f, 0.624f, 0.435f); 
    drawSemiCircle(420.0f, 250.2f, 80.8f, 12.2f);
	glColor3f(0.81f, 0.624f, 0.435f); 
    drawSemiCircle(245.0f, 250.2f, 105.0f, 12.2f);

	glColor3f(0.81f, 0.624f, 0.435f); 
    drawSemiCircle(160.0f, 250.2f, 60.0f, 12.2f);
    
     glColor3f(0.81f, 0.624f, 0.435f); 
    drawSemiCircle(380.0f, 250.2f, 40.8f, 10.2f);

    // Draw lines with different widths in middle of semi circles
    glColor3f(0.81f, 0.624f, 0.435f); 
    drawLine(340.8f, 290.8f, 380.8f, 330.8f, 10.0f);

	
	glColor3f(0.81f, 0.624f, 0.435f); 
    drawLine(330.8f, 305.8f, 365.8f, 340.8f, 10.0f); 

	 glColor3f(0.81f, 0.624f, 0.435f); 
    drawLine(320.8f, 320.8f, 350.8f, 350.8f, 10.0f); 
	
	 glColor3f(0.81f, 0.624f, 0.435f); 
    drawLine(300.8f, 330.8f, 330.8f, 360.8f, 10.0f); 
	
	glColor3f(0.81f, 0.624f, 0.435f);
    drawLine(280.8f, 340.8f, 300.8f, 360.8f, 10.0f); 

	//polygon in gate(right)
     glBegin(GL_POLYGON);
    glColor3f(0.81f, 0.624f, 0.435f); // Set color 
    
    // Define the vertices of the polygon
    glVertex2f(410.0, 250.0);
    glVertex2f(500.0, 250.0);
    glVertex2f(490.0, 285.0);
    glVertex2f(450.5, 325.5);
    glVertex2f(398.0, 320.0);
    glEnd();
    	//polygon in gate(left)
    glBegin(GL_POLYGON);
    glColor3f(0.81f, 0.624f, 0.435f); // Set color 
    
    // Define the vertices of the polygon
    glVertex2f(100.0, 250.0);
    glVertex2f(150.0, 250.0);
    glVertex2f(152.0, 305.0);
    glVertex2f(110.0, 275.0);
    
    
     // Asphalt to drive car
   glColor3f(0.32, 0.32, 0.34);  
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);  
        glVertex2f(0.0f, 80.0f);  
        glVertex2f(600.0, 80.0f);  
        glVertex2f(600.0f, 0.0f); 
    glEnd();
    
     
    
    glEnable(GL_LINE_STIPPLE);
    
    // Set the stipple pattern (0xFF is a full line, 0xF0 is a dashed pattern)
    glLineStipple(4, 0x00FF); // 1 unit on, 1 unit off
    
    // Set the color for the line
    glColor3f(1.0f, 1.0f, 1.0f); 

    // Draw the dashed line
    glBegin(GL_LINES);
        glVertex2f(0.0f, 40.0f);
        glVertex2f(600.0f, 40.0f);
        glEnd();
   
 // Draw the car
    drawCar(carX);
    
    //draw the  trees planting land left side
	 glBegin(GL_POLYGON);
    glColor3f(0.545, 0.271, 0.075); // Set color 
    
    // Define the vertices of the polygon
    glVertex2f(90.0, 230.0);
    glVertex2f(130.0, 230.0);
    glVertex2f(70.0, 130.0);
    glVertex2f(20.5, 130.0);
    glEnd();
    
    
	 //draw the  trees planting land righ side
     glBegin(GL_POLYGON);
    glColor3f(0.545, 0.271, 0.075); // Set color 
    
    glVertex2f(420.0, 230.0);
    glVertex2f(460.0, 230.0);
    glVertex2f(540.0, 130.0);
    glVertex2f(490.5, 130.0);
    glEnd();
    //flowers planting
    drawRectangle(265.0, 110.0, 30.0, 90.0, 0.0, 0.0, 0.0);
    // Draw trees near the gate
    drawTree(65.0f, 170.0f); // Left tree
    drawTree(80.0f, 220.0f); // Left tree
    drawTree(100.0f, 260.0f); // Left tree
    
    drawTree(500.0f, 170.0f); // Right tree
    drawTree(480.0f, 220.0f); // Right tree
    drawTree(460.0f, 260.0f); // Right tree
    

    // Draw flowers near the gate
    drawFlower(280.0f, 150.0f); // Flower near left tree
    drawFlower(280.0f, 200.0f); // Another flower near left tree
    glColor3f(0.6, 0.5, 0.46); 
    drawLine(280.0, 170.0, 280.0, 190.0, 4.0);
    drawLine(280.0, 120.0, 280.0, 140.0, 4.0);
    
    //trafic sign
    drawCircle(540.0f, 140.0f, 22.15f, 1.0f, 0.0f, 0.0f); // Red circle for the sign
    glColor3f(1.0f, 1.0f, 1.0f); // text color
    drawBitmapText("STOP", 525.0, 135.0);
    drawRectangle(537.5 , 100.0f, 5.0, 20.0, 0.0,0.0,0.0);
    
    glPushMatrix(); // Save the current transformation
    glTranslatef(1.0, 340.0, 0.0f); // Move object
    
    
    
   // Define the number of floors and the building dimensions
    int numFloors = 10;
    float buildingWidth = 150.0f;
    float buildingHeight = 60.0f;
    float floorHeight = buildingHeight / numFloors;

    // Set the building color
    glColor3f(0.5f, 0.5f, 0.8f); // Light blue

    // Draw the building
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(buildingWidth, 0.0f);
    glVertex2f(buildingWidth, buildingHeight);
    glVertex2f(0.0f, buildingHeight);
    glEnd();
    

    // Draw the floors
    glColor3f(0.3f, 0.3f, 0.3f); // Gray for floor lines
    for (int i = 1; i < numFloors; ++i) {
        float y = i * floorHeight;
        glBegin(GL_LINES);
        glVertex2f(0.0f, y);
        glVertex2f(buildingWidth, y);
        glEnd();
    }

     glPopMatrix();
     //screen
      drawRectangle(510.0f, 190.08f, 70.0f, 50.2f, 0.64f, 0.68f, 0.65f);
       drawRectangle(515.0f, 195.08f, 60.0f, 40.2f, 1.0f, 1.0f, 1.0f);
       drawRectangle(520.0, 160.0, 5.0f, 30.2f, 0.0f, 0.0f, 0.0f);
      drawRectangle(560.0, 160.0, 5.0f, 30.2f, 0.0f, 0.0f, 0.0f);
      
    //logo design
 
 drawCircle(130.18f, 275.32f, 14.0f, 1.0f, 0.0f, 0.0f);
 drawCircle(130.18f, 275.32f, 10.60f, 1.0f, 1.0f, 1.0f);
 drawCircle(130.18f, 275.32f, 8.045f, 0.0f, 1.0f, 0.0f);
 drawCircle(130.18f, 275.32f, 6.035f, 1.0f, 1.0f, 1.0f);
 drawCircle(130.18f, 275.32f, 4.028f, 0.0f, 0.0f, 1.0f);
 
 drawCircle(430.18f, 275.32f, 14.0f, 1.0f, 0.0f, 0.0f);
 drawCircle(430.18f, 275.32f, 10.60f, 1.0f, 1.0f, 1.0f);
 drawCircle(430.18f, 275.32f, 8.045f, 0.0f, 1.0f, 0.0f);
 drawCircle(430.18f, 275.32f, 6.035f, 1.0f, 1.0f, 1.0f);
 drawCircle(430.18f, 275.32f, 4.028f, 0.0f, 0.0f, 1.0f);
 
 
 
 
    
    glutSwapBuffers();
}

// Timer callback to update the car's position
void update(int value) {
    carX += carSpeed; // Move the car to the right
    if (carX > 600.0f) { // Reset the car's position when it goes off-screen
        carX = -120.0f; // Start from the left side
    }
    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(16, update, 0); // Call this function again after 16ms
}
   

 
 


// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("ASTU Gate");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 400); // Adjust the coordinate system for proper visualization
	glutTimerFunc(1, update, 0); // Initialize the timer for animation
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

