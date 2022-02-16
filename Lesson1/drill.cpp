
#include <iostream>
#include "./../GUI/Simple_window.h"
#include "./../GUI/Graph.h"
#include <string>

int main()
{
    try
    {
        Point t1{100, 100};
        int w = 1000;
        int h = 800;
        Simple_window win{t1, w, h, "DRILL 12"};

        Lines gridX;
        // horizontals
        for (uint i = 0; i <= h; i += 100)
        {
            gridX.add(Point{0, i}, Point{w - 200, i});
        }
        Lines gridY;
        // vertivcals
        for (uint i = 0; i <= w - 200; i += 100)
        {
            gridY.add(Point{i, 0}, Point{i, h});
        }
        win.attach(gridX);
        win.attach(gridY);


        // create the szűzcucc
        for (int y = 0; y < h; y += 100)
        {
            Rectangle *kocka = new Rectangle{Point{y, y}, Point{y + 100, y + 100}};            
            kocka->set_fill_color(Color::red);
            win.attach(*kocka);
        }

        win.wait_for_button();
    }
    catch (const std::exception &e)
    {
    }

    return 0;
}