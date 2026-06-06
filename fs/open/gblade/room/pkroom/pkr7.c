// pkr7.c by konn
inherit ROOM;

void create()
{
        set("short", "第一武道館");
	set( "build", 73 );
        set("long", @LONG



LONG);
        set("exits", ([ /* sizeof == 2 */
            "north" : __DIR__"pkr4",
            "east"  : __DIR__"pkr8",
      ]));
set("no_scale",1);
        set("no_transmit", 1);
        set("light_up", 1);
        setup();
//	enable_commands();
}
//玩家反應訊息會有問題，先關閉等找到問題後再開放吧！
/*
void receive_message(string msgclass, string msg)
{

    tell_room("/open/gblade/room/pkroom/lookpkroom",msg);
}
*/
