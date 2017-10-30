typedef enum color_e{
  COLOR_ROJO,
  COLOR_VERDE,
  COLOR_AMARILLO,
  COLOR_NEGRO,
  COLOR_AZUL
}color_t;

typedef enum tipo_e{
  TIPO_PLUS2,
  TIPO_PLUS4,
  TIPO_SALTO,
  TIPO_REVERTIR,
  TIPO_NUMERO,
  TIPO_CAMBIO
}tipo_t;

typedef struct card_s{
  tipo_t tipo;
  color_t color;
  int valor;
}card_t;

void mostrar_carta(card_t* c);
