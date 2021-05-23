// Programa Principal Ejercicio 1 y 2------------------------------------------------------------------

#include <iostream>

#include "Clases.h"

//Definiciones de funciones de la clase Forma -------------------------------------------------------

Forma::Forma(string nomb) 
{
    nombre = nomb;
}

Forma::Forma(string nomb, Punto pun) : centro (pun)
{
    nombre = nomb;
}

void Forma::imprimir() 
{
    cout << endl << nombre << " tiene un color " << color;
    cout << " con centro en el punto (" << centro.x << ", " << centro.y  << ")";
}

ostream & operator << (ostream & salida, const Forma & f)
{
    salida <<  f.nombre << " de color " << f.color << " con centro (";
    salida <<  f.centro.x << ", " << f.centro.y  << ")" << endl;
    return(salida);
}

void Forma::EstablecerColor(string col)
{
    color = col;
}

string Forma::ObtenerColor()
{
    return(color);
}

void Forma::MoverCentro(Punto pun)
{
    centro.x += pun.x;
    centro.y += pun.y;
}

//Definiciones de funciones de la clase derivada rectángulo--------------------------------

Rectangulo::Rectangulo(string nomb, int menor, int mayor) : Forma(nomb)
{
    lado_menor = menor;
    lado_mayor = mayor;
}

Rectangulo::Rectangulo(string nomb, Punto pun, int menor, int mayor) : Forma(nomb, pun)
{
    lado_menor = menor;
    lado_mayor = mayor;
}

int Rectangulo::area()
{
    return (lado_menor * lado_mayor);
}

int Rectangulo::perimetro()
{
    return (2*lado_menor + 2*lado_mayor);
}

void Rectangulo::CambiarTamano(double factor_escala)
{
    lado_menor = (int) (lado_menor * factor_escala);
    lado_mayor = (int) (lado_mayor * factor_escala);
}

void Rectangulo::imprimir()
{
    Forma::imprimir();
}

ostream & operator << (ostream & salida, const Rectangulo & r)
{
    salida << Forma(r);
    salida << " y de lados " << r.lado_menor << " y " << r.lado_mayor << endl;
    return(salida);
}

//Definiciones de funciones de la clase derivada Cuadrado --------------------------------

Cuadrado::Cuadrado(string nomb, int lado) : Rectangulo(nomb, lado, lado)
{
	;
}

Cuadrado::Cuadrado(string nomb, Punto pun, int lado) : Rectangulo(nomb, pun, lado, lado)
{
	;
}

void Cuadrado::imprimir()
{
    Forma::imprimir();
}

ostream & operator << (ostream & salida, const Cuadrado & col)
{
    salida << Forma(col);
    salida << " y de lado " << col.lado_menor << endl;
    return(salida);
}

//Clase main --------------------------------------------------------------------------

int main ()
{
    //creación de objetos
    Punto pun(3,3);
    Forma forma("Forma", pun);
    Rectangulo rec("Rectangulo", pun, 2, 4);
    Cuadrado cuad("Cuadrado", pun, 4);
    cout << endl << "SE CREARON LOS OBJETOS PUNTO, FORMA, RECTANGULO Y CUADRADO";
    cout << endl << "----------------------------------------------------------" << endl;

    //llamada a funciones de los objetos
    rec.EstablecerColor("azul");
    forma.EstablecerColor("negro");
    cuad.EstablecerColor("rojo");
    
    //Imprimiendo el estado de los objetos
    cout << endl << "DESCRIPCION DEL ESTADO DE LOS OBJETOS";
    cout << endl << "-------------------------------------" << endl;
    rec.imprimir();
    forma.imprimir();
    cuad.imprimir();
    cout << endl; 
	
    // Cálculo del área de los objeto y prueba de MoverCentro y CambiarTamano
    cout << endl << "AREA DEL RECTANGULO DE DIFERENTES TAMANOS Y DEL CUADRADO";
    cout << endl << "--------------------------------------------------------" << endl;
    rec.MoverCentro(Punto(2, 2));
    cout << endl << "El area del Rectangulo 1 es " << rec.area();
    rec.CambiarTamano(3);
    cout << endl << "El area del Rectangulo 2  es " << rec.area();
    rec.CambiarTamano(0.5);
    cout << endl << "El area del Rectangulo 3 es " << rec.area();
    rec.CambiarTamano(2);
    rec.imprimir();
    cout << endl << "El area del Cuadrado es " << cuad.area() << endl;
    
    // Cálculo del perímetro de las figuras
    cout << endl << "PERIMETRO DEL RECTANGULO Y DEL CUADRADO";
    cout << endl << "---------------------------------------" << endl;
    cout << endl << "El perimetro del Rectangulo es " << rec.perimetro();
    cout << endl << "El perimetro del Cuadrado es " << cuad.perimetro();

    cout << endl; 
    cout << endl; 
}