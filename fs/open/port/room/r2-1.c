// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","中央大街");
  set ("long", @LONG
你正走在寬廣的中央大街上 . 中央大街連接著北門和港口 , 
貫穿了整個楓林港的心臟地帶 . 街道非常的寬廣 , 在路中間放
了朱紅漆的杈子 , 禁止人們通行 , 以提供車馬快速的行進 . 東
邊是本地最出名的清風樓客棧 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r2-4",
	"north" : "/open/port/room/r3-1",
	"south" : "/open/port/room/r2-2",
]));
	set("objects",([
	]));

  setup();
}
