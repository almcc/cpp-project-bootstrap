CPP Starter Kit
===============

A simple C++ starter Makefile project for CentOS 6.

Sections
--------

- documentation/sphinx/ (User manual documentation)
- documentation/doxygen/ (Code reference documentation)
- puppet/ (Puppet module to install required packages)
- rpmbuild/ (RPM Build files)
- source/ (C++ Sources and Unit Tests)

Source Directory Structure
------------------------

The make file expects the follow folder structure. The ```source/Makefile``` make file is responsible for making the code. 

- src/common/*
- src/mains/*
- src/test/*

The Makefile will compile source files into obj/ directory with the same directory structure. Binaries are placed in the bin/ directory.

Make Targets
------------

 - Makefile
   - release (Build a whole release and place in release/)
   - clean (Clean everything)
 - source/Makefile
   - new (Default, compile new objects and link.)
   - fresh (clean, new)
   - clean (Removes the obj/ and bin/ directories as well as any other output files.)
   - cppunit(-xml|-txt) (Compiles the unit tests and then runs with --xml flag for xml output.)
   - cppcheck(-xml|-txt) (Runs cppcheck and outputs to xml.)
   - ci(-xml|-txt) (fresh, cppunit, cppcheck)
 - documentation/Makefile
   - docs (Build all the docs)
   - sphinx
   - doxygen
 - rpmbuild/Makefile
   - rpms (Build the rpms)

Versioning
----------

Each Makefile has a local default versioning varaibles that default to app-X.X.X-devX, for building a versioned release use build.py to set the varaibles in the parent Makefile that will then pass these varables down to each makefile in turn. 

License
-------

The MIT License (MIT)

Copyright (c) 2013 Alastair McClelland

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
