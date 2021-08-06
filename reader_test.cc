#include <Eigen/Core>
#include <Eigen/Geometry>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class DatasetReader {
 public:
  DatasetReader(const std::string& path) : path(path + "/") {
    intrinsics = Eigen::Vector4f(517.3, 516.5, 318.6, 255.3);
    std::string fusion_path = path + "/depth_gt.txt";
    std::ifstream f(fusion_path.c_str());

    std::cout << "Opening file: " << fusion_path << std::endl;

    std::string timestamp;
    float rgb_timestamp;
    float depth_timestamp;
    while (!f.eof()) {
      std::string temp;
      getline(f, temp);
      std::stringstream stream(temp);
      Eigen::Vector3f translation;
      Eigen::Quaternionf quaternion;
      std::string depth_name, rgb_name;

      stream >> depth_timestamp;
      stream >> depth_name;

      stream >> timestamp;
      stream >> translation[0];
      stream >> translation[1];
      stream >> translation[2];
      stream >> quaternion.coeffs()[0];
      stream >> quaternion.coeffs()[1];
      stream >> quaternion.coeffs()[2];
      stream >> quaternion.coeffs()[3];

      timestamps.push_back(timestamp);
      depth_image_files.push_back(depth_name);

      std::cout << "read finished." << std::endl;

      Eigen::Matrix4f p;
      std::cout << "Matrix4f created." << std::endl;
      p.setIdentity();
      std::cout << "setIdentity finished." << std::endl;
      p.block<3, 3>(0, 0) = quaternion.matrix();
      std::cout << "set quaternion." << std::endl;
      p.col(3).head<3>() = translation;
      std::cout << "set translation." << std::endl;
      poses.push_back(p);

      std::cout << "Matrix4f finished." << std::endl;
    }
    std::cout << "Loaded " << depth_image_files.size() << " images"
              << std::endl;
  }

 private:
  std::string path;
  std::vector<std::string> depth_image_files;
  std::vector<std::string> timestamps;
  std::vector<Eigen::Matrix4f> poses;
  Eigen::Vector4f intrinsics;
};

int main(int argc, char** argv) {
  DatasetReader dr("/Users/zhangjixiang/Code/cc_test");
  return 0;
}