#include <stdio.h> 

int main(){
/////////////Practical Ex1
printf("Municipal Financial Management System\n");
printf("Welcome to Windhoek Municipality\n");

/////////////Practical Ex2
char municipality[50];
char mayor [50];
int population;

printf("Enter Municipal Financial Name: ");
scanf("%49", municipality);

printf("Enter Mayor: ");
scanf("%49", mayor);

printf("Enter Population: ");
scanf("%d", &population);

printf("\n--------------------------------\n");

printf("Municipalty : %s\n", municipality);
printf("Mayor : %s\n", mayor);
printf("Population : %d\n", population);

return 0;
}
