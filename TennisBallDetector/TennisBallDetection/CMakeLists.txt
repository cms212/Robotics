cmake_minimum_required(VERSION 3.10)
project(EggDetection)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)

# Add ONNX Runtime
set(ONNXRUNTIME_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/onnxruntime-linux-x64-1.16.3)
set(ONNXRUNTIME_INCLUDE_DIRS ${ONNXRUNTIME_ROOT_PATH}/include)
set(ONNXRUNTIME_LIB_DIRS ${ONNXRUNTIME_ROOT_PATH}/lib)
find_library(ONNXRUNTIME_LIB onnxruntime HINTS ${ONNXRUNTIME_LIB_DIRS})

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${ONNXRUNTIME_INCLUDE_DIRS})

add_executable(Tennis_Ball_Detection main.cpp)
add_executable(egg_segmentation EggSegmentationMain.cpp)

target_link_libraries(Tennis_Ball_Detection ${OpenCV_LIBS} ${ONNXRUNTIME_LIB})
target_link_libraries(egg_segmentation ${OpenCV_LIBS})