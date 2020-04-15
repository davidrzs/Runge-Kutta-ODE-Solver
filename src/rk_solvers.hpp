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



// collection of common explicit RK methods.
namespace ExplicitRKSolvers{

    // traditional explicit euler method with convergence order 1
    template <typename Step, typename Function> 
    std::vector<Step> explicitEulerRule(Function f, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(1,1);
        A << 0;
        
        Eigen::VectorXd b(1);
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
    std::vector<Step> classical4thOrderRuleIntegrator(Function f, double time, const Step &y0, unsigned int steps){

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

}


// collection of common implicit RK methods.
namespace ImplicitRKSolvers{

    // traditional implicit euler method with convergence order 1, L-stable
    template <typename Step, typename Function, typename Jacobian> 
    std::vector<Step> implicitEulerRule(Function f, Jacobian df, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(1,1);
        A << 1;
        
        Eigen::VectorXd b(1);
        b << 1;

        ImplicitRungeKuttaIntegrator<Step> iRKi(A,b);
        return iRKi.solve(f, df, time, y0, steps);

    }


    // implicit midpoint method, order 2
    template <typename Step, typename Function, typename Jacobian> 
    std::vector<Step> implicitMidpointRule(Function f, Jacobian df, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(1,1);
        A << 1;
        
        Eigen::VectorXd b(1);
        b << 1;

        ImplicitRungeKuttaIntegrator<Step> iRKi(A,b);
        return iRKi.solve(f, df, time, y0, steps);

    }




    // third order Radau RK-SSM with convergence, L-stable
    template <typename Step, typename Function, typename Jacobian> 
    std::vector<Step> radauRKSSMRule3(Function f, Jacobian df, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(2,2);
        A << 5.0/12, -1.0/12,
             3.0/4, 1.0/4;
        
        Eigen::VectorXd b(2);
        b << 3.0/4, 1.0/4;

        ImplicitRungeKuttaIntegrator<Step> iRKi(A,b);
        return iRKi.solve(f, df, time, y0, steps);

    }


    // fifth order Radau RK-SSM with convergence, L-stable
    // METHOD NOT VERIFIED
    template <typename Step, typename Function, typename Jacobian> 
    std::vector<Step> radauRKSSMRule5(Function f, Jacobian df, double time, const Step &y0, unsigned int steps){

        Eigen::MatrixXd A(3,3);
        A << (88-7*std::sqrt(6))/360 , (196-169*std::sqrt(6))/1800 , (-2+3*std::sqrt(6))/225,
            (196+169*std::sqrt(6))/1800 , (88+7*std::sqrt(6))/360 , (-2-3*std::sqrt(6))/225,
            (16-std::sqrt(6))/36, (16+std::sqrt(6))/36, 1.0/9;
        
        Eigen::VectorXd b(3);
        b << (16-std::sqrt(6))/36 , (16+std::sqrt(6))/36, 1.0/9; 

        ImplicitRungeKuttaIntegrator<Step> iRKi(A,b);
        return iRKi.solve(f, df, time, y0, steps);

    }



}


