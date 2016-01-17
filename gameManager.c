//
//  gameManager.c
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#include "ball.h"
#include "brick.h"
#include "pad.h"


void lose (int *onGame, int *winLose){
    *onGame = 0;
    *winLose = 0;
    
}

void win (int *onGame, int *winLose){
    *onGame = 0;
    *winLose = 1;
}

int winCheck (brick *bloco){
    for (int i = 0; i < NBLOCOS; i++) {
        if (bloco[i].live == 1) {
            return 0;
        }
    }
    return 1;
}

void colisao (circ *bola, int xbarra, brick *bloco){
    int i;
    
    //checl ball pad collision
    if (bola->y - RBOLA <= HBARRA && bola->x >= xbarra && bola->x<= xbarra+LBARRA){
        if(bola->vx > 0){
            bola->vx = VBOLAX + 2*abs(bola->x - xbarra);
        }
        else{
            bola->vx = -(VBOLAX + 2*abs(bola->x-xbarra));
        }
        bola->vy = -bola->vy;
        bola->y = bola->y + 1;
    }
    
    //check ball screen collision
    if ((bola->x - RBOLA) <= 0){
        bola->vx = -bola->vx;
        bola->x = RBOLA + 0.1;
    }
    if ((bola->x + RBOLA) >= LARGURA){
        bola->vx = -bola->vx;
        bola->x = LARGURA - RBOLA - 0.1;
    }
    if ((bola->y + RBOLA) >= ALTURA) {
        bola->vy = -bola->vy;
    }
    
    //check ball brick collision
    
    //create check colision from below e etc
    
    for(i = 0;i < NBLOCOS; i++){
        if(bloco[i].live == 1){
            if(bola->y + RBOLA >= bloco[i].y - HBLOCO){
                if(bola->y + RBOLA <= bloco[i].y + 1){
                    if(bola->x >= bloco[i].x){
                        if(bola->x <= bloco[i].x + LBLOCO){
                            bola->vy = -bola->vy;
                            bloco[i].live = 0;
                        }
                    }
                }
            }
            if(bola->y + RBOLA >= bloco[i].y - 1){
                if(bola->y + RBOLA <= bloco[i].y){
                    if(bola->x >= bloco[i].x){
                        if(bola->x <= bloco[i].x + LBLOCO){
                            bola->vy = -bola->vy;
                            bloco[i].live = 0;
                            
                        }
                    }
                }
            }
            if(bola->x + RBOLA >= bloco[i].x){
                if(bola->x + RBOLA <= bloco[i].x + 1){
                    if(bola->y <= bloco[i].y){
                        if(bola->y >= bloco[i].y - HBLOCO){
                            bola->vx = -bola->vx;
                            bloco[i].live = 0;
                        }
                    }
                }
            }
            if(bola->x- RBOLA <= bloco[i].x + LBLOCO){
                if(bola->x + RBOLA >= bloco[i].x + LBLOCO - 1){
                    if(bola->y <= bloco[i].y){
                        if(bola->y >= bloco[i].y - HBLOCO){
                            bola->vx = -bola->vx;
                            bloco[i].live = 0;
                        }
                    }
                }
            }
            
            
        }
    }
}

void resetGame (circ *bola, brick *bloco, int *onGame, int *xbarra, int *preStart){
    bola->x = (LARGURA)/2;
    bola->y = HBARRA + RBOLA + 0.1;
    *onGame = 1;
    fillMatrix(bloco);
    bola->vx = VBOLAX;
    bola->vy = VBOLAY;
    *xbarra=(LARGURA-LBARRA)/2;
    *preStart = 1;
}

void tempo(int *lastFrameTime, float *elapsedTime){
    if (*lastFrameTime == 0){
        *lastFrameTime = glutGet(GLUT_ELAPSED_TIME);
    }
    int now = glutGet(GLUT_ELAPSED_TIME);
    int elapsedMilliseconds = now - *lastFrameTime;
    *elapsedTime = elapsedMilliseconds/1000.0;
    *lastFrameTime = now;
}

void preformCheck(int *onGame, int *winLose, brick *bloco, circ bola){
    if(bola.y < 0) lose(onGame, winLose);
    if(winCheck(bloco) == 1 ) win(onGame, winLose);
}

void output(int x, int y, float r, float g, float b, void *font, char *string){
    
    glColor3f( r, g, b );
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void drawAll (int onGame, brick *bloco, float *xbarra, int command, float *elapsedTime, circ *bola, int preStart, int winLose){ //game loop!
    if(onGame){
        rect(bloco);
        criaBarra(xbarra, command, elapsedTime);
        criaBola(bola);
        if(preStart) {
            bola->x = *xbarra + LBARRA/2;
        }
        else{
            colisao(bola, *xbarra, bloco);
            moveBola(*elapsedTime, bola);
        }
    }else{
        if(winLose == 0){
            output(70, ALTURA/2, 127, 0, 0, GLUT_BITMAP_HELVETICA_18, "Voce perdeu! Jogar novamente? (S/N)");
        }else{
            output(75, ALTURA/2, 0, 127, 0, GLUT_BITMAP_HELVETICA_18, "Voce venceu! Jogar novamente (S/N)");
        }
    }
}
