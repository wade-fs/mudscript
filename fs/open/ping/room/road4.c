// Room: /open/ping/room/road4.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 407 );
  set ("long", @LONG
走到這裡,算是平南城的地理中心了,兩條石板大道交錯而過
,北方可到段王府,段王爺正在招攬書生,如果你是書生的話,也許
可以過去看看,東方則是平南鬧區,你也許可以在那買些物品.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/woman" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road8",
  "north" : __DIR__"road7.c",
  "west" : __DIR__"road5.c",
  "east" : __DIR__"road3",
]));

  setup();
}
