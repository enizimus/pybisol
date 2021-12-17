# distutils: language = c++

cimport numpy as np

cdef extern from "bisol.cpp":
    pass

cdef extern from "bisol.hpp":
    void solve(np.float64_t *params, np.float64_t *result)