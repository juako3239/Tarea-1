#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Created by jqnfu on 11-04-2025.
//

#ifndef CLASES_H
#define CLASES_H

class Pregunta {
private:
    string enunciado;
    int tiempoEstimado;
    string taxonomia;

public:
    //Declaracion de Constructor de la clase Pregunta
    Pregunta(string enunciado, int tiempoEstimado, string taxonomia);

    //Destructor de la clase Pregunta
    ~Pregunta();

    //Getters, setters y metodos
    string getEnunciado();
    string getTaxonomia();
    int getTiempoEstimado();
    void setEnunciado(string enunciado);
    void setTiempoEstimado(int tiempoEstimado);
    void setTaxonomia(string taxonomia);
    void mostrarPregunta();
};

class PreguntaVoF : public Pregunta {
private:
    bool respuestaCorrecta;
    string justificacion;

public:
    //Declaracion de constructor de la clase PreguntaVoF
    PreguntaVoF(string enunciado, int tiempoEstimado, string taxonomia, bool respuestaCorrecta, string justificacion);
    //Declaracion de getters, setters y metodos
    bool getRespuestaCorrecta();
    void setRespuestaCorrecta(bool respuestaCorrecta);
    string getJustificacion();
    void setJustificacion(string justificacion);
    void mostrarPregunta();
};

class PreguntaAlt : public Pregunta {
private:
    vector<string> opciones;
    int respuestaCorrecta;

public:
    //Declaracion del constructor de la clase PreguntaAlt con uso de herencia de la clase Pregunta
    PreguntaAlt(string enunciado, int tiempoEstimado, string taxonomia, vector<string> opciones, int respuestaCorrecta);
    //Declaracion del destructor de la clase PreguntaAlt
    ~PreguntaAlt();
    //Declaracion de getters, setters y metodos
    vector<string> getOpciones();
    int getRespuestaCorrecta();
    void setRespuestaCorrecta(int respuestaCorrecta);
    void mostrarPregunta();
};

class Prueba {
private:
    vector<PreguntaVoF*> preguntasVF;
    vector<PreguntaAlt*> preguntasAlt;

public:
    //Se usa el push back para agregar elementos al final de un vector ya establecido
    void agregarVF(PreguntaVoF* p);
    void agregarAlternativa(PreguntaAlt* p);
    //Declaracion de metodo mostrar, que sirve para mostrar la cantidad de preguntas V y F en conjunto las de alternativas
    void mostrar();
    //Inicializacion del metodo calcularTiempoTotal, la
    //que va sumando los tiempos de cada pregunta y almacenando, dejando un total
    int calcularTiempoTotal();
    //Inicializacion de metodo buscarTaxonomia, la que entrega "true" si se encuentra y en el caso
    void buscarTaxonomia(string nivel);
    //Inicializaicon de metodo borrarVoF, la que elimina preguntas segun el
    //indice seleccionado
    void borrarVoF(int i);
    //Inicializacion de metodo borrarAlt, que borra las preguntas de alternativas segun el indice
    void borrarAlt(int i);
    //Inicializacion de metodo actualizarPreguntaVoF, la que actualiza preguntas
    //de verdadero y falso segun su indice
    void actualizarPreguntaVoF(int i);
    //Inicializacion metodo actualizarPreguntaAlt, actualizando segun su indice
    void actualizarPreguntaAlt(int i);
    ~Prueba();
    };
//Creacion de clase menu
class Menu {
private:
    int opcion;
    Prueba* prueba;
//Declaracion de metodo mostrarMenu()
public:
    Menu();
    void mostrarMenu();
    ~Menu();
};

#endif //CLASES_H
