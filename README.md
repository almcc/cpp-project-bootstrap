CPP Starter Kit (1.0.0)
=======================

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

License
-------

The MIT License (MIT)

Copyright (c) 2013 Alastair McClelland

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
