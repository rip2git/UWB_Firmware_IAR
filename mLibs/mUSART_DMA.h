#ifndef USART_H_
#define USART_H_

#include "_DEBUG.h"
#include "stm32f0xx.h"

/*! ------------------------------------------------------------------------------------------------------------------
 * @def: USARTx_BUFFER_SIZE
 *
 * @brief: Size of internal two system buffers
 *
*/
#define USARTx_BUFFER_SIZE	196

/*! ------------------------------------------------------------------------------------------------------------------
 * @typedef: USART_RESULT
 *
 * @brief: Used for results (described below) returned from USART methods
 *
*/
typedef int USART_RESULT;

/*! ------------------------------------------------------------------------------------------------------------------
 * @typedef: USART_MODE
 *
 * @brief: 
 *
*/
typedef uint8_t USART_MODE;

/*! ------------------------------------------------------------------------------------------------------------------
 * @def: USART_RESULT
 *
 * @brief: Returns from USART methods after operation
 *
*/
#define USART_SUCCESS					(0)
#define USART_FAIL						(-1)

/*! ------------------------------------------------------------------------------------------------------------------
 * @def: USART_MODE
 *
 * NOTE: USART_WAIT - isn't supported yet
 *
 * @brief: Mode of transmit/receive operation:
 * - USART_NOWAIT 	- 	returns from methods after puts up the data to transmitting or request to receiving
 * - USART_WAIT 	- 	waits while the data isn't received or transmitted
 *
*/
#define USART_NOWAIT					0x00
#define USART_WAIT						0x01

/*! ------------------------------------------------------------------------------------------------------------------
 * @typedef: USART_CALL_BACK
 *
 * @brief: Call-back type for all events
 *
*/
typedef void (*USART_CALL_BACK)(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @def: USART_NO_CallBack
 *
 * @brief: Empty callback
 *
*/
#define USART_NO_CallBack		((void *)0)

/*! ------------------------------------------------------------------------------------------------------------------
 * @def: USART_IRQHandler
 *
 * @brief: Internal IRQHandler name
 *
*/
#define USART_IRQHandler(x) 	DMA1_Channel4_5_IRQHandler(x)


/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_Initialization
 *
 * @brief: Initializes peripherals
 *
 * NOTE: 
 *
 * input parameters
 *
 * output parameters
 *
 * no return value
*/
extern void USART_Initialization(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_SetTRXMode
 *
 * @brief: Sets the mode of receive / transmit operations
 *
 * NOTE: 
 *
 * input parameters
 * @param mode - USART_MODE described above
 *
 * output parameters
 *
 * no return value
*/
extern void USART_SetTRXMode(USART_MODE mode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_SetCallBacks
 *
 * @brief: Sets callback for all events
 *
*/
extern void USART_SetCallBacks(
	USART_CALL_BACK rx_success_cb,
	USART_CALL_BACK rx_fail_cb
);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_StartRead
 *
 * @brief: 
 *
 * NOTE: 
 *
 * input parameters
 * @param buffer - array of the bytes to be received from USART
 * @param length - size of requested data in bytes
 *
 * output parameters
 *
 * return value is result of operation (described above)
*/
extern USART_RESULT USART_StartRead(uint8_t *buffer, uint16_t length);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_ForceReadEnd
 *
 * @brief: Turns off the receiver
 *
 * NOTE: 
 *
 * input parameters
 *
 * output parameters
 *
 * no return value
*/
extern inline void USART_ForceReadEnd(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_ErrorControl
 *
 * @brief: Controls peripherals errors. If errors occurred returns USART_FAIL and turns off the receiver
 *
 * NOTE: Should be called periodically or before catching the data
 *
 * input parameters
 *
 * output parameters
 *
 * return value is result of operation (described above)
*/
extern inline USART_RESULT USART_ErrorControl(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_SendByte
 *
 * @brief: Sends byte through USART
 *
 * NOTE: 
 *
 * input parameters
 * @param c - byte to be sent through USART
 *
 * output parameters
 *
 * return value is result of operation (described above)
*/
extern USART_RESULT USART_SendByte(const uint8_t c);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_SendBuffer
 *
 * @brief: Sends array of the bytes through USART
 *
 * NOTE: 
 *
 * input parameters
 * @param buffer - array of the bytes to be sent through USART
 * @param length - size of sended data in bytes
 *
 * output parameters
 *
 * return value is result of operation (described above)
*/
extern USART_RESULT USART_SendBuffer(const uint8_t *buffer, uint16_t length);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn: USART_SendString
 *
 * @brief: Sends sequence of characters through USART
 *
 * NOTE: param string should be ended with null-terminator
 *
 * input parameters
 * @param string - sequence of characters that should be ended with null-terminator
 *
 * output parameters
 *
 * return value is result of operation (described above)
*/
extern USART_RESULT USART_SendString(const char *string);


#endif