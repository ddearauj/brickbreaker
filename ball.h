//
//  ball.h
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#ifndef __BrickGame__ball__
#define __BrickGame__ball__

#include <stdio.h>
#include "pad.h"

typedef struct circ{ //coordinates
    float x;
    float y;
    
    int vx;
    int vy;
    
}circ;

#define RBOLA 5 //ball radious
#define VBOLAX 300 //ball y speed
#define VBOLAY 300 // ball x speed

void criaBola (circ *bola);

void moveBola (float elapsedTime, circ *bola);

#endif /* defined(__BrickGame__ball__) */
