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
         * The solve methods applies an explicit Runge Kutta method to a given ODE
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
            
            // as advertised the first position will be our initial state
            stepsVector.push_back(y0);

            // knowing the total time and number of steps allows us to calculate the time we integrate over every step
            double h = time / steps;

            // now we call the solver "steps" times to do the actual integration
            for(unsigned int i = 0; i < steps; i++){
                // integrate and directly add to our list
                stepsVector.push_back(iteration(f,stepsVector.back(),h));
            }
            
            return stepsVector;


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
            
            // initialize current step as previous step
            Step y1 = y0;

            // temporary vector to store the increments
            std::vector<Step> increments;
            
            // calculate an increment per loop iteration
            for(unsigned int i = 0; i < size; i++){

                Step increment = y0;
                // second loop to account for dependency of current increments on previous increments
                for(unsigned int k = 0; k < i; k++){
                    increment += h*A(i,k) * increments[k];
                }

                // store the increment                
                increments.push_back(f(increment));
            }

            // now we add the increments with correct weights to y0 which we already copied over to y1
            for(unsigned int i = 0; i < size; i++){
                y1 += h*b(i) *increments[i];
            }

            return y1;

        }


        const Eigen::MatrixXd A;
        const Eigen::VectorXd b;
        unsigned int size;
};












template <typename Step> class ImplicitRungeKuttaIntegrator {

    public:
        ImplicitRungeKuttaIntegrator(const Eigen::MatrixXd &A, const Eigen::VectorXd &b) : A(A),b(b),size(A.cols()){
        }


        /**
         * The solve methods applies an explicit Runge Kutta method to a given ODE
         * 
         * @param f the function we are integrating over
         * @param the Jacobian of f, needed for finding 0 (newton method) to solve for stages.
         * @param time the time interval we want to integrate over
         * @param y0 the initial state of the system
         * @param steps the number of integration steps we would like to make (number of steps equals number of runge kutta method evaluations)
         * 
         * @return a std::vector of states, one for every integration step performed. The first step will be the supplied y0.
         */
        template<typename Function, typename Jacobian>
        std::vector<Step> solve(Function &&f, Jacobian && J, double time, const Step &y0, unsigned int steps){

            std::vector<Step> stepsVector;
            
            // as advertised the first position will be our initial state
            stepsVector.push_back(y0);

            // knowing the total time and number of steps allows us to calculate the time we integrate over every step
            double h = time / steps;

            // now we call the solver "steps" times to do the actual integration
            for(unsigned int i = 0; i < steps; i++){
                // integrate and directly add to our list
                stepsVector.push_back(iteration(f,stepsVector.back(),h));
            }
            
            return stepsVector;


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
        template<typename Function, typename Jacobian>
        Step iteration(Function &&f, Jacobian && J, Step &y0, const double h){
            
            // TODO 

        }


    private:
        const Eigen::MatrixXd A;
        const Eigen::VectorXd b;
        unsigned int size;
};



#endif
