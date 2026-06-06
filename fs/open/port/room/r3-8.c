// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","芳林園");
  set ("long", @LONG
這裡是楓林境內最大的花園 - 芳林園 . 假日時居民們最喜
歡到這裡來賞花 , 散步 , 園中百花競放 , 古木參天 , 到處都
是宜人的景色 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r3-9",
	"south" : "/open/port/room/r3-4",
	"north" : "/open/port/room/r3-11",
]));
	set("objects",([
	]));

  setup();
}
