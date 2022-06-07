/*
 * Copyright 2020~2021 SYSON, MICHAEL B.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @company: USBONG
 * @author: SYSON, MICHAEL B. 
 * @date created: 20200930
 * @date updated: 20211106
 * @website address: http://www.usbong.ph
 *
 * Acknowledgments:
 * 1) "Bulalakaw Wars" Team (2007): 
 * Syson, M., Camacho, R., Gonzales, D., Del Rosario, R., Vidal, E., et al.
 *
 */
//TO-DO: -update: this

#include "MyDynamicObject.h"
#include <stdlib.h>

/* //removed by Mike, 20210826
//added by Mike, 20210725
#include "Level2D.h"
*/

//added by Mike, 20210517
#include "UsbongUtils.h"

#include <string.h>

//edited by Mike, 20201226
//#include <windows.h> //Windows Machine
//added by Mike, 20201217
//Reference: https://stackoverflow.com/questions/34152424/autodetection-of-os-in-c-c;
//answer by: Jeegar Patel, 20151208T0940
//auto-identify if Windows Machine
#ifdef _WIN32
	#include <windows.h> //Windows Machine
#endif
/*
#ifdef linux
    printf("In Linux");
#endif
*/

//added by Mike, 20210821; edited by Mike, 20210827
//note: reverifying: use of SDL Image + OpenGL, without GLUT
#ifdef _WIN32 //Windows machine
	#include <SDL.h>
	#include <SDL_image.h>
//added by Mike, 20210825
#elif defined(__APPLE__)
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#else
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
#endif


#include <stdio.h>

//added by Mike, 20210517
MyDynamicObject::~MyDynamicObject()
{
}

//added by Mike, 202105017
void MyDynamicObject::setUsbongUtils(UsbongUtils* u)
{
     myUsbongUtils = u;
}

//added by Mike, 20201213
void MyDynamicObject::draw() {
}

void MyDynamicObject::hitBy(MyDynamicObject* mdo){
}

bool MyDynamicObject::checkIsCollidable() {
     return isCollidable;
}

void MyDynamicObject::setCollidable(bool c) {
		 //printf(">>setCollidable");
     isCollidable=c;
}

void MyDynamicObject::initializeCollisionSpheres(int ms) {
  csSize=0;
  maxSize = ms;
  collisionSpheres = (float**)malloc(maxSize*sizeof(float*));
  for(i=0; i<maxSize; i++)
    collisionSpheres[i] = (float*)malloc(4*sizeof(float)); //why 4? x y z, and radius
}

void MyDynamicObject::addSphere(float dx, float dy, float dz, float r)
{
	if(csSize!=maxSize)
	{
		collisionSpheres[csSize][0]=dx;
		collisionSpheres[csSize][1]=dy;
		collisionSpheres[csSize][2]=dz;
		collisionSpheres[csSize][3]=r;
		csSize++;
	}
	//else csSize has reached the maxSize
}

float** MyDynamicObject::getCollisionSpheres()
{
   return collisionSpheres;
}

int MyDynamicObject::getNumSpheres()
{
   return csSize;
}

/* //removed by Mike, 20210830
float MyDynamicObject::getX()
{
   return myXPos;
}
float MyDynamicObject::getY()
{
   return myYPos;
}
float MyDynamicObject::getZ()
{
   return myZPos;
}

float MyDynamicObject::getWidth()
{
   return myWidth;
}
float MyDynamicObject::getHeight()
{
   return myHeight;
}
*/

float MyDynamicObject::getDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
/*
    float dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
    char str[700];
    sprintf(str,"here: %f",dist);
    MessageBox(NULL, str, "Welcome!", MB_OK);
*/
   return /*dist;*/(float)sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

bool MyDynamicObject::checkCollision(MyDynamicObject* mdo1, MyDynamicObject* mdo2)
{
    int s1 = mdo1->getNumSpheres();
	int s2 = mdo2->getNumSpheres();
    if(s1==0||s2==0)
    {
    	return false;
    }

    float** cs1 = mdo1->getCollisionSpheres();
    float** cs2 = mdo2->getCollisionSpheres();
    for(int i = 0; i < s1; i++)
    {
    	for(int j = 0; j < s2; j++)
    	{
    		if(getDistance(cs1[i][0] + mdo1->getX(),
						   cs1[i][1] + mdo1->getY(),
						   cs1[i][2] + mdo1->getZ(),
						   cs2[j][0] + mdo2->getX(),
						   cs2[j][1] + mdo2->getY(),
						   cs2[j][2] + mdo2->getZ())
    					<=(cs1[i][3]+cs2[j][3]))
    		{
    			return true;
    	    }
        }
    }        
    return false;
}

/*	//edited by Mike, 20211106
bool MyDynamicObject::isIntersectingRect(MyDynamicObject* mdo1, MyDynamicObject* mdo2)
{     
	//TO-DO: -update: to use keyword for object size in z-axis, etc
    if (mdo2->getZ()+mdo2->getWidth() < mdo1->getZ() || //is the bottom of mdo2 above the top of mdo1?
        mdo2->getZ() > mdo1->getZ()+mdo1->getWidth() || //is the top of mdo2 below bottom of mdo1?
        mdo2->getX()+mdo2->getWidth() < mdo1->getX()  || //is the right of mdo2 to the left of mdo1?
        mdo2->getX() > mdo1->getX()+mdo1->getWidth()) {//is the left of mdo2 to the right of mdo1?
        return false;
	}
	
    return true;
}
*/
bool MyDynamicObject::isIntersectingRect(MyDynamicObject* mdo1, MyDynamicObject* mdo2)
{     
	//TO-DO: -update: to use keyword for object size in z-axis, etc
    if (mdo2->getY()+mdo2->getHeight() < mdo1->getY() || //is the bottom of mdo2 above the top of mdo1?
        mdo2->getY() > mdo1->getY()+mdo1->getHeight() || //is the top of mdo2 below bottom of mdo1?
        mdo2->getX()+mdo2->getWidth() < mdo1->getX()  || //is the right of mdo2 to the left of mdo1?
        mdo2->getX() > mdo1->getX()+mdo1->getWidth()) {//is the left of mdo2 to the right of mdo1?
        return false;
	}
	
    return true;
}

void MyDynamicObject::collideWith(MyDynamicObject* mdo)
{
/*     
    if (this==we)
	{
		return;
	}
*/
//    	printf(">>");

    if ((!checkIsCollidable())||(!mdo->checkIsCollidable()))    
    {
//    		printf(">>>>>NOT COLLIDABLE");

        return;
    }
       
//    if (checkCollision(this, mdo))
		//edited by Mike, 20210830
    if (isIntersectingRect(this, mdo))
//    if (isIntersectingRectAsPixel(this, mdo))
    {
//    	printf(">>dito>>>>>>>>>>>>>>>>>>>>>>>.");
    	
        this->hitBy(mdo);
        mdo->hitBy(this);
    }
}

/* //removed by Mike, 20210830
//added by Mike, 20210527
bool MyDynamicObject::isIntersectingRectAsPixel(MyDynamicObject* mdo1, MyDynamicObject* mdo2)
{     
	//note: computer computation correct, albeit human person may think 
	//based on observation in 3D (3-Dimensions) that beam should hit asteroid
	//alternative collision detection technique 
	//for computer to verify if not intersecting
	//Reference: Jongko, J. et al (2004)

    if (mdo2->getYAsPixel()+mdo2->getHeightAsPixel() < mdo1->getYAsPixel() || //is the bottom of mdo2 above the top of mdo1?
        mdo2->getYAsPixel() > mdo1->getYAsPixel()+mdo1->getHeightAsPixel() || //is the top of mdo2 below bottom of mdo1?
        mdo2->getXAsPixel()+mdo2->getWidthAsPixel() < mdo1->getXAsPixel()  || //is the right of mdo2 to the left of mdo1?
        mdo2->getXAsPixel() > mdo1->getXAsPixel()+mdo1->getWidthAsPixel()) {//is the left of mdo2 to the right of mdo1?
        return false;
		}
	
    return true;
}
*/

/* //removed by Mike, 20210830
//added by Mike, 20210517
//use with computer mouse, et cetera
bool MyDynamicObject::collideWithPressedCoordPos(int pressedCoordPosX, int pressedCoordPosY)	
{
		printf("pressedCoordPosX: %i\n",pressedCoordPosX);
		printf("getXAsPixel()+getWidthAsPixel(): %i\n",getXAsPixel()+getWidthAsPixel());
		
    if (pressedCoordPosX > getXAsPixel()+getWidthAsPixel() || //pressed coordinate position at right of object
        pressedCoordPosX < getXAsPixel() || //pressed coordinate position at left of object
        pressedCoordPosY < getYAsPixel() || //pressed coordinate position at top of object
		pressedCoordPosY > getYAsPixel()+getHeightAsPixel()) { //pressed coordinate position at right of object

		printf("outside button\n");
		
		return false;
	}	
	
	printf("inside button\n");
	
	return true;
}
*/

//added by Mike, 20210724; edited by Mike, 20210830
//use with Level2D
//bool MyDynamicObject::collideWithLevel2DTileRectAsPixel(int iTilePosXAsPixel, int iTilePosYAsPixel, int iTileWidthAsPixel, int iTileHeightAsPixel)	
bool MyDynamicObject::collideWithLevel2DTileRect(float fTilePosX, float fTilePosY, float fTileWidth, float fTileHeight)
{
			//note: we add iOffsetXPosAsPixel and iOffsetYPosAsPixel 
			//to cause need of bigger collision rectangle, before hit
			//tile position at right of object
			//TO-DO: -clarify: to use floating point numbers instead of integers, i.e. whole numbers
		//edited by Mike, 20210831
			if ((fTilePosX > getX()+getWidth()-iOffsetXPosAsPixel+getStepX()) || 
			 			//tile position at left of object
            (fTilePosX+fTileWidth < getX()+iOffsetXPosAsPixel -getStepX()) ||
            //tile position at top of object
            (fTilePosY+fTileHeight < getY()+iOffsetYPosAsPixel -getStepY()) || 
						//tile position at bottom of object            
            (fTilePosY > getY()+getHeight()-iOffsetYPosAsPixel +getStepY())) { 
/*
			if ((fTilePosX > getX()+getWidth()+getStepX()) || 
			 			//tile position at left of object
            (fTilePosX+fTileWidth < getX()-getStepX()) ||
            //tile position at top of object
            (fTilePosY+fTileHeight < getY()-getStepY()) || 
						//tile position at bottom of object            
            (fTilePosY > getY()+getHeight()+getStepY())) { 
*/
//			printf("outside tile\n");
			return false;
		}	

		return true;
}



//added by Mike, 20201016
void MyDynamicObject::destroy()
{
/*	
	for(int i = 0; i < MAX_EXPLOSION_PARTICLES; ++i) {
	    delete [] explosionParticle[i];
	}
	delete [] explosionParticle;
*/
}

//added by Mike, 20210826; edited by Mike, 20210827
//GLuint openGLLoadTexture(char *filename, int *textw, int *texth)
//edited by Mike, 20210831; TO-DO: -reverify: this
//GLuint MyDynamicObject::openGLLoadTexture(char *filename, float *fTextWidth, float *fTextHeight)
GLuint MyDynamicObject::openGLLoadTexture(char *filename, float fMyWidth, float fMyHeight)
{
	SDL_Surface *surface;
	GLenum textureFormat;
	GLuint texture;
	
	surface = IMG_Load(filename);
	
	if (!surface){
		return 0;
	}

//added by Mike, 20210824
//TO-DO: -add: image frame clipping
#if defined(__APPLE__)
    switch (surface->format->BytesPerPixel) {
        case 4:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
//                textureFormat = GL_BGRA;
                textureFormat = GL_RGBA;
            else
//                textureFormat = GL_RGBA;
                textureFormat = GL_BGRA;
            break;
        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
//                textureFormat = GL_BGR;
                textureFormat = GL_RGB;
            else
//                textureFormat = GL_RGB;
                textureFormat = GL_BGR;
            break;
    }
//edited by Mike, 20210905
#elif defined(_WIN32) //Windows machine    
#else
    switch (surface->format->BytesPerPixel) {
        case 4:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                textureFormat = GL_BGRA;
            else
                textureFormat = GL_RGBA;
            break;
            
        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                textureFormat = GL_BGR;
            else
                textureFormat = GL_RGB;
            break;
    }
#endif
    
	/* //edited by Mike, 20210824
	//note: 4 frames per width and height of whole texture image file
	*textw = surface->w;
	*texth = surface->h;
	*/
	
/* //removed by Mike, 20210903	
//    int iCountTotalFrames=4;
    float fCountTotalFrames=4.0f;

    if(strstr(filename, "level2D") != NULL) {
//      iCountTotalFrames=16;
     fCountTotalFrames=16.0f;
        
//        printf(">>> DITO\n");
    }
*/

/*    //edited by Mike, 20210831; TO-DO: -update: this to auto-identify total count of frames
    *fTextWidth = surface->w/fCountTotalFrames; //4;
    *fTextHeight = surface->h/fCountTotalFrames; //4;
*/
    float fTextWidth = surface->w/fCountTotalFrames; //4;
    float fTextHeight = surface->h/fCountTotalFrames; //4;

    
//    printf(">> fTextHeight %f\n",surface->h/fCountTotalFrames);
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
    
/* //edited by Mike, 20210830
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
*/
/*	//edited by Mike, 20210722; this is due to displayed image is blurred
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
     GL_LINEAR_MIPMAP_NEAREST);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
*/
    // set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    // unselect texture myFontTextureObject
//    glBindTexture(GL_TEXTURE_2D, 0);
    
    // setup alpha blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    
	glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w,
	surface->h, 0, textureFormat, GL_UNSIGNED_BYTE, surface->pixels);
	
	SDL_FreeSurface(surface);
	
	return texture;	
}
