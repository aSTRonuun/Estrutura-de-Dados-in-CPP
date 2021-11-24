#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

/**
 * Classe 'Circle' que implementa um círculo
 */
class Circle {
private:
    /**
     * Declaração dos atributos do círculo
     */
    double radius; // o raio do círculo
    Point center; // o centro do círculo
    
public:
    // Construtor default
    Circle() {
        center = Point();
        radius = 0;
    }

    // Construtor com dois argumentos
    Circle(Point& center, double radius) {
        this->center = center;
        this->radius = radius;
    }

    // getters
    Point getCenter() {
        return center;
    }
    double getRadius() {
        return radius;
    }
    
    // setters
    void setRadius(double radius) {
        this->radius = radius;
    }
    void setCenter(double x, double y) {
        center.setX(x);
        center.setY(y);
    }
    void setCenter(Point& center) {
        this->center = center;
    }

    // Operação que calcula a área do círculo
    double area() {
       return 3.14159265 * pow(radius, 2) ;
    }

    // Operação que verifica se um dado ponto p dado 
    // como entrada está ou não dentro do círculo
    bool interior(Point& p) {
        double distancia = pow(this->center.getX() - p.getX(), 2) + pow(this->center.getY() - p.getY(), 2);
        if(distancia < pow(radius, 2)){
            return true;
        }
        return false;
    }

    // Retorna uma string com os dados do círculo
    std::string toString() {
        std::string str = "Circle[radius: "
            + std::to_string(radius)
            + ','
            + "center: "
            + center.toString()
            + ']';
        return str; 
    }
};

#endif