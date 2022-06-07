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
 * @date created: 20201010
 * @date updated: 20211009
 *
 * Acknowledgments:
 * 1) "Bulalakaw Wars" Team (2007): 
 * Syson, M., Camacho, R., Gonzales, D., Del Rosario, R., Vidal, E., et al.
 *
 */
#include <stdlib.h> 

//edited by Mike, 20201011
//#include <string.h>
#include <string>

//added by Mike, 20211008
#include "MyDynamicObject.h"

//added by Mike, 20210516
class UsbongUtils;

class Font: public MyDynamicObject
{
private:
		float fMyWindowWidth,
					fMyWindowHeight;
					
    float myWidth,
    		  myHeight;    
					
		GLboolean test_pow2(GLushort i);
		
public:
    Font(float fWindowWidth, float fWindowHeight);    
    ~Font();
    
    //added by Mike, 20211008
    Font(float xPos, float yPos, float zPos, float fWindowWidth, float fWindowHeight);
    
    UsbongUtils *myUsbongUtils;

		//edited by Mike, 20210903 
		void setupFontPrev(int myFontTextureObject);
		
		GLuint setupFont(char *filename, float fMyWidth, float fMyHeight);
		GLuint openGLLoadTexture(char *filename, float fMyWidth, float fMyHeight);
		
		//edited by Mike, 20201017
		//void draw_string(GLfloat x, GLfloat y, char *string);
		//void draw_char(GLfloat x, GLfloat y, char c);
		/* //edited by Mike, 20210903
		void draw_string(GLfloat x, GLfloat y, GLfloat z, char *string);
		void draw_char(GLfloat x, GLfloat y, GLfloat z, char c);
		*/
		void draw_string(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char *string);
        //added by Mike, 20211008
        void draw_stringBuggy(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char *string);
        void draw_stringOKDrawsRedTriangle(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char *string);
        //added by Mike, 20211009; TO-DO: -update: to use string and char
        void draw_stringCharOutputOK(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char *string);
    
        void draw_char(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char c);
    
        //added by Mike, 20211009
        void draw_charPrev(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char c);

		//edited by Mike, 20211005
		void draw_charRedSquareOK(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char c);
		void draw_charBuggy(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char c);
		void draw_charWith2DLevelOK(GLuint glIFontTexture, GLfloat x, GLfloat y, GLfloat z, char c);
		
		//void draw_string(GLfloat x, GLfloat y, std::string string);
};
	
