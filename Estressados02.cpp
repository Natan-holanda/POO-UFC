#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
int i;
bool existe(vector<int> pessoas, int x) {
 for(i = 0; i < 6; i++){
   if( pessoas[i] == x)
   return true;
}
 return false;
}
int contar(vector<int> pessoas, int x) {
int cont { 0 };
 for(i = 0; i < (int) pessoas.size(); i++){
   if(pessoas[i] == x) cont++;
 }
 return cont;
}
int procura_valor(vector<int> pessoas, int x) {
int l;
 for(i = 0; i < (int) pessoas.size(); i++){
   if(pessoas[i] == x){
   return i;
   }
 }
 return -1;
}
int procurar_valor_apartir(vector<int> pessoas, int x, int inicio){
  for( i = inicio; i < pessoas.size(); i++){
     if(pessoas[i] == x){
     return i;
     }
  }
  return -1;
}
int procurar_menor(vector<int> pessoas) {
int menor {pessoas[0]};
  for(i = 0; i < (int) pessoas.size(); i++){
    if(pessoas[i] < menor) menor = pessoas[i];
    }
 return menor;
}
int procurar_menor_pos(vector<int> pessoas){
int mpos { 0 };
 for(i = 0; i < 6; i++){
   if(pessoas[mpos] < pessoas[i]) mpos = i;
    }
 return mpos;
}
int procurar_menor_pos_apartir(vector<int> pessoas, int inicio){
int menor {pessoas[inicio]};

 for(i = inicio; i < (int) pessoas.size(); i++){
   if(menor < pessoas[i]) menor = pessoas[i];
 }
 return menor;
}
int procurar_melhor_se(vector<int> pessoas){
int menor { 1000 };
 for(i = 0; i < (int)pessoas.size(); i++){
   if(pessoas[i] < menor && pessoas[i] > 0) menor = pessoas[i];
 }
 if(menor == 1000) return -1;
 else{
  return menor;
 }
 }
int stress_medio(vector<int> pessoas) {
double medio { 0 };
 for(i = 0; i < (int) pessoas.size(); i++){
   medio += abs(pessoas[i]);
 }
 medio /= 6;
 return medio;
}
string mais_homens_ou_mulheres(vector<int> pessoas){
int conth { 0 }, contm { 0 };
  for(i = 0; i < (int) pessoas.size(); i++){
   if(pessoas[i] > 0) conth++;
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
string qual_metade_eh_mais_estressada(vector<int> pessoas){
int m1 = 0, m2 = 0;
for(i = 0; i < (int)pessoas.size(); i++){
 if(i <= 3){
   m1 += abs(pessoas[i]);
 }else{
   m2 += abs(pessoas[i]);
 }
}
 if(m1 > m2){
 return ("primeira");
 }else if(m1 < m2){
 return ("segunda");
 }else{
 return ("empate");
 }
}
string homens_sao_mais_estressados_que_mulheres(vector<int> pessoas){
int mediah = 0, mediam = 0, conth = 0, contm = 0;
 for(i = 0; i < (int)pessoas.size(); i++ ){
   if(pessoas[i] < 0){
   mediam += abs(pessoas[i]);
   contm++;
   }else{
   mediah += abs(pessoas[i]);
   conth++;
   }
 }
 if((mediam / contm) > (mediah / conth)){
 return ("não");

 }else if((mediam / contm) == (mediah / conth)) {
 return ("são iguais");
 }else{
 return ("sim");
 }
}
vector <int> clonar(vector <int>& pessoas) {
vector <int> novo;
 for(int value : pessoas)
   novo.push_back( value );
   return novo;
}
vector <int> homens(vector <int>& pessoas){
vector <int> h;
 for(int valor : pessoas)
  if(valor > 0) h.push_back(valor);

  return h;
}
vector <int> pegar_calmos(vector <int>& pessoas) {
vector <int> calmos;
 for(int value : pessoas)
  if(abs(value) < 10 ) calmos.push_back(value);

   return calmos;
}
vector <int> pegar_mulheres_calmas(vector <int>& pessoas) {
vector <int> mcalmas;
 for(int value : pessoas)
  if(value < 0 && abs(value) < 10) mcalmas.push_back(value);

  return mcalmas;
}
vector <int> inverter_com_copia(vector <int>& pessoas) {
vector <int> invertido;
 for(i = ((int) pessoas.size())-1; i >= 0; i--)
  invertido.push_back(pessoas[i]);
 return invertido;
}
void reverter_inplace(vector<int>& pessoas) {
int temp {};
 for(i = 0; i < (int) pessoas.size(); i++) {
  temp = pessoas[((int) pessoas.size()-1)-i];
  pessoas[((int) pessoas.size()-1)-i] = pessoas[i];
  pessoas[i] =  temp;
}
 for(int value : pessoas)
  cout << value <<" ";

  for(i = 0; i < (int) pessoas.size(); i++) {
  temp = pessoas[((int) pessoas.size()-1)-i];
  pessoas[((int) pessoas.size()-1)-i] = pessoas[i];
  pessoas[i] =  temp;
}
}
int sortear(const vector<int>& pessoas) {
int ns =rand() % pessoas.size();
 return pessoas[ns];
}
void embaralhar(vector<int>& v) {
int c {};
vector <bool> trocado(v.size(),false);
int temp {};
 for(i = 0; i < (int) v.size(); i++) {
   int r = rand() % v.size();
     while(v[r] == true)
     {
      r = rand() % v.size();
     }
       temp = v[i];
       v[i] =  v[r];
       v[r] = temp;
       trocado[r] = true;
       trocado[i] = true;

 }
 for(int value : v)
  cout << value << " ";

}
void ordenar (vector <int>& vet) {
 sort (vet.begin(), vet.end());
 for(int value : vet)
  cout << value << " ";
}
vector<int> exclusivos(const vector<int>& v)
{
int d { d + 1 };
int e { };
vector <int> sem_rep;
vector <bool> rep(v.size(), true);
  while(e < v.size()-1)
  {
   while(d < v.size())
   {
    if(v[d] == v[e])
    {
    rep[d] = false ;
    e++;
    d = e;
    }
    d++;
   }
   e++;
   d = e + 1;
  }
  for(i = 0; i < v.size(); i++)
   if(rep[i] == true) sem_rep.push_back(v[i]);

   return sem_rep;
}

vector<int> diferentes(const vector<int>& v)
{
int e { 0 };
int d { e + 1 };
vector <int> sem_rep;
vector <bool> rep(v.size(), true);
  while(e < v.size()-1)
  {
   while(d < v.size())
   {
    if((abs(v[d])) == (abs(v[e])))
    {
    rep[d] = false;
    e++;
    d = e;
    }
    d++;
   }
   e++;
   d = e + 1;
  }
  for(i = 0; i < v.size(); i++)
   if(rep[i] == true) sem_rep.push_back(abs(v[i]));

   return sem_rep;
}
vector<int> abandonados(const vector<int>& v)
{
vector <int> copia;
 for(int value : v)
  copia.push_back(value);
vector <int> removidos;
int o {};
int r {};
bool condi { false };
 for(o = 0; o < copia.size(); o++)
 { condi = false;
  for(r = 0; r < removidos.size(); r++)
  {
  if(copia [o] == removidos[r]) condi = true;
  }
  if(condi == false)
  {
  removidos.push_back(copia[o]);
  copia [o] = 10000;
  }
 }
vector <int> result;
 for(int value : copia)
  if(value != 10000) result.push_back(value);

  return result;
}
int main()
{
 srand(time(0));
 vector <int> pessoas = {-51, 99, 1, -50, -1, -99};
int  x ;
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
 cout << "\nVetor copiado \n";
vector <int> novo { clonar(pessoas) };
 for(int valor : novo)
   cout << valor << " ";
 cout << "\nTodos os homens : \n";
vector <int> h { homens(pessoas)};
 for(int value : h ) cout << value << " ";
 cout << "\nOs mais calmos (menores que dez) : \n";
vector <int> calmos { pegar_calmos(pessoas) };
 for( int value : calmos)
  cout << value << " ";
  cout << "\nMulheres calmas :\n";
  vector <int> mulheres_calmas { pegar_mulheres_calmas(pessoas) };
  for(int valor : mulheres_calmas)
  cout << valor << " ";
  cout <<"\nValores do vetor invertido : \n";
vector <int> invertido { inverter_com_copia(pessoas) };
   for(int value : invertido)
    cout << value << " ";
  cout << "\nVetor invertido sem cópia : \n";
  reverter_inplace(pessoas);
  cout << "\nUm valor sorteado é : \n";
  cout << sortear(pessoas);
  cout << "\nO vetor embaralhado é : \n";
  embaralhar(pessoas);
  pessoas = {-51, 99, 1, -50, -1, -99};
  cout << "\nVetor ordenado : \n";
  ordenar(pessoas);
  pessoas = {1, 2 , 3 , 3, 2 , -1, -10, -99};
  cout << "\nTendo mudado a lista de pessoas para 1, 2 , 3 , 3, 2, -1, -10, -99\n";
  cout <<"Tirando os números repetidos temos :\n";
  vector <int> sem_rep = exclusivos(pessoas);
  for(int valor : sem_rep)
   cout << valor << " ";
  cout << "\nOs diferentes níveis de estresse são :\n";
  vector <int> dif = diferentes(pessoas);
  for(int value : dif)
   cout << value << " ";
vector <int> alones = abandonados(pessoas);
 cout << "\nTirando todos os valores uma única vez, temos :\n";
 for(int val : alones)
  cout << val << " ";
return 0;
}

