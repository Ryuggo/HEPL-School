#include "FctUtilesAdministrateur.h"
#include <QMessageBox>

void WindowAdministrateur::setCommande(int i,const char *T)
{
if (T == NULL || strlen(T) == 0)
	{
	lineCommande[i]->clear();
	return;
	}
lineCommande[i]->setText(T);
return;
}

const char* WindowAdministrateur::getCommande(int i)const
{
char* Buff = (char*)malloc(255);
if (lineCommande[i]->text().size())
	{
	strcpy(Buff,lineCommande[i]->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

void WindowAdministrateur::setDisponible(int i,const char *T)
{
if (T == NULL || strlen(T) == 0)
	{
	lineDisponible[i]->clear();
	return;
	}
lineDisponible[i]->setText(T);
return;
}

const char* WindowAdministrateur::getDisponible(int i)const
{
char* Buff = (char*)malloc(255);
if (lineDisponible[i]->text().size())
	{
	strcpy(Buff,lineDisponible[i]->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

void WindowAdministrateur::setPersonnel(int i,const char *T)
{
if (T == NULL || strlen(T) == 0)
	{
	linePersonnel[i]->clear();
	return;
	}
linePersonnel[i]->setText(T);
return;
}
//void MainMagasin::setArticle3(const char* Text)
//{
//if (Text == NULL || strlen(Text) == 0 ) 
//   { 
//   ui->lineArticle3->clear();
//   return;
//   }
//ui->lineArticle3->setText(Text);
//return;
//}

const char* WindowAdministrateur::getPersonnel(int i)const
{
char* Buff = (char*)malloc(255);
if (linePersonnel[i]->text().size())
	{
	strcpy(Buff,linePersonnel[i]->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

void WindowAdministrateur::setSelectionCommande(const char *T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineSelectionCommande->clear();
	return;
	}
ui->lineSelectionCommande->setText(T);
return;
}

const char* WindowAdministrateur::getSelectionCommande()const
{
char* Buff = (char*)malloc(255);
if (ui->lineSelectionCommande->text().size())
	{
	strcpy(Buff,ui->lineSelectionCommande->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

void WindowAdministrateur::setNomCommande(const char *T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineNomCommande->clear();
	return;
	}
ui->lineNomCommande->setText(T);
return;
}

const char* WindowAdministrateur::getNomCommande()const
{
char* Buff = (char*)malloc(255);
if (ui->lineNomCommande->text().size())
	{
	strcpy(Buff,ui->lineNomCommande->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

void WindowAdministrateur::setSelectionPersonnel(const char *T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineSelectionPersonnel->clear();
	return;
	}
ui->lineSelectionPersonnel->setText(T);
return;
}

const char* WindowAdministrateur::getSelectionPersonnel()const
{
char* Buff = (char*)malloc(255);
if (ui->lineSelectionPersonnel->text().size())
	{
	strcpy(Buff,ui->lineSelectionPersonnel->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

const char* WindowAdministrateur::getCommandeN(int i) const
{
char* Buff = (char*)malloc(255);
if (lineCommandeN[i]->text().size())
	{
	strcpy(Buff,lineCommandeN[i]->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

int WindowAdministrateur::getCommandeT(int i) const
{
if (lineCommandeT[i]->text().size())
	{
	return atoi(lineCommandeT[i]->text().toStdString().c_str());
	}
return -1;
}

void WindowAdministrateur::MessageInformation(const char* T1,const char* T2)
{
QMessageBox::information(this,T1,T2);
      return;
 }
