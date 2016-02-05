#include <stdio.h>
#include <stdlib.h>

#define NB_PARCOURS 10

void afficherTab(int tab[], int longueur)
{
	printf("| ");
	for (int i = 0 ; i < longueur; i++)
	{
	printf("%d | ", tab[i]);
	}
	printf("\n*********************\n");
}

void initialiserTab(int tab[], int longueur)
{
	for (int i = 0; i < longueur; i++)
	{
		tab[i] = 0;
	}
}

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{
	for (int i = 0; i < tailleTableau; i++)
	{
		tableauCopie[i] = tableauOriginal[i];
	}
}

void miroir(int tab[], int longueur, int milieu)
{
	int croissant = 0, decroissant = longueur-1;
	
	while (croissant < milieu)
	{
		tab[decroissant] = tab[croissant];
		croissant++;
		decroissant--;
	}
}

int main()
{
	int longueur = 7;
	int source = longueur/2;
	int tab[longueur];
	int tabPrecedent[longueur];
	
	initialiserTab(tab, longueur);
	
	tab[3] = 256;
	 
	copie(tab, tabPrecedent, longueur);
	
	for (int j = 0; j < NB_PARCOURS; j++)
	{
		for (int i = 0; i < source+1; i++)
		{
			if (tabPrecedent[i] != 0)
			{
				if (i == source)
				{
					tab[i-1] += tabPrecedent[i]/6;
					tab[i] -= (2*tabPrecedent[i])/6;
				}
				else if (i == source-1)
				{
					tab[i-1] += tabPrecedent[i]/6;
					tab[i+1] += (2*tabPrecedent[i]/6);
					tab[i] -= (2*tabPrecedent[i])/6;
				}
				else if ((i-1) < 0)
				{
					tab[i+1] += tabPrecedent[i]/6;
					tab[i] -= (2*tabPrecedent[i])/6;
				}
				else
				{
					tab[i-1] += tabPrecedent[i]/6;
					tab[i+1] += tabPrecedent[i]/6;
					tab[i] -= (2*tabPrecedent[i])/6;
				}
				
			}
		}
		miroir(tab, longueur, source);
		copie(tab, tabPrecedent, longueur);
		afficherTab(tab, longueur);
		
	}
	
	
	return EXIT_SUCCESS;
}


