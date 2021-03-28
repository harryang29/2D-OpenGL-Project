#define GLEW_STATIC
#include<cmath>
#include<iostream>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;
void display();
void move(float x, float y, float z, int startindex);
void Yrotate(float x, float z, int startindex);
void scale(float x, float y, float z, int startindex);
void specialkey(int key, int x, int y);
void mouseclick(int button, int state, int x, int y);
void mouse(int button, int state, int x, int y);

GLfloat vertices[] = {
	//jet figure
	0.0f, -0.3f, 0.0f,
    0.14f, -0.55f, 0.0f,
    0.15f, -0.58f, 0.0f,
    0.13f, -0.60f, 0.0f,
    0.07f, -0.55f, 0.0f,
    0.0f, -0.62f, 0.0f,
    -0.07f, -0.55f, 0.0f,
    -0.13f, -0.60f, 0.0f,
    -0.15f, -0.58f, 0.0f,
    -0.14f, -0.55f, 0.0f,
	//jet design 1
	0.015f, -0.35f, 0.0f,
	0.032f, -0.38f, 0.0f,
	0.024f, -0.39f, 0.0f,
	-0.024f, -0.39f, 0.0f,
	-0.032f, -0.38f, 0.0f,
	-0.015f, -0.35f, 0.0f,
	//jet design 2
	0.037f, -0.39f, 0.0f,
	0.037f, -0.57f, 0.0f,
	0.065f, -0.54, 0.0f,
	0.065f, -0.44f, 0.0f,
	//jet design 3
	-0.037f, -0.39f, 0.0f,
	-0.037f, -0.57f, 0.0f,
	-0.065f, -0.54, 0.0f,
	-0.065f, -0.44f, 0.0f,
	-0.055f, -0.42f, 0.0f,
	-0.055f, -0.46f, 0.0f,
	-0.047f, -0.46f, 0.0f,
	-0.047f, -0.41f, 0.0f,
	//jet design 4
	0.075, -0.46f, 0.0f,
	0.075, -0.54f, 0.0f,
	0.095, -0.56f, 0.0f,
	0.095, -0.5f, 0.0f,
	//jet design 5
	-0.075, -0.46f, 0.0f,
	-0.075, -0.54f, 0.0f,
	-0.095, -0.56f, 0.0f,
	-0.095, -0.5f, 0.0f,
	//jet design 6
	-0.001f, -0.62f, 0.0f,
	-0.001f, -0.60f, 0.0f,
	-0.02f, -0.58f, 0.0f,
	-0.02f, -0.60f, 0.0f,
	//jet design 7
	0.001f, -0.62f, 0.0f,
	0.001f, -0.60f, 0.0f,
	0.02f, -0.58f, 0.0f,
	0.02f, -0.60f, 0.0f,
	//jet design 8
	0.015f, -0.42f, 0.0f,
	0.015f, -0.55f, 0.0f,
	-0.015f, -0.42f, 0.0f,
	-0.015f, -0.55f, 0.0f,
	//missile1
	0.056f, -0.37f, 0.0f,
	0.064f, -0.37f, 0.0f,
	0.064f, -0.42f, 0.0f,
	0.056f, -0.42f, 0.0f,
	//missile2
	-0.056f, -0.37f, 0.0f,
	-0.064f, -0.37f, 0.0f,
	-0.064f, -0.42f, 0.0f,
	-0.056f, -0.42f, 0.0f, 
	//background
	-1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,
	//cloud1
	-0.75, 0.56f, 0.0f,
	-0.8, 0.56f, 0.0f,
	-0.8, 0.58f, 0.0f,
	-0.85, 0.58f, 0.0f,
	-0.85, 0.60f, 0.0f,
	-0.9, 0.60f, 0.0f,
	-0.9, 0.62f, 0.0f,
	-0.95, 0.62f, 0.0f,
	-0.95, 0.64f, 0.0f,
	-1.0, 0.64f, 0.0f,
	-1.0, 0.72f, 0.0f,
	-0.95, 0.72f, 0.0f,
	-0.95, 0.74f, 0.0f,
	-0.9, 0.74f, 0.0f,
	-0.9f, 0.76f, 0.0f,
	-0.85, 0.76f, 0.0f,
	-0.85, 0.78f, 0.0f,
	-0.8, 0.78f, 0.0f,
	-0.8f, 0.8f, 0.0f,
	-0.5f, 0.8f, 0.0f,
	-0.5f, 0.78f, 0.0f,
	-0.45f, 0.78f, 0.0f,
	-0.45f, 0.76f, 0.0f,
	-0.4f, 0.76f, 0.0f,
	-0.4f, 0.74f, 0.0f,
	-0.35f, 0.74f, 0.0f,
	-0.35f, 0.72f, 0.0f,
	-0.2f, 0.72f, 0.0f,
	-0.2f, 0.70f, 0.0f,
	-0.15f, 0.70f, 0.0f,
	-0.15f, 0.68f, 0.0f,
	-0.05f, 0.68f, 0.0f,
	-0.05f, 0.66f, 0.0f,
	0.0f, 0.66f, 0.0f,
	0.0f, 0.58f, 0.0f,
	-0.05, 0.58f, 0.0f,
	-0.05, 0.56f, 0.0f,
	-0.1, 0.56f, 0.0f,
	-0.1, 0.54f, 0.0f,
	-0.15, 0.54f, 0.0f,	
	//cloud2
	-0.85f, -0.06f, 0.0f,
	-0.85f, -0.04f, 0.0f,
	-0.9f, -0.04f, 0.0f,	
	-0.9f, 0.04f, 0.0f,
	-0.85f, 0.04f, 0.0f,
	-0.85f, 0.06f, 0.0f,
	-0.8f, 0.06f, 0.0f,	
	-0.8f, 0.08f, 0.0f,
	-0.75f, 0.08f, 0.0f,		
	-0.75f, 0.1f, 0.0f,	
	-0.6f, 0.1f, 0.0f,	
	-0.6f, 0.08f, 0.0f,
	-0.55f, 0.08f, 0.0f,	
	-0.55f, 0.06f, 0.0f,
	-0.5f, 0.06f, 0.0f,	
	-0.5f, 0.04f, 0.0f,
	-0.45f, 0.04f, 0.0f,	
	-0.45f, 0.02f, 0.0f,
	-0.4f, 0.02f, 0.0f,	
	-0.4f, -0.04f, 0.0f,
	-0.45f, -0.04f, 0.0f,	
	-0.45f, -0.06f, 0.0f,
	//cloud3
	0.9f, 0.2f, 0.0f,
	0.9f, 0.22f, 0.0f,
	0.95f, 0.22f, 0.0f,	
	0.95f, 0.3f, 0.0f,
	0.9f, 0.3f, 0.0f,
	0.9f, 0.32f, 0.0f,
	0.85f, 0.32f, 0.0f,	
	0.85f, 0.34f, 0.0f,
	0.8f, 0.34f, 0.0f,		
	0.8f, 0.36f, 0.0f,	
	0.65f, 0.36f, 0.0f,	
	0.65f, 0.34f, 0.0f,
	0.6f, 0.34f, 0.0f,	
	0.6f, 0.32f, 0.0f,
	0.55f, 0.32f, 0.0f,	
	0.55f, 0.3f, 0.0f,
	0.5f, 0.3f, 0.0f,	
	0.5f, 0.28f, 0.0f,
	0.45f, 0.28f, 0.0f,	
	0.45f, 0.22f, 0.0f,
	0.5f, 0.22f, 0.0f,	
	0.5f, 0.2f, 0.0f,
	//cloud4
	0.45f, -0.7f, 0.0f,
	0.45f, -0.68f, 0.0f,
	0.5f, -0.68f, 0.0f,	
	0.5f, -0.6f, 0.0f,
	0.45f, -0.6f, 0.0f,
	0.45f, -0.58f, 0.0f,
	0.4f, -0.58f, 0.0f,	
	0.4f, -0.56f, 0.0f,
	0.35f, -0.56f, 0.0f,		
	0.35f, -0.54f, 0.0f,	
	0.2f, -0.54f, 0.0f,	
	0.2f, -0.56f, 0.0f,
	0.15f, -0.56f, 0.0f,	
	0.15f, -0.58f, 0.0f,
	0.1f, -0.58f, 0.0f,	
	0.1f, -0.6f, 0.0f,
	0.05f, -0.6f, 0.0f,	
	0.05f, -0.62f, 0.0f,
	0.0f, -0.62f, 0.0f,	
	0.0f, -0.68f, 0.0f,
	0.05f, -0.68f, 0.0f,	
	0.05f, -0.7f, 0.0f,
};

GLfloat *mapV = NULL;

int forUpdate=0;
int ctr=0;
int rty=0;
int rtyctr=0;

GLuint VBOid;

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(800, 800);
   glutCreateWindow("simple");
   glutFullScreen();
   glutDisplayFunc(display);
   glutSpecialFunc(specialkey);
   glutMouseFunc(mouse);
   GLenum err = glewInit();
   if(err == GLEW_OK){
        glutMainLoop();
   }
}

void draw(){

	if(!forUpdate){
  	
	    glGenBuffers(1, &VBOid);
	    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	  
  	    glEnableClientState(GL_VERTEX_ARRAY);
	  
	    glVertexPointer(3, GL_FLOAT, 0, 0);
		//background
	    glColor4f(0.0f,0.2f,0.4f,1.0f);
    	glDrawArrays(GL_POLYGON,56,4); 
    	//cloud1
    	glColor4f(0.6f,0.6f,0.7f,1.0f);
    	glDrawArrays(GL_POLYGON,60,40); 
    	//cloud2
    	glDrawArrays(GL_POLYGON,100,22); 
    	//cloud3
    	glDrawArrays(GL_POLYGON,122,22); 
    	//cloud4
    	glDrawArrays(GL_POLYGON,144,22); 
		//missile1 & 2 
    	glColor4f(0.0f,0.0f,0.0f,1.0f);
    	glDrawArrays(GL_LINE_LOOP,48,4);
	    glDrawArrays(GL_LINE_LOOP,52,4);
    	glColor4f(0.7f,0.7f,0.7f,1.0f);
    	glDrawArrays(GL_POLYGON,48,4);
	    glDrawArrays(GL_POLYGON,52,4);
	    //jet figure
    	glColor4f(0.7f,0.7f,0.7f,1.0f);
    	glDrawArrays(GL_POLYGON,0,10);
    	//jet design
    	glColor4f(0.0f,0.0f,0.0f,1.0f);
    	glDrawArrays(GL_LINE_LOOP,0,10);
    	glDrawArrays(GL_LINE_LOOP,10,6);
    	glDrawArrays(GL_LINE_LOOP,16,4);
    	glDrawArrays(GL_LINE_LOOP,20,8);
    	glDrawArrays(GL_LINE_LOOP,28,4);
    	glDrawArrays(GL_LINE_LOOP,32,4);
    	glDrawArrays(GL_POLYGON,36,4);
    	glDrawArrays(GL_POLYGON,40,4);
    	glDrawArrays(GL_LINES,44,4);
	    
	    
	    glDisableClientState(GL_VERTEX_ARRAY);  
  }else{
	  	glEnableClientState(GL_VERTEX_ARRAY);
	
	    glVertexPointer(3, GL_FLOAT, 0, 0);
	    //background
	    glColor4f(0.0f,0.2f,0.4f,1.0f);
    	glDrawArrays(GL_POLYGON,56,4); 
    	//cloud1
    	glColor4f(0.6f,0.6f,0.7f,1.0f);
    	glDrawArrays(GL_POLYGON,60,40); 
    	//cloud2
    	glDrawArrays(GL_POLYGON,100,22); 
    	//cloud3
    	glDrawArrays(GL_POLYGON,122,22); 
    	//cloud4
    	glDrawArrays(GL_POLYGON,144,22); 
		//missile1 & 2 
    	glColor4f(1.0f,0.0f,0.0f,1.0f);
    	glDrawArrays(GL_LINE_LOOP,48,4);
	    glDrawArrays(GL_LINE_LOOP,52,4);
    	glColor4f(1.0f,0.8f,0.6f,1.0f);
    	glDrawArrays(GL_POLYGON,48,4);
	    glDrawArrays(GL_POLYGON,52,4);	
	    //jet figure
    	glColor4f(0.7f,0.7f,0.7f,1.0f);
    	glDrawArrays(GL_POLYGON,0,10);
    	//jet design
    	glColor4f(0.0f,0.0f,0.0f,1.0f);
    	glDrawArrays(GL_LINE_LOOP,0,10);
    	glDrawArrays(GL_LINE_LOOP,10,6);
    	glDrawArrays(GL_LINE_LOOP,16,4);
    	glDrawArrays(GL_LINE_LOOP,20,8);
    	glDrawArrays(GL_LINE_LOOP,28,4);
    	glDrawArrays(GL_LINE_LOOP,32,4);
    	glDrawArrays(GL_POLYGON,36,4);
    	glDrawArrays(GL_POLYGON,40,4);
    	glDrawArrays(GL_LINES,44,4);
    	 
	
	    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void modify(int value){
	if(value == 1){
		//delay for 3 seconds
		Sleep(3000);
	}else if(value%301 == 0){
		mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

		for(int i=144; i < 168; i+=3){
			//return the missiles
			move(0.0f,-1.2f,0.0f,i);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
		
	}else if(value == 370 || value == 2470 || value == 4570 || value == 6670){
		mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

		for(int i=432; i < 498; i+=3){
			//return cloud4
			move(0.0f,2.1f,0.0f,i);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
		
	}else if(value == 1000 || value == 3100 || value == 5200 || value == 7300){
		mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

		for(int i=300; i < 366; i+=3){
			//return cloud2
			move(0.0f,2.1f,0.0f,i);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
		
	}else if(value == 1300 || value == 3400 || value == 5500 || value == 7600){
		mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

		for(int i=366; i < 432; i+=3){
			//return cloud3
			move(0.0f,2.1f,0.0f,i);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
		
	}else if(value == 1800 || value == 4000 || value == 6200 || value == 8400){
		mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

		for(int i=180; i < 300; i+=3){
			//return cloud1
			move(0.0f,2.2f,0.0f,i);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
		
	}else if(value == 9000){
		//bind with 0, so, switch back to normal pointer operation
  		glBindBuffer(GL_ARRAY_BUFFER, 0);
  		glDeleteBuffers(1, &VBOid);
  		exit(0);
	}else{
		forUpdate = 1;
		
		mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		
		for(int i=144; i < 168; i+=3){
		//fires the missile
		move(0.0f,0.004f,0.0f,i);
		}
		for(int i=180; i < 300; i+=3){
			//move cloud1
			move(0.0f,-0.001f,0.0f,i);
		}
		for(int i=300; i < 366; i+=3){
			//move cloud2
			move(0.0f,-0.001f,0.0f,i);
		}
		for(int i=366; i < 432; i+=3){
			//move cloud3
			move(0.0f,-0.001f,0.0f,i);
		}
		for(int i=432; i < 498; i+=3){
			//move cloud4
			move(0.0f,-0.001f,0.0f,i);
		}
		if(rty == 1){
			if(rtyctr < 44000){
				for(int i=0; i < 168; i+=3){
				//rotates the jet
				Yrotate(0.008f,0.008f,i);
				rtyctr++;				
				}			
			}else{
				rty = 0;
				rtyctr = 0;
			}
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
	}
		
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();
	glutPostRedisplay();
	glutTimerFunc(10,modify,ctr++);
}

void move(float x, float y, float z, int startindex){
	
	GLfloat w = 1.0f;
	//Rotation Matrix Template
	GLfloat ta[] = {
		1, 0.0f, 0.0f, x,
		0.0f, 1, 0.0f, y,
		0.0f, 0.0f, 1, z,
		0.0f, 0.0f, 0.0f, 1
	};
	
	//Using the Rotation Matrix to Matrix Multiplication of 4x4 to 4x1 matrix 
	//with no simplification included
	GLfloat tx, ty, tz;
	tx = (ta[0]*mapV[startindex]) + (ta[1]*mapV[startindex+1]) + (ta[2]*mapV[startindex+2]) + (ta[3]* w);
	ty = (ta[4]*mapV[startindex]) + (ta[5]*mapV[startindex+1]) + (ta[6]*mapV[startindex+2]) + (ta[7]* w);
	tz = (ta[8]*mapV[startindex]) + (ta[9]*mapV[startindex+1]) + (ta[10]*mapV[startindex+2]) + (ta[11]* w);
	
	
	mapV[startindex] = tx;
	mapV[startindex+1] = ty;
	mapV[startindex+2] = tz;
	

}

void Yrotate(float x, float z, int startindex){
	GLfloat w = 1.0;
	//Rotation Matrix Template
	GLfloat ta[] = {
		cos(x), 0.0f, sin(x), 0.0f,
		0.0f, 1, 0.0f, 0.0f,
		-sin(z), 0.0f, cos(z), 0.0f,
		0.0f, 0.0f, 0.0f, 1
	};
	
	//Using the Rotation Matrix to Matrix Multiplication of 4x4 to 4x1 matrix 
	//with no simplification included
	GLfloat tx, ty, tz;
	tx = (ta[0]*mapV[startindex]) + (ta[1]*mapV[startindex+1]) + (ta[2]*mapV[startindex+2]) + (ta[3]* w);
	ty = (ta[4]*mapV[startindex]) + (ta[5]*mapV[startindex+1]) + (ta[6]*mapV[startindex+2]) + (ta[7]* w);
	tz = (ta[8]*mapV[startindex]) + (ta[9]*mapV[startindex+1]) + (ta[10]*mapV[startindex+2]) + (ta[11]* w);
	
	
	mapV[startindex] = tx;
	mapV[startindex+1] = ty;
	mapV[startindex+2] = tz;
}

void scale(float x, float y, float z, int startindex){
	
	GLfloat w = 1.0f;
	//Scaling Matrix Template
	GLfloat ta[] = {
		x, 0.0f, 0.0f, 0.0f,
		0.0f, y, 0.0f, 0.0f,
		0.0f, 0.0f, z, 0.0f,
		0.0f, 0.0f, 0.0f, 1
	};
	
	//Using the Scaling Matrix to Matrix Multiplication of 4x4 to 4x1 matrix 
	//with no simplification included
	GLfloat tx, ty, tz;
	tx = (ta[0]*mapV[startindex]) + (ta[1]*mapV[startindex+1]) + (ta[2]*mapV[startindex+2]) + (ta[3]* w);
	ty = (ta[4]*mapV[startindex]) + (ta[5]*mapV[startindex+1]) + (ta[6]*mapV[startindex+2]) + (ta[7]* w);
	tz = (ta[8]*mapV[startindex]) + (ta[9]*mapV[startindex+1]) + (ta[10]*mapV[startindex+2]) + (ta[11]* w);
	
	
	mapV[startindex] = tx;
	mapV[startindex+1] = ty;
	mapV[startindex+2] = tz;
}

void specialkey(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		
			for(int i=0; i < 168; i+=3){
				move(0.0f,0.05f,0.0f,i);
			}
			
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		
			for(int i=0; i < 168; i+=3){
				move(0.0f,-0.05f,0.0f,i);
			}
			
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		
			for(int i=0; i < 168; i+=3){
				move(-0.05f,0.0f,0.0f,i);
			}
			
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		
			for(int i=0; i < 168; i+=3){
				move(0.05f,0.0f,0.0f,i);
			}
			
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glutPostRedisplay();
			break;
	}
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		rty = 1;
    }	

    if (button == 3 && state == GLUT_UP)
    {
       	mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		
		for(int i=0; i < 168; i+=3){
			//scale up
			scale(1.1f,1.1f,1.1f,i);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
    }
    if (button == 4 && state == GLUT_UP)
    {
       	mapV = (GLfloat *) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		
		for(int i=0; i < 168; i+=3){
			//scale down
			scale(0.9f,0.9f,0.9f,i);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glutPostRedisplay();
    }
}


