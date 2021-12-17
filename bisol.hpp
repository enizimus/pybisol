#ifndef BISOL_H
#define BISOL_H

#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

// Definitions of various constants : 
#define INPUT_LEN 8
#define M_PI      3.14159265358979323846
#define M_PI_H    1.5707963267948966
#define C_A       0.000003
#define E_M       1.0

// Definitions for stray field calculation : 
#define N_PTS   11
#define Y_MAX   10
#define X_MAX   10

// Definitions for point locations solenoid sides : 
#define INSIDE  1
#define TOP     2
#define RIGHT   3
#define BOTTOM  4
#define LEFT    5
#define OUTSIDE 6

// Define quadrature consts 
#define QUADPTSLEN    5
#define CONVERGED     1
#define NOT_CONVERGED 0

// Definition of integration constants :
extern std::vector<double> xi;
extern std::vector<double> w_3;
extern std::vector<double> w_7;
extern std::vector<double> w_15;
extern std::vector<double> w_31;
extern std::vector<double> w_63;
extern std::vector<int> nQuadPts;

// Internal data structures :
struct IntPts;
struct Geometry;
struct QuadResult;

// Function definitions : 
int checkPointLocation(Geometry geometry);
IntPts getIntegrationPoints(const int ptLocation, Geometry geometry);
std::vector<double> calculateArea(const IntPts intPts);
double calcCompleteEllipticalInt(double p1, double p2, double p3, double p4);
std::vector<double> potFunctionEn(double x, double y, double xf, double yf);
std::vector<double> potFunctionBs(double x, double y, double xf, double yf);
QuadResult gaussQuadrature(std::vector<double> potFunc(double, double, double, double),
                            IntPts intPts, const int ind, const double tolerance);
double integratePoints(const IntPts intPts, const double currDens, const double tolerance);
std::vector<double> integratePointsBStray(const IntPts intPts, const double currDens, const double tolerance);
double integrateCoilEnergy(const std::vector<double> geometry, const double
	currDens, const double xF, const double yF);
double calculatePartialEnergy(const std::vector<double> geometry1, 
	const std::vector<double> geometry2,
	const double currDens1, const double currDens2);
double calculateEnergy(const std::vector<double> geometrySol1,
	const std::vector<double> geometrySol2,
	const double currDensSol1, const double  currDensSol2);
std::vector<double> calculatePartialStrayField(const std::vector<double> geometry,
                                             const double currDensSol1,
                                             double xF, double yF);
std::vector<double> calculateStrayField(const std::vector<double> geometrySol1, 
                                      const std::vector<double> geometrySol2, 
                                      const double currDensSol1, const double  currDensSol2);
std::vector<double> calculateMaxField(const std::vector<double> geometrySol1, 
                                    const std::vector<double> geometrySol2, 
                                    const double currDensSol1, const double  currDensSol2);
void solve(double *prms, double *result);

#endif