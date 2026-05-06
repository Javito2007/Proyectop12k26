#ifndef BANCOS_H
#define BANCOS_H
#include <string>


class Bancos
{
    public:
        Bancos();
        virtual ~Bancos();
        bool InfoTransferencia(std::string nombreBanco, std::string nombreCliente, int numeroTarjeta);
        bool InfoPagoPlanilla(std::string nombreBanco, std::string nombreCliente, int numeroCuenta);
        bool procesoTransferencia(int numeroTarjeta, double monto, double saldoCuenta);
        bool procesoPagoPlanilla(int numeroCuenta, double montoPago, double saldoCuenta);
    protected:

    private:
        std::string titularCuenta;
        double saldo;
        int idCuenta;


};

#endif // BANCOS_H
