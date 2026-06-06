// Room: /u/g/guetenr/beggar/room/beg2/clr31.c
inherit ROOM;

void create ()
{
  set ("short", "訓練房");
  set ("long", @LONG
的弟子和外頭的不同，這裡的弟子身上都背有布袋，有一
個、兩個‧‧‧一直到八個，這裡就是丐幫有袋弟子修練的地
方。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"clr29.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/room/beg1/npc/lv1beg.c" : 3,
]));

  setup();
}
