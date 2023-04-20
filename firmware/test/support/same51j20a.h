#ifndef _SAME51J20A_H_
#define _SAME51J20A_H_

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#include "core_cm4.h"

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR SAME51J20A                        */
/* ************************************************************************** */
#include "component/ac.h"
// #include "component/adc.h"
#include "../packs/ATSAME51J20A_DFP/component/adc.h"
#include "component/aes.h"
#include "component/can.h"
#include "component/ccl.h"
#include "component/cmcc.h"
#include "component/dac.h"
#include "component/dmac.h"
#include "component/dsu.h"
#include "component/eic.h"
#include "component/evsys.h"
#include "component/freqm.h"
#include "component/fuses.h"
#include "component/gclk.h"
#include "component/hmatrixb.h"
#include "component/i2s.h"
#include "component/icm.h"
#include "component/mclk.h"
#include "component/nvmctrl.h"
#include "component/osc32kctrl.h"
#include "component/oscctrl.h"
#include "component/pac.h"
#include "component/pcc.h"
#include "component/pdec.h"
#include "component/pm.h"
#include "component/port.h"
#include "component/pukcc.h"
#include "component/qspi.h"
#include "component/ramecc.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/sdhc.h"
#include "component/sercom.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/tcc.h"
#include "component/trng.h"
#include "component/usb.h"
#include "component/wdt.h"

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with sizes of integer constants for C/C++ */
#  define _UINT8_(x)   ((uint8_t)(x))    /* C code: 8-bits unsigned integer constant value */
#  define _UINT16_(x)  ((uint16_t)(x))   /* C code: 16-bits unsigned integer constant value */
#  define _UINT32_(x)  ((uint32_t)(x))   /* C code: 32-bits unsigned integer constant value */

#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M4 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /* -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /* -13 Hard Fault, all classes of Fault    */
  MemoryManagement_IRQn     = -12, /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11, /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn           = -10, /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SVCall_IRQn               =  -5, /* -5  System Service Call via SVC instruction */
  DebugMonitor_IRQn         =  -4, /* -4  Debug Monitor                       */
  PendSV_IRQn               =  -2, /* -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /* -1  System Tick Timer                   */

/******  SAME51J20A specific Interrupt Numbers ***********************************/
  PM_IRQn                   =   0, /* 0   Power Manager (PM)                  */
  MCLK_IRQn                 =   1, /* 1   Main Clock (MCLK)                   */
  OSCCTRL_XOSC0_IRQn        =   2, /* 2   Oscillators Control (OSCCTRL)       */
  OSCCTRL_XOSC1_IRQn        =   3, /* 3   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DFLL_IRQn         =   4, /* 4   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DPLL0_IRQn        =   5, /* 5   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DPLL1_IRQn        =   6, /* 6   Oscillators Control (OSCCTRL)       */
  OSC32KCTRL_IRQn           =   7, /* 7   32kHz Oscillators Control (OSC32KCTRL) */
  SUPC_OTHER_IRQn           =   8, /* 8   Supply Controller (SUPC)            */
  SUPC_BODDET_IRQn          =   9, /* 9   Supply Controller (SUPC)            */
  WDT_IRQn                  =  10, /* 10  Watchdog Timer (WDT)                */
  RTC_IRQn                  =  11, /* 11  Real-Time Counter (RTC)             */
  EIC_EXTINT_0_IRQn         =  12, /* 12  External Interrupt Controller (EIC) */
  EIC_EXTINT_1_IRQn         =  13, /* 13  External Interrupt Controller (EIC) */
  EIC_EXTINT_2_IRQn         =  14, /* 14  External Interrupt Controller (EIC) */
  EIC_EXTINT_3_IRQn         =  15, /* 15  External Interrupt Controller (EIC) */
  EIC_EXTINT_4_IRQn         =  16, /* 16  External Interrupt Controller (EIC) */
  EIC_EXTINT_5_IRQn         =  17, /* 17  External Interrupt Controller (EIC) */
  EIC_EXTINT_6_IRQn         =  18, /* 18  External Interrupt Controller (EIC) */
  EIC_EXTINT_7_IRQn         =  19, /* 19  External Interrupt Controller (EIC) */
  EIC_EXTINT_8_IRQn         =  20, /* 20  External Interrupt Controller (EIC) */
  EIC_EXTINT_9_IRQn         =  21, /* 21  External Interrupt Controller (EIC) */
  EIC_EXTINT_10_IRQn        =  22, /* 22  External Interrupt Controller (EIC) */
  EIC_EXTINT_11_IRQn        =  23, /* 23  External Interrupt Controller (EIC) */
  EIC_EXTINT_12_IRQn        =  24, /* 24  External Interrupt Controller (EIC) */
  EIC_EXTINT_13_IRQn        =  25, /* 25  External Interrupt Controller (EIC) */
  EIC_EXTINT_14_IRQn        =  26, /* 26  External Interrupt Controller (EIC) */
  EIC_EXTINT_15_IRQn        =  27, /* 27  External Interrupt Controller (EIC) */
  FREQM_IRQn                =  28, /* 28  Frequency Meter (FREQM)             */
  NVMCTRL_0_IRQn            =  29, /* 29  Non-Volatile Memory Controller (NVMCTRL) */
  NVMCTRL_1_IRQn            =  30, /* 30  Non-Volatile Memory Controller (NVMCTRL) */
  DMAC_0_IRQn               =  31, /* 31  Direct Memory Access Controller (DMAC) */
  DMAC_1_IRQn               =  32, /* 32  Direct Memory Access Controller (DMAC) */
  DMAC_2_IRQn               =  33, /* 33  Direct Memory Access Controller (DMAC) */
  DMAC_3_IRQn               =  34, /* 34  Direct Memory Access Controller (DMAC) */
  DMAC_OTHER_IRQn           =  35, /* 35  Direct Memory Access Controller (DMAC) */
  EVSYS_0_IRQn              =  36, /* 36  Event System Interface (EVSYS)      */
  EVSYS_1_IRQn              =  37, /* 37  Event System Interface (EVSYS)      */
  EVSYS_2_IRQn              =  38, /* 38  Event System Interface (EVSYS)      */
  EVSYS_3_IRQn              =  39, /* 39  Event System Interface (EVSYS)      */
  EVSYS_OTHER_IRQn          =  40, /* 40  Event System Interface (EVSYS)      */
  PAC_IRQn                  =  41, /* 41  Peripheral Access Controller (PAC)  */
  RAMECC_IRQn               =  45, /* 45  RAM ECC (RAMECC)                    */
  SERCOM0_0_IRQn            =  46, /* 46  Serial Communication Interface (SERCOM0) */
  SERCOM0_1_IRQn            =  47, /* 47  Serial Communication Interface (SERCOM0) */
  SERCOM0_2_IRQn            =  48, /* 48  Serial Communication Interface (SERCOM0) */
  SERCOM0_OTHER_IRQn        =  49, /* 49  Serial Communication Interface (SERCOM0) */
  SERCOM1_0_IRQn            =  50, /* 50  Serial Communication Interface (SERCOM1) */
  SERCOM1_1_IRQn            =  51, /* 51  Serial Communication Interface (SERCOM1) */
  SERCOM1_2_IRQn            =  52, /* 52  Serial Communication Interface (SERCOM1) */
  SERCOM1_OTHER_IRQn        =  53, /* 53  Serial Communication Interface (SERCOM1) */
  SERCOM2_0_IRQn            =  54, /* 54  Serial Communication Interface (SERCOM2) */
  SERCOM2_1_IRQn            =  55, /* 55  Serial Communication Interface (SERCOM2) */
  SERCOM2_2_IRQn            =  56, /* 56  Serial Communication Interface (SERCOM2) */
  SERCOM2_OTHER_IRQn        =  57, /* 57  Serial Communication Interface (SERCOM2) */
  SERCOM3_0_IRQn            =  58, /* 58  Serial Communication Interface (SERCOM3) */
  SERCOM3_1_IRQn            =  59, /* 59  Serial Communication Interface (SERCOM3) */
  SERCOM3_2_IRQn            =  60, /* 60  Serial Communication Interface (SERCOM3) */
  SERCOM3_OTHER_IRQn        =  61, /* 61  Serial Communication Interface (SERCOM3) */
  SERCOM4_0_IRQn            =  62, /* 62  Serial Communication Interface (SERCOM4) */
  SERCOM4_1_IRQn            =  63, /* 63  Serial Communication Interface (SERCOM4) */
  SERCOM4_2_IRQn            =  64, /* 64  Serial Communication Interface (SERCOM4) */
  SERCOM4_OTHER_IRQn        =  65, /* 65  Serial Communication Interface (SERCOM4) */
  SERCOM5_0_IRQn            =  66, /* 66  Serial Communication Interface (SERCOM5) */
  SERCOM5_1_IRQn            =  67, /* 67  Serial Communication Interface (SERCOM5) */
  SERCOM5_2_IRQn            =  68, /* 68  Serial Communication Interface (SERCOM5) */
  SERCOM5_OTHER_IRQn        =  69, /* 69  Serial Communication Interface (SERCOM5) */
  CAN0_IRQn                 =  78, /* 78  Control Area Network (CAN0)         */
  CAN1_IRQn                 =  79, /* 79  Control Area Network (CAN1)         */
  USB_OTHER_IRQn            =  80, /* 80  Universal Serial Bus (USB)          */
  USB_SOF_HSOF_IRQn         =  81, /* 81  Universal Serial Bus (USB)          */
  USB_TRCPT0_IRQn           =  82, /* 82  Universal Serial Bus (USB)          */
  USB_TRCPT1_IRQn           =  83, /* 83  Universal Serial Bus (USB)          */
  TCC0_OTHER_IRQn           =  85, /* 85  Timer Counter Control (TCC0)        */
  TCC0_MC0_IRQn             =  86, /* 86  Timer Counter Control (TCC0)        */
  TCC0_MC1_IRQn             =  87, /* 87  Timer Counter Control (TCC0)        */
  TCC0_MC2_IRQn             =  88, /* 88  Timer Counter Control (TCC0)        */
  TCC0_MC3_IRQn             =  89, /* 89  Timer Counter Control (TCC0)        */
  TCC0_MC4_IRQn             =  90, /* 90  Timer Counter Control (TCC0)        */
  TCC0_MC5_IRQn             =  91, /* 91  Timer Counter Control (TCC0)        */
  TCC1_OTHER_IRQn           =  92, /* 92  Timer Counter Control (TCC1)        */
  TCC1_MC0_IRQn             =  93, /* 93  Timer Counter Control (TCC1)        */
  TCC1_MC1_IRQn             =  94, /* 94  Timer Counter Control (TCC1)        */
  TCC1_MC2_IRQn             =  95, /* 95  Timer Counter Control (TCC1)        */
  TCC1_MC3_IRQn             =  96, /* 96  Timer Counter Control (TCC1)        */
  TCC2_OTHER_IRQn           =  97, /* 97  Timer Counter Control (TCC2)        */
  TCC2_MC0_IRQn             =  98, /* 98  Timer Counter Control (TCC2)        */
  TCC2_MC1_IRQn             =  99, /* 99  Timer Counter Control (TCC2)        */
  TCC2_MC2_IRQn             = 100, /* 100 Timer Counter Control (TCC2)        */
  TCC3_OTHER_IRQn           = 101, /* 101 Timer Counter Control (TCC3)        */
  TCC3_MC0_IRQn             = 102, /* 102 Timer Counter Control (TCC3)        */
  TCC3_MC1_IRQn             = 103, /* 103 Timer Counter Control (TCC3)        */
  TCC4_OTHER_IRQn           = 104, /* 104 Timer Counter Control (TCC4)        */
  TCC4_MC0_IRQn             = 105, /* 105 Timer Counter Control (TCC4)        */
  TCC4_MC1_IRQn             = 106, /* 106 Timer Counter Control (TCC4)        */
  TC0_IRQn                  = 107, /* 107 Basic Timer Counter (TC0)           */
  TC1_IRQn                  = 108, /* 108 Basic Timer Counter (TC1)           */
  TC2_IRQn                  = 109, /* 109 Basic Timer Counter (TC2)           */
  TC3_IRQn                  = 110, /* 110 Basic Timer Counter (TC3)           */
  TC4_IRQn                  = 111, /* 111 Basic Timer Counter (TC4)           */
  TC5_IRQn                  = 112, /* 112 Basic Timer Counter (TC5)           */
  PDEC_OTHER_IRQn           = 115, /* 115 Quadrature Decodeur (PDEC)          */
  PDEC_MC0_IRQn             = 116, /* 116 Quadrature Decodeur (PDEC)          */
  PDEC_MC1_IRQn             = 117, /* 117 Quadrature Decodeur (PDEC)          */
  ADC0_OTHER_IRQn           = 118, /* 118 Analog Digital Converter (ADC0)     */
  ADC0_RESRDY_IRQn          = 119, /* 119 Analog Digital Converter (ADC0)     */
  ADC1_OTHER_IRQn           = 120, /* 120 Analog Digital Converter (ADC1)     */
  ADC1_RESRDY_IRQn          = 121, /* 121 Analog Digital Converter (ADC1)     */
  AC_IRQn                   = 122, /* 122 Analog Comparators (AC)             */
  DAC_OTHER_IRQn            = 123, /* 123 Digital-to-Analog Converter (DAC)   */
  DAC_EMPTY_0_IRQn          = 124, /* 124 Digital-to-Analog Converter (DAC)   */
  DAC_EMPTY_1_IRQn          = 125, /* 125 Digital-to-Analog Converter (DAC)   */
  DAC_RESRDY_0_IRQn         = 126, /* 126 Digital-to-Analog Converter (DAC)   */
  DAC_RESRDY_1_IRQn         = 127, /* 127 Digital-to-Analog Converter (DAC)   */
  I2S_IRQn                  = 128, /* 128 Inter-IC Sound Interface (I2S)      */
  PCC_IRQn                  = 129, /* 129 Parallel Capture Controller (PCC)   */
  AES_IRQn                  = 130, /* 130 Advanced Encryption Standard (AES)  */
  TRNG_IRQn                 = 131, /* 131 True Random Generator (TRNG)        */
  ICM_IRQn                  = 132, /* 132 Integrity Check Monitor (ICM)       */
  PUKCC_IRQn                = 133, /* 133 PUblic-Key Cryptography Controller (PUKCC) */
  QSPI_IRQn                 = 134, /* 134 Quad SPI interface (QSPI)           */
  SDHC0_IRQn                = 135, /* 135 SD/MMC Host Controller (SDHC0)      */

  PERIPH_MAX_IRQn           = 135  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M4 handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnPM_Handler;                           /*   0 Power Manager (PM) */
  void* pfnMCLK_Handler;                         /*   1 Main Clock (MCLK) */
  void* pfnOSCCTRL_XOSC0_Handler;                /*   2 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_XOSC1_Handler;                /*   3 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DFLL_Handler;                 /*   4 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DPLL0_Handler;                /*   5 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DPLL1_Handler;                /*   6 Oscillators Control (OSCCTRL) */
  void* pfnOSC32KCTRL_Handler;                   /*   7 32kHz Oscillators Control (OSC32KCTRL) */
  void* pfnSUPC_OTHER_Handler;                   /*   8 Supply Controller (SUPC) */
  void* pfnSUPC_BODDET_Handler;                  /*   9 Supply Controller (SUPC) */
  void* pfnWDT_Handler;                          /*  10 Watchdog Timer (WDT) */
  void* pfnRTC_Handler;                          /*  11 Real-Time Counter (RTC) */
  void* pfnEIC_EXTINT_0_Handler;                 /*  12 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_1_Handler;                 /*  13 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_2_Handler;                 /*  14 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_3_Handler;                 /*  15 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_4_Handler;                 /*  16 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_5_Handler;                 /*  17 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_6_Handler;                 /*  18 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_7_Handler;                 /*  19 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_8_Handler;                 /*  20 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_9_Handler;                 /*  21 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_10_Handler;                /*  22 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_11_Handler;                /*  23 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_12_Handler;                /*  24 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_13_Handler;                /*  25 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_14_Handler;                /*  26 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_15_Handler;                /*  27 External Interrupt Controller (EIC) */
  void* pfnFREQM_Handler;                        /*  28 Frequency Meter (FREQM) */
  void* pfnNVMCTRL_0_Handler;                    /*  29 Non-Volatile Memory Controller (NVMCTRL) */
  void* pfnNVMCTRL_1_Handler;                    /*  30 Non-Volatile Memory Controller (NVMCTRL) */
  void* pfnDMAC_0_Handler;                       /*  31 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_1_Handler;                       /*  32 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_2_Handler;                       /*  33 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_3_Handler;                       /*  34 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_OTHER_Handler;                   /*  35 Direct Memory Access Controller (DMAC) */
  void* pfnEVSYS_0_Handler;                      /*  36 Event System Interface (EVSYS) */
  void* pfnEVSYS_1_Handler;                      /*  37 Event System Interface (EVSYS) */
  void* pfnEVSYS_2_Handler;                      /*  38 Event System Interface (EVSYS) */
  void* pfnEVSYS_3_Handler;                      /*  39 Event System Interface (EVSYS) */
  void* pfnEVSYS_OTHER_Handler;                  /*  40 Event System Interface (EVSYS) */
  void* pfnPAC_Handler;                          /*  41 Peripheral Access Controller (PAC) */
  void* pvReserved42;
  void* pvReserved43;
  void* pvReserved44;
  void* pfnRAMECC_Handler;                       /*  45 RAM ECC (RAMECC) */
  void* pfnSERCOM0_0_Handler;                    /*  46 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_1_Handler;                    /*  47 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_2_Handler;                    /*  48 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_OTHER_Handler;                /*  49 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM1_0_Handler;                    /*  50 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_1_Handler;                    /*  51 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_2_Handler;                    /*  52 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_OTHER_Handler;                /*  53 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM2_0_Handler;                    /*  54 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_1_Handler;                    /*  55 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_2_Handler;                    /*  56 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_OTHER_Handler;                /*  57 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM3_0_Handler;                    /*  58 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_1_Handler;                    /*  59 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_2_Handler;                    /*  60 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_OTHER_Handler;                /*  61 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM4_0_Handler;                    /*  62 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_1_Handler;                    /*  63 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_2_Handler;                    /*  64 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_OTHER_Handler;                /*  65 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM5_0_Handler;                    /*  66 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_1_Handler;                    /*  67 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_2_Handler;                    /*  68 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_OTHER_Handler;                /*  69 Serial Communication Interface (SERCOM5) */
  void* pvReserved70;
  void* pvReserved71;
  void* pvReserved72;
  void* pvReserved73;
  void* pvReserved74;
  void* pvReserved75;
  void* pvReserved76;
  void* pvReserved77;
  void* pfnCAN0_Handler;                         /*  78 Control Area Network (CAN0) */
  void* pfnCAN1_Handler;                         /*  79 Control Area Network (CAN1) */
  void* pfnUSB_OTHER_Handler;                    /*  80 Universal Serial Bus (USB) */
  void* pfnUSB_SOF_HSOF_Handler;                 /*  81 Universal Serial Bus (USB) */
  void* pfnUSB_TRCPT0_Handler;                   /*  82 Universal Serial Bus (USB) */
  void* pfnUSB_TRCPT1_Handler;                   /*  83 Universal Serial Bus (USB) */
  void* pvReserved84;
  void* pfnTCC0_OTHER_Handler;                   /*  85 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC0_Handler;                     /*  86 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC1_Handler;                     /*  87 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC2_Handler;                     /*  88 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC3_Handler;                     /*  89 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC4_Handler;                     /*  90 Timer Counter Control (TCC0) */
  void* pfnTCC0_MC5_Handler;                     /*  91 Timer Counter Control (TCC0) */
  void* pfnTCC1_OTHER_Handler;                   /*  92 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC0_Handler;                     /*  93 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC1_Handler;                     /*  94 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC2_Handler;                     /*  95 Timer Counter Control (TCC1) */
  void* pfnTCC1_MC3_Handler;                     /*  96 Timer Counter Control (TCC1) */
  void* pfnTCC2_OTHER_Handler;                   /*  97 Timer Counter Control (TCC2) */
  void* pfnTCC2_MC0_Handler;                     /*  98 Timer Counter Control (TCC2) */
  void* pfnTCC2_MC1_Handler;                     /*  99 Timer Counter Control (TCC2) */
  void* pfnTCC2_MC2_Handler;                     /* 100 Timer Counter Control (TCC2) */
  void* pfnTCC3_OTHER_Handler;                   /* 101 Timer Counter Control (TCC3) */
  void* pfnTCC3_MC0_Handler;                     /* 102 Timer Counter Control (TCC3) */
  void* pfnTCC3_MC1_Handler;                     /* 103 Timer Counter Control (TCC3) */
  void* pfnTCC4_OTHER_Handler;                   /* 104 Timer Counter Control (TCC4) */
  void* pfnTCC4_MC0_Handler;                     /* 105 Timer Counter Control (TCC4) */
  void* pfnTCC4_MC1_Handler;                     /* 106 Timer Counter Control (TCC4) */
  void* pfnTC0_Handler;                          /* 107 Basic Timer Counter (TC0) */
  void* pfnTC1_Handler;                          /* 108 Basic Timer Counter (TC1) */
  void* pfnTC2_Handler;                          /* 109 Basic Timer Counter (TC2) */
  void* pfnTC3_Handler;                          /* 110 Basic Timer Counter (TC3) */
  void* pfnTC4_Handler;                          /* 111 Basic Timer Counter (TC4) */
  void* pfnTC5_Handler;                          /* 112 Basic Timer Counter (TC5) */
  void* pvReserved113;
  void* pvReserved114;
  void* pfnPDEC_OTHER_Handler;                   /* 115 Quadrature Decodeur (PDEC) */
  void* pfnPDEC_MC0_Handler;                     /* 116 Quadrature Decodeur (PDEC) */
  void* pfnPDEC_MC1_Handler;                     /* 117 Quadrature Decodeur (PDEC) */
  void* pfnADC0_OTHER_Handler;                   /* 118 Analog Digital Converter (ADC0) */
  void* pfnADC0_RESRDY_Handler;                  /* 119 Analog Digital Converter (ADC0) */
  void* pfnADC1_OTHER_Handler;                   /* 120 Analog Digital Converter (ADC1) */
  void* pfnADC1_RESRDY_Handler;                  /* 121 Analog Digital Converter (ADC1) */
  void* pfnAC_Handler;                           /* 122 Analog Comparators (AC) */
  void* pfnDAC_OTHER_Handler;                    /* 123 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_EMPTY_0_Handler;                  /* 124 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_EMPTY_1_Handler;                  /* 125 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_RESRDY_0_Handler;                 /* 126 Digital-to-Analog Converter (DAC) */
  void* pfnDAC_RESRDY_1_Handler;                 /* 127 Digital-to-Analog Converter (DAC) */
  void* pfnI2S_Handler;                          /* 128 Inter-IC Sound Interface (I2S) */
  void* pfnPCC_Handler;                          /* 129 Parallel Capture Controller (PCC) */
  void* pfnAES_Handler;                          /* 130 Advanced Encryption Standard (AES) */
  void* pfnTRNG_Handler;                         /* 131 True Random Generator (TRNG) */
  void* pfnICM_Handler;                          /* 132 Integrity Check Monitor (ICM) */
  void* pfnPUKCC_Handler;                        /* 133 PUblic-Key Cryptography Controller (PUKCC) */
  void* pfnQSPI_Handler;                         /* 134 Quad SPI interface (QSPI) */
  void* pfnSDHC0_Handler;                        /* 135 SD/MMC Host Controller (SDHC0) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAME51J20A_H_ */