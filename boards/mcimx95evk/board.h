/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BOARD_H
#define BOARD_H

#include "fsl_common.h"
#include "config_board.h"
#include "dev_sm.h"

/*!
 * @addtogroup BRD_SM_MX95EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the board API.
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @name Board general parameters
 */
/** @{ */
#define BOARD_TICK_PERIOD_MSEC  10U               /*!< Tick period */
#define BOARD_SWI_IRQn          Reserved110_IRQn  /*!< SWI IRQ */
#define BOARD_HAS_WDOG                            /*!< Has a watchdog */
#define BOARD_HAS_PMIC                            /*!< Has a PMIC */
#define BOARD_HAS_GPIO1_0                         /*!< Uses GPIO1 0 */
/** @} */

/*!
 * @name Watchdog modes
 */
/** @{ */
#define BOARD_WDOG_MODE_WARM     0U  /*!< Wdog generate warm reset */
#define BOARD_WDOG_MODE_COLD     1U  /*!< Wdog generate cold reset */
#define BOARD_WDOG_MODE_IRQ      2U  /*!< Wdog generate IRQ only */
#define BOARD_WDOG_MODE_OFF      3U  /*!< Wdog disabled */
#define BOARD_WDOG_MODE_TRIGGER  4U  /*!< Trigger wdog */
/** @} */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/

/*! Configure the M33 MPU */
void BOARD_ConfigMPU(void);

/*! Init hardware */
void BOARD_InitHardware(void);

/*! Init clocks */
void BOARD_InitClocks(void);

/*!
 * Get a device clock debug UART info.
 *
 * @param inst Return SDK LPUART instance
 * @param baud Return baud rate in Hz
 * @param clockId Return clockId for the UART
 *
 * This function returns the UART info for the UART used for SM
 * debug..
 *
 * @return Returns the LPUART base type pointer.
 */
LPUART_Type *BOARD_GetDebugUart(uint8_t *inst, uint32_t *baud,
    uint32_t *clockId);

/*! Init the debug UART */
void BOARD_InitDebugConsole(void);

/*! Init interrupt handlers */
void BOARD_InitHandlers(void);

/*! Init timers */
void BOARD_InitTimers(void);

/*! Init serial buses */
void BOARD_InitSerialBus(void);

/*!
 * Set the watchdog mode
 *
 * @param mode Mode to set.
 */
void BOARD_WdogModeSet(uint32_t mode);

/*! Service the watchdog */
void BOARD_WdogRefresh(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/** @} */

#endif /* BOARD_H */

