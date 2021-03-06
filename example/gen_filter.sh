#!/bin/bash
# set -x
if [ $# -lt 3 ]; then
    echo "usage: $0 src_ip dst_port file_name"
    exit -1;
fi

SRC_IP=$1
DST_PORT=$2
echo "Generating filter for src ip: ${SRC_IP}, dst port ${DST_PORT}."

FILTER_FILE_NAME=$3
echo "Writing filter into file: ${FILTER_FILE_NAME}"

echo "(src ${SRC_IP} and tcp dst port ${DST_PORT}) and ((tcp[((tcp[12:1] & 0xf0) >> 2)+4:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+5:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+6:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+7:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+8:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+9:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+10:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+11:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+12:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+13:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+14:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+15:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+16:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+17:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+18:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+19:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+20:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+21:2] = 0x733a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+4:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+5:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+6:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+7:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+8:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+9:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+10:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+11:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+12:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+13:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+14:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+15:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+16:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+17:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+18:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+19:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+20:2] = 0x653a) or (tcp[((tcp[12:1] & 0xf0) >> 2)+21:2] = 0x653a))" > ${FILTER_FILE_NAME}