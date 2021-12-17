cimport cppbisol

cimport numpy as np
import numpy as np

N_PARAMS = 8
N_RES_PARAMS = 5

cdef cppsolve(params):

    if len(params.shape) == 1 and len(params) == N_PARAMS:
        params = params[None,:]
    elif len(params.shape) == 1 and params.shape[0] != N_PARAMS:
        raise AssertionError(f"Max number of params for sample is {N_PARAMS}")
    elif len(params.shape) == 2 and params.shape[1] != N_PARAMS:
        raise AssertionError(f"Max number of params for sample is {N_PARAMS}")
    elif len(params.shape) > 2:
        raise AssertionError("Only 2-D arrays acceptable")
    
    cdef int n_samples = params.shape[0]

    cdef np.float64_t[:,:] arr1 = np.ascontiguousarray(params, dtype=np.float64)
    cdef np.float64_t[:,:] arr2 = np.ascontiguousarray(np.zeros((n_samples, N_RES_PARAMS), 
                                                       dtype=np.float64), dtype=np.float64)
    
    for ind in range(n_samples):
        cppbisol.solve(&arr1[ind][0], &arr2[ind][0])

    return np.asarray(arr2, dtype=np.float64)

def solve(params: np.ndarray) -> np.ndarray:
    return cppsolve(params)