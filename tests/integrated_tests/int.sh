#!/bin/sh

echo "------"

echo 'POST / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{["a" : "b"]}\r\n' | ncat  127.0.0.1 8000 > InvalidRequest.txt

if cmp -s InvalidRequest.txt InvalidRequest.gold ; then
 echo "Eqval"
fi
