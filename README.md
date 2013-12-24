Cwrapping
=========

Wrapping SLATEC's quadpack library for use in Scipy

Right now I'm compiling this on linux with:
   gcc testQuad.c -L. -lslatecfull -lgfortran
where libslatecfull.a is the slatec fortran library in the same directory as the other two files.
