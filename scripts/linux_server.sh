#!/bin/sh
ifn=$1
net=$2
dev=$3
ifconfig ${ifn} ${net}.1 pointopoint ${net}.2 mtu 1400 up
echo 1 > /proc/sys/net/ipv4/ip_forward
iptables -t nat -A POSTROUTING -s ${net}.2/32 -o ${dev} -j MASQUERADE
echo $*
