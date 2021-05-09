	//
	// HAL para definição dos pinos de GPIO, incluindo UART, LED3, etc.
	//

	#include "hal_gpio.h"

  void hal_gpio_init(void)
	{
		MX_GPIO_Init();
  }

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	
  /*Configure GPIO LED3 pin Output Level */
  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
  /*Configure GPIO pin : LD3_Pin */
  GPIO_InitStruct.Pin = LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD3_GPIO_Port, &GPIO_InitStruct);
	
	
	/*Configure BUZZ_OUT GPIO pin Output Level */
  HAL_GPIO_WritePin(BUZZ_OUT_GPIO_Port, BUZZ_OUT_Pin, GPIO_PIN_RESET);
  /*Configure GPIO pin : BUZZ_OUT_Pin */
  GPIO_InitStruct.Pin = BUZZ_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BUZZ_OUT_GPIO_Port, &GPIO_InitStruct);
	
	
	/*Configure BLE_RX GPIO pin Output Level */
  HAL_GPIO_WritePin(BLE_RX_GPIO_Port, BLE_RX_Pin, GPIO_PIN_RESET);
  /*Configure GPIO pin : BUZZ_OUT_Pin */
  GPIO_InitStruct.Pin = BLE_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BLE_RX_GPIO_Port, &GPIO_InitStruct);
	
	
	/*Configure BLE_TX GPIO pin Output Level */
  HAL_GPIO_WritePin(BLE_TX_GPIO_Port, BLE_TX_Pin, GPIO_PIN_RESET);
  /*Configure GPIO pin : BUZZ_OUT_Pin */
  GPIO_InitStruct.Pin = BLE_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BLE_TX_GPIO_Port, &GPIO_InitStruct);
}
