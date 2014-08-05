/*
    Copyright (C) 2014  Cagdas Caglak cagdascaglak@gmail.com http://expcodes.blogspot.com.tr/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ADXL345.h"

ADXL345::ADXL345():i2c(1) {
}

ADXL345::ADXL345(BBB_I2C &i2c){
	this->i2c = i2c;
}

ADXL345::~ADXL345() {
}

void ADXL345::initialize() {
    i2c.writeByteNoExit(ADXL345_RA_POWER_CTL, 0);
    setAutoSleepEnabled(true);
    setMeasureEnabled(true);
}

uint8_t ADXL345::getDeviceID() {
    return i2c.readByteNoExit(ADXL345_RA_DEVID);
}

uint8_t ADXL345::getTapThreshold() {
    return i2c.readByteNoExit(ADXL345_RA_THRESH_TAP);
}

void ADXL345::setTapThreshold(uint8_t threshold) {
    i2c.writeByteNoExit(ADXL345_RA_THRESH_TAP, threshold);
}

void ADXL345::setOffset(int8_t x, int8_t y, int8_t z) {
    i2c.writeByteNoExit(ADXL345_RA_OFSX, x);
    i2c.writeByteNoExit(ADXL345_RA_OFSY, y);
    i2c.writeByteNoExit(ADXL345_RA_OFSZ, z);
}

int8_t ADXL345::getOffsetX() {
    return i2c.readByteNoExit(ADXL345_RA_OFSX);
}

void ADXL345::setOffsetX(int8_t x) {
    i2c.writeByteNoExit(ADXL345_RA_OFSX, x);
}

int8_t ADXL345::getOffsetY() {
    return i2c.readByteNoExit(ADXL345_RA_OFSY);
}

void ADXL345::setOffsetY(int8_t y) {
    i2c.writeByteNoExit(ADXL345_RA_OFSY, y);
}

int8_t ADXL345::getOffsetZ() {
    return i2c.readByteNoExit(ADXL345_RA_OFSZ);
}

void ADXL345::setOffsetZ(int8_t z) {
    i2c.writeByteNoExit(ADXL345_RA_OFSZ, z);
}

uint8_t ADXL345::getTapDuration() {
    return i2c.readByteNoExit(ADXL345_RA_DUR);
}

void ADXL345::setTapDuration(uint8_t duration) {
    i2c.writeByteNoExit(ADXL345_RA_DUR, duration);
}

uint8_t ADXL345::getDoubleTapLatency() {
    return i2c.readByteNoExit(ADXL345_RA_LATENT);
}

void ADXL345::setDoubleTapLatency(uint8_t latency) {
    i2c.writeByteNoExit(ADXL345_RA_LATENT, latency);
}

uint8_t ADXL345::getDoubleTapWindow() {
    return i2c.readByteNoExit(ADXL345_RA_WINDOW);
}

void ADXL345::setDoubleTapWindow(uint8_t window) {
    i2c.writeByteNoExit(ADXL345_RA_WINDOW, window);
}

uint8_t ADXL345::getActivityThreshold() {
    return i2c.readByteNoExit(ADXL345_RA_THRESH_ACT);
}

void ADXL345::setActivityThreshold(uint8_t threshold) {
    i2c.writeByteNoExit(ADXL345_RA_THRESH_ACT, threshold);
}

uint8_t ADXL345::getInactivityThreshold() {
    return i2c.readByteNoExit(ADXL345_RA_THRESH_INACT);
}

void ADXL345::setInactivityThreshold(uint8_t threshold) {
    i2c.writeByteNoExit(ADXL345_RA_THRESH_INACT, threshold);
}

uint8_t ADXL345::getInactivityTime() {
    return i2c.readByteNoExit(ADXL345_RA_TIME_INACT);
}

void ADXL345::setInactivityTime(uint8_t time) {
    i2c.writeByteNoExit(ADXL345_RA_TIME_INACT, time);
}

bool ADXL345::getActivityAC() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_ACT_AC_BIT);
}

void ADXL345::setActivityAC(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_ACT_AC_BIT);
}

bool ADXL345::getActivityXEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_ACT_X_BIT);
}

void ADXL345::setActivityXEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_ACT_X_BIT);
}

bool ADXL345::getActivityYEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_ACT_Y_BIT);
}

void ADXL345::setActivityYEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_ACT_Y_BIT);

}

bool ADXL345::getActivityZEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_ACT_Z_BIT);
}

void ADXL345::setActivityZEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_ACT_Z_BIT);
}

bool ADXL345::getInactivityAC() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_INACT_AC_BIT);
}

/** Set inctivity AC/DC coupling.
 * @param enabled Inactivity AC/DC coupling (TRUE for AC, FALSE for DC)
 * @see getActivityAC()
 * @see ADXL345_RA_ACT_INACT_CTL
 * @see ADXL345_AIC_INACT_AC_BIT
 */
void ADXL345::setInactivityAC(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_INACT_AC_BIT);
}

/** Get X axis inactivity monitoring.
 * @return Y axis inactivity monitoring enabled value
 * @see getActivityAC()
 * @see getActivityXEnabled()
 * @see ADXL345_RA_ACT_INACT_CTL
 * @see ADXL345_AIC_INACT_X_BIT
 */
bool ADXL345::getInactivityXEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_INACT_X_BIT);
}

/** Set X axis activity monitoring inclusion.
 * @param enabled X axis inactivity monitoring inclusion value
 * @see getActivityAC()
 * @see getActivityXEnabled()
 * @see ADXL345_RA_ACT_INACT_CTL
 * @see ADXL345_AIC_INACT_X_BIT
 */
void ADXL345::setInactivityXEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_INACT_X_BIT);
}

/** Get Y axis inactivity monitoring.
 * @return Y axis inactivity monitoring enabled value
 * @see getActivityAC()
 * @see getActivityXEnabled()
 * @see ADXL345_RA_ACT_INACT_CTL
 * @see ADXL345_AIC_INACT_Y_BIT
 */
bool ADXL345::getInactivityYEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_INACT_Y_BIT);
}

/** Set Y axis inactivity monitoring inclusion.
 * @param enabled Y axis inactivity monitoring inclusion value
 * @see getActivityAC()
 * @see getActivityXEnabled()
 * @see ADXL345_RA_ACT_INACT_CTL
 * @see ADXL345_AIC_INACT_Y_BIT
 */
void ADXL345::setInactivityYEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_INACT_Y_BIT);
}

/** Get Z axis inactivity monitoring.
 * @return Z axis inactivity monitoring enabled value
 * @see getActivityAC()
 * @see getActivityXEnabled()
 * @see ADXL345_RA_ACT_INACT_CTL
 * @see ADXL345_AIC_INACT_Z_BIT
 */
bool ADXL345::getInactivityZEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_INACT_CTL, ADXL345_AIC_INACT_Z_BIT);
}

/** Set Z axis inactivity monitoring inclusion.
 * @param enabled Z axis activity monitoring inclusion value
 * @see getActivityAC()
 * @see getActivityXEnabled()
 * @see ADXL345_RA_ACT_INACT_CTL
 * @see ADXL345_AIC_INACT_Z_BIT
 */
void ADXL345::setInactivityZEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_ACT_INACT_CTL, enabled, ADXL345_AIC_INACT_Z_BIT);
}

// THRESH_FF register

/** Get freefall threshold value.
 * The THRESH_FF register is eight bits and holds the threshold value, in
 * unsigned format, for free-fall detection. The acceleration on all axes is
 * compared with the value in THRESH_FF to determine if a free-fall event
 * occurred. The scale factor is 62.5 mg/LSB. Note that a value of 0 mg may
 * result in undesirable behavior if the free-fall interrupt is enabled. Values
 * between 300 mg and 600 mg (0x05 to 0x09) are recommended.
 * @return Freefall threshold value (scaled at 62.5 mg/LSB)
 * @see ADXL345_RA_THRESH_FF
 */
uint8_t ADXL345::getFreefallThreshold() {
    return i2c.readByteNoExit(ADXL345_AIC_INACT_Z_BIT);
}

/** Set freefall threshold value.
 * @param threshold Freefall threshold value (scaled at 62.5 mg/LSB)
 * @see getFreefallThreshold()
 * @see ADXL345_RA_THRESH_FF
 */
void ADXL345::setFreefallThreshold(uint8_t threshold) {
    i2c.writeByteNoExit(ADXL345_RA_THRESH_FF, threshold);
}

// TIME_FF register

/** Get freefall time value.
 * The TIME_FF register is eight bits and stores an unsigned time value
 * representing the minimum time that the value of all axes must be less than
 * THRESH_FF to generate a free-fall interrupt. The scale factor is 5 ms/LSB. A
 * value of 0 may result in undesirable behavior if the free-fall interrupt is
 * enabled. Values between 100 ms and 350 ms (0x14 to 0x46) are recommended.
 * @return Freefall time value (scaled at 5 ms/LSB)
 * @see getFreefallThreshold()
 * @see ADXL345_RA_TIME_FF
 */
uint8_t ADXL345::getFreefallTime() {
    return i2c.readByteNoExit(ADXL345_RA_TIME_FF);
}

/** Set freefall time value.
 * @param threshold Freefall time value (scaled at 5 ms/LSB)
 * @see getFreefallTime()
 * @see ADXL345_RA_TIME_FF
 */
void ADXL345::setFreefallTime(uint8_t time) {
    i2c.writeByteNoExit(ADXL345_RA_TIME_FF, time);
}

// TAP_AXES register

/** Get double-tap fast-movement suppression.
 * Setting the suppress bit suppresses double tap detection if acceleration
 * greater than the value in THRESH_TAP is present between taps. See the Tap
 * Detection section in the datasheet for more details.
 * @return Double-tap fast-movement suppression value
 * @see getTapThreshold()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_SUP_BIT
 */
bool ADXL345::getTapAxisSuppress() {
    return i2c.readBitNoExit(ADXL345_RA_TAP_AXES, ADXL345_TAPAXIS_SUP_BIT);
}

/** Set double-tap fast-movement suppression.
 * @param enabled Double-tap fast-movement suppression value
 * @see getTapAxisSuppress()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_SUP_BIT
 */
void ADXL345::setTapAxisSuppress(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_TAP_AXES, enabled, ADXL345_TAPAXIS_SUP_BIT);
}

/** Get double-tap fast-movement suppression.
 * A setting of 1 in the TAP_X enable bit enables x-axis participation in tap
 * detection. A setting of 0 excludes the selected axis from participation in
 * tap detection.
 * @return Double-tap fast-movement suppression value
 * @see getTapThreshold()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_X_BIT
 */
bool ADXL345::getTapAxisXEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_TAP_AXES, ADXL345_TAPAXIS_X_BIT);
}

/** Set tap detection X axis inclusion.
 * @param enabled X axis tap detection enabled value
 * @see getTapAxisXEnabled()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_X_BIT
 */
void ADXL345::setTapAxisXEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_TAP_AXES, enabled, ADXL345_TAPAXIS_X_BIT);
}

/** Get tap detection Y axis inclusion.
 * A setting of 1 in the TAP_Y enable bit enables y-axis participation in tap
 * detection. A setting of 0 excludes the selected axis from participation in
 * tap detection.
 * @return Double-tap fast-movement suppression value
 * @see getTapThreshold()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_Y_BIT
 */
bool ADXL345::getTapAxisYEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_TAP_AXES, ADXL345_TAPAXIS_Y_BIT);
}

/** Set tap detection Y axis inclusion.
 * @param enabled Y axis tap detection enabled value
 * @see getTapAxisYEnabled()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_Y_BIT
 */
void ADXL345::setTapAxisYEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_TAP_AXES, enabled, ADXL345_TAPAXIS_Y_BIT);
}

/** Get tap detection Z axis inclusion.
 * A setting of 1 in the TAP_Z enable bit enables z-axis participation in tap
 * detection. A setting of 0 excludes the selected axis from participation in
 * tap detection.
 * @return Double-tap fast-movement suppression value
 * @see getTapThreshold()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_Z_BIT
 */
bool ADXL345::getTapAxisZEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_TAP_AXES, ADXL345_TAPAXIS_Z_BIT);
}

/** Set tap detection Z axis inclusion.
 * @param enabled Z axis tap detection enabled value
 * @see getTapAxisZEnabled()
 * @see ADXL345_RA_TAP_AXES
 * @see ADXL345_TAPAXIS_Z_BIT
 */
void ADXL345::setTapAxisZEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_TAP_AXES, enabled, ADXL345_TAPAXIS_Z_BIT);
}

// ACT_TAP_STATUS register

/** Get X axis activity source flag.
 * These bits indicate the first axis involved in a tap or activity event. A
 * setting of 1 corresponds to involvement in the event, and a setting of 0
 * corresponds to no involvement. When new data is available, these bits are not
 * cleared but are overwritten by the new data. The ACT_TAP_STATUS register
 * should be read before clearing the interrupt. Disabling an axis from
 * participation clears the corresponding source bit when the next activity or
 * single tap/double tap event occurs.
 * @return X axis activity source flag
 * @see ADXL345_RA_ACT_TAP_STATUS
 * @see ADXL345_TAPSTAT_ACTX_BIT
 */
bool ADXL345::getActivitySourceX() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_TAP_STATUS, ADXL345_TAPSTAT_ACTX_BIT);
}

/** Get Y axis activity source flag.
 * @return Y axis activity source flag
 * @see getActivitySourceX()
 * @see ADXL345_RA_ACT_TAP_STATUS
 * @see ADXL345_TAPSTAT_ACTY_BIT
 */
bool ADXL345::getActivitySourceY() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_TAP_STATUS, ADXL345_TAPSTAT_ACTY_BIT);
}

/** Get Z axis activity source flag.
 * @return Z axis activity source flag
 * @see getActivitySourceX()
 * @see ADXL345_RA_ACT_TAP_STATUS
 * @see ADXL345_TAPSTAT_ACTZ_BIT
 */
bool ADXL345::getActivitySourceZ() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_TAP_STATUS, ADXL345_TAPSTAT_ACTZ_BIT);
}

/** Get sleep mode flag.
 * A setting of 1 in the asleep bit indicates that the part is asleep, and a
 * setting of 0 indicates that the part is not asleep. This bit toggles only if
 * the device is configured for auto sleep. See the AUTO_SLEEP Bit section of
 * the datasheet for more information on autosleep mode.
 * @return Sleep mode enabled flag
 * @see ADXL345_RA_ACT_TAP_STATUS
 * @see ADXL345_TAPSTAT_ASLEEP_BIT
 */
bool ADXL345::getAsleep() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_TAP_STATUS, ADXL345_TAPSTAT_ASLEEP_BIT);
}

/** Get X axis tap source flag.
 * @return X axis tap source flag
 * @see getActivitySourceX()
 * @see ADXL345_RA_ACT_TAP_STATUS
 * @see ADXL345_TAPSTAT_TAPX_BIT
 */
bool ADXL345::getTapSourceX() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_TAP_STATUS, ADXL345_TAPSTAT_TAPX_BIT);
}

/** Get Y axis tap source flag.
 * @return Y axis tap source flag
 * @see getActivitySourceX()
 * @see ADXL345_RA_ACT_TAP_STATUS
 * @see ADXL345_TAPSTAT_TAPY_BIT
 */
bool ADXL345::getTapSourceY() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_TAP_STATUS, ADXL345_TAPSTAT_TAPY_BIT);
}

/** Get Z axis tap source flag.
 * @return Z axis tap source flag
 * @see getActivitySourceX()
 * @see ADXL345_RA_ACT_TAP_STATUS
 * @see ADXL345_TAPSTAT_TAPZ_BIT
 */
bool ADXL345::getTapSourceZ() {
    return i2c.readBitNoExit(ADXL345_RA_ACT_TAP_STATUS, ADXL345_TAPSTAT_TAPZ_BIT);
}

// BW_RATE register

/** Get low power enabled status.
 * A setting of 0 in the LOW_POWER bit selects normal operation, and a setting
 * of 1 selects reduced power operation, which has somewhat higher noise (see
 * the Power Modes section of the datasheet for details).
 * @return Low power enabled status
 * @see ADXL345_RA_BW_RATE
 * @see ADXL345_BW_LOWPOWER_BIT
 */
bool ADXL345::getLowPowerEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_BW_RATE, ADXL345_BW_LOWPOWER_BIT);
}

/** Set low power enabled status.
 * @see getLowPowerEnabled()
 * @param enabled Low power enable setting
 * @see ADXL345_RA_BW_RATE
 * @see ADXL345_BW_LOWPOWER_BIT
 */
void ADXL345::setLowPowerEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_BW_RATE, enabled, ADXL345_BW_LOWPOWER_BIT);
}

/** Get measurement data rate.
 * These bits select the device bandwidth and output data rate (see Table 7 and
 * Table 8 in the datasheet for details). The default value is 0x0A, which
 * translates to a 100 Hz output data rate. An output data rate should be
 * selected that is appropriate for the communication protocol and frequency
 * selected. Selecting too high of an output data rate with a low communication
 * speed results in samples being discarded.
 * @return Data rate (0x0 - 0xF)
 * @see ADXL345_RA_BW_RATE
 * @see ADXL345_BW_RATE_BIT
 * @see ADXL345_BW_RATE_LENGTH
 */
uint8_t ADXL345::getRate() {
    return i2c.readMoreBitsNoExit(ADXL345_RA_BW_RATE, ADXL345_BW_RATE_LENGTH, ADXL345_BW_LOWPOWER_BIT);
}

/** Set measurement data rate.
 * 0x7 =  12.5Hz
 * 0x8 =  25Hz, increasing or decreasing by factors of 2, so:
 * 0x9 =  50Hz
 * 0xA = 100Hz
 * @param rate New data rate (0x0 - 0xF)
 * @see ADXL345_RATE_100
 * @see ADXL345_RA_BW_RATE
 * @see ADXL345_BW_RATE_BIT
 * @see ADXL345_BW_RATE_LENGTH
 */
void ADXL345::setRate(uint8_t rate) {
    i2c.writeMoreBitsNoExit(ADXL345_RA_BW_RATE, rate, ADXL345_BW_RATE_LENGTH, ADXL345_BW_LOWPOWER_BIT);
}

// POWER_CTL register

/** Get activity/inactivity serial linkage status.
 * A setting of 1 in the link bit with both the activity and inactivity
 * functions enabled delays the start of the activity function until
 * inactivity is detected. After activity is detected, inactivity detection
 * begins, preventing the detection of activity. This bit serially links the
 * activity and inactivity functions. When this bit is set to 0, the inactivity
 * and activity functions are concurrent. Additional information can be found
 * in the Link Mode section of the datasheet.
 *
 * When clearing the link bit, it is recommended that the part be placed into
 * standby mode and then set back to measurement mode with a subsequent write.
 * This is done to ensure that the device is properly biased if sleep mode is
 * manually disabled; otherwise, the first few samples of data after the link
 * bit is cleared may have additional noise, especially if the device was asleep
 * when the bit was cleared.
 *
 * @return Link status
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_LINK_BIT
 */
bool ADXL345::getLinkEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_POWER_CTL, ADXL345_PCTL_LINK_BIT);
}

/** Set activity/inactivity serial linkage status.
 * @param enabled New link status
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_LINK_BIT
 */
void ADXL345::setLinkEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_POWER_CTL, enabled, ADXL345_PCTL_LINK_BIT);

}

/** Get auto-sleep enabled status.
 * If the link bit is set, a setting of 1 in the AUTO_SLEEP bit enables the
 * auto-sleep functionality. In this mode, the ADXL345 auto-matically switches
 * to sleep mode if the inactivity function is enabled and inactivity is
 * detected (that is, when acceleration is below the THRESH_INACT value for at
 * least the time indicated by TIME_INACT). If activity is also enabled, the
 * ADXL345 automatically wakes up from sleep after detecting activity and
 * returns to operation at the output data rate set in the BW_RATE register. A
 * setting of 0 in the AUTO_SLEEP bit disables automatic switching to sleep
 * mode. See the description of the Sleep Bit in this section of the datasheet
 * for more information on sleep mode.
 *
 * If the link bit is not set, the AUTO_SLEEP feature is disabled and setting
 * the AUTO_SLEEP bit does not have an impact on device operation. Refer to the
 * Link Bit section or the Link Mode section for more information on utilization
 * of the link feature.
 *
 * When clearing the AUTO_SLEEP bit, it is recommended that the part be placed
 * into standby mode and then set back to measure-ment mode with a subsequent
 * write. This is done to ensure that the device is properly biased if sleep
 * mode is manually disabled; otherwise, the first few samples of data after the
 * AUTO_SLEEP bit is cleared may have additional noise, especially if the device
 * was asleep when the bit was cleared.
 *
 * @return Auto-sleep enabled status
 * @see getActivityThreshold()
 * @see getInactivityThreshold()
 * @see getInactivityTime()
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_AUTOSLEEP_BIT
 */
bool ADXL345::getAutoSleepEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_POWER_CTL, ADXL345_PCTL_AUTOSLEEP_BIT);
}

/** Set auto-sleep enabled status.
 * @param enabled New auto-sleep status
 * @see getAutoSleepEnabled()
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_AUTOSLEEP_BIT
 */
void ADXL345::setAutoSleepEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_POWER_CTL, enabled, ADXL345_PCTL_AUTOSLEEP_BIT);
}

/** Get measurement enabled status.
 * A setting of 0 in the measure bit places the part into standby mode, and a
 * setting of 1 places the part into measurement mode. The ADXL345 powers up in
 * standby mode with minimum power consumption.
 * @return Measurement enabled status
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_MEASURE_BIT
 */
bool ADXL345::getMeasureEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_POWER_CTL, ADXL345_PCTL_MEASURE_BIT);
}

/** Set measurement enabled status.
 * @param enabled Measurement enabled status
 * @see getMeasureEnabled()
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_MEASURE_BIT
 */
void ADXL345::setMeasureEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_POWER_CTL, enabled, ADXL345_PCTL_MEASURE_BIT);
}

/** Get sleep mode enabled status.
 * A setting of 0 in the sleep bit puts the part into the normal mode of
 * operation, and a setting of 1 places the part into sleep mode. Sleep mode
 * suppresses DATA_READY, stops transmission of data to FIFO, and switches the
 * sampling rate to one specified by the wakeup bits. In sleep mode, only the
 * activity function can be used. When the DATA_READY interrupt is suppressed,
 * the output data registers (Register 0x32 to Register 0x37) are still updated
 * at the sampling rate set by the wakeup bits (D1:D0).
 *
 * When clearing the sleep bit, it is recommended that the part be placed into
 * standby mode and then set back to measurement mode with a subsequent write.
 * This is done to ensure that the device is properly biased if sleep mode is
 * manually disabled; otherwise, the first few samples of data after the sleep
 * bit is cleared may have additional noise, especially if the device was asleep
 * when the bit was cleared.
 *
 * @return Sleep enabled status
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_SLEEP_BIT
 */
bool ADXL345::getSleepEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_POWER_CTL, ADXL345_PCTL_SLEEP_BIT);
}

/** Set sleep mode enabled status.
 * @param Sleep mode enabled status
 * @see getSleepEnabled()
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_SLEEP_BIT
 */
void ADXL345::setSleepEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_POWER_CTL, enabled, ADXL345_PCTL_SLEEP_BIT);

}

/** Get wakeup frequency.
 * These bits control the frequency of readings in sleep mode as described in
 * Table 20 in the datasheet. (That is, 0 = 8Hz, 1 = 4Hz, 2 = 2Hz, 3 = 1Hz)
 * @return Wakeup frequency (0x0 - 0x3, indicating 8/4/2/1Hz respectively)
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_SLEEP_BIT
 */
uint8_t ADXL345::getWakeupFrequency() {
    return i2c.readMoreBitsNoExit(ADXL345_RA_POWER_CTL, ADXL345_PCTL_WAKEUP_LENGTH, ADXL345_PCTL_WAKEUP_BIT);
}

/** Set wakeup frequency.
 * @param frequency Wakeup frequency (0x0 - 0x3, indicating 8/4/2/1Hz respectively)
 * @see getWakeupFrequency()
 * @see ADXL345_RA_POWER_CTL
 * @see ADXL345_PCTL_SLEEP_BIT
 */
void ADXL345::setWakeupFrequency(uint8_t frequency) {
    i2c.writeMoreBitsNoExit(ADXL345_RA_POWER_CTL, frequency, ADXL345_PCTL_WAKEUP_LENGTH, ADXL345_PCTL_WAKEUP_BIT);
}

// INT_ENABLE register

/** Get DATA_READY interrupt enabled status.
 * Setting bits in this register to a value of 1 enables their respective
 * functions to generate interrupts, whereas a value of 0 prevents the functions
 * from generating interrupts. The DATA_READY, watermark, and overrun bits
 * enable only the interrupt output; the functions are always enabled. It is
 * recommended that interrupts be configured before enabling their outputs.
 * @return DATA_READY interrupt enabled status.
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_DATA_READY_BIT
 */
bool ADXL345::getIntDataReadyEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_DATA_READY_BIT);
}

/** Set DATA_READY interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_DATA_READY_BIT
 */
void ADXL345::setIntDataReadyEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_DATA_READY_BIT);
}

/** Set SINGLE_TAP interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_SINGLE_TAP_BIT
 */
bool ADXL345::getIntSingleTapEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_SINGLE_TAP_BIT);
}

/** Set SINGLE_TAP interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_SINGLE_TAP_BIT
 */
void ADXL345::setIntSingleTapEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_SINGLE_TAP_BIT);
}

/** Get DOUBLE_TAP interrupt enabled status.
 * @return Interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_DOUBLE_TAP_BIT
 */
bool ADXL345::getIntDoubleTapEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_DOUBLE_TAP_BIT);
}

/** Set DOUBLE_TAP interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_DOUBLE_TAP_BIT
 */
void ADXL345::setIntDoubleTapEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_DOUBLE_TAP_BIT);
}

/** Set ACTIVITY interrupt enabled status.
 * @return Interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_ACTIVITY_BIT
 */
bool ADXL345::getIntActivityEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_ACTIVITY_BIT);
}

/** Set ACTIVITY interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_ACTIVITY_BIT
 */
void ADXL345::setIntActivityEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_ACTIVITY_BIT);
}

/** Get INACTIVITY interrupt enabled status.
 * @return Interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_INACTIVITY_BIT
 */
bool ADXL345::getIntInactivityEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_INACTIVITY_BIT);
}

/** Set INACTIVITY interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_INACTIVITY_BIT
 */
void ADXL345::setIntInactivityEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_INACTIVITY_BIT);
}

/** Get FREE_FALL interrupt enabled status.
 * @return Interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_FREE_FALL_BIT
 */
bool ADXL345::getIntFreefallEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_FREE_FALL_BIT);
}

/** Set FREE_FALL interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_FREE_FALL_BIT
 */
void ADXL345::setIntFreefallEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_FREE_FALL_BIT);
}

/** Get WATERMARK interrupt enabled status.
 * @return Interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_WATERMARK_BIT
 */
bool ADXL345::getIntWatermarkEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_WATERMARK_BIT);
}

/** Set WATERMARK interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_WATERMARK_BIT
 */
void ADXL345::setIntWatermarkEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_WATERMARK_BIT);
}

/** Get OVERRUN interrupt enabled status.
 * @return Interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_OVERRUN_BIT
 */
bool ADXL345::getIntOverrunEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_INT_ENABLE, ADXL345_INT_OVERRUN_BIT);
}

/** Set OVERRUN interrupt enabled status.
 * @param enabled New interrupt enabled status
 * @see getIntDataReadyEnabled()
 * @see ADXL345_RA_INT_ENABLE
 * @see ADXL345_INT_OVERRUN_BIT
 */
void ADXL345::setIntOverrunEnabled(bool enabled) {
    i2c.writeBitNoExit(ADXL345_RA_INT_ENABLE, enabled, ADXL345_INT_OVERRUN_BIT);
}

// INT_MAP register

/** Get DATA_READY interrupt pin.
 * Any bits set to 0 in this register send their respective interrupts to the
 * INT1 pin, whereas bits set to 1 send their respective interrupts to the INT2
 * pin. All selected interrupts for a given pin are OR'ed.
 * @return Interrupt pin setting
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_DATA_READY_BIT
 */
uint8_t ADXL345::getIntDataReadyPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_DATA_READY_BIT);
}

/** Set DATA_READY interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_DATA_READY_BIT
 */
void ADXL345::setIntDataReadyPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_DATA_READY_BIT);
}

/** Get SINGLE_TAP interrupt pin.
 * @return Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_SINGLE_TAP_BIT
 */
uint8_t ADXL345::getIntSingleTapPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_SINGLE_TAP_BIT);
}

/** Set SINGLE_TAP interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_SINGLE_TAP_BIT
 */
void ADXL345::setIntSingleTapPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_SINGLE_TAP_BIT);
}

/** Get DOUBLE_TAP interrupt pin.
 * @return Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_DOUBLE_TAP_BIT
 */
uint8_t ADXL345::getIntDoubleTapPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_DOUBLE_TAP_BIT);
}

/** Set DOUBLE_TAP interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_DOUBLE_TAP_BIT
 */
void ADXL345::setIntDoubleTapPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_DOUBLE_TAP_BIT);
}

/** Get ACTIVITY interrupt pin.
 * @return Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_ACTIVITY_BIT
 */
uint8_t ADXL345::getIntActivityPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_ACTIVITY_BIT);
}

/** Set ACTIVITY interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_ACTIVITY_BIT
 */
void ADXL345::setIntActivityPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_ACTIVITY_BIT);
}

/** Get INACTIVITY interrupt pin.
 * @return Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_INACTIVITY_BIT
 */
uint8_t ADXL345::getIntInactivityPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_INACTIVITY_BIT);
}

/** Set INACTIVITY interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_INACTIVITY_BIT
 */
void ADXL345::setIntInactivityPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_INACTIVITY_BIT);

}

/** Get FREE_FALL interrupt pin.
 * @return Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_FREE_FALL_BIT
 */
uint8_t ADXL345::getIntFreefallPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_FREE_FALL_BIT);
}

/** Set FREE_FALL interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_FREE_FALL_BIT
 */
void ADXL345::setIntFreefallPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_FREE_FALL_BIT);
}

/** Get WATERMARK interrupt pin.
 * @return Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_WATERMARK_BIT
 */
uint8_t ADXL345::getIntWatermarkPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_WATERMARK_BIT);
}

/** Set WATERMARK interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_WATERMARK_BIT
 */
void ADXL345::setIntWatermarkPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_WATERMARK_BIT);
}

/** Get OVERRUN interrupt pin.
 * @return Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_OVERRUN_BIT
 */
uint8_t ADXL345::getIntOverrunPin() {
    return i2c.readBitNoExit(ADXL345_RA_INT_MAP, ADXL345_INT_OVERRUN_BIT);
}

/** Set OVERRUN interrupt pin.
 * @param pin Interrupt pin setting
 * @see getIntDataReadyPin()
 * @see ADXL345_RA_INT_MAP
 * @see ADXL345_INT_OVERRUN_BIT
 */
void ADXL345::setIntOverrunPin(uint8_t pin) {
    i2c.writeBitNoExit(ADXL345_RA_INT_MAP, pin, ADXL345_INT_OVERRUN_BIT);
}

// INT_SOURCE register

/** Get DATA_READY interrupt source flag.
 * Bits set to 1 in this register indicate that their respective functions have
 * triggered an event, whereas a value of 0 indicates that the corresponding
 * event has not occurred. The DATA_READY, watermark, and overrun bits are
 * always set if the corresponding events occur, regardless of the INT_ENABLE
 * register settings, and are cleared by reading data from the DATAX, DATAY, and
 * DATAZ registers. The DATA_READY and watermark bits may require multiple
 * reads, as indicated in the FIFO mode descriptions in the FIFO section. Other
 * bits, and the corresponding interrupts, are cleared by reading the INT_SOURCE
 * register.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_DATA_READY_BIT
 */
uint8_t ADXL345::getIntDataReadySource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_DATA_READY_BIT);
}

/** Get SINGLE_TAP interrupt source flag.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_SINGLE_TAP_BIT
 */
uint8_t ADXL345::getIntSingleTapSource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_SINGLE_TAP_BIT);
}

/** Get DOUBLE_TAP interrupt source flag.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_DOUBLE_TAP_BIT
 */
uint8_t ADXL345::getIntDoubleTapSource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_DOUBLE_TAP_BIT);
}

/** Get ACTIVITY interrupt source flag.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_ACTIVITY_BIT
 */
uint8_t ADXL345::getIntActivitySource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_ACTIVITY_BIT);
}

/** Get INACTIVITY interrupt source flag.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_INACTIVITY_BIT
 */
uint8_t ADXL345::getIntInactivitySource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_INACTIVITY_BIT);
}

/** Get FREE_FALL interrupt source flag.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_FREE_FALL_BIT
 */
uint8_t ADXL345::getIntFreefallSource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_FREE_FALL_BIT);
}

/** Get WATERMARK interrupt source flag.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_WATERMARK_BIT
 */
uint8_t ADXL345::getIntWatermarkSource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_WATERMARK_BIT);
}

/** Get OVERRUN interrupt source flag.
 * @return Interrupt source flag
 * @see ADXL345_RA_INT_SOURCE
 * @see ADXL345_INT_OVERRUN_BIT
 */
uint8_t ADXL345::getIntOverrunSource() {
    return i2c.readBitNoExit(ADXL345_RA_INT_SOURCE, ADXL345_INT_OVERRUN_BIT);
}

// DATA_FORMAT register

/** Get self-test force enabled.
 * A setting of 1 in the SELF_TEST bit applies a self-test force to the sensor,
 * causing a shift in the output data. A value of 0 disables the self-test
 * force.
 * @return Self-test force enabled setting
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_SELFTEST_BIT
 */
uint8_t ADXL345::getSelfTestEnabled() {
    return i2c.readBitNoExit(ADXL345_RA_DATA_FORMAT, ADXL345_FORMAT_SELFTEST_BIT);
}

/** Set self-test force enabled.
 * @param enabled New self-test force enabled setting
 * @see getSelfTestEnabled()
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_SELFTEST_BIT
 */
void ADXL345::setSelfTestEnabled(uint8_t enabled) {
    i2c.writeBitNoExit(ADXL345_RA_DATA_FORMAT, enabled, ADXL345_FORMAT_SELFTEST_BIT);
}

/** Get SPI mode setting.
 * A value of 1 in the SPI bit sets the device to 3-wire SPI mode, and a value
 * of 0 sets the device to 4-wire SPI mode.
 * @return SPI mode setting
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_SELFTEST_BIT
 */
uint8_t ADXL345::getSPIMode() {
    return i2c.readBitNoExit(ADXL345_RA_DATA_FORMAT, ADXL345_FORMAT_SPIMODE_BIT);
}

/** Set SPI mode setting.
 * @param mode New SPI mode setting
 * @see getSPIMode()
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_SELFTEST_BIT
 */
void ADXL345::setSPIMode(uint8_t mode) {
    i2c.writeBitNoExit(ADXL345_RA_DATA_FORMAT, mode, ADXL345_FORMAT_SPIMODE_BIT);
}

/** Get interrupt mode setting.
 * A value of 0 in the INT_INVERT bit sets the interrupts to active high, and a
 * value of 1 sets the interrupts to active low.
 * @return Interrupt mode setting
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_INTMODE_BIT
 */
uint8_t ADXL345::getInterruptMode() {
    return i2c.readBitNoExit(ADXL345_RA_DATA_FORMAT, ADXL345_FORMAT_INTMODE_BIT);
}

/** Set interrupt mode setting.
 * @param mode New interrupt mode setting
 * @see getInterruptMode()
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_INTMODE_BIT
 */
void ADXL345::setInterruptMode(uint8_t mode) {
    i2c.writeBitNoExit(ADXL345_RA_DATA_FORMAT, mode, ADXL345_FORMAT_INTMODE_BIT);
}

/** Get full resolution mode setting.
 * When this bit is set to a value of 1, the device is in full resolution mode,
 * where the output resolution increases with the g range set by the range bits
 * to maintain a 4 mg/LSB scale factor. When the FULL_RES bit is set to 0, the
 * device is in 10-bit mode, and the range bits determine the maximum g range
 * and scale factor.
 * @return Full resolution enabled setting
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_FULL_RES_BIT
 */
uint8_t ADXL345::getFullResolution() {
    return i2c.readBitNoExit(ADXL345_RA_DATA_FORMAT, ADXL345_FORMAT_FULL_RES_BIT);
}

/** Set full resolution mode setting.
 * @param resolution New full resolution enabled setting
 * @see getFullResolution()
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_FULL_RES_BIT
 */
void ADXL345::setFullResolution(uint8_t resolution) {
    i2c.writeBitNoExit(ADXL345_RA_DATA_FORMAT, resolution, ADXL345_FORMAT_FULL_RES_BIT);
}

/** Get data justification mode setting.
 * A setting of 1 in the justify bit selects left-justified (MSB) mode, and a
 * setting of 0 selects right-justified mode with sign extension.
 * @return Data justification mode
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_JUSTIFY_BIT
 */
uint8_t ADXL345::getDataJustification() {
    return i2c.readBitNoExit(ADXL345_RA_DATA_FORMAT, ADXL345_FORMAT_JUSTIFY_BIT);
}

/** Set data justification mode setting.
 * @param justification New data justification mode
 * @see getDataJustification()
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_JUSTIFY_BIT
 */
void ADXL345::setDataJustification(uint8_t justification) {
    i2c.writeBitNoExit(ADXL345_RA_DATA_FORMAT, justification, ADXL345_FORMAT_JUSTIFY_BIT);
}

/** Get data range setting.
 * These bits set the g range as described in Table 21. (That is, 0x0 - 0x3 to
 * indicate 2g/4g/8g/16g respectively)
 * @return Range value (0x0 - 0x3 for 2g/4g/8g/16g)
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_RANGE_BIT
 * @see ADXL345_FORMAT_RANGE_LENGTH
 */
uint8_t ADXL345::getRange() {
    return i2c.readMoreBitsNoExit(ADXL345_RA_DATA_FORMAT, ADXL345_FORMAT_RANGE_LENGTH, ADXL345_FORMAT_RANGE_BIT);
}

/** Set data range setting.
 * @param range Range value (0x0 - 0x3 for 2g/4g/8g/16g)
 * @see getRange()
 * @see ADXL345_RA_DATA_FORMAT
 * @see ADXL345_FORMAT_RANGE_BIT
 * @see ADXL345_FORMAT_RANGE_LENGTH
 */
void ADXL345::setRange(uint8_t range) {
    i2c.writeMoreBitsNoExit(ADXL345_RA_DATA_FORMAT, range, ADXL345_FORMAT_RANGE_LENGTH, ADXL345_FORMAT_RANGE_BIT);
}

// DATA* registers

/** Get 3-axis accleration measurements.
 * These six bytes (Register 0x32 to Register 0x37) are eight bits each and hold
 * the output data for each axis. Register 0x32 and Register 0x33 hold the
 * output data for the x-axis, Register 0x34 and Register 0x35 hold the output
 * data for the y-axis, and Register 0x36 and Register 0x37 hold the output data
 * for the z-axis. The output data is twos complement, with DATAx0 as the least
 * significant byte and DATAx1 as the most significant byte, where x represent
 * X, Y, or Z. The DATA_FORMAT register (Address 0x31) controls the format of
 * the data. It is recommended that a multiple-byte read of all registers be
 * performed to prevent a change in data between reads of sequential registers.
 * 
 * The DATA_FORMAT register controls the presentation of data to Register 0x32
 * through Register 0x37. All data, except that for the +/-16 g range, must be
 * clipped to avoid rollover.
 *
 * @param x 16-bit signed integer container for X-axis acceleration
 * @param y 16-bit signed integer container for Y-axis acceleration
 * @param z 16-bit signed integer container for Z-axis acceleration
 * @see ADXL345_RA_DATAX0
 */
void ADXL345::getAcceleration(int16_t* x, int16_t* y, int16_t* z) {
    *x = i2c.readWordNoExit(ADXL345_RA_DATAX1, ADXL345_RA_DATAX0);
    *y = i2c.readWordNoExit(ADXL345_RA_DATAY1, ADXL345_RA_DATAY0);
    *z = i2c.readWordNoExit(ADXL345_RA_DATAZ1, ADXL345_RA_DATAZ0);
}

/** Get X-axis accleration measurement.
 * @return 16-bit signed X-axis acceleration value
 * @see ADXL345_RA_DATAX0
 */
int16_t ADXL345::getAccelerationX() {
    return i2c.readWordNoExit(ADXL345_RA_DATAX1, ADXL345_RA_DATAX0);
}

/** Get Y-axis accleration measurement.
 * @return 16-bit signed Y-axis acceleration value
 * @see ADXL345_RA_DATAY0
 */
int16_t ADXL345::getAccelerationY() {
    return i2c.readWordNoExit(ADXL345_RA_DATAY1, ADXL345_RA_DATAY0);
}

/** Get Z-axis accleration measurement.
 * @return 16-bit signed Z-axis acceleration value
 * @see ADXL345_RA_DATAZ0
 */
int16_t ADXL345::getAccelerationZ() {
    return i2c.readWordNoExit(ADXL345_RA_DATAZ1, ADXL345_RA_DATAZ0);
}

// FIFO_CTL register

/** Get FIFO mode.
 * These bits set the FIFO mode, as described in Table 22. That is:
 *
 * 0x0 = Bypass (FIFO is bypassed.)
 *
 * 0x1 = FIFO (FIFO collects up to 32 values and then stops collecting data,
 *       collecting new data only when FIFO is not full.)
 *
 * 0x2 = Stream (FIFO holds the last 32 data values. When FIFO is full, the
 *       oldest data is overwritten with newer data.)
 *
 * 0x3 = Trigger (When triggered by the trigger bit, FIFO holds the last data
 *       samples before the trigger event and then continues to collect data 
 *       until full. New data is collected only when FIFO is not full.)
 *
 * @return Curent FIFO mode
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFO_MODE_BIT
 * @see ADXL345_FIFO_MODE_LENGTH
 */
uint8_t ADXL345::getFIFOMode() {
    return i2c.readMoreBitsNoExit(ADXL345_RA_FIFO_CTL, ADXL345_FIFO_MODE_LENGTH, ADXL345_FIFO_MODE_BIT);
}

/** Set FIFO mode.
 * @param mode New FIFO mode
 * @see getFIFOMode()
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFO_MODE_BIT
 * @see ADXL345_FIFO_MODE_LENGTH
 */
void ADXL345::setFIFOMode(uint8_t mode) {
    i2c.writeMoreBitsNoExit(ADXL345_RA_FIFO_CTL, mode, ADXL345_FIFO_MODE_LENGTH, ADXL345_FIFO_MODE_BIT);
}

/** Get FIFO trigger interrupt setting.
 * A value of 0 in the trigger bit links the trigger event of trigger mode to
 * INT1, and a value of 1 links the trigger event to INT2.
 * @return Current FIFO trigger interrupt setting
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFO_TRIGGER_BIT
 */
uint8_t ADXL345::getFIFOTriggerInterruptPin() {
    return i2c.readBitNoExit(ADXL345_RA_FIFO_CTL, ADXL345_FIFO_TRIGGER_BIT);
}

/** Set FIFO trigger interrupt pin setting.
 * @param interrupt New FIFO trigger interrupt pin setting
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFO_TRIGGER_BIT
 */
void ADXL345::setFIFOTriggerInterruptPin(uint8_t interrupt) {
    i2c.writeBitNoExit(ADXL345_RA_FIFO_CTL, interrupt, ADXL345_FIFO_TRIGGER_BIT);
}

/** Get FIFO samples setting.
 * The function of these bits depends on the FIFO mode selected (see Table 23).
 * Entering a value of 0 in the samples bits immediately sets the watermark
 * status bit in the INT_SOURCE register, regardless of which FIFO mode is
 * selected. Undesirable operation may occur if a value of 0 is used for the
 * samples bits when trigger mode is used.
 *
 * MODE    | EFFECT
 * --------+-------------------------------------------------------------------
 * Bypass  | None.
 * FIFO    | FIFO entries needed to trigger a watermark interrupt.
 * Stream  | FIFO entries needed to trigger a watermark interrupt.
 * Trigger | Samples are retained in the FIFO buffer before a trigger event.
 *
 * @return Current FIFO samples setting
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFO_SAMPLES_BIT
 * @see ADXL345_FIFO_SAMPLES_LENGTH
 */
uint8_t ADXL345::getFIFOSamples() {
    return i2c.readMoreBitsNoExit(ADXL345_RA_FIFO_CTL, ADXL345_FIFO_SAMPLES_LENGTH, ADXL345_FIFO_SAMPLES_BIT);
}

/** Set FIFO samples setting.
 * @param size New FIFO samples setting (impact depends on FIFO mode setting)
 * @see getFIFOSamples()
 * @see getFIFOMode()
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFO_SAMPLES_BIT
 * @see ADXL345_FIFO_SAMPLES_LENGTH
 */
void ADXL345::setFIFOSamples(uint8_t size) {
    i2c.writeMoreBitsNoExit(ADXL345_RA_FIFO_CTL, size, ADXL345_FIFO_SAMPLES_LENGTH, ADXL345_FIFO_SAMPLES_BIT);
}

// FIFO_STATUS register

/** Get FIFO trigger occurred status.
 * A 1 in the FIFO_TRIG bit corresponds to a trigger event occurring, and a 0
 * means that a FIFO trigger event has not occurred.
 * @return FIFO trigger occurred status
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFOSTAT_TRIGGER_BIT
 */
bool ADXL345::getFIFOTriggerOccurred() {
    return i2c.readBitNoExit(ADXL345_RA_FIFO_STATUS, ADXL345_FIFOSTAT_TRIGGER_BIT);
}

/** Get FIFO length.
 * These bits report how many data values are stored in FIFO. Access to collect
 * the data from FIFO is provided through the DATAX, DATAY, and DATAZ registers.
 * FIFO reads must be done in burst or multiple-byte mode because each FIFO
 * level is cleared after any read (single- or multiple-byte) of FIFO. FIFO
 * stores a maximum of 32 entries, which equates to a maximum of 33 entries
 * available at any given time because an additional entry is available at the
 * output filter of the I2Cdev::
 * @return Current FIFO length
 * @see ADXL345_RA_FIFO_CTL
 * @see ADXL345_FIFOSTAT_LENGTH_BIT
 * @see ADXL345_FIFOSTAT_LENGTH_LENGTH
 */
uint8_t ADXL345::getFIFOLength() {
    return i2c.readMoreBitsNoExit(ADXL345_RA_FIFO_STATUS, ADXL345_FIFOSTAT_LENGTH_BIT, ADXL345_FIFOSTAT_BIT_START);
}