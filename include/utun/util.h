/* UDP Tunnel - util.h
 * 2009 - Felipe Astroza
 * Under GPLv2 license (see LICENSE)
 */

#ifndef UTIL_H
#define UTIL_H

int mstrtoport(char *str, unsigned short *out);
void exec_script(const char *name, const char *arg, const char *arg2, const char *arg3);

#endif

