# Runge Kutta ODE Solver

**under construction**

<p>
  <img src="./demo/lotkaVolterraSolved.png" width="49%" />
  <img src="./demo/lorenzAttractorSolved.png" width="49%" /> 
</p>

This tiny header only C++ library provides very easy to use [Runge-Kutta solvers](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods) for ordinary differential equations.

It features:

- Explicit solvers
- Implicit solvers
- A wide range of built in Runge-Kutta methods.
- Very easy implementation of custom methods. The solvers can implement any provided Butcher scheme.

## Usage

TODO

## Built-in Methods

### Explicit Methods

| **Method Name** | **Order of Convergence** |
|-----------------|-----------|
|      `explicitEulerRule`            |     1      |
|`explicitTrapezoidalRule`|               2  |
|        `explicitMidPointRule`          |  2         |
|             `classical4thOrderRule`    |   4        |
|`kuttas38thRule`| 4 |

### Implicit Methods

| **Method Name** | **Order of Convergence** | **Stability Guarantees**
|-----------------|-----------|----------------|
|      `implicitEulerRule`   |     1    | none |
|`implicitMidpointRule`|    2  | none |
|   `radauRKSSMRule3`   |  3    | L-stable |
|  `radauRKSSMRule5`   |   5   | L-stable |

## Examples

TODO

## Installation

**Installing Eigen**

Make sure you have Eigen installed: This can easily be done using your packet manager:

- on Debian based systems: `sudo apt install libeigen3-dev`
- on RPM based systems: `sudo dnf install eigen3-devel`

To run the code you very likely have to tell your C++ compiler where it can find eigen. For example: `g++ -I /usr/include/eigen3 myFile.cpp`

## What the Code does not provide!

The code comes with ABSOLUTELY NO WARRANTY. See the [license](./LICENSE) for more information.

The code implements Runge Kutta methods but does not check if a solution blow up occurs. It does not (yet) feature any adaptive integration. It is your job to select the right Runge-Kutta method (e.g. A-stable, L-stable etc.).

## Background of this Project

In fall of 2019 I took the class "Numerical Methods for CSE" taught by Prof. Hiptmair at ETH Zürich. Having been fascinated by the stability (as well as instability) of Runge-Kutta methods I have written this tiny library. Since this code might be useful for others too I published it on GitHub.

## Sources

- Implementation details have been taken from [Prof. Hiptmair's](https://math.ethz.ch/sam/the-institute/people/ralf-hiptmair.html) [lecture notes](https://www.sam.math.ethz.ch/~grsam/NCSE19/NumCSE_Lecture_Document.pdf) as well as homeworks.

## License

See the [license](./LICENSE) file in this repository.
