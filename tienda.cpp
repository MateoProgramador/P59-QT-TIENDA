#include "tienda.h"
#include "ui_tienda.h"

Tienda::Tienda(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tienda)
{
    ui->setupUi(this);
    //Lista de productos
    cargarProductos();
    //Mostrar productos en el combo
    foreach (Producto *p , m_producto){
        ui->inProducto->addItem(p->nombre());
    }
    //Configurar cabecera de la tabla
    QStringList cabecera = {"Cantidad","Producto","Subtotal"};
    ui->outDetalle->setColumnCount(3);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);

}

Tienda::~Tienda()
{
    delete ui;
}
/**
 * @brief Tienda::cargarProductos Cargar la lista de productos de la tienda
 */
void Tienda::cargarProductos()
{
    //Crear productos QUEMADOS en el codigo
    m_producto.append(new Producto(1,"Leche",0.80));
    m_producto.append(new Producto(2,"Pan",0.15));
    m_producto.append(new Producto(3,"Queso",2.50));
}
