#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
    //vecteur de dimension 3
    double e[3];

    //constructeur vide initialisant le vecteur à (0,0,0)
    vec3() : e{0,0,0} {}
    //constructeur non vide
    vec3(double e0, double e1, double e2) : e{e0,e1,e2} {}

    //getters
    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    //operateur : négatif 
    vec3 operator-() const {return vec3(-e[0], -e[1],-e[2]);}
    double operator[]((int i) const {return e[i];}
    double& operator[](int i) {return e[i];}     // & indique que la méthode retourne une référence, pas une copie donc c'est un "setter" : v[2] = 10; => "mets la 3eme coordonnée du vecteur v à 10"


    //opérateur somme
    vec3& operator+=(const vec3& v){
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    double length() const {
        return std::sqrt(length_squared());
    }

};
//simple alias pour + de clarité
using point3 = vec3;

//fonctions utiles


inline std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out << v.e[0] << ' ' << v.e[1] << '' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v){

}



