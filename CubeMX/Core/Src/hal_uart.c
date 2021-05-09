//
// HAL para interface UART, neste projeto associada a comunicação com o módulo BlueTooth.
//

#include "hal_uart.h"

  //
  // Variáveis Externas.
  //
  extern UART_HandleTypeDef huart2;
  
  //
  // Inicialização dos parâmetros da UART.
  //
  void hal_uart_init(void){
	  MX_USART2_UART_Init();
  }
  
  //
  // Escreve dados na UART (envio para o módulo BlueTooth.
  //
  void hal_uart_write(unsigned char dataUart){
	  /*
	  Colocar aqui o método para enviar dado pela UART. O exemplo abaixo
	  escreve o valor recebido na função na UART:
	  
	  USART2->TDR = writeUart;
	  
	  */
  }
  
  // -------------------------------------------------------------------------
  // Funções do fabricante.
  // -------------------------------------------------------------------------

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
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
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}
