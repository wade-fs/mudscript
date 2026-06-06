// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","東大街");
  set ("long", @LONG
你正走在東大街上 . 相較於中央大街 , 這裡的行人明顯少
了許多 , 這一帶是楓林港的住宅區 . 楓林近幾年來不但倭寇不
敢來犯 , 治安更是優良 , 百姓們安居樂業 , 繁榮富庶 . 你看
到路上行人們個個臉上充滿著愉快的笑容 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r3-1",
	"east" : "/open/port/room/r3-3",
]));
	set("objects",([
	]));

  setup();
}
