/* Ce programme fait le tri des moyennes de chacune de deux classes dont le nombre 
d'étudiant est saisi par l'utilisateur, il permet aussi de fusioner les moyennes des 
deux classes et de les faires trier */
#include <stdio.h>
void tri_affichage_tableau(float *moyenne, int size)
{ int c=0,i,j;
  float L;
    for( i=0;i<size;i++)
    {
     for(j=i+1;j<size;j++) 
        if(moyenne[i]>moyenne[j])
          {
            L=moyenne[i];
            moyenne[i]=moyenne[j];
            moyenne[j]=L;
          }
     if(moyenne[i]>=10){c++;}
    }  
    printf("\nLe classement des moyennes par ordre croissant pour cette classe est \n");
    for (i = 0; i < size; ++i)
    {   printf("moyenne[%d] = %f\n", i+1, moyenne[i]);
    }
    printf(" \nLe nombre d'eleves qui ont eu une moyenne >= 10 dans cette classe est: %d\n",c);
    printf(" \nLa plus grande moyenne cette classe est: pgmc=%f\n",moyenne[size-1]);
    printf(" \nLa plus petite moyenne cette classe est: ppmc=%f\n",moyenne[0]);
}
int main(void)
{  int i,j,k,l,size1,cl,size2,size3;
printf("\nEntrer le nombre des etudiants de la classe 1:");
scanf("%d",&size1);
printf("\nEntrer le nombre des etudiants de la classe 2:");
scanf("%d",&size2);
  float moyenne1[size1];
  size3=size1+size2;
  float classes[size3];
  printf("\nEntrer les moyennes de la classe 1\n");
   for ( i = 0; i < size1; i++)
    {   printf("moyenne1[%d] =", i+1);
        scanf("%f",&moyenne1[i]); 
    }
   tri_affichage_tableau(moyenne1, size1);
  float moyenne2[size2];
   printf("\nEntrer les moyennes de la classe 2\n");
   for(i=0;i<size2;i++)
    {   printf("moyenne[%d] =", i+1);
        scanf("%f",&moyenne2[i]); 
     }
     tri_affichage_tableau(moyenne2, size2);
i=0;j=0;k=0;
		while((i<size1) && (j<size2))
		{
			if(moyenne1[i]<moyenne2[j])
			{
			  classes[k]=moyenne1[i];
				i=i+1;
			}
			else
			{
				classes[k]=moyenne2[j];
				j=j+1;
			}
			k=k+1;
		}		
		while(i<size1)
		{
			classes[k]=moyenne1[i];
			i=i+1;
			k=k+1;
		}
		while(j<size2)
		{
			classes[k]=moyenne2[j];
			j=j+1;
			k=k+1;
		}
printf("Le tri des notes des deux classes par ordre croissant");
for(l=0;l<size3;l++)
    {   printf("classes[%d] =%f\n", l,classes[l]);
     }
}
