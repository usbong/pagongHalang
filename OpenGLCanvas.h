/*
 * Copyright 2020~2022 SYSON, MICHAEL B.
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
 * @date created: 20200929
 * @date updated: 20220119; from 20211103
 * @website address: http://www.usbong.ph
 *
 * Acknowledgments:
 * 1) "Bulalakaw Wars" Team (2007):
 * Syson, M., Camacho, R., Gonzales, D., Del Rosario, R., Vidal, E., et al.
 *
 */

//TO-DO: -update: "Canvas" to "Engine"?
//TO-DO: -update: this

#ifndef OPENGLCANVAS_H
#define OPENGLCANVAS_H

//added by Mike, 20201207
//auto-identify if Windows Machine
#ifdef _WIN32
#include <windows.h> //Windows Machine
#endif
/*
 #ifdef linux
 printf("In Linux");
 #endif
 */

//added by Mike, 20210818
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

//#include "CTargaImage.h"

/* //removed by Mike, 20200929
 #include "MyDynamicObject.h"
 #include "Sound.h"
 */

#include <stdio.h>
//added by Mike, 20201213
#include <vector>

//added by Mike, 20210502
#include <math.h>

#define PI 3.14159
#define TWO_PI PI*2.0
#define HALF_PI PI/2.0
#define TRUE 1
#define FALSE 0

#define FONT_TEXTURE 2
#define LEVEL_TEXTURE 3 //added by Mike, 20201122

//TO-DO: -update: this
#define KAHON_TEXTURE 4 //added by Mike, 20210402
#define ARMOR_TEXTURE 5 //added by Mike, 20210412
#define BAHAY_TEXTURE 6 //added by Mike, 20210418

//added by Mike, 20210420
//TO-DO: -update: this
//TO-DO: -add: texture definitions in PolygolUtils
#define MIKE_TEXTURE_A 7 //added in Pilot.h
#define MIKE_TEXTURE_B 8
#define MIKE_TEXTURE_C 9

//added by Mike, 20210507
#define ROBOT_TEXTURE_A 10

//added by Mike, 20210521
#define BUTTON_TEXTURE_A 11

//added by Mike, 20210613
#define TEXT_TEXTURE_A 12

//added by Mike, 20210524; edited by Mike, 20210613
#define BALL_TEXTURE_A 13

#define LEVEL_2D_TEXTURE 14 //added by Mike, 20210704

#define MAX_ENEMY 2

//edited by Mike, 20201013
//#define MAX_BEAMS 5
//added by Mike, 20201214
//TO-DO: -update: this
#define MAX_BEAMS 32

//edited by Mike, 20201016
//#define MAX_ASTEROID 28 //groups of 3, therefore 4 groups, plus inner groupings
//edited by Mike, 20201017
//#define MAX_ASTEROID 4
#define MAX_ASTEROID 16

#define MAX_LIFE 3
#define REQUIRED_POINTS_FOR_BONUS 30000 //5000

//added by Mike, 20201213
//includes: pilot, robotship, beams, asteroid,
//edited by Mike, 20210120
//#define MAX_DYNAMIC_OBJECT 50 //TO-DO: -update: this

//edited by Mike, 20210206; edited by Mike, 20210502
//#define MAX_DYNAMIC_OBJECT 18 //remove beams x32
//edited by Mike, 20210521
//#define MAX_DYNAMIC_OBJECT 19 //add pilotPlayer2

//edited by Mike, 20210522
//#define MAX_DYNAMIC_OBJECT 1 //pilotPlayer1 only
//edited by Mike, 20210524
//#define MAX_DYNAMIC_OBJECT 2 //pilotPlayer1 and pilotPlayer2
#define MAX_DYNAMIC_OBJECT 3 //pilotPlayer1, pilotPlayer2, and Ball

//#define MAX_DYNAMIC_OBJECT 17 //remove beams x32

#define MAX 1026 //buffer
#define LINE_POINTS_SET 4 //added by Mike, 20210513

#define TITLE_SCREEN 0
#define CONTROLS_SCREEN 1
#define GAME_SCREEN 2
#define GAMEOVER_SCREEN 3
#define HIGHSCORE_SCREEN 4

#define ROBOTSHIP_INITIALIZING_STATE 0

//added by Mike, 20201123
#define GL_CLAMP_TO_EDGE 0x812F

//added by Mike, 20210207
#define FACING_UP 0
#define FACING_DOWN 1
#define FACING_LEFT 2
#define FACING_RIGHT 3
//diagonal
#define FACING_LEFT_AND_UP 4
#define FACING_RIGHT_AND_UP 5
#define FACING_LEFT_AND_DOWN 6
#define FACING_RIGHT_AND_DOWN 7

//added by Mike, 20211025
#define MAX_PILOT_KEY_DOWN_HISTORY 100 //5

//added by Mike, 20211027
#define MAX_ROBOTSHIP_COUNT 3

//added by Mike, 20210827
class Level2D;

//added by Mike, 20210925
class Level3D;

class Pilot;
class Text; //added by Mike, 20210902

class Robotship; //added by Mike, 20211025

/* //removed by Mike, 20210825
class MyDynamicObject; //added by Mike, 20201213


//added by Mike, 20210514
class Button;

//added by Mike, 20210613
class Text;

//class Enemy; //removed by Mike, 20201013
class Beam;
class Asteroid;

//added by Mike, 20210516
class UsbongUtils;

class Level; //added by Mike, 20201118


class Ball; //added by Mike, 20210524
*/

class OpenGLCanvas
{
private:
/* //removed by Mike, 20210825
    RobotShip *myRobotShip,
    *myRobotShipPlayer2;
*/    
    //added by Mike, 20210827
    Level2D *myLevel2D;
    
    //added by Mike, 20210925
    Level3D *myLevel3D;
        
    Pilot *myPilot;
    Robotship *myRobotship; //added by Mike, 20211025

    Robotship *myRobotshipContainer[MAX_ROBOTSHIP_COUNT]; //added by Mike, 20211025
    //added by Mike, 20211027
    int iPrevPilotKeyDownContainer[MAX_ROBOTSHIP_COUNT];
    
    
    Text *myText; //added by Mike, 20210902
    
    //added by Mike, 20211025
    int iArrayPilotKeyDownHistoryContainer[MAX_PILOT_KEY_DOWN_HISTORY];
    int iPilotKeyDownCount;
    int iDelayExecuteKeyDownMovement;
    int iDelayExecuteKeyDownMovementMax;
    
    //added by Mike, 20211103
    int iPrevIndexCount;

/* //removed by Mike, 20210825
    Pilot *myPilotPartner; //added by Mike, 20210530
    
    //added by Mike, 20210502
    Pilot *myPilotPlayer2;
    Pilot *myPilotPlayer2Partner; //added by Mike, 20210530
    
    //added by Mike, 20210514
    //TO-DO: -update: this
    Button *myButton;
    
    //added by Mike, 20210613
    Text *myText;
    
    //added by Mike, 20210524
    Ball *myBall;
    
    
    //added by Mike, 20210516
    UsbongUtils *myUsbongUtils;
    
    //added by Mike, 20201118
    Level *myLevel;

    //added by Mike, 20210703
    Level2D *myLevel2D;
    
    //Enemy *myEnemy[MAX_ENEMY];
    //removed by Mike, 20201013
    //        Enemy *myEnemy;
    
    Beam *myBeam[MAX_BEAMS];iPilotKeyDownCount
    
    //added by Mike, 20201014
    Asteroid *myAsteroid[MAX_ASTEROID];
    //        Asteroid *myAsteroid;
*/
    
/* //removed by Mike, 20210825    
    //added by Mike, 20201213
    //TO-DO: -add: level tile boxes, e.g. parts of tree
    //TO-DO: -update: MAX_DYNAMIC_OBJECT value
    //MyDynamicObject *myDynamicObjectContainer[MAX_DYNAMIC_OBJECT];
    //std::vector<MyDynamicObject> items;
    std::vector<MyDynamicObject*> vMyDynamicObjectContainer;
*/
		//added by Mike, 20210825
		SDL_Renderer *mySDLRenderer;
		SDL_Texture *texture;

		//added by Mike, 20210826
		GLuint openGLITexture;
				
		int iPilotX;
		int iPilotY;				
				
    char *infile;//= "Patches1.txt";
    char *outfile;
    FILE *in;
    FILE *out;
    char buffer[MAX];
    
    float rotationAngle;
    
    //added by Mike, 20210513
    int stepHistoryList[MAX][LINE_POINTS_SET];
    int stepHistoryListCount;
    
    int myKeysDown[10];
    
    //added by Mike, 20210510
    int myMouseActionDown[1];
    
    float rotationSpeed;
    
    int myRepaintCounter;
    int myRepaintDelay;
    
    char tempText[50];
    int score,
    rest,
    restPlayer2,
    missiles,
    highScore,
    numOfAsteroidsLeft,
    currFrame,
    keyPressCounter,
    scoreBeforeBonus;
    bool isTwoPlayers;
    
    //added by Mike, 20201023; edited by Mike, 20201025
    //TO-DO: -update: container names in RobotShip.cpp, etc
    float myCanvasPosX,
    myCanvasPosY,
    myCanvasPosZ;
    
    float myCanvasStepX,
    myCanvasStepY,
    myCanvasStepZ,
    myCanvasEyeStepX,
    myCanvasRotateAxisStepY, //added by Mike, 20201024
    //added by Mike, 20201025
    myCanvasLookAtAngle,
    myCanvasEyePosX,
    myCanvasEyePosY,
    myCanvasEyePosZ,
    myCanvasCenterPosX,
    myCanvasCenterPosY,
    myCanvasCenterPosZ,
    //added by Mike, 20201026
    myCanvasLookAtAngleRad,
    xAccel,
    yAccel,
    zAccel;
    
    //grid
    int iRowCountMax,
	 			iColumnCountMax,
    iHeightCountMax; //added by Mike, 20210208
    
    //TO-DO: -update: this to use "x", "y", "z" keywords
    float fGridSquareWidth,
    	    fGridSquareHeight;
    
    bool hasTurnedNinetyDegCounterClockWise,
			 hasTurnedNinetyDegClockWise;
			 
    //added by Mike, 20210416
    float fKahonRotation;
    
    //added by Mike, 20210325
    //TO-DO: -update: this
    int iCountLevelM;
    
    //added by Mike, 20210420
    //TO-DO: -update: this
    int iCountTaoAnimationFrame;
    //		int iTaoAnimationFrameOffset;
    float fTaoAnimationFrameOffset;
    
    //unsigned int myFontTextureObject;
    
    unsigned int myFontListBase;
    
    //added by Mike, 20210512
    bool hasPressedMouseActionDown;
    
    //removed by Mike, 20200930, due to Linux Machine
    //        HDC hDC;
    
    //CTargaImage *myBackground,
    //            *myFont;
    unsigned int currTextureBackground,
    myTextureObjectFont,
    titleBackground,
    gameBackground;
    bool loadBackground();
    bool setupProjection();
    //removed by Mike, 20200930
    //void drawPlane();
    void drawGrid();
    
    //added by Mike, 20201020
    void drawGridWithZAxis();
    
    void gameReset();
    void resetDynamicObjects();

    //added by Mike, 20210402
    void setupKahonTexture(int myKahonTextureObject);
    
    //added by Mike, 20210420
    //TO-DO: -update: this
    void setupTaoTexture();
    
    //added by Mike, 20210412
    void drawKahonWithTextureForVerification();
    
    //added by Mike, 20210511
    float autoConvertFromPixelToVertexPointX(int iPointX);
    float autoConvertFromPixelToVertexPointY(int iPointY);
    
public:
    OpenGLCanvas();
    ~OpenGLCanvas();
    //virtual ~CGfxOpenGL();
    
    /*		//removed by Mike, 20200929
     Sound *sound;
     SoundClip *beam, *valkyrie, *explosion, *zing, *thrust, *rotate, *bonus, *title;
     */
     
    //added by Mike, 20201015
    /* //edited by Mike, 20210625
    	int myWindowWidth;
    	int myWindowHeight;
     */
    float myWindowWidth;
    float myWindowHeight;
    
    //declared as static, i.e. final, container with value in mainLinux.cpp
    //added by Mike, 20210606
    //edited by Mike, 20210625; edited by Mike, 20210726
     int myWindowWidthAsPixel;
     int myWindowHeightAsPixel;
/*
    float myWindowWidthAsPixel;
    float myWindowHeightAsPixel;
*/
    //added by Mike, 20210626
    float fMyWindowWidthAsPixelRatioToHeightPixel;
    int iMyWindowWidthAsPixelOffset; //added by Mike, 20210702
    
    /*		int myWindowWidthAsPixelOpenGLCanvas;
     int myWindowHeightAsPixelOpenGLCanvas;
     */
     
    //added by Mike, 20210826
    int iTextureWidth, iTextureHeight;
          
    //added by Mike, 20210510
    int iStartPointX,
    iStartPointY,
    iEndPointX,
    iEndPointY;
    
    int currentState;
    
    //edited by Mike, 20210517
    //    	bool init();
    //edited by Mike, 20210725; edited again by Mike, 20210825
//    bool init(int myWindowWidthAsPixelInput, int myWindowHeightAsPixelInput);
    bool init(int myWindowWidthAsPixelInput, int myWindowHeightAsPixelInput, SDL_Renderer *mySDLRenderer);
    //bool init(float myWindowWidthAsPixelInput, float myWindowHeightAsPixelInput);
    
    bool shutdown();
    
    void keyDown(int keyCode);
    void keyUp(int keyCode);
    
    void mouseActionDown(int mouseActionId, int iXPos, int iYPos);
    void mouseActionUp(int mouseActionId, int iXPos, int iYPos);
    
    //added by Mike, 20210514
    void mouseMotionActionDown(int mouseActionId, int iXPos, int iYPos);
    
    //void Prepare(float dt);
    void renderPrev(); //edited by Mike, 20210825    
    void render();
    void update();
    void updateBuggy(); //added by Mike, 20220119
    
    void addScore(int s);
    void loseLife();
    void changeState(int s);		
};

#endif
