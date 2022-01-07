#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class Cliente {
    std::string nome;
    int id;
    int pos;
    public :
    Cliente (std::string nome = "", int id = 0, int pos = 0) {
        this->nome = nome;
        this->id = id;
        this->pos = pos;
    }
    std::string getNome() {
        return nome;
    }
    int getId() {
        return id;
    }
    int getPos() {
        return pos;
    }
    void setNome(std::string nome) {
        this->nome = nome;
    }
    void setId(int id) {
        this->id = id;
    }
    void setPos(int pos) {
        this->pos = pos;
    }
    std::string toString() {
        std::string texto{this->nome + ":" + std::to_string(this->id) + ":" + std::to_string(this->pos) + " "};
        return texto;
    }
};

class Cinema {
    map <int, Cliente> cadeiras;
    public:
    Cinema (int capacidade = 0) {
        for(int i = 0; i < capacidade; i++) {
            cadeiras[i] = Cliente("", 0, i);
        }
    }
    void init(int capacidade) {
        for (int i = 0; i < capacidade; i++)
        {
            cadeiras[i] = Cliente("", 0, i);
        }
        
    }
    void reservar(Cliente cliente) {
     auto it = cadeiras.find(cliente.getPos());
     if(it->second.getNome() == "") {
         cadeiras[cliente.getPos()] = cliente;
     } else {
         cout << "fail : cadeira ocupada" << endl;
     }
    }
    void cancelar(string name) {
        for(auto it = cadeiras.begin(); it != cadeiras.end(); it++) {
            if(it->second.getNome() == name) {
                cadeiras[it->first] = Cliente("", 0, it->first);
                return;
            }
        }
        cout << "fail : cliente nao esta no cinema" << endl;
    }
    void imprimir() {
        cout << "[";
        for(auto it = cadeiras.begin(); it != cadeiras.end(); it++) {
            if(it->second.getNome() != "") {
                cout << it->second.toString();
            }else{
                cout << "- ";
            }
        }
        cout << "]" << endl;
    }
};
int main() {
    Cinema cinema;
    Cliente cliente;
    while (true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;
        if(command == "reservar") {
            string nome;
            int id;
            int pos;
            ss >> nome >> id >> pos;
            cliente = Cliente(nome, id, pos);
            cinema.reservar(cliente);
        } else if(command == "cancelar") {
            string nome;
            ss >> nome;
            cinema.cancelar(nome);
        } else if(command == "show") {
            cinema.imprimir();
        } else if(command == "end") {
            break;
        }else if(command == "init") {
            int capacidade;
            ss >> capacidade;
            cinema.init(capacidade);
        }
    }
    
}