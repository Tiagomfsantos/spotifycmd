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
#include "spotify_CMD.h"

int main(int argc, char **argv)
{
   if (argc > 1)
   {
      HWND window_handle = FindWindow(L"SpotifyMainWindow", NULL);

      if (window_handle == NULL)
      {
         cout << "ERROR" << std::endl;
         cout << "Can not find spotify, is it running?" << std::endl;
         return 1;
      }

      char buffer[512] = "";
      string artistName = "";
      string songName = "";

      if (GetWindowText(window_handle, buffer, sizeof(buffer)) > 0)
      {
         std::string title = buffer;

         std::string::size_type pos1 = title.find('-');
         std::string::size_type pos2 = title.find(static_cast<char>(-106));

         if (pos1 != std::string::npos && pos2 != std::string::npos)
         {
            pos1 += 2;
            artistName = title.substr(pos1, pos2 - pos1 - 1);
            songName = title.substr(pos2 + 2);
         }
      }

      std::string command = argv[1];

      if (command == "playpause")
      {
         SendMessage(window_handle, APPCOMMAND, 0, CMD_PLAYPAUSE);
         std::cout << "OK" << std::endl;
         return 0;
      }
      else if (command == "next")
      {
         SendMessage(window_handle, APPCOMMAND, 0, CMD_NEXT);
         std::cout << "OK" << std::endl;
         return 0;
      }
      else if (command == "prev")
      {
         SendMessage(window_handle, APPCOMMAND, 0, CMD_PREVIOUS);
         std::cout << "OK" << std::endl;
         return 0;
      }
      else if (command == "stop")
      {
         SendMessage(window_handle, APPCOMMAND, 0, CMD_STOP);
         std::cout << "OK" << std::endl;
         return 0;
      }
      else if (command == "mute")
      {
         SendMessage(window_handle, APPCOMMAND, 0, CMD_MUTE);
         std::cout << "OK" << std::endl;
         return 0;
      }
      else if (command == "volup")
      {
         SendMessage(window_handle, APPCOMMAND, 0, CMD_VOLUMEUP);
         std::cout << "OK" << std::endl;
         return 0;
      }
      else if (command == "voldown")
      {
         SendMessage(window_handle, APPCOMMAND, 0, CMD_VOLUMEDOWN);
         std::cout << "OK" << std::endl;
         return 0;
      }
      else if (command == "status")
      {
         if (artistName == "" && songName == "")
         {
            std::cout << "WARN" << std::endl;
            std::cout << "Playback paused" << std::endl;
         }
         else
         {
            std::cout << "OK" << std::endl;
            std::cout << artistName << std::endl;
            std::cout << songName << std::endl;
         }

         return 0;
      }
   }

   std::cout << "spotify_cmd version " << VERSION << ", copyright by Tiago Santos 2021 (tiagomfsantos@yahoo.com)" << std::endl;
   std::cout << "Usage:" << " ./spotify_cmd [playpause|prev|next|stop|mute|volup|voldown|status]" << std::endl;
   return 0;
}
