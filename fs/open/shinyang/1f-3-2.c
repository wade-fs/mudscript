// Room: /u/w/whatup/area/shinyang/1f-3-2.c
inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
前方看起來就城主府中的重要之地，前方門上的牌匾寫著議事堂
三個大字四周竟然沒有看到人，令你十分的好奇，不禁讓你想進去議
事堂中參觀一下，但是聽到巡邏中的衛兵聲音靠近，令你猶豫了一下
。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"1f-3-3.c",
  "west" : __DIR__"1f-2-2.c",
  "east" : __DIR__"1f-4-2.c",
  "south" : __DIR__"1f-3-1.c",
]));
  set("no_auc", 1);

  setup();
}
