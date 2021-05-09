	//
	// HAL para definição do timer geral TIM2.
	//
	#include "hal_timer.h"
	#include "ssd1306.h" 
	#include "fonts.h" 
	#include "test.h" 
	#include <stdio.h>
	extern uint16_t AD_RES; 
  extern TIM_HandleTypeDef htim2;

  void hal_timer_init(void)
	{
		MX_TIM2_Init();
  }

  void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
	{  
		/* 
	  Nesta função de Callback você precisa colocar contadores, e usar funções 
	  de escrita em GPIO para acender e apagar o LED3, por exemplo.
	  */
		
    if(htim->Instance == TIM2) 
		{
				HAL_GPIO_TogglePin(LD3_GPIO_Port,  LD3_Pin);	//Inverter o sinal do Pino 26 do LED
				atualizaOLED();   														//Atualiza a tela LCD a cada  XX ms
				HAL_Delay(100);
				HAL_GPIO_TogglePin(LD3_GPIO_Port,  LD3_Pin);	//Inverter o sinal do Pino 26 do LED
    }
  }

      
/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM2_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};


  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
}


void atualizaOLED(void)
{
		char Valor[10];
	
		sprintf(Valor, "%uint16_t", AD_RES);
		if(AD_RES < 100)	//AUSENCIA OU BAIXO NIVEL DE CO2
		{
			SSD1306_GotoXY( 10 , 10 );  // vá para 10, 10 
			SSD1306_Puts( (char*)"Nivel de CO2 Ausente ou Baixo" ,  (FontDef_t*)&Font_11x18,  (SSD1306_COLOR_t)1 );
			SSD1306_GotoXY( 10 ,  30 );  
			SSD1306_Puts(Valor,  (FontDef_t*)&Font_11x18,  (SSD1306_COLOR_t)1 );  
			SSD1306_UpdateScreen();  																							// Atualização do LCD	
			HAL_GPIO_WritePin(BUZZ_OUT_GPIO_Port,  LD3_Pin, GPIO_PIN_RESET);			// Reseta o pino 11 do Buzzer para desligado	
		}
		else if(AD_RES < 200)	//NIVEL ACEITAVEL DE C02
		{
			SSD1306_GotoXY( 10 , 10 );  // vá para 10, 10 
			SSD1306_Puts( (char*)"Nivel de CO2 Presente" ,  (FontDef_t*)&Font_11x18,  (SSD1306_COLOR_t)1 );
			SSD1306_GotoXY( 10 , 30 );  
			
			SSD1306_Puts(Valor,  (FontDef_t*)&Font_11x18,  (SSD1306_COLOR_t)1 );  
			SSD1306_UpdateScreen();  																							// Atualização do LCD	
			HAL_GPIO_WritePin(BUZZ_OUT_GPIO_Port,  LD3_Pin, GPIO_PIN_RESET);			// Reseta o pino 11 do Buzzer para desligado
		}
		else	//NIVEL MUITO ALTO DE CO2
		{
			SSD1306_GotoXY( 10 , 10 );
			SSD1306_Puts( (char*)"Nivel de CO2 Alto" ,  (FontDef_t*)&Font_11x18,  (SSD1306_COLOR_t)1 );
			SSD1306_GotoXY( 10 , 30 );  
			SSD1306_Puts(Valor,  (FontDef_t*)&Font_11x18,  (SSD1306_COLOR_t)1 );  
			SSD1306_UpdateScreen();  																							//Atualização de tela	
			HAL_GPIO_TogglePin(BUZZ_OUT_GPIO_Port,  LD3_Pin);											//Inverter o sinal do Pino 11 do BUUZZER - ATIVA AVISO SONORO
		}
}
