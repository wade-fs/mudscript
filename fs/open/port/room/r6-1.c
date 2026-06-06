// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","城牆邊");
  set ("long", @LONG
你正走在一條小巷上 . 當初在建造城牆時 , 即在房屋和城
牆之間預留了七步的空間 , 可容車馬往來 . 牆壁是由磚石所砌
成 , 高數十尺 , 從這裡可以看到城牆上有數名守衛正在巡邏著

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r1-2",
	"east" : "/open/port/room/r6-2",
]));
	set("objects",([
	]));

  setup();
}
