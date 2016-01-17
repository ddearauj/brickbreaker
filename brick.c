//
//  brick.c
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#include "brick.h"

float xbloco (int n){ //defining the x position based on the number of bricks on the row
    float x = ((LBLOCO+5)*n)%(LARGURA+5);
    return x;
}

float ybloco (int n){ //defining the brick y coordinate based on the number of rows we already have
    int aux = ((LBLOCO+5)*n)/(LARGURA+5);
    float y = ALTURA-aux*(HBLOCO+5);
    return y;
}

void rect (brick *bloco){ //painting the bricks
    for (int i = 0; i < NBLOCOS; i++){
        if(bloco[i].live){
            int aux = ((LBLOCO+5) * i)/(LARGURA+5);
            glColor3b(127-15 * aux, 127, 0);
            glBegin(GL_QUADS);
            glVertex2f(bloco[i].x, bloco[i].y);
            glVertex2f(bloco[i].x + LBLOCO, bloco[i].y);
            glVertex2f(bloco[i].x + LBLOCO, bloco[i].y - HBLOCO);
            glVertex2f(bloco[i].x, bloco[i].y - HBLOCO);
            glEnd();
        }
    }
}

void fillMatrix(brick *bloco){ // filling the brick array
    for (int i = 0; i < NBLOCOS; i++){
        bloco[i].live = 1;
        bloco[i].x = xbloco(i);
        bloco[i].y = ybloco(i);
    }
}