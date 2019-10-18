int S1=A0;		//Variable to store pin no. of Sensor 1
int S2=A1;		//Variable to store pin no. of Sensor 2
int S3=A2;		//Variable to store pin no. of Sensor 3
int S4=A3;		//Variable to store pin no. of Sensor 4
int lmp =2;		//variable to store "left motor positive" pin
int lmn =3;		//variable to store "left motor negative" pin
int rmp =10;	//variable to store "right motor positive" pin
int rmn =11;	//variable to store "right motor negative" pin
int v1 = 0;		//Variable to store value of Sensor 1 ranging from 0 to 1023
int v2 = 0;		//Variable to store value of Sensor 2 ranging from 0 to 1023
int v3 = 0;		//Variable to store value of Sensor 3 ranging from 0 to 1023
int v4 = 0;		//Variable to store value of Sensor 4 ranging from 0 to 1023

void setup(){
	pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
}

int a=0;

void loop(){
  
  	cal();

	while((v1 < 700/*(WHITE - '0')*/ && v2 < 700/*(WHITE - '0')*/ && v3 < 700/*(WHITE - '0')*/ && v4 < 700/*(WHITE - '0')*/)
			|| (v1 < 700/*(WHITE - '0')*/ && v2 < 700/*(WHITE - '0')*/ && v3 < 700/*(WHITE - '0')*/ && v4 > 700/*(BLACK - '1')*/)
			|| (v1 < 700/*(WHITE - '0')*/ && v2 > 700/*(BLACK - '1')*/ && v3 > 700/*(BLACK - '1')*/ && v4 < 700/*(WHITE - '0')*/)
			|| (v1 < 700/*(WHITE - '0')*/ && v2 < 700/*(WHITE - '0')*/ && v3 < 700/*(WHITE - '0')*/ && v4 > 700/*(BLACK - '1')*/)
			|| (v1 < 700/*(WHITE - '0')*/ && v2 > 700/*(BLACK - '1')*/ && v3 > 700/*(BLACK - '1')*/ && v4 < 700/*(WHITE - '0')*/) )
 	{
  		forwd();
 	}

	while((v1 < 700/*(WHITE - '0')*/ && v2 < 700/*(WHITE - '0')*/ && v3 > 700/*(BLACK - '1')*/ && v4 > 700/*(BLACK - '1')*/)
			|| (v1 < 700/*(WHITE - '0')*/ && v2 > 700/*(BLACK - '1')*/ && v3 > 700/*(BLACK - '1')*/ && v4 > 700/*(BLACK - '1')*/)
			|| (v1 > 700/*(BLACK - '1')*/ && v2 < 700/*(WHITE - '0')*/ && v3 > 700/*(BLACK - '1')*/ && v4 > 700/*(BLACK - '1')*/))
  	{
    	l();
  	}

	while((v1 > 700/*(BLACK - '1')*/ && v2 > 700/*(BLACK - '1')*/ && v3 < 700/*(WHITE - '0')*/ && v4 < 700/*(WHITE - '0')*/)
			|| (v1 > 700/*(BLACK - '1')*/ && v2 > 700/*(BLACK - '1')*/ && v3 < 700/*(WHITE - '0')*/ && v4 > 700/*(BLACK - '1')*/)
			|| (v1 > 700/*(BLACK - '1')*/ && v2 > 700/*(BLACK - '1')*/ && v3 > 700/*(BLACK - '1')*/ && v4 < 700/*(WHITE - '0')*/)
			|| (v1 > 700/*(BLACK - '1')*/ && v2 > 700/*(BLACK - '1')*/ && v3 > 700/*(BLACK - '1')*/ && v4 > 700/*(BLACK - '1')*/))
  	{
    	r();
  	}

	while((v1 < 700/*(WHITE - '0')*/ && v2 < 700/*(WHITE - '0')*/ && v3 > 700/*(BLACK - '1')*/ && v4 < 700/*(WHITE - '0')*/)
			|| (v1 > 700/*(BLACK - '1')*/ && v2 < 700/*(WHITE - '0')*/ && v3 > 700/*(BLACK - '1')*/ && v4 < 700/*(WHITE - '0')*/))
  	{
    	bl();
  	}

	while((v1 < 700/*(WHITE - '0')*/ && v2 > 700/*(BLACK - '1')*/ && v3 < 700/*(WHITE - '0')*/ && v4 < 700/*(WHITE - '0')*/)
			|| (v1 < 700/*(WHITE - '0')*/ && v2 > 700/*(BLACK - '1')*/ && v3 < 700/*(WHITE - '0')*/ && v4 > 700/*(BLACK - '1')*/))
  	{
    	br();
  	}

	while((v1 > 700/*(BLACK - '1')*/ && v2 > 700/*(BLACK - '1')*/ && v3 > 700/*(BLACK - '1')*/ && v4 > 700/*(BLACK - '1')*/))
  	{
    	if(a==0)
		{
			digitalWrite (rmp, LOW);
			digitalWrite (rmn, HIGH);
			digitalWrite (lmp, HIGH);
			digitalWrite (lmn, LOW);
			delay(1);
    	}
		digitalWrite (rmp, LOW);
		digitalWrite (rmn, LOW);
		digitalWrite (lmp, HIGH);
		digitalWrite (lmn, LOW);
		delay(600);
		a=a+1;
		cal();
		a=0;
  	}
}
     

int cal()
{
	v1=analogRead(S1);
	v2=analogRead(S2);
	v3=analogRead(S3);
	v4=analogRead(S4);
}


void forwd()
{
	digitalWrite (rmp, HIGH);
	digitalWrite (rmn, LOW);
	digitalWrite (lmp, HIGH);
	digitalWrite (lmn, LOW);
	cal();
}


void r()
{
	digitalWrite (rmp, LOW);
	digitalWrite (rmn, HIGH);
	digitalWrite (lmp, HIGH);
	digitalWrite (lmn, LOW);
	delay(20);
	digitalWrite (rmp, LOW);
	digitalWrite (rmn, LOW);
	digitalWrite (lmp, HIGH);
	digitalWrite (lmn, LOW);
	cal();
}


void l()
{
	digitalWrite (rmp, HIGH);
	digitalWrite (rmn, LOW);
	digitalWrite (lmp, LOW);
	digitalWrite (lmn, HIGH);
	delay(20);
	digitalWrite (rmp, HIGH);
	digitalWrite (rmn, LOW);
	digitalWrite (lmp, LOW);
	digitalWrite (lmn, LOW);
	cal();
}


void br()
{
	digitalWrite (rmp, LOW);
	digitalWrite (rmn, HIGH);
	digitalWrite (lmp, HIGH);
	digitalWrite (lmn, LOW);
	delay(20);
	digitalWrite (rmp, LOW);
	digitalWrite (rmn, LOW);
	digitalWrite (lmp, HIGH);
	digitalWrite (lmn, LOW);
	cal();
}


void bl()
{
	digitalWrite (rmp, HIGH);
	digitalWrite (rmn, LOW);
	digitalWrite (lmp, LOW);
	digitalWrite (lmn, HIGH);
	delay(20);
	digitalWrite (rmp, HIGH);
	digitalWrite (rmn, LOW);
	digitalWrite (lmp, LOW);
	digitalWrite (lmn, LOW);
	cal();
}