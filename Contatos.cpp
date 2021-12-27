#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Agenda{
    string label;
    string fone;

public:

    Agenda(string label = "", string fone = "") {
        this->label = label;
        this->fone = fone;
    }
    string getLabel() {
        return this->label;
    }
    string getFone() {
        return this->fone;
    }
    void setLabel(string l) {
        this->label = l;
    }
    void setFone(string f) {
        this->fone = f;
    }
     string toString(int pos) {
        string texto{"["+ to_string(pos)+":"+this->label + ":" + this->fone + "] "};
        return texto;
    }
    friend class Contato;
};
class Contato {
    string nome;
    vector <Agenda> fones;
public:
    string getNome() {
        return this->nome;
    }
    void setNome(string nome) {
        this->nome = nome;
    }
    Contato(string nome = "") {
        this->nome = nome;
    }
    void addFone(Agenda fone) {
        fones.push_back(fone);
    }
    void removeFone(int pos) {
        fones.erase(fones.begin() + pos);
    }
    friend string toString(Contato& c) {
        string texto = c.nome+" ";
        for (int i = 0; i < (int)c.fones.size(); i++) {
            texto += c.fones[i].toString(i);
        }
        return texto;
    }

    friend class Agenda;
};
    bool isNumber(string s) {
        for(int i = 0;i < (int)s.size(); i++) {
                if(isdigit(s[i]) == false) {
                    cout << "Fone invalido" << endl;
                    return false;
                }
            }
            return true;
    }
int main() {
    Contato contato;
    Agenda agenda;
    while (true) {
        string line;
        getline(cin, line);
        string cmd;
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "init") {
            string nome;
            ss >> nome;
            contato.setNome(nome);
        } else if (cmd == "add") {
            string label;
            string fone;
            ss >> label >> fone;
            bool r = isNumber(fone);
            if (r == true) {
                agenda.setLabel(label);
                agenda.setFone(fone);
                contato.addFone(agenda);
            }
        } else if (cmd == "remove") {
            int pos;
            ss >> pos;
            contato.removeFone(pos);
        } else if (cmd == "show") {
            cout << toString(contato) << endl;
        } else if (cmd == "end") {
            break;
        }
        
    }
    
}