/***************************************************************************//**
* \file cyUart_p50_p51.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_cyUart_p50_p51_H)
#define CY_SCB_cyUart_p50_p51_H

#include <cydevice_trm.h>
#include <cyfitter.h>
#include <cytypes.h>
#include <CyLib.h>

/* SCB IP block v0 is available in PSoC 4100/PSoC 4200 */
#define cyUart_p50_p51_CY_SCBIP_V0    (CYIPBLOCK_m0s8scb_VERSION == 0u)
/* SCB IP block v1 is available in PSoC 4000 */
#define cyUart_p50_p51_CY_SCBIP_V1    (CYIPBLOCK_m0s8scb_VERSION == 1u)
/* SCB IP block v2 is available in all other devices */
#define cyUart_p50_p51_CY_SCBIP_V2    (CYIPBLOCK_m0s8scb_VERSION >= 2u)

/** Component version major.minor */
#define cyUart_p50_p51_COMP_VERSION_MAJOR    (4)
#define cyUart_p50_p51_COMP_VERSION_MINOR    (0)
    
#define cyUart_p50_p51_SCB_MODE           (4u)

/* SCB modes enum */
#define cyUart_p50_p51_SCB_MODE_I2C       (0x01u)
#define cyUart_p50_p51_SCB_MODE_SPI       (0x02u)
#define cyUart_p50_p51_SCB_MODE_UART      (0x04u)
#define cyUart_p50_p51_SCB_MODE_EZI2C     (0x08u)
#define cyUart_p50_p51_SCB_MODE_UNCONFIG  (0xFFu)

/* Condition compilation depends on operation mode: Unconfigured implies apply to all modes */
#define cyUart_p50_p51_SCB_MODE_I2C_CONST_CFG       (cyUart_p50_p51_SCB_MODE_I2C       == cyUart_p50_p51_SCB_MODE)
#define cyUart_p50_p51_SCB_MODE_SPI_CONST_CFG       (cyUart_p50_p51_SCB_MODE_SPI       == cyUart_p50_p51_SCB_MODE)
#define cyUart_p50_p51_SCB_MODE_UART_CONST_CFG      (cyUart_p50_p51_SCB_MODE_UART      == cyUart_p50_p51_SCB_MODE)
#define cyUart_p50_p51_SCB_MODE_EZI2C_CONST_CFG     (cyUart_p50_p51_SCB_MODE_EZI2C     == cyUart_p50_p51_SCB_MODE)
#define cyUart_p50_p51_SCB_MODE_UNCONFIG_CONST_CFG  (cyUart_p50_p51_SCB_MODE_UNCONFIG  == cyUart_p50_p51_SCB_MODE)

/* Condition compilation for includes */
#define cyUart_p50_p51_SCB_MODE_I2C_INC      (0u !=(cyUart_p50_p51_SCB_MODE_I2C   & cyUart_p50_p51_SCB_MODE))
#define cyUart_p50_p51_SCB_MODE_EZI2C_INC    (0u !=(cyUart_p50_p51_SCB_MODE_EZI2C & cyUart_p50_p51_SCB_MODE))
#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_SCB_MODE_SPI_INC  (0u !=(cyUart_p50_p51_SCB_MODE_SPI   & cyUart_p50_p51_SCB_MODE))
    #define cyUart_p50_p51_SCB_MODE_UART_INC (0u !=(cyUart_p50_p51_SCB_MODE_UART  & cyUart_p50_p51_SCB_MODE))
#else
    #define cyUart_p50_p51_SCB_MODE_SPI_INC  (0u)
    #define cyUart_p50_p51_SCB_MODE_UART_INC (0u)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

/* Interrupts remove options */
#define cyUart_p50_p51_REMOVE_SCB_IRQ             (0u)
#define cyUart_p50_p51_SCB_IRQ_INTERNAL           (0u == cyUart_p50_p51_REMOVE_SCB_IRQ)

#define cyUart_p50_p51_REMOVE_UART_RX_WAKEUP_IRQ  (1u)
#define cyUart_p50_p51_UART_RX_WAKEUP_IRQ         (0u == cyUart_p50_p51_REMOVE_UART_RX_WAKEUP_IRQ)

/* SCB interrupt enum */
#define cyUart_p50_p51_SCB_INTR_MODE_NONE     (0u)
#define cyUart_p50_p51_SCB_INTR_MODE_INTERNAL (1u)
#define cyUart_p50_p51_SCB_INTR_MODE_EXTERNAL (2u)

/* Internal clock remove option */
#define cyUart_p50_p51_REMOVE_SCB_CLK     (0u)
#define cyUart_p50_p51_SCB_CLK_INTERNAL   (0u == cyUart_p50_p51_REMOVE_SCB_CLK)


/***************************************
*       Includes
****************************************/

#include "cyUart_p50_p51_PINS.h"

#if (cyUart_p50_p51_SCB_CLK_INTERNAL)
    #include "cyUart_p50_p51_SCBCLK.h"
#endif /* (cyUart_p50_p51_SCB_CLK_INTERNAL) */


/***************************************
*       Type Definitions
***************************************/

typedef struct
{
    uint8 enableState;
} cyUart_p50_p51_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_general
* @{
*/

/* Start and Stop APIs */
void cyUart_p50_p51_Init(void);
void cyUart_p50_p51_Enable(void);
void cyUart_p50_p51_Start(void);
void cyUart_p50_p51_Stop(void);

/** @} general */

/**
* \addtogroup group_power
* @{
*/
/* Sleep and Wakeup APis */
void cyUart_p50_p51_Sleep(void);
void cyUart_p50_p51_Wakeup(void);
/** @} power */ 

/**
* \addtogroup group_interrupt
* @{
*/
#if (cyUart_p50_p51_SCB_IRQ_INTERNAL)
    /* Custom interrupt handler */
    void cyUart_p50_p51_SetCustomInterruptHandler(void (*func)(void));
#endif /* (cyUart_p50_p51_SCB_IRQ_INTERNAL) */
/** @} interrupt */

/* Interface to internal interrupt component */
#if (cyUart_p50_p51_SCB_IRQ_INTERNAL)
    /**
    * \addtogroup group_interrupt
    * @{
    */    
    /*******************************************************************************
    * Function Name: cyUart_p50_p51_EnableInt
    ****************************************************************************//**
    *
    *  When using an Internal interrupt, this enables the interrupt in the NVIC. 
    *  When using an external interrupt the API for the interrupt component must 
    *  be used to enable the interrupt.
    *
    *******************************************************************************/
    #define cyUart_p50_p51_EnableInt()    CyIntEnable(cyUart_p50_p51_ISR_NUMBER)
    
    
    /*******************************************************************************
    * Function Name: cyUart_p50_p51_DisableInt
    ****************************************************************************//**
    *
    *  When using an Internal interrupt, this disables the interrupt in the NVIC. 
    *  When using an external interrupt the API for the interrupt component must 
    *  be used to disable the interrupt.
    *
    *******************************************************************************/    
    #define cyUart_p50_p51_DisableInt()   CyIntDisable(cyUart_p50_p51_ISR_NUMBER)
    /** @} interrupt */

    /*******************************************************************************
    * Function Name: cyUart_p50_p51_ClearPendingInt
    ****************************************************************************//**
    *
    *  This function clears the interrupt pending status in the NVIC. 
    *
    *******************************************************************************/
    #define cyUart_p50_p51_ClearPendingInt()  CyIntClearPending(cyUart_p50_p51_ISR_NUMBER)
#endif /* (cyUart_p50_p51_SCB_IRQ_INTERNAL) */

#if (cyUart_p50_p51_UART_RX_WAKEUP_IRQ)
    /*******************************************************************************
    * Function Name: cyUart_p50_p51_RxWakeEnableInt
    ****************************************************************************//**
    *
    *  This function enables the interrupt (RX_WAKE) pending status in the NVIC. 
    *
    *******************************************************************************/    
    #define cyUart_p50_p51_RxWakeEnableInt()  CyIntEnable(cyUart_p50_p51_RX_WAKE_ISR_NUMBER)
    

    /*******************************************************************************
    * Function Name: cyUart_p50_p51_RxWakeDisableInt
    ****************************************************************************//**
    *
    *  This function disables the interrupt (RX_WAKE) pending status in the NVIC.  
    *
    *******************************************************************************/
    #define cyUart_p50_p51_RxWakeDisableInt() CyIntDisable(cyUart_p50_p51_RX_WAKE_ISR_NUMBER)
    
    
    /*******************************************************************************
    * Function Name: cyUart_p50_p51_RxWakeClearPendingInt
    ****************************************************************************//**
    *
    *  This function clears the interrupt (RX_WAKE) pending status in the NVIC. 
    *
    *******************************************************************************/    
    #define cyUart_p50_p51_RxWakeClearPendingInt()  CyIntClearPending(cyUart_p50_p51_RX_WAKE_ISR_NUMBER)
#endif /* (cyUart_p50_p51_UART_RX_WAKEUP_IRQ) */

/**
* \addtogroup group_interrupt
* @{
*/
/* Get interrupt cause */
/*******************************************************************************
* Function Name: cyUart_p50_p51_GetInterruptCause
****************************************************************************//**
*
*  Returns a mask of bits showing the source of the current triggered interrupt. 
*  This is useful for modes of operation where an interrupt can be generated by 
*  conditions in multiple interrupt source registers.
*
*  \return
*   Mask with the OR of the following conditions that have been triggered.
*    - cyUart_p50_p51_INTR_CAUSE_MASTER - Interrupt from Master
*    - cyUart_p50_p51_INTR_CAUSE_SLAVE - Interrupt from Slave
*    - cyUart_p50_p51_INTR_CAUSE_TX - Interrupt from TX
*    - cyUart_p50_p51_INTR_CAUSE_RX - Interrupt from RX
*
*******************************************************************************/
#define cyUart_p50_p51_GetInterruptCause()    (cyUart_p50_p51_INTR_CAUSE_REG)


/* APIs to service INTR_RX register */
/*******************************************************************************
* Function Name: cyUart_p50_p51_GetRxInterruptSource
****************************************************************************//**
*
*  Returns RX interrupt request register. This register contains current status 
*  of RX interrupt sources.
*
*  \return
*   Current status of RX interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - cyUart_p50_p51_INTR_RX_FIFO_LEVEL - The number of data elements in the 
      RX FIFO is greater than the value of RX FIFO level.
*   - cyUart_p50_p51_INTR_RX_NOT_EMPTY - Receiver FIFO is not empty.
*   - cyUart_p50_p51_INTR_RX_FULL - Receiver FIFO is full.
*   - cyUart_p50_p51_INTR_RX_OVERFLOW - Attempt to write to a full 
*     receiver FIFO.
*   - cyUart_p50_p51_INTR_RX_UNDERFLOW - Attempt to read from an empty 
*     receiver FIFO.
*   - cyUart_p50_p51_INTR_RX_FRAME_ERROR - UART framing error detected.
*   - cyUart_p50_p51_INTR_RX_PARITY_ERROR - UART parity error detected.
*
*******************************************************************************/
#define cyUart_p50_p51_GetRxInterruptSource() (cyUart_p50_p51_INTR_RX_REG)


/*******************************************************************************
* Function Name: cyUart_p50_p51_SetRxInterruptMode
****************************************************************************//**
*
*  Writes RX interrupt mask register. This register configures which bits from 
*  RX interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: RX interrupt sources to be enabled (refer to 
*   cyUart_p50_p51_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetRxInterruptMode(interruptMask)     cyUart_p50_p51_WRITE_INTR_RX_MASK(interruptMask)


/*******************************************************************************
* Function Name: cyUart_p50_p51_GetRxInterruptMode
****************************************************************************//**
*
*  Returns RX interrupt mask register This register specifies which bits from 
*  RX interrupt request register will trigger an interrupt event.
*
*  \return 
*   RX interrupt sources to be enabled (refer to 
*   cyUart_p50_p51_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define cyUart_p50_p51_GetRxInterruptMode()   (cyUart_p50_p51_INTR_RX_MASK_REG)


/*******************************************************************************
* Function Name: cyUart_p50_p51_GetRxInterruptSourceMasked
****************************************************************************//**
*
*  Returns RX interrupt masked request register. This register contains logical
*  AND of corresponding bits from RX interrupt request and mask registers.
*  This function is intended to be used in the interrupt service routine to 
*  identify which of enabled RX interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled RX interrupt sources (refer to 
*   cyUart_p50_p51_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define cyUart_p50_p51_GetRxInterruptSourceMasked()   (cyUart_p50_p51_INTR_RX_MASKED_REG)


/*******************************************************************************
* Function Name: cyUart_p50_p51_ClearRxInterruptSource
****************************************************************************//**
*
*  Clears RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to be cleared (refer to 
*   cyUart_p50_p51_GetRxInterruptSource() function for bit fields values).
*
*  \sideeffects 
*   The side effects are listed in the table below for each 
*   affected interrupt source. Refer to section RX FIFO interrupt sources for 
*   detailed description.
*   - cyUart_p50_p51_INTR_RX_FIFO_LEVEL Interrupt source is not cleared when 
*     the receiver FIFO has more entries than level.
*   - cyUart_p50_p51_INTR_RX_NOT_EMPTY Interrupt source is not cleared when
*     receiver FIFO is not empty.
*   - cyUart_p50_p51_INTR_RX_FULL Interrupt source is not cleared when 
*      receiver FIFO is full.
*
*******************************************************************************/
#define cyUart_p50_p51_ClearRxInterruptSource(interruptMask)  cyUart_p50_p51_CLEAR_INTR_RX(interruptMask)


/*******************************************************************************
* Function Name: cyUart_p50_p51_SetRxInterrupt
****************************************************************************//**
*
*  Sets RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to set in the RX interrupt request 
*   register (refer to cyUart_p50_p51_GetRxInterruptSource() function for bit 
*   fields values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetRxInterrupt(interruptMask)  cyUart_p50_p51_SET_INTR_RX(interruptMask)

void cyUart_p50_p51_SetRxFifoLevel(uint32 level);


/* APIs to service INTR_TX register */
/*******************************************************************************
* Function Name: cyUart_p50_p51_GetTxInterruptSource
****************************************************************************//**
*
*  Returns TX interrupt request register. This register contains current status 
*  of TX interrupt sources.
* 
*  \return 
*   Current status of TX interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - cyUart_p50_p51_INTR_TX_FIFO_LEVEL - The number of data elements in the 
*     TX FIFO is less than the value of TX FIFO level.
*   - cyUart_p50_p51_INTR_TX_NOT_FULL - Transmitter FIFO is not full.
*   - cyUart_p50_p51_INTR_TX_EMPTY - Transmitter FIFO is empty.
*   - cyUart_p50_p51_INTR_TX_OVERFLOW - Attempt to write to a full 
*     transmitter FIFO.
*   - cyUart_p50_p51_INTR_TX_UNDERFLOW - Attempt to read from an empty 
*     transmitter FIFO.
*   - cyUart_p50_p51_INTR_TX_UART_NACK - UART received a NACK in SmartCard 
*   mode.
*   - cyUart_p50_p51_INTR_TX_UART_DONE - UART transfer is complete. 
*     All data elements from the TX FIFO are sent.
*   - cyUart_p50_p51_INTR_TX_UART_ARB_LOST - Value on the TX line of the UART
*     does not match the value on the RX line.
*
*******************************************************************************/
#define cyUart_p50_p51_GetTxInterruptSource() (cyUart_p50_p51_INTR_TX_REG)


/*******************************************************************************
* Function Name: cyUart_p50_p51_SetTxInterruptMode
****************************************************************************//**
*
*  Writes TX interrupt mask register. This register configures which bits from 
*  TX interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: TX interrupt sources to be enabled (refer to 
*   cyUart_p50_p51_GetTxInterruptSource() function for bit field values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetTxInterruptMode(interruptMask)  cyUart_p50_p51_WRITE_INTR_TX_MASK(interruptMask)


/*******************************************************************************
* Function Name: cyUart_p50_p51_GetTxInterruptMode
****************************************************************************//**
*
*  Returns TX interrupt mask register This register specifies which bits from 
*  TX interrupt request register will trigger an interrupt event.
*
*  \return 
*   Enabled TX interrupt sources (refer to 
*   cyUart_p50_p51_GetTxInterruptSource() function for bit field values).
*   
*******************************************************************************/
#define cyUart_p50_p51_GetTxInterruptMode()   (cyUart_p50_p51_INTR_TX_MASK_REG)


/*******************************************************************************
* Function Name: cyUart_p50_p51_GetTxInterruptSourceMasked
****************************************************************************//**
*
*  Returns TX interrupt masked request register. This register contains logical
*  AND of corresponding bits from TX interrupt request and mask registers.
*  This function is intended to be used in the interrupt service routine to identify 
*  which of enabled TX interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled TX interrupt sources (refer to 
*   cyUart_p50_p51_GetTxInterruptSource() function for bit field values).
*
*******************************************************************************/
#define cyUart_p50_p51_GetTxInterruptSourceMasked()   (cyUart_p50_p51_INTR_TX_MASKED_REG)


/*******************************************************************************
* Function Name: cyUart_p50_p51_ClearTxInterruptSource
****************************************************************************//**
*
*  Clears TX interrupt sources in the interrupt request register.
*
*  \param interruptMask: TX interrupt sources to be cleared (refer to 
*   cyUart_p50_p51_GetTxInterruptSource() function for bit field values).
*
*  \sideeffects 
*   The side effects are listed in the table below for each affected interrupt 
*   source. Refer to section TX FIFO interrupt sources for detailed description.
*   - cyUart_p50_p51_INTR_TX_FIFO_LEVEL - Interrupt source is not cleared when 
*     transmitter FIFO has less entries than level.
*   - cyUart_p50_p51_INTR_TX_NOT_FULL - Interrupt source is not cleared when
*     transmitter FIFO has empty entries.
*   - cyUart_p50_p51_INTR_TX_EMPTY - Interrupt source is not cleared when 
*     transmitter FIFO is empty.
*   - cyUart_p50_p51_INTR_TX_UNDERFLOW - Interrupt source is not cleared when 
*     transmitter FIFO is empty and I2C mode with clock stretching is selected. 
*     Put data into the transmitter FIFO before clearing it. This behavior only 
*     applicable for PSoC 4100/PSoC 4200 devices.
*
*******************************************************************************/
#define cyUart_p50_p51_ClearTxInterruptSource(interruptMask)  cyUart_p50_p51_CLEAR_INTR_TX(interruptMask)


/*******************************************************************************
* Function Name: cyUart_p50_p51_SetTxInterrupt
****************************************************************************//**
*
*  Sets RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to set in the RX interrupt request 
*   register (refer to cyUart_p50_p51_GetRxInterruptSource() function for bit 
*   fields values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetTxInterrupt(interruptMask)  cyUart_p50_p51_SET_INTR_TX(interruptMask)

void cyUart_p50_p51_SetTxFifoLevel(uint32 level);


/* APIs to service INTR_MASTER register */
/*******************************************************************************
* Function Name: cyUart_p50_p51_GetMasterInterruptSource
****************************************************************************//**
*
*  Returns Master interrupt request register. This register contains current 
*  status of Master interrupt sources.
*
*  \return 
*   Current status of Master interrupt sources. 
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - cyUart_p50_p51_INTR_MASTER_SPI_DONE - SPI master transfer is complete.
*     Refer to Interrupt sources section for detailed description.
*   - cyUart_p50_p51_INTR_MASTER_I2C_ARB_LOST - I2C master lost arbitration.
*   - cyUart_p50_p51_INTR_MASTER_I2C_NACK - I2C master received negative 
*    acknowledgement (NAK).
*   - cyUart_p50_p51_INTR_MASTER_I2C_ACK - I2C master received acknowledgement.
*   - cyUart_p50_p51_INTR_MASTER_I2C_STOP - I2C master generated STOP.
*   - cyUart_p50_p51_INTR_MASTER_I2C_BUS_ERROR - I2C master bus error 
*     (detection of unexpected START or STOP condition).
*
*******************************************************************************/
#define cyUart_p50_p51_GetMasterInterruptSource() (cyUart_p50_p51_INTR_MASTER_REG)

/*******************************************************************************
* Function Name: cyUart_p50_p51_SetMasterInterruptMode
****************************************************************************//**
*
*  Writes Master interrupt mask register. This register configures which bits 
*  from Master interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: Master interrupt sources to be enabled (refer to 
*   cyUart_p50_p51_GetMasterInterruptSource() function for bit field values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetMasterInterruptMode(interruptMask)  cyUart_p50_p51_WRITE_INTR_MASTER_MASK(interruptMask)

/*******************************************************************************
* Function Name: cyUart_p50_p51_GetMasterInterruptMode
****************************************************************************//**
*
*  Returns Master interrupt mask register This register specifies which bits 
*  from Master interrupt request register will trigger an interrupt event.
*
*  \return 
*   Enabled Master interrupt sources (refer to 
*   cyUart_p50_p51_GetMasterInterruptSource() function for return values).
*
*******************************************************************************/
#define cyUart_p50_p51_GetMasterInterruptMode()   (cyUart_p50_p51_INTR_MASTER_MASK_REG)

/*******************************************************************************
* Function Name: cyUart_p50_p51_GetMasterInterruptSourceMasked
****************************************************************************//**
*
*  Returns Master interrupt masked request register. This register contains 
*  logical AND of corresponding bits from Master interrupt request and mask 
*  registers.
*  This function is intended to be used in the interrupt service routine to 
*  identify which of enabled Master interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled Master interrupt sources (refer to 
*   cyUart_p50_p51_GetMasterInterruptSource() function for return values).
*
*******************************************************************************/
#define cyUart_p50_p51_GetMasterInterruptSourceMasked()   (cyUart_p50_p51_INTR_MASTER_MASKED_REG)

/*******************************************************************************
* Function Name: cyUart_p50_p51_ClearMasterInterruptSource
****************************************************************************//**
*
*  Clears Master interrupt sources in the interrupt request register.
*
*  \param interruptMask: Master interrupt sources to be cleared (refer to 
*   cyUart_p50_p51_GetMasterInterruptSource() function for bit field values).
*
*******************************************************************************/
#define cyUart_p50_p51_ClearMasterInterruptSource(interruptMask)  cyUart_p50_p51_CLEAR_INTR_MASTER(interruptMask)

/*******************************************************************************
* Function Name: cyUart_p50_p51_SetMasterInterrupt
****************************************************************************//**
*
*  Sets Master interrupt sources in the interrupt request register.
*
*  \param interruptMask: Master interrupt sources to set in the Master interrupt
*   request register (refer to cyUart_p50_p51_GetMasterInterruptSource() 
*   function for bit field values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetMasterInterrupt(interruptMask)  cyUart_p50_p51_SET_INTR_MASTER(interruptMask)


/* APIs to service INTR_SLAVE register */
/*******************************************************************************
* Function Name: cyUart_p50_p51_GetSlaveInterruptSource
****************************************************************************//**
*
*  Returns Slave interrupt request register. This register contains current 
*  status of Slave interrupt sources.
*
*  \return 
*   Current status of Slave interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - cyUart_p50_p51_INTR_SLAVE_I2C_ARB_LOST - I2C slave lost arbitration: 
*     the value driven on the SDA line is not the same as the value observed 
*     on the SDA line.
*   - cyUart_p50_p51_INTR_SLAVE_I2C_NACK - I2C slave received negative 
*     acknowledgement (NAK).
*   - cyUart_p50_p51_INTR_SLAVE_I2C_ACK - I2C slave received 
*     acknowledgement (ACK).
*   - cyUart_p50_p51_INTR_SLAVE_I2C_WRITE_STOP - Stop or Repeated Start 
*     event for write transfer intended for this slave (address matching 
*     is performed).
*   - cyUart_p50_p51_INTR_SLAVE_I2C_STOP - Stop or Repeated Start event 
*     for (read or write) transfer intended for this slave (address matching 
*     is performed).
*   - cyUart_p50_p51_INTR_SLAVE_I2C_START - I2C slave received Start 
*     condition.
*   - cyUart_p50_p51_INTR_SLAVE_I2C_ADDR_MATCH - I2C slave received matching 
*     address.
*   - cyUart_p50_p51_INTR_SLAVE_I2C_GENERAL - I2C Slave received general 
*     call address.
*   - cyUart_p50_p51_INTR_SLAVE_I2C_BUS_ERROR - I2C slave bus error (detection 
*      of unexpected Start or Stop condition).
*   - cyUart_p50_p51_INTR_SLAVE_SPI_BUS_ERROR - SPI slave select line is 
*      deselected at an expected time while the SPI transfer.
*
*******************************************************************************/
#define cyUart_p50_p51_GetSlaveInterruptSource()  (cyUart_p50_p51_INTR_SLAVE_REG)

/*******************************************************************************
* Function Name: cyUart_p50_p51_SetSlaveInterruptMode
****************************************************************************//**
*
*  Writes Slave interrupt mask register. 
*  This register configures which bits from Slave interrupt request register 
*  will trigger an interrupt event.
*
*  \param interruptMask: Slave interrupt sources to be enabled (refer to 
*   cyUart_p50_p51_GetSlaveInterruptSource() function for bit field values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetSlaveInterruptMode(interruptMask)   cyUart_p50_p51_WRITE_INTR_SLAVE_MASK(interruptMask)

/*******************************************************************************
* Function Name: cyUart_p50_p51_GetSlaveInterruptMode
****************************************************************************//**
*
*  Returns Slave interrupt mask register.
*  This register specifies which bits from Slave interrupt request register 
*  will trigger an interrupt event.
*
*  \return 
*   Enabled Slave interrupt sources(refer to 
*   cyUart_p50_p51_GetSlaveInterruptSource() function for bit field values).
*
*******************************************************************************/
#define cyUart_p50_p51_GetSlaveInterruptMode()    (cyUart_p50_p51_INTR_SLAVE_MASK_REG)

/*******************************************************************************
* Function Name: cyUart_p50_p51_GetSlaveInterruptSourceMasked
****************************************************************************//**
*
*  Returns Slave interrupt masked request register. This register contains 
*  logical AND of corresponding bits from Slave interrupt request and mask 
*  registers.
*  This function is intended to be used in the interrupt service routine to 
*  identify which of enabled Slave interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled Slave interrupt sources (refer to 
*   cyUart_p50_p51_GetSlaveInterruptSource() function for return values).
*
*******************************************************************************/
#define cyUart_p50_p51_GetSlaveInterruptSourceMasked()    (cyUart_p50_p51_INTR_SLAVE_MASKED_REG)

/*******************************************************************************
* Function Name: cyUart_p50_p51_ClearSlaveInterruptSource
****************************************************************************//**
*
*  Clears Slave interrupt sources in the interrupt request register.
*
*  \param interruptMask: Slave interrupt sources to be cleared (refer to 
*   cyUart_p50_p51_GetSlaveInterruptSource() function for return values).
*
*******************************************************************************/
#define cyUart_p50_p51_ClearSlaveInterruptSource(interruptMask)   cyUart_p50_p51_CLEAR_INTR_SLAVE(interruptMask)

/*******************************************************************************
* Function Name: cyUart_p50_p51_SetSlaveInterrupt
****************************************************************************//**
*
*  Sets Slave interrupt sources in the interrupt request register.
*
*  \param interruptMask: Slave interrupt sources to set in the Slave interrupt 
*   request register (refer to cyUart_p50_p51_GetSlaveInterruptSource() 
*   function for return values).
*
*******************************************************************************/
#define cyUart_p50_p51_SetSlaveInterrupt(interruptMask)   cyUart_p50_p51_SET_INTR_SLAVE(interruptMask)

/** @} interrupt */ 


/***************************************
*     Vars with External Linkage
***************************************/

/**
* \addtogroup group_globals
* @{
*/

/** cyUart_p50_p51_initVar indicates whether the cyUart_p50_p51 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the cyUart_p50_p51_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  cyUart_p50_p51_Init() function can be called before the 
*  cyUart_p50_p51_Start() or cyUart_p50_p51_Enable() function.
*/
extern uint8 cyUart_p50_p51_initVar;
/** @} globals */

/***************************************
*              Registers
***************************************/

#define cyUart_p50_p51_CTRL_REG               (*(reg32 *) cyUart_p50_p51_SCB__CTRL)
#define cyUart_p50_p51_CTRL_PTR               ( (reg32 *) cyUart_p50_p51_SCB__CTRL)

#define cyUart_p50_p51_STATUS_REG             (*(reg32 *) cyUart_p50_p51_SCB__STATUS)
#define cyUart_p50_p51_STATUS_PTR             ( (reg32 *) cyUart_p50_p51_SCB__STATUS)

#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_SPI_CTRL_REG           (*(reg32 *) cyUart_p50_p51_SCB__SPI_CTRL)
    #define cyUart_p50_p51_SPI_CTRL_PTR           ( (reg32 *) cyUart_p50_p51_SCB__SPI_CTRL)

    #define cyUart_p50_p51_SPI_STATUS_REG         (*(reg32 *) cyUart_p50_p51_SCB__SPI_STATUS)
    #define cyUart_p50_p51_SPI_STATUS_PTR         ( (reg32 *) cyUart_p50_p51_SCB__SPI_STATUS)

    #define cyUart_p50_p51_UART_CTRL_REG          (*(reg32 *) cyUart_p50_p51_SCB__UART_CTRL)
    #define cyUart_p50_p51_UART_CTRL_PTR          ( (reg32 *) cyUart_p50_p51_SCB__UART_CTRL)

    #define cyUart_p50_p51_UART_TX_CTRL_REG       (*(reg32 *) cyUart_p50_p51_SCB__UART_TX_CTRL)
    #define cyUart_p50_p51_UART_TX_CTRL_PTR       ( (reg32 *) cyUart_p50_p51_SCB__UART_TX_CTRL)

    #define cyUart_p50_p51_UART_RX_CTRL_REG       (*(reg32 *) cyUart_p50_p51_SCB__UART_RX_CTRL)
    #define cyUart_p50_p51_UART_RX_CTRL_PTR       ( (reg32 *) cyUart_p50_p51_SCB__UART_RX_CTRL)

    #define cyUart_p50_p51_UART_RX_STATUS_REG     (*(reg32 *) cyUart_p50_p51_SCB__UART_RX_STATUS)
    #define cyUart_p50_p51_UART_RX_STATUS_PTR     ( (reg32 *) cyUart_p50_p51_SCB__UART_RX_STATUS)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

#if !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_UART_FLOW_CTRL_REG     (*(reg32 *) cyUart_p50_p51_SCB__UART_FLOW_CTRL)
    #define cyUart_p50_p51_UART_FLOW_CTRL_PTR     ( (reg32 *) cyUart_p50_p51_SCB__UART_FLOW_CTRL)
#endif /* !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_I2C_CTRL_REG           (*(reg32 *) cyUart_p50_p51_SCB__I2C_CTRL)
#define cyUart_p50_p51_I2C_CTRL_PTR           ( (reg32 *) cyUart_p50_p51_SCB__I2C_CTRL)

#define cyUart_p50_p51_I2C_STATUS_REG         (*(reg32 *) cyUart_p50_p51_SCB__I2C_STATUS)
#define cyUart_p50_p51_I2C_STATUS_PTR         ( (reg32 *) cyUart_p50_p51_SCB__I2C_STATUS)

#define cyUart_p50_p51_I2C_MASTER_CMD_REG     (*(reg32 *) cyUart_p50_p51_SCB__I2C_M_CMD)
#define cyUart_p50_p51_I2C_MASTER_CMD_PTR     ( (reg32 *) cyUart_p50_p51_SCB__I2C_M_CMD)

#define cyUart_p50_p51_I2C_SLAVE_CMD_REG      (*(reg32 *) cyUart_p50_p51_SCB__I2C_S_CMD)
#define cyUart_p50_p51_I2C_SLAVE_CMD_PTR      ( (reg32 *) cyUart_p50_p51_SCB__I2C_S_CMD)

#define cyUart_p50_p51_I2C_CFG_REG            (*(reg32 *) cyUart_p50_p51_SCB__I2C_CFG)
#define cyUart_p50_p51_I2C_CFG_PTR            ( (reg32 *) cyUart_p50_p51_SCB__I2C_CFG)

#define cyUart_p50_p51_TX_CTRL_REG            (*(reg32 *) cyUart_p50_p51_SCB__TX_CTRL)
#define cyUart_p50_p51_TX_CTRL_PTR            ( (reg32 *) cyUart_p50_p51_SCB__TX_CTRL)

#define cyUart_p50_p51_TX_FIFO_CTRL_REG       (*(reg32 *) cyUart_p50_p51_SCB__TX_FIFO_CTRL)
#define cyUart_p50_p51_TX_FIFO_CTRL_PTR       ( (reg32 *) cyUart_p50_p51_SCB__TX_FIFO_CTRL)

#define cyUart_p50_p51_TX_FIFO_STATUS_REG     (*(reg32 *) cyUart_p50_p51_SCB__TX_FIFO_STATUS)
#define cyUart_p50_p51_TX_FIFO_STATUS_PTR     ( (reg32 *) cyUart_p50_p51_SCB__TX_FIFO_STATUS)

#define cyUart_p50_p51_TX_FIFO_WR_REG         (*(reg32 *) cyUart_p50_p51_SCB__TX_FIFO_WR)
#define cyUart_p50_p51_TX_FIFO_WR_PTR         ( (reg32 *) cyUart_p50_p51_SCB__TX_FIFO_WR)

#define cyUart_p50_p51_RX_CTRL_REG            (*(reg32 *) cyUart_p50_p51_SCB__RX_CTRL)
#define cyUart_p50_p51_RX_CTRL_PTR            ( (reg32 *) cyUart_p50_p51_SCB__RX_CTRL)

#define cyUart_p50_p51_RX_FIFO_CTRL_REG       (*(reg32 *) cyUart_p50_p51_SCB__RX_FIFO_CTRL)
#define cyUart_p50_p51_RX_FIFO_CTRL_PTR       ( (reg32 *) cyUart_p50_p51_SCB__RX_FIFO_CTRL)

#define cyUart_p50_p51_RX_FIFO_STATUS_REG     (*(reg32 *) cyUart_p50_p51_SCB__RX_FIFO_STATUS)
#define cyUart_p50_p51_RX_FIFO_STATUS_PTR     ( (reg32 *) cyUart_p50_p51_SCB__RX_FIFO_STATUS)

#define cyUart_p50_p51_RX_MATCH_REG           (*(reg32 *) cyUart_p50_p51_SCB__RX_MATCH)
#define cyUart_p50_p51_RX_MATCH_PTR           ( (reg32 *) cyUart_p50_p51_SCB__RX_MATCH)

#define cyUart_p50_p51_RX_FIFO_RD_REG         (*(reg32 *) cyUart_p50_p51_SCB__RX_FIFO_RD)
#define cyUart_p50_p51_RX_FIFO_RD_PTR         ( (reg32 *) cyUart_p50_p51_SCB__RX_FIFO_RD)

#define cyUart_p50_p51_RX_FIFO_RD_SILENT_REG  (*(reg32 *) cyUart_p50_p51_SCB__RX_FIFO_RD_SILENT)
#define cyUart_p50_p51_RX_FIFO_RD_SILENT_PTR  ( (reg32 *) cyUart_p50_p51_SCB__RX_FIFO_RD_SILENT)

#ifdef cyUart_p50_p51_SCB__EZ_DATA0
    #define cyUart_p50_p51_EZBUF_DATA0_REG    (*(reg32 *) cyUart_p50_p51_SCB__EZ_DATA0)
    #define cyUart_p50_p51_EZBUF_DATA0_PTR    ( (reg32 *) cyUart_p50_p51_SCB__EZ_DATA0)
#else
    #define cyUart_p50_p51_EZBUF_DATA0_REG    (*(reg32 *) cyUart_p50_p51_SCB__EZ_DATA00)
    #define cyUart_p50_p51_EZBUF_DATA0_PTR    ( (reg32 *) cyUart_p50_p51_SCB__EZ_DATA00)
#endif /* cyUart_p50_p51_SCB__EZ_DATA00 */

#define cyUart_p50_p51_INTR_CAUSE_REG         (*(reg32 *) cyUart_p50_p51_SCB__INTR_CAUSE)
#define cyUart_p50_p51_INTR_CAUSE_PTR         ( (reg32 *) cyUart_p50_p51_SCB__INTR_CAUSE)

#define cyUart_p50_p51_INTR_I2C_EC_REG        (*(reg32 *) cyUart_p50_p51_SCB__INTR_I2C_EC)
#define cyUart_p50_p51_INTR_I2C_EC_PTR        ( (reg32 *) cyUart_p50_p51_SCB__INTR_I2C_EC)

#define cyUart_p50_p51_INTR_I2C_EC_MASK_REG   (*(reg32 *) cyUart_p50_p51_SCB__INTR_I2C_EC_MASK)
#define cyUart_p50_p51_INTR_I2C_EC_MASK_PTR   ( (reg32 *) cyUart_p50_p51_SCB__INTR_I2C_EC_MASK)

#define cyUart_p50_p51_INTR_I2C_EC_MASKED_REG (*(reg32 *) cyUart_p50_p51_SCB__INTR_I2C_EC_MASKED)
#define cyUart_p50_p51_INTR_I2C_EC_MASKED_PTR ( (reg32 *) cyUart_p50_p51_SCB__INTR_I2C_EC_MASKED)

#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_INTR_SPI_EC_REG        (*(reg32 *) cyUart_p50_p51_SCB__INTR_SPI_EC)
    #define cyUart_p50_p51_INTR_SPI_EC_PTR        ( (reg32 *) cyUart_p50_p51_SCB__INTR_SPI_EC)

    #define cyUart_p50_p51_INTR_SPI_EC_MASK_REG   (*(reg32 *) cyUart_p50_p51_SCB__INTR_SPI_EC_MASK)
    #define cyUart_p50_p51_INTR_SPI_EC_MASK_PTR   ( (reg32 *) cyUart_p50_p51_SCB__INTR_SPI_EC_MASK)

    #define cyUart_p50_p51_INTR_SPI_EC_MASKED_REG (*(reg32 *) cyUart_p50_p51_SCB__INTR_SPI_EC_MASKED)
    #define cyUart_p50_p51_INTR_SPI_EC_MASKED_PTR ( (reg32 *) cyUart_p50_p51_SCB__INTR_SPI_EC_MASKED)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_INTR_MASTER_REG        (*(reg32 *) cyUart_p50_p51_SCB__INTR_M)
#define cyUart_p50_p51_INTR_MASTER_PTR        ( (reg32 *) cyUart_p50_p51_SCB__INTR_M)

#define cyUart_p50_p51_INTR_MASTER_SET_REG    (*(reg32 *) cyUart_p50_p51_SCB__INTR_M_SET)
#define cyUart_p50_p51_INTR_MASTER_SET_PTR    ( (reg32 *) cyUart_p50_p51_SCB__INTR_M_SET)

#define cyUart_p50_p51_INTR_MASTER_MASK_REG   (*(reg32 *) cyUart_p50_p51_SCB__INTR_M_MASK)
#define cyUart_p50_p51_INTR_MASTER_MASK_PTR   ( (reg32 *) cyUart_p50_p51_SCB__INTR_M_MASK)

#define cyUart_p50_p51_INTR_MASTER_MASKED_REG (*(reg32 *) cyUart_p50_p51_SCB__INTR_M_MASKED)
#define cyUart_p50_p51_INTR_MASTER_MASKED_PTR ( (reg32 *) cyUart_p50_p51_SCB__INTR_M_MASKED)

#define cyUart_p50_p51_INTR_SLAVE_REG         (*(reg32 *) cyUart_p50_p51_SCB__INTR_S)
#define cyUart_p50_p51_INTR_SLAVE_PTR         ( (reg32 *) cyUart_p50_p51_SCB__INTR_S)

#define cyUart_p50_p51_INTR_SLAVE_SET_REG     (*(reg32 *) cyUart_p50_p51_SCB__INTR_S_SET)
#define cyUart_p50_p51_INTR_SLAVE_SET_PTR     ( (reg32 *) cyUart_p50_p51_SCB__INTR_S_SET)

#define cyUart_p50_p51_INTR_SLAVE_MASK_REG    (*(reg32 *) cyUart_p50_p51_SCB__INTR_S_MASK)
#define cyUart_p50_p51_INTR_SLAVE_MASK_PTR    ( (reg32 *) cyUart_p50_p51_SCB__INTR_S_MASK)

#define cyUart_p50_p51_INTR_SLAVE_MASKED_REG  (*(reg32 *) cyUart_p50_p51_SCB__INTR_S_MASKED)
#define cyUart_p50_p51_INTR_SLAVE_MASKED_PTR  ( (reg32 *) cyUart_p50_p51_SCB__INTR_S_MASKED)

#define cyUart_p50_p51_INTR_TX_REG            (*(reg32 *) cyUart_p50_p51_SCB__INTR_TX)
#define cyUart_p50_p51_INTR_TX_PTR            ( (reg32 *) cyUart_p50_p51_SCB__INTR_TX)

#define cyUart_p50_p51_INTR_TX_SET_REG        (*(reg32 *) cyUart_p50_p51_SCB__INTR_TX_SET)
#define cyUart_p50_p51_INTR_TX_SET_PTR        ( (reg32 *) cyUart_p50_p51_SCB__INTR_TX_SET)

#define cyUart_p50_p51_INTR_TX_MASK_REG       (*(reg32 *) cyUart_p50_p51_SCB__INTR_TX_MASK)
#define cyUart_p50_p51_INTR_TX_MASK_PTR       ( (reg32 *) cyUart_p50_p51_SCB__INTR_TX_MASK)

#define cyUart_p50_p51_INTR_TX_MASKED_REG     (*(reg32 *) cyUart_p50_p51_SCB__INTR_TX_MASKED)
#define cyUart_p50_p51_INTR_TX_MASKED_PTR     ( (reg32 *) cyUart_p50_p51_SCB__INTR_TX_MASKED)

#define cyUart_p50_p51_INTR_RX_REG            (*(reg32 *) cyUart_p50_p51_SCB__INTR_RX)
#define cyUart_p50_p51_INTR_RX_PTR            ( (reg32 *) cyUart_p50_p51_SCB__INTR_RX)

#define cyUart_p50_p51_INTR_RX_SET_REG        (*(reg32 *) cyUart_p50_p51_SCB__INTR_RX_SET)
#define cyUart_p50_p51_INTR_RX_SET_PTR        ( (reg32 *) cyUart_p50_p51_SCB__INTR_RX_SET)

#define cyUart_p50_p51_INTR_RX_MASK_REG       (*(reg32 *) cyUart_p50_p51_SCB__INTR_RX_MASK)
#define cyUart_p50_p51_INTR_RX_MASK_PTR       ( (reg32 *) cyUart_p50_p51_SCB__INTR_RX_MASK)

#define cyUart_p50_p51_INTR_RX_MASKED_REG     (*(reg32 *) cyUart_p50_p51_SCB__INTR_RX_MASKED)
#define cyUart_p50_p51_INTR_RX_MASKED_PTR     ( (reg32 *) cyUart_p50_p51_SCB__INTR_RX_MASKED)

/* Defines get from SCB IP parameters. */
#define cyUart_p50_p51_FIFO_SIZE      (8u)  /* TX or RX FIFO size. */
#define cyUart_p50_p51_EZ_DATA_NR     (32u)  /* Number of words in EZ memory. */ 
#define cyUart_p50_p51_ONE_BYTE_WIDTH (8u)            /* Number of bits in one byte. */
#define cyUart_p50_p51_FF_DATA_NR_LOG2_MASK       (0x0Fu)      /* Number of bits to represent a FIFO address. */
#define cyUart_p50_p51_FF_DATA_NR_LOG2_PLUS1_MASK (0x1Fu) /* Number of bits to represent #bytes in FIFO. */


/***************************************
*        Registers Constants
***************************************/

#if (cyUart_p50_p51_SCB_IRQ_INTERNAL)
    #define cyUart_p50_p51_ISR_NUMBER     ((uint8) cyUart_p50_p51_SCB_IRQ__INTC_NUMBER)
    #define cyUart_p50_p51_ISR_PRIORITY   ((uint8) cyUart_p50_p51_SCB_IRQ__INTC_PRIOR_NUM)
#endif /* (cyUart_p50_p51_SCB_IRQ_INTERNAL) */

#if (cyUart_p50_p51_UART_RX_WAKEUP_IRQ)
    #define cyUart_p50_p51_RX_WAKE_ISR_NUMBER     ((uint8) cyUart_p50_p51_RX_WAKEUP_IRQ__INTC_NUMBER)
    #define cyUart_p50_p51_RX_WAKE_ISR_PRIORITY   ((uint8) cyUart_p50_p51_RX_WAKEUP_IRQ__INTC_PRIOR_NUM)
#endif /* (cyUart_p50_p51_UART_RX_WAKEUP_IRQ) */

/* cyUart_p50_p51_CTRL_REG */
#define cyUart_p50_p51_CTRL_OVS_POS           (0u)  /* [3:0]   Oversampling factor                 */
#define cyUart_p50_p51_CTRL_EC_AM_MODE_POS    (8u)  /* [8]     Externally clocked address match    */
#define cyUart_p50_p51_CTRL_EC_OP_MODE_POS    (9u)  /* [9]     Externally clocked operation mode   */
#define cyUart_p50_p51_CTRL_EZBUF_MODE_POS    (10u) /* [10]    EZ buffer is enabled                */
#if !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_CTRL_BYTE_MODE_POS (11u) /* [11]    Determines the number of bits per FIFO data element */
#endif /* !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */
#define cyUart_p50_p51_CTRL_ADDR_ACCEPT_POS   (16u) /* [16]    Put matched address in RX FIFO       */
#define cyUart_p50_p51_CTRL_BLOCK_POS         (17u) /* [17]    Ext and Int logic to resolve collide */
#define cyUart_p50_p51_CTRL_MODE_POS          (24u) /* [25:24] Operation mode                       */
#define cyUart_p50_p51_CTRL_ENABLED_POS       (31u) /* [31]    Enable SCB block                     */
#define cyUart_p50_p51_CTRL_OVS_MASK          ((uint32) 0x0Fu)
#define cyUart_p50_p51_CTRL_EC_AM_MODE        ((uint32) 0x01u << cyUart_p50_p51_CTRL_EC_AM_MODE_POS)
#define cyUart_p50_p51_CTRL_EC_OP_MODE        ((uint32) 0x01u << cyUart_p50_p51_CTRL_EC_OP_MODE_POS)
#define cyUart_p50_p51_CTRL_EZBUF_MODE        ((uint32) 0x01u << cyUart_p50_p51_CTRL_EZBUF_MODE_POS)
#if !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_CTRL_BYTE_MODE ((uint32) 0x01u << cyUart_p50_p51_CTRL_BYTE_MODE_POS)
#endif /* !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */
#define cyUart_p50_p51_CTRL_ADDR_ACCEPT       ((uint32) 0x01u << cyUart_p50_p51_CTRL_ADDR_ACCEPT_POS)
#define cyUart_p50_p51_CTRL_BLOCK             ((uint32) 0x01u << cyUart_p50_p51_CTRL_BLOCK_POS)
#define cyUart_p50_p51_CTRL_MODE_MASK         ((uint32) 0x03u << cyUart_p50_p51_CTRL_MODE_POS)
#define cyUart_p50_p51_CTRL_MODE_I2C          ((uint32) 0x00u)
#define cyUart_p50_p51_CTRL_MODE_SPI          ((uint32) 0x01u << cyUart_p50_p51_CTRL_MODE_POS)
#define cyUart_p50_p51_CTRL_MODE_UART         ((uint32) 0x02u << cyUart_p50_p51_CTRL_MODE_POS)
#define cyUart_p50_p51_CTRL_ENABLED           ((uint32) 0x01u << cyUart_p50_p51_CTRL_ENABLED_POS)

/* cyUart_p50_p51_STATUS_REG */
#define cyUart_p50_p51_STATUS_EC_BUSY_POS     (0u)  /* [0] Bus busy. Externally clocked logic access to EZ memory */
#define cyUart_p50_p51_STATUS_EC_BUSY         ((uint32) 0x0Fu)

/* cyUart_p50_p51_SPI_CTRL_REG  */
#define cyUart_p50_p51_SPI_CTRL_CONTINUOUS_POS        (0u)  /* [0]     Continuous or Separated SPI data transfers */
#define cyUart_p50_p51_SPI_CTRL_SELECT_PRECEDE_POS    (1u)  /* [1]     Precedes or coincides start of data frame  */
#define cyUart_p50_p51_SPI_CTRL_CPHA_POS              (2u)  /* [2]     SCLK phase                                 */
#define cyUart_p50_p51_SPI_CTRL_CPOL_POS              (3u)  /* [3]     SCLK polarity                              */
#define cyUart_p50_p51_SPI_CTRL_LATE_MISO_SAMPLE_POS  (4u)  /* [4]     Late MISO sample enabled                   */
#if !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_SPI_CTRL_SCLK_CONTINUOUS_POS   (5u)  /* [5]     Enable continuous SCLK generation */
    #define cyUart_p50_p51_SPI_CTRL_SSEL0_POLARITY_POS    (8u)  /* [8]     SS0 polarity                      */
    #define cyUart_p50_p51_SPI_CTRL_SSEL1_POLARITY_POS    (9u)  /* [9]     SS1 polarity                      */
    #define cyUart_p50_p51_SPI_CTRL_SSEL2_POLARITY_POS    (10u) /* [10]    SS2 polarity                      */
    #define cyUart_p50_p51_SPI_CTRL_SSEL3_POLARITY_POS    (11u) /* [11]    SS3 polarity                      */
#endif /* !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */
#define cyUart_p50_p51_SPI_CTRL_LOOPBACK_POS          (16u) /* [16]    Local loop-back control enabled            */
#define cyUart_p50_p51_SPI_CTRL_MODE_POS              (24u) /* [25:24] Submode of SPI operation                   */
#define cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_POS      (26u) /* [27:26] Selects SPI SS signal                      */
#define cyUart_p50_p51_SPI_CTRL_MASTER_MODE_POS       (31u) /* [31]    Master mode enabled                        */
#define cyUart_p50_p51_SPI_CTRL_CONTINUOUS            ((uint32) 0x01u)
#define cyUart_p50_p51_SPI_CTRL_SELECT_PRECEDE        ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_SELECT_PRECEDE_POS)
#define cyUart_p50_p51_SPI_CTRL_SCLK_MODE_MASK        ((uint32) 0x03u << cyUart_p50_p51_SPI_CTRL_CPHA_POS)
#define cyUart_p50_p51_SPI_CTRL_CPHA                  ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_CPHA_POS)
#define cyUart_p50_p51_SPI_CTRL_CPOL                  ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_CPOL_POS)
#define cyUart_p50_p51_SPI_CTRL_LATE_MISO_SAMPLE      ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_SPI_CTRL_LATE_MISO_SAMPLE_POS)
#if !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_SPI_CTRL_SCLK_CONTINUOUS  ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_SCLK_CONTINUOUS_POS)
    #define cyUart_p50_p51_SPI_CTRL_SSEL0_POLARITY   ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_SSEL0_POLARITY_POS)
    #define cyUart_p50_p51_SPI_CTRL_SSEL1_POLARITY   ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_SSEL1_POLARITY_POS)
    #define cyUart_p50_p51_SPI_CTRL_SSEL2_POLARITY   ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_SSEL2_POLARITY_POS)
    #define cyUart_p50_p51_SPI_CTRL_SSEL3_POLARITY   ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_SSEL3_POLARITY_POS)
    #define cyUart_p50_p51_SPI_CTRL_SSEL_POLARITY_MASK ((uint32)0x0Fu << cyUart_p50_p51_SPI_CTRL_SSEL0_POLARITY_POS)
#endif /* !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_SPI_CTRL_LOOPBACK              ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_LOOPBACK_POS)
#define cyUart_p50_p51_SPI_CTRL_MODE_MASK             ((uint32) 0x03u << cyUart_p50_p51_SPI_CTRL_MODE_POS)
#define cyUart_p50_p51_SPI_CTRL_MODE_MOTOROLA         ((uint32) 0x00u)
#define cyUart_p50_p51_SPI_CTRL_MODE_TI               ((uint32) 0x01u << cyUart_p50_p51_CTRL_MODE_POS)
#define cyUart_p50_p51_SPI_CTRL_MODE_NS               ((uint32) 0x02u << cyUart_p50_p51_CTRL_MODE_POS)
#define cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_MASK     ((uint32) 0x03u << cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_POS)
#define cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT0         ((uint32) 0x00u)
#define cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT1         ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_POS)
#define cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT2         ((uint32) 0x02u << cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_POS)
#define cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT3         ((uint32) 0x03u << cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_POS)
#define cyUart_p50_p51_SPI_CTRL_MASTER                ((uint32) 0x01u << cyUart_p50_p51_SPI_CTRL_MASTER_MODE_POS)
#define cyUart_p50_p51_SPI_CTRL_SLAVE                 ((uint32) 0x00u)

/* cyUart_p50_p51_SPI_STATUS_REG  */
#define cyUart_p50_p51_SPI_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy - slave selected */
#define cyUart_p50_p51_SPI_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EzAddress                 */
#define cyUart_p50_p51_SPI_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define cyUart_p50_p51_SPI_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << cyUart_p50_p51_I2C_STATUS_EZBUF_ADDR_POS)

/* cyUart_p50_p51_UART_CTRL */
#define cyUart_p50_p51_UART_CTRL_LOOPBACK_POS         (16u) /* [16] Loop-back    */
#define cyUart_p50_p51_UART_CTRL_MODE_POS             (24u) /* [24] UART subMode */
#define cyUart_p50_p51_UART_CTRL_LOOPBACK             ((uint32) 0x01u << cyUart_p50_p51_UART_CTRL_LOOPBACK_POS)
#define cyUart_p50_p51_UART_CTRL_MODE_UART_STD        ((uint32) 0x00u)
#define cyUart_p50_p51_UART_CTRL_MODE_UART_SMARTCARD  ((uint32) 0x01u << cyUart_p50_p51_UART_CTRL_MODE_POS)
#define cyUart_p50_p51_UART_CTRL_MODE_UART_IRDA       ((uint32) 0x02u << cyUart_p50_p51_UART_CTRL_MODE_POS)
#define cyUart_p50_p51_UART_CTRL_MODE_MASK            ((uint32) 0x03u << cyUart_p50_p51_UART_CTRL_MODE_POS)

/* cyUart_p50_p51_UART_TX_CTRL */
#define cyUart_p50_p51_UART_TX_CTRL_STOP_BITS_POS         (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period */
#define cyUart_p50_p51_UART_TX_CTRL_PARITY_POS            (4u)  /* [4]   Parity bit                              */
#define cyUart_p50_p51_UART_TX_CTRL_PARITY_ENABLED_POS    (5u)  /* [5]   Parity enable                           */
#define cyUart_p50_p51_UART_TX_CTRL_RETRY_ON_NACK_POS     (8u)  /* [8]   Smart Card: re-send frame on NACK       */
#define cyUart_p50_p51_UART_TX_CTRL_ONE_STOP_BIT          ((uint32) 0x01u)
#define cyUart_p50_p51_UART_TX_CTRL_ONE_HALF_STOP_BITS    ((uint32) 0x02u)
#define cyUart_p50_p51_UART_TX_CTRL_TWO_STOP_BITS         ((uint32) 0x03u)
#define cyUart_p50_p51_UART_TX_CTRL_STOP_BITS_MASK        ((uint32) 0x07u)
#define cyUart_p50_p51_UART_TX_CTRL_PARITY                ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_TX_CTRL_PARITY_POS)
#define cyUart_p50_p51_UART_TX_CTRL_PARITY_ENABLED        ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_TX_CTRL_PARITY_ENABLED_POS)
#define cyUart_p50_p51_UART_TX_CTRL_RETRY_ON_NACK         ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_TX_CTRL_RETRY_ON_NACK_POS)

/* cyUart_p50_p51_UART_RX_CTRL */
#define cyUart_p50_p51_UART_RX_CTRL_STOP_BITS_POS             (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period*/
#define cyUart_p50_p51_UART_RX_CTRL_PARITY_POS                (4u)  /* [4]   Parity bit                             */
#define cyUart_p50_p51_UART_RX_CTRL_PARITY_ENABLED_POS        (5u)  /* [5]   Parity enable                          */
#define cyUart_p50_p51_UART_RX_CTRL_POLARITY_POS              (6u)  /* [6]   IrDA: inverts polarity of RX signal    */
#define cyUart_p50_p51_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS    (8u)  /* [8]   Drop and lost RX FIFO on parity error  */
#define cyUart_p50_p51_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS     (9u)  /* [9]   Drop and lost RX FIFO on frame error   */
#define cyUart_p50_p51_UART_RX_CTRL_MP_MODE_POS               (10u) /* [10]  Multi-processor mode                   */
#define cyUart_p50_p51_UART_RX_CTRL_LIN_MODE_POS              (12u) /* [12]  Lin mode: applicable for UART Standard */
#define cyUart_p50_p51_UART_RX_CTRL_SKIP_START_POS            (13u) /* [13]  Skip start not: only for UART Standard */
#define cyUart_p50_p51_UART_RX_CTRL_BREAK_WIDTH_POS           (16u) /* [19:16]  Break width: (Break width + 1)      */
#define cyUart_p50_p51_UART_TX_CTRL_ONE_STOP_BIT              ((uint32) 0x01u)
#define cyUart_p50_p51_UART_TX_CTRL_ONE_HALF_STOP_BITS        ((uint32) 0x02u)
#define cyUart_p50_p51_UART_TX_CTRL_TWO_STOP_BITS             ((uint32) 0x03u)
#define cyUart_p50_p51_UART_RX_CTRL_STOP_BITS_MASK            ((uint32) 0x07u)
#define cyUart_p50_p51_UART_RX_CTRL_PARITY                    ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_PARITY_POS)
#define cyUart_p50_p51_UART_RX_CTRL_PARITY_ENABLED            ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_PARITY_ENABLED_POS)
#define cyUart_p50_p51_UART_RX_CTRL_POLARITY                  ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_POLARITY_POS)
#define cyUart_p50_p51_UART_RX_CTRL_DROP_ON_PARITY_ERR        ((uint32) 0x01u << \
                                                                   cyUart_p50_p51_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS)
#define cyUart_p50_p51_UART_RX_CTRL_DROP_ON_FRAME_ERR         ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS)
#define cyUart_p50_p51_UART_RX_CTRL_MP_MODE                   ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_MP_MODE_POS)
#define cyUart_p50_p51_UART_RX_CTRL_LIN_MODE                  ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_LIN_MODE_POS)
#define cyUart_p50_p51_UART_RX_CTRL_SKIP_START                ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_SKIP_START_POS)
#define cyUart_p50_p51_UART_RX_CTRL_BREAK_WIDTH_MASK          ((uint32) 0x0Fu << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_BREAK_WIDTH_POS)
/* cyUart_p50_p51_UART_RX_STATUS_REG */
#define cyUart_p50_p51_UART_RX_STATUS_BR_COUNTER_POS     (0u)  /* [11:0] Baud Rate counter */
#define cyUart_p50_p51_UART_RX_STATUS_BR_COUNTER_MASK    ((uint32) 0xFFFu)

#if !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    /* cyUart_p50_p51_UART_FLOW_CTRL_REG */
    #define cyUart_p50_p51_UART_FLOW_CTRL_TRIGGER_LEVEL_POS    (0u)  /* [7:0] RTS RX FIFO trigger level         */
    #define cyUart_p50_p51_UART_FLOW_CTRL_RTS_POLARITY_POS     (16u) /* [16]  Polarity of the RTS output signal */
    #define cyUart_p50_p51_UART_FLOW_CTRL_CTS_POLARITY_POS     (24u) /* [24]  Polarity of the CTS input signal  */
    #define cyUart_p50_p51_UART_FLOW_CTRL_CTS_ENABLED_POS      (25u) /* [25]  Enable CTS signal                 */
    #define cyUart_p50_p51_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK   ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_MASK)
    #define cyUart_p50_p51_UART_FLOW_CTRL_RTS_POLARITY         ((uint32) 0x01u << \
                                                                       cyUart_p50_p51_UART_FLOW_CTRL_RTS_POLARITY_POS)
    #define cyUart_p50_p51_UART_FLOW_CTRL_CTS_POLARITY         ((uint32) 0x01u << \
                                                                       cyUart_p50_p51_UART_FLOW_CTRL_CTS_POLARITY_POS)
    #define cyUart_p50_p51_UART_FLOW_CTRL_CTS_ENABLE           ((uint32) 0x01u << \
                                                                       cyUart_p50_p51_UART_FLOW_CTRL_CTS_ENABLED_POS)
#endif /* !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

/* cyUart_p50_p51_I2C_CTRL */
#define cyUart_p50_p51_I2C_CTRL_HIGH_PHASE_OVS_POS           (0u)   /* [3:0] Oversampling factor high: master only */
#define cyUart_p50_p51_I2C_CTRL_LOW_PHASE_OVS_POS            (4u)   /* [7:4] Oversampling factor low:  master only */
#define cyUart_p50_p51_I2C_CTRL_M_READY_DATA_ACK_POS         (8u)   /* [8]   Master ACKs data while RX FIFO != FULL*/
#define cyUart_p50_p51_I2C_CTRL_M_NOT_READY_DATA_NACK_POS    (9u)   /* [9]   Master NACKs data if RX FIFO ==  FULL */
#define cyUart_p50_p51_I2C_CTRL_S_GENERAL_IGNORE_POS         (11u)  /* [11]  Slave ignores General call            */
#define cyUart_p50_p51_I2C_CTRL_S_READY_ADDR_ACK_POS         (12u)  /* [12]  Slave ACKs Address if RX FIFO != FULL */
#define cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK_POS         (13u)  /* [13]  Slave ACKs data while RX FIFO == FULL */
#define cyUart_p50_p51_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS    (14u)  /* [14]  Slave NACKs address if RX FIFO == FULL*/
#define cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK_POS    (15u)  /* [15]  Slave NACKs data if RX FIFO is  FULL  */
#define cyUart_p50_p51_I2C_CTRL_LOOPBACK_POS                 (16u)  /* [16]  Loop-back                             */
#define cyUart_p50_p51_I2C_CTRL_SLAVE_MODE_POS               (30u)  /* [30]  Slave mode enabled                    */
#define cyUart_p50_p51_I2C_CTRL_MASTER_MODE_POS              (31u)  /* [31]  Master mode enabled                   */
#define cyUart_p50_p51_I2C_CTRL_HIGH_PHASE_OVS_MASK  ((uint32) 0x0Fu)
#define cyUart_p50_p51_I2C_CTRL_LOW_PHASE_OVS_MASK   ((uint32) 0x0Fu << \
                                                                cyUart_p50_p51_I2C_CTRL_LOW_PHASE_OVS_POS)
#define cyUart_p50_p51_I2C_CTRL_M_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_M_READY_DATA_ACK_POS)
#define cyUart_p50_p51_I2C_CTRL_M_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_M_NOT_READY_DATA_NACK_POS)
#define cyUart_p50_p51_I2C_CTRL_S_GENERAL_IGNORE      ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_S_GENERAL_IGNORE_POS)
#define cyUart_p50_p51_I2C_CTRL_S_READY_ADDR_ACK      ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_S_READY_ADDR_ACK_POS)
#define cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK_POS)
#define cyUart_p50_p51_I2C_CTRL_S_NOT_READY_ADDR_NACK ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS)
#define cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK_POS)
#define cyUart_p50_p51_I2C_CTRL_LOOPBACK              ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_LOOPBACK_POS)
#define cyUart_p50_p51_I2C_CTRL_SLAVE_MODE            ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_SLAVE_MODE_POS)
#define cyUart_p50_p51_I2C_CTRL_MASTER_MODE           ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CTRL_MASTER_MODE_POS)
#define cyUart_p50_p51_I2C_CTRL_SLAVE_MASTER_MODE_MASK    ((uint32) 0x03u << \
                                                                cyUart_p50_p51_I2C_CTRL_SLAVE_MODE_POS)

/* cyUart_p50_p51_I2C_STATUS_REG  */
#define cyUart_p50_p51_I2C_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy: internally clocked */
#define cyUart_p50_p51_I2C_STATUS_S_READ_POS      (4u)  /* [4]    Slave is read by master      */
#define cyUart_p50_p51_I2C_STATUS_M_READ_POS      (5u)  /* [5]    Master reads Slave           */
#define cyUart_p50_p51_I2C_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EZAddress                    */
#define cyUart_p50_p51_I2C_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define cyUart_p50_p51_I2C_STATUS_S_READ          ((uint32) 0x01u << cyUart_p50_p51_I2C_STATUS_S_READ_POS)
#define cyUart_p50_p51_I2C_STATUS_M_READ          ((uint32) 0x01u << cyUart_p50_p51_I2C_STATUS_M_READ_POS)
#define cyUart_p50_p51_I2C_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << cyUart_p50_p51_I2C_STATUS_EZBUF_ADDR_POS)

/* cyUart_p50_p51_I2C_MASTER_CMD_REG */
#define cyUart_p50_p51_I2C_MASTER_CMD_M_START_POS             (0u)  /* [0] Master generate Start                */
#define cyUart_p50_p51_I2C_MASTER_CMD_M_START_ON_IDLE_POS     (1u)  /* [1] Master generate Start if bus is free */
#define cyUart_p50_p51_I2C_MASTER_CMD_M_ACK_POS               (2u)  /* [2] Master generate ACK                  */
#define cyUart_p50_p51_I2C_MASTER_CMD_M_NACK_POS              (3u)  /* [3] Master generate NACK                 */
#define cyUart_p50_p51_I2C_MASTER_CMD_M_STOP_POS              (4u)  /* [4] Master generate Stop                 */
#define cyUart_p50_p51_I2C_MASTER_CMD_M_START         ((uint32) 0x01u)
#define cyUart_p50_p51_I2C_MASTER_CMD_M_START_ON_IDLE ((uint32) 0x01u << \
                                                                   cyUart_p50_p51_I2C_MASTER_CMD_M_START_ON_IDLE_POS)
#define cyUart_p50_p51_I2C_MASTER_CMD_M_ACK           ((uint32) 0x01u << \
                                                                   cyUart_p50_p51_I2C_MASTER_CMD_M_ACK_POS)
#define cyUart_p50_p51_I2C_MASTER_CMD_M_NACK          ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_I2C_MASTER_CMD_M_NACK_POS)
#define cyUart_p50_p51_I2C_MASTER_CMD_M_STOP          ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_I2C_MASTER_CMD_M_STOP_POS)

/* cyUart_p50_p51_I2C_SLAVE_CMD_REG  */
#define cyUart_p50_p51_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define cyUart_p50_p51_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define cyUart_p50_p51_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define cyUart_p50_p51_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << cyUart_p50_p51_I2C_SLAVE_CMD_S_NACK_POS)

#define cyUart_p50_p51_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define cyUart_p50_p51_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define cyUart_p50_p51_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define cyUart_p50_p51_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << cyUart_p50_p51_I2C_SLAVE_CMD_S_NACK_POS)

/* cyUart_p50_p51_I2C_CFG_REG */
#if (cyUart_p50_p51_CY_SCBIP_V0)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_HYS_POS           (0u)  /* [1:0]   Trim bits for the I2C SDA filter         */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_TRIM_POS          (2u)  /* [3:2]   Trim bits for the I2C SDA filter         */
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_HYS_POS           (4u)  /* [5:4]   Trim bits for the I2C SCL filter         */
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_TRIM_POS          (6u)  /* [7:6]   Trim bits for the I2C SCL filter         */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_HYS_POS       (8u)  /* [9:8]   Trim bits for I2C SDA filter output path */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_TRIM_POS      (10u) /* [11:10] Trim bits for I2C SDA filter output path */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_HS_POS            (16u) /* [16]    '0': 50 ns filter, '1': 10 ns filter     */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_ENABLED_POS       (17u) /* [17]    I2C SDA filter enabled                   */
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_HS_POS            (24u) /* [24]    '0': 50 ns filter, '1': 10 ns filter     */
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_ENABLED_POS       (25u) /* [25]    I2C SCL filter enabled                   */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_HS_POS        (26u) /* [26]    '0': 50 ns filter, '1': 10 ns filter     */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_ENABLED_POS   (27u) /* [27]    I2C SDA output delay filter enabled      */
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_HYS_MASK          ((uint32) 0x03u)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                cyUart_p50_p51_I2C_CFG_SDA_FILT_TRIM_POS)
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_HYS_MASK          ((uint32) 0x03u << \
                                                                cyUart_p50_p51_I2C_CFG_SCL_FILT_HYS_POS)
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                cyUart_p50_p51_I2C_CFG_SCL_FILT_TRIM_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_HYS_MASK      ((uint32) 0x03u << \
                                                                cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_HYS_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_TRIM_MASK     ((uint32) 0x03u << \
                                                                cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_TRIM_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_HS                ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CFG_SDA_FILT_HS_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_ENABLED           ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CFG_SDA_FILT_ENABLED_POS)
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_HS                ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CFG_SCL_FILT_HS_POS)
#define cyUart_p50_p51_I2C_CFG_SCL_FILT_ENABLED           ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CFG_SCL_FILT_ENABLED_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_HS            ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_HS_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_ENABLED       ((uint32) 0x01u << \
                                                                cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_ENABLED_POS)
#else
#define cyUart_p50_p51_I2C_CFG_SDA_IN_FILT_TRIM_POS   (0u)  /* [1:0] Trim bits for "i2c_sda_in" 50 ns filter */
#define cyUart_p50_p51_I2C_CFG_SDA_IN_FILT_SEL_POS    (4u)  /* [4]   "i2c_sda_in" filter delay: 0 ns and 50 ns */
#define cyUart_p50_p51_I2C_CFG_SCL_IN_FILT_TRIM_POS   (8u)  /* [9:8] Trim bits for "i2c_scl_in" 50 ns filter */
#define cyUart_p50_p51_I2C_CFG_SCL_IN_FILT_SEL_POS    (12u) /* [12]  "i2c_scl_in" filter delay: 0 ns and 50 ns */
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT0_TRIM_POS (16u) /* [17:16] Trim bits for "i2c_sda_out" 50 ns filter 0 */
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT1_TRIM_POS (18u) /* [19:18] Trim bits for "i2c_sda_out" 50 ns filter 1 */
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT2_TRIM_POS (20u) /* [21:20] Trim bits for "i2c_sda_out" 50 ns filter 2 */
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT_SEL_POS   (28u) /* [29:28] Cumulative "i2c_sda_out" filter delay: */

#define cyUart_p50_p51_I2C_CFG_SDA_IN_FILT_TRIM_MASK  ((uint32) 0x03u)
#define cyUart_p50_p51_I2C_CFG_SDA_IN_FILT_SEL        ((uint32) 0x01u << cyUart_p50_p51_I2C_CFG_SDA_IN_FILT_SEL_POS)
#define cyUart_p50_p51_I2C_CFG_SCL_IN_FILT_TRIM_MASK  ((uint32) 0x03u << \
                                                            cyUart_p50_p51_I2C_CFG_SCL_IN_FILT_TRIM_POS)
#define cyUart_p50_p51_I2C_CFG_SCL_IN_FILT_SEL        ((uint32) 0x01u << cyUart_p50_p51_I2C_CFG_SCL_IN_FILT_SEL_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT0_TRIM_MASK ((uint32) 0x03u << \
                                                            cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT0_TRIM_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT1_TRIM_MASK ((uint32) 0x03u << \
                                                            cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT1_TRIM_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT2_TRIM_MASK ((uint32) 0x03u << \
                                                            cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT2_TRIM_POS)
#define cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT_SEL_MASK   ((uint32) 0x03u << \
                                                            cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT_SEL_POS)
#endif /* (cyUart_p50_p51_CY_SCBIP_V0) */


/* cyUart_p50_p51_TX_CTRL_REG */
#define cyUart_p50_p51_TX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Data frame width: (Data width - 1) */
#define cyUart_p50_p51_TX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define cyUart_p50_p51_TX_CTRL_ENABLED_POS        (31u) /* [31]  Transmitter enabled               */
#define cyUart_p50_p51_TX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define cyUart_p50_p51_TX_CTRL_MSB_FIRST          ((uint32) 0x01u << cyUart_p50_p51_TX_CTRL_MSB_FIRST_POS)
#define cyUart_p50_p51_TX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define cyUart_p50_p51_TX_CTRL_ENABLED            ((uint32) 0x01u << cyUart_p50_p51_TX_CTRL_ENABLED_POS)

/* cyUart_p50_p51_TX_CTRL_FIFO_REG */
#define cyUart_p50_p51_TX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)  /* [2:0] Trigger level                              */
#define cyUart_p50_p51_TX_FIFO_CTRL_CLEAR_POS             (16u) /* [16]  Clear TX FIFO: cleared after set           */
#define cyUart_p50_p51_TX_FIFO_CTRL_FREEZE_POS            (17u) /* [17]  Freeze TX FIFO: HW do not inc read pointer */
#define cyUart_p50_p51_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_MASK)
#define cyUart_p50_p51_TX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << cyUart_p50_p51_TX_FIFO_CTRL_CLEAR_POS)
#define cyUart_p50_p51_TX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << cyUart_p50_p51_TX_FIFO_CTRL_FREEZE_POS)

/* cyUart_p50_p51_TX_FIFO_STATUS_REG */
#define cyUart_p50_p51_TX_FIFO_STATUS_USED_POS    (0u)  /* [3:0]   Amount of entries in TX FIFO */
#define cyUart_p50_p51_TX_FIFO_SR_VALID_POS       (15u) /* [15]    Shifter status of TX FIFO    */
#define cyUart_p50_p51_TX_FIFO_STATUS_RD_PTR_POS  (16u) /* [18:16] TX FIFO read pointer         */
#define cyUart_p50_p51_TX_FIFO_STATUS_WR_PTR_POS  (24u) /* [26:24] TX FIFO write pointer        */
#define cyUart_p50_p51_TX_FIFO_STATUS_USED_MASK   ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_PLUS1_MASK)
#define cyUart_p50_p51_TX_FIFO_SR_VALID           ((uint32) 0x01u << cyUart_p50_p51_TX_FIFO_SR_VALID_POS)
#define cyUart_p50_p51_TX_FIFO_STATUS_RD_PTR_MASK ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_MASK << \
                                                                    cyUart_p50_p51_TX_FIFO_STATUS_RD_PTR_POS)
#define cyUart_p50_p51_TX_FIFO_STATUS_WR_PTR_MASK ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_MASK << \
                                                                    cyUart_p50_p51_TX_FIFO_STATUS_WR_PTR_POS)

/* cyUart_p50_p51_TX_FIFO_WR_REG */
#define cyUart_p50_p51_TX_FIFO_WR_POS    (0u)  /* [15:0] Data written into TX FIFO */
#define cyUart_p50_p51_TX_FIFO_WR_MASK   ((uint32) 0xFFu)

/* cyUart_p50_p51_RX_CTRL_REG */
#define cyUart_p50_p51_RX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Data frame width: (Data width - 1) */
#define cyUart_p50_p51_RX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define cyUart_p50_p51_RX_CTRL_MEDIAN_POS         (9u)  /* [9]   Median filter                     */
#define cyUart_p50_p51_RX_CTRL_ENABLED_POS        (31u) /* [31]  Receiver enabled                  */
#define cyUart_p50_p51_RX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define cyUart_p50_p51_RX_CTRL_MSB_FIRST          ((uint32) 0x01u << cyUart_p50_p51_RX_CTRL_MSB_FIRST_POS)
#define cyUart_p50_p51_RX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define cyUart_p50_p51_RX_CTRL_MEDIAN             ((uint32) 0x01u << cyUart_p50_p51_RX_CTRL_MEDIAN_POS)
#define cyUart_p50_p51_RX_CTRL_ENABLED            ((uint32) 0x01u << cyUart_p50_p51_RX_CTRL_ENABLED_POS)


/* cyUart_p50_p51_RX_FIFO_CTRL_REG */
#define cyUart_p50_p51_RX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)   /* [2:0] Trigger level                            */
#define cyUart_p50_p51_RX_FIFO_CTRL_CLEAR_POS             (16u)  /* [16]  Clear RX FIFO: clear after set           */
#define cyUart_p50_p51_RX_FIFO_CTRL_FREEZE_POS            (17u)  /* [17]  Freeze RX FIFO: HW writes has not effect */
#define cyUart_p50_p51_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_MASK)
#define cyUart_p50_p51_RX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << cyUart_p50_p51_RX_FIFO_CTRL_CLEAR_POS)
#define cyUart_p50_p51_RX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << cyUart_p50_p51_RX_FIFO_CTRL_FREEZE_POS)

/* cyUart_p50_p51_RX_FIFO_STATUS_REG */
#define cyUart_p50_p51_RX_FIFO_STATUS_USED_POS    (0u)   /* [3:0]   Amount of entries in RX FIFO */
#define cyUart_p50_p51_RX_FIFO_SR_VALID_POS       (15u)  /* [15]    Shifter status of RX FIFO    */
#define cyUart_p50_p51_RX_FIFO_STATUS_RD_PTR_POS  (16u)  /* [18:16] RX FIFO read pointer         */
#define cyUart_p50_p51_RX_FIFO_STATUS_WR_PTR_POS  (24u)  /* [26:24] RX FIFO write pointer        */
#define cyUart_p50_p51_RX_FIFO_STATUS_USED_MASK   ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_PLUS1_MASK)
#define cyUart_p50_p51_RX_FIFO_SR_VALID           ((uint32) 0x01u << cyUart_p50_p51_RX_FIFO_SR_VALID_POS)
#define cyUart_p50_p51_RX_FIFO_STATUS_RD_PTR_MASK ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_MASK << \
                                                                    cyUart_p50_p51_RX_FIFO_STATUS_RD_PTR_POS)
#define cyUart_p50_p51_RX_FIFO_STATUS_WR_PTR_MASK ((uint32) cyUart_p50_p51_FF_DATA_NR_LOG2_MASK << \
                                                                    cyUart_p50_p51_RX_FIFO_STATUS_WR_PTR_POS)

/* cyUart_p50_p51_RX_MATCH_REG */
#define cyUart_p50_p51_RX_MATCH_ADDR_POS     (0u)  /* [7:0]   Slave address                        */
#define cyUart_p50_p51_RX_MATCH_MASK_POS     (16u) /* [23:16] Slave address mask: 0 - doesn't care */
#define cyUart_p50_p51_RX_MATCH_ADDR_MASK    ((uint32) 0xFFu)
#define cyUart_p50_p51_RX_MATCH_MASK_MASK    ((uint32) 0xFFu << cyUart_p50_p51_RX_MATCH_MASK_POS)

/* cyUart_p50_p51_RX_FIFO_WR_REG */
#define cyUart_p50_p51_RX_FIFO_RD_POS    (0u)  /* [15:0] Data read from RX FIFO */
#define cyUart_p50_p51_RX_FIFO_RD_MASK   ((uint32) 0xFFu)

/* cyUart_p50_p51_RX_FIFO_RD_SILENT_REG */
#define cyUart_p50_p51_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define cyUart_p50_p51_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* cyUart_p50_p51_RX_FIFO_RD_SILENT_REG */
#define cyUart_p50_p51_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define cyUart_p50_p51_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* cyUart_p50_p51_EZBUF_DATA_REG */
#define cyUart_p50_p51_EZBUF_DATA_POS   (0u)  /* [7:0] Data from EZ Memory */
#define cyUart_p50_p51_EZBUF_DATA_MASK  ((uint32) 0xFFu)

/*  cyUart_p50_p51_INTR_CAUSE_REG */
#define cyUart_p50_p51_INTR_CAUSE_MASTER_POS  (0u)  /* [0] Master interrupt active                 */
#define cyUart_p50_p51_INTR_CAUSE_SLAVE_POS   (1u)  /* [1] Slave interrupt active                  */
#define cyUart_p50_p51_INTR_CAUSE_TX_POS      (2u)  /* [2] Transmitter interrupt active            */
#define cyUart_p50_p51_INTR_CAUSE_RX_POS      (3u)  /* [3] Receiver interrupt active               */
#define cyUart_p50_p51_INTR_CAUSE_I2C_EC_POS  (4u)  /* [4] Externally clock I2C interrupt active   */
#define cyUart_p50_p51_INTR_CAUSE_SPI_EC_POS  (5u)  /* [5] Externally clocked SPI interrupt active */
#define cyUart_p50_p51_INTR_CAUSE_MASTER      ((uint32) 0x01u)
#define cyUart_p50_p51_INTR_CAUSE_SLAVE       ((uint32) 0x01u << cyUart_p50_p51_INTR_CAUSE_SLAVE_POS)
#define cyUart_p50_p51_INTR_CAUSE_TX          ((uint32) 0x01u << cyUart_p50_p51_INTR_CAUSE_TX_POS)
#define cyUart_p50_p51_INTR_CAUSE_RX          ((uint32) 0x01u << cyUart_p50_p51_INTR_CAUSE_RX_POS)
#define cyUart_p50_p51_INTR_CAUSE_I2C_EC      ((uint32) 0x01u << cyUart_p50_p51_INTR_CAUSE_I2C_EC_POS)
#define cyUart_p50_p51_INTR_CAUSE_SPI_EC      ((uint32) 0x01u << cyUart_p50_p51_INTR_CAUSE_SPI_EC_POS)

/* cyUart_p50_p51_INTR_SPI_EC_REG, cyUart_p50_p51_INTR_SPI_EC_MASK_REG, cyUart_p50_p51_INTR_SPI_EC_MASKED_REG */
#define cyUart_p50_p51_INTR_SPI_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define cyUart_p50_p51_INTR_SPI_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define cyUart_p50_p51_INTR_SPI_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define cyUart_p50_p51_INTR_SPI_EC_WAKE_UP              ((uint32) 0x01u)
#define cyUart_p50_p51_INTR_SPI_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SPI_EC_EZBUF_STOP_POS)
#define cyUart_p50_p51_INTR_SPI_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SPI_EC_EZBUF_WRITE_STOP_POS)

/* cyUart_p50_p51_INTR_I2C_EC, cyUart_p50_p51_INTR_I2C_EC_MASK, cyUart_p50_p51_INTR_I2C_EC_MASKED */
#define cyUart_p50_p51_INTR_I2C_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define cyUart_p50_p51_INTR_I2C_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define cyUart_p50_p51_INTR_I2C_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define cyUart_p50_p51_INTR_I2C_EC_WAKE_UP              ((uint32) 0x01u)
#define cyUart_p50_p51_INTR_I2C_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_I2C_EC_EZBUF_STOP_POS)
#define cyUart_p50_p51_INTR_I2C_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_I2C_EC_EZBUF_WRITE_STOP_POS)

/* cyUart_p50_p51_INTR_MASTER, cyUart_p50_p51_INTR_MASTER_SET,
   cyUart_p50_p51_INTR_MASTER_MASK, cyUart_p50_p51_INTR_MASTER_MASKED */
#define cyUart_p50_p51_INTR_MASTER_I2C_ARB_LOST_POS   (0u)  /* [0] Master lost arbitration                          */
#define cyUart_p50_p51_INTR_MASTER_I2C_NACK_POS       (1u)  /* [1] Master receives NACK: address or write to slave  */
#define cyUart_p50_p51_INTR_MASTER_I2C_ACK_POS        (2u)  /* [2] Master receives NACK: address or write to slave  */
#define cyUart_p50_p51_INTR_MASTER_I2C_STOP_POS       (4u)  /* [4] Master detects the Stop: only self generated Stop*/
#define cyUart_p50_p51_INTR_MASTER_I2C_BUS_ERROR_POS  (8u)  /* [8] Master detects bus error: misplaced Start or Stop*/
#define cyUart_p50_p51_INTR_MASTER_SPI_DONE_POS       (9u)  /* [9] Master complete transfer: Only for SPI           */
#define cyUart_p50_p51_INTR_MASTER_I2C_ARB_LOST       ((uint32) 0x01u)
#define cyUart_p50_p51_INTR_MASTER_I2C_NACK           ((uint32) 0x01u << cyUart_p50_p51_INTR_MASTER_I2C_NACK_POS)
#define cyUart_p50_p51_INTR_MASTER_I2C_ACK            ((uint32) 0x01u << cyUart_p50_p51_INTR_MASTER_I2C_ACK_POS)
#define cyUart_p50_p51_INTR_MASTER_I2C_STOP           ((uint32) 0x01u << cyUart_p50_p51_INTR_MASTER_I2C_STOP_POS)
#define cyUart_p50_p51_INTR_MASTER_I2C_BUS_ERROR      ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_MASTER_I2C_BUS_ERROR_POS)
#define cyUart_p50_p51_INTR_MASTER_SPI_DONE           ((uint32) 0x01u << cyUart_p50_p51_INTR_MASTER_SPI_DONE_POS)

/*
* cyUart_p50_p51_INTR_SLAVE, cyUart_p50_p51_INTR_SLAVE_SET,
* cyUart_p50_p51_INTR_SLAVE_MASK, cyUart_p50_p51_INTR_SLAVE_MASKED
*/
#define cyUart_p50_p51_INTR_SLAVE_I2C_ARB_LOST_POS         (0u)  /* [0]  Slave lost arbitration                   */
#define cyUart_p50_p51_INTR_SLAVE_I2C_NACK_POS             (1u)  /* [1]  Slave receives NACK: master reads data   */
#define cyUart_p50_p51_INTR_SLAVE_I2C_ACK_POS              (2u)  /* [2]  Slave receives ACK: master reads data    */
#define cyUart_p50_p51_INTR_SLAVE_I2C_WRITE_STOP_POS       (3u)  /* [3]  Slave detects end of write transaction   */
#define cyUart_p50_p51_INTR_SLAVE_I2C_STOP_POS             (4u)  /* [4]  Slave detects end of transaction intended */
#define cyUart_p50_p51_INTR_SLAVE_I2C_START_POS            (5u)  /* [5]  Slave detects Start                      */
#define cyUart_p50_p51_INTR_SLAVE_I2C_ADDR_MATCH_POS       (6u)  /* [6]  Slave address matches                    */
#define cyUart_p50_p51_INTR_SLAVE_I2C_GENERAL_POS          (7u)  /* [7]  General call received                    */
#define cyUart_p50_p51_INTR_SLAVE_I2C_BUS_ERROR_POS        (8u)  /* [8]  Slave detects bus error                  */
#define cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS (9u)  /* [9]  Slave write complete: Only for SPI       */
#define cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_STOP_POS       (10u) /* [10] Slave end of transaction: Only for SPI   */
#define cyUart_p50_p51_INTR_SLAVE_SPI_BUS_ERROR_POS        (11u) /* [11] Slave detects bus error: Only for SPI    */
#define cyUart_p50_p51_INTR_SLAVE_I2C_ARB_LOST             ((uint32) 0x01u)
#define cyUart_p50_p51_INTR_SLAVE_I2C_NACK                 ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_NACK_POS)
#define cyUart_p50_p51_INTR_SLAVE_I2C_ACK                  ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_ACK_POS)
#define cyUart_p50_p51_INTR_SLAVE_I2C_WRITE_STOP           ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_WRITE_STOP_POS)
#define cyUart_p50_p51_INTR_SLAVE_I2C_STOP                 ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_STOP_POS)
#define cyUart_p50_p51_INTR_SLAVE_I2C_START                ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_START_POS)
#define cyUart_p50_p51_INTR_SLAVE_I2C_ADDR_MATCH           ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_ADDR_MATCH_POS)
#define cyUart_p50_p51_INTR_SLAVE_I2C_GENERAL              ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_GENERAL_POS)
#define cyUart_p50_p51_INTR_SLAVE_I2C_BUS_ERROR            ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_I2C_BUS_ERROR_POS)
#define cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                   cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS)
#define cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_STOP_POS)
#define cyUart_p50_p51_INTR_SLAVE_SPI_BUS_ERROR           ((uint32) 0x01u << \
                                                                    cyUart_p50_p51_INTR_SLAVE_SPI_BUS_ERROR_POS)

/*
* cyUart_p50_p51_INTR_TX, cyUart_p50_p51_INTR_TX_SET,
* cyUart_p50_p51_INTR_TX_MASK, cyUart_p50_p51_INTR_TX_MASKED
*/
#define cyUart_p50_p51_INTR_TX_TRIGGER_POS        (0u)  /* [0]  Trigger on TX FIFO entires                       */
#define cyUart_p50_p51_INTR_TX_NOT_FULL_POS       (1u)  /* [1]  TX FIFO is not full                              */
#define cyUart_p50_p51_INTR_TX_EMPTY_POS          (4u)  /* [4]  TX FIFO is empty                                 */
#define cyUart_p50_p51_INTR_TX_OVERFLOW_POS       (5u)  /* [5]  Attempt to write to a full TX FIFO               */
#define cyUart_p50_p51_INTR_TX_UNDERFLOW_POS      (6u)  /* [6]  Attempt to read from an empty TX FIFO            */
#define cyUart_p50_p51_INTR_TX_BLOCKED_POS        (7u)  /* [7]  No access to the EZ memory                       */
#define cyUart_p50_p51_INTR_TX_UART_NACK_POS      (8u)  /* [8]  UART transmitter received a NACK: SmartCard mode */
#define cyUart_p50_p51_INTR_TX_UART_DONE_POS      (9u)  /* [9]  UART transmitter done even                       */
#define cyUart_p50_p51_INTR_TX_UART_ARB_LOST_POS  (10u) /* [10] UART lost arbitration: LIN or SmartCard          */
#define cyUart_p50_p51_INTR_TX_TRIGGER            ((uint32) 0x01u)
#define cyUart_p50_p51_INTR_TX_FIFO_LEVEL         (cyUart_p50_p51_INTR_TX_TRIGGER)
#define cyUart_p50_p51_INTR_TX_NOT_FULL           ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_NOT_FULL_POS)
#define cyUart_p50_p51_INTR_TX_EMPTY              ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_EMPTY_POS)
#define cyUart_p50_p51_INTR_TX_OVERFLOW           ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_OVERFLOW_POS)
#define cyUart_p50_p51_INTR_TX_UNDERFLOW          ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_UNDERFLOW_POS)
#define cyUart_p50_p51_INTR_TX_BLOCKED            ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_BLOCKED_POS)
#define cyUart_p50_p51_INTR_TX_UART_NACK          ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_UART_NACK_POS)
#define cyUart_p50_p51_INTR_TX_UART_DONE          ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_UART_DONE_POS)
#define cyUart_p50_p51_INTR_TX_UART_ARB_LOST      ((uint32) 0x01u << cyUart_p50_p51_INTR_TX_UART_ARB_LOST_POS)

/*
* cyUart_p50_p51_INTR_RX, cyUart_p50_p51_INTR_RX_SET,
* cyUart_p50_p51_INTR_RX_MASK, cyUart_p50_p51_INTR_RX_MASKED
*/
#define cyUart_p50_p51_INTR_RX_TRIGGER_POS        (0u)   /* [0]  Trigger on RX FIFO entires            */
#define cyUart_p50_p51_INTR_RX_NOT_EMPTY_POS      (2u)   /* [2]  RX FIFO is not empty                  */
#define cyUart_p50_p51_INTR_RX_FULL_POS           (3u)   /* [3]  RX FIFO is full                       */
#define cyUart_p50_p51_INTR_RX_OVERFLOW_POS       (5u)   /* [5]  Attempt to write to a full RX FIFO    */
#define cyUart_p50_p51_INTR_RX_UNDERFLOW_POS      (6u)   /* [6]  Attempt to read from an empty RX FIFO */
#define cyUart_p50_p51_INTR_RX_BLOCKED_POS        (7u)   /* [7]  No access to the EZ memory            */
#define cyUart_p50_p51_INTR_RX_FRAME_ERROR_POS    (8u)   /* [8]  Frame error in received data frame    */
#define cyUart_p50_p51_INTR_RX_PARITY_ERROR_POS   (9u)   /* [9]  Parity error in received data frame   */
#define cyUart_p50_p51_INTR_RX_BAUD_DETECT_POS    (10u)  /* [10] LIN baud rate detection is completed   */
#define cyUart_p50_p51_INTR_RX_BREAK_DETECT_POS   (11u)  /* [11] Break detection is successful         */
#define cyUart_p50_p51_INTR_RX_TRIGGER            ((uint32) 0x01u)
#define cyUart_p50_p51_INTR_RX_FIFO_LEVEL         (cyUart_p50_p51_INTR_RX_TRIGGER)
#define cyUart_p50_p51_INTR_RX_NOT_EMPTY          ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_NOT_EMPTY_POS)
#define cyUart_p50_p51_INTR_RX_FULL               ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_FULL_POS)
#define cyUart_p50_p51_INTR_RX_OVERFLOW           ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_OVERFLOW_POS)
#define cyUart_p50_p51_INTR_RX_UNDERFLOW          ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_UNDERFLOW_POS)
#define cyUart_p50_p51_INTR_RX_BLOCKED            ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_BLOCKED_POS)
#define cyUart_p50_p51_INTR_RX_FRAME_ERROR        ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_FRAME_ERROR_POS)
#define cyUart_p50_p51_INTR_RX_PARITY_ERROR       ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_PARITY_ERROR_POS)
#define cyUart_p50_p51_INTR_RX_BAUD_DETECT        ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_BAUD_DETECT_POS)
#define cyUart_p50_p51_INTR_RX_BREAK_DETECT       ((uint32) 0x01u << cyUart_p50_p51_INTR_RX_BREAK_DETECT_POS)

/* Define all interrupt sources */
#define cyUart_p50_p51_INTR_I2C_EC_ALL    (cyUart_p50_p51_INTR_I2C_EC_WAKE_UP    | \
                                             cyUart_p50_p51_INTR_I2C_EC_EZBUF_STOP | \
                                             cyUart_p50_p51_INTR_I2C_EC_EZBUF_WRITE_STOP)

#define cyUart_p50_p51_INTR_SPI_EC_ALL    (cyUart_p50_p51_INTR_SPI_EC_WAKE_UP    | \
                                             cyUart_p50_p51_INTR_SPI_EC_EZBUF_STOP | \
                                             cyUart_p50_p51_INTR_SPI_EC_EZBUF_WRITE_STOP)

#define cyUart_p50_p51_INTR_MASTER_ALL    (cyUart_p50_p51_INTR_MASTER_I2C_ARB_LOST  | \
                                             cyUart_p50_p51_INTR_MASTER_I2C_NACK      | \
                                             cyUart_p50_p51_INTR_MASTER_I2C_ACK       | \
                                             cyUart_p50_p51_INTR_MASTER_I2C_STOP      | \
                                             cyUart_p50_p51_INTR_MASTER_I2C_BUS_ERROR | \
                                             cyUart_p50_p51_INTR_MASTER_SPI_DONE)

#define cyUart_p50_p51_INTR_SLAVE_ALL     (cyUart_p50_p51_INTR_SLAVE_I2C_ARB_LOST      | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_NACK          | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_ACK           | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_WRITE_STOP    | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_STOP          | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_START         | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_ADDR_MATCH    | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_GENERAL       | \
                                             cyUart_p50_p51_INTR_SLAVE_I2C_BUS_ERROR     | \
                                             cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_WRITE_STOP | \
                                             cyUart_p50_p51_INTR_SLAVE_SPI_EZBUF_STOP       | \
                                             cyUart_p50_p51_INTR_SLAVE_SPI_BUS_ERROR)

#define cyUart_p50_p51_INTR_TX_ALL        (cyUart_p50_p51_INTR_TX_TRIGGER   | \
                                             cyUart_p50_p51_INTR_TX_NOT_FULL  | \
                                             cyUart_p50_p51_INTR_TX_EMPTY     | \
                                             cyUart_p50_p51_INTR_TX_OVERFLOW  | \
                                             cyUart_p50_p51_INTR_TX_UNDERFLOW | \
                                             cyUart_p50_p51_INTR_TX_BLOCKED   | \
                                             cyUart_p50_p51_INTR_TX_UART_NACK | \
                                             cyUart_p50_p51_INTR_TX_UART_DONE | \
                                             cyUart_p50_p51_INTR_TX_UART_ARB_LOST)

#define cyUart_p50_p51_INTR_RX_ALL        (cyUart_p50_p51_INTR_RX_TRIGGER      | \
                                             cyUart_p50_p51_INTR_RX_NOT_EMPTY    | \
                                             cyUart_p50_p51_INTR_RX_FULL         | \
                                             cyUart_p50_p51_INTR_RX_OVERFLOW     | \
                                             cyUart_p50_p51_INTR_RX_UNDERFLOW    | \
                                             cyUart_p50_p51_INTR_RX_BLOCKED      | \
                                             cyUart_p50_p51_INTR_RX_FRAME_ERROR  | \
                                             cyUart_p50_p51_INTR_RX_PARITY_ERROR | \
                                             cyUart_p50_p51_INTR_RX_BAUD_DETECT  | \
                                             cyUart_p50_p51_INTR_RX_BREAK_DETECT)

/* I2C and EZI2C slave address defines */
#define cyUart_p50_p51_I2C_SLAVE_ADDR_POS    (0x01u)    /* 7-bit address shift */
#define cyUart_p50_p51_I2C_SLAVE_ADDR_MASK   (0xFEu)    /* 8-bit address mask */

/* OVS constants for IrDA Low Power operation */
#define cyUart_p50_p51_CTRL_OVS_IRDA_LP_OVS16     (0x00u)
#define cyUart_p50_p51_CTRL_OVS_IRDA_LP_OVS32     (0x01u)
#define cyUart_p50_p51_CTRL_OVS_IRDA_LP_OVS48     (0x02u)
#define cyUart_p50_p51_CTRL_OVS_IRDA_LP_OVS96     (0x03u)
#define cyUart_p50_p51_CTRL_OVS_IRDA_LP_OVS192    (0x04u)
#define cyUart_p50_p51_CTRL_OVS_IRDA_LP_OVS768    (0x05u)
#define cyUart_p50_p51_CTRL_OVS_IRDA_LP_OVS1536   (0x06u)

/* OVS constant for IrDA */
#define cyUart_p50_p51_CTRL_OVS_IRDA_OVS16        (cyUart_p50_p51_UART_IRDA_LP_OVS16)


/***************************************
*    Common Macro Definitions
***************************************/

/* Re-enables the SCB IP. A clear enable bit has a different effect
* on the scb IP depending on the version:
*  CY_SCBIP_V0: resets state, status, TX and RX FIFOs.
*  CY_SCBIP_V1 or later: resets state, status, TX and RX FIFOs and interrupt sources.
* Clear I2C command registers are because they are not impacted by re-enable.
*/
#define cyUart_p50_p51_SCB_SW_RESET   cyUart_p50_p51_I2CFwBlockReset()

/* TX FIFO macro */
#define cyUart_p50_p51_CLEAR_TX_FIFO \
                            do{        \
                                cyUart_p50_p51_TX_FIFO_CTRL_REG |= ((uint32)  cyUart_p50_p51_TX_FIFO_CTRL_CLEAR); \
                                cyUart_p50_p51_TX_FIFO_CTRL_REG &= ((uint32) ~cyUart_p50_p51_TX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define cyUart_p50_p51_GET_TX_FIFO_ENTRIES    (cyUart_p50_p51_TX_FIFO_STATUS_REG & \
                                                 cyUart_p50_p51_TX_FIFO_STATUS_USED_MASK)

#define cyUart_p50_p51_GET_TX_FIFO_SR_VALID   ((0u != (cyUart_p50_p51_TX_FIFO_STATUS_REG & \
                                                         cyUart_p50_p51_TX_FIFO_SR_VALID)) ? (1u) : (0u))

/* RX FIFO macro */
#define cyUart_p50_p51_CLEAR_RX_FIFO \
                            do{        \
                                cyUart_p50_p51_RX_FIFO_CTRL_REG |= ((uint32)  cyUart_p50_p51_RX_FIFO_CTRL_CLEAR); \
                                cyUart_p50_p51_RX_FIFO_CTRL_REG &= ((uint32) ~cyUart_p50_p51_RX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define cyUart_p50_p51_GET_RX_FIFO_ENTRIES    (cyUart_p50_p51_RX_FIFO_STATUS_REG & \
                                                    cyUart_p50_p51_RX_FIFO_STATUS_USED_MASK)

#define cyUart_p50_p51_GET_RX_FIFO_SR_VALID   ((0u != (cyUart_p50_p51_RX_FIFO_STATUS_REG & \
                                                         cyUart_p50_p51_RX_FIFO_SR_VALID)) ? (1u) : (0u))

/* Write interrupt source: set sourceMask bits in cyUart_p50_p51_INTR_X_MASK_REG */
#define cyUart_p50_p51_WRITE_INTR_I2C_EC_MASK(sourceMask) \
                                                do{         \
                                                    cyUart_p50_p51_INTR_I2C_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_WRITE_INTR_SPI_EC_MASK(sourceMask) \
                                                do{         \
                                                    cyUart_p50_p51_INTR_SPI_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_WRITE_INTR_MASTER_MASK(sourceMask) \
                                                do{         \
                                                    cyUart_p50_p51_INTR_MASTER_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_WRITE_INTR_SLAVE_MASK(sourceMask)  \
                                                do{         \
                                                    cyUart_p50_p51_INTR_SLAVE_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_WRITE_INTR_TX_MASK(sourceMask)     \
                                                do{         \
                                                    cyUart_p50_p51_INTR_TX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_WRITE_INTR_RX_MASK(sourceMask)     \
                                                do{         \
                                                    cyUart_p50_p51_INTR_RX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Enable interrupt source: set sourceMask bits in cyUart_p50_p51_INTR_X_MASK_REG */
#define cyUart_p50_p51_ENABLE_INTR_I2C_EC(sourceMask) \
                                                do{     \
                                                    cyUart_p50_p51_INTR_I2C_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)
#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_ENABLE_INTR_SPI_EC(sourceMask) \
                                                do{     \
                                                    cyUart_p50_p51_INTR_SPI_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_ENABLE_INTR_MASTER(sourceMask) \
                                                do{     \
                                                    cyUart_p50_p51_INTR_MASTER_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_ENABLE_INTR_SLAVE(sourceMask)  \
                                                do{     \
                                                    cyUart_p50_p51_INTR_SLAVE_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_ENABLE_INTR_TX(sourceMask)     \
                                                do{     \
                                                    cyUart_p50_p51_INTR_TX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_ENABLE_INTR_RX(sourceMask)     \
                                                do{     \
                                                    cyUart_p50_p51_INTR_RX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

/* Disable interrupt source: clear sourceMask bits in cyUart_p50_p51_INTR_X_MASK_REG */
#define cyUart_p50_p51_DISABLE_INTR_I2C_EC(sourceMask) \
                                do{                      \
                                    cyUart_p50_p51_INTR_I2C_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_DISABLE_INTR_SPI_EC(sourceMask) \
                                do{                      \
                                    cyUart_p50_p51_INTR_SPI_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_DISABLE_INTR_MASTER(sourceMask) \
                                do{                      \
                                cyUart_p50_p51_INTR_MASTER_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define cyUart_p50_p51_DISABLE_INTR_SLAVE(sourceMask) \
                                do{                     \
                                    cyUart_p50_p51_INTR_SLAVE_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define cyUart_p50_p51_DISABLE_INTR_TX(sourceMask)    \
                                do{                     \
                                    cyUart_p50_p51_INTR_TX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)

#define cyUart_p50_p51_DISABLE_INTR_RX(sourceMask)    \
                                do{                     \
                                    cyUart_p50_p51_INTR_RX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

/* Set interrupt sources: write sourceMask bits in cyUart_p50_p51_INTR_X_SET_REG */
#define cyUart_p50_p51_SET_INTR_MASTER(sourceMask)    \
                                                do{     \
                                                    cyUart_p50_p51_INTR_MASTER_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_SET_INTR_SLAVE(sourceMask) \
                                                do{ \
                                                    cyUart_p50_p51_INTR_SLAVE_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_SET_INTR_TX(sourceMask)    \
                                                do{ \
                                                    cyUart_p50_p51_INTR_TX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_SET_INTR_RX(sourceMask)    \
                                                do{ \
                                                    cyUart_p50_p51_INTR_RX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Clear interrupt sources: write sourceMask bits in cyUart_p50_p51_INTR_X_REG */
#define cyUart_p50_p51_CLEAR_INTR_I2C_EC(sourceMask)  \
                                                do{     \
                                                    cyUart_p50_p51_INTR_I2C_EC_REG = (uint32) (sourceMask); \
                                                }while(0)

#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_CLEAR_INTR_SPI_EC(sourceMask)  \
                                                do{     \
                                                    cyUart_p50_p51_INTR_SPI_EC_REG = (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_CLEAR_INTR_MASTER(sourceMask)  \
                                                do{     \
                                                    cyUart_p50_p51_INTR_MASTER_REG = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_CLEAR_INTR_SLAVE(sourceMask)   \
                                                do{     \
                                                    cyUart_p50_p51_INTR_SLAVE_REG  = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_CLEAR_INTR_TX(sourceMask)      \
                                                do{     \
                                                    cyUart_p50_p51_INTR_TX_REG     = (uint32) (sourceMask); \
                                                }while(0)

#define cyUart_p50_p51_CLEAR_INTR_RX(sourceMask)      \
                                                do{     \
                                                    cyUart_p50_p51_INTR_RX_REG     = (uint32) (sourceMask); \
                                                }while(0)

/* Return true if sourceMask is set in cyUart_p50_p51_INTR_CAUSE_REG */
#define cyUart_p50_p51_CHECK_CAUSE_INTR(sourceMask)    (0u != (cyUart_p50_p51_INTR_CAUSE_REG & (sourceMask)))

/* Return true if sourceMask is set in INTR_X_MASKED_REG */
#define cyUart_p50_p51_CHECK_INTR_I2C_EC(sourceMask)  (0u != (cyUart_p50_p51_INTR_I2C_EC_REG & (sourceMask)))
#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_CHECK_INTR_SPI_EC(sourceMask)  (0u != (cyUart_p50_p51_INTR_SPI_EC_REG & (sourceMask)))
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */
#define cyUart_p50_p51_CHECK_INTR_MASTER(sourceMask)  (0u != (cyUart_p50_p51_INTR_MASTER_REG & (sourceMask)))
#define cyUart_p50_p51_CHECK_INTR_SLAVE(sourceMask)   (0u != (cyUart_p50_p51_INTR_SLAVE_REG  & (sourceMask)))
#define cyUart_p50_p51_CHECK_INTR_TX(sourceMask)      (0u != (cyUart_p50_p51_INTR_TX_REG     & (sourceMask)))
#define cyUart_p50_p51_CHECK_INTR_RX(sourceMask)      (0u != (cyUart_p50_p51_INTR_RX_REG     & (sourceMask)))

/* Return true if sourceMask is set in cyUart_p50_p51_INTR_X_MASKED_REG */
#define cyUart_p50_p51_CHECK_INTR_I2C_EC_MASKED(sourceMask)   (0u != (cyUart_p50_p51_INTR_I2C_EC_MASKED_REG & \
                                                                       (sourceMask)))
#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_CHECK_INTR_SPI_EC_MASKED(sourceMask)   (0u != (cyUart_p50_p51_INTR_SPI_EC_MASKED_REG & \
                                                                       (sourceMask)))
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */
#define cyUart_p50_p51_CHECK_INTR_MASTER_MASKED(sourceMask)   (0u != (cyUart_p50_p51_INTR_MASTER_MASKED_REG & \
                                                                       (sourceMask)))
#define cyUart_p50_p51_CHECK_INTR_SLAVE_MASKED(sourceMask)    (0u != (cyUart_p50_p51_INTR_SLAVE_MASKED_REG  & \
                                                                       (sourceMask)))
#define cyUart_p50_p51_CHECK_INTR_TX_MASKED(sourceMask)       (0u != (cyUart_p50_p51_INTR_TX_MASKED_REG     & \
                                                                       (sourceMask)))
#define cyUart_p50_p51_CHECK_INTR_RX_MASKED(sourceMask)       (0u != (cyUart_p50_p51_INTR_RX_MASKED_REG     & \
                                                                       (sourceMask)))

/* Return true if sourceMask is set in cyUart_p50_p51_CTRL_REG: generally is used to check enable bit */
#define cyUart_p50_p51_GET_CTRL_ENABLED    (0u != (cyUart_p50_p51_CTRL_REG & cyUart_p50_p51_CTRL_ENABLED))

#define cyUart_p50_p51_CHECK_SLAVE_AUTO_ADDR_NACK     (0u != (cyUart_p50_p51_I2C_CTRL_REG & \
                                                                cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK))


/***************************************
*      I2C Macro Definitions
***************************************/

/* Enable auto ACK/NACK */
#define cyUart_p50_p51_ENABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                      \
                                cyUart_p50_p51_I2C_CTRL_REG |= cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define cyUart_p50_p51_ENABLE_SLAVE_AUTO_DATA_ACK \
                            do{                     \
                                cyUart_p50_p51_I2C_CTRL_REG |= cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define cyUart_p50_p51_ENABLE_SLAVE_AUTO_DATA_NACK \
                            do{                      \
                                cyUart_p50_p51_I2C_CTRL_REG |= cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define cyUart_p50_p51_ENABLE_MASTER_AUTO_DATA_ACK \
                            do{                      \
                                cyUart_p50_p51_I2C_CTRL_REG |= cyUart_p50_p51_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define cyUart_p50_p51_ENABLE_MASTER_AUTO_DATA_NACK \
                            do{                       \
                                cyUart_p50_p51_I2C_CTRL_REG |= cyUart_p50_p51_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Disable auto ACK/NACK */
#define cyUart_p50_p51_DISABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                       \
                                cyUart_p50_p51_I2C_CTRL_REG &= ~cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define cyUart_p50_p51_DISABLE_SLAVE_AUTO_DATA_ACK \
                            do{                      \
                                cyUart_p50_p51_I2C_CTRL_REG &= ~cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define cyUart_p50_p51_DISABLE_SLAVE_AUTO_DATA_NACK \
                            do{                       \
                                cyUart_p50_p51_I2C_CTRL_REG &= ~cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define cyUart_p50_p51_DISABLE_MASTER_AUTO_DATA_ACK \
                            do{                       \
                                cyUart_p50_p51_I2C_CTRL_REG &= ~cyUart_p50_p51_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define cyUart_p50_p51_DISABLE_MASTER_AUTO_DATA_NACK \
                            do{                        \
                                cyUart_p50_p51_I2C_CTRL_REG &= ~cyUart_p50_p51_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Enable Slave autoACK/NACK Data */
#define cyUart_p50_p51_ENABLE_SLAVE_AUTO_DATA \
                            do{                 \
                                cyUart_p50_p51_I2C_CTRL_REG |= (cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK |      \
                                                                  cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK); \
                            }while(0)

/* Disable Slave autoACK/NACK Data */
#define cyUart_p50_p51_DISABLE_SLAVE_AUTO_DATA \
                            do{                  \
                                cyUart_p50_p51_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK |       \
                                                                    cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                            }while(0)

/* Disable Master autoACK/NACK Data */
#define cyUart_p50_p51_DISABLE_MASTER_AUTO_DATA \
                            do{                   \
                                cyUart_p50_p51_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(cyUart_p50_p51_I2C_CTRL_M_READY_DATA_ACK |       \
                                                                    cyUart_p50_p51_I2C_CTRL_M_NOT_READY_DATA_NACK)); \
                            }while(0)
/* Disables auto data ACK/NACK bits */
#define cyUart_p50_p51_DISABLE_AUTO_DATA \
                do{                        \
                    cyUart_p50_p51_I2C_CTRL_REG &= ((uint32) ~(cyUart_p50_p51_I2C_CTRL_M_READY_DATA_ACK      |  \
                                                                 cyUart_p50_p51_I2C_CTRL_M_NOT_READY_DATA_NACK |  \
                                                                 cyUart_p50_p51_I2C_CTRL_S_READY_DATA_ACK      |  \
                                                                 cyUart_p50_p51_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                }while(0)

/* Master commands */
#define cyUart_p50_p51_I2C_MASTER_GENERATE_START \
                            do{                    \
                                cyUart_p50_p51_I2C_MASTER_CMD_REG = cyUart_p50_p51_I2C_MASTER_CMD_M_START_ON_IDLE; \
                            }while(0)

#define cyUart_p50_p51_I2C_MASTER_CLEAR_START \
                            do{                 \
                                cyUart_p50_p51_I2C_MASTER_CMD_REG =  ((uint32) 0u); \
                            }while(0)

#define cyUart_p50_p51_I2C_MASTER_GENERATE_RESTART cyUart_p50_p51_I2CReStartGeneration()

#define cyUart_p50_p51_I2C_MASTER_GENERATE_STOP \
                            do{                   \
                                cyUart_p50_p51_I2C_MASTER_CMD_REG =                                            \
                                    (cyUart_p50_p51_I2C_MASTER_CMD_M_STOP |                                    \
                                        (cyUart_p50_p51_CHECK_I2C_STATUS(cyUart_p50_p51_I2C_STATUS_M_READ) ? \
                                            (cyUart_p50_p51_I2C_MASTER_CMD_M_NACK) : (0u)));                   \
                            }while(0)

#define cyUart_p50_p51_I2C_MASTER_GENERATE_ACK \
                            do{                  \
                                cyUart_p50_p51_I2C_MASTER_CMD_REG = cyUart_p50_p51_I2C_MASTER_CMD_M_ACK; \
                            }while(0)

#define cyUart_p50_p51_I2C_MASTER_GENERATE_NACK \
                            do{                   \
                                cyUart_p50_p51_I2C_MASTER_CMD_REG = cyUart_p50_p51_I2C_MASTER_CMD_M_NACK; \
                            }while(0)

/* Slave commands */
#define cyUart_p50_p51_I2C_SLAVE_GENERATE_ACK \
                            do{                 \
                                cyUart_p50_p51_I2C_SLAVE_CMD_REG = cyUart_p50_p51_I2C_SLAVE_CMD_S_ACK; \
                            }while(0)

#if (cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    /* Slave NACK generation for EC_AM logic on address phase. Ticket ID #183902 */
    void cyUart_p50_p51_I2CSlaveNackGeneration(void);
    #define cyUart_p50_p51_I2C_SLAVE_GENERATE_NACK cyUart_p50_p51_I2CSlaveNackGeneration()

#else
    #define cyUart_p50_p51_I2C_SLAVE_GENERATE_NACK \
                            do{                      \
                                cyUart_p50_p51_I2C_SLAVE_CMD_REG = cyUart_p50_p51_I2C_SLAVE_CMD_S_NACK; \
                            }while(0)
#endif /* (cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_I2C_SLAVE_CLEAR_NACK \
                            do{               \
                                cyUart_p50_p51_I2C_SLAVE_CMD_REG = 0u; \
                            }while(0)

/* Return 8-bit address. The input address should be 7-bits */
#define cyUart_p50_p51_GET_I2C_8BIT_ADDRESS(addr) (((uint32) ((uint32) (addr) << \
                                                                    cyUart_p50_p51_I2C_SLAVE_ADDR_POS)) & \
                                                                        cyUart_p50_p51_I2C_SLAVE_ADDR_MASK)

#define cyUart_p50_p51_GET_I2C_7BIT_ADDRESS(addr) ((uint32) (addr) >> cyUart_p50_p51_I2C_SLAVE_ADDR_POS)

/* Adjust SDA filter Trim settings */
#define cyUart_p50_p51_DEFAULT_I2C_CFG_SDA_FILT_TRIM  (0x02u)
#define cyUart_p50_p51_EC_AM_I2C_CFG_SDA_FILT_TRIM    (0x03u)

#if (cyUart_p50_p51_CY_SCBIP_V0)
    #define cyUart_p50_p51_SET_I2C_CFG_SDA_FILT_TRIM(sdaTrim) \
        do{                                                 \
            cyUart_p50_p51_I2C_CFG_REG =                  \
                            ((cyUart_p50_p51_I2C_CFG_REG & (uint32) ~cyUart_p50_p51_I2C_CFG_SDA_FILT_TRIM_MASK) | \
                             ((uint32) ((uint32) (sdaTrim) <<cyUart_p50_p51_I2C_CFG_SDA_FILT_TRIM_POS)));           \
        }while(0)
#endif /* (cyUart_p50_p51_CY_SCBIP_V0) */

/* Enable/Disable analog and digital filter */
#define cyUart_p50_p51_DIGITAL_FILTER_DISABLE    (0u)
#define cyUart_p50_p51_DIGITAL_FILTER_ENABLE     (1u)
#define cyUart_p50_p51_I2C_DATA_RATE_FS_MODE_MAX (400u)
#if (cyUart_p50_p51_CY_SCBIP_V0)
    /* cyUart_p50_p51_I2C_CFG_SDA_FILT_OUT_ENABLED is disabled by default */
    #define cyUart_p50_p51_I2C_CFG_FILT_MASK  (cyUart_p50_p51_I2C_CFG_SDA_FILT_ENABLED | \
                                                 cyUart_p50_p51_I2C_CFG_SCL_FILT_ENABLED)
#else
    /* cyUart_p50_p51_I2C_CFG_SDA_OUT_FILT_SEL_MASK is disabled by default */
    #define cyUart_p50_p51_I2C_CFG_FILT_MASK  (cyUart_p50_p51_I2C_CFG_SDA_IN_FILT_SEL | \
                                                 cyUart_p50_p51_I2C_CFG_SCL_IN_FILT_SEL)
#endif /* (cyUart_p50_p51_CY_SCBIP_V0) */

#define cyUart_p50_p51_I2C_CFG_ANALOG_FITER_DISABLE \
        do{                                           \
            cyUart_p50_p51_I2C_CFG_REG &= (uint32) ~cyUart_p50_p51_I2C_CFG_FILT_MASK; \
        }while(0)

#define cyUart_p50_p51_I2C_CFG_ANALOG_FITER_ENABLE \
        do{                                          \
            cyUart_p50_p51_I2C_CFG_REG |= (uint32)  cyUart_p50_p51_I2C_CFG_FILT_MASK; \
        }while(0)

/* Return slave select number from SPI_CTRL register */
#define cyUart_p50_p51_GET_SPI_CTRL_SS(activeSelect) (((uint32) ((uint32) (activeSelect) << \
                                                                    cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_POS)) & \
                                                                        cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_MASK)

/* Return true if bit is set in cyUart_p50_p51_I2C_STATUS_REG */
#define cyUart_p50_p51_CHECK_I2C_STATUS(sourceMask)   (0u != (cyUart_p50_p51_I2C_STATUS_REG & (sourceMask)))

/* Return true if bit is set in cyUart_p50_p51_SPI_STATUS_REG */
#define cyUart_p50_p51_CHECK_SPI_STATUS(sourceMask)   (0u != (cyUart_p50_p51_SPI_STATUS_REG & (sourceMask)))

/* Return FIFO size depends on cyUart_p50_p51_CTRL_BYTE_MODE bit */
#define cyUart_p50_p51_GET_FIFO_SIZE(condition) ((0u != (condition)) ? \
                                                    (2u * cyUart_p50_p51_FIFO_SIZE) : (cyUart_p50_p51_FIFO_SIZE))


/***************************************
*       Get Macros Definitions
***************************************/

/* cyUart_p50_p51_CTRL */
#define cyUart_p50_p51_GET_CTRL_OVS(oversample)       (((uint32) (oversample) - 1u) & cyUart_p50_p51_CTRL_OVS_MASK)

#define cyUart_p50_p51_GET_CTRL_EC_OP_MODE(opMode)        ((0u != (opMode)) ? \
                                                                (cyUart_p50_p51_CTRL_EC_OP_MODE)  : (0u))

#define cyUart_p50_p51_GET_CTRL_EC_AM_MODE(amMode)        ((0u != (amMode)) ? \
                                                                (cyUart_p50_p51_CTRL_EC_AM_MODE)  : (0u))

#define cyUart_p50_p51_GET_CTRL_BLOCK(block)              ((0u != (block))  ? \
                                                                (cyUart_p50_p51_CTRL_BLOCK)       : (0u))

#define cyUart_p50_p51_GET_CTRL_ADDR_ACCEPT(acceptAddr)   ((0u != (acceptAddr)) ? \
                                                                (cyUart_p50_p51_CTRL_ADDR_ACCEPT) : (0u))

#if (cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_GET_CTRL_BYTE_MODE(mode)   (0u)
#else
    #define cyUart_p50_p51_GET_CTRL_BYTE_MODE(mode)   ((0u != (mode)) ? \
                                                            (cyUart_p50_p51_CTRL_BYTE_MODE) : (0u))
#endif /* (cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

/* cyUart_p50_p51_I2C_CTRL */
#define cyUart_p50_p51_GET_I2C_CTRL_HIGH_PHASE_OVS(oversampleHigh) (((uint32) (oversampleHigh) - 1u) & \
                                                                        cyUart_p50_p51_I2C_CTRL_HIGH_PHASE_OVS_MASK)

#define cyUart_p50_p51_GET_I2C_CTRL_LOW_PHASE_OVS(oversampleLow)  ((((uint32) (oversampleLow) - 1u) << \
                                                                    cyUart_p50_p51_I2C_CTRL_LOW_PHASE_OVS_POS) &  \
                                                                    cyUart_p50_p51_I2C_CTRL_LOW_PHASE_OVS_MASK)

#define cyUart_p50_p51_GET_I2C_CTRL_S_NOT_READY_ADDR_NACK(wakeNack) ((0u != (wakeNack)) ? \
                                                            (cyUart_p50_p51_I2C_CTRL_S_NOT_READY_ADDR_NACK) : (0u))

#define cyUart_p50_p51_GET_I2C_CTRL_S_GENERAL_IGNORE(genCall) ((0u != (genCall)) ? \
                                                                    (cyUart_p50_p51_I2C_CTRL_S_GENERAL_IGNORE) : (0u))

#define cyUart_p50_p51_GET_I2C_CTRL_SL_MSTR_MODE(mode)    ((uint32)(mode) << cyUart_p50_p51_I2C_CTRL_SLAVE_MODE_POS)

/* cyUart_p50_p51_SPI_CTRL */
#define cyUart_p50_p51_GET_SPI_CTRL_CONTINUOUS(separate)  ((0u != (separate)) ? \
                                                                (cyUart_p50_p51_SPI_CTRL_CONTINUOUS) : (0u))

#define cyUart_p50_p51_GET_SPI_CTRL_SELECT_PRECEDE(mode)  ((0u != (mode)) ? \
                                                                      (cyUart_p50_p51_SPI_CTRL_SELECT_PRECEDE) : (0u))

#define cyUart_p50_p51_GET_SPI_CTRL_SCLK_MODE(mode)       (((uint32) (mode) << \
                                                                        cyUart_p50_p51_SPI_CTRL_CPHA_POS) & \
                                                                        cyUart_p50_p51_SPI_CTRL_SCLK_MODE_MASK)

#define cyUart_p50_p51_GET_SPI_CTRL_LATE_MISO_SAMPLE(lateMiso) ((0u != (lateMiso)) ? \
                                                                    (cyUart_p50_p51_SPI_CTRL_LATE_MISO_SAMPLE) : (0u))

#if (cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_GET_SPI_CTRL_SCLK_CONTINUOUS(sclkType) (0u)
    #define cyUart_p50_p51_GET_SPI_CTRL_SSEL_POLARITY(polarity)   (0u)
#else
    #define cyUart_p50_p51_GET_SPI_CTRL_SCLK_CONTINUOUS(sclkType) ((0u != (sclkType)) ? \
                                                                    (cyUart_p50_p51_SPI_CTRL_SCLK_CONTINUOUS) : (0u))

    #define cyUart_p50_p51_GET_SPI_CTRL_SSEL_POLARITY(polarity)   (((uint32) (polarity) << \
                                                                     cyUart_p50_p51_SPI_CTRL_SSEL0_POLARITY_POS) & \
                                                                     cyUart_p50_p51_SPI_CTRL_SSEL_POLARITY_MASK)
#endif /* ((cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_GET_SPI_CTRL_SUB_MODE(mode)        (((uint32) (mode) << cyUart_p50_p51_SPI_CTRL_MODE_POS) & \
                                                                                 cyUart_p50_p51_SPI_CTRL_MODE_MASK)

#define cyUart_p50_p51_GET_SPI_CTRL_SLAVE_SELECT(select)  (((uint32) (select) << \
                                                                      cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_POS) & \
                                                                      cyUart_p50_p51_SPI_CTRL_SLAVE_SELECT_MASK)

#define cyUart_p50_p51_GET_SPI_CTRL_MASTER_MODE(mode)     ((0u != (mode)) ? \
                                                                (cyUart_p50_p51_SPI_CTRL_MASTER) : (0u))

/* cyUart_p50_p51_UART_CTRL */
#define cyUart_p50_p51_GET_UART_CTRL_MODE(mode)           (((uint32) (mode) << \
                                                                            cyUart_p50_p51_UART_CTRL_MODE_POS) & \
                                                                            cyUart_p50_p51_UART_CTRL_MODE_MASK)

/* cyUart_p50_p51_UART_RX_CTRL */
#define cyUart_p50_p51_GET_UART_RX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                        cyUart_p50_p51_UART_RX_CTRL_STOP_BITS_MASK)

#define cyUart_p50_p51_GET_UART_RX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                                    (cyUart_p50_p51_UART_RX_CTRL_PARITY) : (0u))

#define cyUart_p50_p51_GET_UART_RX_CTRL_POLARITY(polarity)    ((0u != (polarity)) ? \
                                                                    (cyUart_p50_p51_UART_RX_CTRL_POLARITY) : (0u))

#define cyUart_p50_p51_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (cyUart_p50_p51_UART_RX_CTRL_DROP_ON_PARITY_ERR) : (0u))

#define cyUart_p50_p51_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (cyUart_p50_p51_UART_RX_CTRL_DROP_ON_FRAME_ERR) : (0u))

#define cyUart_p50_p51_GET_UART_RX_CTRL_MP_MODE(mpMode)   ((0u != (mpMode)) ? \
                                                        (cyUart_p50_p51_UART_RX_CTRL_MP_MODE) : (0u))

#define cyUart_p50_p51_GET_UART_RX_CTRL_BREAK_WIDTH(width)    (((uint32) ((uint32) (width) - 1u) << \
                                                                    cyUart_p50_p51_UART_RX_CTRL_BREAK_WIDTH_POS) & \
                                                                    cyUart_p50_p51_UART_RX_CTRL_BREAK_WIDTH_MASK)

/* cyUart_p50_p51_UART_TX_CTRL */
#define cyUart_p50_p51_GET_UART_TX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                cyUart_p50_p51_UART_RX_CTRL_STOP_BITS_MASK)

#define cyUart_p50_p51_GET_UART_TX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                               (cyUart_p50_p51_UART_TX_CTRL_PARITY) : (0u))

#define cyUart_p50_p51_GET_UART_TX_CTRL_RETRY_NACK(nack)  ((0u != (nack)) ? \
                                                               (cyUart_p50_p51_UART_TX_CTRL_RETRY_ON_NACK) : (0u))

/* cyUart_p50_p51_UART_FLOW_CTRL */
#if !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(level)   ( (uint32) (level) & \
                                                                 cyUart_p50_p51_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK)

    #define cyUart_p50_p51_GET_UART_FLOW_CTRL_RTS_POLARITY(polarity) ((0u != (polarity)) ? \
                                                                (cyUart_p50_p51_UART_FLOW_CTRL_RTS_POLARITY) : (0u))

    #define cyUart_p50_p51_GET_UART_FLOW_CTRL_CTS_POLARITY(polarity) ((0u != (polarity)) ? \
                                                                (cyUart_p50_p51_UART_FLOW_CTRL_CTS_POLARITY) : (0u))

    #define cyUart_p50_p51_GET_UART_FLOW_CTRL_CTS_ENABLE(ctsEn)      ((0u != (ctsEn)) ? \
                                                                (cyUart_p50_p51_UART_FLOW_CTRL_CTS_ENABLE) : (0u))
#endif /* !(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

/* cyUart_p50_p51_RX_CTRL */
#define cyUart_p50_p51_GET_RX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                cyUart_p50_p51_RX_CTRL_DATA_WIDTH_MASK)

#define cyUart_p50_p51_GET_RX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (cyUart_p50_p51_RX_CTRL_MSB_FIRST) : (0u))

#define cyUart_p50_p51_GET_RX_CTRL_MEDIAN(filterEn)       ((0u != (filterEn)) ? \
                                                                (cyUart_p50_p51_RX_CTRL_MEDIAN) : (0u))

/* cyUart_p50_p51_RX_MATCH */
#define cyUart_p50_p51_GET_RX_MATCH_ADDR(addr)    ((uint32) (addr) & cyUart_p50_p51_RX_MATCH_ADDR_MASK)
#define cyUart_p50_p51_GET_RX_MATCH_MASK(mask)    (((uint32) (mask) << \
                                                            cyUart_p50_p51_RX_MATCH_MASK_POS) & \
                                                            cyUart_p50_p51_RX_MATCH_MASK_MASK)

/* cyUart_p50_p51_RX_FIFO_CTRL */
#define cyUart_p50_p51_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    cyUart_p50_p51_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* cyUart_p50_p51_TX_CTRL */
#define cyUart_p50_p51_GET_TX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                cyUart_p50_p51_TX_CTRL_DATA_WIDTH_MASK)

#define cyUart_p50_p51_GET_TX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (cyUart_p50_p51_TX_CTRL_MSB_FIRST) : (0u))

/* cyUart_p50_p51_TX_FIFO_CTRL */
#define cyUart_p50_p51_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    cyUart_p50_p51_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* cyUart_p50_p51_INTR_SLAVE_I2C_GENERAL */
#define cyUart_p50_p51_GET_INTR_SLAVE_I2C_GENERAL(genCall)  ((0u != (genCall)) ? \
                                                                (cyUart_p50_p51_INTR_SLAVE_I2C_GENERAL) : (0u))

/* Return true if master mode is enabled cyUart_p50_p51_SPI_CTRL_REG */
#define cyUart_p50_p51_CHECK_SPI_MASTER   (0u != (cyUart_p50_p51_SPI_CTRL_REG & cyUart_p50_p51_SPI_CTRL_MASTER))

/* Return inactive state of SPI SCLK line depends on CPOL */
#define cyUart_p50_p51_GET_SPI_SCLK_INACTIVE \
            ((0u == (cyUart_p50_p51_SPI_CTRL_REG & cyUart_p50_p51_SPI_CTRL_CPOL)) ? (0u) : (1u))

/* Get output pin inactive state */
#if (cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1)
#define cyUart_p50_p51_GET_SPI_SS0_INACTIVE       (1u)
#define cyUart_p50_p51_GET_SPI_SS1_INACTIVE       (1u)
#define cyUart_p50_p51_GET_SPI_SS2_INACTIVE       (1u)
#define cyUart_p50_p51_GET_SPI_SS3_INACTIVE       (1u)
#define cyUart_p50_p51_GET_UART_RTS_INACTIVE      (1u)

#else
#define cyUart_p50_p51_GET_SPI_SS0_INACTIVE  \
        ((0u != (cyUart_p50_p51_SPI_CTRL_REG & cyUart_p50_p51_SPI_CTRL_SSEL0_POLARITY)) ? (0u) : (1u))

#define cyUart_p50_p51_GET_SPI_SS1_INACTIVE  \
        ((0u != (cyUart_p50_p51_SPI_CTRL_REG & cyUart_p50_p51_SPI_CTRL_SSEL1_POLARITY)) ? (0u) : (1u))

#define cyUart_p50_p51_GET_SPI_SS2_INACTIVE  \
        ((0u != (cyUart_p50_p51_SPI_CTRL_REG & cyUart_p50_p51_SPI_CTRL_SSEL2_POLARITY)) ? (0u) : (1u))

#define cyUart_p50_p51_GET_SPI_SS3_INACTIVE  \
        ((0u != (cyUart_p50_p51_SPI_CTRL_REG & cyUart_p50_p51_SPI_CTRL_SSEL3_POLARITY)) ? (0u) : (1u))

#define cyUart_p50_p51_GET_UART_RTS_INACTIVE \
        ((0u == (cyUart_p50_p51_UART_FLOW_CTRL_REG & cyUart_p50_p51_UART_FLOW_CTRL_RTS_POLARITY)) ? (0u) : (1u))

#endif /*(cyUart_p50_p51_CY_SCBIP_V0 || cyUart_p50_p51_CY_SCBIP_V1) */

/* Clear register constants for configuration and interrupt mask */
#define cyUart_p50_p51_CLEAR_REG          ((uint32) (0u))
#define cyUart_p50_p51_NO_INTR_SOURCES    ((uint32) (0u))
#define cyUart_p50_p51_DUMMY_PARAM        ((uint32) (0u))
#define cyUart_p50_p51_SUBMODE_SPI_SLAVE  ((uint32) (0u))

/* Return in case of I2C read error */
#define cyUart_p50_p51_I2C_INVALID_BYTE   ((uint32) 0xFFFFFFFFu)
#define cyUart_p50_p51_CHECK_VALID_BYTE   ((uint32) 0x80000000u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

#define cyUart_p50_p51_CHECK_INTR_EC_I2C(sourceMask)  cyUart_p50_p51_CHECK_INTR_I2C_EC(sourceMask)
#if (!cyUart_p50_p51_CY_SCBIP_V1)
    #define cyUart_p50_p51_CHECK_INTR_EC_SPI(sourceMask)  cyUart_p50_p51_CHECK_INTR_SPI_EC(sourceMask)
#endif /* (!cyUart_p50_p51_CY_SCBIP_V1) */

#define cyUart_p50_p51_CY_SCBIP_V1_I2C_ONLY   (cyUart_p50_p51_CY_SCBIP_V1)
#define cyUart_p50_p51_EZBUFFER_SIZE          (cyUart_p50_p51_EZ_DATA_NR)

#define cyUart_p50_p51_EZBUF_DATA00_REG   cyUart_p50_p51_EZBUF_DATA0_REG
#define cyUart_p50_p51_EZBUF_DATA00_PTR   cyUart_p50_p51_EZBUF_DATA0_PTR

#endif /* (CY_SCB_cyUart_p50_p51_H) */


/* [] END OF FILE */
