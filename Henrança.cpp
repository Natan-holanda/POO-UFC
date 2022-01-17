#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Funcionario{
    string nome;
    int id;
    int salario = 10000;
protected:
    string cargo = "Funcionario";
public:
    Funcionario (string nome = "Sena", int id = 10){
        this->nome = nome;
        this->id = id;
    }
    string getNome(){
        return this->nome;
    }
     int getId(){
        return this->id;
    }
     int getSalario(){
        return this->salario;
    }
    void setSalario(int salario){
        this->salario = salario;
    }
    string getCargo(){
        return this->cargo;
    }
    virtual void entrada(){
        cout << "Entrada do " << this->cargo << " " << this->nome << endl;
    }
    virtual void saida(){
        cout << "Saida do " << this->cargo << " " << this->nome << endl;
    }
};
class Professor: public Funcionario {
    string disciplina;
    int sala;
public:
    Professor(string nome = "Sena", int id = 10, string disciplina = "POO", int sala = 0): Funcionario(nome, id), disciplina{disciplina}, sala{sala}{
        this->cargo = "Professor";
    }
    virtual void Aula(int tempo,Professor& professor){
        cout << "Professor " << professor.getNome() << " está dando aula de " << this->disciplina << " na sala " << this->sala << " por " << tempo << " horas" << endl;
    }
    string getDisc(){
        return disciplina;
    }
    int getSala(){
        return sala;
    }
    friend ostream& operator<<(ostream& os, Funcionario& funcionario){
        os << "Nome: " << funcionario.getNome() << endl;
        os << "Cargo: " << funcionario.getCargo() << endl;
        if(funcionario.getCargo() == "Professor"){
            os << "Disciplina: " << ((Professor&)funcionario).getDisc() << endl;
            os << "Sala: " << ((Professor&)funcionario).getSala() << endl;
        }
        os << "Id: " << funcionario.getId() << endl;
        os << "Salario: " << funcionario.getSalario() << endl;
        if(funcionario.getNome() == "Sena"){
            os << "Merece ganhar mais!";
    }
     return os;
}
};
class Coordenador: public Professor{
    string curso;
public:
    Coordenador(string nome = "Enyo", int id = 10, string disciplina = "Ciência", int sala = 0, string curso = "Ciencia da Computaçao"): Professor(nome, id, disciplina, sala), curso{curso}{
        this->cargo = "Coordenador";
    }
    string getCurso(){
        return curso;
    }
    void Evento(string evento, Coordenador& coordenador){
        cout << "O coordenador " << coordenador.getNome() << " está organizando o evento " << evento << endl;
    }
    friend ostream& operator<<(ostream& os, Coordenador& coordenador){
        os << "Nome: " << coordenador.getNome() << endl;
        os << "Id: " << coordenador.getId() << endl;
        os << "Salario: " << coordenador.getSalario() << endl;
        os << "Disciplina: " << coordenador.getDisc() << endl;
        os << "Sala: " << coordenador.getSala() << endl;
        os << "Curso: " << coordenador.getCurso() << endl;
        os << "Bem vindos ao " << coordenador.getCurso() << "!" << endl;
     return os;
    }
};



int main() {
Professor melhor("Sena", 10, "POO", 0);
Coordenador QuaseMelhor("Enyo", 10, "FUP", 0, "Ciencia da Computaçao");
melhor.setSalario(10000000);
melhor.entrada();
cout << melhor << endl;
melhor.Aula(3, melhor);
melhor.saida();
QuaseMelhor.entrada();
QuaseMelhor.Aula(3, QuaseMelhor);
QuaseMelhor.Evento("Aulão estagiários", QuaseMelhor);
QuaseMelhor.saida();
}