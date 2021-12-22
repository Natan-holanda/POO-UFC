#include <iostream>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include <sstream>

using namespace std;
class Kid {
        int age;
        string name;
    public :
        Kid(string name = "", int age = 0) {
            this->age = age;
            this->name = name;
        }
        int getAge() {
            return age;
        }
        string getName() {
            return name;
        }
        void setAge(int age) {
            this->age = age;
        }
        void setName(string name) {
            this->name = name;
        }
        std::string toString(){
            std::string texto{this->name + ":" + std::to_string(this->age)};
            return texto;
    }
};
class Pulapula {
    list <Kid> esperando;
    list <Kid> brincando;
    Kid remove_kid(string name, list <Kid> lista){
        for(auto it = lista.begin(); it != lista.end(); it++){
            if(it->getName() == name){
                Kid k = *it;
                lista.erase(it);
                return k;
            }
        }
        return Kid("",0);
    }
    public :
     Pulapula (){

     };
     void arrive(Kid kid) {
           esperando.push_back(kid);
            }
    void enter() {
        if(esperando.empty() == false) {
            brincando.push_back(esperando.front());
            esperando.pop_front();
        }else{
            cout << "\nNao ha ninguem na fila" << endl;
        }
    }
     void leave() {
            if(brincando.empty() == false) {
                esperando.push_back(brincando.front());
                brincando.pop_front();
            }else{
                cout << "\nNao ha ninguem brincando" << endl;
            }
     }
     void papaiChegou(string name) {
        Kid k = remove_kid(name, esperando);
        if(!(k.getName() != "")){
        Kid k = remove_kid(name, brincando);
        }
    }

        std::string toString(){
            std::string texto{"=>"};
            for(auto it = this->esperando.rbegin(); it != this->esperando.rend(); it++){
                texto += it->toString() + " ";
            }
            texto += "=> [ ";
            for(auto it = this->brincando.rbegin(); it != this->brincando.rend(); it++){
                texto += it->toString() + " ";
            }
            texto += "]";
            return texto;
        }

};

    

int main() {
    Pulapula pula;
    while(true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;
        if(command == "arrive") {
            string name;
            int age;
            ss >> name >> age;
            Kid k(name, age);
            pula.arrive(k);
        }else if(command == "enter") {
            pula.enter();
        }else if(command == "leave") {
            pula.leave();
        }else if(command == "papaiChegou") {
            string name;
            ss >> name;
            pula.papaiChegou(name);
        }else if(command == "show") {
            cout << pula.toString() << endl;
        }else if(command == "end") {
            break;
        }
    }
}