cmake_minimum_required(VERSION 3.1)
project(cpp_demo)

# find_package
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)
find_package(Bullet REQUIRED)
find_package(drake CONFIG REQUIRED)

include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${BULLET_INCLUDE_DIRS}
  ${drake_INCLUDE_DIRS}
)

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