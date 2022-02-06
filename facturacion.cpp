#include "facturacion.h"
#include "ui_facturacion.h"

Facturacion::Facturacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Facturacion)
{
    ui->setupUi(this);
}

Facturacion::~Facturacion()
{
    delete ui;
}

void Facturacion::setCedula(const QString &newCedula)
{
    m_cedula = newCedula;
}

void Facturacion::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

void Facturacion::setTelefono(const QString &newTelefono)
{
    m_telefono = newTelefono;
}

void Facturacion::setDireccion(const QString &newDireccion)
{
    m_direccion = newDireccion;
}

void Facturacion::setCorreo(const QString &newCorreo)
{
    m_correo = newCorreo;
}

void Facturacion::ingresoDatos(QString cedula, QString nombre, QString telefono, QString direccion, QString correo)
{
    setCedula(cedula);
    setNombre(nombre);
    setTelefono(telefono);
    setDireccion(direccion);
    setCorreo(correo);
    mostrar();

}

void Facturacion::setProductos(const QString &newProductos)
{
    m_productos = newProductos;
}

void Facturacion::totales(QString subTotal, QString IVA, QString total)
{
    QString formato = "";
    formato += "\nSubtotal: " + subTotal + "\n" + "IVA: "  + IVA + "\n" + "Total: " + total;
    ui->outDatos->appendPlainText(formato);
}

void Facturacion::mostrar()
{
    facturacionPantalla();


}

void Facturacion::facturacionPantalla()
{
    QString data = "";
    QString titulo = "\t********************************************\n\t\tHOY NO FIO MAÑANA SI\n"
                     "\t********************************************\n"
                     "\tRUC:999999999\n"
                     "\t"+tr("Direccion")+": Av.Condor Ñan y Rumiñaca Ñan\n\tQuito 58\n"
                     "\t"+tr("Numero")+": (02) 314-2212\n"
                     "\t********************************************\n"
                     "\t\t - -"+tr ("DATOS CLIENTE")+ "- - \n"
                     "\t********************************************\n";
data = titulo;
    if(m_cedula!="999999999"){
        QString nombre = "\t"+tr("Nombre")+": " + m_nombre + "\n";
        QString cedula = "\t"+tr("Cedula")+": " + m_cedula + "\n";
        QString telefono = "\t"+tr("Telefono")+": " + m_telefono + "\n";
        QString correo = "\t"+tr("E-mail")+": " + m_correo + "\n";
        QString direccion = "\t"+tr("Direccion")+": " + m_direccion + "\n";
                                                         "\t*************************************\n";
        data+=nombre+cedula+telefono+correo+direccion+"\n"+"\n";

    }
    else{
        QString  add = "\t\t"+tr("CONSUMIDOR FINAL")+"\n\n\t**********************************************\n";
        data= add;

    }
    QString pro;
    pro= "\t"+tr("Cantidad")+"\t"+tr("Producto")+"\t"+tr("P.Unitario")+"\t"+tr("SubTotal")+"\n" + m_productos;
    data+=pro;
    ui->outDatos->setPlainText(data);

}

void Facturacion::on_buttonBox_accepted()
{
    QString fecha = QDateTime::currentDateTime().toString("ddMMyyyy");
        QFile archivo (fecha+".txt");
        if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
            QTextStream datos_Archivo(&archivo);
            datos_Archivo<<ui->outDatos->toPlainText();

        }

        archivo.close();
}

