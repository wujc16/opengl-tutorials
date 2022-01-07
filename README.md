# OpenGL Tutorial

本项目是学习 [LearnOpenGL CN](https://learnopengl-cn.github.io/) 的学习代码。

## 运行方式

对于绝大部分的项目，运行方式类似，以项目 00_hello_window 为例，运行方式如下：
1. 首先运行 ``cd 00_hello_window`` 进入到项目文件夹；
2. 打开 CMakeLists.txt 文件，根据自己的安装路径，修改对应的 library 和 include 的路径；
2. 使用 ``mkdir build`` 创建 build 文件夹，创建成功后，``cd build`` 进入新建好的 build 文件夹中；
3. 运行 ``cmake ..`` 进行 cmake 的编译；
5. 运行 ``make`` 生成可执行文件，如果没有修改的话，可执行文件的名称一般会是 demo；
6. 最后执行 ``./demo`` 即可运行生成的可执行文件。
