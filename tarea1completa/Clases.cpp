//
// Created by jqnfu on 11-04-2025.
//

#include "ClasesS.h"

//Metodos de clase Pregunta

Pregunta::Pregunta(string enunciado, int tiempoEstimado, string taxonomia) {
    this->enunciado = enunciado;
    this->tiempoEstimado = tiempoEstimado;
    this->taxonomia = taxonomia;
}
//Inicializacion del destructor de la clase Pregunta
Pregunta::~Pregunta() {
    cout << "Destruyendo clase de tipo pregunta" << endl;
}
//Inicializacion de getters y setters de la clase Pregunta
string Pregunta::getEnunciado() {
    return this->enunciado;
}
void Pregunta::setEnunciado(string enunciado) {
    this->enunciado = enunciado;
}
int Pregunta::getTiempoEstimado() {
    return this->tiempoEstimado;
}
void Pregunta::setTiempoEstimado(int tiempoEstimado) {
    this->tiempoEstimado = tiempoEstimado;
}
string Pregunta::getTaxonomia() {
    return this->taxonomia;
}
void Pregunta::setTaxonomia(string taxonomia) {
    this->taxonomia = taxonomia;
}

//Inicializacion de metodo mostrarPregunta de la clase Pregunta
void Pregunta::mostrarPregunta() {
    cout << "Pregunta:\n" << getEnunciado() << endl;
    cout << "Nivel de Bloom: " << getTaxonomia() << endl;
    cout << "Tiempo: " << getTiempoEstimado() << " min\n\n";
}

//Metodos de clase Pregunta Verdadero o Falso

PreguntaVoF::PreguntaVoF(string enunciado, int tiempoEstimado, string taxonomia, bool respuestaCorrecta, string justificacion)
    : Pregunta(enunciado, tiempoEstimado, taxonomia) {
    this->respuestaCorrecta = respuestaCorrecta;
    this->justificacion = justificacion;
}

//Inicializacion de getters, setters y metodo
bool PreguntaVoF::getRespuestaCorrecta() {
    return this->respuestaCorrecta;
}

void PreguntaVoF::setRespuestaCorrecta(bool respuestaCorrecta) {
    this->respuestaCorrecta = respuestaCorrecta;
}

string PreguntaVoF::getJustificacion() {
    return this->justificacion;
}

void PreguntaVoF::setJustificacion(string justificacion) {
    this->justificacion = justificacion;
}

void PreguntaVoF::mostrarPregunta() {
    cout << "Pregunta Verdadero o Falso:\n" << getEnunciado() << endl;
    if (respuestaCorrecta == true) {
        cout<<"Respuesta: Verdadero"<<endl;
    }
    else if (respuestaCorrecta == false) {
        cout<<"Respuesta: Falso"<<endl;
    }
    cout << "Justificacion: " << justificacion << endl;
    cout << "Nivel de Bloom: " << getTaxonomia() << endl;
    cout << "Tiempo: " << getTiempoEstimado() << " min\n\n";
}

//Metodos de clase Preguntas Alternativas

//Inicializacion de constructor de clase PreguntaAlt con uso de herencia de clase Pregunta
PreguntaAlt::PreguntaAlt(string enunciado, int tiempoEstimado, string taxonomia, vector<string> opciones, int respuestaCorrecta)
    : Pregunta(enunciado, tiempoEstimado, taxonomia) {
    this->opciones = opciones;
    this->respuestaCorrecta = respuestaCorrecta;
}

//Destructor de clase PreguntaAlt
PreguntaAlt::~PreguntaAlt() {
    cout << "Destruyendo Pregunta de Alternativas" << endl;
}

//Inicializacion de getters, setters y metodo
vector<string> PreguntaAlt::getOpciones() {
    return this->opciones;
}
int PreguntaAlt::getRespuestaCorrecta() {
    return this->respuestaCorrecta;
}
void PreguntaAlt::setRespuestaCorrecta(int respuestaCorrecta) {
    this->respuestaCorrecta = respuestaCorrecta;
}
void PreguntaAlt::mostrarPregunta() {
    cout << "Pregunta de Alternativas:\n" << getEnunciado() << endl;
    cout << "\nOpciones:\n";
    for (size_t i = 0; i < opciones.size(); ++i) {
        char letra = 'A' + i; //Se usa esta denominación para mostrar las alternativas con su letra respectiva
        cout << "  " << letra << ") " << opciones[i];
        if ((int)i == respuestaCorrecta)
            cout << "  <-- Correcta";
        cout << "\n";
    }
    cout << "Nivel de Bloom: " << getTaxonomia() << endl;
    cout << "Tiempo: " << getTiempoEstimado() << " min\n\n";
} //Se usa un ciclo for para recorrer y agregar las alternativas que el usuario requiera e indicar la respuesta correcta

//Metodos de clase Prueba

void Prueba::agregarVF(PreguntaVoF* p) {
    preguntasVF.push_back(p);
}

void Prueba::agregarAlternativa(PreguntaAlt* p) {
    preguntasAlt.push_back(p);
}

void Prueba::mostrar() {
    int num = 1;   //enumera las preguntas y con num++ va aumentando respecto a la cantidad de preguntas
    for (PreguntaVoF* p : preguntasVF) {
        cout << num++ << ". ";
        p->mostrarPregunta();
    }
    for (PreguntaAlt* p : preguntasAlt) {
        cout << num++ << ". ";
        p->mostrarPregunta();
    }
}

    //Inicializacion del metodo calcularTiempoTotal, la
    //que va sumando los tiempos de cada pregunta y almacenando, dejando un total
int Prueba::calcularTiempoTotal() {
        int total = 0;
        for (PreguntaVoF* p : preguntasVF) //recorre todas las preguntasVF para calcular su tiempo
            total += p->getTiempoEstimado();
        for (PreguntaAlt* p : preguntasAlt) //recorre todas las preguntasAlt para calcular su tiempo
            total += p->getTiempoEstimado();
        return total;
    }

    //Inicializacion de metodo buscarTaxonomia, la que entrega "true" si se encuentra y en el caso
    //contrario entrega un mensaje en consola
void Prueba::buscarTaxonomia(string nivel) {
        bool encontrado = false;
        for (PreguntaVoF* p : preguntasVF) {
            if (p->getTaxonomia() == nivel) {
                p->mostrarPregunta();
                encontrado = true;
            }
        }
        for (PreguntaAlt* p : preguntasAlt) {
            if (p->getTaxonomia() == nivel) {
                p->mostrarPregunta();
                encontrado = true;
            }
        }
        if (!encontrado)
            cout << "No se encontraron preguntas con ese nivel taxonomico.\n";
    }

    //Inicializaicon de metodo borrarVoF, la que elimina preguntas segun el
    //indice seleccionado
void Prueba::borrarVoF(int i) {
        if (i >= 0 && i < preguntasVF.size()) {
            delete preguntasVF[i]; //borra el objeto
            preguntasVF.erase(preguntasVF.begin() + i); //borra el vector
            cout << "Pregunta de Verdadero o Falso eliminada correctamente.\n";
        } else {
            cout << "Indice invalido.\n";
        }
    }
    //Inicializacion de metodo borrarAlt, que borra las preguntas de alternativas segun el indice
void Prueba::borrarAlt(int i) {
        if (i >= 0 && i < preguntasAlt.size()) {
            delete preguntasAlt[i]; //borra el objeto
            preguntasAlt.erase(preguntasAlt.begin() + i);//borra el vector
            cout << "Pregunta de alternativas eliminada correctamente.\n";
        } else {
            cout << "Indice invalido.\n";
        }
    }

    //Inicializacion de metodo actualizarPreguntaVoF, la que actualiza preguntas
    //de verdadero y falso segun su indice
    //Se hace uso de getline: lee una cadena de texto incluyendo espacios, a diferencia de cin la cual soporta una palabra
    //y cin.ignore:limpia el buffer de entrada del cin, limpiando el salto de linea sobrante para evitar errores
void Prueba::actualizarPreguntaVoF(int i) {
        if (i < 0 || i >= preguntasVF.size()) {
            cout << "Indice invalido.\n";
            return;
        }

        string enunciado, justificacion, nivel;
        char respuestaChar;
        int tiempo;

        cin.ignore();
        cout << "Nuevo enunciado: ";
        getline(cin, enunciado);
        preguntasVF[i]->setEnunciado(enunciado);

        cout << "Nueva respuesta correcta (V/F): ";
        cin >> respuestaChar;
        preguntasVF[i]->setRespuestaCorrecta(respuestaChar == 'V' || respuestaChar == 'v');

        cin.ignore();
        cout << "Nueva justificacion: ";
        getline(cin, justificacion);
        preguntasVF[i]->setJustificacion(justificacion);

        cout << "Nuevo nivel de Bloom: ";
        getline(cin, nivel);
        preguntasVF[i]->setTaxonomia(nivel);

        cout << "Nuevo tiempo estimado (min): ";
        cin >> tiempo;
        preguntasVF[i]->setTiempoEstimado(tiempo);
    }

    //Inicializacion metodo actualizarPreguntaAlt
void Prueba::actualizarPreguntaAlt(int i) {
        if (i < 0 || i >= preguntasAlt.size()) {
            cout << "Indice invalido.\n";
            return;
        }
        string enunciado, taxonomia;
        int tiempo, nOpciones, correcta;
        vector<string> opciones;

        cin.ignore();
        cout << "Nuevo enunciado: ";
        getline(cin, enunciado);
        preguntasAlt[i]->setEnunciado(enunciado);

        cout << "Nuevo tiempo estimado (minutos): ";
        cin >> tiempo;
        preguntasAlt[i]->setTiempoEstimado(tiempo);
        cin.ignore();

        cout << "Nuevo nivel taxonomico: ";
        getline(cin, taxonomia);
        preguntasAlt[i]->setTaxonomia(taxonomia);

        cout << "Numero de opciones: ";
        cin >> nOpciones;cin.ignore();

        opciones.clear();  // Elimina las opciones anteriores
        for (int i = 0; i < nOpciones; ++i) {
            string op;
            cout << "Opcion " << (char)('A' + i) << ": ";
            getline(cin, op);
            opciones.push_back(op);
        }

        preguntasAlt[i]->getOpciones() = opciones;
        cout << "Indice de la respuesta correcta (0 a " << nOpciones - 1 << "): ";
        cin >> correcta;
        preguntasAlt[i]->setRespuestaCorrecta(correcta);
        cin.ignore();
    }

    //Inicializacion de destructor de la clase Prueba
    //eliminando asi las preguntas de verdadero y falso + alternativas
    Prueba::~Prueba() {
        for (PreguntaVoF* p : preguntasVF) {
            delete p;
        }
        for (PreguntaAlt* p : preguntasAlt) {
            delete p;
        }
    }

//Metodos de clase Menu

Menu::Menu() {
    prueba = new Prueba();
}
void Menu::mostrarMenu() {
        do {
            cout << "\n ||||||| MENU ||||||  \n";
            cout << "1. Agregar pregunta Verdadero/Falso\n";
            cout << "2. Agregar pregunta de Alternativas\n";
            cout << "3. Mostrar todas las preguntas\n";
            cout << "4. Buscar preguntas por nivel taxonomico\n";
            cout << "5. Calcular tiempo total de la evaluacion\n";
            cout << "6. Borrar item\n";
            cout << "7. Actualizar item\n";
            cout << "0. Salir del programa\n";
            cout << "Seleccione opcion: ";
            cin >> opcion;
            cin.ignore();

            //Opciones del menu con sus respectivos if, while, for, cin, cout y llamadas a metodos
            if (opcion == 1) {
                string enunciado, taxonomia, justificacion;
                char respuesta;
                int tiempo;

                cout << "Enunciado: ";
                getline(cin, enunciado);
                cout << "Respuesta correcta (V/F): ";
                cin >> respuesta;
                cin.ignore();
                cout << "Justificacion: ";
                getline(cin, justificacion);
                cout << "Nivel de Bloom: ";
                getline(cin, taxonomia);
                cout << "Tiempo estimado (min): ";
                cin >> tiempo;
                cin.ignore();

                bool esVerdadero = (respuesta == 'V' || respuesta == 'v'); //¿
                PreguntaVoF* p = new PreguntaVoF(enunciado, tiempo, taxonomia, esVerdadero, justificacion); //para la creacion de nuevas preguntas mediante new
                prueba->agregarVF(p);
            }

            else if (opcion == 2) {
                string enunciado, taxonomia;
                int tiempo, nOpciones, correcta;
                vector<string> opciones;

                cout << "Enunciado: ";
                getline(cin, enunciado);
                cout << "Numero de opciones: ";
                cin >> nOpciones;
                cin.ignore();

                for (int i = 0; i < nOpciones; ++i) {
                    string opcion;
                    cout << "Opcion " << (char)('A' + i) << ": ";
                    getline(cin, opcion);
                    opciones.push_back(opcion);
                }

                cout << "Indice de la correcta (0 a " << nOpciones - 1 << "): ";
                cin >> correcta;
                cin.ignore();
                cout << "Nivel de Bloom: ";
                getline(cin, taxonomia);
                cout << "Tiempo estimado (min): ";
                cin >> tiempo;
                cin.ignore();

                PreguntaAlt* p = new PreguntaAlt(enunciado, tiempo, taxonomia, opciones, correcta); //para la creacion de nuevas preguntas mediante new
                prueba->agregarAlternativa(p);
            }

            else if (opcion == 3) {
                prueba->mostrar();
            }

            else if (opcion == 4) {
                string nivel;
                cout << "Nivel a buscar: ";
                getline(cin, nivel);
                prueba->buscarTaxonomia(nivel);
            }

            else if (opcion == 5) {
                cout << "Tiempo total estimado: " << prueba->calcularTiempoTotal() << " minutos\n";
            }


            else if (opcion == 6) {
                int tipo, i;
                cout << "¿Que tipo de pregunta desea borrar? (1 para Verdadero/Falso, 2 para Alternativa): ";
                cin >> tipo;
                cin.ignore();

                if (tipo == 1) {
                    prueba->mostrar(); // Opcional, para que vea los índices
                    cout << "Ingrese el indice de la pregunta Verdadero/Falso a eliminar (comienza con 0): ";
                    cin >> i;
                    prueba->borrarVoF(i);
                } else if (tipo == 2) {
                    prueba->mostrar(); // Opcional
                    cout << "Ingrese el indice de la pregunta de alternativas a eliminar (comienza con 0): ";
                    cin >> i;
                    prueba->borrarAlt(i);
                } else {
                    cout << "Tipo invalido.\n";
                }
            }

            else if (opcion == 7) {
                int tipo, i;
                cout << "¿Que tipo de pregunta desea actualizar? (1 para Verdadero/Falso, 2 para Alternativa): ";
                cin >> tipo;
                cout << "Indice de la pregunta a actualizar (comienza con 0): ";
                cin >> i;

                if (tipo == 1) {
                    prueba->actualizarPreguntaVoF(i);
                } else if (tipo == 2) {
                    prueba->actualizarPreguntaAlt(i);
                } else {
                    cout << "Tipo invalido.\n";
                }
            }
        } while (opcion != 0);
    }

    //Inicializacion del destructor de clase Menu
    Menu::~Menu() {
        delete prueba;
    }
;
