from setuptools import Extension, setup
from Cython.Build import cythonize
import numpy

__version__ = "1.0"

setup(
    name="pybisol",
    version=__version__,
    author="Eniz Museljic",
    author_email="eniz.m@outlook.com",
    description="Python wrapper module for a c++ implementation of superconducting coil field solver.",
    ext_modules = cythonize([Extension("pybisol", ["pybisol.pyx"])]),
    include_dirs = [numpy.get_include()],
    install_requires=["numpy", "cython"],
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ], 
    python_requires='>=3.7',
    zip_safe=False
)