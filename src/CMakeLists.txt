#cmake版本要求
cmake_minimum_required(VERSION 3.5)
#设置项目名称
project(xl_program)
####################################################################
#Cmake中的赋值操作set(变量名 变量值)
#set(Path ${CMAKE_SOURCE_DIR})
#PROJECT_SOURCE_DIR     //PROJECT()命令的最近一个CMakeLists.txt文件在文件夹的路径
#PROJECT_BINARY_DIR     //运行命令cmake的目录，即工程编译发生的路径
#EXECUTABLE_OUTPUT_PATH //指定最终的文件的位置

#设置自动生成moc文件，一定要设置
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # CMAKE包含当前的目录
#CMAKE_CURRENT_SOURCE_DIR
#CMAKE_CURRENT_BINARY_DIR


#指定编程语言版本
set(CMAKE_C_STANDARD 99)            #C99
set(CMAKE_CXX_STANDARD 17)          #C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

####################################################################
#设置Qt的支持
set(QT5_LIBRARIES Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Xml)
#自动查找配置构建工程所需的程序库
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Xml REQUIRED)

#查找可执行程序
#find_program()

####################################################################
#获取工程目录下的文件
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}
                          ${PROJECT_SOURCE_DIR}/*.h
                          ${PROJECT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp
                          ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE FORMS   ${PROJECT_SOURCE_DIR}/*.ui)
file(GLOB_RECURSE FILES   ${PROJECT_SOURCE_DIR}/file_structure.txt)

#添加要编译的可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS} ${FILES})
##add_subdirectory(src/hci)
##add_subdirectory(src/srm)
#link_libraries(ws2_32)

#添加可执行文件所需要的库
target_link_libraries(${PROJECT_NAME} ${QT5_LIBRARIES} Qt5::Core ws2_32 wsock32)

#target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${QT5_LIBRARIES} ${CMAKE_DL_LIBS} ${LIBS} Qt5::Core )
