#include "bisol.hpp"

std::vector<double> xi = { -0.7745966692414834,0,0.7745966692414834,
                -.9604912687080203,-.4342437493468026,
                .4342437493468026,.9604912687080203,
                -.993831963212755,-.8884592328722570,
                -.6211029467372264,-.2233866864289669,
                .2233866864289669,.6211029467372264,
                .8884592328722570,.993831963212755,
                -.9990981249676676,-.9815311495537401,
                -.9296548574297401,-.8367259381688687,
                -.7024962064915271,-.5313197436443756,
                -.3311353932579768,-.1124889431331866,
                .1124889431331866,.3311353932579768,
                .5313197436443756,.7024962064915271,
                .8367259381688687,.9296548574297401,
                .9815311495537401,.9990981249676676,
                -.9998728881203576,-.997206259372222,
                -.9886847575474295,-.9721828747485818,
                -.9463428583734029,-.9103711569570043,
                -.8639079381936905,-.8069405639502176,
                -.7397560443526948,-.6629096600247806,
                -.5771957100520458,-.483618026945841,
                -.3833593241987303,-.2777498220218243,
                -.1682352515522075,-.5634431304659279e-1,
                .5634431304659279e-1,.1682352515522075,
                .2777498220218243,.3833593241987303,
                .483618026945841,.5771957100520458,
                .6629096600247806,.7397560443526948,
                .8069405639502176,.8639079381936905,
                .9103711569570043,.9463428583734029,
                .9721828747485818,.9886847575474295,
                .997206259372222,.9998728881203576 };

std::vector<double> w_3 = { .555555555555555,.888888888888888,
                          .555555555555555 };

std::vector<double> w_7 = { .2684880898683334,.4509165386584741,.2684880898683334,
                          .1046562260264673,.4013974147759622,.4013974147759622,
                          .1046562260264673 };

std::vector<double> w_15 = { .1344152552437842,.2255104997982067,.1344152552437842,
                          .5160328299707974e-1,.2006285293769890,
                          .2006285293769890,.5160328299707974e-1,
                          .1700171962994026e-1,.9292719531512454e-1,
                          .1715119091363914,.2191568584015875,
                          .2191568584015875,.1715119091363914,
                          .9292719531512454e-1,.1700171962994026e-1 };

std::vector<double> w_31 = { .1127552567207687,.672077542959907e-1,.1127552567207687,
                          .258075980961766e-1,.1003142786117956,
                          .1003142786117956,.258075980961766e-1,
                          .8434565739321106e-2,.4646289326175799e-1,
                          .8575592004999035e-1,.1095784210559246,
                          .1095784210559246,.8575592004999035e-1,
                          .4646289326175799e-1,.8434565739321106e-2,
                          .1644604985438781e-1,.1644604985438781e-1,
                          .3595710330712932e-1,.5697950949412336e-1,
                          .7687962049900353e-1,.9362710998126447e-1,
                          .1056698935802348,.1119568730209535,
                          .1119568730209535,.1056698935802348,
                          .9362710998126447e-1,.7687962049900353e-1,
                          .5697950949412336e-1,.3595710330712932e-1,
                          .1644604985438781e-1,.1644604985438781e-1 };

std::vector<double> w_63 = {   .3360387714820773e-1,.5637762836038472e-1,.3360387714820773e-1,
                             .1290380010035127e-1,.5015713930589954e-1,
                             .5015713930589954e-1,.1290380010035127e-1,
                             .4217630441558855e-2,.2323144663991027e-1,
                             .4287796002500773e-1,.5478921052796287e-1,
                             .5478921052796287e-1,.4287796002500773e-1,
                             .2323144663991027e-1,.4217630441558855e-2,
                             .1265156556230068e-2,.8223007957235930e-2,
                             .1797855156812827e-1,.2848975474583355e-1,
                             .3843981024945553e-1,.4681355499062801e-1,
                             .5283494679011652e-1,.5597843651047632e-1,
                             .5597843651047632e-1,.5283494679011652e-1,
                             .4681355499062801e-1,.3843981024945553e-1,
                             .2848975474583355e-1,.1797855156812827e-1,
                             .8223007957235930e-2,.1265156556230068e-2,
                             .3632214818455307e-3,.2579049794685688e-2,
                             .6115506822117246e-2,.1049824690962132e-1,
                             .1540675046655950e-1,.2059423391591271e-1,
                             .2586967932721475e-1,.3107355111168796e-1,
                             .3606443278078257e-1,.4071551011694432e-1,
                             .4491453165363220e-1,.4856433040667320e-1,
                             .5158325395204846e-1,.5390549933526606e-1,
                             .5548140435655936e-1,.5627769983125430e-1,
                             .5627769983125430e-1,.5548140435655936e-1,
                             .5390549933526606e-1,.5158325395204846e-1,
                             .4856433040667320e-1,.4491453165363220e-1,
                             .4071551011694432e-1,.3606443278078257e-1,
                             .3107355111168796e-1,.2586967932721475e-1,
                             .2059423391591271e-1,.1540675046655950e-1,
                             .1049824690962132e-1,.6115506822117246e-2,
                             .2579049794685688e-2,.3632214818455307e-3 };

std::vector<int> nQuadPts = { 3,7,15,31,63 };

struct QuadResult {
    int convergence = NOT_CONVERGED;
    double result = 0.0;
    double resR = 0.0;
    double resZ = 0.0;
};

struct Geometry {
    double rA = 0;
    double rB = 0;
    double hA = 0;
    double hB = 0;
    double xF = 0;
    double yF = 0;
};

struct IntPts {
    std::vector<double> x_low  = { 0,0,0,0 };
    std::vector<double> x_high = { 0,0,0,0 };
    std::vector<double> y_low  = { 0,0,0,0 };
    std::vector<double> y_high = { 0,0,0,0 };
    std::vector<double> xF = { 0,0,0,0 };
    std::vector<double> yF = { 0,0,0,0 };
    int len = 4;
};

std::vector<double> add(std::vector<double> a, std::vector<double> b, int k){
    
    size_t vLen = a.size();
    std::vector<double> out(vLen, 0.0);
    for(size_t ix = 0; ix < vLen; ix++){
        out[ix] = a[ix] + k*b[ix];
    }

    return out;
}

double dot(std::vector<double> a, std::vector<double> b){
    
    size_t vLen = a.size();
    double out = 0.0;
    for(size_t ix = 0; ix < vLen; ix++){
        out += a[ix]*b[ix];
    }

    return out;
}

std::vector<double> mult(std::vector<double> a, std::vector<double> b){
    
    size_t vLen = a.size();
    std::vector<double> out(vLen, 0.0);
    for(size_t ix = 0; ix < vLen; ix++){
        out[ix] = a[ix]*b[ix];
    }

    return out;
}

int checkPointLocation(Geometry geometry) {
    
    double eps = sqrt((geometry.rB - geometry.rA) * (geometry.hB - geometry.hA)) / 3.0;

    if (((geometry.xF >= geometry.rA) & (geometry.xF <= geometry.rB)) & 
        ((geometry.yF >= geometry.hA) & (geometry.yF <= geometry.hB)))
        return INSIDE;

    else {
        
        if ((abs(geometry.xF - geometry.rA) < eps) & 
           ((geometry.yF >= geometry.hA) & (geometry.yF <= geometry.hB)))
            return LEFT;
        else if ((abs(geometry.xF - geometry.rB) < eps) & 
            ((geometry.yF >= geometry.hA) & (geometry.yF <= geometry.hB)))
            return RIGHT;
        else if ((abs(geometry.yF - geometry.hA) < eps) &
            ((geometry.xF >= geometry.rA) & (geometry.xF <= geometry.rB)))
            return BOTTOM;
        else if ((abs(geometry.yF - geometry.hB) < eps) & 
            ((geometry.xF >= geometry.rA) & (geometry.xF <= geometry.rB)))
            return TOP;

    }

    return OUTSIDE;
}

IntPts getIntegrationPoints(const int ptLocation, Geometry geometry) {
    
    IntPts intPts;
    double xlim, ylim;

    intPts.xF = { geometry.xF, geometry.xF, geometry.xF, geometry.xF };
    intPts.yF = { geometry.yF, geometry.yF, geometry.yF, geometry.yF };

    

    if (ptLocation == INSIDE) {
        intPts.x_low  = { geometry.rA, geometry.rA, geometry.xF, geometry.xF };
        intPts.x_high = { geometry.xF, geometry.xF, geometry.rB, geometry.rB };
        intPts.y_low  = { geometry.hA, geometry.yF, geometry.yF, geometry.hA };
        intPts.y_high = { geometry.yF, geometry.hB, geometry.hB, geometry.yF };
    }
    else if (ptLocation == OUTSIDE) {
        intPts.x_low[0]  = geometry.rA;
        intPts.x_high[0] = geometry.rB;
        intPts.y_low[0]  = geometry.hA;
        intPts.y_high[0] = geometry.hB;
        intPts.len = 1;
    }
    else if (ptLocation == TOP) {
        ylim = geometry.hA + (geometry.hB - geometry.hA) * 0.9;
        intPts.x_low  = { geometry.rA, geometry.rA, geometry.xF, geometry.xF };
        intPts.x_high = { geometry.xF, geometry.xF, geometry.rB, geometry.rB };
        intPts.y_low  = { geometry.hA, ylim,        ylim,        geometry.hA };
        intPts.y_high = { ylim,        geometry.hB, geometry.hB, ylim };
    }
    else if (ptLocation == BOTTOM) {
        ylim = geometry.hA + (geometry.hB - geometry.hA) * 0.1;
        intPts.x_low  = { geometry.rA, geometry.rA, geometry.xF, geometry.xF };
        intPts.x_high = { geometry.xF, geometry.xF, geometry.rB, geometry.rB };
        intPts.y_low  = { geometry.hA, ylim,        ylim,        geometry.hA };
        intPts.y_high = { ylim,        geometry.hB, geometry.hB, ylim };
    }
    else if (ptLocation == LEFT) {
        xlim = geometry.rA + (geometry.rB - geometry.rA) * 0.1;
        intPts.x_low  = { geometry.rA, geometry.rA, xlim,        xlim };
        intPts.x_high = { xlim,        xlim,        geometry.rB, geometry.rB };
        intPts.y_low  = { geometry.hA, geometry.yF, geometry.yF, geometry.hA };
        intPts.y_high = { geometry.yF, geometry.hB, geometry.hB, geometry.yF };
    }
    else if (ptLocation == RIGHT) {
        xlim = geometry.rA + (geometry.rB - geometry.rA) * 0.9;
        intPts.x_low  = { geometry.rA, geometry.rA, xlim,        xlim };
        intPts.x_high = { xlim,        xlim,        geometry.rB, geometry.rB };
        intPts.y_low  = { geometry.hA, geometry.yF, geometry.yF, geometry.hA };
        intPts.y_high = { geometry.yF, geometry.hB, geometry.hB, geometry.yF };
    }

    return intPts;
}

std::vector<double> calculateArea(const IntPts intPts) {
    std::vector<double> area = mult(add(intPts.x_high, intPts.x_low, -1), add(intPts.y_high, intPts.y_low, -1));
    return area;
}

double calcCompleteEllipticalInt(double p1, double p2, double p3, double p4) {

    if (p1 == 0.0)
        throw "Value of p1 cant be zero!!!";
    
    bool stillRunning = true;
    double t0 = abs(p1), t1, t2, t3, t4 = t0, t5 = 1.0;

    if (p2 > 0) {
        p2 = sqrt(p2);
        p4 = p4 / p2;
    }
    else {
        t1 = t0 * t0;
        t2 = 1.0 - t1;
        t3 = 1.0 - p2;
        t1 = t1 - p2;
        t2 = t2 * (p4 - p3 * p2);
        p2 = sqrt(t1 / t3);
        p3 = (p3 - p4) / t3;
        p4 = -t2 / (t3 * t3 * p2) + p3 * p2;
    }
    
    while (stillRunning) {
        t1 = p3;
        p3 = p3 + p4 / p2;
        t3 = t4 / p2;
        p4 = p4 + t1 * t3;
        p4 = p4 + p4;
        p2 = t3 + p2;
        t3 = t5;
        t5 = t0 + t5;

        if (abs(t3 - t0) > t3 * C_A) {
            t0 = 2*sqrt(t4);
            t4 = t0 * t5;

        }
        else
            stillRunning = false;

    }

    return M_PI_H * (p4 + p3 * t5) / (t5 * (t5 + p2));
}


std::vector<double> potFunctionEn(double x, double y, double xf, double yf) {

    std::vector<double> pot = {0.0, 0.0}; 
    double coo_coef = 0.0, coo_coef_ca = 0.0, int_1 = 0.0, int_2 = 0.0;

    if (xf > 0.0) {

        coo_coef = sqrt(4 * x * xf / (pow((x + xf), 2) + pow((yf - y), 2)));
        coo_coef_ca = cos(asin(coo_coef));
        int_1 = calcCompleteEllipticalInt(coo_coef_ca, 1.0, 1.0, 1.0);
        int_2 = calcCompleteEllipticalInt(coo_coef_ca, 1.0, 1.0, pow(coo_coef_ca, 2));
        pot[0] = 4.0e-7 / coo_coef * sqrt(x / xf) * ((1.0 - 0.5 * pow(coo_coef, 2)) * int_1 - int_2);

    }

    return pot;
}

std::vector<double> potFunctionBs(double x, double y, double xf, double yf) {

    std::vector<double> pot = {0.0, 0.0};
    double z = yf - y;
    double coo_coef = 0.0, coo_coef_ca = 0.0, coo_coef_z = 0.0;
    double int_1 = 0.0, int_2 = 0.0;

    if (xf > 0.0) {

        coo_coef = sqrt(4 * x * xf / (pow((x + xf), 2) + pow((yf - y), 2)));
        coo_coef_ca = cos(asin(coo_coef));
        int_1 = calcCompleteEllipticalInt(coo_coef_ca, 1.0, 1.0, 1.0);
        int_2 = calcCompleteEllipticalInt(coo_coef_ca, 1.0, 1.0, pow(coo_coef_ca, 2));

        coo_coef_z = pow(x - xf, 2) + pow(z, 2);

        pot[0] = 1e-7 * coo_coef * z / (xf*sqrt(x*xf)) * (-int_1 + (pow(x,2)+pow(xf,2)+pow(z,2)) / coo_coef_z * int_2);
        pot[1] = 1e-7 * coo_coef / sqrt(x*xf) * (int_1 + (pow(x,2)-pow(xf,2)-pow(z,2)) / coo_coef_z * int_2);

    }
    else{
        pot[0] = 0.0;
        pot[1] = 2 * M_PI * 1e-7 / x * pow(x/sqrt(pow(x,2) + pow(z,2)),3);
    }

    return pot;
}

QuadResult gaussQuadrature(std::vector<double> potFunc(double, double, double, double),
                            IntPts intPts, const int ind, const double tolerance) {

    QuadResult quadResult;

    // change of coordinates : 
    double Xa = 0.5 * (intPts.x_high[ind] - intPts.x_low[ind]);
    double Xb = 0.5 * (intPts.x_high[ind] + intPts.x_low[ind]);
    double Ya = 0.5 * (intPts.y_high[ind] - intPts.y_low[ind]);
    double Yb = 0.5 * (intPts.y_high[ind] + intPts.y_low[ind]);

    // Define helper variables : 
    double X = 0.0, Y = 0.0, delta = 0.0; 
    double integralR = 0.0, integralZ = 0.0;
    double integral = 0.0, int_old = 0.0;

    // Assemble array with pointers to integration coeffs : 
    std::vector<double>* W[QUADPTSLEN] = {&w_3, &w_7, &w_15, &w_31, &w_63};

    // Loop and calculate function values and integrate : 
    for (int ix = 0; ix < QUADPTSLEN; ix++) {
        
        integralR = 0.0; 
        integralZ = 0.0;
        integral = 0.0;
        
        auto w = W[ix];

        for (int iy = 0; iy < nQuadPts[ix]; iy++) {

            X = Xa * xi[iy] + Xb;

            for (int iz = 0; iz < nQuadPts[ix]; iz++) {

                Y = Ya * xi[iz] + Yb;

                // calculate function values : 
                auto temp = potFunc(X, Y, intPts.xF[0], intPts.yF[0]);

                // Gauss quadrature : 
                integralR += w[0][iy] * w[0][iz] * temp[0];
                integralZ += w[0][iy] * w[0][iz] * temp[1];
                
            }
        }

        integralR *= Xa * Ya;
        integralZ *= Xa * Ya;
        
        integral = sqrt(pow(integralR, 2) + pow(integralZ, 2));

        if (ix == 0) {
            int_old = integral;
        }
        else {

            if (integral != 0.0) {
                delta = abs((integral - int_old) / integral);
            }
            else {
                delta = integral;
            }

            if (delta < tolerance) {
             
                quadResult.convergence = CONVERGED;
                quadResult.result = integral;
                quadResult.resR = integralR;
                quadResult.resZ = integralZ;

                return quadResult;
            }
            else {
                quadResult.convergence = NOT_CONVERGED;
                quadResult.result = integral;
                quadResult.resR = integralR;
                quadResult.resZ = integralZ;
            }
        }
        
    }
    return quadResult;
}

double integratePoints(const IntPts intPts, const double currDens, const double tolerance) {

    double result = 0.0;

    std::vector<double> areas = calculateArea(intPts);
    for (int ix = 0; ix < intPts.len; ix++) {
        if (areas[ix] > 0.0) {
            auto tempQuad = gaussQuadrature(potFunctionEn, intPts, ix, tolerance);
            result += tempQuad.result;
        }
    }
    return result * currDens;
}

std::vector<double> integratePointsBStray(const IntPts intPts, const double currDens, const double tolerance) {

    std::vector<double> result = {0.0, 0.0};

    std::vector<double> areas = calculateArea(intPts);
    for (int ix = 0; ix < intPts.len; ix++) {
        if (areas[ix] > 0.0) {
            auto tempQuad = gaussQuadrature(potFunctionBs, intPts, ix, tolerance);
            
            result[0] += tempQuad.resR;
            result[1] += tempQuad.resZ;
            
        }
    }

    result[0] = result[0]*currDens;
    result[1] = result[1]*currDens;

    return result;
}


double integrateCoilEnergy(const std::vector<double> geometry, const double currDens, const double xF, const double yF) {
    
    // Decalare helper geometry variables : 
    // possible optimization : move out of function to not be calculated every time!
    Geometry coilGeom;
    coilGeom.rA = geometry[0] - 0.5 * geometry[2];
    coilGeom.rB = geometry[0] + 0.5 * geometry[2];
    coilGeom.hA = -geometry[1];
    coilGeom.hB =  geometry[1];
    coilGeom.xF = xF;
    coilGeom.yF = yF;

    // Tolerance value : 
    const double tolerance = 50e-3;

    auto ptLocation = checkPointLocation(coilGeom);
    auto intPts = getIntegrationPoints(ptLocation, coilGeom);

    auto result = integratePoints(intPts, currDens, tolerance);

    return result;

}

double calculatePartialEnergy(const std::vector<double> geometry1, const std::vector<double> geometry2,
                       const double currDens1, const double currDens2) {

    /*                       0             1               2
    *       geometry1 = { radius 1, half height 1, radial thickness 1 }
            geometry2 = { radius 2, half height 2, radial thickness 2 }
            currDens1 = current density solenoid 1
            currDens2 = current density solenoid 2
    
    */
    
    // Declare and initialize integration variables : 
    double energy = 0.0;
    const int nPoints = w_3.size();

    double xF = 0.0;
    double yF = 0.0;

    double partialEnergy = 0.0;

    double half_width_1  = geometry1[2] * 0.5;
    double half_height_1 = geometry1[1];
    double radius_1      = geometry1[0];
    
    for (int ix = 0; ix < nPoints; ix++) {
        
        xF = half_width_1 * xi[ix] + radius_1;

        for (int iy = 0; iy < nPoints; iy++) {
            
            yF = half_height_1 * xi[iy]; // no addition as center is at 0

            double energy1 = integrateCoilEnergy(geometry1, currDens1, xF, yF);
            double energy2 = integrateCoilEnergy(geometry2, currDens2, xF, yF);

            energy += w_3[ix] * w_3[iy] * xF * (energy1 + energy2);

        }
    }

    partialEnergy = energy * currDens1 * M_PI * half_height_1 * half_width_1;

    return partialEnergy;

}

/*
calculateEnergy function : 
*/
double calculateEnergy(const std::vector<double> geometrySol1, const std::vector<double> geometrySol2, 
                       const double currDensSol1, const double  currDensSol2){
    
    double energy1 = calculatePartialEnergy(geometrySol1, geometrySol2, currDensSol1, currDensSol2);
    double energy2 = calculatePartialEnergy(geometrySol2, geometrySol1, currDensSol2, currDensSol1);

    return energy1 + energy2;
}

std::vector<double> calculatePartialStrayField(const std::vector<double> geometry,
                                             const double currDensSol1,
                                             double xF, double yF){

    // Decalare helper geometry variables : 
    // possible optimization : move out of function to not be calculated every time!
    Geometry coilGeom;
    coilGeom.rA = geometry[0] - 0.5 * geometry[2];
    coilGeom.rB = geometry[0] + 0.5 * geometry[2];
    coilGeom.hA = -geometry[1];
    coilGeom.hB =  geometry[1];
    coilGeom.xF = xF;
    coilGeom.yF = yF;

    // Tolerance value : 
    const double tolerance = 1e-3;

    auto ptLocation = checkPointLocation(coilGeom);
    auto intPts = getIntegrationPoints(ptLocation, coilGeom);

    auto Bstray = integratePointsBStray(intPts, currDensSol1, tolerance);

    return Bstray;

}

std::vector<double> calculateStrayField(const std::vector<double> geometrySol1, 
                                      const std::vector<double> geometrySol2, 
                                      const double currDensSol1, const double  currDensSol2){

    double slope = X_MAX/(N_PTS - 1);
    double Babs = 0.0, BabsSq = 0.0;

    for(int ix = 0; ix < N_PTS; ix++){
        
        double xF = ix * slope;
        double yF = Y_MAX;

        auto Bstray1 = calculatePartialStrayField(geometrySol1, currDensSol1, xF, yF);
        auto Bstray2 = calculatePartialStrayField(geometrySol2, currDensSol2, xF, yF);
        
        auto Bstray = add(Bstray1, Bstray2, 1);

        BabsSq += pow(Bstray[0], 2) + pow(Bstray[1], 2);
        Babs += sqrt(pow(Bstray[0], 2) + pow(Bstray[1], 2));

    }

    slope = -Y_MAX/(N_PTS - 1);

    for(int ix = 0; ix < N_PTS; ix++){
        
        double xF = X_MAX;
        double yF = Y_MAX + slope*ix;

        auto Bstray1 = calculatePartialStrayField(geometrySol1, currDensSol1, xF, yF);
        auto Bstray2 = calculatePartialStrayField(geometrySol2, currDensSol2, xF, yF);
        
        auto Bstray = add(Bstray1, Bstray2, 1);

        BabsSq += pow(Bstray[0], 2) + pow(Bstray[1], 2);
        Babs += sqrt(pow(Bstray[0], 2) + pow(Bstray[1], 2));

    }

    std::vector<double> vecBstray = {Babs/(2*N_PTS), BabsSq/(2*N_PTS)};
    
    return vecBstray;
}


std::vector<double> calculateMaxField(const std::vector<double> geometrySol1, 
                                    const std::vector<double> geometrySol2, 
                                    const double currDensSol1, const double  currDensSol2){
    
    const int nRows = 3;

    std::vector<double> Bmax = {0.0, 0.0};

    // Tolerance value : 
    const double tolerance = 1e-3;

    Geometry coilGeom1;
    coilGeom1.rA = geometrySol1[0] - 0.5 * geometrySol1[2];
    coilGeom1.rB = geometrySol1[0] + 0.5 * geometrySol1[2];
    coilGeom1.hA = -geometrySol1[1];
    coilGeom1.hB =  geometrySol1[1];

    Geometry coilGeom2;
    coilGeom2.rA = geometrySol2[0] - 0.5 * geometrySol2[2];
    coilGeom2.rB = geometrySol2[0] + 0.5 * geometrySol2[2];
    coilGeom2.hA = -geometrySol2[1];
    coilGeom2.hB =  geometrySol2[1];
    
    // Determine values of field at inner coil : 
    std::vector<double> xP = {coilGeom1.rA, coilGeom1.rB,                 coilGeom1.rB};
    std::vector<double> yP = {0.0,         (coilGeom1.hB-coilGeom1.hA)/4, 0.0};

    // std::vector<double> Bp = arma::zeros(3,2);

    for(int ix = 0; ix < nRows; ix++){

        coilGeom1.xF = xP[ix];
        coilGeom1.yF = yP[ix];

        coilGeom2.xF = xP[ix];
        coilGeom2.yF = yP[ix];

        auto ptLocation1 = checkPointLocation(coilGeom1);
        auto intPts1 = getIntegrationPoints(ptLocation1, coilGeom1);
        auto B1temp = integratePointsBStray(intPts1, currDensSol1, tolerance);

        auto ptLocation2 = checkPointLocation(coilGeom2);
        auto intPts2 = getIntegrationPoints(ptLocation2, coilGeom2);
        auto B2temp = integratePointsBStray(intPts2, currDensSol2, tolerance);

        auto BmaxTemp = sqrt(pow(B1temp[0] + B2temp[0],2) + pow(B1temp[1] + B2temp[1],2));
        
        if(BmaxTemp > Bmax[0]){
            Bmax[0] = BmaxTemp;
        }

    }

    // Determine max value of outer coil : 

    coilGeom1.xF = coilGeom2.rA;
    coilGeom1.yF = 0;

    coilGeom2.xF = coilGeom2.rA;
    coilGeom2.yF = 0;

    auto ptLocation1 = checkPointLocation(coilGeom1);
    auto intPts1 = getIntegrationPoints(ptLocation1, coilGeom1);
    auto B1temp = integratePointsBStray(intPts1, currDensSol1, tolerance);

    auto ptLocation2 = checkPointLocation(coilGeom2);
    auto intPts2 = getIntegrationPoints(ptLocation2, coilGeom2);
    auto B2temp = integratePointsBStray(intPts2, currDensSol2, tolerance);

    auto Btemp = add(B1temp, B2temp, 1);

    Bmax[1] = sqrt(pow(Btemp[0],2) + pow(Btemp[1],2));

    return Bmax;
 
}

void solve(double *prms, double *results) {
	/*
	* Function for calculating the energy, stray field and max field values.
	* 
    * 
	* GEOMETRIC PARAMETERS:
            XDOF(0)=R1 RADIUS OF THE CENTER OF SOL. 1
            XDOF(1)=R2 RADIUS OF THE CENTER OF SOL. 2
            XDOF(2)=H1 HALF HEIGHT SOL. 1
            XDOF(3)=H2 HALF HEIGHT SOL. 2
            XDOF(4)=D1 RADIAL THICKNESS SOL. 1
            XDOF(5)=D2 RADIAL THICKNESS SOL. 2
        
      ELECTRICAL PARAMETERS:
            XDOF(6)=CURD1 CURRENT DENSITY SOL. 1
            XDOF(7)=CURD2 CURRENT DENSITY SOL. 2

      ARE CONVERTED TO : 

            geometrySol1 = { radius 1, half height 1, radial thickness 1 }
            geometrySol2 = { radius 2, half height 2, radial thickness 2 }
            currDensSol1 = current density solenoid 1
            currDensSol2 = current density solenoid 2

                       
      NOTE: CURD1 t4 CURD2 SHOULD HAVE Op2OSITE SIGN AS MAXIMUM 
            MAY FALL IN ANOTHER AREA.
	*/

    // Check if passed array is 8x1 : 
    // assert(prms.size() == INPUT_LEN);

    // Extract input parameters into new variables :
    const std::vector<double> geometrySol1 = { prms[0],prms[2],prms[4] };
    const std::vector<double> geometrySol2 = { prms[1],prms[3],prms[5] };

    const double currDensSol1 = prms[6];
    const double currDensSol2 = prms[7];

    auto energy = calculateEnergy(geometrySol1, geometrySol2, currDensSol1, currDensSol2);
    auto Bstray = calculateStrayField(geometrySol1, geometrySol2, currDensSol1, currDensSol2);
    auto Bmax = calculateMaxField(geometrySol1, geometrySol2, currDensSol1, currDensSol2);

    results[0] = energy;
    results[1] = Bstray[0];
    results[2] = Bstray[1];
    results[3] = Bmax[0];
    results[4] = Bmax[1];

}