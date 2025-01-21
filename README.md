# Pybisol : 
This is a python wrapper package of a C++ implementation of a superconducting concentric coil system solver. The solver is using the biot savart law to calculate the main magnetic field, the stray field and then the energy from it. 

## **pybisol** installation instructions :

Please make sure that you are using anaconda python and not your system python as it is only tested and verified with anaconda python. 

First set up a new environment by opening your console and running : 
```bash
conda create --name optienv python
```
Activate the environment with :
```bash
conda activate optienv
``` 
Then you need to install the dependencies by running : 
```python
python -m pip install -r requirements.txt
```
After this you can install the library in 
```bash
$ python -m pip install .
```
This will install the library in the current environment.

If you are using vscode to debug or run your code please make sure that you have selected the correct environment (that is `optienv`). This can be done by pressing `ctrl+shift+P` and searching for *Python: Select Interpreter*, there you need to select `optienv` for your environment.

To make sure that everything is installed correctly, navigate to the `exmples/` directory and execute the `example.py` file. It should run and print and output if everything is ok.

## Usage instructions : 

Usage examples can be found in the examples directory. The package provides a simple `solve()` function which accepts an array containing the simulation parameters : 
- `R_1` and `R_2` in `m` ... radial distance of the center of the first and second coil from the system center.
- `h_1` and `h_2` in `m` ... half height of the first and second coil respectively.
- `d_1` and `d_2` in `m` ... thickness of the first and second coil respectively.
- `J_1` and `J_2` in `A/mm^2` ... current density of the first and second coil respectively.
  
The vector is then constructed from these as : 
```math
x = [R_1, R_2, h_1, h_2, d_1, d_2, J_1, J_2]
```

The function can be invoked by running : 

```python
y = pybisol.solve(x)
```

Where y is again a vector with : 

```math
y = [E, Bs_1, Bs_2, Bmax_1, Bmax_2]
```

with : 

- `E` in `J` ... total energy stored in the system.
- `Bs_1` in `T` ... is the sum of the absolute values of the stray field in the computation points divided by the numer of points.
- `Bs_2` in `T^2` ... is the sum of the squares of the stray field in the computation points divided by the number of points.
- `Bmax_1` and `Bmax_2` in `T` ... maximal field for solenoid 1 and 2.

