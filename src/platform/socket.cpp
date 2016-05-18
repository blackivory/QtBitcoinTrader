//  This file is part of Qt Bitcion Trader
//      https://github.com/JulyIGHOR/QtBitcoinTrader
//  Copyright (C) 2013-2016 July IGHOR <julyighor@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  In addition, as a special exception, the copyright holders give
//  permission to link the code of portions of this program with the
//  OpenSSL library under certain conditions as described in each
//  individual source file, and distribute linked combinations including
//  the two.
//
//  You must obey the GNU General Public License in all respects for all
//  of the code used other than OpenSSL. If you modify file(s) with this
//  exception, you may extend this exception to your version of the
//  file(s), but you are not obligated to do so. If you do not wish to do
//  so, delete this exception statement from your version. If you delete
//  this exception statement from all source files in the program, then
//  also delete it here.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "socket.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#endif


namespace Platform {

void setSocketTimeout(qintptr socket, int timeout)
{
#ifdef Q_OS_WIN
        setsockopt((SOCKET) socket, SOL_SOCKET, SO_RCVTIMEO, (const char*) &timeout, sizeof(int));
#else
        struct timeval vtime;
        vtime.tv_sec = timeout / 1000;
        vtime.tv_usec = timeout * 1000 - vtime.tv_sec * 1000000;
        setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, &vtime, sizeof(struct timeval));
#endif
}

}
