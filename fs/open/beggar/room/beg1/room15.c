// Room: /u/g/guetenr/beggar/room/beg1/room15.c
inherit ROOM;

void create ()
{
  set ("short", "清幽小道");
  set ("long", @LONG
泥土路向南北蜿蜒而去，另有一支泥土路向東而去；西邊望去是遠接天
際無垠的水田，渲成滿眼綠意，又有一株李花怯生生地立在路旁，白花勝雪
淡泊纖濃，香雅潔密添清幽，待輕風吹來便似蝴蝶翩然翔舞，紛紛揚揚宛如
細雪輕覆，讓人拂了一身還滿，索性任它花謝花飛花滿天。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room16.c",
  "south" : __DIR__"room14.c",
  "west" : __DIR__"room18.c",
]));
  set("outdoors", "/open/");

  setup();
}
