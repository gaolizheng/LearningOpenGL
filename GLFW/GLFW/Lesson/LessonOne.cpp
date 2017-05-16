//
//  LessonOne.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/9.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonOne.hpp"


void LessonOne::showLessonContent()
{
    
    /**
     We don't want the application to draw a single image and then immediately quit and close the 
     window. We want the application to keep drawing images and handling user input until the program 
     has been explicitly told to stop. For this reason we have to create a while loop, that we now 
     call the game loop, that keeps on running until we tell GLFW to stop. The following code shows 
     a very simple game loop:
     
     The glfwWindowShouldClose function checks at the start of each loop iteration if GLFW has been
     instructed to close, if so, the function returns true and the game loop stops running, after 
     which we can close the application.
     The glfwPollEvents function checks if any events are triggered (like keyboard input or mouse
     movement events) and calls the corresponding functions (which we can set via callback methods).
     We usually call eventprocessing functions at the start of a loop iteration.
     The glfwSwapBuffers will swap the color buffer (a large buffer that contains color values for 
     each pixel in GLFW's window) that has been used to draw in during this iteration and show it 
     as output to the screen.
     
     Double buffer
     When an application draws in a single buffer the resulting image might display flickering 
     issues. This is because the resulting output image is not drawn in an instant, but drawn 
     pixel by pixel and usually from left to right and top to bottom. Because these images are 
     not displayed at an instant to the user, but rather via a step by step generation the result
     may contain quite a few artifacts. To circumvent these issues, windowing applications apply
     a double buffer for rendering. The front buffer contains the final output image that is shown
     at the screen, while all the rendering commands draw to the back buffer. As soon as all the
     rendering commands are finished we swap the back buffer to the front buffer so the image is
     instantly displayed to the user, removing all the aforementioned artifacts.
     
     */
    while (!glfwWindowShouldClose(WindowManager::getInstance()->getWindow())) {
        //check and call events
        glfwPollEvents();
        
        //rendering commands here
        /**
         Just to test if things actually work we want to clear the screen with a color of our 
         choice. At the start of each render iteration we always want to clear the screen otherwise
         we would still see the results from the previous iteration (this could be the effect you're
         looking for, but usually you don't). We can clear the screen's color buffer using the 
         glClear function where we pass in buffer bits to specify which buffer we would like to
         clear. The possible bits we can set are GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT and
         GL_STENCIL_BUFFER_BIT. Right now we only care about the color values so we only clear
         the color buffer.
         
         Note that we also set a color via glClearColor to clear the screen with. Whenever
         we call glClear and clear the color buffer, the entire colorbuffer will be filled
         with the color as configured by glClearColor. This will result in a dark green-blueish
         color.
         
         As you might recall from the OpenGL tutorial, the glClearColor function is a 
         state-setting function and glClear is a state-using function in that it uses 
         the current state to retrieve the clearing color from.
         */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //swap the buffers
        glfwSwapBuffers(WindowManager::getInstance()->getWindow());
    }
    
    /**
     As soon as we exit the game loop we would like to properly clean/delete all resources
     that were allocated. We can do this via the glfwTerminate function that we call at the
     end of the function.
     */
    glfwTerminate();
    
}

