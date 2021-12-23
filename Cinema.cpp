#include <iostream>
#include <string>
#include <vector>
#include <sstream>
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
        std::vector <Cliente> cadeiras;
        public:
        Cinema (int capacidade = 0) {
            cadeiras.resize(capacidade);
            for(int i = 0; i < capacidade; i++) {
                cadeiras[i] = Cliente("", 0, i);
            }
        }
        void reservar(Cliente cliente) {
        for(int i = 0; i < (int)cadeiras.size(); i++) {
            if(cadeiras[i].getNome() == cliente.getNome()) {
                cout << "Cliente ja esta na sala" << endl;
                return;
            }
        }
        if(cadeiras[cliente.getPos()].getNome() == "") {
            cadeiras[cliente.getPos()] = cliente;
        } else {
            cout << "fail : cadeira ocupada" << endl;
        }
        }
        void cancelar(string name) {
            for(int i = 0; i < (int)cadeiras.size(); i++) {
                if(cadeiras[i].getNome() == name) {
                    cadeiras[i] = Cliente("",0,0);
                    return;
                }
            }
            cout << "fail : cliente nao esta no cinema" << endl;
        }
        void imprimir() {
            cout << "[ ";
            for(int i = 0; i < (int) cadeiras.size(); i++) {
                if(cadeiras[i].getNome() != "") {
                    cout << cadeiras[i].toString() << " ";
                }else{ 
                    cout << "- ";
                }
            }
            cout << "]" << endl;
        }
    };
int main() {
     Cinema c;
    while (true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;
        if(command == "init") {
            int capacidade;
            ss >> capacidade;
            c = Cinema(capacidade);
        }else if(command == "reservar") {
            string name;
            int id;
            int pos;
            ss >> name;
            ss >> id;
            ss >> pos;
            Cliente cliente(name, id, pos);
            c.reservar(cliente);
    }else if(command == "cancelar") {
            string name;
            ss >> name;
            c.cancelar(name);
        }else if(command == "show") {
            c.imprimir();
        }else if(command == "end") {
            break;
        }
    }
}