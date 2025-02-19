#include <GL/glut.h>
#include <cmath>
/*Section: 2
	Group Name			ID_No
	1. Begonet Debebe 	UGR/30244/15
	2. Endrias Eshetu 	UGR/30469/15
	3. Israel Bekele	UGR/30715/15
	4. Milkesa Bulti	UGR/30933/15
*/
void FlagSWE(void){
	glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(0.3,0.1,0.1);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(85, 555); 
    glVertex2i(105, 545);
    glVertex2i(85, 305); 
    glVertex2i(105, 315);
    glEnd();
    
	glPushMatrix(); // Save the current matrix
    glTranslatef(80.0, -10.0, 0.0); 
    glScalef(0.8, 0.8, 1.0);
    //for green part
    glColor3f(0., 0.55, 0.25);
    glRecti(20, 400, 620, 700);
    
    //for blue part
    glColor3f(0.0, 0.0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(20, 700); 
    glVertex2i(20, 400); 
    glVertex2i(320, 550);
    glEnd();
    
    //for white part
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(20, 650); 
    glVertex2i(20, 450); 
    glVertex2i(220, 550);
    glEnd();
    
     //for red part
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(20, 600); 
    glVertex2i(20, 500); 
    glVertex2i(120, 550);
    glEnd();
    
    //for star
    glColor3f(0.9, 0.85, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(458, 565);
    glVertex2i(482, 565);
    glVertex2i(490, 545); 
    glVertex2i(470, 530); 
    glVertex2i(450, 545); 
    glEnd();
   
    //top triangle
    glBegin(GL_POLYGON);
    glVertex2i(458, 565);
    glVertex2i(482, 565);
    glVertex2i(470, 590); 
    glEnd();
    
    //right triangle
    glBegin(GL_POLYGON);
    glVertex2i(482, 565);
    glVertex2i(490, 545);
    glVertex2i(510, 560); 
    glEnd();
    
    //left triangle
    glBegin(GL_POLYGON);
    glVertex2i(458, 565); 
    glVertex2i(450, 545);
    glVertex2i(430, 560); 
    glEnd();
    
    //right-bottom triangle
    glBegin(GL_POLYGON);
    glVertex2i(470, 530);
    glVertex2i(490, 545);
    glVertex2i(492, 520); 
    glEnd();
    
    //left-bottom triangle
    glBegin(GL_POLYGON);
    glVertex2i(470, 530);
    glVertex2i(450, 545); 
    glVertex2i(448, 520); 
    glEnd();
	
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(482, 570); 
    glVertex2i(486, 568); 
    glVertex2i(495, 587);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2i(492, 544); 
    glVertex2i(491, 540); 
    glVertex2i(512, 530);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2i(468.5, 526); 
    glVertex2i(471.5, 526); 
    glVertex2i(470, 500);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2i(448, 544); 
    glVertex2i(447, 540); 
    glVertex2i(430, 535);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2i(458, 570); 
    glVertex2i(454, 568); 
    glVertex2i(445, 587);
    glEnd();
    
    
    glPopMatrix(); // Restore the previous matrix
    
    glColor3f(0.3,0.1,0.1);
    glRecti(73, 50, 87, 560);
    glBegin(GL_POLYGON);
    glVertex2i(68, 559); 
    glVertex2i(92, 559);
    glVertex2i(80, 600);
    glEnd();
    
    glRecti(30, 10, 130, 30);
    glRecti(40, 30, 120, 50);
    glRecti(50, 50, 110, 70);
    
GLint a;
    const char* title = "Flag of South West of Ethiopia";

    glColor3f(0.2, 0.2, 0.1); // Set text color
    glPushMatrix();
    glTranslatef(100, 565, 0); // Position the text
    glScalef(0.3, 0.3, 0.3);   // Scale text for size adjustment
    glLineWidth(2);            // Make text bold by increasing line width

    for (a = 0; title[a] != '\0'; a++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, title[a]);
    }
    
    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
}

void Init(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 600.0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Flag of South West of Ethiopia");
	Init();
	glutDisplayFunc(FlagSWE);
	glutMainLoop();
	return 0;
}
