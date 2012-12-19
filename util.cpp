
double deadband(double motorVal, double range = .2)
{
	if(motorVal > -1*range && motorVal < range)
	{
		motorVal = 0;
	}
	return motorVal;
}

double fence(double x, double upper = 1, double lower = -1)
{
	if(x < lower)
	{
		x = lower;
	} 
	else if(x > upper)
	{
		x = upper;
	}
	
	return x;
}
