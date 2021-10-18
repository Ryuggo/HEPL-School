void WindowSuiviCommande::setE1(int i,const char * T)
{
if (T == NULL || strlen(T) == 0)
	{
	ui->lineE1->clear();
	return;
	}
switch(i)
	{ 
	case 0:
		ui->lineE1->setText(T);
	break;
	case 1:
		ui->lineE2->setText(T);
	break;
	case 2:
		ui->lineE3->setText(T);
	break;
	case 3:
		ui->lineE4->setText(T);
	break;
	}
return;
}

void WindowSuiviCommande::setCheck(int i,bool b)
{
switch(i)
	{
	
	case 1 : 
		ui->checkBoxE2->setChecked(b);
		break;
	case 2 : 
		ui->checkBoxE3->setChecked(b);
		break;
	case 3 : 
		ui->checkBoxE4->setChecked(b);
		break;
	case 0 : 
		ui->checkBoxE1->setChecked(b);
		break;
	case 5 : 
		ui->checkBoxLivraison->setChecked(b);
		break;
	}
}
