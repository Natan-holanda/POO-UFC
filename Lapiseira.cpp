#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct  Grafite {
    float calibre;
    string dureza;
    int tamanho;

        Grafite(float calibre = 0, string dureza = "", int tamanho = 0):
            calibre {calibre}, dureza {dureza}, tamanho {tamanho} {

         }

   friend ostream& operator << (ostream& os,Grafite grafite){
        os << "[" << grafite.calibre << ":" << grafite.dureza << ":" << grafite.tamanho << "]";
        return os;
    }
};

struct Lapiseira {
    int folhas { 0 };
    float calibre;
    Grafite * grafite;
        Lapiseira (float calibre = 0 ,Grafite * grafite = nullptr):
        calibre {calibre}, grafite {grafite}{

        }
    bool InserirGrafite(Grafite grafite){
        if(this->grafite != nullptr){
            cout << "fail : já existe grafite\n";
            return false;
        }else if(grafite.calibre != this->calibre){
            cout << "fail : calibre incompatível\n";
            return false;
        }else{
            this->grafite = &grafite;
            return true;
        }
    }
     Grafite * RemoverGrafite (){
            if(this->grafite == nullptr){
                cout << "Lapiseira sem grafite\n";
                return nullptr;
            }else{
                Grafite * grafite = this->grafite;
                this->grafite = nullptr;
                return grafite;
            }
        }
    bool escrever(int d) {
        if (this->grafite == nullptr){
            cout << "Lapiseira sem grafite\n";
            return false;
        }
        if (this->grafite->tamanho <= 0) {
            cout << "warning : grafite acabou\n";
            this->grafite = nullptr;
            return false;
        }
            if (this->grafite->dureza == "HB") {
                  if(this->grafite->tamanho -= 1 * d < 0) {
                    this->grafite->tamanho = 0;
                    cout << "fail : folhas escritas completas : " << this->folhas << "\n";
                    this->folhas = 0;
                    this->grafite = nullptr;
                    return false;
                }else{
                this->grafite->tamanho -= 1 * d;
                this->folhas += 1 * d;
                if(this->grafite->tamanho == 0){
                    this->grafite = nullptr;
                      cout << "warning : grafite acabou\n"; 
                      }
                                    return true;                
                }       
            }else if (this->grafite->dureza == "2B"){
                if(this->grafite->tamanho -= 2 * d < 0) {
                    this->grafite->tamanho = 0;
                    cout << "fail : folhas escritas completas : " << this->folhas << "\n";
                    this->folhas = 0;
                    this->grafite = nullptr;
                    return false;
                }else{
                this->grafite->tamanho -= 2 * d;
                this->folhas += d;
                 if(this->grafite->tamanho == 0){
                    this->grafite = nullptr;
                      cout << "warning : grafite acabou\n"; 
                      }
                return true;
                }       
        }else if (this->grafite->dureza == "4B"){
            if((this->grafite->tamanho -= 4 * d) < 0) {
                    this->grafite->tamanho = 0;
                    cout << "fail : folhas escritas completas : " << this->folhas << "\n";
                    this->folhas = 0;
                    this->grafite = nullptr;
                    return false;
                }else{
                this->grafite->tamanho -= 4 * d;
                this->folhas += d;
                 if(this->grafite->tamanho == 0){
                    this->grafite = nullptr;
                      cout << "warning : grafite acabou\n"; 
                      }
                return true;
                }       
    }else if (this->grafite->dureza == "6B"){
        if(this->grafite->tamanho -= 6 * d < 0) {
                    this->grafite->tamanho = 0;
                    cout << "fail : folhas escritas completas : " << this->folhas << "\n";
                    this->folhas = 0;
                    this->grafite = nullptr;
                    return false;
                }else{
                this->grafite->tamanho -= 6 * d;
                 if(this->grafite->tamanho == 0){
                    this->grafite = nullptr;
                      cout << "warning : grafite acabou\n"; 
                      }
                return true;
                }       
     }
   return false;
   }
        friend ostream& operator << (ostream& os,Lapiseira lapiseira){
        os << "calibre : " << lapiseira.calibre << ", ";
        os << "grafite : ";
        if(lapiseira.grafite == nullptr){
            os << "null\n";
            return os;
        }else{
            cout << *lapiseira.grafite << "\n";
          return os;       
        }
    }
};
int main() {
    Lapiseira * lapiseira = new Lapiseira();
    Grafite  grafite;
  while(true) {
    string line;
        getline(cin, line);
    stringstream ss(line);
    string cmd;
    ss >> cmd;
    if(cmd == "init") {
        float calibre;
        ss >> calibre;
       lapiseira->calibre = calibre;
    }else if(cmd == "show") {
        cout << *lapiseira << "\n";
    }else if(cmd == "inserir") {
        float calibre;
        string dureza;
        int tamanho;
        ss >> calibre >> dureza >> tamanho;
        grafite.calibre = calibre;
        grafite.dureza = dureza;
        grafite.tamanho = tamanho;
        lapiseira->InserirGrafite(grafite);
    }else if(cmd == "remover") {
       lapiseira->RemoverGrafite();
    }
    else if(cmd == "write") {
        int d;
        ss >> d;
        lapiseira->escrever(d);
    }
    else if(cmd == "end") {
        break;
    }
  }
    return 0;
}