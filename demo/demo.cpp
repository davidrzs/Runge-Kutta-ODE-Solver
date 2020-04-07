
#include <iostream> 

#include "matplotlibcpp.h"

#include <Eigen/Dense>
#include "rk_implementer.hpp"
#include "rk_solvers.hpp"

namespace plt = matplotlibcpp;


int main(void) {

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

  std::vector<Eigen::VectorXd> result = ExplicitRKSolvers::classical4thOrderRuleIntegrator(f, time,y0, steps);

  std::cout << "The classical 4th order Runge-Kutta method gives us" << result.back().transpose() << std::endl;


  std::vector<double> t(steps);
  std::vector<double> prey(steps);
  std::vector<double> predator(steps);

    for(size_t i = 0; i < t.size(); i++) {
        t[i] = i*(time / (double) steps);
        prey[i] = result[i](0);
        predator[i] = result[i](1);
    }

    plt::plot(t, prey);
    plt::plot(t,predator);
    plt::save("xkcd.png");



  
  
}

    
