//
//  pad.h
//  BrickGame
//
//  Created by Daniel Pereira on 1/15/16.
//  Copyright (c) 2016 RDF. All rights reserved.
//

#ifndef __BrickGame__pad__
#define __BrickGame__pad__

#include <stdio.h>
#include "screen.h"

#define LBARRA 50 // pad width
#define HBARRA 10 // pad height
#define VBARRA 300 // pad speed

void criaBarra (float *xbarra, int command, float *elapsedTime);

#endif /* defined(__BrickGame__pad__) */
