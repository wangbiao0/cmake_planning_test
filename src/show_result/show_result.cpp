#include <iostream>
#include <graphics.h>
#include "show_result.h"

using namespace std;

void ShowResult::drawResult(){
    initgraph(100,100);
    setbkcolor(WHITE);
    cleardevice();

    cout<<"draw circles: "<<endl;
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID);
    circle(500,500,200);
    circle(500,500,400);
    
    system("pause");
    closegraph();
}
