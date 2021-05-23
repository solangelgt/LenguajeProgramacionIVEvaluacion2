
#include <iostream>

using namespace std;

// Ejercicio 1: Declaración y definición de Clase Punto------------------------------------

class Punto {
    public:
	    int x;
	    int y;
        Punto() {x = 0; y=0;};
	    Punto(int i, int j) {x = i; y = j;}
};

// Ejercicio 1: Declaración de Clase Forma  ----------------------------------------------

class Forma  {
    protected:
	    string color;
	    Punto centro;
	    string nombre;
    public:
	    Forma(string);
	    Forma(string, Punto);
	    virtual ~Forma() {};
	    virtual void imprimir();
	    virtual int area() {return(0);};
	    string ObtenerColor();
	    void EstablecerColor(string);
	    void MoverCentro(Punto);
	    friend ostream & operator << (ostream & salida, const Forma & f);
};

//Ejercicio 1: Definiciones de funciones de la clase Forma -------------------------------------------------------

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


// Ejercicio 1: Declaración de Clase Derivada Rectángulo -----------------------------------------

class Rectangulo: public Forma {
    protected:
	    int lado_menor;
	    int lado_mayor;
    public:
	    Rectangulo(string, int, int);
	    Rectangulo(string, Punto, int, int);
	    virtual void imprimir();
	    virtual int area();
	    virtual int perimetro();
	    void CambiarTamano(double);
	    friend ostream & operator << (ostream & salida, const Rectangulo & r);
};

// Ejercicio 1: Definiciones de funciones de la clase derivada rectángulo-------------------------

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

// Ejercicio 2: Declaración de Clase derivada Cuadrado

class Cuadrado: public Rectangulo {
    public:
	    Cuadrado(string, int);
	    Cuadrado(string, Punto, int);
	    virtual void imprimir();
	    friend ostream & operator << (ostream & salida, const Cuadrado & col);
};

//Ejercicio 2: Definiciones de funciones de la clase derivada Cuadrado --------------------------------

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
    int coordenada_x, coordenada_y, lmenor, lMayor,l;
    string colfor, colrec, colcuad; 
    double factor;

    cout << endl << "CREACION DE LOS OBJETOS: " << endl;
    cout << "-----------------------" << endl;

    //1. Creación de un objeto Punto (pun)
    cout << endl << "Ingrese la coordenada x del centro de los objetos: " << endl;
	cin  >> coordenada_x;
    cout << "Ingrese la coordenada y del centro de los objetos: " << endl;
	cin  >> coordenada_y;
    Punto pun(coordenada_x,coordenada_y);
    cout << "Se creo el objeto Punto" << endl;
 
    //2. Creación de un objeto Forma (forma)
    Forma forma("Forma", pun);
    cout << endl << "Se creo el objeto Forma" << endl;

    //3. Creación de un objeto Rectapunto (rec)
    cout << endl << "Ingrese lado menor del rectangulo: " << endl;
	cin  >> lmenor; 
    cout << "Ingrese lado mayor del rectangulo: " << endl;
	cin  >> lMayor; 
    Rectangulo rec("Rectangulo", pun, lmenor, lMayor);
    cout << "Se creo el objeto Rectangulo" << endl;

    //4. Creación de un objeto Cuadrado (cuad)
    cout << endl << "Ingrese lado del cuadrado: " << endl;
	cin  >> l;
    Cuadrado cuad("Cuadrado", pun, l);
    cout << "Se creo el objeto Cuadrado" << endl;
    
    //5. Establecer el color de los objetos creados
    cout << endl << "ESTABLECER EL COLOR DE LOS OBJETOS";
    cout << endl << "----------------------------------" << endl;
    cout << "Ingrese color del objeto forma: " << endl;
	cin  >> colfor;
    forma.EstablecerColor(colfor);
    cout << "Ingrese color del objeto rectangulo: " << endl;
	cin  >> colrec;
    rec.EstablecerColor(colrec);
    cout << "Ingrese color del objeto cuadrado: " << endl;
	cin  >> colcuad;
    cuad.EstablecerColor(colcuad);
    
    //6. Imprimiendo el estado de los objetos
    cout << endl << "DESCRIPCION DEL ESTADO DE LOS OBJETOS";
    cout << endl << "-------------------------------------" << endl;
    rec.imprimir();
    forma.imprimir();
    cuad.imprimir();
    cout << endl; 
	
    //7. Cálculo del área de los objetos rectángulo y cuadrado
    cout << endl << "AREA DEL RECTANGULO Y DEL CUADRADO";
    cout << endl << "----------------------------------" << endl;
    cout << endl << "El area del Rectangulo es " << rec.area();
    cout << endl << "El area del Cuadrado es " << cuad.area() << endl;

    //8. Cálculo del perímetro de los objetos rectángulo y cuadrado
    cout << endl << "PERIMETRO DEL RECTANGULO Y DEL CUADRADO";
    cout << endl << "---------------------------------------" << endl;
    cout << endl << "El perimetro del Rectangulo es " << rec.perimetro();
    cout << endl << "El perimetro del Cuadrado es " << cuad.perimetro() << endl;

    //9. Prueba de la función MoverCentro y CambiarTamano del Rectangulo
    cout << endl << "CAMBIAR CENTRO Y TAMANO DEL RECTANGULO";
    cout << endl << "--------------------------------------" << endl;
    
    cout << "Ingrese el cambio de x del centro del rectangulo: " << endl;
	cin  >> coordenada_x;

    cout << "Ingrese el cambio de y del centro del rectangulo: " << endl;
	cin  >> coordenada_y;

    rec.MoverCentro(Punto(coordenada_x,coordenada_y));
    
    cout << "Ingrese el factor de cambio de tamano del rectangulo: " << endl;
	cin  >> factor;
    rec.CambiarTamano(factor);
    rec.imprimir();
    cout << endl << "El area del nuevo rectangulo es " << rec.area();
    
    cout << endl; 
    cout << endl << "PRESIONE UNA TECLA PARA CONTINUAR...." << endl;
    cin.get();
}