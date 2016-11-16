void U()
{
	for (int i=0;i<3;i++)
	{
		temp[i]=front[0][i];
	}
	for (int i=0;i<3;i++)
	{
		front[0][i]=le[0][i];
		le[0][i]=back[0][i];
		back[0][i]=ri[0][i];
		ri[0][i]=temp[i];
	}
}

void UI()
{
	for (int i=0;i<3;i++)
	{
		temp[i]=front[0][i];
	}
	for (int i=0;i<3;i++)
	{
		front[0][i]=ri[0][i];
		ri[0][i]=back[0][i];
		back[0][i]=le[0][i];
		le[0][i]=temp[i];
	}
}
