#include "Fraccion.hpp"
using namespace std;

void pruebaExceptionCiclada(){
    int x, y;
    cout << "ingresa es dividendo: ";
    cin >> x;
    cout << "ingresa el divisor: ";
    cin >> y;
    while(true){
        try{
            if(y==0){
                throw "Division por cero, no puedo realizarlo";
            }
            int z=x/y;
            cout << "El resultado de la division es: " << z << endl;
            break;
        }
        catch(const char* msg){
            cerr << msg << endl;
            cout << "Ingresa otro denominador: ";
            cin >> y;
        }
    }
}

int main() 
{
  /*int x = 5;
  int z = 2;
  int y = ++x + z;
  cout << y << endl;
  cout << x << endl;
  pruebaExceptionCiclada();*/
  int n, d;
  cout << "Numerador: ";
  cin >> n;
  cout << "Denominador: ";
  cin >> d;
  while(true){
    try{
        Fraccion f1(n, d);
        cout << f1 << endl;
        break;
    }
    catch(invalid_argument& e){
        cerr << e.what() << endl;
        cout << "Denominador: ";
        cin >> d;
    }
  }
  cout << "Fin de programa" << endl;
}
