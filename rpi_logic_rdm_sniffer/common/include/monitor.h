/**
 * @file monitor.h
 *
 */
/* Copyright (C) 2015 by Arjan van Vught <pm @ http://www.raspberrypi.org/forum/>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include <stdarg.h>
#include <stdint.h>

#define MONITOR_LINE_LABEL		(uint8_t)5
#define MONITOR_LINE_INFO		(uint8_t)6
#define MONITOR_LINE_RDM_DATA	(uint8_t)11
#define MONITOR_LINE_STATUS		(uint8_t)23
#define MONITOR_LINE_STATS		(uint8_t)25

extern void monitor_line(const uint8_t, /*@null@*/ const char *, ...) /*@*/;
extern void monitor_time_uptime(const uint8_t);
extern void monitor_rdm_data(const uint8_t, const uint16_t, const uint8_t *);
extern void monitor_dmx_data(const uint8_t, const uint8_t *);
/*
 *
 */
extern void monitor_update(void);

#endif /* MONITOR_H_ */