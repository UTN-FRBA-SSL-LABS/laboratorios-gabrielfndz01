#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

void test_compra_con_descuento(void) {
    printf("\n[integracion: compra con descuento]\n");
    Carrito c;
    carrito_init(&c);

    Producto pan = {"Pan", 200, 3};
    carrito_agregar(&c, pan);

    Producto leche = {"Leche", 350, 2};
    carrito_agregar(&c, leche);

    int total = carrito_total(&c);
    
    /* Verificamos el total esperado de 1300 */
    ASSERT_IGUAL(1300, total);
    
    /* Verificamos que con 10% de descuento sea 1170 */
    ASSERT_IGUAL(1170, carrito_descuento(total, 10));
}

/* PARTE E */
void test_agregar_hasta_llenar(void) {
    printf("\n[integracion: agregar hasta llenar limite]\n");
    Carrito c;
    carrito_init(&c);

    Producto p = {"Queso", 1500, 1};

    /* 1. Llenar el carrito hasta su capacidad máxima (4 productos) */
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);

    /* 2. Verificar que el conteo es MAX_ITEMS (4) */
    ASSERT_IGUAL(4, carrito_contar(&c));

    /* 3. Verificar que intentar agregar uno más devuelve 0 */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));

    /* 4. Verificar que el conteo sigue siendo MAX_ITEMS (no cambió) */
    ASSERT_IGUAL(4, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    test_compra_con_descuento(); 
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
