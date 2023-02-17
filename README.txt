README 

HOW TO COMPILE:
1. Before you open Visual Studio Code, go to 
https://github.com/ydm/mit-vecmath
2. Create a test directory on your home folder (since we're using Linux, your local directory will be labeled 'home').
3. git clone https://github.com/ydm/mit-vecmath.git
4. there is a make file so, in the terminal, go to the test directory and run the cmd "make" 
5. Once an output file is create, run "sudo make install" so that vecmath can be installed to your include and lib local directories.
6. You do all this to make sure that, when you build this project, you won't get a "error vecmath not found". 
7. And then, finally, you can go this project and, in the attached terminal to Visual Studio code, run "make" to build this project.
8. Once the make command is done, the a0 executable file will be created.
9. In the terminal, type "./a0" to run.

------------------------------------------------------------------------
COLLABORATORS
None 

------------------------------------------------------------------------
References
1. This tutorial called "Getting Started with OpenGL in Visual C++"
https://www.c-sharpcorner.com/UploadFile/f5a10c/getting-started-with-opengl-in-visual-cpp/

2.Fedora forums

3. the mit-vecmath git repo
------------------------------------------------------------------------
Problems
1. Before I discovered how to properly build the vecmath directory, I always got a "vecmath.h: no such file or directory" error. 

2. Sometimes rendering would take a long time because the laptop I'm using is old and I initially made the
mistake of using a large MAX_BUFFER_SIZE (>=1000). 
------------------------------------------------------------------------

Extra Credit

1. I implemented the color fading function that works with up to 10 different types of colors.
2. Mouse-based camera is now possible thanks to special glutMouse functions.
3. Object spinning has now been implemented.

------------------------------------------------------------------------

Comments

Honestly, the coding part (aside from figuring out how to properly time the spin function as well as the color changing one due to how many 
colors I decided to try) wasn't difficult. The hardest part of this assignment was setting up 
Freeglut and vecmath include folders and then setting up OpenGL on a VM. I abandoned the VM setup altogether in favor of using an old 
laptop that had ubuntu installed as its primary OS.  