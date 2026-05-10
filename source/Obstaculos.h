#pragma once
#include "raylib.h"
#include <box2d.h>

class Obstaculos
{
public:
    void Iniciar(b2World& mundo, float x, float y, float ancho, float alto, Color color);
    void Dibujar() const;

private:
    b2Body* cuerpo = nullptr;
    float x, y, ancho, alto;
    Color color;
};