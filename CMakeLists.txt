cmake_minimum_required(VERSION 3.1)
project(cpp_demo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
set(CMAKE_BUILD_TYPE "RELEASE")

# find_package
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)
find_package(Bullet REQUIRED)
find_package(drake CONFIG REQUIRED)
find_package(Armadillo REQUIRED)

include_directories(
  ${EIGEN3_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${BULLET_INCLUDE_DIRS}
  ${drake_INCLUDE_DIRS} ${ARMADILLO_INCLUDE_DIRS})

include_directories(/Users/zhangjixiang/Code/eigen-3.4-rc1)

# add_executable
add_executable(json_test json_test.cc)
target_link_libraries(json_test PRIVATE nlohmann_json::nlohmann_json)

add_executable(eigen_test eigen_test.cc)

add_executable(tmp_test tmp_test.cc)

add_executable(boost_test boost_test.cc)
target_link_libraries(boost_test ${Boost_LIBRARIES})

add_executable(bullet_test bullet_test.cc)
target_link_libraries(bullet_test ${BULLET_LIBRARIES})

add_executable(drake_test drake_test.cc)
target_link_libraries(drake_test drake::drake)

add_executable(reader_test reader_test.cc)

add_executable(armadillo_test armadillo_test.cc)
target_link_libraries(armadillo_test ${ARMADILLO_LIBRARIES})
