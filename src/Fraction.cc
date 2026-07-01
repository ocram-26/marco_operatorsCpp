#include "Fraction.h"

#include <iostream>
#include <numeric>
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator)
  : numerator(numerator), denominator(denominator) {
//  this->numerator = numerator this->numerator señala al atributo de la clase
  if(denominator == 0)
    throw std::invalid_argument("denominator cannot be zero");

  normalize();
}

Fraction::Fraction(int numerator)
  : Fraction(numerator, 1) {
}

int Fraction::num() const {
  return numerator;
}

int Fraction::den() const {
  return denominator;
}

void Fraction::normalize(){
  // TODO: normalizar la fraccion.
  // Sugerencia:
  // 1. Si denominator < 0, mover el signo al numerador.
  // 2. Usar std::gcd para reducir numerator y denominator.
  if(denominator < 0){
    numerator = - numerator;
    denominator = - denominator;
  }
  int mcd = std::gcd(numerator,denominator);
  if(mcd != 0){
    numerator /= mcd;
    denominator /= mcd;
  }
}

Fraction& Fraction::operator+=(const Fraction& other){
  //a.operator+=(b)
  numerator = (numerator * other.denominator) + (other.numerator * denominator);
  denominator = denominator * other.denominator;
  normalize();
  return *this;
}

Fraction& Fraction::operator-=(const Fraction& other){
  //a.operator-=(b)
  numerator = (numerator * other.denominator) - (other.numerator * denominator);
  denominator = denominator * other.denominator;
  normalize();
  return *this;
}

Fraction operator+(Fraction a, const Fraction& b){
  // TODO: reutilizar operator+=.
  a += b;
  return a;
}

Fraction operator-(Fraction a, const Fraction& b){
  // TODO: reutilizar operator-=.
  a -= b;
  return a;
}

Fraction operator*(const Fraction& a, const Fraction& b){
  // TODO: implementar multiplicacion.
  
  return Fraction(a.num() * b.num(), a.den() * b.den()); 
}

Fraction operator/(const Fraction& a, const Fraction& b){
  // TODO: implementar division y rechazar division por fraccion cero.
  return Fraction(a.num() * b.den(), b.num() * a.den());
}

bool operator==(const Fraction& a, const Fraction& b){
  // TODO: implementar igualdad.
  return (a.num() == b.num() && a.den() == b.den());
}

bool operator!=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator==.
  return !(a == b);
}

bool operator<(const Fraction& a, const Fraction& b){
  // TODO: implementar usando productos cruzados.
  return (a.num() * b.den() < b.num() * a.den());
}

bool operator<=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator< y operator==.
  return (a < b || a == b);
}

bool operator>(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator<.
  return (b < a);
}

bool operator>=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator<.
  return (b < a || a == b);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f){
  // TODO: imprimir con el formato numerador/denominador.
  os << f.num() << '/' << f.den();
  return os;
}

std::istream& operator>>(std::istream& is, Fraction& f){
  // TODO: leer con el formato numerador/denominador.
  // Si la entrada es invalida, marcar failbit y no modificar f.
  int n, d;
  char slash;

  is >> n >> slash >> d;

  if(!is || slash != '/' || d == 0)
    is.setstate(std::ios::failbit);
  else
    f = Fraction(n, d);

  return is;
}
