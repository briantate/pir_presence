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
mcp3221Handle mcp3221;
uint16_t adc_count;

bool isConversionComplete;

void MyMCP3221_Callback(MCP3221_EVENT event)
{
    if (MCP3221_CONVERSION_COMPLETE == event)
    {
//        printf("val = %d \r\n",MCP3221_GetResult(mcp3221));
        isConversionComplete = true;
    }
    else if(MCP3221_CONVERSION_PENDING == event)
    {
        printf("Conversion pending \r\n");
    }
    else
    {
        printf("mcp3221 error: %d \r\n", event);
    }
}


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
    isConversionComplete = false;
    ADC0_Enable();
    printf("PIR presence detection\r\n");
    
    mcp3221 = MCP3221_Open(0x4D, MyMCP3221_Callback);
    
    if(0 == mcp3221)
    {
        printf("error opening MCP3221\r\n");
    }
    else
    {
        printf("MCP3221 open successful %x \r\n", mcp3221);
    }
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        for(i = 0; i<10000000; i++)
        {
            __asm("NOP");
        }
        LED0_Toggle();
        MCP3221_StartConversion(mcp3221);
        while(!isConversionComplete)
        {
            __asm("NOP");
        }
        isConversionComplete = false;
        printf("val = %d \r\n",MCP3221_GetResult(mcp3221));
        
        ADC0_ConversionStart();

        /* Wait till ADC conversion result is available */
        while(!ADC0_ConversionStatusGet())
        {

        };

        /* Read the ADC result */
        adc_count = ADC0_ConversionResultGet();
        printf("adc = %d \r\n",adc_count);
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

