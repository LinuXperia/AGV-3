#include "main.h"

u8 canbuf_hub[32];

/******************************************************************** 
* ����  setHubMotorEnable          
* ���ܣ�������ر���챵��        ��������
* ��ڲ�����
		u16 DevID; 0x0005 0x0006 0x0007 0x0008                    
*   inti; 0 �ͷ� ���   1 ���� ���                     
* ���ڲ�����    
*******************************************************************/
void setHubMotorEnable(u16 DevID,int i)
{
	
	if(i==0)
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xFA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x10;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x0F;

		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //���ͱ�׼֡��ʽ
		delay_ms(1);

	}
	else if (i==1)
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xFA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x10;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x1F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //���ͱ�׼֡��ʽ
		delay_ms(1);
	}

}	



/******************************************************************** 
* ���ƣssetHubMotorMode           
* ���ܣ�������챵������ģʽ   �㲥ģʽ      
* ��ڲ�����
		                   
*    int i; 1 �ٶ�ģʽ  0 λ��ģʽ                       
* ���ڲ�����    
*******************************************************************/
void setHubMotorMode(int i)
{
	u16 DevID=0x0000;         														//����Ϊ�㲥ģʽ
	if(i==1)																							//����Ϊ�ٶ�ģʽ
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;																//�㲥ģʽΪDA��һ��ģʽΪFA
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x19;																//19��Ϊ���ù���ģʽ
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x2F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  									//���ͱ�׼֡��ʽ
		delay_ms(1);
	}
	else if (i==0)																					//����Ϊλ��ģʽ
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x19;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x3F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //���ͱ�׼֡��ʽ
		delay_ms(1);
	}

}


/******************************************************************** 
* ���ƣssetHubMotorPlusSubSpeed          
* ���ܣ�������챵���Ӽ���ʱ��     �㲥ģʽ 
* ��ڲ����� 
						int i; 1 �ٶ�ģʽ  0 λ��ģʽ  :
                                  
* ���ڲ�����   
*******************************************************************/

void setHubMotorPlusSubSpeed(int i)         //ֱ����Ĭ�ϵļӼ���ʱ��
{

	u16 DevID=0x0000;         														//����Ϊ�㲥ģʽ
	if(i==1)																							//�����ٶ�ģʽ�¼Ӽ���ʱ��
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x13;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x0A;
		canbuf_hub[7] =0x0A;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  										//���ͱ�׼֡��ʽ
		delay_ms(1);

	}
	else if (i==0)																				//����λ��ģʽ�¼Ӽ���ʱ��
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x12;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x0A;
		canbuf_hub[7] =0x0A;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //���ͱ�׼֡��ʽ
		delay_ms(1);

	}
}

/******************************************************************** 
* ���ƣssetHubMotorPositionMaxSpeed           
* ���ܣ�������챵��λ��ģʽ������ٶ�   
* ��ڲ�����
		u16 DevID; 0x0005 0x0006 0x0007 0x0008 
		int speed: ���õ�����ٶ�ֵ
                                 
* ���ڲ�������ǰλ��    
*******************************************************************/
void setHubMotorPositionMaxSpeed(u16 DevID,int speed)
{
	unsigned char instruction[2][8] =
  {
   {0x00,0xFA,0x00,0x14,0x00,0x00,0x00,0x00}, 
  };
	int i;
 	int *p;
  int iIndexSpeed = 0;
	unsigned char c;
	if(DevID==0x00)   																				//�㲥ģʽ
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	
	 p = (int*)(instruction[iIndexSpeed] + 4);									
	*p = (int)(speed*8192/3000);															//�ٶ�ת��
	c = *(instruction[iIndexSpeed] + 4);											//ת������ĸ��ֽ�1��2��3��4
																														//����ʱҪ����4��3��2��1��˳���Ͳ�����������
  *(instruction[iIndexSpeed] + 4) = *(instruction[iIndexSpeed] + 4 + 3);
  *(instruction[iIndexSpeed] + 4 + 3) = c;
  c = *(instruction[iIndexSpeed] + 4 + 1);
  *(instruction[iIndexSpeed] + 4 + 1) = *(instruction[iIndexSpeed] + 4 + 2);
  *(instruction[iIndexSpeed] + 4 + 2) = c;
	CAN_Send_Msg(instruction[0],8,0,DevID,0);
	delay_ms(1);


}


/******************************************************************** 
* ���ƣssetHubMotorPositionModeControlWord           
* ���ܣ�������챵��λ��ģʽ������  
* ��ڲ�����
		int mode�� mode=0  ���λ��ģʽ
							 mode=1  ����λ��ģʽ
                                 
* ���ڲ�������ǰλ��    
*******************************************************************/
void setHubMotorPositionModeControlWord(int mode)
{
	u16 DevID=0x0000;         														//����Ϊ�㲥ģʽ
	if(mode==1)																						//���þ���λ��ģʽ
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x17;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x4F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  										//���ͱ�׼֡��ʽ
		delay_ms(1);
	}
	else if (mode==0)																				//�������λ��ģʽ
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x17;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x5F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //���ͱ�׼֡��ʽ
		delay_ms(1);
	}
}


/******************************************************************** 
* ���ƣsgetHubMotorNowPosition           
* ���ܣ������챵�����ǰλ��   
* ��ڲ�����
		u16 DevID; 0x0005 0x0006 0x0007 0x0008  
                                 
* ���ڲ�������ǰλ��    
*******************************************************************/
void getHubMotorNowPosition(u16 DevID)
{
	

}

/******************************************************************** 
* ���ƣssetHubMotorTargetPosition          
* ���ܣ�������챵��Ŀ��λ��   
* ��ڲ�����
		u16 DevID; 0x0005 0x0006 0x0007 0x0008  
                                 
* ���ڲ�����  
*******************************************************************/
void setHubMotorTargetPosition(u16 DevID)
{
		
}

/******************************************************************** 
* ���ƣssetHubMotorTargetSpeed          
* ���ܣ�������챵��Ŀ���ٶ�  
* ��ڲ�����
		u16 DevID; 0x0005 0x0006 0x0007 0x0008                    
*   int speed; �ٶ�ֵ    
			//�������ڲ����� ʵ���ٶ�=����ֵ/8192*3000RPM
			//������챵������ٶ�����Ϊ 1000RPM
* ���ڲ�����    
*******************************************************************/
void setHubMotorTargetSpeed(u16 DevID,int speed)
{
 unsigned char instruction[2][8] =
  {
   {0x00,0xFA,0x00,0x11,0x00,0x00,0x00,0x00}, 
  };
	int i;
 	int *p;
  int iIndexSpeed = 0;
	unsigned char c;
	if(DevID==0x00)   																				//�㲥ģʽ
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	 p = (int*)(instruction[iIndexSpeed] + 4);									
	*p = (int)(speed*8192/3000);															//�ٶ�ת��
	c = *(instruction[iIndexSpeed] + 4);											//ת������ĸ��ֽ�1��2��3��4
																														//����ʱҪ����4��3��2��1��˳���Ͳ�����������
  *(instruction[iIndexSpeed] + 4) = *(instruction[iIndexSpeed] + 4 + 3);
  *(instruction[iIndexSpeed] + 4 + 3) = c;
  c = *(instruction[iIndexSpeed] + 4 + 1);
  *(instruction[iIndexSpeed] + 4 + 1) = *(instruction[iIndexSpeed] + 4 + 2);
  *(instruction[iIndexSpeed] + 4 + 2) = c;
	CAN_Send_Msg(instruction[0],8,0,DevID,0);	
	delay_ms(1);
}

/******************************************************************** 
* ���ƣssetHubMotorLength          
* ���ܣ�������챵���н�����   
* ��ڲ�����
		u16 DevID; 0x0005 0x0006 0x0007 0x0008  
		int length: ����                            
* ���ڲ�����  
*******************************************************************/
void setHubMotorLength(u16 DevID,int length)
{
	unsigned char instruction[2][8] =
  {
   {0x00,0xFA,0x00,0x16,0x00,0x00,0x00,0x00}, 
  };
	int i;
 	int *p;
  int iIndex = 0;
	unsigned char c;
	if(DevID==0x00)   																									//�㲥ģʽ
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	
	 p = (int*)(instruction[iIndex] + 4);									
	*p = (int)(length);																									//����λ��
	c = *(instruction[iIndex] + 4);																			//ת������ĸ��ֽ�1��2��3��4
																																			//����ʱҪ����4��3��2��1��˳���Ͳ�����������
  *(instruction[iIndex] + 4) = *(instruction[iIndex] + 4 + 3);
  *(instruction[iIndex] + 4 + 3) = c;
  c = *(instruction[iIndex] + 4 + 1);
  *(instruction[iIndex] + 4 + 1) = *(instruction[iIndex] + 4 + 2);
  *(instruction[iIndex] + 4 + 2) = c;
	CAN_Send_Msg(instruction[0],8,0,DevID,0);		
	delay_ms(1);
}


/******************************************************************** 
* ���ƣshubMotorSpeed          
* ���ܣ�������챵���ٶ�   
* ��ڲ�����
		int hubCounte     //����ֵ                           
* ���ڲ�����  
*******************************************************************/
void hubMotorSpeed(int hubCounte)
{
	if(hubCounte>24)
	{
		hubCounte=24;
	}
	else if(hubCounte>16&&hubCounte<=24)
	{
		hubmotor_speed=15;
	}
	else if(hubCounte>8&&hubCounte<=16)
	{
		hubmotor_speed=10;
	}
	else if(hubCounte>0&&hubCounte<=8)
	{
		hubmotor_speed=5;
	}
	else if(hubCounte==0)
	{
		hubmotor_speed=0;
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		hubmotor_speed=(-5);
	}
	else if(hubCounte<(-8)&&hubCounte>=(-16))
	{
		hubmotor_speed=(-10);
	}
	else if(hubCounte<(-16)&&hubCounte>=(-24))
	{
		hubmotor_speed=(-15);
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		hubCounte=(-24);
	}

}

/******************************************************************** 
* ���ƣshubMotorSpeed          
* ���ܣ�������챵���ٶ�   
* ��ڲ�����
		int hubCounte     //����ֵ                           
* ���ڲ�����  
*******************************************************************/
void hubMotorPul(int hubCounte)
{
	if(hubCounte>24)
	{
		hubCounte=24;
	}
	else if(hubCounte>16&&hubCounte<=24)
	{
//		setDir(0x0005,P_);
//		setDir(0x0006,P_);
//		setDir(0x0007,P_);
//		setDir(0x0008,P_);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
	}
	else if(hubCounte>8&&hubCounte<=16)
	{
//		setDir(0x0005,P_);
//		setDir(0x0006,P_);
//		setDir(0x0007,P_);
//		setDir(0x0008,P_);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
	}
	else if(hubCounte>0&&hubCounte<=8)
	{
		setDir(0x0005,P_);
		setDir(0x0006,P_);
		setDir(0x0007,P_);
		setDir(0x0008,P_);
		setCyc(0x0005,900);
		setCyc(0x0006,900);
		setCyc(0x0007,900);
		setCyc(0x0008,900);
	}
	else if(hubCounte==0)
	{
		setCyc(0x0005,0);
		setCyc(0x0006,0);
		setCyc(0x0007,0);
		setCyc(0x0008,0);
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		setDir(0x0005,N_);
		setDir(0x0006,N_);
		setDir(0x0007,N_);
		setDir(0x0008,N_);
		setCyc(0x0005,900);
		setCyc(0x0006,900);
		setCyc(0x0007,900);
		setCyc(0x0008,900);
	}
	else if(hubCounte<(-8)&&hubCounte>=(-16))
	{
//		setDir(0x0005,N_);
//		setDir(0x0006,N_);
//		setDir(0x0007,N_);
//		setDir(0x0008,N_);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
	}
	else if(hubCounte<(-16)&&hubCounte>=(-24))
	{
//		setDir(0x0005,N_);
//		setDir(0x0006,N_);
//		setDir(0x0007,N_);
//		setDir(0x0008,N_);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		hubCounte=(-24);
	}

}

//������챵���н����Ⱥ��н��ٶ�
void setHubMotorLengthAndSpeed(u16 DevID,s32 length,s32 speed)
{



}
