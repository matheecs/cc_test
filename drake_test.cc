#include <drake/solvers/mathematical_program.h>
#include <drake/solvers/mosek_solver.h>
#include <drake/solvers/solve.h>

#include <Eigen/Dense>

int main() {
  drake::solvers::MathematicalProgram prog;

  Eigen::Matrix2d A;
  A << 1, 2, 3, 4;
  Eigen::Vector2d b;
  b << 10, 10;

  std::cout << A(Eigen::all, Eigen::last) << std::endl;

  auto state = prog.NewContinuousVariables(2, "state");
  prog.AddLinearConstraint((A * state).array() >= b.array());
  prog.AddCost(state.transpose() * state);

  drake::solvers::MosekSolver mp;

  drake::solvers::MathematicalProgramResult result = mp.Solve(prog);
  assert(result.is_success());
  std::cout << "Result: " << std::endl << result.GetSolution() << std::endl;
  std::cout << "Solver id: " << result.get_solver_id() << std::endl;

  return 0;
}