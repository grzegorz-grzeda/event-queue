/*
 * MIT License
 *
 * Copyright (c) 2023 Grzegorz Grzęda
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H
#include <stdbool.h>
#include <stdint.h>

#ifndef EVENT_QUEUE_PAYLOAD_MAX_SIZE
#error "EVENT_QUEUE_MAX_COUNT not defined!"
#define EVENT_QUEUE_PAYLOAD_MAX_SIZE (0)
#endif

typedef struct event {
    uint16_t id;
    char payload[EVENT_QUEUE_PAYLOAD_MAX_SIZE];
} event_t;

void event_queue_initialize(void);

void event_queue_destroy(void);

void event_queue_send_fast_event(uint16_t id);

void event_queue_send_event(uint16_t id, const void* payload);

bool event_queue_fetch_event(event_t* event);

#endif  // EVENT_QUEUE_H