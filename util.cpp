
double deadband(double motorVal, double range = .2)
{
	if(motorVal > -1*range && motorVal < range)
	{
		motorVal = 0;
	}
	return motorVal;
}

double fence(double x)
{
	if(x < -1)
	{
		x = -1;
	} 
	else if(x > 1)
	{
		x = 1;
	}
	
	return x;
}
