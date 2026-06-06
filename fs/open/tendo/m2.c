// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
	set ("short", "道路");
  set ("long", @LONG
沿著道路行走，往西望去即是綿亙不絕的崑崙山脈。滄茫的
景色和略帶著幾分寒意的冷風，讓你不自覺的多加了幾件衣服。

LONG);

  set("objects", ([ /* sizeof() == 1 */
//"/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
"west" : "/open/tendo/m3",
"south" : "/open/tendo/m1",
]));

  setup();
}
