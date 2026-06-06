// pkr3.c by konn
inherit ROOM;

void create()
{
        set("short","第一武道館");
	set( "build", 49 );
        set("long", @LONG
這裡滿地是血, 看來剛才是有一翻激烈的打鬥了, 不知是誰與誰的性命相
拚, 往西首一看, 一隻匕首丟在那裡, 在你不遠的前方也是幾隻金鏢散了
一地, 東首又是一把斷劍一把鈍刀, 依這情形看來, 應該是一場火拚吧,
你暗忖沒看到這場好戲而感到可惜。




LONG);
        set("exits", ([ /* sizeof == 2 */
            "west"  : __DIR__"pkr2",
            "south" : __DIR__"pkr6",
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
