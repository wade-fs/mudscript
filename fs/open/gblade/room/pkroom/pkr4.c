// pkr4.c by konn
inherit ROOM;

void create()
{
        set("short", "第一武道館");
	set( "build", 64 );
        set("long", @LONG




LONG);
        set("exits", ([ /* sizeof == 3 */
            "north" : __DIR__"pkr1",
            "east"  : __DIR__"pkr5",
            "south" : __DIR__"pkr7",
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
