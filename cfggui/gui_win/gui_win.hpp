/* ************************************************************************************************/ // clang-format off
// flipflip's cfggui
//
// Copyright (c) 2021 Philippe Kehl (flipflip at oinkzwurgl dot org),
// https://oinkzwurgl.org/hacking/ubloxcfg
//
// This program is free software: you can redistribute it and/or modify it under the terms of the
// GNU General Public License as published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef __GUI_WIN_H__
#define __GUI_WIN_H__

#include <memory>
#include <cinttypes>
#include <string>

#ifdef _WIN32
#  ifndef NOGDI
#    define NOGDI
#  endif
#endif

#include "imgui.h"

#include "gui_settings.hpp"
#include "gui_widget.hpp"

/* ***** Window base class ********************************************************************** */

class GuiWin
{
    public:
        GuiWin(const std::string &name);
        virtual ~GuiWin() {};

        void                 Open();
        void                 Close();
        virtual bool         IsOpen();
        bool                *GetOpenFlag();
        const std::string   &GetName();
        const std::string   &GetTitle(); // Title with ID ("title###id")
        void                 SetTitle(const std::string &title);
        void                 Focus();
        const std::string   &GetUidStr(); // Run-time (!) UID

        virtual void         Loop(const uint32_t &frame, const double &now);

        virtual void         DrawWindow();

        bool                 ToggleButton(const char *label, const char *labelOff, bool *toggle, const char *tooltipOn, const char *tooltipOff);

    protected:
        enum POS_e : int
        {
            POS_NONE, POS_USER, POS_N, POS_NE, POS_E, POS_SE, POS_S, POS_SW, POS_W, POS_NW
        };

        std::string          _winTitle;
        std::string          _winName;
        std::string          _winImguiName;
        bool                 _winOpen;
        enum POS_e           _winPos;
        enum POS_e           _winRePos;
        enum POS_e           _winIniPos;
        ImGuiWindowFlags     _winFlags;
        ImVec2               _winSize;
        ImVec2               _winSizeMin;
        uint64_t             _winUid;
        std::string          _winUidStr;
        std::shared_ptr<GuiSettings> _winSettings;

        bool                 _DrawWindowBegin();
        void                 _DrawWindowEnd();
        void                 _DrawWindowContextMenuItems(const bool lockPosition = false);
        ImVec2               _WinSizeToVec(ImVec2 size);

    private:
};

/* ****************************************************************************************************************** */
#endif // __GUI_WIN_H__