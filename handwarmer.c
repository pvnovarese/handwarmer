/* 
 * Copyright (c) 2014 Scott Vokes <vokes.s@gmail.com>
 *  
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *  
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* Convert electricity to heat.
 *
 * To build:
 *     make handwarmer
 *
 * To use:
 *     ./handwarmer [number of core, default: 8]
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <err.h>

static void heat(void) {
    int i = 0;
    for (;;) { i++; }
}

int main(int argc, char **argv) {
    int processes = 8;
    if (argc > 1) { processes = atoi(argv[1]); }
    if (processes < 1 || processes > 64) {
        fprintf(stderr, "Bad number of processes\n");
        exit(1);
    }

    for (int i=0; i<processes - 1; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            err(1, "fork");
        } else if (pid == 0) {  /* child */
            heat();
        } else {
            /* no-op */
        }
    }

    heat();
    return 0;
}
