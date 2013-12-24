#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static const double  PI=3.14159265359;

double* globalargs; //Array to store function parameters (x1,...,xn)
double (*globalf)(int, double *); //Pointer to function of array
int globalnargs; //Int to store number of elements in globargs.  I'm not totally sure this is necessary.

int init(double (*f)(int, double *), int n, double args[n]){
  //Initialize
  //Returns 1 on failure 
  //Returns 0 on success
  
  globalnargs = n;
  globalf = f;
  //globalargs = malloc(sizeof(double)*n); //I'm real unsure about mallocing here
  globalargs = args;

  if (&globalnargs == NULL || &globalf == NULL || &globalnargs == NULL)
    return 1;
  else
    return 0;
}

double call(double* x){ // Evaluates user defined function as function of one variable.
  //We want to create a new array with [x0, concatenated with [x1, . . . , xn]]
  double (*f)(int, double *) = globalf;
  double evalArray[globalnargs+1];
  int i = 1;
  evalArray[0] = *x;
  //  printf("%f\n", evalArray[0]);

  for(i; i < globalnargs + 1 ; i++){
    evalArray[i] = globalargs[i-1]; //Add everything from globalargs to end of evalArray
    //  printf("%f\n", evalArray[i]);
  }
  //printf("Test: %f\n", f(globalnargs, evalArray));
  return  f(globalnargs, evalArray);
}

double dqag2(double (*f)(int, double *), int nargs, double args[nargs], double a, double b,
       double epsabs, double epsrel,int key, double result, double abserr, int neval, int ier,
       int limit, int lenw, int last, int iwork[limit], double work[lenw]){//User called function

  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqag_(call,&a,&b,&epsabs,&epsrel,&key,&result,&abserr,&neval,&ier,&limit,&lenw,&last,&iwork,&work);
  return result;
}


double dqagi2(double (*f)(int, double *), int nargs, double args[nargs], double bound, int inf,
       double epsabs, double epsrel, double result, double abserr, int neval, int ier,
       int limit, int lenw, int last, int iwork[limit], double work[lenw]){//User called function
//      SUBROUTINE DQAGI (F, BOUND, INF, EPSABS, EPSREL, RESULT, ABSERR,
//      +   NEVAL, IER, LIMIT, LENW, LAST, IWORK, WORK)
 
  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqagi_(call,&bound,&inf,&epsabs,&epsrel,&result,&abserr,&neval,&ier,&limit,&lenw,&last,&iwork,&work);
  return result;
}

double dqagie2(double (*f)(int, double *), int nargs, double args[nargs], double* bound, int* inf, 
	       double* epsabs, double* epsrel, int* limit,double* result, double* abserr, int* neval, 
	       int* ier, double alist[*limit], double blist[*limit], double rlist[*limit], double elist[*limit], 
	       int iord[*limit], int* last){
  if(init(f,nargs,args)){//Error                                                                                                            
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqagie_(call, bound, inf, epsabs, epsrel, limit, result, abserr, neval, ier, alist, blist, rlist, elist, iord, last);

  return *result;

}

double dqags2(double (*f)(int, double *), int nargs, double args[nargs], double a, double b,
       double epsabs, double epsrel, double result, double abserr, int neval, int ier,
       int limit, int lenw, int last, int iwork[limit], double work[lenw]){//User called function

  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqags_(call,&a,&b,&epsabs,&epsrel,&result,&abserr,&neval,&ier,&limit,&lenw,&last,&iwork,&work);
  return result;
}

double dqagse2(double (*f)(int, double *), int nargs, double args[nargs], double* a, double* b, double* epsabs, double* epsrel, int* limit, double* result, double* abserr, int* neval, int* ier, double alist[*limit], double blist[*limit], double rlist[*limit], double elist[*limit], int iord[*limit], int* last){
  if(init(f,nargs,args)){//Error                                         
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqagse_(call, a, b, epsabs, epsrel, limit, result, abserr, neval, ier, alist, blist, rlist, elist, iord, last);
 
  return *result;

}

double dqng2(double (*f)(int, double *), int nargs, double args[nargs], double a, double b, 
        double epsabs, double epsrel, double result, double abserr, int neval, int ier){
  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqng_(call,&a,&b,&epsabs,&epsrel,&result,&abserr,&neval,&ier);
  return result;

}

double dqawo2(double (*f)(int, double *), int nargs, double args[nargs], double a, double b,
        double omega, int integr, double epsabs, double epsrel, double result, double abserr,
        int neval, int ier, int leniw, int maxp1, int lenw, int last, int iwork[leniw],
        double work[lenw]){
  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqawo_(call, &a, &b, &omega, &integr, &epsabs, &epsrel, &result, &abserr, &neval, &ier, 
        &leniw, &maxp1, &lenw, &last, &iwork, &work);
  return result;

}


double dqawoe2(double (*f)(int, double *), int nargs, double args[nargs], double* a, double* b, double* omega, int* integr, double* epsabs, double* epsrel, int* limit, int* icall, int* maxp1, double* result, double* abserr, int* neval, int* ier, int* last, double alist[*limit], double blist[*limit], double rlist[*limit], double elist[*limit], int iord[*limit], int nnlog[*limit], int* momcom, double chebmo[*maxp1][25] ){  
  if(init(f,nargs,args)){//Error                                                               
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqawoe_(call, a, b, omega, integr, epsabs, epsrel, limit, icall, maxp1, result, abserr, neval, ier, last, alist, blist, rlist, elist, iord, nnlog, momcom, chebmo);

 return *result;

}

double dqagp2(double (*f)(int, double *), int nargs, double args[nargs], double a, double b, 
       int npts2, double points[npts2], double epsabs, double epsrel, double result,
       double abserr, int neval, int ier, int leniw,int lenw, int last, 
       int iwork[leniw], double work[lenw]){

  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqagp_(call,&a,&b,&npts2,&points,&epsabs,&epsrel,&result,&abserr,&neval,&ier,&leniw,&lenw,&last,&iwork,&work);
 
  return result;
}

double dqagpe2(double (*f)(int, double *), int nargs, double args[nargs], double* a, double* b, int* npts2, double points[*npts2], double* epsabs, double* epsrel, int* limit,double* result, double* abserr, int* neval, int* ier, double alist[*limit], double blist[*limit], double rlist[*limit], double elist[*limit], double pts[*npts2], int iord[*limit], int level[*limit], int ndin[*limit], int* last){//ordering in documentation is confusing.... Check this.
  if(init(f,nargs,args)){//Error                                                                                                            
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqagpe_(call, a, b, npts2, points, epsabs, epsrel, limit, result, abserr, neval, ier, alist, blist, rlist, elist, pts, iord, level, ndin, last);

  return *result;

}

double dqawc2(double (*f)(int, double *), int nargs, double args[nargs], double a, double b,
	      double c, double epsabs, double epsrel, double result, double abserr,
	      int neval, int ier, int limit, int lenw, int last, int iwork[limit], double work[lenw]){
  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }

  dqawc_(call,&a,&b,&c,&epsabs,&epsrel,&result,&abserr,&neval,&ier,&limit,&lenw,&last,&iwork,&work);
    
  return result; 
}

double dqawce2(double (*f)(int, double *), int nargs, double args[nargs], double* a, double* b, double* c, double* epsabs, double* epsrel, int* limit, double* result, double* abserr, int* neval, int* ier, double alist[*limit], double blist[*limit],double rlist[*limit], double elist[*limit], int iord[*limit], int* last){
  if(init(f,nargs,args)){//Error   
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }
  
  dqawce_(call, a, b, c, epsabs, epsrel, limit, result, abserr, neval, ier, alist, blist, rlist, elist, iord, last);
  
  return *result;

}

double dqawf2(double (*f)(int, double *), int nargs, double args[nargs], double a, double omega,
	      int integr, double epsabs, double result, double abserr, int neval, int ier, 
	      int limlst, int lst, int leniw, int maxp1, int lenw, int iwork[leniw], 
	      double work[lenw]){
  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }
  
  dqawf_(call,&a,&omega,&integr,&epsabs,&result,&abserr,&neval,&ier,&limlst,&lst,&leniw,&maxp1,
	 &lenw,&iwork,&work);
  
  return result;

}

double dqawfe2(double (*f)(int, double *), int nargs, double args[nargs], double* a, double* omega, int* integr, double* epsabs, int* limlst, int* limit, int* maxp1, double* result, double* abserr, int* neval, int* ier, double rslst[*limlst], double erlst[*limlst], int ierlst[*limlst], int* lst, double alist[*limit], double blist[*limit], double rlist[*limit], double elist[*limit], int iord[*limit], int nnlog[*limit], double chebmo[*maxp1][25] ){
  if(init(f,nargs,args)){//Error                                                                                                            
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }
  
  dqawfe_(call, a, omega, integr, epsabs, limlst, limit, maxp1, result, abserr, neval, ier, rslst, erlst, ierlst, lst, alist, blist, rlist, elist, iord, nnlog, chebmo);
  
  return *result;

}

double dqaws2(double (*f)(int, double *), int nargs, double args[nargs], double a, double b,
	      double alfa, double beta, int integr, double epsabs, double epsrel, double result,
	      double abserr, int neval, int ier, int limit, int lenw, int last, int iwork[limit],
	      double work[lenw]){
  if(init(f,nargs,args)){//Error
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }
  
  dqaws_(call, &a, &b, &alfa, &beta, &integr, &epsabs, &epsrel,
	 &result, &abserr, &neval, &ier, &limit, &lenw, &last, &iwork, &work);
  
  return result;

}

double dqawse2(double (*f)(int, double *), int nargs, double args[nargs], double* a, double* b, double* alfa, double* beta, int* integr, double* epsabs, double* epsrel, int* limit, double* result, double* abserr, int* neval, int* ier, double alist[*limit], double blist[*limit], double rlist[*limit], double elist[*limit], int iord[*limit], int* last){
  if(init(f,nargs,args)){//Error	      
    
    printf("%s\n", "Initialization did not complete correctly.");
    exit(1);
  }
  
  dqawse_(call, a, b, alfa, beta, integr, epsabs, epsrel, limit, result, abserr, neval, ier, alist, blist, rlist,elist, iord, last);
  
  return *result;
  
}

//I need to write all the e versions of these routines.
