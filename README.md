CPP Starter Kit
===============

A simple C++ starter Makefile project.

File Directory Structure
------------------------

The make file expects the follow folder structure.

- src/common/*
- src/mains/*
- src/test/*

The Makefile will compile source files into obj/ directory with the same directory structure. Binaries are placed in the bin/ directory.

Make Targets
------------

 - new (Default, compile new objects and link.)
 - fresh (clean, new)
 - clean (Removes the obj/ and bin/ directories as well as any other output files.)
 - vars (Echo variables for debug.)
 - test (Compiles the unit tests and then runs with --xml flag for xml output.)
 - cppcheck (Runs cppcheck and outputs to xml.)
 - ci (fresh, test, cppcheck)


