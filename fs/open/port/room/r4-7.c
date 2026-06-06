// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","刀客交誼廳");
  set ("long", @LONG
這裡是刀客們平時聊天 , 打屁的地方 . 四周擺了幾張桌椅
 , 你可以在此好好的休息一下 . 由於其他職業的人不能進來 ,
很多資深的刀客會放些裝備在此 , 以照顧後輩 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/port/room/r4-6",
]));
	set("objects",([
	]));

  setup();
}
