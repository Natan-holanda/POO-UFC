#include <bits/stdc++.h>
using namespace std;
int i;
bool existe(int vetp[6], int x) {
 for(i = 0; i < 6; i++){
    if(vetp[i] == x){
    return true;
    break;
  }
}
 return false;
}
int contar(int vet[6], int x) {
int cont = 0;
 for(i = 0; i < 6; i++){
   if(vet[i] == x) cont++;
 }
 return cont;
}
int procura_valor(int vet[6], int x) {
int l;
 for(i = 0; i < 6; i++){
   if(vet[i] == x){
   return i;
   break;
   }
 }
 return -1;
}
int procurar_valor_apartir(int vet[6], int x, int inicio){
  for( i = inicio; i < 6; i++){
     if(vet[i] == x){
     return i;
      break;
     }
  }
  return -1;
}
int procurar_menor(int vet[6]) {
int menor = vet[0];
  for(i = 0; i < 6; i++){
    if(vet[i] < menor) menor = vet[i];
    }
 return menor;
}
int procurar_menor_pos(int vet[6]){
int mpos = 0;
 for(i = 0; i < 6; i++){
   if(vet[mpos] < vet[i]) mpos = i;
    }
 return mpos;
}
int procurar_menor_pos_apartir(int vet[6], int inicio){
 int menor = vet[inicio];
 for(i = inicio; i < 6; i++){
   if(menor < vet[i]) menor = vet[i];
 }
 return menor;
}
int procurar_melhor_se(int vet[6]){
int menor = 1000;
 for(i = 0; i < 6; i++){
   if(vet[i] < menor && vet[i] > 0) menor = vet[i];
 }
 if(menor == 1000) return -1;
 else{
  return menor;
 }
 }
int stress_medio(int vet[6]) {
double medio = 0;
 for(i = 0; i < 6; i++){
   medio += abs(vet[i]);
 }
 medio /= 6;
 return medio;
}
string mais_homens_ou_mulheres(int vet[6]){
int conth = 0, contm = 0;
  for(i = 0; i < 6; i++){
   if(vet[i] > 0) conth++;
   else{
   contm++;
   }
  }
  if(conth > contm)
  {
  return ("homens");
  }else if(conth < contm)
  {
  return ("mulheres");
  }else
  {
  return ("empate");
  }
}
string qual_metade_eh_mais_estressada(int vet[6]){
int m1 = 0, m2 = 0;
for(i = 0; i < 6; i++){
 if(i <= 3){
   m1 += abs(vet[i]);
 }else{
   m2 += abs(vet[i]);
 }
}
 if(m1 > m2)
 {
 return ("primeira");
 }else if(m1 < m2)
 {
 return ("segunda");
 }else
 {
 return ("empate");
 }
}
string homens_sao_mais_estressados_que_mulheres(int vet[5]){
int mediah = 0, mediam = 0, conth = 0, contm = 0;
 for(i = 0; i < 5; i++ ){
   if(vet[i] < 0){
   mediam += abs(vet[i]);
   contm++;
   }else{
   mediah += abs(vet[i]);
   conth++;
   }
 }
 if((mediam / contm) > (mediah / conth))
 {
 return ("não");
 }else if((mediam / contm) == (mediah / conth))
 {
 return ("são iguais");
 }else
 {
 return ("sim");
 }
}
int main(){
int pessoas[] = {-51, 99, 1, -50, -1, -99}, x ;
 cout << "O vetor é :";
 for(i = 0; i < 6; i++) cout << pessoas[i] <<" ";
 cout <<"\n\n";
 cout << "Existe o valor 1 nesse array ?\n";
 cout << existe(pessoas,1);
 cout << "\nQuantas vezes o valor 1 apareceu ?\n";
 cout << contar(pessoas,1);
 cout << "\nEm que posição o valor 1 aparece pela primeira vez ?\n";
 cout << procura_valor(pessoas,1);
 cout << "\nDada a posição 1, qual a posição em que o 1 aparece? \n";
 cout << procurar_valor_apartir(pessoas, 1, 1);
 cout << "\nQual o menor valor da lista? \n";
 cout << procurar_menor(pessoas);
 cout << "\n qual a posição do menor valor da lista?\n";
 cout <<  procurar_menor_pos(pessoas);
 cout << "\nDada a posição 3 para iniciar a busca, qual a posição do menor valor da lista?";
 cout << procurar_menor_pos_apartir(pessoas, 3);
 cout <<"\nqual a posição do homem mais calmo?\n";
 cout << procurar_melhor_se(pessoas);
 cout << "\nqual a média de stress da fila?\n";
 cout << stress_medio(pessoas);
 cout << "\nNa fila existem mais homens ou mulheres?\n";
 cout << mais_homens_ou_mulheres(pessoas);
 cout << "\nO nível de stress da primeira metade é maior que o nível de stress da segunda metade da fila?\n";
 cout << qual_metade_eh_mais_estressada(pessoas);
 cout << "\na média do stress dos homens é maior que a das mulheres?\n";
 cout << homens_sao_mais_estressados_que_mulheres(pessoas);
return 0;
}
