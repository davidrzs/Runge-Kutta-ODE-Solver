#ifndef RKIMPLEMENTER

#define RKIMPLEMENTER

#include <Eigen/Dense>
#include <vector>







/**
 * 
 * Implementation of an explicit Runge Kutta Solver. See the documentation for more information.
 * 
 */
template <class Step> class ExplicitRungeKuttaIntegrator {

    public:
        /**
         * Constructor for the ExplicitRungeKuttaIntegrator
         * 
         * @param A the coefficients matrix A of a butcher scheme
         * @param b the weights vector for a butcher scheme. Note that we are taking a column vector whereas in a butcher tableau this would be a row vector (though doesn't matter if one uses VectorXd in Eigen).
         */
        ExplicitRungeKuttaIntegrator(const Eigen::MatrixXd &A, const Eigen::VectorXd &b):A(A),b(b),size(A.cols()){
        }

        /**
         * The solve methods applies a Runge Kutta method to a given ODE
         * 
         * @param f the function we are integrating over
         * @param time the time interval we want to integrate over
         * @param y0 the initial state of the system
         * @param steps the number of integration steps we would like to make (number of steps equals number of runge kutta method evaluations)
         * 
         * @return a std::vector of states, one for every integration step performed. The first step will be the supplied y0.
         */
        template<typename Function>
        std::vector<Step> solve(Function &&f, double time, const Step &y0, unsigned int steps){

            std::vector<Step> stepsVector;

            double h = time / steps;

        }

    private:
        /**
         * This function computes on single runge kutta step and returns its result.
         * 
         * @param f the function we are integrating over
         * @param y0 the starting value (the initial value or the previous step's result)
         * @param h the step size
         * 
         * @return the computation of one runge kutta step
         */
        template<typename Function>
        Step iteration(Function &&f, Step &y0, const double h){

        }




        const Eigen::MatrixXd A;
        const Eigen::VectorXd b;
        unsigned int size;
};



















template <typename Step> class ImplicitRungeKuttaIntegrator {

    public:
        ImplicitRungeKuttaIntegrator(const Eigen::MatrixXd &A, const Eigen::VectorXd &b) : A(A),b(b),size(A.cols()){
        }


        template<class Function>
        std::vector<Step> solve(Function &&f, double time, const Step &y0, unsigned int steps){

            std::vector<Step> stepsVector;

            double h = time / steps;

            // TODO - implement

        }


    private:
        const Eigen::MatrixXd A;
        const Eigen::VectorXd b;
        unsigned int size;
};



#endif
