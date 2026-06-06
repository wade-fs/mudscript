// Room: /u/p/poloer/dragon/a1
inherit ROOM;

void create ()
{
  set ("short", "炎龍谷前段");
  set ("long", @LONG
進到了谷中，四周昏暗無光，要小心奕奕的走才行。只能摸
著牆壁前進，感覺身旁不時有東西走過，偶而還能聽到鬼怪哭嚎
的聲音，聽起來令人起寒。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mob1.c" : 2,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"a4",
  "east" : __DIR__"a2",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
