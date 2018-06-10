#include <stdio.h>

int main() {

    float arg1, arg2, add, sub, mul, div ;

    printf( "Enter two numbers : " );
    scanf( "%f%f", &arg1, &arg2 );

    /* Perform floating point Addition, Subtraction, Multiplication & Division */
    __asm__ ( "flds %1;"
              "flds %2;"
              "fadd;"
              "fstps %0;" : "=g" (add) : "g" (arg1), "g" (arg2) ) ;

    __asm__ ( "flds %2;"
              "flds %1;"
              "fsub;"
              "fstps %0;" : "=g" (sub) : "g" (arg1), "g" (arg2) ) ;

    __asm__ ( "flds %1;"
              "flds %2;"
              "fmul;"
              "fstps %0;" : "=g" (mul) : "g" (arg1), "g" (arg2) ) ;

    __asm__ ( "flds %2;"
              "flds %1;"
              "fdiv;"
              "fstps %0;" : "=g" (div) : "g" (arg1), "g" (arg2) ) ;

    printf( "%f + %f = %f\n", arg1, arg2, add );
    printf( "%f - %f = %f\n", arg1, arg2, sub );
    printf( "%f * %f = %f\n", arg1, arg2, mul );
    printf( "%f / %f = %f\n", arg1, arg2, div );

    return 0 ;
}
