#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int pc = 0;

int r0[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int r1[16];
int r2[16];
int r3[16];
int r4[16];
int r5[16];
int r6[16];
int r7[16];
int r8[16];
int r9[16];
int r10[16];
int r11[16];
int r12[16];
int r13[16];
int r14[16];
int r15[16];


unsigned int *memoire;
char ligne[18];
int numligne=0;

void add(int dest , int reg1 , int reg2){
  int a,b;
  if(reg1 < 16 ){
    a = reg1;
  }
  else {a = reg1-16;}

  if(reg2<16){
    b=reg2;
  }
  else {
    b = reg2-16;
  }
dest = a+b;
pc++;

}


void sub(int dest , int reg1 ,int reg2){
  int a,b;
  if(reg1 < 16 ){
    a = reg1;
  }
  else {a = reg1-16;}

  if(reg2<16){
    b=reg2;
  }
  else {
    b = reg2-16;
  }
dest = a-b;
pc++;
}


void addi();
void mul();
void lw();
void sw();
void beq();
void bne();
void j();

void printRegistre(){

    printf("1	0x%08x\n", r0[]);
  	printf("2	0x%08x\n", r1[1]);
  	printf("3	0x%08x\n", r2[2]);
  	printf("4	0x%08x\n", r3[3]);
  	printf("5	0x%08x\n", r4[4]);
  	printf("6	0x%08x\n", r5[5]);
  	printf("7	0x%08x\n", r6[6]);
  	printf("8	0x%08x\n", r7[7]);
  	printf("9	0x%08x\n", r8[8]);
  	printf("10 0x%08x\n", r9[9]);
  	printf("11 0x%08x\n", r10[10]);
  	printf("12 0x%08x\n", r11[11]);
  	printf("13 0x%08x\n", r12[12]);
  	printf("14 0x%08x\n", r13[13]);
  	printf("15 0x%08x\n", r14[14]);
  	printf("16 0x%08x\n", r15[15]);
}

int ToDecimale(char *binaire){
  int b, val , c,d;
  int somme= 0;
  int longeur=0;
  longeur = strlen(binaire) - 1; // pour enlenever le char null
  for(b=0;b<=longeur;b++){
    val = (binaire[b] - '0'); // convertis le caractère en une valeur numérique

    //on verifie que le caractere est bien une valeur binaire(0 ou 1)
    if((val!=0 || val!=1)){
      return 0 ;
    }

    for(c=1,d=longeur; d>b;d--){
      c*=2;

    somme=somme+ val*c ;//on fait la somme
    }
    return somme ;
  }
}

int main(int argc, char const *argv[]) {

  FILE* fichier = NULL;
  fichier = fopen("decode.txt", "r");
  if(fichier == NULL){
    printf("impossible d'ouvrir le fichier \n" );
    exit(EXIT_FAILURE);
  }

  //printf("--------Affichage du contenue du fichier-------\n");
  //if (fichier!=NULL) {
  memoire = (int*)malloc(8000*sizeof(int)); //8000 car 1 ko = 1000*8 8000/16
  if(memoire== NULL){
    printf("Erreur intialisation mémoire\n" );
  }

  for (int j = 0 ; j <8000 ; j++){
    memoire[j]= -1;  // initialise la mémoire à -1
  }
    for(int i = 0 ; i<16; i++){
      r1[i]=0x0;
      r2[i]=0x0;
      r3[i]=0x0;
      r4[i]=0x0;
      r5[i]=0x0;
      r6[i]=0x0;
      r7[i]=0x0;
      r8[i]=0x0;
      r9[i]=0x0;
      r10[i]=0x0;
      r11[i]=0x0;
      r12[i]=0x0;
      r13[i]=0x0;
      r14[i]=0x0;
      r15[i]=0x0;
    }
///copier ce que se trouve dans le fichier dans la mémoire
int i=0;
while(fgets(ligne,18,fichier)!=NULL){
  numligne++;
  char *rm ;
  rm = strchr(ligne,'\n');
  if(rm !=NULL){
    *rm= '\0';
  }

    memoire[i]=ToDecimale(ligne);
    // si nop instruction est faire un break
			if (strcmp(ligne, "00000000000000000000000000000000") == 0) {  // pour cela on compare la chaine de caractere
				i = 0x400;
				break;
			}

			else
				i++;
}


void process_IF() {
    // PC
    pc = pc+2;
    // Instruction Fetch

}



//  }

  return 0;
}
