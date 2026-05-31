// by ACKY 06/01/00

#include <ansi.h>
#include <msg.h>

#define MAX_BUFFER	5120	// MAX 訊息流量 = 5KB

int help( object me );

int main( object me , string arg )
{
        int msg_buffer;

	if( !arg )
		return help( me );

	if( sscanf( arg, "%d", msg_buffer )!=1 )
		return help( me );

	if( msg_buffer == 0 ) {
		me->delete_temp( "msg_buffer" );
		write( HIC"系統將不取代任何訊息。\n"NOR );
		return 1;
	}

	if( msg_buffer < sizeof(MSG) || msg_buffer>MAX_BUFFER ) {
		write( HIR"[注意]"HIC" <最大訊息流量> 最小值為 "HIY+sizeof(MSG)+HIC" , 最大值為 "HIY+MAX_BUFFER+HIC"。\n"NOR );
		return 1;
	}

	me->set_temp( "msg_buffer", msg_buffer );	
	write( HIC"您將<最大訊息流量>設為 "HIY+msg_buffer+HIC"。\n"NOR );
	return 1;
}
        
int help( object me )
{
	write(@HELP
	msg_filter <最大訊息流量> : 設定接收訊息之最大流量。

		   <最大訊息流量> : 單位 byte

	如果訊息超過所設定的<最大訊息流量>, 將以 "+MSG+" 取代, 以節約流量。
	若<最大訊息流量>設定為 0, 系統將不取代任何訊息。
	每次上線時, 系統將自動設定<最大訊息流量>為 0。

	[範例] msg_filter 100
	[說明] 設定接收訊息之最大流量為 100 bytes。

	                                        by ACKY 06/01/2000
HELP
);
        return 1;

}

