#ifndef FACTURACION_H
#define FACTURACION_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Facturacion;
}

class Facturacion : public QDialog
{
    Q_OBJECT

public:
    explicit Facturacion(QWidget *parent = nullptr);
    ~Facturacion();

    void setCedula(const QString &newCedula);
    void setNombre(const QString &newNombre);
    void setTelefono(const QString &newTelefono);
    void setDireccion(const QString &newDireccion);
    void setCorreo(const QString &newCorreo);
    void ingresoDatos(QString cedula, QString nombre, QString telefono, QString direccion , QString correo);

    void setProductos(const QString &newProductos);

private:
    Ui::Facturacion *ui;
    QString m_cedula;
    QString m_nombre;
    QString m_telefono;
    QString m_direccion;
    QString m_correo;
    QString m_productos;
    void mostrar();
    void facturacionPantalla();

};

#endif // FACTURACION_H
