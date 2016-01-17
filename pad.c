//
//  pad.c
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#include "pad.h"


void criaBarra (float *xbarra, int command, float *elapsedTime){
    if (command == 0)
        *xbarra -= VBARRA * *elapsedTime;
    if (command == 1)
        *xbarra += VBARRA * *elapsedTime;
    
    glPushMatrix();
    
    glTranslatef(*xbarra, 0.0, 0.0);
    glColor3f(100, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f( 0.0, 0.0);
    glVertex2f(LBARRA, 0.0);
    glVertex2f(LBARRA, HBARRA);
    glVertex2f( 0.0, HBARRA);
    glEnd();
    glPopMatrix();
}