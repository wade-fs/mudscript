inherit ROOM;

void create ()
{
  set ("short", "迴廊");
  set ("long", @LONG
長長的走道向前延伸, 這兒有許多房間, 是段家子弟的居所, 在
此切勿大聲喧嘩, 免的引人反感。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"np2",
  "north" : __DIR__"np14",
]));
  set("light_up", 1);

  setup();
}
