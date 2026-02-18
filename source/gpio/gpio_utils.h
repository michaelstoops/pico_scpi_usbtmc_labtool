#ifndef _GPIO_UTILS_H
#define _GPIO_UTILS_H

#include "scpi/scpi.h"

#define INSTRUMENT_DIGI_OUTP_COMMANDS \
    {.pattern = "DIGItal:OUTPut#", .callback = SCPI_DigitalOutput,}, \
    {.pattern = "DIGItal:OUTPut#?", .callback = SCPI_DigitalOutputQ,},

#define INSTRUMENT_DIGI_INP_COMMANDS \
    {.pattern = "DIGItal:INPut#?", .callback = SCPI_DigitalInputQ,},


// GPIO output IDs, in order of their SCPI OUTP#
#ifndef GPIO_OUTPUTS
#define GPIO_OUTPUTS 22, 14, 15
#endif // GPIO_OUTPUTS

// GPIO input IDs, in order of their SCPI INP#
#ifndef GPIO_INPUTS
#define GPIO_INPUTS 20, 21, 27
#endif // GPIO_INPUTS

void initGpioUtils();

uint32_t outPinCount();

void initOutPins();
void setOutPinAt(uint32_t index, bool on);
bool isOutPinAt(uint32_t index);

uint32_t inPinCount();

void initInPins();
bool isInPinAt(uint32_t index);

scpi_result_t SCPI_DigitalOutput(scpi_t * context);
scpi_result_t SCPI_DigitalOutputQ(scpi_t * context);
scpi_result_t SCPI_DigitalInputQ(scpi_t * context);

#endif // _GPIO_UTILS_H
