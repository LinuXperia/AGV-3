#include "main.h"

extern int cnt;

u8 sendFlag=0;
/******************************************************************** 
* ���ƣ�getAbEncoderVaule               
* ���ܣ���ȡ���Ա�������ֵ            
* ��ڲ�����
		u8 DevID; 0x01 0x02 0x03 0x04                    
*                              
* ���ڲ�����  unsigned short  ��ǰ���Ա�������ֵ       
*******************************************************************/
//unsigned short getAbEncoderVaule(u8 DevID_U8)
//{
//	unsigned short encoder_value=0;
//	unsigned short encoder_crc;
//	unsigned char  send_buf[8];
//	unsigned short crc_value;
//	unsigned char  rcv_buf[9];
//		
//	send_buf[0] = DevID_U8;
//	send_buf[1] = 0x04;
//	send_buf[2] = 0x04;
//	send_buf[3] = 0x00;
//	send_buf[4] = 0x00;
//	send_buf[5] = 0x02;
//	send_buf[6] = 0x70;
//	send_buf[7] = 0xFB;
//	if(DevID_U8==0x02)
//	{ 
//		  send_buf[6]=0x70;
//		  send_buf[7]=0xC8;
//	}
//	if(DevID_U8==0x03)
//	{
//		send_buf[6]=0x71;
//		send_buf[7]=0x19;
//	}
//	if(DevID_U8==0x04)
//	{
//		send_buf[6]=0x70;
//		send_buf[7]=0xAE;
//	}
//	RS485_TX_EN=1;	  //����Ϊ����		
//	MYDMA_Send_Config(DMA1_Channel7,(u32)&USART2->DR,(u32)send_buf,10);//DMA1ͨ��7,����Ϊ����2,�洢��Ϊsend_buf,����10.
//	USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE); //ʹ�ܴ���2��DMA����      
//	MYDMA_Send_Enable(DMA1_Channel7);//��ʼһ��DMA���䣡	  
//		//�ȴ�DMA������ɣ���ʱ������������һЩ�£����
//		//ʵ��Ӧ���У����������ڼ䣬����ִ�����������
//	while(1)
//	{					
//		if(DMA_GetFlagStatus(DMA1_FLAG_TC7)!=RESET)	//�ж�ͨ��7�������
//		{
//			DMA_ClearFlag(DMA1_FLAG_TC7);//���ͨ��7������ɱ�־
//			break; 
//		} 
//	}	
//	RS485_TX_EN=0;	  //����Ϊ����				
//	MYDMA_Receive_Config(DMA1_Channel6,(u32)&USART2->DR,(u32)rcv_buf,9);//DMA1ͨ��6,����Ϊ����2,�洢��Ϊrcv_buf,����9.		
//	USART_DMACmd(USART2,USART_DMAReq_Rx,ENABLE); //ʹ�ܴ���2��DMA����     
//	MYDMA_Receive_Enable(DMA1_Channel6);//��ʼһ��DMA���䣡	  
//	while(1)
//	{
//		cnt=0;
//		if(DMA_GetFlagStatus(DMA1_FLAG_TC6)!=RESET)	//�ж�ͨ��6�������
//		{
//			DMA_ClearFlag(DMA1_FLAG_TC6);//���ͨ��6������ɱ�־
//			break; 
//		}
//	}				
///*CRCУ��*/
//	encoder_crc = CRC16Check(rcv_buf,7);
//	crc_value = 0;
//	crc_value = (unsigned char)rcv_buf[8];
//	crc_value <<= 8;
//	crc_value += (unsigned char)rcv_buf[7];
//	if (crc_value == encoder_crc)
//	{
//		 encoder_value = 0;
//		 encoder_value = (unsigned char)rcv_buf[3];
//		 encoder_value <<= 8;
//		 encoder_value += (unsigned char)rcv_buf[4];
//		 cnt=0;
//		 return encoder_value; 																		//���ص�ǰ���Ա�������ֵ			
//	} 
//	else
//	{
//			return 1;    //��ʾ�������ݴ��� ������
//	}
//										
///*CRCУ�����*/	
//}

unsigned short getAbEncoderVaule(void)
{
	unsigned short encoder_value=0;
	unsigned short encoder_crc;
	unsigned char  send_buf[8];
	unsigned short crc_value;
	unsigned char  rcv_buf[9];
	u8 len=0;
	
	send_buf[0] = 0x01;
	send_buf[1] = 0x04;
	send_buf[2] = 0x04;
	send_buf[3] = 0x00;
	send_buf[4] = 0x00;
	send_buf[5] = 0x02;
	switch(sendFlag)
	{
		case 0:
			sendFlag=1;
			RS485_TX_EN=1;	  //����Ϊ����	
			send_buf[0] = 0x01;
			send_buf[6] = 0x70;
			send_buf[7] = 0xFB;
			RS485_Send_Data(send_buf,8);
			RS485_TX_EN = 0;	  //����Ϊ����	
			break;
		case 1:
			RS485_Receive_Data(rcv_buf,&len);
			sendFlag = 2;
			RS485_TX_EN = 1;	  //����Ϊ����	
			send_buf[0] = 0x02;
			send_buf[6] = 0x70;
		  send_buf[7] = 0xC8;
			RS485_Send_Data(send_buf,8);
			RS485_TX_EN = 0;	  //����Ϊ����	
			break;
		case 2:
			RS485_Receive_Data(rcv_buf,&len);
			sendFlag=3;
			RS485_TX_EN = 1;	  //����Ϊ����	
			send_buf[0] = 0x03;
			send_buf[6] = 0x71;
			send_buf[7] = 0x19;
			RS485_Send_Data(send_buf,8);
			RS485_TX_EN = 0;	  //����Ϊ����	
			break;
		case 3:
			RS485_Receive_Data(rcv_buf,&len);
			sendFlag=4;
			RS485_TX_EN = 1;	  //����Ϊ����	
			send_buf[0] = 0x04;
			send_buf[6]=0x70;
			send_buf[7]=0xAE;
			RS485_Send_Data(send_buf,8);
			RS485_TX_EN = 0;	  //����Ϊ����	
			break;
		case 4:
			RS485_Receive_Data(rcv_buf,&len);
			sendFlag=1;
			RS485_TX_EN = 1;	  //����Ϊ����	
			send_buf[0] = 0x01;
			send_buf[6] = 0x70;
			send_buf[7] = 0xFB;
			RS485_Send_Data(send_buf,8);
			RS485_TX_EN = 0;	  //����Ϊ����	
			break;
		default:
				 break;
	}	
		
	/*CRCУ��*/
	encoder_crc = CRC16Check(rcv_buf,7);
	crc_value = 0;
	crc_value = (unsigned char)rcv_buf[8];
	crc_value <<= 8;
	crc_value += (unsigned char)rcv_buf[7];
	if (crc_value == encoder_crc)
	{
		 encoder_value = 0;
		 encoder_value = (unsigned char)rcv_buf[3];
		 encoder_value <<= 8;
		 encoder_value += (unsigned char)rcv_buf[4];
		 cnt=0;
		 switch(rcv_buf[0])
		 {
			 case 0x01:
				 encode1_value = encoder_value;
				 LCD_ShowxNum(180,630,(int)encode1_value,8,16,0X00);
				 break;
			 case 0x02:
				 encode2_value = encoder_value;
			   LCD_ShowxNum(180,660,(int)encode2_value,8,16,0X00);
				 break;
			 case 0x03:
				 encode3_value = encoder_value;
			   LCD_ShowxNum(180,690,(int)encode3_value,8,16,0X00);
				 break;
			 case 0x04:
				 encode4_value = encoder_value;
				 LCD_ShowxNum(180,720,(int)encode4_value,8,16,0X00);
				 break;
			 default:
				 break;
		 
		 }
		 return 0; 																		//���ص�ǰ���Ա�������ֵ			
	} 
	else
	{
			return 1;    //��ʾ�������ݴ��� ������
	}
										
/*CRCУ�����*/	
}


