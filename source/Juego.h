#pragma once
#include "raylib.h"
#include <box2d.h>
#include <vector>
#include "Proyectil.h"
#include "Obstaculos.h"

class Juego
{
public:
    void Iniciar();
    void Actualizar();
    void Dibujar();
    void Cerrar();
    void Reiniciar();
    bool DebeTerminar() const;

private:
    void CrearParedes();

    static const int ANCHO_PANTALLA = 1000;
    static const int ALTO_PANTALLA = 600;

    b2World   mundo{ b2Vec2(0.0f, 9.8f) };
    Texture2D texCatapulta = {};
    Texture2D texVoltorb = {};
    Proyectil voltorb;
    std::vector<Obstaculos> obstaculos;

    Color colorFondo = { 110, 100, 215, 255 };
    Color colorTextoPrincipal = RAYWHITE;
    Color colorTextoSecundario = DARKPURPLE;
    Color colorSuelo = {};

    Sound gritoVoltorb = {};
    Music musicaTetris = {};
    bool sonidoReproducido = false;
};
