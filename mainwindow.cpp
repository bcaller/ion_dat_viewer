/****************************************************************************
 *
 * * ion_dat_viewer - an Ion Torrent Dat file viewer based on Qt
 *
 * * version: v0.1.0
 *
 * * author: mark doerr (mark.doerr@uni-greifswald.de)
 *
 * * date: 160520
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

#include "mainwindow.h"
#include "well_view.h"
#include "well_plot.h"
#include "dat_loader.h"
#include <iostream>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    const QString window_title = "Ion Torrent Viewer v0.0.1";

    scene = new QGraphicsScene;

    dat_data = new DatLoader(raw_data);

    std::cout << "main window: raw data created normal_distribution (5.0,2.0)\n\tdata size:" << raw_data.size() << std::endl;

    populateWellPlots(); // adding datapoint to graphs

    h1Splitter = new QSplitter(this);

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(h1Splitter);

    WellView *view = new WellView("Ion Torrent Chip");
    view->view()->setScene(scene);
    h1Splitter->addWidget(view);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(vSplitter);
    setLayout(layout);

    // final finish of the MainWindow
    setWindowTitle(window_title.trimmed());
    setCentralWidget(h1Splitter);

}

void MainWindow::populateWellPlots()
{
    const int point_offset = 12;  // !!!! remove hardcode offset !!!
    const int min_well_coordinate_x = 2200; //= 11000;
    const int min_well_coordinate_y = 1400; //7000;
    const int well_plot_distance_x = 110;
    const int well_plot_distance_y = 70;

    // Populating the scene
    int n_items = 0;
    int x_item_pos = 0;

    int line_left = 0;
    int max_rep = 7699;

    for (int i = -min_well_coordinate_x; i < min_well_coordinate_x; i +=  well_plot_distance_x) {
        ++x_item_pos;

        int y_item_pos = 0;

        if (line_left > max_rep) { line_left = 0;}

        for (int j = -min_well_coordinate_y; j < min_well_coordinate_y; j += well_plot_distance_y) {
            ++y_item_pos;

            if (line_left > max_rep) { line_left = 0;}

           WellPlot *item = new WellPlot(x_item_pos, y_item_pos, raw_data, line_left, point_offset);

           item->setPos(QPointF(i, j));
           scene->addItem(item);

           ++n_items;
           line_left = line_left + point_offset;
        }
        line_left = line_left + point_offset;
    }
}
