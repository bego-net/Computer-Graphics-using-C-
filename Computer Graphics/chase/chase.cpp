#include <GL/glut.h>
/*Section: 2
	Group Name			ID_No
	1. Begonet Debebe 	UGR/30244/15
	2. Endrias Eshetu 	UGR/30469/15
	3. Israel Bekele	UGR/30715/15
	4. Milkesa Bulti	UGR/30933/15
*/

void ChaseBoard(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0); 
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    
    //fo background board
    for(int i=0; i<6; i++){
    	for (int j=0; j<6; j++){
    		if((i+j)%2 == 0){
    			glColor3f(0.9, 0.9, 0.9);
    			glRecti(i * 100,j * 100,(i + 1) * 100,(j + 1) * 100);
				}else 
				glColor3f(0.5, 0.5, 0.5);
				glRecti(i * 100,j * 100,(i + 1) * 100,(j + 1) * 100);	
	}
}
    
    glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Chase Game");
	glutDisplayFunc(ChaseBoard);
	glutMainLoop();
	return 0;
}
