> Any sufficiently complicated C or Fortran program contains an ad-hoc, informally-specified, bug-ridden, slow implementation
> of half of Common Lisp. - Philip Greenspun

# SoftLisp
A simple embeddable lisp interpreter written in C++. 
This is a for-study project, and will be used to provide scripting to SoftTracer.

## Features
Currently SoftLisp is under development.

## Getting Started
This project is being developed directly on Windows 10. I am trying to avoid platform dependent code, but since I am using
Visual Studio 2017 CE and running on Windows 10, and not yet testing it in other environments, some windows-isms might slip.

In order to compile the project, you need:
- a binary distribution of Boost (for Boost::Parameters) in C:\SDL\local\boost_1_64_0

Building requirements will change as soon as I am able to tackle the multi-platform requirements (sorry).

## What are you currently working on?
- Making a set of unit-tests for development and non-regression testing

## What is your future work?
- 1) a lisp interpreter
- 2) make it so that any program can register functions, classes or variables to be accessed via Lisp
- 3) start using this on softtracer for scripting: http://github.com/limacat76/SoftTracer
- 4) when I can get a Linux machine I want to make both this project and softtracer buildable on linux+gcc, maybe via CMake

Other common-lisp/scheme/whatever features that will be implemented may vary

## Need help?
You can contact me at limacat@gmail.com or via anonymous message at https://softtracer.sarahah.com/

11.08.2017