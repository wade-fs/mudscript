// Room: /open/main/room/s14.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 48 );
  set ("long", @LONG
這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏，北方有座黑色的高
山，但山腰以上被雲霧圍繞著，似乎帶著邪氣.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"d14",
  "west" : __DIR__"s13",
  "south" : __DIR__"p6",
]));
  set("outdoors", "/open/main");

  setup();
  replace_program(ROOM);
}
