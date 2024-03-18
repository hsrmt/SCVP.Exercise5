#include <unistd.h>
#include <systemc.h>

#include "kpn.h"

void kpn::add_process() {
    while (true) {
        unsigned int a = fifo_a.read();
        unsigned int c = fifo_c.read();
        unsigned int b = a + c;
        fifo_b.write(b);
    }
}

void kpn::split_process() {
    int print_count = 0;
    while (print_count < 10) {
        unsigned int b = fifo_b.read();
        fifo_a.write(b);
        fifo_d.write(b);
        out_e.write(b);
        std::cout << "Split Output e: " << b << std::endl;
        print_count++;
        if (print_count >= 10) {
            sc_stop(); // Stop the simulation
        }
    }
}

void kpn::delay_process() {
    while (true) {
        unsigned int d = fifo_d.read();
        fifo_c.write(d);
    }
}

// sc_main remains in a separate file (main.cpp) as usual.
