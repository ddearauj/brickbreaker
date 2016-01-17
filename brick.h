//
//  brick.h
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#ifndef __BrickGame__brick__
#define __BrickGame__brick__

#include <stdio.h>
#include "screen.h"

typedef struct brick {
    int live; //if it is on screen. if true = 1
    float x;
    float y;
}brick;

#define NBLOCOS 30 //number of bricks
#define HBLOCO 10  //brick height
#define LBLOCO 75 // brick width

float xbloco (int n);

float ybloco (int n);

void rect (brick *bloco);

void fillMatrix(brick *bloco);

#endif /* defined(__BrickGame__brick__) */
