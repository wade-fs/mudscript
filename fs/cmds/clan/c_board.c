// c_board.c by ACKY
inherit F_CLEAN_UP;
#include <ansi.h>
#include <clanf.h>
string id, short, long, clan;

void input_long( string str, object me )
{
	int i, n;
	string room, file, *strs;

	long = ( str=="" ? me->query("clan/name") + "佈告欄。" : str );

    	file = "/obj/board/" + clan + "_b.c";

	str = @CODE
inherit BULLETIN_BOARD;
void create()
{
CODE;
	str += sprintf( "\tset_name( \"%s\", ({ \"%s\", \"board\" }) );\n", short, id );
	if(long)
		str += sprintf( "\tset( \"long\", \"%s\\n\" );\n", long );
	str += sprintf( "\tset( \"board_id\", \"%s\" );\n", clan );
	str += "\tset( \"capacity\", 100 );\n";
	str += "\tset( \"location\", CLAN_D->clan_query( \"" + clan + "\", \"home\" ) );\n";
	str += "\tset( \"master\", ({ CLAN_D->clan_query( \"" + clan + "\", \"master\" ) }) );\n";
	str += "\tsetup();\n}\n";
	write_file( file, str, 1 );

	room = "/open/clan/" + clan + "/room/hall.c";
	file = read_file(room);
	strs = explode( file, "\n" );
	n = sizeof(strs);
	for( i=0; i<n; i++ )
		if( strsrch( strs[i], "setup();" ) != -1 ) break;
	strs[i] += "\n\tcall_other( \"/obj/board/" + clan + "_b\", \"???\" );";
	file = implode( strs, "\n" ) + "\n";
	write_file( room, file, 1 );
	C_ROOM->update_room( room, me );

	message_vision( HIY"$N花了壹千兩黃金建造佈告欄。\n"NOR, me );
	CLAN_D->add_money( clan, -1000 );
	CLAN_D->add_clanset( clan, "board", -1 );
}

int main( object me )
{
	if( !me->query("clan") || me->query("clan/rank") > 1 )
		return 0;
	clan = CLAN_D->what_clan_area(me);
	if( clan == "NULL" )
		return notify_fail( "此處並非幫派區域。\n" );
	if( !CLAN_D->is_clan_room(me) && !wizardp(me) )
		return notify_fail( "此區域並非本幫所屬地盤。\n" );

	if( !CLAN_D->clan_query( clan, "board" ) ) {
		write( "確定要刪除佈告欄嗎? [N] :" );
		input_to( "ask_yn", 0, me );
		return 1;
	}
	if( CLAN_D->clan_query( clan, "gold" ) < 1000 )
		return notify_fail( "幫派存款不足。\n" );
	write( "請輸入佈告欄的英文名稱(ID), 輸入 Enter 設為預設值: board\n"HIY">"NOR );
	input_to( "input_id" , 0, me );
	return 1;
}

void ask_yn( string str, object me )
{
	string *strs, room, file;
	int i, n;

	if( !strlen(str) || ( str[0] != 'y' && str[0] != 'Y' ) ) {
		write( "OK.\n" );
		return;
	}

	room = "/open/clan/" + clan + "/room/hall.c";
	file = read_file(room);
	strs = explode( file, "\n" );
	n = sizeof(strs);
	for( i=0; i<n; i++ )
		if( strsrch( strs[i], "call_other" ) != -1 ) break;
	file = implode( strs[0..i-1], "\n" ) + "\n" +
		implode( strs[i+1..<0], "\n" ) + "\n";
	rm( "/obj/board/" + clan + "_b.c" );
	rm( "/data/board/" + clan + ".o" );
	CLAN_D->add_clanset( clan, "board", 1 );
	write_file( room, file, 1 );
	C_ROOM->update_room( CLAN_D->clan_query( clan, "home" ), me );
	C_ROOM->update_room( room, me );
	write( "OK.\n" );
}

void input_id( string str, object me )
{
	id = ( str=="" ? "board" : str );
	write( "\n請輸入佈告欄的中文名稱(short), 輸入 Enter 設為預設值: " + me->query("clan/name") + "佈告欄\n"HIY">"NOR );
	input_to( "input_short" , 0, me );
}

void input_short( string str, object me )
{
	short = ( str=="" ? me->query("clan/name") + "佈告欄" : str );
	write( "\n請輸入佈告欄的中文敘述(long), 輸入 Enter 設為預設值: " + me->query("clan/name") + "佈告欄\n"HIY">"NOR );
	input_to( "input_long" , 0, me );
}

int help( object me )
{
	write( @HELP
指令格式: c_board
指令說明: 建造佈告欄。
	  需要壹千兩黃金。

	  c_board
	  刪除佈告欄。
						by ACKY 08/17/2000
HELP);
	return 1;
}
