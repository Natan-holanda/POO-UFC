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
vector<int> exclusivos(const vector<int>& v) {

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

vector<int> diferentes(const vector<int>& v) {

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

vector<int> abandonados(const vector<int>& v) {

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
vector<int> sozinhos(const vector<int>& v)
{
vector <bool> duplo(v.size(),false);
 for(i = 0; i < (int) v.size()-1; i++)
  {
   for(int e = i+1; e < (int) v.size(); e++)
   {
    if(abs(v[i]) == abs(v[e]))
    {
    duplo[i] = true;
    duplo[e] = true;
    }
   }
  }
vector <int> res;
 for(int r = 0; r < (int) v.size(); r++)
 {
  if(duplo[r] != true) res.push_back(v[r]);
 }
 return res;
}
int mais_ocorrencias(const vector<int>& v) {

int l {};
int r{};
vector <int> duplo(v.size(),1);
 for (i = 0; i < (int) v.size()-1; i++)
  {
   for (int e = i+1; e < (int) v.size(); e++)
   {
    if (abs(v[i]) == abs(v[e]))
    {
    duplo[i]++;
    }
   }
  }
  sort(duplo.begin(),duplo.end());
  return duplo.back();
}

int briga(const vector <int>& v) {

int vezes {};
int e {};
int m { 1 };
int d { m + 1 };
 while (d < v.size())
  {
   if ((abs(v[e]) > 30 && abs(v[d]) > 30) && abs(v[m]) > 50) vezes ++;
   d++;
   m++;
   e++;
  }
 return vezes;
}
int apaziguado (const vector <int>& v) {

int vezes {};
int e { 0 };
int d { 1 };
 while (d < v.size())
  {
   if ((abs(v[e]) > 80 && abs(v[d]) < 10) || (abs(v[d]) > 80 && abs(v[e]) < 10) ) vezes ++;
   d++;
   e++;
  }
 return vezes;
}
int quantos_times(const vector <int>& v) {

int times {};
int e {};
int d { e + 1 };
 while (d < v.size())
 {
  if ((v[d] > 0 && v[e] > 0) || (v[d] < 0 && v[e] < 0))
  {
   d++;
   e++;
   times ++;
  }else{
  d++;
  e++;
  }
 }
 return times;
}
int maior_time(const vector <int>& v) {

vector <int> times;
int temp { };
int e { 0 };
int d { };
bool condi { false };
 for (e = 0; e < v.size()-1; e++)
 {
  d = e + 1;

   while (v[e] > 0 && v[d] > 0)
   {
    temp ++;
    e++;
    d++;
    condi = true;
   }
   while (v[e] < 0 && v[d] < 0 && condi == false)
   {
    temp ++;
    e++;
    d++;
   }
   times.push_back(temp);
   temp = 0;
   condi = false;
  }
  sort(times.begin(), times.end());
  return times.back()-1;
 }
int sem_time(vector <int>& v) {

int e { 0 };
int m { e + 1};
int d { m + 1 };
int stime {};
  while ( d < v.size())
  {
   if (e == 0)
   {
    if ((v[e] > 0 && v[m] < 0) ||( v[e] < 0 && v[m] > 0) ) stime++;
   }
   if ((v[m] > 0 && v[e] < 0 && v[d] < 0)||(v[m] < 0 && v[e] > 0 && v[d] > 0)  ) stime++;
   d++;
   m++;
   e++;

  }
  return stime;
}

int casais(const vector <int>& v) {

int casal { 0 };
vector <bool> cfeito(v.size(), false);
int e {};
int d { e + 1};
 while (e < v.size()-1)
  {
   while (d < v.size())
     {
      if ((abs(v[e]) == abs(v[d]) && (v[e] > 0 && v[d] < 0)) ||(abs(v[e]) == abs(v[d]) && (v[e] < 0 && v[d] > 0)) )
       {
        if (cfeito[d] == false && cfeito[e] == false)
        {
       casal ++;
       cfeito[d] = true;
       cfeito[e] = true;
        }
       d++;
       }else{
       d++;
       }
     }
     e++;
     d = e + 1;
  }
  return casal;
}
int trio (vector <int>& v) {

int tr { 0 }, i;
vector <int> copia;
 for (i = 0; i < v.size(); i++) copia.push_back(abs(v[i]));

 sort(copia.begin(),copia.end());
 for (i = 0; i < copia.size(); i++)
 {
  if ((copia[i] == copia[i + 1] && copia[i + 2] == copia[i + 1]) && i <= copia.size()- 3)tr ++;
 }
 return tr;

}
vector <int> r(vector <int>& v,int n) {
vector<int> recebe;
 for (i = 0; i < v.size(); i++)
 {
  if (v[i] != n) recebe.push_back(v[i]);
 }
 return recebe;

}
vector <int> inserir(vector <int>& v, int pos, int n) {

vector <int> res(v.size() + 1);
 for (i = 0; i < res.size(); i++)
 {
  if(i == pos) {
   res[i] = (n);
  }
 else if(i < pos)res[i] = (v[i]);
 else{
  res[i] = v[i-1];
 }
 }
  return res;

}

vector <int> dance(vector <int>& v) {

vector <int> res = v;
int e {};
int d { e + 1 };
bool zerou { false };
 while (d < res.size()) {
  if(abs(res[e]) == abs(res[d])) {
   if(e > 0) {
    res[e] = 0;
    res[d] = 0;
    e--;
    d++;
    zerou = true;
   }else{
    res[e] = 0;
    res[d] = 0;
    d += 2;
    e = d - 1;
   }
  }else if(zerou == true) {
   d++;
   e = d - 1;
   zerou = false;
  }else{
  d++;
  e++;
  }
 }
vector <int> r;
 for(int valor : res)
  if(valor != 0) r.push_back(valor);
  return r;
}

int main() {

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
  cout << "\nOs elementos (em módulo) que estão sozinhos no vetor são :\n";
vector <int> sozim = sozinhos(pessoas);
 for( int value : sozim)
   cout << value << " ";
   cout << "\nA maior ocorrência de um mesmo nível de estresse é : \n";
int estress_comum = mais_ocorrencias(pessoas);
cout << estress_comum;
   cout << "\nA quantidade de possíveis brigas ocorridas :\n";
int brigas = briga(pessoas);
   cout << brigas;
   pessoas = {100, -90, 9, 88, -6, -80};
   cout <<"\nMudando os valores do vetor para : 100, -90, 9, 88, -6, -80\n";
   cout << "Irá ocorrer a seguinte quantidade de casos de apaziguamento : \n";
int calminho = apaziguado(pessoas);
   cout << calminho << '\n';
   cout <<"\nO número de times formados é :\n";
int t { quantos_times(pessoas) };
   cout << t << '\n';
   cout << "\n O maior time existente é : \n";
int m_time { maior_time(pessoas) };
   cout << m_time << '\n';
   cout << "\nA quantidade de pessoas que estavam sem um time é :\n";
int s { sem_time(pessoas) };
   cout << s << '\n';
   cout << "\nA quantidade de casais é : \n";
int casal { casais(pessoas) };
   cout << casal << '\n';
   cout << "\nMudando o valor do estresse para -80, 100, -90, 9, -9, 80, 88, -6, 9, -80\n";
   cout << "\nA quantidade de trios que podem ser formados é : \n";
   pessoas = {-80, 100, -90, 9, -9, 80, 88, -6, 9, -80};
int tri = trio(pessoas);
 cout << tri << '\n';
 cout << "\nSe quisermos, por exemplo, apagar a pessoa 9, temos : \n";
vector <int> s9 = r(pessoas, 9);
 for(int value : s9)
  cout << value << " ";
  cout << "\n\nSe quisermos inserir, por exemplo, o 7 na posição 3, teremos : \n";
vector <int> inserido =  inserir(pessoas,3,7);
 for(int value : inserido) cout << value <<" ";
 cout << "\n\nSe quisermos colocar os pares para dançar teríamos por exemplo : \n";
vector <int> rd = dance(pessoas);
 for(int rii : rd)
  cout << rii << " ";
return 0;
}

