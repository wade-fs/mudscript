// pkr1.c by konn
// pkr1.c by konn
inherit ROOM;

void create ()
{
  set ("short", "第一武道館");
	set( "build", 49 );
  set ("long", @LONG
四周站滿了五排人牆, 每人各敲著一張牛皮鼓, 咚咚咚咚的敲著, 一陣陣
鼓聲傳入你的耳裡, 有如千軍萬馬般的軍隊蜂湧而至, 這裡是武道館的一
角, 四面牆掛滿了虎皮, 更增添了幾分雄偉的氣勢。人牆外則是一群士兵
在跑場, 一圈又一圈, 一圈再一圈, 你不禁感到豪氣抖生。




LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pkr4",
  "east" : __DIR__"pkr2",
]));
  set("light_up", 1);
  set("no_transmit", 1);
set("no_scale",1);
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
