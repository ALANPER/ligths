#include "semaforo.hpp"

int main() {
    button.rise(&start_timer);
    button.fall(&finish_timer);
    transition();
}
