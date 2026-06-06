// Room: /u/g/guetenr/beggar/room/beg2/clr34.c
inherit ROOM;

void create ()
{
  set ("short", "東廂房");
  set ("long", @LONG
說大不大，說小不小，正是東廂房的寫照，一進此間只見
一張因缺了隻腳而歪斜的方桌，和兩條已被蟲蝕而瘡痍滿目的
長凳。房間偏西處的兩扇窗子，紙糊早已破盡，顯得可有可無
，偏東處擺著一張木板床，床上坐有一人，原來便是掌棒龍頭
。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"clr33.c",
  "east" : __DIR__"clr35.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/beggar/room/beg1/npc/lv7beg.c" : 2,
  "/open/beggar/room/beg1/npc/leader_lu.c" : 1,
]));

  setup();
}
