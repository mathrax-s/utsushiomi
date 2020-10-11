#include "project.h"

void CapSense_DisplayState(void);

uint16 bright;
int Button[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
int Status[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
int SendData[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
struct SensorData{
	uint16	RawCount;
	uint16	Baseline;
	uint16	Diff;
};
typedef struct SensorData SnsDat;
SnsDat sData[13];

int msgData[13]={10,20,30,40,50,60,70,80,90,100,110,120,130};

int main()
{
    int i;
    
    /* Enable global interrupts */
    CyGlobalIntEnable;

    /* Start PWM and CapSense components */
    LED_CONTROL_Start();

    CapSense_CSD_Start();

    UART_1_Start();
   
    
    /* Initialize baselines */
    CapSense_CSD_InitializeAllBaselines();

    while(1u)
    {
        uint8 pinstate = Pin_Read();
        
        //if(UART_1_UartGetByte()=='r'){
        if(pinstate == 0){
            CapSense_CSD_InitializeAllBaselines();
        }
        

        
        /* Update all baselines */
        CapSense_CSD_UpdateEnabledBaselines();
        
   		/* Start scanning all enabled sensors */
    	CapSense_CSD_ScanEnabledWidgets();
        
        /* Place your application code here */
        while(CapSense_CSD_IsBusy() != 0);

        for(i=0; i<13; i++){
            Button[i] = CapSense_CSD_CheckIsWidgetActive(i);
            if(Button[i]==1){
                if(Status[i]==0){
                    Status[i]=1;
                    SendData[i]=1;
                }else{
                    
                    SendData[i]=0;
                }
                bright=65535;
            }else{
                Status[i]=0;
                SendData[i]=0;
                
            }
            
            UART_1_UartPutChar('0'+SendData[i]);
                
            if(i<(13-1)){
                UART_1_UartPutChar(',');
            }
		}
        //FOOTER    
        UART_1_UartPutChar(10); 
        UART_1_UartPutChar(13); 
                
        LED_CONTROL_WriteCompare((uint32)bright);
        bright*=0.99;
    }
      
}



/* [] END OF FILE */
