### Instructions :
1. Go to Tools > Build Systems > New Build System
2. Copy the code from C++14.sublime-build and paste it ther and save it by any name.
3. Go to Tools > Build Systems ans select your new build system
4. Create 2 files named input.in and output.in in same directory in which u have ur code.
5. Write input in input.in, save and run the code in sublime and you will get output in output.in .

Tips :
You can use CTRL + shift + B to directly compile run.
You can use 3 pane setup to view code, input file and output file at once (ALT + SHIFT + 3).

# C++14.sublime-build (FOR LINUX) :
Build system to directly compile and run c++ programs in sublime on linux. Moreover it uses c++14 directly opposed to the fact that terminal doesnt.

# C++14.sublime-build (FOR IOS(Mac Users) ) :
Follow the same steps above just copy the sublime build file corresponding to OS X. You need to have gcc and gtimout installed to be able to run above build system.

To install gcc in IOS :

brew install gcc
To install gtimout in IOS :

brew install coreutils
Remember you may have to change the version in g++-{version} in sublime build file according to gcc version installed by brew. At the time of writting this post it is 10 hence is written as g++-9
