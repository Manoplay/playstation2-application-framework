# PlayStation 2 Application Framework

     *******      **     ********
    /**////**    ****   /**///// 
    /**   /**   **//**  /**      
    /*******   **  //** /******* 
    /**////   **********/**////  
    /**      /**//////**/**      
    /**      /**     /**/**      
    //       //      // //    

## Introduction
The PAF (**PlayStation 2 Application Framework**) is a C++ framework which allows you to develop simple PS2 applications (or 2D games) making it easier to access basic PS2 rendering and control features.
The framework features (for now):
* ScreenManager
* Screen
* Basic Renderables
* Pad Input
* Timer
* Debug console (WIP)

## The Screen
In this framework, you instantiate a `ScreenManager` in your `main()` method, switch to a subclass of the `Screen` class, then call the ScreenManager's `main` method. In order to create a screen, you simply subclass the `Screen` class, then override the constructor to add your `Renderable`s to the screen. You will have full access to the `Renderable* renderables` field, and a convenience method `SetRenderableCount(int)` which allocates memory for your renderables.

## The Renderables
A Renderable is something which can be rendered on the screen. The Screen class itself is a renderable, because it has a Render() method under the hood, which is called by the ScreenManager. You can create a custom renderable by simply subclassing `Renderable`, then overriding `Render(GSGLOBAL*)` method. The framework provides some basic renderables:
* Square (a simple colored square)
* FontM (ROM Font)
* Texture (any texture)

You can instantiate FontM and Texture using the ScreenManager, while the Square can be instantiated directly.

## Installation
PAF will install includes and library respectively under `$(PS2SDK)/paf/include` and `$(PS2SDK)/paf/lib`.

To build and install from source (which is currently the only way), just grab the source or clone this repository, then run

    make install

in the root directory.
