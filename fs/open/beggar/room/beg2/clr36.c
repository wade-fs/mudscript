// Room: /u/g/guetenr/beggar/room/beg2/clr36.c
inherit ROOM;

void create ()
{
  set ("short", "訓練場");
  set ("long", @LONG
這裡是丐幫訓練有成的弟子加強訓練的地方，你看到這裡
的弟子和外頭的不同，這裡的弟子身上都背有布袋，有一個、
兩個‧‧‧一直到八個，這裡就是丐幫有袋弟子修練的地方。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"clr35.c",
]));
  set("outdoors", "/open/beggar");
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/room/beg1/npc/lv5beg.c" : 2,
]));

  setup();
}
