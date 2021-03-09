////////////////////////////////////////////////////////////////////////////
//   This program is free software; you can redistribute it and/or modify //
//   it under the terms of the GNU General Public License as published by //
//   the Free Software Foundation; either version 2 of the License, or    //
//   (at your option) any later version.                                  //
//                                                                        //
//   This program is distributed in the hope that it will be useful,      //
//   but WITHOUT ANY WARRANTY; without even the implied warranty of       //
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        //
//   GNU General Public License for more details.                         //
//                                                                        //
//   Inspiration and definitions from:                                    //
//   https://code.google.com/archive/p/spotifycmd/                        //
////////////////////////////////////////////////////////////////////////////
#pragma once

using namespace std;

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <tchar.h>

#define VERSION "1.0"

#define APPCOMMAND 0x0319

#define CMD_PLAYPAUSE 917504
#define CMD_MUTE 524288
#define CMD_VOLUMEDOWN 589824
#define CMD_VOLUMEUP 655360
#define CMD_STOP 851968
#define CMD_PREVIOUS 786432
#define CMD_NEXT 720896