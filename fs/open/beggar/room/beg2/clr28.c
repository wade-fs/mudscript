// Room: /u/g/guetenr/beggar/room/beg2/clr28.c
inherit ROOM;

void create ()
{
  set ("short", "丐幫藏書房");
  set ("long", @LONG
此地是丐幫保存重要書籍的地方，書架上滿滿的都是書，
不知道有沒有「降龍十八掌」跟「打狗棒法」的秘笈呢？
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"clr25.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/room/beg1/npc/exp_3000beg2.c" : 1,
]));

  setup();
}
