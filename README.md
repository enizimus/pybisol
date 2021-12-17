# Pybisol : 
This is a python wrapper package of a C++ implementation of a superconducting concentric coil system solver. The solver is using the biot savart law to calculate the main magnetic field, the stray field and then the energy from it. 

## **pybisol** installation instructions :

- Package can be built by running : 
```
$ python setup.py build_ext -i
``` 
- Now the *.so* or *.pyd* (on windows) is used to import the *bisol* module from.

- Package can also be installed by running : 
```bash
$ python setup.py install
```
- This way it will be made available in the current environment everywhere.

## Usage instructions : 

Usage examples can be found in the examples directory. The package provides a simple `solve()` function which accepts an array containing the simulation parameters : 
- $R_1$ and $R_2$ in $m$ ... radial distance of the center of the first and second coil from the system center.
- $h_1$ and $h_2$ in $m$ ... half height of the first and second coil respectively.
- $d_1$ and $d_2$ in $m$ ... thickness of the first and second coil respectively.
- $J_1$ and $J_2$ in $A/mm^2$ ... current density of the first and second coil respectively.
  
The vector is then constructed from these as : 

$$\boldsymbol{x} = [R_1, R_2, h_1, h_2, d_1, d_2, J_1, J_2]^T$$

The function can be invoked by running : 

```python
y = pybisol.solve(x)
```

Where y is again a vector with : 

$$\boldsymbol{y} = [E, Bs_1, Bs_2, Bmax_1, Bmax_2]$$

with : 

- $E$ ... total energy stored in the system.
- $Bs_1$ and $Bs_2$ ... stray field for solenoid 1 and 2.
- $Bmax_1$ and $Bmax_2$ ... maximal field for solenoid 1 and 2.

