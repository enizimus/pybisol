import numpy as np
import pybisol

# Calling for one set of parameters :
# In this case the optimal parameters.
params = np.array([1.296, 1.8, 1.089, 1.513, 0.583, 0.195, 16.695e6, -18.91e6], 
                  dtype=np.float64)

result = pybisol.solve(params)
print(result)

# Calling the solver for 10 different parameter configurations :
params = np.random.rand(10, 8)

result = pybisol.solve(params)