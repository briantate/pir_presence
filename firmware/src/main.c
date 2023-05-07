/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "MCP3221.h"
#include "analog/MCP3221.h"
#include "PIR_CLICK.h"

#define MOTION_DETECT_THRESHOLD (2500)

#define ADC_METHOD_MCP3221

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

volatile uint32_t i = 0;
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    ADC0_Enable();
    puts("PIR presence detection\r\n");
    
    PIR_Init();
    
    while ( true )
    {
        uint16_t mcpVal = 0;
        uint16_t adcVal = 0;
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        
        for(i = 0; i<10000000; i++)
        {
            __asm("NOP");
        }
        LED0_Toggle();
        
#ifdef ADC_METHOD_MCP3221
        
        if(PIR_IsPresent())
        {
            puts("MCP motion detected \r\n");
        }
#else                 
        ADC0_ConversionStart();

        /* Wait till ADC conversion result is available */
        while(!ADC0_ConversionStatusGet())
        {

        };

        /* Read the ADC result */
        adcVal = ADC0_ConversionResultGet();
//        printf("adc = %d \r\n",adcVal);
        if(MOTION_DETECT_THRESHOLD < adcVal)
        {
            puts("ADC motion detected\r\n");
        }
#endif  
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

