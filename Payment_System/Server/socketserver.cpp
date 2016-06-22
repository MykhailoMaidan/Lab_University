#include "socketserver.h"
#include <QString>


SocketServer::SocketServer()
{


}
void SocketServer::InitializeSocket() // start initialize socket
{
    if(WSAStartup(MAKEWORD(2,2), &wsdata)<0)
    {
        qDebug() << "Initialize error...";
    }

}

void SocketServer::BindSocket() // bind socket
{
    if((ServerSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))<0)
    {
        qDebug() << "Socket error...";
    }
     ServerAddr.sin_family = AF_INET;
     ServerAddr.sin_port = htons(7777);
     ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
     if(bind(ServerSocket, (LPSOCKADDR) &ServerAddr, sizeof(ServerAddr))<0)
     {
         qDebug() << "Bind error...";
     }
}

void SocketServer::ListhenSocket() // socket starts lithen
{
    if(listen(ServerSocket,SOMAXCONN)<0)
    {
        qDebug() << "Listhen error...";
    }
}

void SocketServer::AcceptSocket() // sokcet begin accept
{
    int sizeServerAddr = sizeof(ServerAddr);
while(1){
        if((ClientSocket = accept(ServerSocket,(struct sockaddr*)&ServerAddr, &sizeServerAddr))<0)
        {
        qDebug() << "Accept error...";
        }
        if(ClientSocket <= 0)
        {

               qDebug() << "Client not connect...";

        }
        else
         ProcessingClient();

}
}

void SocketServer::ProcessingClient()
{
     char buff[100];
     while(1)
     {
     memset(buff,0,sizeof(buff));
     if(recv(ClientSocket,buff, sizeof(buff),0) < 0)//
     {
         qDebug() << "recv error";
     }
     qDebug() << buff;
    if(strcmp(buff,"Water") == false)
    {
        while(1)
        {

        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)//
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менше, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE water set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from Water where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "The price for services:" +  query_socket->value(3).toString() + '-' + "Arrears:" + query_socket->value(4).toString();
                qDebug () << info;
                number = query_socket->value(4).toString();
                cout ++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }else
        {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }



    }
        }
    }
    else if(strcmp(buff,"Gas") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE gass set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout= 0;
            query_socket->exec("select* from gass where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "The price for services:" +  query_socket->value(3).toString() + '-' + "Arrears:" + query_socket->value(4).toString();
                qDebug () << info;
                number = query_socket->value(4).toString();
                cout++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }

    }
    }
    else if(strcmp(buff,"Power") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE power set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from power where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "The price for services:" +  query_socket->value(3).toString() + '-' + "Arrears:" + query_socket->value(4).toString();
                qDebug () << info;
                number = query_socket->value(4).toString();
                cout++;

            }


        if(cout < 1)
        {
            if(send(ClientSocket,"0",2,0))
            {

            }
        }else
        {
        if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
        {

        }
        }
        }
        }
    }
else if(strcmp(buff,"rubish") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE rubbish set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from rubbish where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "Arrears:" + query_socket->value(3).toString();
                qDebug () << info;
                number = query_socket->value(3).toString();
                cout++;
            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }
            else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }
        }

    }
    else if(strcmp(buff,"intercom") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE intercom set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from intercom where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "Arrears:" + query_socket->value(3).toString();
                qDebug () << info;
                number = query_socket->value(3).toString();
                cout++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }
            else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }
        }

    }
    else if(strcmp(buff,"internet") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE internet set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout= 0;
            query_socket->exec("select* from internet where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' +
                       "Arrears:" + query_socket->value(2).toString();
                qDebug () << info;
                number = query_socket->value(3).toString();
                cout++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }
            else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }
        }

    }
    else if(strcmp(buff,"lift") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE elevator set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from elevator where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "Arrears:" + query_socket->value(3).toString();
                qDebug () << info;
                number = query_socket->value(3).toString();
                cout++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }
            else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }
        }

    }
    else if(strcmp(buff,"phone") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE phone set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from phone where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "The price for services:" +  query_socket->value(3).toString() + '-' + "Arrears:" + query_socket->value(4).toString();
                qDebug () << info;
                number = query_socket->value(4).toString();
                cout++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }
        }

    }
    else if(strcmp(buff,"heating") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE heating set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from heating where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                      "The price for services:" +  query_socket->value(3).toString() + '-' + "Arrears:" + query_socket->value(4).toString();
                qDebug () << info;
                number = query_socket->value(4).toString();
                cout++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }
        }

    }
    else if(strcmp(buff,"rent") == false)
    {
        while(1)
        {
        memset(buf_data_user , 0 , sizeof(buf_data_user));
        if(recv(ClientSocket,buf_data_user,200,0) <0 )
        {
            qDebug() << "recv error...";
        }
        if(strcmp(buf_data_user,"close") == false )
        {
            break;
        }
        else if(strcmp(buf_data_user,"pay") == false)
        {
            double ran;
            QString buff;
            double d;
            memset(buf_data_user,0,sizeof(buf_data_user));
            if(recv(ClientSocket,buf_data_user,200,0) <0 )
            {
                qDebug() << "recv error...";
            }

            if(atof(number.toStdString().c_str()) > atof(buf_data_user) )
            {
                 ran = atof(number.toStdString().c_str()) -  atof(buf_data_user);
                 QString tem = "Ви оплатили менеш, ваш борг:"  + QString::number(atof(number.toStdString().c_str()) -  atof(buf_data_user));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else if(atof(number.toStdString().c_str()) == atof(buf_data_user))
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ви погасили борг:" ;
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }
            }
            else
            {
                buff = "Дякую що заплатили ";
                ran  = 0;
                QString tem = "Ваша здача:" + QString::number(atof(buf_data_user) - atof(number.toStdString().c_str()));
                if(send(ClientSocket,tem.toStdString().c_str(),100,0))
                {

                }

            }

            query_socket->exec("UPDATE rent set Pay = " + QString::number(ran) + ";");
        }
        else
        {
            info.clear();
            int cout = 0;
            query_socket->exec("select* from rent where Number ='" +   QString(buf_data_user) +
                               "'");
            while(query_socket->next())
            {
               info += "Сontract number:" + query_socket->value(0).toString() + '-' +
                       "User name:" + query_socket->value(1).toString() + '-' + "Address:" + query_socket->value(2).toString() + '-' +
                       "The price for services:" +  query_socket->value(3).toString() + '-' + "Arrears:" + query_socket->value(4).toString();
                qDebug () << info;
                number = query_socket->value(4).toString();
                cout++;

            }
            if(cout < 1)
            {
                if(send(ClientSocket,"0",2,0))
                {

                }
            }else
            {
            if(send(ClientSocket,info.toStdString().c_str(),info.length()+1,0))
            {

            }
            }
        }
        }

    }
    else if(strcmp(buf_data_user,"close") == false)
    {
        break;
     }
}
}





void SocketServer::DBtoSock(QSqlDatabase *obj)
{
    db = obj;
    query_socket = new QSqlQuery(*db);
}


