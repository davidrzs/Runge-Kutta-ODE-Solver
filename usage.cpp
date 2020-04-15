
#include <iostream> 

#include <Eigen/Dense>
#include "src/rk_implementer.hpp"
#include "src/rk_solvers.hpp"


int main() {

  /**
   *  Setting global variables, the time we are integrating over
   *  and the number of integration steps we take in this time.
   * 
   *  We also define the function f representing our ODE
   *  and the initial conditiond y0.
   */

  unsigned int steps = 100;
  unsigned int time = 20;

  auto f = [] (Eigen::VectorXd y) {
    Eigen::VectorXd df(2);
    df << y(0)*(3-0.7*y(1)) , -y(1)*(0.7-0.8*y(0));
    return df;
  };

  Eigen::VectorXd y0(2);
  y0 << 6,2;

  /**
   * Solve using built in solver:
   */

  std::vector<Eigen::VectorXd> y1Vec = ExplicitRKSolvers::classical4thOrderRuleIntegrator(f, time,y0, steps);

  std::cout << "The classical 4th order Runge-Kutta method gives us" << y1Vec.back().transpose() << std::endl;

  for(int i = 0; i < y1Vec.size(); i++){
    std::cout << y1Vec.at(i).transpose() << " \n";
  }

  /**
   * Solve explicitly using custom Butcher's table:
   */

  Eigen::MatrixXd A(3,3);
  A << 0, 0, 0,
       1, 0, 0,
       1.0/4,1.0/4,0;
  Eigen::VectorXd b(3);
  b << 1.0/6, 1.0/6, 2.0/3;

  ExplicitRungeKuttaIntegrator<Eigen::VectorXd> Solver(A,b);
  std::vector<Eigen::VectorXd> y2Vec = Solver.solve(f,2,y0,10);

  std::cout << "SSPRK3 3rd order Runge-Kutta method gives us = " << y2Vec[10].transpose() << std::endl;
  
}

    
