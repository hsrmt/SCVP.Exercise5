#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn)
{
private:
    // ADD THINGS HERE
    sc_fifo<unsigned int> fifo_a, fifo_b, fifo_c, fifo_d;
    sc_signal<unsigned int> internal_e_signal;
    // Output port for the Split process to output signal e

    // Internal SC_THREAD processes
    void add_process();
    void split_process();
    void delay_process();
public:
    sc_out<unsigned int> out_e;


    SC_CTOR(kpn):fifo_a(10), fifo_b(10), fifo_c(10), fifo_d(10), out_e("out_e") // : ADD THINGS HERE
    {
        // ADD THINGS HERE
                // Initialize the FIFOs with starting values
        fifo_b.write(1);
        fifo_c.write(0);

        // Register the SC_THREAD processes
        SC_THREAD(add_process);
        SC_THREAD(split_process);
        SC_THREAD(delay_process);

        out_e(internal_e_signal);
    }
};

#endif // KPN_H
