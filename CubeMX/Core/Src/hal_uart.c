//
// HAL para interface UART, neste projeto associada a comunica��o com o m�dulo BlueTooth.
//

#include "hal_uart.h"

  //
  // Vari�veis Externas.
  //
  extern UART_HandleTypeDef huart2;
	extern uint16_t AD_RES;
  
  //
  // Inicializa��o dos par�metros da UART.
  //
  void hal_uart_init(void)
	{
	  MX_USART2_UART_Init();
  }
  
  //
  // Escreve dados na UART (envio para o m�dulo BlueTooth.
  //
  void hal_uart_write(unsigned char dataUart)
	{
		char buffer[40];

		if(HAL_UART_Receive_IT(&huart2, RX_BUFFER, BUFFER_LEN))
		{		
			TX_BUFFER[0] = dataUart>>4;
			HAL_UART_Transmit(&huart2, TX_BUFFER, sizeof(TX_BUFFER), 100);	// Envia apenas o valor lido pelo ADC, sem qualquer mensagem.
		}
}
  
  // -------------------------------------------------------------------------
  // Fun��es do fabricante.
  // -------------------------------------------------------------------------

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == huart2.Instance)
    {
			if(RX_BUFFER[0] == '1')
			{
					HAL_GPIO_WritePin(BLE_RX_GPIO_Port, BLE_RX_Pin, GPIO_PIN_SET);
			}
			else if(RX_BUFFER[0] == '0')
			{
					HAL_GPIO_WritePin(BLE_TX_GPIO_Port, BLE_RX_Pin, GPIO_PIN_RESET);
			}
			HAL_UART_Receive_IT(&huart2, RX_BUFFER, BUFFER_LEN);
    }
}