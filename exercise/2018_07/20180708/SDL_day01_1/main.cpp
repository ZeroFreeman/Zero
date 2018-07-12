
#include <iostream>
//#include <string>

#include "../include/SDL.h"
#include "../SDL2_image-2.0.3/include/SDL_image.h"
#undef main

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 853;
const int SCREEN_BPP = 32;

int main01()
{
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    //The image we will load and show on the screen
    SDL_Surface* gHelloWorld = NULL;

    //首先初始化   初始化SD视频子系统
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    //创建窗口
    gWindow=SDL_CreateWindow("SHOW BMP",//窗口标题
                            SDL_WINDOWPOS_UNDEFINED,//窗口位置设置
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,//窗口的宽度
                            SCREEN_HEIGHT,//窗口的高度
                            SDL_WINDOW_SHOWN//显示窗口
                            );
    if(gWindow==NULL)
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    //Use this function to get the SDL surface associated with the window.
    //获取窗口对应的surface
    gScreenSurface=SDL_GetWindowSurface(gWindow);

    //加载图片
    gHelloWorld = IMG_Load("../image/0.jpg");//加载图片
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "Hello_World.bmp", SDL_GetError() );
        return false;
    }
    //Use this function to perform a fast surface copy to a destination surface.
    //surface的快速复制
    //下面函数的参数分别为： SDL_Surface* src ,const SDL_Rect* srcrect , SDL_Surface* dst ,  SDL_Rect* dstrect
    SDL_BlitSurface( gHelloWorld ,     NULL ,                     gScreenSurface ,          NULL);
    SDL_UpdateWindowSurface(gWindow);//更新显示copy the window surface to the screen
    SDL_Delay(20000);//延时2000毫秒

    //释放内存
    SDL_FreeSurface( gHelloWorld );//释放空间
    gHelloWorld = NULL;

    SDL_DestroyWindow(gWindow);//销毁窗口
    gWindow = NULL ;

    SDL_Quit();//退出SDL

    return 0;
}


int main()
{
    SDL_Window *wind = NULL;
    SDL_Surface *image = NULL;
    SDL_Surface *screen = NULL;
    string filename = "../image/timg.gif";

    SDL_Init(SDL_INIT_EVERYTHING);

    wind = SDL_CreateWindow("SHOW image",//窗口标题
                            SDL_WINDOWPOS_UNDEFINED,//窗口位置设置
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,//窗口的宽度
                            SCREEN_HEIGHT,//窗口的高度

                            SDL_WINDOW_SHOWN//显示窗口
                            );

    screen = SDL_GetWindowSurface(wind);

    image = IMG_Load(filename.c_str());

    SDL_BlitSurface(image, NULL, screen, NULL);

    SDL_UpdateWindowSurface(wind);

    SDL_Delay(2000);

    SDL_FreeSurface(image);

    SDL_DestroyWindow(wind);

    SDL_Quit();


    return 0;
}
