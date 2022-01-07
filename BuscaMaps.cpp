#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
class Fone{
private:
    int id;
    string numero;
    string label;
public:
    Fone(int id = 0, string numero ="", string label=""){
        this->id = id;
        this->numero = numero;
        this->label = label;
    }
    bool isNumber(string numero){
        string aceitos = "0123456789";
        for(char c : numero){
            if(aceitos.find(c) == -1){
                return false;
            }
        }
        return true;
    }
    void setlabel(string label){
        this->label = label;
    }
    
    void setNumero(string numero){
        if(isNumber(numero)){
            this->numero = numero;
        }
    }

    void setId(int id){
        this->id = id;
    }

    string getLabel(){
        return this->label;
    }

    int getId(){
        return this->id;
    }

    string getNumero(){
        return this->numero;
    }
};

class Contato{
private:
    string nome;
public:
    vector<Fone> fones;
    
    Contato(string nome=""){
        this->nome = nome;
    }
    
    bool addFone(Fone fone){
        for(Fone &f : fones){
            if(f.getNumero() == fone.getNumero()){
                return false;
            }
        }
        this->fones.push_back(fone);
        return true;
    }
    
    void removerNumero(int posicao){
        this->fones.erase(this->fones.begin()+posicao);
    }

    void setNome(string nome){
        this->nome = nome;
    }

    string getNome(){
        return this->nome;
    }

    string getFones(){
        stringstream ss;
        for(int i=0; i<(int)fones.size(); i++){
            ss << "-" << this->fones[i].getNumero() << endl;
        }
        return ss.str();
    }
    
    string toString(){
        stringstream ss;
        ss <<this->nome << " ";
        for(int i=0; i<(int)fones.size(); i++){
            ss << "[" << this->fones[i].getId() << "::" << this->fones[i].getLabel()<< "::" << this->fones[i].getNumero() << "] ";
        }
        return ss.str();
    }
};


class Agenda{
    private:
        map<string, Contato*> contatos;
    public:

        bool adicionarContato(Contato& contato){
            Contato* c = contatos[contato.getNome()];
            if(c == nullptr){
                contatos[contato.getNome()] = &contato;
                return true;
            }
            return false;
        }
        
        bool removerContato(string nome){
            return this->contatos.erase(nome);
        }
        
        void buscarContato(string nome){
            bool aux;
            for(auto& c : this->contatos){
                if(c.first.find(nome) != -1 || c.second->getFones().find(nome) != -1){
                    cout << c.second->toString() << endl;
                    aux = true;
                }else{
                    aux = false;
                }
            }
            if(aux == false){
                cout << "contato nao encontrado" << endl;
            }

        }
        
        Contato* getFirstContato(string nome){
            return contatos.begin()->second;
        }

        int size(){
            return this->contatos.size();
        }
        
        string toString(){
            stringstream ss;
            ss << "Agenda: " << endl;
            for(auto it = contatos.begin(); it != contatos.end(); it++){
                ss << it->second->toString() << endl;
            }
            return ss.str();
        }

        Contato* getContato(string nome){
            return contatos[nome];
        }
};

int main(){
    Contato* contato = nullptr;
    Agenda agenda;
    Fone fone;
    
    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "add"){
            string nome;
            string label;
            string numero;
            ss >> nome >> numero >> label;
            Contato* contato = new Contato(nome);
            if(fone.isNumber(numero)){
                int id;
                if(agenda.adicionarContato(*contato) == false){
                    contato = agenda.getContato(nome);
                    id = contato->fones.size();
                }else{
                    id = 0;
                }
                fone = Fone(id, numero, label);
                if(contato->addFone(fone) == true){
                }else{
                    cout << "Numero ja existe!!" << endl;
                }
            }else{
                cout << "Numero invalido!!" << endl;
            }

        }else if(cmd == "rmFone"){
            string nome;
            Contato* aux;
            int posicao;
            ss >> nome >> posicao;
            aux = agenda.getContato(nome);
            if(aux != nullptr){
                aux->removerNumero(posicao);
            }else{
                cout << "Contato nao encontrado!!" << endl;
            }

        }else if(cmd == "rm"){
            string nome;
            ss >> nome;
            if(agenda.removerContato(nome)){
                cout << "Contato deletado!!" << endl;
                contato = agenda.getFirstContato(nome);
            }else{
                cout << "Contato nao encontrado!!" << endl;
            }        

        }else if(cmd == "search"){
            string nome;
            ss >> nome;
            agenda.buscarContato(nome);
        
        }else if(cmd == "show"){
            cout << agenda.toString() << endl;

        }else{
            cout << "Comando invalido!!" << endl;
        }
    }
};