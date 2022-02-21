// created by Molesz at 2022/02/17 10:44.
// 
// DE-IK - 2022 - Prog1



#include <iostream>
#include "./../GUI/Simple_window.h"
#include "./../GUI/Graph.h"
#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */

using namespace Graph_lib;
int main(){
    try
    {
        int gridW = 800, gridH=800;
        Simple_window win {Point{0,0},1000,800,"Drill13"};

        Lines grid;
        for(int x = 0; x <= gridW; x+=100){
            grid.add(Point{x,0},Point{x,gridH});
            grid.add(Point{0,x}, Point{gridW,x});
        }
        win.attach(grid);


        for(int i = 0; i < gridW; i+=100){
            Rectangle *kocka = new Rectangle(Point{i,i},Point{i+100,i+100});
            kocka->set_fill_color(Color::red);
            win.attach(*kocka);
        }
        win.wait_for_button();
        //absolute path of the image
        string path = "/home/molesz/Desktop/Egyetem/Prog1/Lesson2/kep.jpg";
        vector<Image*> images = { //create a list of images with coords
            new Image{Point{100,300},path},
            new Image{Point{500,300},path},
            new Image{Point{200,600},path},
            
        };
        //attach every image to the screen
        for(Image  *img : images){
            win.attach(*img);
        }
        win.wait_for_button();
        //generate a rand value btw 0 and 8 and create a Point on a screen and an imagef with the current coords
        while(true){
            short randx = rand() % ((gridW/100)-1); //index of x axis
            short randy = rand() % ((gridH/100)-1); //index of y axis

            Point imgPoint{randx*100, randy*100};
            Image img{imgPoint, path};
            img.set_mask(Point{0,0},100,100);
            win.attach(img);
            win.wait_for_button();
        }
        //delete the memory of images
        for(auto p : images){
            delete p;
        }
        images.clear();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...){
        std:cerr << "Unexpected error :(" << std::endl;
    }
    

    return 0;
}