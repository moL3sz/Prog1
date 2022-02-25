// created by Molesz at 2022/02/25 15:35.
// 
// DE-IK - 2022 - Prog1


#include <iostream>
#include "./../GUI/Simple_window.h"
#include "./../GUI/Graph.h"
#include <string>
using namespace std;
using namespace Graph_lib;
int main(){
    try{

        Point t1 {100, 100};

        Simple_window win {t1, 640, 400, "My window"};

        win.wait_for_button(); 

        Axis xa {Axis::x, Point {20, 300}, 200, 10, "x axis"};

        win.attach(xa);
        win.set_label("Axis");
        win.wait_for_button();

        Axis ya {Axis::y, Point {20, 300}, 280, 10, "y axis"};
        ya.set_color(Color::cyan); 
        win.attach(ya);
        win.set_label("y axis");
        win.wait_for_button();

        Function sine {sin, 0 , 100, Point{20, 150}, 1000, 50, 50}; 
        win.attach(sine);
        win.set_label("Sine function");
        win.wait_for_button();
        sine.set_color(Color::blue);

        Polygon poly; 
        poly.add(Point{300,200});
        poly.add(Point{350,100});
        poly.add(Point{400,200});

        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);
        win.attach(poly);
        win.set_label("Draw polygon");
        win.wait_for_button();

        Rectangle r {Point{200, 200}, 100, 50};
        win.attach(r);

        Closed_polyline poly_rect;
        poly_rect.add(Point{100, 50});
        poly_rect.add(Point{200, 50});
        poly_rect.add(Point{200, 100});
        poly_rect.add(Point{100, 100});
        poly_rect.add(Point{50, 75});

        win.set_label("Draw rectangle");
        win.attach(poly_rect);
        win.wait_for_button();

        r.set_fill_color(Color::yellow);
        poly.set_style(Line_style(Line_style::dash,4));
        poly_rect.set_style(Line_style(Line_style(Line_style::dash,2)));
        poly_rect.set_fill_color(Color::green);
        win.set_label("Canvas#7");
        win.wait_for_button();

        Text t {Point{180,100}, "Hello, boiiii!"};
        win.attach(t);
        win.set_label("Canvas #8");
        win.wait_for_button();

        t.set_font(Graph_lib::Font::times_bold);
        t.set_font_size(20);
        win.set_label("Canvas #9");
        win.wait_for_button();

        Image ii {Point{100,50}, "/home/molesz/Desktop/Egyetem/Prog1/Lesson1/doom.jpg"};
        win.attach(ii);
        win.set_label("Canvas #10");
        win.wait_for_button();

        ii.move(100,200); //relative moving
        win.set_label("Canvas #11");
        win.wait_for_button();

        Circle c {Point{100,200},50};
        Ellipse e {Point{100,200}, 75,25};
        e.set_color(Color::dark_red);
        Mark m {Point{100,200},'x'};

        ostringstream oss;
        oss << "Screen size: " << x_max() << "*" << y_max()
            << "; window size: " << win.x_max() << win.y_max();
        Text sizes {Point{100,200},oss.str()};

        Image cal {Point{225,225}, "/home/molesz/Desktop/Egyetem/Prog1/Lesson1/cpp.jpg"};
        cal.set_mask(Point{40,40},200,150);

        win.attach(c);
        win.attach(m);
        win.attach(e);

        win.attach(sizes);
        win.attach(cal);
        win.set_label("Cavas #12");
        win.wait_for_button();

    } catch (exception& e) {
        cerr << "exception: " << e.what()<< '\n';
        return 1; 
    } catch (...) {
        cerr << "error\n";
        return 2;
    }
}