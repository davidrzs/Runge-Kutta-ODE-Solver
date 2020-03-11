#include "./rk_implementer.hpp"
#include<vector>

namespace RKSolvers{


    template <class Step> 
    std::vector<State> explicitEulerRule(Function &&f, double time, const Step &y0, unsinged int steps){

        Eigen::MatrixXd A(1,1);
        A << 0;
        
        Eigen::VectorXd b(2);
        b << 1;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }


    template <class Step> 
    std::vector<State> explicitTrapezoidalRule(Function &&f, double time, const Step &y0, unsinged int steps){

        Eigen::MatrixXd A(2,2);
        A << 0,0,
             1, 0;
        
        Eigen::VectorXd b(2);
        b << 0.5,0.5;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }


    template <class Step> 
    std::vector<State> explicitMidPointRule(Function &&f, double time, const Step &y0, unsinged int steps){

        Eigen::MatrixXd A(2,2);
        A << 0,0,
             0.5, 0;
        
        Eigen::VectorXd b(2);
        b << 0,1;

        ExplicitRungeKuttaIntegrator<Step> eRKi(A,b);
        return eRKi.solve(f, time, y0, steps);

    }


    template <class Step> 
    std::vector<State> classical4thOrderRule(Function &&f, double time, const Step &y0, unsinged int steps){

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


    template <class Step> 
    std::vector<State> kuttas38thRule(Function &&f, double time, const Step &y0, unsinged int steps){

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