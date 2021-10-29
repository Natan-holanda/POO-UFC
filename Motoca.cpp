/*
    Esta é uma implementação e estudo da aula de Programação Orientada a Objetos do Professor Sena.
    O código a seguir foi feito em uma aula, e eu o estudei e implementei, com o objetivo único de aprendizado.
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Pessoa   {
    string nome;
    int idade;
    Pessoa (string nome = "", int idade = 0){
        this->idade = idade;
        this->nome = nome;
        }
   friend ostream& operator<<(ostream& os, const Pessoa p) {
       os << "Pessoa : " << p.nome << " Idade : " << p.idade;
       return os;
   }
};
   
struct Motoca {
    Pessoa * pessoa {nullptr};
    int tempo = 0; 
    int potencia = 1;
    Motoca  (int potencia = 0) {
     this->potencia = potencia;
     }
    bool InserirPessoas(Pessoa * p) {
        if(this->pessoa != nullptr) {
            cout << "Motoca Cheia!\n";
            return false;
        }
        this->pessoa = p;
        return true;
    }
    string buzinar(){
        return "P"+ (string(this->potencia,'e')) + "m";
    }
    Pessoa * remover_pessoa(){
        Pessoa * p = this->pessoa;
        p = nullptr;
        return p;
    }
    void ComprarTempo(int tempo) {
        this->tempo += tempo;
    }
    bool dirigir(int tempo) {
        if(this->pessoa == nullptr) {
            cout << "Não tem ninguém para dirigir\n";
            return false;
        }if(tempo <= this->tempo) {
            cout << "Pode dirigir por " << tempo << " minutos\n";
            this->tempo -= tempo;
            return true;
        } if(tempo > this->tempo) {
            cout << "Só conseguiu dirigir por " << this->tempo << " minutos\n";
            this->tempo = 0;
            return true;
        }

    }
    friend ostream& operator<<(ostream& os, Motoca& m) {
      os << "[" << *m.pessoa << "]";
      return os;
    }

};

int main() {
 Motoca motoca(1);
while (true) {
   string line;
    getline(cin, line);
    stringstream ss(line);
    string cmd;
    ss >> cmd;
    if(cmd == "end") {
        break;
    } else if(cmd == "init") {
        int pot = 0;
        ss >> pot;
        motoca = Motoca(pot);
    } else if(cmd == "Inserir") {
        string nome;
        int idade;
        ss >> nome >> idade;
        Pessoa * p = new Pessoa(nome, idade);
        if(!motoca.InserirPessoas(p))
            delete p;
    } else if (cmd == "retirar") {
        Pessoa * p = motoca.remover_pessoa();
        if(p != nullptr) {
          delete p;   
        }
       
    }
     else if(cmd == "show") {
        cout << motoca << '\n';
    } else{
        cout << "Comando não é válido\n";
    }

}
}