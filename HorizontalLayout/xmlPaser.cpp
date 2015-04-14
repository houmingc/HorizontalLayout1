#include <iostream>
#include <QtXml>
#include <QFile>

QStringList xmlID;
QStringList xmlName;
QStringList xmlValue;



int xmlPaser()
{

    QDomDocument xmlBOM;

    QFile f("/opt/imx6.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        std::cerr << "Error while loading file" << std::endl;
        return 1;
    }
    xmlBOM.setContent(&f);
    f.close();

    QDomElement root=xmlBOM.documentElement();
    QString Type=root.tagName();
    QString Board=root.attribute("BOARD","No name");
    int Year=root.attribute("YEAR","1900").toInt();

    std::cout << "Type  = " << Type.toStdString().c_str() << std::endl;
    std::cout << "Board = " << Board.toStdString() << std::endl;
    std::cout << "Year  = " << Year << std::endl;
    std::cout << std::endl;

    QDomElement Component=root.firstChild().toElement();


    while(!Component.isNull())
    {

        if (Component.tagName()=="Component")
        {
            xmlID<<Component.attribute("ID","No ID");
            QDomElement Child=Component.firstChild().toElement();


            while (!Child.isNull())
            {
                if (Child.tagName()=="Name") xmlName<<Child.firstChild().toText().data();
                if (Child.tagName()=="Value") xmlValue<<Child.firstChild().toText().data();
                Child = Child.nextSibling().toElement();
            }
        }
        Component = Component.nextSibling().toElement();
    }



    return 0;
}
