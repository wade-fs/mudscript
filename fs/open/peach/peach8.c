// Room: /u/w/whatup/peach/peach8
inherit ROOM;

void create ()
{
  set ("short", "桃木林");
  set ("long", @LONG
一走進桃木林裡，映入眼簾的是一大片桃木，並且一直延伸下去
，也沒有明顯的道路痕跡，只能四處走走，期盼能快點找到出口，早
點離開這裡。。
LONG);

  set("outdoors", "/u/b");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"peach9.c",
  "east" : __DIR__"peach7.c",
  "west" : __DIR__"peach1",
]));

  setup();
}
