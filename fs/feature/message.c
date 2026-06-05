// message.c

#include <ansi.h>
#include <dbase.h>
#include <limit.h>
#include <msg.h>

#define MAX_MSG_BUFFER 200

static string *msg_buffer = ({});

void receive_message( string msgclass, string msg )
{
	string subclass, *ch;

	if( !interactive(this_object()) ) {
		this_object()->relay_message( msgclass, msg );
		return;
	}
	if( sscanf( msgclass, "%s:%s", subclass, msgclass ) == 2 ) {
		switch(subclass) {
		case "channel" :
			if( !pointerp( ch = query_temp("channels") ) ||
				member_array( msgclass, ch ) == -1 )
				return;
    break;
    case "vision":
			if( pointerp( ch = query_temp("tuneoff") ) &&
				member_array( msgclass, ch ) != -1 )
        msg = " - 略 -\n";
      break;

    case "outdoor" :
      if( !environment() || !environment()->query("outdoors") )
				return;
			break;
		default:
			error( "Message: Invalid Subclass " + subclass + ".\n" );
		}
	}

	if( query_temp("block_msg/all") || query_temp( "block_msg/" + msgclass ) )
		return;
  if(query("env/encode"))
  {
//    msg = iconv("big5",query("env/encode"),msg);
  }
	if( (in_input(this_object()) || in_edit(this_object())) )
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
			msg_buffer += ({ msg });
		else
			msg_buffer = msg_buffer[0..MAX_MSG_BUFFER/2] + ({ msg });
	else {
		if( query_temp("msg_buffer") && msg[0..1] != "【" && strlen(msg) > query_temp("msg_buffer") )
			msg = MSG + "\n";
		if( strlen(msg) < __LARGEST_PRINTABLE_STRING__ )
			receive(msg);
		else
			while( strlen(msg) > 0 ) {
				receive( msg[0..__LARGEST_PRINTABLE_STRING__-1] );
				msg = msg[__LARGEST_PRINTABLE_STRING__..];
			}
	}
}

void write_prompt()
{
	if( sizeof(msg_buffer) ) {
		receive( BOLD + "[暫存訊息]\n" + NOR );
		this_object()->more( "", msg_buffer, 0 );
		msg_buffer = ({});
	}

	if( query("env/status") )
		printf( "%s精力: %d" + NOR + " %s氣血: %d" + NOR + " %s神瞑: %d" + NOR + " > ",
			STATUS("gin"), query("gin"), STATUS("kee"), query("kee"), STATUS("sen"), query("sen") );
	else if(!query("env/no_status"))
		receive( "> " );
}

void receive_snoop( string msg )
{
	receive( "%" + msg );
}
