/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////

#include "custom_main.h"





////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
// Timer period: 500000uS
//#define TMR_PERIOD         500000U
//#if defined(TWR_KV46F150M)
//#define LPTMR0_IDX LPTMR_IDX
//#endif

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
/*!
 * @brief LPTMR interrupt call back function.
 * The function is used to toggle LED1.
 */
//void lptmr_call_back(void)
//{
//    // Toggle LED1
//    LED1_TOGGLE;
//}

/*!
 * @brief Main function
 */



int main (void)
{
    // RX buffers
    //! @param receiveBuff Buffer used to hold received data
//    uint8_t receiveBuff;


#ifdef FRDM
//    // Initialize standard SDK demo application pins
    hardware_init();
#endif


    // Set timer period for TMR_PERIOD seconds
//    LPTMR_DRV_SetTimerPeriodUs(LPTMR0_IDX, TMR_PERIOD);
    // Install interrupt call back function for LPTMR
//    LPTMR_DRV_InstallCallback(LPTMR0_IDX, lptmr_call_back);

//	LPTMR_DRV_Start(LPTMR0_IDX);

    // Initialize LED1
 //   LED1_EN;

    cmain();
}
