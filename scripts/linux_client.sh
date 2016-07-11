#!/bin/sh
ifn=$1
net=$2
ifconfig ${ifn} ${net}.2 pointopoint ${net}.1 mtu 1400 up
echo $*