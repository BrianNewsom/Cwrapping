Cwrapping
=========

Wrapping SLATEC's quadpack library for use in Scipy

Right now I'm compiling this on linux with:
   gcc testQuad.c -L. -lslatecfull -lgfortran
where libslatecfull.a is the slatec fortran library in the same directory as the other two files.


KNOWN ISSUES:
   1.) Small numerical error on test_indefinite
      -Source unknown
   2.) I'm not sure how to complete the integration of test_cosine_weighted_infinite, as the work done in python            isn't easily converted to c.
   
