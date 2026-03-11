#include "unity.h"

// Ces fonctions sont appelées avant et après CHAQUE test
void setUp(void) {
    // Optionnel : Initialisation si besoin
}

void tearDown(void) {
    // Optionnel : Nettoyage si besoin
}

void test_point_initialization(void){

}

// --- MAIN ---
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_point_initialization);


    return UNITY_END();
}