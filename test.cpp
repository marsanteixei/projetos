#include <stdio.h> 
#include <stdlib.h>
/*Construa um programa em C que tenha como entrada um conjunto de cinco inteiros
{Pmat, Plin, Phum, Pnat, Pred}
que são, respectivamente, os pesos das áreas de conhecimento Matemática, Linguagens,
Ciências Humanas, Ciências da Natureza e Redação para um determinado curso em uma
Universidade; e um arquivo de dados alunos.dat que contém na primeira linha um inteiro n
que informa o número de linhas do arquivo e cada uma das demais linhas é composta por um codigo e 5 floats (de 0 a 10) distribuídos da seguinte forma:
[código do aluno] [Nota Matemática] [Nota em Linguagem] [Nota Humanas] [Nota Natureza] [Nota Redação]
a) criar um arquivo aluno.dat (deve ser pedindo as notas e codigo do aluno), leia os dados dos alunos do arquivo alunos.dat e armazene em estruturas que possuam
os seguintes campos: codigo, Nmat, Nlin, Nhum, Nnat, Nred e Media_P.
b) Calcule a média ponderada para cada um dos alunos utilizando os pesos {Pmat, Plin, Phum,
Pnat, Pred} e armazene no campo Media_P.
c) Apresente no monitor um relatório mostrando as notas, campos com notas multiplicadas pelos pesos e a situação de cada aluno 
(Na coluna situação deve ser apresentado AP se a Media_P = 6,0 e RP, caso contrário).
d) Armazene o relatório do item (c) em um arquivo report.dat. A primeira linha deve
conter apenas a quantidade de alunos armazenadas no arquivo e cada linha a seguir deve
conter os dados apresentados no relatório.*/
void armazenardadosarq(int quant,float vetcod[],float vetmat[],float vetlin[],float vethum[],float vetnat[],float vetred[] ){
	FILE *arq;
	int i;
    arq = fopen("alunos.dat", "w");
	fprintf(arq," %d \n",quant);
	for(i=0;i<quant;i++)
	{
		fprintf(arq," %f    %f    %f    %f    %f    %f \n",vetcod[i],vetmat[i], vetlin[i],vethum[i],vetnat[i],vetred[i]);
	}
	fclose(arq);
}

float calcmediapond(int p1, int p2, int p3, int p4, int p5, float n1, float n2, float n3, float n4, float n5){
	float mediapond;
	mediapond=(float)(((p1*n1)+(p2*n2)+(p3*n3)+(p4*n4)+(p5*n5))/(p1+p2+p3+p4+p5));
	return mediapond;
	
}
int main(){
int quant;	
float cod;
float aux;
int i;
printf("entre com a quantidade de alunos\n");
scanf("%d",&quant);
float vet1[quant];
float vet2[quant];
float vet3[quant];
float vet4[quant];
float vet5[quant];
float vet6[quant];
for(i=0;i<quant;i++){
	printf("entre com o codigo do aluno %d \n",i+1);
	scanf("%f",&cod);
	vet1[i]=cod;
}
for(i=0;i<quant;i++){
	printf("entre com a nota de matematica do aluno %d \n",i+1);
	scanf("%f",&aux);
	vet2[i]=aux;
}
for(i=0;i<quant;i++){
	printf("entre com a nota de Linguagem do aluno %d \n",i+1);
	scanf("%f",&aux);
	vet3[i]=aux;
}
for(i=0;i<quant;i++){
	printf("entre com a nota de humanas do aluno %d \n",i+1);
	scanf("%f",&aux);
	vet4[i]=aux;
}
for(i=0;i<quant;i++){
	printf("entre com a nota de ciencias da natureza do aluno %d \n",i+1);
	scanf("%f",&aux);
	vet5[i]=aux;
}
for(i=0;i<quant;i++){
	printf("entre com a nota de redacao do aluno %d \n",i+1);
	scanf("%f",&aux);
	vet6[i]=aux;
}
//criando o arquivo com os dados:
armazenardadosarq(quant,vet1,vet2,vet3,vet4,vet5,vet6);

//leitura do arquivo:
int q,j;
int k=6;
FILE *arq;
	arq=fopen("alunos.dat","rt");
     fscanf(arq,"%d",&q);
     float matriz_dados[q][k];
     for(i=0;i<q;i++)
	{
		for(j=0;j<k;j++){
			
			fscanf(arq,"%f",&matriz_dados[i][j]);
		}		
	}
	//pedindo os pesos para cada materia:
	int pmat, plin, phum, pnat, pred;
	printf("entre com o peso para matematica\n");
	scanf("%d",&pmat);
	printf("entre com o peso para linguagem\n");
	scanf("%d",&plin);
	printf("entre com o peso para humanas\n");
	scanf("%d",&phum);
	printf("entre com o peso para ciencias da natureza\n");
	scanf("%d",&pnat);
	printf("entre com o peso para redacao\n");
	scanf("%d",&pred);
	//criando estrutura aluno:
	typedef struct aluno
{
	float codigo;
	float nmat;
	float nlin;
	float nhum;
	float nnat;
	float nred;
	float media_p;
}Taluno;

Taluno alu[q];
char situacao1[]="AP";
char situacao2[]="RP";
//clocando os dados num vetor de estruturas:
for(i=0;i<q;i++){
		
		alu[i].codigo= matriz_dados[i][0];
	    alu[i].nmat=matriz_dados[i][1];
	    alu[i].nlin=matriz_dados[i][2];
	    alu[i].nhum=matriz_dados[i][3];
	    alu[i].nnat=matriz_dados[i][4];
	    alu[i].nred=matriz_dados[i][5];
	    alu[i].media_p=calcmediapond(pmat,plin,phum,pnat,pred,alu[i].nmat,alu[i].nlin,alu[i].nhum,alu[i].nnat,alu[i].nred); //calculando media ponderada
	}	
	
   printf("              notas originais:                                                              notas com pesos:                                    \n\n");
   printf("codigo      MAT         LIN         HUM          NAT           RED            MAT            LIN           HUM          NAT          RED      MEDIA POND      SITUACAO\n\n");
   for(i=0;i<q;i++){
   	
   printf("%.0f         %.2f        %.2f        %.2f        %.2f           %.2f           %.2f           %.2f          %.2f         %.2f         %.2f      %.2f       %s\n\n",alu[i].codigo,alu[i].nmat,alu[i].nlin,alu[i].nhum,alu[i].nnat,alu[i].nred,pmat*alu[i].nmat,plin*alu[i].nlin,phum*alu[i].nhum,pnat*alu[i].nnat,pred*alu[i].nred,alu[i].media_p, alu[i].media_p >= 6 ? situacao1 : situacao2);
   }

	//criando arquivo report.dat:
	 FILE *arq2;
    arq2 = fopen("report.dat", "w");
    fprintf(arq2," %d \n",q);
    fprintf(arq2,"              notas originais:                                                              notas com pesos:                                    \n\n");
   fprintf(arq2,"codigo         MAT         LIN          HUM          NAT          RED         MAT        LIN          HUM         NAT         RED        MEDIA POND       SITUACAO\n\n");
   for(i=0;i<q;i++){
   	
   fprintf(arq2,"%.0f           %.2f        %.2f          %.2f         %.2f        %.2f        %.2f       %.2f         %.2f        %.2f        %.2f        %.2f             %s\n\n",alu[i].codigo,alu[i].nmat,alu[i].nlin,alu[i].nhum,alu[i].nnat,alu[i].nred,pmat*alu[i].nmat,plin*alu[i].nlin,phum*alu[i].nhum,pnat*alu[i].nnat,pred*alu[i].nred,alu[i].media_p, alu[i].media_p >= 6 ? situacao1 : situacao2);
   }
   	fclose(arq2);
}
