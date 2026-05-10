#pragma once
#include "raylib.h"
#include <box2d.h>

class Proyectil
{
public:
    void Iniciar(b2World& mundo, Texture2D textura, float posX, float posY);
    void AplicarImpulso();
    void Dibujar() const;

private:
    b2Body* cuerpo = nullptr;
    Texture2D textura = {};
    float     radio = 30.0f;
    bool      lanzado = false;
};