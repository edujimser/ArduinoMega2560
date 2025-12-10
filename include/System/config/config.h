#ifndef     CONF_MAIN_H
#define     CONF_MAIN_H


/**
 * @brief Main configuration structure for the project.
 *
 * Groups global parameters that control the overall behavior
 * of the application, allowing features to be enabled or disabled
 * at compile-time or runtime.
 */
struct configuracionMain {
    bool debugMode;
    bool fullDiagnosticsPins;
    bool diagnoseAnalog;
    bool diagnoseGPIO;
    bool diagnosePWM;
    bool diagnoseUART;
    bool diagnoseEEPROM;
};
extern configuracionMain systemConfiguration;

#endif // CONF_MAIN_H