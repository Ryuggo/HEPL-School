void WindowTableauAffichage::setCommande(int i,const char *T)
{
if (!strlen(T))
	{
	lineCommande[i]->clear();
	return;
	}
lineCommande[i]->setText(T);
return;
}

const char* WindowTableauAffichage::getCommande(int i)const
{
char* Buff = (char*)malloc(255);
if (lineCommande[i]->text().size())
	{
	strcpy(Buff,lineCommande[i]->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

void WindowTableauAffichage::setPersonnel(int i,const char *T)
{
if (!strlen(T))
	{
	linePersonnel[i]->clear();
	return;
	}
linePersonnel[i]->setText(T);
return;
}

const char* WindowTableauAffichage::getPersonnel(int i)const
{
char* Buff = (char*)malloc(255);
if (linePersonnel[i]->text().size())
	{
	strcpy(Buff,linePersonnel[i]->text().toStdString().c_str());
	return Buff;
	}
return NULL;
}

void WindowTableauAffichage::setEtat(int i,const char *T)
{
if (!strlen(T))
	{
	labelEtat[i]->clear();
	return;
	}
labelEtat[i]->setText(T);
return;
}

