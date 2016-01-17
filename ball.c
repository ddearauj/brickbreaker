//
//  ball.c
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#include "ball.h"

void criaBola (circ *bola){ //creates the ball
    float x2,y2;
    float angle;
    double radius = RBOLA;
    
    
    glColor3b(100,100,100);
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(bola->x,bola->y);
    
    for (angle=1.0f;angle<361.0f;angle+=0.2)
    {
        x2 = bola->x +sin(angle) * radius;
        y2 = bola->y +cos(angle) * radius;
        glVertex2f(x2,y2);
    }
    
    glEnd();
}

void moveBola (float elapsedTime, circ *bola){
    
    bola->x += bola->vx * elapsedTime;
    bola->y += bola->vy * elapsedTime;
}