#include "tienda.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QLocale>
#include <QMessageBox>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale location;
    QString text= location.languageToString(location.language());
    // Objeto para manejar las traducciones
       QTranslator traducion;
       if(text =="English"){
           traducion.load(":/tienda_en.qm");
       }else if (text == "French"){
           traducion.load(":/tienda_fr_FR.qm");
       }
       if((text != "English")&& (text != "French")&& (text!= "Spanish")){
           QMessageBox::warning(NULL,"Advertencia","No se encontro el idioma en su sitema,se usara uno por defecto");
       }
       if (text != QLocale::Spanish){
           a.installTranslator(&traducion);
       }
//       // Solicitando al usuario que seleccione un idioma
//       //QStringList idiomas;
//       //idiomas << "Francés" << "Inglés" << "Español";
//      // QString idiomaSeleccionado = QInputDialog::getItem(NULL,
//                                  //"Idioma",
//                                  "Seleccione un idioma",
//                                  idiomas);
//       // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
//       if (idiomaSeleccionado == "Francés"){
//           traducion.load(":/Calculadora_fr_FR.qm");
//       }else if (idiomaSeleccionado == "Inglés"){
//           traducion.load(":/Calculadora_en.qm");
//       }
//       // Si es diferente de español, se instala la traducción en TODA la aplicación
//       if (idiomaSeleccionado != "Español"){
//           a.installTranslator(&traducion);
//       }
//       // Muestra la ventana principal



    Tienda w;
    w.show();
    return a.exec();
}
