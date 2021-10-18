
void windowFenetrePersonnel::setE1(const char * T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineE1->clear();
	return;
	}
ui->lineE1->setText(T);

return;
}
void windowFenetrePersonnel::setE2(const char * T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineE2->clear();
	return;
	}
ui->lineE2->setText(T);
}
void windowFenetrePersonnel::setE3(const char * T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineE3->clear();
	return;
	}
ui->lineE3->setText(T);
}
void windowFenetrePersonnel::setE4(const char * T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineE4->clear();
	return;
	}
ui->lineE4->setText(T);
}
void windowFenetrePersonnel::setNomC(const char * T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->label->clear();
	return;
	}
ui->label->setText(T);
}

void windowFenetrePersonnel::setCheck(int i,bool b)
{
switch(i)
	{
	
	case 1 : 
		ui->checkBox2->setChecked(b);
		break;
	case 2 : 
		ui->checkBox3->setChecked(b);
		break;
	case 3 : 
		ui->checkBox4->setChecked(b);
		break;
	case 0 : 
		ui->checkBox1->setChecked(b);
		break;
	}
}
