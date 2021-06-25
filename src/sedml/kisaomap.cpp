
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

std::map<int, std::string> g_kisaomap = {
   {654, "amount rate"},
   {386, "scaled preconditioned generalized minimal residual method"},
   {810, "Reduced eigenvalue matrix"},
   {621, "stochastic simulation leaping method"},
   {808, "Reduced stoichiometry matrix"},
   {404, "symmetricity of matrix"},
   {539, "minimum factor to change step size by"},
   {506, "genetic algorithm"},
   {219, "maximum Adams order"},
   {99, "type of system behaviour"},
   {543, "stability limit detection flag"},
   {510, "truncated Newton"},
   {358, "biconjugate gradient method"},
   {325, "minimum fast/discrete reaction occurrences number"},
   {421, "type of validation"},
   {824, "aggregation function"},
   {556, "relative quadrature tolerance"},
   {589, "ACB flux sampling method"},
   {523, "cooling factor"},
   {453, "ordered updating policy"},
   {428, "matrix for clusterization"},
   {497, "KLU"},
   {338, "h-version of the finite element method"},
   {639, "flux"},
   {108, "progression with fixed time step"},
   {606, "Hierarchical Stochastic Simulation Algorithm"},
   {560, "LSODA/LSODAR hybrid method"},
   {837, "particle number"},
   {39, "tau-leaping method"},
   {236, "exact solution"},
   {592, "dynamic rFBA"},
   {432, "IDA-like method"},
   {203, "particle number lower limit"},
   {517, "number of generations"},
   {319, "Monte Carlo method"},
   {632, "functional iteration root-finding method"},
   {64, "Runge-Kutta based method"},
   {97, "modelling and simulation algorithm characteristic"},
   {415, "maximum number of steps"},
   {448, "logical model simulation method"},
   {521, "simulated annealing parameter"},
   {554, "parsimonius flux balance analysis (minimum number of active fluxes)"},
   {528, "parsimonious enzyme usage flux balance analysis (minimum sum of absolute fluxes)"},
   {587, "IMEX"},
   {599, "Hybrid Gibson - Euler-Maruyama Method"},
   {201, "modelling and simulation algorithm parameter"},
   {234, "LSODKR"},
   {369, "partial differential equation discretization method"},
   {106, "continuous variable"},
   {604, "MSR Tolerance"},
   {336, "D-leaping method"},
   {835, "Concentration control coefficient matrix (scaled)"},
   {567, "force physical correctness"},
   {340, "h-p version of the finite element method"},
   {17, "multi-state agent-based simulation method"},
   {373, "differential-algebraic equation problem"},
   {617, "IDA-CVODE hybrid method"},
   {475, "integration method"},
   {643, "upper bound"},
   {571, "absolute tolerance adjustment factor"},
   {75, "Gillespie multi-particle method"},
   {829, "minimum"},
   {21, "StochSim nearest-neighbour algorithm"},
   {424, "mean-centring of variables"},
   {469, "maximal timestep"},
   {301, "Heun method"},
   {430, "variables preprocessing parameter"},
   {565, "absolute tolerance for root finding"},
   {532, "loopless"},
   {31, "Euler backward method"},
   {302, "embedded Runge-Kutta method"},
   {437, "flux balance analysis"},
   {597, "tolerance"},
   {104, "stochastic system behaviour"},
   {334, "multiparticle lattice gas automata"},
   {278, "Metropolis Monte Carlo algorithm"},
   {15, "Gillespie first reaction algorithm"},
   {615, "fully-implicit regular grid finite volume method with a variable time step"},
   {347, "meshless geometry handling"},
   {648, "step"},
   {473, "Bayesian inference algorithm"},
   {81, "estimated midpoint tau-leaping method"},
   {223, "number of history bins"},
   {282, "KINSOL"},
   {504, "random search"},
   {28, "slow-scale stochastic simulation algorithm"},
   {384, "semi-implicit midpoint rule"},
   {351, "multinomial tau-leaping method"},
   {486, "maximum iterations"},
   {628, "modelling and simulation algorithm parameter value"},
   {256, "virtual box side length"},
   {435, "embedded Runge-Kutta 5(4) method"},
   {309, "Crank-Nicolson method"},
   {239, "explicit method type"},
   {537, "explicit Runge-Kutta method of order 3(2)"},
   {86, "Fehlberg method"},
   {563, "Pahle hybrid Gibson-Bruck Next Reaction method/RK-45 method"},
   {378, "implicit midpoint rule"},
   {345, "h-p cloud method"},
   {576, "Quadratic MOMA"},
   {243, "method switching control parameter"},
   {626, "band direct solver"},
   {451, "type of updating policy"},
   {484, "maximum order"},
   {58, "Greens function reaction dynamics"},
   {289, "Adams method"},
   {382, "modified midpoint method"},
   {630, "root-finding method"},
   {362, "implicit-state Doob-Gillespie algorithm"},
   {590, "ACHR flux sampling method"},
   {548, "quadratic programming"},
   {515, "Levenberg-Marquardt"},
   {260, "virtual box size"},
   {807, "Elasticity coefficient (scaled)"},
   {395, "improved biconjugate gradient method"},
   {574, "species transition probabilities"},
   {40, "Poisson tau-leaping method"},
   {541, "Beta parameter for stabilized step size control"},
   {95, "sub-volume stochastic reaction-diffusion algorithm"},
   {317, "E-Cell multi-algorithm simulation method"},
   {818, "L0 matrix"},
   {413, "exact Newton method"},
   {343, "generalized finite element method"},
   {478, "preconditioner"},
   {310, "method of lines"},
   {822, "extensive property"},
   {287, "Milstein method"},
   {254, "Brownian diffusion accuracy"},
   {389, "quasi-minimal residual method"},
   {356, "DASSL"},
   {624, "method for solving a system of linear equations"},
   {552, "optimization method"},
   {323, "equation-free probabilistic steady-state approximation"},
   {482, "half-bandwith parameter"},
   {228, "tau-leaping epsilon"},
   {393, "ingenious conjugate gradients-squared method"},
   {495, "random asynchronous updating policy"},
   {637, "derived property"},
   {90, "LSODI"},
   {232, "LSOIBT"},
   {367, "partitioned Runge-Kutta method"},
   {806, "Elasticity matrix (scaled)"},
   {641, "bound"},
   {526, "flux variability analysis"},
   {559, "initial step size"},
   {321, "Cash-Karp method"},
   {51, "Bortz-Kalos-Lebowitz algorithm"},
   {585, "TOMS731"},
   {328, "minimum fast rate"},
   {820, "model and simulation property characteristic"},
   {354, "Krylov subspace projection method"},
   {602, "Minimum species threshold for continuous approximation"},
   {230, "minimum reactions per leap"},
   {595, "rFBA"},
   {332, "ER-leap initial leap"},
   {635, "unscaled property"},
   {493, "synchronous updating policy"},
   {276, "Gill method"},
   {524, "partitioned leaping method"},
   {45, "implicit tau-leaping method"},
   {429, "clusterization parameter"},
   {371, "stochastic differential equation problem"},
   {307, "finite difference method"},
   {652, "concentration rate"},
   {204, "particle number upper limit"},
   {409, "ordinary Newton method"},
   {280, "Adams-Moulton method"},
   {502, "DA-DFBA"},
   {339, "p-version of the finite element method"},
   {84, "nonnegative Poisson tau-leaping method"},
   {263, "NFSim agent-based simulation method"},
   {561, "Pahle hybrid Gibson-Bruck Next Reaction method/Runge-Kutta method"},
   {398, "iterative method for solving a system of linear equations"},
   {365, "NDSolve method"},
   {838, "concentration"},
   {102, "spatial description"},
   {600, "Hybrid Adaptive Gibson - Milstein Method"},
   {467, "maximum step size"},
   {609, "Embedded Runge-Kutta Prince-Dormand (8,9) method"},
   {593, "MOMA"},
   {237, "approximate solution"},
   {831, "model and simulation property"},
   {613, "Stochastic simulation algorithm with normally-distributed next reaction times"},
   {646, "propensity"},
   {529, "parallelism"},
   {241, "Gillespie-like method"},
   {274, "first-passage Monte Carlo algorithm"},
   {471, "local optimization algorithm"},
   {809, "Reduced Jacobian matrix"},
   {376, "linearity of equation"},
   {407, "steady state method"},
   {650, "sensitivity"},
   {509, "evolutionary strategy"},
   {805, "Elasticity coefficient (unscaled)"},
   {535, "VODE"},
   {568, "NLEQ1"},
   {89, "LSODAR"},
   {305, "Verner method"},
   {56, "Smoluchowski equation based method"},
   {546, "convex optimization algorithm"},
   {513, "NL2SOL"},
   {572, "level of superimposed noise"},
   {816, "Link matrix"},
   {579, "Linear MOMA"},
   {411, "Newton-like method"},
   {248, "tau-leaping delta"},
   {341, "mixed finite element method"},
   {644, "maximum flux"},
   {611, "Incremental stochastic simulation algorithm"},
   {500, "SOA-DFBA"},
   {405, "type of differential equation"},
   {380, "Richardson extrapolation based method"},
   {285, "finite volume method"},
   {507, "genetic algorithm SR"},
   {0, "modelling and simulation algorithm"},
   {252, "partitioning control parameter"},
   {544, "IDAS"},
   {418, "N-way partial least squares regression method"},
   {511, "steepest descent"},
   {348, "extended finite element method"},
   {315, "lattice gas automata"},
   {804, "Elasticity matrix (unscaled)"},
   {827, "standard error"},
   {422, "number of N-way partial least squares regression factors"},
   {29, "Gillespie direct algorithm"},
   {629, "Null"},
   {557, "absolute steady-state tolerance"},
   {487, "minimum damping"},
   {454, "constant updating policy"},
   {82, "k-alpha leaping method"},
   {583, "minimum order"},
   {326, "number of samples"},
   {550, "simplex method"},
   {505, "particle swarm"},
   {622, "flux balance method"},
   {655, "rate"},
   {87, "Dormand-Prince method"},
   {283, "IDA"},
   {480, "lower half-bandwidth"},
   {352, "hybrid method"},
   {296, "Hammer-Hollingsworth method"},
   {518, "evolutionary algorithm parameter"},
   {98, "type of variable"},
   {449, "synchronous logical model simulation method"},
   {416, "partial least squares regression method"},
   {802, "Control coefficient (scaled)"},
   {803, "Control coefficient (unscaled)"},
   {825, "mean"},
   {588, "flux sampling"},
   {420, "number of partial least squares components"},
   {555, "absolute quadrature tolerance"},
   {522, "start temperature"},
   {93, "LSODPK"},
   {235, "type of solution"},
   {337, "finite element method"},
   {433, "CVODE-like method"},
   {363, "rule-based simulation method"},
   {330, "R-leaping algorithm"},
   {100, "type of progression time step"},
   {498, "number of runs"},
   {607, "Hierarchical Fehlberg method"},
   {549, "non-linear programming"},
   {516, "Hooke&Jeeves"},
   {633, "computational function"},
   {491, "discrete event simulation algorithm"},
   {261, "Euler method"},
   {396, "transpose-free quasi-minimal residual algorithm"},
   {819, "Nr matrix"},
   {553, "optimization solver"},
   {801, "Concentration control coefficient matrix (unscaled)"},
   {427, "number of clusters"},
   {22, "Elf and Ehrenberg method"},
   {520, "evolutionary algorithm"},
   {324, "nested stochastic simulation algorithm"},
   {76, "Stundzia and Lumsden method"},
   {533, "pFBA factor"},
   {566, "stochastic second order Runge-Kutta method"},
   {605, "SDE Tolerance"},
   {303, "Zonneveld method"},
   {107, "progression with adaptive time step"},
   {598, "Hybrid Gibson - Milstein Method"},
   {836, "amount"},
   {335, "generalized stochastic simulation algorithm"},
   {209, "relative tolerance"},
   {374, "ordinary differential equation problem"},
   {476, "iteration type"},
   {618, "bunker"},
   {279, "Adams-Bashforth method"},
   {71, "LSODE"},
   {570, "auto reduce tolerances"},
   {48, "adaptive explicit-implicit tau-leaping method"},
   {329, "constant-time kinetic Monte Carlo algorithm"},
   {74, "binomial tau-leaping method"},
   {425, "standardising of variables"},
   {20, "PVODE"},
   {527, "geometric flux balance analysis"},
   {32, "explicit fourth-order Runge-Kutta method"},
   {834, "rate of change"},
   {564, "stochastic Runge-Kutta method"},
   {33, "Rosenbrock method"},
   {531, "fraction of optimum"},
   {105, "discrete variable"},
   {346, "mesh-based geometry handling"},
   {372, "partial differential equation problem"},
   {577, "flux minimization weight"},
   {649, "shadow price"},
   {616, "semi-implicit regular grid finite volume method with a fixed time step"},
   {244, "granularity control parameter"},
   {379, "Bulirsch-Stoer algorithm"},
   {211, "absolute tolerance"},
   {452, "random updating policy"},
   {581, "BKMC"},
   {653, "particle number rate"},
   {620, "parsimonius flux balance analysis"},
   {257, "surface-bound epsilon"},
   {580, "ROOM"},
   {27, "Gibson-Bruck next reaction algorithm"},
   {350, "probability-weighted dynamic Monte Carlo method"},
   {308, "MacCormack method"},
   {538, "safety factor on new step selection"},
   {468, "maximal timestep method"},
   {205, "partitioning interval"},
   {30, "Euler forward method"},
   {800, "systems property"},
   {436, "Dormand-Prince 8(5,3) method"},
   {403, "homogeneousness of equation"},
   {614, "Implementation"},
   {472, "global optimization algorithm"},
   {311, "type of domain geometry handling"},
   {575, "Hybrid tau-leaping method"},
   {542, "correction step should use internally generated full Jacobian"},
   {288, "backward differentiation formula"},
   {627, "diagonal approximate Jacobian solver"},
   {485, "minimum step size"},
   {815, "Flux control coefficient matrix (scaled)"},
   {255, "molecules per virtual box"},
   {357, "conjugate gradient method"},
   {383, "Bader-Deuflhard method"},
   {38, "sorting stochastic simulation algorithm"},
   {394, "quasi-minimal residual variant of biconjugate gradient stabilized method"},
   {591, "mdFBA"},
   {638, "level"},
   {496, "CVODES"},
   {631, "iterative root-finding method"},
   {514, "Nelder-Mead"},
   {318, "Gauss-Legendre Runge-Kutta method"},
   {447, "COAST"},
   {540, "maximum factor to change step size by"},
   {573, "probabilistic logical model simulation method"},
   {817, "Kernel matrix"},
   {479, "upper half-bandwidth"},
   {249, "critical firing threshold"},
   {19, "CVODE"},
   {216, "integrate reduced model"},
   {586, "Gibson-Bruck next reaction algorithm with indexed priority queue"},
   {821, "intensive property"},
   {483, "step size"},
   {625, "dense direct solver"},
   {253, "coarse-graining factor"},
   {450, "asynchronous logical model simulation method"},
   {388, "minimal residual method"},
   {220, "maximum BDF order"},
   {355, "DASPK"},
   {322, "hybridity"},
   {419, "metamodelling method"},
   {299, "Butcher-Kuntzmann method"},
   {814, "Flux control coefficient matrix (unscaled)"},
   {233, "LSODES"},
   {91, "LSODIS"},
   {392, "biconjugate gradient stabilized method"},
   {636, "primary property"},
   {603, "Minimum reaction rate for continuous approximation"},
   {68, "deterministic cellular automata update algorithm"},
   {558, "relative steady-state tolerance"},
   {525, "stop condition"},
   {642, "minimum flux"},
   {423, "partial least squares regression-like method"},
   {353, "generalized minimal residual algorithm"},
   {320, "BioRica hybrid method"},
   {455, "prioritized updating policy"},
   {584, "initial order"},
   {551, "primal-dual interior point method"},
   {828, "maximum"},
   {596, "srFBA"},
   {601, "Number of trials"},
   {333, "accelerated stochastic simulation algorithm"},
   {366, "symplecticness"},
   {103, "deterministic system behaviour"},
   {832, "time"},
   {812, "Jacobian matrix"},
   {264, "cellular automata update method"},
   {297, "Lobatto method"},
   {519, "population size"},
   {494, "fully asynchronous updating policy"},
   {231, "Pahle hybrid method"},
   {647, "derivative"},
   {46, "trapezoidal tau-leaping method"},
   {640, "lower bound"},
   {813, "Eigenvalue matrix"},
   {370, "type of problem"},
   {839, "temperature"},
   {434, "Higham-Hall method"},
   {569, "NLEQ2"},
   {306, "Lagrangian sliding fluid element algorithm"},
   {536, "ZVODE"},
   {281, "multistep method"},
   {503, "simulated annealing"},
   {408, "Newton-type method"},
   {651, "reduced costs"},
   {562, "Pahle hybrid Gibson-Bruck Next Reaction method/LSODA method"},
   {492, "asynchronous updating policy"},
   {634, "scaled property"},
   {238, "type of method"},
   {594, "order"},
   {397, "preconditioning technique"},
   {331, "exact R-leaping algorithm"},
   {364, "Adams predictor-corrector method"},
   {499, "dynamic flux balance analysis"},
   {608, "Hierarchical flux balance analysis"},
   {242, "error control parameter"},
   {377, "one-step method"},
   {645, "objective value"},
   {612, "implicit 4th order Runge-Kutta method at Gaussian points"},
   {470, "optimization algorithm"},
   {811, "Stoichiometry matrix"},
   {3, "weighted stochastic simulation algorithm"},
   {501, "DOA-DFBA"},
   {381, "midpoint method"},
   {57, "Brownian diffusion Smoluchowski method"},
   {304, "Radau method"},
   {534, "reactions"},
   {349, "method of finite spheres"},
   {94, "Livermore solver"},
   {316, "enhanced Greens function reaction dynamics"},
   {412, "inexact Newton method"},
   {547, "linear programming"},
   {619, "emc-sim"},
   {477, "linear solver"},
   {273, "hard-particle molecular dynamics"},
   {240, "implicit method type"},
   {375, "delay differential equation problem"},
   {342, "level set method"},
   {610, "Composite-rejection stochastic simulation algorithm"},
   {88, "LSODA"},
   {508, "evolutionary programming"},
   {286, "Euler-Maruyama method"},
   {656, "use adaptive time steps"},
   {481, "interpolate solution"},
   {623, "flux balance problem"},
   {410, "simlified Newton method"},
   {578, "nested algorithm"},
   {290, "Merson method"},
   {512, "praxis"},
   {545, "include sensitivity variables in error control mechanism"},
   {417, "hierarchical cluster-based partial least squares regression method"},
   {314, "S-System power-law canonical differential equations solver"},
   {582, "Spatiocyte method"},
   {826, "standard deviation"},
   {488, "seed"},
   {258, "neighbour distance"},
   {327, "maximum discrete number"},
};
