inherit ROOM;

void create ()
{
  set ("short", "船艙通道");
  set ("long", @LONG
房間一, 敘述未想....
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"i2.c",
]));

  setup();
}
