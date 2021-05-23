// Ejercicio 1: Clase Punto ************************************************

using namespace std;

const double PI=3.1416;

class Punto {
    public:
	    int x;
	    int y;
        Punto() {x = 0; y=0;};
	    Punto(int i, int j) {x = i; y = j;}
};

// Ejercicio 1: Clase Forma ***********************************************

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

// Ejercicio 1: Clase Derivada Rectángulo ***********************************

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
// Ejercicio 2: Clase derivada Cuadrado de la clase rectángulo


class Cuadrado: public Rectangulo {
    public:
	    Cuadrado(string, int);
	    Cuadrado(string, Punto, int);
	    virtual void imprimir();
	    friend ostream & operator << (ostream & salida, const Cuadrado & col);
};
