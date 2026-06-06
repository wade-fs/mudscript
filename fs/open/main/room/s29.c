// Room: /open/main/room/s29.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 12 );
  set ("long", @LONG
這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"L25",
  "south" : __DIR__"s36",
	"north" : "/open/main/room/[3]",
  "east" : __DIR__"s30",
]));
  set("outdoors", "/open/main");

  setup();
}
