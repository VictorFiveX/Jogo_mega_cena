#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
void main()
{
	int val[6], sort[6], prim, seg, x, aux, count=0, count1=0, mega=0, z=0;
	int matriz[3][6], auxmatriz[1][1];
	srand(time(NULL));//sorteia aleatoriamente sem repetir
	//baseado no tempo
	setlocale(LC_ALL,"");//inclui caracteres especial na impress�o
	printf("Esse programa faz jogo da MegaSena.\n");
	//sorteia numeros de 1 a 60
	for(x=0;x<6;x++)
	{
		sort[x]=rand() % 60+1;
	//	printf(" %d ",sort[x]);
	}
	
	//coloca os valores em ordem crescente - bubble sort
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(sort[prim]>sort[seg])//verifica se anterior � maior 
			//que posterior
			{
				aux = sort[prim];//movimenta primeiro valor para aux
				sort[prim]=sort[seg];//movimento seg para prim valor
				sort[seg]=aux;//movimenta aux para segundo valor
				//trocando as posi��es para colocar em ordem 
				//crescente
			}
		}
	}
/*	printf("\nOrdenado.\n");
	for(x=0;x<6;x++)
	{
		printf(" %d ",sort[x]);
	}*/
	novo://label - etiqueta de goto
	
	//bubble sort apra verificar se sorteio foi repetido
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(sort[prim]==sort[seg])//compara sorteio repetido
			{
				sort[prim]=rand() % 60+1;//sorteia novamente 
				//no lugar do repetido
			}
			else
			{
				count++;//contar quantas vezes foi repetido
				//tem que ser 15 - para garantir todos diferentes
			}
		}
	}
	if(count < 15)//se for menor que 15 tem nuemro repetido
	{
		count=0;//reinicia variavel que conta repetidos
		goto novo;//faz retorno para nova verifica��o
	}

//coloca em ordem crescente
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(sort[prim]>sort[seg])
			{
				aux = sort[prim];
				sort[prim]=sort[seg];
				sort[seg]=aux;
			}
		}
	}
	
	// Imprime valores do vetor
	/* for(x=0;x<6;x++)
	{
		printf(" %d ",sort[x]);
	} */
	
	for(z = 0; z < 3; z++)
	{
		printf("\nJogo %d�", z);
		
		for(x=0;x<6;x++)
		{
			printf("\nO seu %d� valor do jogo:",x);
			scanf("%d", &matriz[z][x]);
		}
	}
	novojogo://label de retorno de verifica��o de repetidos
	for(z = 0; z < 3; z++)
	{
		for(prim=0;prim<5;prim++)
		{
			for(seg=prim+1;seg<6;seg++)
			{
				if(matriz[z][prim]==matriz[z][seg])
				{
					printf("\nVoc� jogou n�mero repetido!");
					printf("\nJogue novamente a posi��o %d do %d� jogo:",seg, z);
					scanf("%d", &matriz[z][seg]);
				}
				else
				{
					count1++;
				}
			}
		}
	}
	if(count1 < 15)
	{
		count1=0;
		goto novojogo;
	}
	
	//coloca em ordem a matriz
	for(z = 0; z < 3; z++)
	{

		for(prim=0;prim<5;prim++)
		{
			for(seg=prim+1;seg<6;seg++)
			{
				if(matriz[z][prim]>matriz[z][seg])
				{
					auxmatriz[0][0] = matriz[z][prim];
					matriz[z][prim]= matriz[z][seg];
					matriz[z][seg]= auxmatriz[0][0];
				}
			}
		} 
	}
     
    // imprime matriz ordenada
    /* for(z = 0; z < 3; z++)
    {
    	for(x = 0; x < 6; x++)
    	{
    		printf(" %d ", matriz[z][x]);
		}
	}*/
	
	//verifica quantos numeros voc� acertou na mega - bubble sort
    for(z = 0; z < 3; z++)
    {
		for(prim=0;prim<6;prim++)
		{
			for(seg=0;seg<6;seg++)
			{
				if(matriz[z][prim]==sort[seg])
				{
					mega++;
				}
			}
		}
			
		if(mega==6)
		{
			printf("\nJogo %d�: ", z);
			printf("\nParab�ns voc� � um novo milionario!!!");
		}
		if(mega==5)
		{
			printf("\nJogo %d�: ", z);
			printf("\nParab�ns voc� acertou na quina!!!");
		}
		if(mega==4)
		{
			printf("\nJogo %d�: ", z);
			printf("\nParab�ns voc� acertou na quadra!!!");
		}
		if(mega<4)
		{
			printf("\nJogo %d�: ", z);
			printf("\nVoc� n�o ganhou, acertou %d numero(s)!!!",mega);
		}
		mega = 0;
	}
	
	getch();
}
