#include "Proyectil.h"

const float ESCALA = 30.0f;

void Proyectil::Iniciar(b2World& mundo, Texture2D textura, float posX, float posY)
{
    this->textura = textura;
    lanzado = false;
    b2BodyDef definicion;
    definicion.type = b2_dynamicBody;
    definicion.position.Set(posX / ESCALA, posY / ESCALA);
    cuerpo = mundo.CreateBody(&definicion);

    b2CircleShape forma;
    forma.m_radius = radio / ESCALA;

    b2FixtureDef accesorio;
    accesorio.shape = &forma;
    accesorio.density = 1.0f;
    accesorio.friction = 0.6f;
    accesorio.restitution = 0.4f;
    cuerpo->CreateFixture(&accesorio);
}

void Proyectil::AplicarImpulso()
{
    if (lanzado) return;

    b2Vec2 impulso(15.0f, -40.0f);
    cuerpo->ApplyLinearImpulse(impulso, cuerpo->GetWorldCenter(), true);
    lanzado = true;
}

void Proyectil::Dibujar() const
{
    b2Vec2 posicion = cuerpo->GetPosition();
    float  angulo = cuerpo->GetAngle() * RAD2DEG;

    float pantallaX = posicion.x * ESCALA;
    float pantallaY = posicion.y * ESCALA;
    float diametro = radio * 2.0f;

    Rectangle origen = { 0, 0, (float)textura.width, (float)textura.height };
    Rectangle destino = { pantallaX, pantallaY, diametro, diametro };
    Vector2   centro = { diametro / 2.0f, diametro / 2.0f };

    DrawTexturePro(textura, origen, destino, centro, angulo, WHITE);
}