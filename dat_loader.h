/****************************************************************************
 *
 * * ion_dat_viewer - an Ion Torrent Dat file viewer based on Qt
 *
 * * version: v0.1.1
 *
 * * author: mark doerr (mark.doerr@uni-greifswald.de)
 *
 * * date: 160521
 *
 * * Inspired by chip Qt4 example from Trolltech A/S.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 ***************************************************************************/

#ifndef DAT_LOADER_H
#define DAT_LOADER_H

#include <fstream>
#include <vector>
#include <iostream>
#include <random>
#include "dat_headers.h"

#define NUM_DAT_POINTS 5

class DatLoader
{
public:
    DatLoader(std::vector<double>& raw_data );

    int numX(void) const {return this->expt_header.cols; }
    int numY(void) const  {return this->expt_header.rows; }
    int numDataPoints(void) const {return num_data_points; }

private:
    struct dat_file_header df_header;
    struct experiment_header expt_header;
    const int num_data_points  = NUM_DAT_POINTS; // remove hardcoded stuff
    int p[NUM_DAT_POINTS] = {};  // !!! remove hardcoded arrays
};

#endif // DAT_LOADER_H



