inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
天龍寺雖不比少林寺招收眾多的俗家弟子,但好歹天龍寺也
是大理的武學重鎮,段家以前若發生內亂也是需要仰賴天龍寺的
武力,因此天龍寺都會在此訓練寺內的僧徒,以備不時之需。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"aa66",
  "east" : __DIR__"aa64",
]));
  set("objects", ([ /* sizeof() == 1 */
"/open/tailong/npc/monkf3.c":2,
]));

  setup();
  replace_program(ROOM);
}
