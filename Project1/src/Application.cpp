#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Glew must be intialised after the glfw context*/
    if (glewInit() != GLEW_OK)
        std::cout << "Wrong context" << std::endl;

    /* Print current build */
    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    /* Id for the buffer, OpenGL works as a state machine*/
    unsigned int buffer;
    glGenBuffers(1, &buffer); // Generate buffer and ID
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // Select the buffer
    

    /* Buffers can be stream, static or dynamic
    * Static means the data is modified once, used multiple times
    * just like the implementation below
    * Dynamic means the data is used and modified constantly */

    // Put data into the buffer
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); 

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Begin triangle rendering */
        glBegin(GL_TRIANGLES);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glEnd();
        /* end triangle rendering */


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}