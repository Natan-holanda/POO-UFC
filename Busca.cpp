#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
class Fone{
    int id;
    string label;
    string fone;

public:

    Fone(int id=0, string fone="", string label=""){
        this->id = id;
        this->fone = fone;
        this->label = label;
    }
    int getId(){
        return id;
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
    void setId(int i) {
        this->id = i;
    }

    string toString(){
            stringstream ss;
            ss << "[ "<< id << " ]"<< "[ " << "Label: " << label << " ] [ " << "Fone: " << fone<< " ]\n";
            return ss.str();
    }

    friend class Contato;
    friend class Agenda;

};

class Contato {
    protected:
    string nome;
    vector <Fone> fones;
public:
    Contato(vector<Fone> fones, string nome){
        this->fones = fones;
        this->nome = nome;
    }

    int getSize() {
        return this->fones.size();
    }
    string getNome() {
        return this->nome;
    }
    void setNome(string nome) {
        this->nome = nome;
    }
    
    void addFone(Fone fone){
        while(true){
            for(int i = 0; i < (int)fones.size(); i++){
                if(fone.getId() == fones[i].getId()){
                    fone.setId(fone.getId()+1);
                    true;
                }
            }
        fones.push_back(fone);
        break;
        }
    }

    void removeFone(string prefix){
        for(int i = 0; i < (int)fones.size(); i++){
            if(fones[i].getLabel() == prefix){
                fones.erase(fones.begin() + i);
                cout<<"Numero removido!"<<endl;
            }else{
                cout<<"Este contato nao possui esse prefixo!"<<endl;
            }
        }
    }

    string toString(){
        stringstream ss;
        ss << "Nome: " << nome << "\n";
        for(int i = 0; i < (int)fones.size(); i++){
            ss << fones[i].toString();
        }
            return ss.str();

    }

    bool isNumber(string s) {
        for(int i = 0;i < (int)s.size(); i++) {
                if(isdigit(s[i]) == false) {
                    cout << "Fone invalido" << endl;
                    return false;
                }
            }
            return true;
    }



    friend class Fone;
    friend class Agenda;

};

class Agenda{
public:
   vector <Contato> contatos;

    void addContato(Contato c) {
        contatos.push_back(c);
    }

    int getId(int indice){
        return contatos[indice].fones[0].id;
    }

    void removeContato(int pos) {
        contatos.erase(contatos.begin() + pos);
    }
    
    int encontrarContato(string nome){
        for(int i = 0; i < (int)contatos.size(); i++){
            if(contatos[i].getNome() == nome){
                return i;
            }
        }
        return -1;
    }

    void encontrarNome(string nome){
        vector<Contato> resultado;
        for(int i = 0; i < (int)contatos.size(); i++){
            if(contatos[i].getNome().find(nome) != string::npos){
                resultado.push_back(contatos[i]);
            }
        }

        for(int i = 0; i < (int)resultado.size(); i++){
            cout<<resultado[i].toString();
            cout<<"\n";
        }
    }

    void encontrarNumero(string fone){
        vector<string> resultado;
        for(int i = 0; i < (int)contatos.size(); i++){
            for(int j = 0; j < (int)contatos[i].fones.size(); j++){
                if(contatos[i].fones[j].fone.find(fone) != string::npos){
                    stringstream str;
                    str << "[" << contatos[i].fones[j].id << "] ";
                    str << "[" << contatos[i].getNome() << "] ";
                    str << "[" << contatos[i].fones[j].fone << "] ";
                    resultado.push_back(str.str());
                }
            }
        }

        for(int i = 0; i < (int)resultado.size(); i++){
            cout<<resultado[i]<<endl;
        }
    }


string toString(){
        stringstream ss;
        for(int i = 0; i < (int)contatos.size(); i++){
            ss << contatos[i].toString() << "\n";
        }
        return ss.str();
    }

    friend class Contato;

};
int main(){
    Agenda agenda;
    while(true){
        string str;
        cin >> str;
        if(str == "break"){
            break;
        } else if(str == "add"){
            string nome; 
            string fone;
            string label;

            cin >> nome;
            cin >> label;
            cin >> fone;

            int posicao = agenda.encontrarContato(nome);

            if(posicao == -1){
                Contato contato(vector<Fone>(), nome);
                Fone f(0, fone, label);
                contato.addFone(f);
                agenda.addContato(contato);

            }else{
                agenda.contatos[posicao].addFone(Fone(0, fone, label));
            }

        } else if(str == "remover"){
            string nome, label;
            cin >> nome;
            cin >> label;

            int indice = agenda.encontrarContato(nome);
            if(indice == -1){
                cout << "Contato nao existe\n";
            }else{      
                agenda.contatos[indice].removeFone(label);
            }
        } else if(str == "encontrarNome"){
            string nome;
            cin >> nome;
            agenda.encontrarNome(nome);
        } else if(str == "encontrarNumero"){
            string fone;
            cin >> fone;
            agenda.encontrarNumero(fone);
        } else if(str == "show"){
            sort(agenda.contatos.begin(), agenda.contatos.end(), [](Contato a, Contato b){
                return a.getNome() < b.getNome();
            });
            cout<<agenda.toString();
        }else{
            cout<<"Comando invalido\n";
        }
    }
    return 0;
}