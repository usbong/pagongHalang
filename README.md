# Usbong Pagong (HALANG)
Set of computer instructions with reusable component parts;<br/> 
<b>MAIN:</b> PAHALANG na pagkilos

### keyphrase:
Simple Directmedia Layer (SDL) <b>AND</b> Open Graphics Library (OpenGL)<br/>
<br/>
where: SDL : compression techniques<br/>
OpenGL : 3D Graphics techniques

## Objective
Continue to increase know-how to build Electronic Book Readers with Human-Computer Interactivity<br/>
<br/>

<b>Recommended Action:</b><br/>
--> verify: [CAPCOM GHOSTS'N GOBLINS (G'NG) Year 1985 Family Computer](https://github.com/usbong/documentation/blob/master/Usbong/R%26D/Notes/ComputerInteractiveLessonsLearned/GHOSTS'N%20GOBLINS.md)<br/>

# 1. Example
## 1.1. Horizontal Scroll Movement
<img src="https://github.com/usbong/pagong/blob/main/screenshots/usbongPagongHorizontalScrollMovementOKV20210920T1513.gif" width="60%">
<br/>
TO-DO: -update: image animation file 

# 2. Additional References
## 2.1. [Usbong Pagong](https://github.com/usbong/pagong)<br/>
--> Super Mario Story 64; Spritesheet<br/>

## 2.2. Web Service: Math is Fun
### Example: https://www.mathsisfun.com/algebra/sohcahtoa.html; last accessed: 20210922

# 3. Library Requirements
Library: set of reusable instructions

## 3.1. Simple Directmedia Layer (SDL): SDL version 2.0, SDL Image, SDL Mixer<br/>
https://www.libsdl.org/download-2.0.php; last accessed: 20210922<br/>
--> <b>Recommendation:</b> Reuse Image Compression instructions, e.g. loading .png image files<br/>
--> https://www.libsdl.org/projects/SDL_mixer/release/; last accessed: 20230629<br/>
--> version: SDL Mixer 2.0.4<br/>

<img src="https://github.com/usbong/pagongHalang/blob/main/notes/usbongUpdateFileLocationsSDLLibraryNotesV20230629T1520.png" width="100%">


### Note: OS 32-bit system instructions; update to use 64-bit

DevCPP

Project -> Project Options -> Parameters

"C:/Program Files/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libopengl32.a"

"C:/Program Files/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libglu32.a"

"C:/Program Files/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libglut32.a"

"C:/Usbong/SDL2-2.0.12/lib/x86/SDL2.dll"

"C:/Usbong/SDL2_image-2.0.5/lib/x86/SDL2_image.dll"

"C:/Program Files/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libgdi32.a"

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/SDL2_mixer.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libFLAC-8.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libmodplug-1.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libmpg123-0.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libogg-0.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libopus-0.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libopusfile-0.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libvorbis-0.dll

C:/Usbong/SDL2_mixer-2.0.4/lib/x86/libvorbisfile-3.dll

## -- 

https://stackoverflow.com/questions/17988904/compile-64-bit-binary-with-mingw-dev-c; last accessed: 20230706

> Dev-C++ setup bundled with mingw 64-bit compiler under Orwell Dev-C++'s download section. Make sure you choose "TDM-GCC x64 4.7.1" either setup or portable.

http://orwelldevcpp.blogspot.com/; last accessed: 20230706

DEV CPP


## 3.2. Open Graphics Library (OpenGL)
https://www.opengl.org/; last accessed: 20210922<br/>
--> <b>Recommendation:</b> Not to add OpenGL instructions for computer machines with classification:<br/> 
32-bit Operating System (OS) without 3-D Graphic Acceleration Card

### 3.2.1. Installation Instructions:
Enter the following COMMANDS in the Terminal Window:<br/>
<b>sudo apt-get install mesa-utils</b><br/>
<b>sudo apt-get install freeglut3-dev</b><br/>
<br/>
<b>Reference:</b><br/>
https://askubuntu.com/questions/96087/how-to-install-opengl-glut-libraries;<br/>
last accessed: 20220310<br/>
answer by: A-Sharabiani, 20170719T1535<br/>
edited by: Amir, 20180425T1940<br/>

# 4. Add-on Software Tools
## 4.1. [LibreOffice Calc: Spreadsheet](https://www.libreoffice.org/discover/calc/)<br/>
--> <b>Note:</b> Row & Column Editing Tool

## 4.2. [GNU Image Manipulation Program (GIMP)](https://www.gimp.org/)<br/>
--> <b>Note:</b> Multi-layered Image Editing Tool with Compression Techniques, e.g. .png, .jpg. 

## 4.3. [Microsoft Paint](https://support.microsoft.com/en-us/windows/get-microsoft-paint-a6b9578c-ed1c-5b09-0699-4ed8115f9aa9)
--> <b>Note:</b> Quick Single-layered Image Editing Tool

# 5. Open Source Software License
Copyright 2021~2023 SYSON, MICHAEL B.

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

@company: USBONG<br/>
@author: SYSON, MICHAEL B.<br/>
@website address: http://www.usbong.ph<br/>
