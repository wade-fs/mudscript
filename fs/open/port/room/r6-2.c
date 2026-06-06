// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","城牆邊");
  set ("long", @LONG
你正走在城牆邊的小巷上 . 這條小巷連接著守衛隊和城門 .
 緊臨著城牆延伸 , 你可以看到許多值勤中的守衛來來去去 , 這
裡戒備森嚴 , 你最好少在此惹事 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r6-1",
	"east" : "/open/port/room/r6-3",
]));
	set("objects",([
	]));

  setup();
}
