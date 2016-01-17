//
//  gameManager.h
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#ifndef __BrickGame__gameManager__
#define __BrickGame__gameManager__

#include <stdio.h>
#include "brick.h"
#include "ball.h"


void lose (int *onGame, int *winLose);

void win (int *onGame, int *winLose);

int winCheck (brick *bloco);

void colisao (circ *bola, int xbarra, brick *bloco);

void resetGame (circ *bola, brick *bloco, int *onGame, float *xbarra, int *preStart);

void tempo(int *lastFrameTime, float *elapsedTime);

void preformCheck(int *onGame, int *winLose, brick *bloco, circ bola);

void output(int x, int y, float r, float g, float b, void *font, char *string);

void drawAll (int onGame, brick *bloco, float *xbarra, int command, float *elapsedTime, circ *bola, int preStart, int winLose);


#endif /* defined(__BrickGame__gameManager__) */
