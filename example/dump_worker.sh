#!/bin/bash
# set -x

./gen_filter.sh 202.45.128.223 56724 ./worker_filter.txt

tcpdump -B 6000000 -s 0 -F ./worker_filter.txt -i any -w resnet_worker.pcap