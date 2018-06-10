#include <stdio.h>
#include <math.h>


#define PI 3.14159265

int altitud1 (add,alt,altura, totaltime,tiempo, gravedad,division,dos,velocidad,quo,rem){

	int result;

	__asm__ __volatile__ ( "imull %%ebx, %%eax;" : "=a" (totaltime) : "a" (tiempo) , "b" (tiempo));

	__asm__ __volatile__ ( "imull %%ebx, %%eax;" : "=a" (totaltime) : "a" (totaltime) , "b" (gravedad));

	  __asm__ ( "movl $0x0, %%edx;"
              "movl %2, %%eax;"
              "movl %3, %%ebx;"
               "idivl %%ebx;" : "=a" (quo), "=d" (rem) : "g" (totaltime), "g" (dos));

	__asm__ __volatile__ ( "addl %%ebx, %%eax;" : "=a" (alt) : "a" (altura) , "b" (velocidad));

    __asm__ __volatile__ ( "addl %%ebx, %%eax;" : "=a" (add) : "a" (alt) , "b" (quo));

	return result=add;

}


int altitud2 (sub,alt,altura, totaltime,tiempo, gravedad,division,dos,velocidad,quo,rem){

    int result;

    __asm__ __volatile__ ( "imull %%ebx, %%eax;" : "=a" (totaltime) : "a" (tiempo) , "b" (tiempo));

    __asm__ __volatile__ ( "imull %%ebx, %%eax;" : "=a" (totaltime) : "a" (totaltime) , "b" (gravedad));

      __asm__ ( "movl $0x0, %%edx;"
              "movl %2, %%eax;"
              "movl %3, %%ebx;"
               "idivl %%ebx;" : "=a" (quo), "=d" (rem) : "g" (totaltime), "g" (dos));

    __asm__ __volatile__ ( "subl %%ebx, %%eax;" : "=a" (alt) : "a" (altura) , "b" (velocidad));

    __asm__ __volatile__ ( "addl %%ebx, %%eax;" : "=a" (sub) : "a" (alt) , "b" (quo));

    return result=sub;

}

int deltaTime (sub,tiempo,segundo){

	int result;

	__asm__ __volatile__ (

    "addl %%ebx, %%eax;" : "=a" (sub) : "a" (tiempo) , "b" (segundo)

		);
	return result=sub;
}


int copyDeltaTime (sub,copyTime,segundo){

    int result;

    __asm__ __volatile__ (

    "subl %%ebx, %%eax;" : "=a" (sub) : "a" (copyTime) , "b" (segundo)

        );
    return result=sub;
}

float sacarAngulo (ang,seno,rad){

	float result;

    __asm__ __volatile__ ( "addl %%ebx, %%eax;" : "=a" (ang) : "a" (seno) , "b" (rad));

	return result=ang;

}



int main() {

    // AVION McDonnell Douglas C-9B Skytrain II

    // Ciudad: Las Vegas

		float potencia = 50;
    float gasolina = 200000;
		float tempertaruta= 36;
		float divVaria=100;
		float temp=-11.546825;
		float variaTem=0.65;
		float consumo = 4.277;
		float vel=9.7536;
		float decimal= 0.01;
		float tiempoHora=0.1;
		float gravedad=9.8;
		float rad    = 0.18479956785;
		float angulo=-(PI/2);
		float altura=24000;
		float  val = 180.0 / PI;
		float dmul,dgas,division,ret ,ang,div, consumoPorSegundo, consumoTotal, gas, velocidad, seno;

    int arg1, arg2, add, sub, mul, quo, rem,totaltime,alt;
    int dos=2;
    int segundo=1;
    int tiempo= 0;
    int copyTime=38;
    int band=1;



    	do {

				  system("clear");


    	printf("----------------\n" );

    	printf("----------------\n" );

    	tiempo= deltaTime(sub,tiempo,segundo);

        ret = cos(angulo)* val;


        printf("Angulo de la nariz del avion: %fº\n",ret );

				__asm__ ( "flds %1;"
									"flds %2;"
									"fmul;"
									"fstps %0;" : "=g" (velocidad) : "g" (vel), "g" (ret) ) ;

        printf("Velocidad en Y: %f m/s\n ", velocidad);

				float tiempoF=(float)tiempo;
				__asm__ ( "flds %1;"
									"flds %2;"
									"fmul;"
									"fstps %0;" : "=g" (consumoPorSegundo) : "g" (tiempoF), "g" (consumo) ) ;

				__asm__ ( "flds %2;"
									"flds %1;"
									"fsub;"
									"fstps %0;" : "=g" (consumoTotal) : "g" (gasolina), "g" (consumoPorSegundo) ) ;

        printf("Gasolina: %f L\n", consumoTotal);

         if (velocidad<=(-0.000001)) {

            copyTime= copyDeltaTime(sub,copyTime,segundo);

						int altitud = altitud2(sub,alt,altura, totaltime,copyTime, gravedad,division,dos,velocidad,quo,rem);

            printf( "Altura : %d Ft\n",  altitud );

            printf("Tiempo : %d s\n", tiempo );


						float altiM= (float)altitud/3.280839;

						__asm__ ( "flds %1;"
											"flds %2;"
											"fmul;"
											"fstps %0;" : "=g" (dmul) : "g" (altiM), "g" (variaTem) ) ;


						__asm__ ( "flds %2;"
						          "flds %1;"
						          "fdiv;"
					          	"fstps %0;" : "=g" (div) : "g" (dmul), "g" (divVaria) ) ;


						__asm__ ( "flds %2;"
											"flds %1;"
									    "fsub;"
									    "fstps %0;" : "=g" (temp) : "g" (tempertaruta), "g" (div) ) ;


        }

        else {// HAY QUE HACER EN ASSEMBLY


			int altitud = altitud1(add,alt,altura, totaltime,tiempo, gravedad,division,dos,velocidad,quo,rem);

    	printf( "Altura : %d Ft\n",  altitud );

        printf("Tiempo : %d s\n", tiempo );

				float altiM= (float)altitud/3.280839;

				__asm__ ( "flds %1;"
									"flds %2;"
									"fmul;"
									"fstps %0;" : "=g" (dmul) : "g" (altiM), "g" (variaTem) ) ;


				__asm__ ( "flds %2;"
				          "flds %1;"
				          "fdiv;"
			          	"fstps %0;" : "=g" (div) : "g" (dmul), "g" (divVaria) ) ;


				__asm__ ( "flds %2;"
									"flds %1;"
							    "fsub;"
							    "fstps %0;" : "=g" (temp) : "g" (tempertaruta), "g" (div) ) ;


        }


				float arg125 = 1.25;
				float arg5 =5;
				float arg2 =2;


					if ((tiempo>=1)&&(tiempo<=21)&&(potencia<75))
						// 	potencia = potencia+1.25;
						__asm__ ( "flds %1;"
				              "flds %2;"
				              "fadd;"
				              "fstps %0;" : "=g" (potencia) : "g" (potencia), "g" (arg125) ) ;


					if ((tiempo>=26)&&(tiempo<=30)&&(potencia<81))
						// 	potencia = potencia + 1.25;
						__asm__ ( "flds %1;"
				              "flds %2;"
				              "fadd;"
				              "fstps %0;" : "=g" (potencia) : "g" (potencia), "g" (arg125) ) ;

					if ((tiempo>=31)&&(tiempo<=37))
						// 	potencia = potencia - 5;
						__asm__ ( "flds %2;"
				              "flds %1;"
				              "fsub;"
				              "fstps %0;" : "=g" (potencia) : "g" (potencia), "g" (arg5) ) ;


					if ((tiempo>=38)&&(tiempo<=65)&&(potencia>25))
						// 	potencia = potencia - 2;
						__asm__ ( "flds %2;"
				              "flds %1;"
				              "fsub;"
				              "fstps %0;" : "=g" (potencia) : "g" (potencia), "g" (arg2) ) ;

					int potenciaI =(int)potencia;


				printf("Potencia del motor: %d %c \n", potenciaI, 37);


				printf("Tempertaruta : %fCº\n", temp );

    	if ((tiempo<6)||((tiempo>25)&&(tiempo<43))||(tiempo>60)){// HAY QUE HACER EN ASSEMBLY

			__asm__ ( "flds %1;"
								"flds %2;"
								"fadd;"
								"fstps %0;" : "=g" (angulo) : "g" (angulo), "g" (rad)) ;
							}

    	//angulo=angulo+rad; HAY QUE HACER EN ASSEMBLY
			__asm__ ( "flds %1;"
								"flds %2;"
								"fadd;"
								"fstps %0;" : "=g" (tiempoHora) : "g" (tiempoHora), "g" (decimal) ) ;


								if ((tiempo>30)&&(tiempo<43))
								printf("Momento de gravedad 0\n"	 );

								  sleep(1);

		}while (tiempo!=65);// HAY QUE HACER EN ASSEMBLY

    return 0 ;
}
