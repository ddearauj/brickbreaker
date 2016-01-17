//
//  main.c
//  BrickGame
//
//  Created by Daniel Pereira, Rafael Hesse and Fernando Salhani on 14/11/12.
//  Copyright (c) 2012 RDF. All rights reserved.
//

#include "gameManager.h"

brick *bloco = NULL;
float xbarra = (LARGURA-LBARRA)/2;
int lastFrameTime;
float elapsedTime;
circ bola;
int k = 2;
int onGame = 1;
int winlose = 0;
int preStart = 1;

//Some glut functions do not accept parameters, therefore this file will have some global variables solely for these funcitons

void keyboard(int key, int x, int y){
    
    
    //pad movement
    if(xbarra >=0 && xbarra + LBARRA <= LARGURA){
        if (key == GLUT_KEY_LEFT && xbarra > 0)
            k = 0;
        if (key == GLUT_KEY_RIGHT && xbarra + LBARRA < LARGURA)
            k = 1;
    }
    else{
        if(xbarra <= 0)
            xbarra=0;
        if(xbarra + LBARRA > LARGURA)
            xbarra = LARGURA - LBARRA;
        k = 2;
    }
    //MOVIMENTO BARRA
    
    //if yes
    if (key == 115){
        if(onGame == 0)
            resetGame(&bola, bloco, &onGame, &xbarra, &preStart);
    }
    //SIM
    
    //NAO
    if (key==110){
        if(onGame==0)
            exit(0);
    }
    //NAO
    
    //ESC
    if (key==27){
        exit(0);
    }
    //ESC
    
    //SPACE
    if(key==32) preStart=0;
    //SPACE
    
    glutPostRedisplay();
}

void keyboardup(int key, int x, int y){
    if (key == GLUT_KEY_LEFT)
        k = 2;
    if (key == GLUT_KEY_RIGHT)
        k = 2;
    
}


void display(void){
    
    tempo(&lastFrameTime, &elapsedTime);
    preformCheck(&onGame, &winlose, bloco, bola);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawAll(onGame, bloco, &xbarra, k, &elapsedTime, &bola, preStart, winlose);
    glutSwapBuffers();
    
}

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glutInitWindowSize(LARGURA, ALTURA);
}

void idle(void){
    glutPostRedisplay();
}





int main (int argc, char** argv){
    
    bola.x = (LARGURA)/2;
    bola.y = HBARRA + RBOLA + 0.1;
    bola.vx = VBOLAX;
    bola.vy = VBOLAY;
    
    //allocate bricks
    bloco = (brick *)malloc(NBLOCOS*sizeof(brick));
    //fillMatrix(bloco);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(LARGURA, ALTURA);
    glutCreateWindow("BrickGame");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutSpecialFunc(keyboard);
    glutSpecialUpFunc(keyboardup);
    fillMatrix(bloco);
    
    glutMainLoop();
}
