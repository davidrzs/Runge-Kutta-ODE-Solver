#ifndef RKIMPLEMENTER

#define RKIMPLEMENTER

#include <Eigen/Dense>
#include <vector>


template <class Step> class ExplicitRungeKuttaIntegrator {

    public: 
        ExplicitRungeKuttaIntegrator(const Eigen::MatrixXd &A, const Eigen::VectorXd &b):A(A),b(b),size(A.cols()){
            // TODO add necessary checks
        }


        template<typename Function> std::vector<Step> solve(Function &&f, double time, const Step &y0, unsigned int steps){
            
            std::vector<Step> stepsVector;
            
            double h = time / steps;


        }


    private:
        const Eigen::MatrixXd A;
        const Eigen::VectorXd b;
        unsigned int size;
};





















template <typename Step> class ImplicitRungeKuttaIntegrator {

    public: 
        ImplicitRungeKuttaIntegrator(const Eigen::MatrixXd &A, const Eigen::VectorXd &b) : A(A),b(b),size(A.cols()){
            // TODO add necessary checks
        }


        template<class Function>
        std::vector<Step> solve(Function &&f, double time, const Step &y0, unsigned int steps){
            
            std::vector<Step> stepsVector;
            
            double h = time / steps;

            
        }


    private:
        const Eigen::MatrixXd A;
        const Eigen::VectorXd b;
        unsigned int size;
};



#endif
