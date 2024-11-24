#include<iostream>
#include<cmath>
using namespace std;

int n;
struct Linea{
    struct Puntos{
        float x;
        float y;
    }puntoi,puntof;
};
void guardar_puntos(Linea& , Linea& );
int lineas_se_cruzan(Linea , Linea);
int lineas_se_cruzan(Linea, Linea, float m1,  float m2);
float proceso();
int contador_proceso();
float angulo_interseccion(Linea a , Linea b, bool en_grados = false ){
    float x1 = a.puntoi.x;
    float y1 = a.puntoi.y;
    float x2 = a.puntof.x;
    float y2 = a.puntof.y;
    float x3 = b.puntoi.x;
    float y3 = b.puntoi.y;
    float x4 = b.puntof.x;
    float y4 = b.puntof.y;
    float pendiente1, pendiente2;
    float angulo;
    pendiente1 = (y2-y1)/(x2-x1);
    pendiente2 = (y4-y3)/(x4-x3);
    angulo = atan(fabs((pendiente2 - pendiente1) / (1 + pendiente1 * pendiente2)));
    if(en_grados){
        return angulo * 180/M_PI;
    } else {
        return angulo;
    }
}

int main(){
    bool llamar_funcion = true;
    Linea a,b;
    guardar_puntos(a,b);
    cout << lineas_se_cruzan(a,b);
    cout<< endl;

    float m1,m2;
    cout << "Probando sobrecarga" << endl;
    if (a.puntof.x - a.puntoi.x == 0) {
    m1 = 0; 
    } else {
    m1 = (a.puntof.y - a.puntoi.y) / (a.puntof.x - a.puntoi.x);
    }

    if (b.puntof.x - b.puntoi.x == 0) {
    m2 = 0; 
    } else {
    m2 = (b.puntof.y - b.puntoi.y) / (b.puntof.x - b.puntoi.x);
    }  
    cout << lineas_se_cruzan( a, b, m1, m2);


    cout<<endl;
    int opcion;
    cout<<"Angulo en el punto de cruce "<<endl;
    cout<<angulo_interseccion(a,b);
    cout<<"Mostrar angulo en grados?  1.Si  2.No '\n'"; cin>>opcion;
    if(opcion ==1){
        cout<<angulo_interseccion(a,b,true);
    }

    while(llamar_funcion){
        int opcion=0;
        cout<<proceso();
        cout<<"Llamar otra vez? 1.Si | 2.No "; cin>>opcion;
        if(opcion==2){
            llamar_funcion = false;
        }  
    }
    cout << "Las llamadas a la funcion fueron: " << contador_proceso();

}

void guardar_puntos(Linea& a, Linea& b){
    cout<<"Linea 1"<<endl;
    cout << "Punto inicial " << endl;
    cout << "Coordenada x: "; cin>> a.puntoi.x;
    cout << "Coordenada y: "; cin >> a.puntoi.y;
    cout << "Punto final " << endl;
    cout << "Coordenada x: "; cin>> a.puntof.x;
    cout << "Coordenada y: "; cin>> a.puntof.y;
    cout << endl;
    cout<<"Linea 2"<<endl;
    cout << "Punto inicial " << endl;
    cout << "Coordenada x: "; cin>> b.puntoi.x;
    cout << "Coordenada y: "; cin >> b.puntoi.y;
    cout << "Punto final " << endl;
    cout << "Coordenada x: "; cin>> b.puntof.x;
    cout << "Coordenada y: "; cin>> b.puntof.y;
}

int lineas_se_cruzan(Linea a, Linea b){
    float x1 = a.puntoi.x; 
    float y1 = a.puntoi.y;
    float x2 = a.puntof.x; 
    float y2 = a.puntof.y;
    float x3 = b.puntoi.x; 
    float y3 = b.puntoi.y;
    float x4 = b.puntof.x; 
    float y4 = b.puntof.y;
    float pendiente1, pendiente2;
    pendiente1 = (y2 - y1)/(x2 - x1);
    pendiente2 = (y4 - y3)/(x4 - x3);

    // Casos de líneas verticales y horizontales
    if (x1 == x2 && x3 != x4) { 
        if (y3 <= y1 && y4 >= y1) { // se cruzan
            return 1;  
        }
    } else if (y1 == y2 && y3 != y4) { 
        if (x3 <= x1 && x4 >= x1) { // se cruzan
            return 1;  
        }
    }

    //Paralelas
    if (pendiente1 == pendiente2) { 
        return 0;
    }
    // Otros casos 
    float det = (x2 - x1) * (y3 - y4) - (y2 - y1) * (x3 - x4);
    float t = ((x3 - x1) * (y3 - y4) - (y3 - y1) * (x3 - x4)) / det;
    float u = ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) / det;
    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        return 1; // Las líneas se cruzan
    }

    return -1; // Las líneas no se cruzan ni son paralelas
}

int lineas_se_cruzan(Linea a, Linea b, float m1, float m2){ //sobrecarga
    float x1 = a.puntoi.x; 
    float y1 = a.puntoi.y;
    float x2 = a.puntof.x; 
    float y2 = a.puntof.y;
    float x3 = b.puntoi.x; 
    float y3 = b.puntoi.y;
    float x4 = b.puntof.x; 
    float y4 = b.puntof.y;
    float det = (x2 - x1) * (y3 - y4) - (y2 - y1) * (x3 - x4);
    float t = ((x3 - x1) * (y3 - y4) - (y3 - y1) * (x3 - x4)) / det;
    float u = ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) / det;
    if (m1 == m2) { 
        return 0;
    }
    // Perpendiculares 
    if(m1 != 0 && m2 != 0){
        if(m1*m2 == -1 ){ 
        return 1;
        }
    } else if(m1 == 0 && m2 ==0){ // Casos verticales u horizontales
        if(x2 == x1 && y4 == y3){
            return 1;
        } else if (x4 == x3 && y2 == y1){
            return 1;
        }
    }
    
    if (t >= 0 && t <= 1 && u >= 0 && u <= 1){ // se cruzan
        return -1;
    }
    
}

float proceso(){
    float a;
    float b;
    cout << "Ingrese un numero: "; cin>> a; 
    cout << "Ingrese un segundo numero: "; cin>>b;
    n++;
    return a+b;
}

int contador_proceso(){
    return n;
}