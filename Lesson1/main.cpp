// created by Molesz at 2022/02/10 10:22.
//
// DE-IK - 2022 - Prog1

#include <iostream>
#include "./../GUI/Simple_window.h"
#include "./../GUI/Graph.h"
#include <string>
using namespace std;
int main()
{
    try
    {
        Point t1{100, 100};
        Simple_window win{t1, 640, 480, "YEAH BOI"};

        Axis xa{Axis::x, Point{20, 300}, 200, 10, "x-axis"};
        win.attach(xa);
        win.set_label("x-axis");

        Axis ya{Axis::y, Point{20, 300}, 200, 10, "y-axis"};
        win.attach(ya);
        win.set_label("y-axis");
        Function sine{sin, 0, 100, Point{20,100},1000,50,50};
        win.attach(sine);
        win.set_label("Sine");
        win.wait_for_button();

        Polygon poly;
        poly.set_fill_color(Color::cyan);
        poly.add(Point{300,200});
        poly.add(Point{350,100});
        poly.add(Point{400,200});

        poly.set_color(Color::dark_red);
        poly.set_style(Line_style::dashdot);

        win.set_label("Poly");
        win.attach(poly);
        win.wait_for_button();

        Rectangle r {Point{200,200},100,100};
        win.attach(r);

        Closed_polyline clp;

        clp.add(Point{200,300});
        clp.add(Point{210,360});
        clp.add(Point{250,670});
        clp.add(Point{120,10});
        clp.add(Point{20,306});
        clp.add(Point{50,360});
        win.attach(clp);
        win.wait_for_button();

        Text t{Point{150,150},"Hello biooooioiouji4okhjkhsfkljaséj!"};
        t.set_font(Graph_lib::Font::courier_bold);
        t.set_font_size(30);
        win.attach(t);
        win.wait_for_button();

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "error\n";
        return 2;
    }
}