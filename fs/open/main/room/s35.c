// Room: /open/main/room/s35.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 12 );
  set ("long", @LONG
這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
LONG);

set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
//  "/open/main/npc/gao-shion.c" : 1,
// "/open/main/npc/secret_man.c" : 1, 神秘小販關掉
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"s34",
  "north" : __DIR__"L25",
  "east" : __DIR__"s36",
]));

  setup();
  replace_program(ROOM);
}
