// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","守衛隊休息室");
  set ("long", @LONG
這裡是守衛隊隊員休息的地方 . 小小的房間裡擺著幾張木製
的桌椅 , 兩三個值勤完畢的守衛正在此泡茶 , 下棋 , 享受著難
得的清閒 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r6-3",
]));
	set("objects",([
	"/open/port/npc/guard2":3,
	]));

  setup();
}
