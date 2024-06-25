
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_


void DIO_voidSetPinDir(int Group_Type, int Pin_No, int DirStatus);
void DIO_voidSetPinValue(int Group_Type, int Pin_No, int Value);
int DIO_intReadPinValue(int Group_Type, int Pin_No);
void DIO_voidControlPullupPin(int Group_Type,int Pin_No , int PullUp_Status);
void DIO_voidSetPortDir(int Group_Type , int DirStatus);
void DIO_voidSetPortValue(int Group_Type , int Value);
int DIO_intReadPortValue(int Group_Type);
void DIO_voidControlPullupPort(int Group_Type , int PullUp_Status);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */