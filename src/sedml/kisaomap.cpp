
/**
 * \file    kisao.cpp
 * \brief   KiSAO map
 * \author  Lucian Smith
 * 
 * <!--------------------------------------------------------------------------
 * 
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on 
 * github: https://github.com/fbergmann/libSEDML/
 * 
 * 
 * Copyright (c) 2013-2021, Frank T. Bergmann  
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ---------------------------------------------------------------------- -->
 * 
 */
 
#include <map>
#include <string>
#include "sedml/common/libsedml-version.h"

LIBSEDML_CPP_NAMESPACE_BEGIN

std::map<int, std::string> g_kisaomap = {
   {0, "modelling and simulation algorithm"},
   {3, "weighted stochastic simulation algorithm"},
   {15, "Gillespie first reaction algorithm"},
   {17, "multi-state agent-based simulation method"},
   {19, "CVODE"},
   {20, "PVODE"},
   {21, "StochSim nearest-neighbour algorithm"},
   {22, "Elf and Ehrenberg method"},
   {27, "Gibson-Bruck next reaction algorithm"},
   {28, "slow-scale stochastic simulation algorithm"},
   {29, "Gillespie direct algorithm"},
   {30, "Euler forward method"},
   {31, "Euler backward method"},
   {32, "explicit fourth-order Runge-Kutta method"},
   {33, "Rosenbrock method"},
   {38, "sorting stochastic simulation algorithm"},
   {39, "tau-leaping method"},
   {40, "Poisson tau-leaping method"},
   {45, "implicit tau-leaping method"},
   {46, "trapezoidal tau-leaping method"},
   {48, "adaptive explicit-implicit tau-leaping method"},
   {51, "Bortz-Kalos-Lebowitz algorithm"},
   {56, "Smoluchowski equation based method"},
   {57, "Brownian diffusion Smoluchowski method"},
   {58, "Greens function reaction dynamics"},
   {64, "Runge-Kutta based method"},
   {68, "deterministic cellular automata update algorithm"},
   {71, "LSODE"},
   {74, "binomial tau-leaping method"},
   {75, "Gillespie multi-particle method"},
   {76, "Stundzia and Lumsden method"},
   {81, "estimated midpoint tau-leaping method"},
   {82, "k-alpha leaping method"},
   {84, "nonnegative Poisson tau-leaping method"},
   {86, "Fehlberg method"},
   {87, "Dormand-Prince method"},
   {88, "LSODA"},
   {89, "LSODAR"},
   {90, "LSODI"},
   {91, "LSODIS"},
   {93, "LSODPK"},
   {94, "Livermore solver"},
   {95, "sub-volume stochastic reaction-diffusion algorithm"},
   {97, "modelling and simulation algorithm characteristic"},
   {98, "type of variable"},
   {99, "type of system behaviour"},
   {100, "type of progression time step"},
   {102, "spatial description"},
   {103, "deterministic system behaviour"},
   {104, "stochastic system behaviour"},
   {105, "discrete variable"},
   {106, "continuous variable"},
   {107, "progression with adaptive time step"},
   {108, "progression with fixed time step"},
   {201, "modelling and simulation algorithm parameter"},
   {203, "particle number lower limit"},
   {204, "particle number upper limit"},
   {205, "partitioning interval"},
   {209, "relative tolerance"},
   {211, "absolute tolerance"},
   {216, "use reduced model"},
   {219, "maximum Adams order"},
   {220, "maximum BDF order"},
   {223, "number of history bins"},
   {228, "tau-leaping epsilon"},
   {230, "minimum reactions per leap"},
   {231, "Pahle hybrid method"},
   {232, "LSOIBT"},
   {233, "LSODES"},
   {234, "LSODKR"},
   {235, "type of solution"},
   {236, "exact solution"},
   {237, "approximate solution"},
   {238, "type of method"},
   {239, "explicit method type"},
   {240, "implicit method type"},
   {241, "Gillespie-like method"},
   {242, "error control parameter"},
   {243, "method switching control parameter"},
   {244, "granularity control parameter"},
   {248, "tau-leaping delta"},
   {249, "critical firing threshold"},
   {252, "partitioning control parameter"},
   {253, "coarse-graining factor"},
   {254, "Brownian diffusion accuracy"},
   {255, "molecules per virtual box"},
   {256, "virtual box side length"},
   {257, "surface-bound epsilon"},
   {258, "neighbour distance"},
   {260, "virtual box size"},
   {261, "Euler method"},
   {263, "NFSim agent-based simulation method"},
   {264, "cellular automata update method"},
   {273, "hard-particle molecular dynamics"},
   {274, "first-passage Monte Carlo algorithm"},
   {276, "Gill method"},
   {278, "Metropolis Monte Carlo algorithm"},
   {279, "Adams-Bashforth method"},
   {280, "Adams-Moulton method"},
   {281, "multistep method"},
   {282, "KINSOL"},
   {283, "IDA"},
   {285, "finite volume method"},
   {286, "Euler-Maruyama method"},
   {287, "Milstein method"},
   {288, "backward differentiation formula"},
   {289, "Adams method"},
   {290, "Merson method"},
   {296, "Hammer-Hollingsworth method"},
   {297, "Lobatto method"},
   {299, "Butcher-Kuntzmann method"},
   {301, "Heun method"},
   {302, "embedded Runge-Kutta method"},
   {303, "Zonneveld method"},
   {304, "Radau method"},
   {305, "Verner method"},
   {306, "Lagrangian sliding fluid element algorithm"},
   {307, "finite difference method"},
   {308, "MacCormack method"},
   {309, "Crank-Nicolson method"},
   {310, "method of lines"},
   {311, "type of domain geometry handling"},
   {314, "S-System power-law canonical differential equations solver"},
   {315, "lattice gas automata"},
   {316, "enhanced Greens function reaction dynamics"},
   {317, "E-Cell multi-algorithm simulation method"},
   {318, "Gauss-Legendre Runge-Kutta method"},
   {319, "Monte Carlo method"},
   {320, "BioRica hybrid method"},
   {321, "Cash-Karp method"},
   {322, "hybridity"},
   {323, "equation-free probabilistic steady-state approximation"},
   {324, "nested stochastic simulation algorithm"},
   {325, "minimum fast/discrete reaction occurrences number"},
   {326, "number of samples"},
   {327, "maximum discrete number"},
   {328, "minimum fast rate"},
   {329, "constant-time kinetic Monte Carlo algorithm"},
   {330, "R-leaping algorithm"},
   {331, "exact R-leaping algorithm"},
   {332, "ER-leap initial leap"},
   {333, "accelerated stochastic simulation algorithm"},
   {334, "multiparticle lattice gas automata"},
   {335, "generalized stochastic simulation algorithm"},
   {336, "D-leaping method"},
   {337, "finite element method"},
   {338, "h-version of the finite element method"},
   {339, "p-version of the finite element method"},
   {340, "h-p version of the finite element method"},
   {341, "mixed finite element method"},
   {342, "level set method"},
   {343, "generalized finite element method"},
   {345, "h-p cloud method"},
   {346, "mesh-based geometry handling"},
   {347, "meshless geometry handling"},
   {348, "extended finite element method"},
   {349, "method of finite spheres"},
   {350, "probability-weighted dynamic Monte Carlo method"},
   {351, "multinomial tau-leaping method"},
   {352, "hybrid method"},
   {353, "generalized minimal residual algorithm"},
   {354, "Krylov subspace projection method"},
   {355, "DASPK"},
   {356, "DASSL"},
   {357, "conjugate gradient method"},
   {358, "biconjugate gradient method"},
   {362, "implicit-state Doob-Gillespie algorithm"},
   {363, "rule-based simulation method"},
   {364, "Adams predictor-corrector method"},
   {365, "NDSolve method"},
   {366, "symplecticness"},
   {367, "partitioned Runge-Kutta method"},
   {369, "partial differential equation discretization method"},
   {370, "type of problem"},
   {371, "stochastic differential equation problem"},
   {372, "partial differential equation problem"},
   {373, "differential-algebraic equation problem"},
   {374, "ordinary differential equation problem"},
   {375, "delay differential equation problem"},
   {376, "linearity of equation"},
   {377, "one-step method"},
   {378, "implicit midpoint rule"},
   {379, "Bulirsch-Stoer algorithm"},
   {380, "Richardson extrapolation based method"},
   {381, "midpoint method"},
   {382, "modified midpoint method"},
   {383, "Bader-Deuflhard method"},
   {384, "semi-implicit midpoint rule"},
   {386, "scaled preconditioned generalized minimal residual method"},
   {388, "minimal residual method"},
   {389, "quasi-minimal residual method"},
   {392, "biconjugate gradient stabilized method"},
   {393, "ingenious conjugate gradients-squared method"},
   {394, "quasi-minimal residual variant of biconjugate gradient stabilized method"},
   {395, "improved biconjugate gradient method"},
   {396, "transpose-free quasi-minimal residual algorithm"},
   {397, "preconditioning technique"},
   {398, "iterative method for solving a system of linear equations"},
   {403, "homogeneousness of equation"},
   {404, "symmetricity of matrix"},
   {405, "type of differential equation"},
   {407, "steady state method"},
   {408, "Newton-type method"},
   {409, "ordinary Newton method"},
   {410, "simlified Newton method"},
   {411, "Newton-like method"},
   {412, "inexact Newton method"},
   {413, "exact Newton method"},
   {415, "maximum number of steps"},
   {416, "partial least squares regression method"},
   {417, "hierarchical cluster-based partial least squares regression method"},
   {418, "N-way partial least squares regression method"},
   {419, "metamodelling method"},
   {420, "number of partial least squares components"},
   {421, "type of validation"},
   {422, "number of N-way partial least squares regression factors"},
   {423, "partial least squares regression-like method"},
   {424, "mean-centring of variables"},
   {425, "standardising of variables"},
   {427, "number of clusters"},
   {428, "matrix for clusterization"},
   {429, "clusterization parameter"},
   {430, "variables preprocessing parameter"},
   {432, "IDA-like method"},
   {433, "CVODE-like method"},
   {434, "Higham-Hall method"},
   {435, "embedded Runge-Kutta 5(4) method"},
   {436, "Dormand-Prince 8(5,3) method"},
   {437, "flux balance analysis"},
   {447, "COAST"},
   {448, "logical model simulation method"},
   {449, "synchronous logical model simulation method"},
   {450, "asynchronous logical model simulation method"},
   {451, "type of updating policy"},
   {452, "random updating policy"},
   {453, "ordered updating policy"},
   {454, "constant updating policy"},
   {455, "prioritized updating policy"},
   {467, "maximum step size"},
   {468, "maximal timestep method"},
   {469, "maximal timestep"},
   {470, "optimization algorithm"},
   {471, "local optimization algorithm"},
   {472, "global optimization algorithm"},
   {473, "Bayesian inference algorithm"},
   {475, "integration method"},
   {476, "iteration type"},
   {477, "linear solver"},
   {478, "preconditioner"},
   {479, "upper half-bandwidth"},
   {480, "lower half-bandwidth"},
   {481, "interpolate solution"},
   {482, "half-bandwith parameter"},
   {483, "step size"},
   {484, "maximum order"},
   {485, "minimum step size"},
   {486, "maximum iterations"},
   {487, "minimum damping"},
   {488, "seed"},
   {491, "discrete event simulation algorithm"},
   {492, "asynchronous updating policy"},
   {493, "synchronous updating policy"},
   {494, "fully asynchronous updating policy"},
   {495, "random asynchronous updating policy"},
   {496, "CVODES"},
   {497, "KLU"},
   {498, "number of runs"},
   {499, "dynamic flux balance analysis"},
   {500, "SOA-DFBA"},
   {501, "DOA-DFBA"},
   {502, "DA-DFBA"},
   {503, "simulated annealing"},
   {504, "random search"},
   {505, "particle swarm"},
   {506, "genetic algorithm"},
   {507, "genetic algorithm SR"},
   {508, "evolutionary programming"},
   {509, "evolutionary strategy"},
   {510, "truncated Newton"},
   {511, "steepest descent"},
   {512, "praxis"},
   {513, "NL2SOL"},
   {514, "Nelder-Mead"},
   {515, "Levenberg-Marquardt"},
   {516, "Hooke&Jeeves"},
   {517, "number of generations"},
   {518, "evolutionary algorithm parameter"},
   {519, "population size"},
   {520, "evolutionary algorithm"},
   {521, "simulated annealing parameter"},
   {522, "start temperature"},
   {523, "cooling factor"},
   {524, "partitioned leaping method"},
   {525, "stop condition"},
   {526, "flux variability analysis"},
   {527, "geometric flux balance analysis"},
   {528, "parsimonious enzyme usage flux balance analysis (minimum sum of absolute fluxes)"},
   {529, "parallelism"},
   {531, "fraction of optimum"},
   {532, "loopless"},
   {533, "pFBA factor"},
   {534, "reactions"},
   {535, "VODE"},
   {536, "ZVODE"},
   {537, "explicit Runge-Kutta method of order 3(2)"},
   {538, "safety factor on new step selection"},
   {539, "minimum factor to change step size by"},
   {540, "maximum factor to change step size by"},
   {541, "beta parameter for stabilized step size control"},
   {542, "correction step should use internally generated full Jacobian"},
   {543, "stability limit detection flag"},
   {544, "IDAS"},
   {545, "include sensitivity variables in error control mechanism"},
   {546, "convex optimization algorithm"},
   {547, "linear programming"},
   {548, "quadratic programming"},
   {549, "non-linear programming"},
   {550, "simplex method"},
   {551, "primal-dual interior point method"},
   {552, "optimization method"},
   {553, "optimization solver"},
   {554, "parsimonius flux balance analysis (minimum number of active fluxes)"},
   {555, "absolute quadrature tolerance"},
   {556, "relative quadrature tolerance"},
   {557, "absolute steady-state tolerance"},
   {558, "relative steady-state tolerance"},
   {559, "initial step size"},
   {560, "LSODA/LSODAR hybrid method"},
   {561, "Pahle hybrid Gibson-Bruck Next Reaction method/Runge-Kutta method"},
   {562, "Pahle hybrid Gibson-Bruck Next Reaction method/LSODA method"},
   {563, "Pahle hybrid Gibson-Bruck Next Reaction method/RK-45 method"},
   {564, "stochastic Runge-Kutta method"},
   {565, "absolute tolerance for root finding"},
   {566, "stochastic second order Runge-Kutta method"},
   {567, "force physical correctness"},
   {568, "NLEQ1"},
   {569, "NLEQ2"},
   {570, "auto reduce tolerances"},
   {571, "absolute tolerance adjustment factor"},
   {572, "level of superimposed noise"},
   {573, "probabilistic logical model simulation method"},
   {574, "species transition probabilities"},
   {575, "hybrid tau-leaping method"},
   {576, "quadratic MOMA"},
   {577, "flux minimization weight"},
   {578, "nested algorithm"},
   {579, "linear MOMA"},
   {580, "ROOM"},
   {581, "BKMC"},
   {582, "Spatiocyte method"},
   {583, "minimum order"},
   {584, "initial order"},
   {585, "TOMS731"},
   {586, "Gibson-Bruck next reaction algorithm with indexed priority queue"},
   {587, "IMEX"},
   {588, "flux sampling"},
   {589, "ACB flux sampling method"},
   {590, "ACHR flux sampling method"},
   {591, "mdFBA"},
   {592, "dynamic rFBA"},
   {593, "MOMA"},
   {594, "order"},
   {595, "rFBA"},
   {596, "srFBA"},
   {597, "tolerance"},
   {598, "hybrid Gibson - Milstein method"},
   {599, "hybrid Gibson - Euler-Maruyama method"},
   {600, "hybrid adaptive Gibson - Milstein method"},
   {601, "number of trials"},
   {602, "minimum species threshold for continuous approximation"},
   {603, "minimum reaction rate for continuous approximation"},
   {604, "MSR tolerance"},
   {605, "SDE tolerance"},
   {606, "hierarchical stochastic simulation algorithm"},
   {607, "hierarchical Fehlberg method"},
   {608, "hierarchical flux balance analysis"},
   {609, "embedded Runge-Kutta Prince-Dormand (8,9) method"},
   {610, "composite-rejection stochastic simulation algorithm"},
   {611, "incremental stochastic simulation algorithm"},
   {612, "implicit 4th order Runge-Kutta method at Gaussian points"},
   {613, "stochastic simulation algorithm with normally-distributed next reaction times"},
   {614, "implementation"},
   {615, "fully-implicit regular grid finite volume method with a variable time step"},
   {616, "semi-implicit regular grid finite volume method with a fixed time step"},
   {617, "IDA-CVODE hybrid method"},
   {618, "bunker"},
   {619, "emc-sim"},
   {620, "parsimonius flux balance analysis"},
   {621, "stochastic simulation leaping method"},
   {622, "flux balance method"},
   {623, "flux balance problem"},
   {624, "method for solving a system of linear equations"},
   {625, "dense direct solver"},
   {626, "band direct solver"},
   {627, "diagonal approximate Jacobian solver"},
   {628, "modelling and simulation algorithm parameter value"},
   {629, "null"},
   {630, "root-finding method"},
   {631, "iterative root-finding method"},
   {632, "functional iteration root-finding method"},
   {633, "computational function"},
   {634, "scaled property"},
   {635, "unscaled property"},
   {636, "primary property"},
   {637, "derived property"},
   {638, "level"},
   {639, "flux"},
   {640, "lower bound"},
   {641, "bound"},
   {642, "minimum flux"},
   {643, "upper bound"},
   {644, "maximum flux"},
   {645, "objective value"},
   {646, "propensity"},
   {647, "derivative"},
   {648, "step"},
   {649, "shadow price"},
   {650, "sensitivity"},
   {651, "reduced costs"},
   {652, "concentration rate"},
   {653, "particle number rate"},
   {654, "amount rate"},
   {655, "rate"},
   {656, "use adaptive time steps"},
   {657, "sequential logical simulation method"},
   {658, "logical model analysis method"},
   {659, "Naldi MDD logical model stable state search method"},
   {660, "logical model stable state search method"},
   {661, "logical model trap space identification method"},
   {662, "Klarner ASP logical model trap space identification method"},
   {663, "BDD logical model trap space identification method"},
   {664, "Second order backward implicit product Euler scheme"},
   {665, "maximum number of iterations for root finding"},
   {666, "Jacobian epsilon"},
   {667, "memory size"},
   {668, "Numerical Recipes in C 'stiff' Rosenbrock method"},
   {669, "Resource Balance Analysis"},
   {670, "use multiple steps"},
   {671, "use stiff method"},
   {672, "Numerical Recipes in C 'quality-controlled Runge-Kutta' method"},
   {673, "skip reactions that produce negative species amounts"},
   {674, "presimulate"},
   {675, "Broyden method"},
   {676, "degree of linearity"},
   {677, "maximum number of steps for presimulation"},
   {678, "maximum number of steps for approximation"},
   {679, "maximum time for approximation"},
   {680, "duration"},
   {681, "maximum time"},
   {682, "allow approximation"},
   {683, "relative tolerance for approximation"},
   {684, "number of steps per output"},
   {685, "biological state optimization method"},
   {686, "Enzyme Cost Minimization"},
   {687, "Max-min Driving Force method"},
   {688, "type of system described"},
   {689, "mathematical system"},
   {690, "biological system"},
   {691, "metabolic system"},
   {692, "cellular system"},
   {693, "biochemical system"},
   {694, "ODE solver"},
   {695, "parameters for"},
   {800, "systems property"},
   {801, "concentration control coefficient matrix (unscaled)"},
   {802, "control coefficient (scaled)"},
   {803, "control coefficient (unscaled)"},
   {804, "elasticity matrix (unscaled)"},
   {805, "elasticity coefficient (unscaled)"},
   {806, "elasticity matrix (scaled)"},
   {807, "elasticity coefficient (scaled)"},
   {808, "reduced stoichiometry matrix"},
   {809, "reduced Jacobian matrix"},
   {810, "reduced eigenvalue matrix"},
   {811, "stoichiometry matrix"},
   {812, "Jacobian matrix"},
   {813, "Eigenvalue matrix"},
   {814, "flux control coefficient matrix (unscaled)"},
   {815, "flux control coefficient matrix (scaled)"},
   {816, "link matrix"},
   {817, "kernel matrix"},
   {818, "L0 matrix"},
   {819, "Nr matrix"},
   {820, "model and simulation property characteristic"},
   {821, "intensive property"},
   {822, "extensive property"},
   {824, "aggregation function"},
   {825, "mean ignoring NaN"},
   {826, "standard deviation ignoring NaN"},
   {827, "standard error ignoring NaN"},
   {828, "maximum ignoring NaN"},
   {829, "minimum ignoring NaN"},
   {830, "maximum"},
   {831, "model and simulation property"},
   {832, "time"},
   {834, "rate of change"},
   {835, "concentration control coefficient matrix (scaled)"},
   {836, "amount"},
   {837, "particle number"},
   {838, "concentration"},
   {839, "temperature"},
   {840, "minimum"},
   {841, "mean"},
   {842, "standard deviation"},
   {843, "standard error"},
   {844, "sum ignoring NaN"},
   {845, "sum"},
   {846, "product ignoring NaN"},
   {847, "product"},
   {848, "cumulative sum ignoring NaN"},
   {849, "cumulative sum"},
   {850, "cumulative product ignoring NaN"},
   {851, "cumulative product"},
   {852, "count ignoring NaN"},
   {853, "count"},
   {854, "length ignoring NaN"},
   {855, "length"},
   {856, "median ignoring NaN"},
   {857, "median"},
   {858, "variance ignoring NaN"},
   {859, "variance"},
};
LIBSEDML_CPP_NAMESPACE_END

