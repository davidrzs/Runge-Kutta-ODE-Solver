/**
 * 
 * 
 * 
 * 
 * 
 * 
 */



#include "rk_implementer.hpp"
#include<vector>



// collection of common RK explicit RK methods.
namespace ExplicitRKSolvers{

    // traditional explicit euler method with convergence order 1
    template <typename Step, typename Function> 
    std::vector<Step> explicitEulerRule(Function f, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(1,1);
        A << 0;
        
        Eigen::VectorXd b(2);
        b << 1;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }

    // explicit trapizoidal rule with convergece order 2
    template <typename Step, typename Function> 
    std::vector<Step> explicitTrapezoidalRule(Function f, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(2,2);
        A << 0,0,
             1, 0;
        
        Eigen::VectorXd b(2);
        b << 0.5,0.5;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }

    // explicit midpoint rule with convergence order 2
    template <typename Step, typename Function>
    std::vector<Step> explicitMidPointRule(Function f, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(2,2);
        A << 0,0,
             0.5, 0;
        
        Eigen::VectorXd b(2);
        b << 0,1;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }

    // classical 4-th order runge kutta single step method
    template <typename Step, typename Function>
    std::vector<Step> classical4thOrderRule(Function f, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(4,4);
        A << 0,0,0,0,
            0.5,0,0,0,
            0,0.5,0,0,
            0,0,1,0;
        
        Eigen::VectorXd b(4);
        b << 1.0/6,2.0/6,2.0/6,1.0/6;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }

    // kutta's 3/8-rule of order 4
    template <typename Step, typename Function>
    std::vector<Step> kuttas38thRule(Function f, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(4,4);
        A << 0,0,0,0,
            1.0/3,0,0,0,
            -1.0/3,1,0,0,
            1,-1,1,0;
        
        Eigen::VectorXd b(4);
        b << 1.0/8, 3.0/8, 3.0/8, 1.0/8;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }

    namespace ExplicitRKSolvers{
    }


}