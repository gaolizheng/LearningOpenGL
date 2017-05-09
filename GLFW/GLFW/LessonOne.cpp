//
//  LessonOne.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/9.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonOne.hpp"
void LessonOne::createHelloWindow()
{
    /**
     In the main function we first initialize GLFW with glfwInit, after which we can configure GLFW 
     using glfwWindowHint. The first argument of glfwWindowHint tells us what option we want to
     configure, where we can select the option from a large enum of possible options prefixed with 
     GLFW_. The second argument is an integer that sets the value of our option. A list of all the
     possible options and its corresponding values can be found at GLFW's window handling documentation.
     If you try to run the application now and it gives a lot of undefined reference errors it means 
     you didn't successfully link the GLFW library.
     
     Since the focus of this website is on OpenGL version 3.3 we'd like to tell GLFW that 3.3 is the
     OpenGL version we want to use. This way GLFW can make the proper arrangements when creating the
     OpenGL context. This ensures that when a user does not have the proper OpenGL version GLFW fails
     to run. We set the major and minor version both to 3. We also tell GLFW we want to explicitly use
     the core-profile and that the window should not be resizable by a user. Telling GLFW explicitly 
     that we want to use the core-profile means we'll get access to a smaller subset of OpenGL features
     (without backwards-compatible features we no longer need). Note that on Mac OS X you need to add 
     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); to your initialization code for it to work.
     
     */
    glfwInit();
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    /**
     
     The glfwCreateWindow function requires the window width and height as its first two arguments
     respectively. The third argument allows us to create a name for the window; for now we call it
     "Hello OpenGL" but you're allowed to name it whatever you like. We can ignore the last 2 parameters.
     The function returns a GLFWwindow object that we'll later need for other GLFW operations. After 
     that we tell GLFW to make the context of our window the main context on the current thread.
     */
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello OpenGL", nullptr, nullptr);
    if (window == nullptr) {
        cout<<"Failed to create GLFW window"<<endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    
    /**
     
     Before we can start rendering we have to do one last thing. We have to tell OpenGL the size of
     the rendering window so OpenGL knows how we want to display the data and coordinates with respect
     to the window. We can set those dimensions via the glViewport function
     
     Behind the scenes OpenGL uses the data specified via glViewport to transform the 2D coordinates 
     it processed to coordinates on your screen. For example, a processed point of location 
     (-0.5,0.5) would (as its final transformation) be mapped to (200,450) in screen coordinates. 
     Note that processed coordinates in OpenGL are between -1 and 1 so we effectively map from the
     range (-1 to 1) to (0, 800) and (0, 600).
     */
    int width,height;
    glfwGetFramebufferSize(window, width, height);
    glViewport(0, 0, width, height);
    
    /**
     We don't want the application to draw a single image and then immediately quit and close the 
     window. We want the application to keep drawing images and handling user input until the program 
     has been explicitly told to stop. For this reason we have to create a while loop, that we now 
     call the game loop, that keeps on running until we tell GLFW to stop. The following code shows 
     a very simple game loop:
     */
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}
