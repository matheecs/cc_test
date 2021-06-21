#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;

int main() {
  Matrix2d a;
  a << 1, 2, 3, 4;
  MatrixXd b(2, 2);
  b << 2, 3, 1, 4;
  std::cout << "a + b =\n" << a + b << std::endl;
  std::cout << "a - b =\n" << a - b << std::endl;
  std::cout << "Doing a += b;" << std::endl;
  a += b;
  std::cout << "Now a =\n" << a << std::endl;
  Vector3d v(1, 2, 3);
  Vector3d w(1, 0, 0);
  std::cout << "-v + w - v =\n" << -v + w - v << std::endl;

  Eigen::Matrix<double, 2, 1> M_2x1;
  M_2x1(0, 0) = 1.;
  M_2x1(0, 0) = 2.;
  std::cout << M_2x1[0] << std::endl;
}