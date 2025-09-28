cmake_minimum_required(VERSION 3.10)
project(EggDetection)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)

# Add ONNX Runtime
find_library(ONNXRUNTIME_LIB onnxruntime HINTS /usr/local/lib)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(/usr/local/include)

add_executable(Tennis_Ball_Detection main.cpp)
add_executable(egg_segmentation EggSegmentationMain.cpp)

target_link_libraries(Tennis_Ball_Detection ${OpenCV_LIBS} ${ONNXRUNTIME_LIB})
target_link_libraries(egg_segmentation ${OpenCV_LIBS})