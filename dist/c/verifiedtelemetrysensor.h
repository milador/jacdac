// Autogenerated C header file for Verified Telemetry
#ifndef _JACDAC_SPEC_VERIFIED_TELEMETRY_H
#define _JACDAC_SPEC_VERIFIED_TELEMETRY_H 1

#define JD_SERVICE_CLASS_VERIFIED_TELEMETRY  0x2194841f

// enum Status (uint8_t)
#define JD_VERIFIED_TELEMETRY_STATUS_UNKNOWN 0x0
#define JD_VERIFIED_TELEMETRY_STATUS_WORKING 0x1
#define JD_VERIFIED_TELEMETRY_STATUS_FAULTY 0x2

// enum FingerprintType (uint8_t)
#define JD_VERIFIED_TELEMETRY_FINGERPRINT_TYPE_FALL_CURVE 0x1
#define JD_VERIFIED_TELEMETRY_FINGERPRINT_TYPE_CURRENT_SENSE 0x2
#define JD_VERIFIED_TELEMETRY_FINGERPRINT_TYPE_CUSTOM 0x3

/**
 * Read-only Status (uint8_t). Reads the telemetry working status, where ``true`` is working and ``false`` is faulty.
 */
#define JD_VERIFIED_TELEMETRY_REG_TELEMETRY_STATUS 0x180

/**
 * Read-write ms uint32_t. Specifies the interval between computing the fingerprint information.
 */
#define JD_VERIFIED_TELEMETRY_REG_TELEMETRY_STATUS_INTERVAL 0x80

/**
 * Constant FingerprintType (uint8_t). Type of the fingerprint.
 */
#define JD_VERIFIED_TELEMETRY_REG_FINGERPRINT_TYPE 0x181

/**
 * Template Fingerprint information of a working sensor.
 */
#define JD_VERIFIED_TELEMETRY_REG_FINGERPRINT_TEMPLATE 0x182
typedef struct jd_verified_telemetry_fingerprint_template {
    uint16_t confidence; // %
    uint8_t template[0];
} jd_verified_telemetry_fingerprint_template_t;


/**
 * No args. This command will clear the template fingerprint of a sensor and collect a new template fingerprint of the attached sensor.
 */
#define JD_VERIFIED_TELEMETRY_CMD_RESET_FINGERPRINT_TEMPLATE 0x80

/**
 * No args. This command will append a new template fingerprint to the `fingerprintTemplate`. Appending more fingerprints will increase the accuracy in detecting the telemetry status.
 */
#define JD_VERIFIED_TELEMETRY_CMD_RETRAIN_FINGERPRINT_TEMPLATE 0x81

/**
 * Argument: telemetry_status Status (uint8_t). The telemetry status of the device was updated.
 */
#define JD_VERIFIED_TELEMETRY_EV_TELEMETRY_STATUS_CHANGE JD_EV_CHANGE

/**
 * The fingerprint template was updated
 */
#define JD_VERIFIED_TELEMETRY_EV_FINGERPRINT_TEMPLATE_CHANGE 0x80

#endif