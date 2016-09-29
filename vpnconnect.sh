#!/bin/bash

#requires openvpn and openconnect

OP=$1

if [ "$(id -u)" != "0" ]
then
	echo "use sudo to execute: sudo $0"
	exit
fi

if [ "$OP" = "C" ]
then
	echo -n "VPN? "
	read SERVER

	openvpn --mktun --dev tun1
	ifconfig tun1 up
	
	openconnect $SERVER \
				--interface=tun1 \
				--background \
				--syslog \
				--pid-file=vpn.pid \
				--quiet
	
	echo -e "CONECCTED\n"
fi

if [ "$OP" = "D" ]
then
	PID=$(cat vpn.pid)
	kill -2 $PID

	sleep 2
	
	ifconfig tun1 down
	openvpn --rmtun --dev tun1
	
	echo -e "DISCONECCTED\n"
fi
