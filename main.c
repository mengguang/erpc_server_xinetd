#include <stdio.h>
#include "erpc.h"
/*
service erpc-server
{
	disable		= no
	type		= UNLISTED
	id		    = erpc-server
	socket_type	= stream
	protocol	= tcp
	user		= root
	wait		= no
	port		= 10002
	server		= /root/bin/erpc_server_xinetd
}
 */

int main() {
    erpc_packet_t request;
    erpc_packet_zero(&request);

    erpc_packet_t response;
    erpc_packet_zero(&response);

    int c = 0;
    bool result;
    while((c = fgetc(stdin)) != EOF) {
        result = erpc_feed_packet(&request, c);
        if(result == true) {
            result = erpc_process_request(&request,&response);
            if(result == true) {
                fwrite(response.data,1,response.length,stdout);
                fflush(stdout);
            }
            erpc_packet_zero(&request);
        }
    }
    return 0;
}