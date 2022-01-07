# OpenGL Tutorial

本项目是学习 [LearnOpenGL CN](https://learnopengl-cn.github.io/) 的学习代码。

## 环境配置

本项目所有代码均在 Mac 上运行，在运行之前，需要确保电脑已经进行好如下的配置：
1. 首先需要安装好最新版本的 XCode，安装完后其实就不需要另外安装 c++ 的编译器了；
2. 安装好 homebrew，具体安装教程可以参考：https://brew.sh/
3. 本 opengl 教程使用的是 glfw 和 glad 的搭配，glad 已经将代码复制到了项目中，因此本机需要进行 glfw 的安装，安装命令为：``brew install glfw3``，安装完毕后，需要使用自己的 glfw 安装地址的 include 和 lib 路径去替换各个项目中的 glfw 文件路径；
4. cmake 的安装；
5. 其他，包括 vscode 的安装和 vscode 中 C++ extension 的安装，这个按自己所需配置。

## 运行方式

对于绝大部分的项目，运行方式类似，以项目 00_hello_window 为例，运行方式如下：
1. 首先运行 ``cd 00_hello_window`` 进入到项目文件夹；
2. 打开 CMakeLists.txt 文件，根据自己的安装路径，修改对应的 library 和 include 的路径；
2. 使用 ``mkdir build`` 创建 build 文件夹，创建成功后，``cd build`` 进入新建好的 build 文件夹中；
3. 运行 ``cmake ..`` 进行 cmake 的编译；
5. 运行 ``make`` 生成可执行文件，如果没有修改的话，可执行文件的名称一般会是 demo；
6. 最后执行 ``./demo`` 即可运行生成的可执行文件。
