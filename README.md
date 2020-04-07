# Runge Kutta ODE Solver

**UNDER CONSTRUCTION**

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

will follow


## Examples

TODO

## What the Code does not provide!

The code comes with ABSOLUTELY NO WARRANTY. See the [license](./LICENSE) for more information.

The code implements Runge Kutta methods but does not check if a solution blow up occurs. It does not (yet) feature any adaptive integration. It is your job to select the right Runge-Kutta method (e.g. A-stable, L-stable etc.).

## Playing aroung with the `demo.cpp` file



## Sources

- Implementation details have been taken from [Prof. Hiptmair's](https://math.ethz.ch/sam/the-institute/people/ralf-hiptmair.html) [lecture notes](https://www.sam.math.ethz.ch/~grsam/NCSE19/NumCSE_Lecture_Document.pdf) as well as homeworks.

## License

See the [license](./LICENSE) file in this repository.
