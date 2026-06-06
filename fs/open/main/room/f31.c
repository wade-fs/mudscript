// Room: /open/main/room/f31.c

inherit ROOM;

void create ()
{
  set ("short", "森林");
  set ("long", @LONG
這裡是一片廣大的原始森林，參差的樹木雜亂的長著，陽
光透過枝葉灑下點點金黃，地上則凌亂的部滿落葉與雜草.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/butterfly" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r49",
"enter":"/open/area/forest/f01",
  "west" : __DIR__"f30",
]));

  setup();
}
