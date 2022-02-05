#ifndef TIENDA_H
#define TIENDA_H

#include <QMainWindow>

#include "producto.h"
#include "facturacion.h"
#include "acerca.h"

#define IVA 12

QT_BEGIN_NAMESPACE
namespace Ui { class Tienda; }
QT_END_NAMESPACE

class Tienda : public QMainWindow
{
    Q_OBJECT

public:
    Tienda(QWidget *parent = nullptr);
    ~Tienda();

private slots:
    void on_inProducto_currentIndexChanged(int index);

    void on_btnAgregar_released();

    void on_Finalizar_released();

    void on_btnLimpiar_released();

    void on_actionAcerca_de_triggered();

private:
    Ui::Tienda *ui;
    QList<Producto*> m_productos;
    void cargarProductos();
    float m_subtotal;
    void calcular(float stProducto);
    bool verificacionCedula(QString as);
    bool campos();
    void limpiar();


};
#endif // TIENDA_H
