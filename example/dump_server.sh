#!/bin/bash
# set -x

./gen_filter.sh 202.45.128.223 56725 ./server_filter.txt

tcpdump -B 6000000 -s 0 -F ./server_filter.txt -i any -w resnet_server.pcap