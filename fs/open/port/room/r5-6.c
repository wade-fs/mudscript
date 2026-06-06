// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","漁戶");
	set( "build", 12 );
  set ("long", @LONG
你正處於一間破舊的小屋裡 , 這是一對老漁夫婦的家 . 如
今他們早已不再出海打魚了 , 平日只是坐在門口 , 吹吹海風 ,
看看漁港 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/port/room/r5-4",
]));
	set("objects",([
	"/open/port/npc/oldman":1,
	"/open/port/npc/oldwoman":1,
	]));

  setup();
}
