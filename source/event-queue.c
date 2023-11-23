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
#include "event-queue.h"
#include <g2labs-platform-queue.h>
#include <string.h>

#ifndef EVENT_QUEUE_MAX_COUNT
#error "EVENT_QUEUE_MAX_COUNT not defined!"
#define EVENT_QUEUE_MAX_COUNT (0)
#endif

static platform_queue_t* event_queue = NULL;

void event_queue_initialize(void) {
    event_queue = platform_queue_create(sizeof(event_t), EVENT_QUEUE_MAX_COUNT);
}

void event_queue_destroy(void) {
    platform_queue_destroy(event_queue);
}

void event_queue_send_fast_event(uint16_t id) {
    event_queue_send_event(id, NULL);
}

void event_queue_send_event(uint16_t id, const void* payload) {
    event_t e = {.id = id, .payload = {0}};
    if (payload) {
        memcpy(e.payload, payload, EVENT_QUEUE_PAYLOAD_MAX_SIZE);
    }
    platform_queue_push(event_queue, &e);
}

bool event_queue_fetch_event(event_t* event) {
    if (!event) {
        return false;
    }
    return platform_queue_fetch(event_queue, event);
}