// Room: /open/poison/room/sh5.c
inherit ROOM;

void create ()
{
  set ("short", "藥鋪");
  set ("long", @LONG
甫一踏近此處，一股刺鼻的藥味迎面向你撲來，在你眼前的是
一個紫檀木所製的大櫃子橫靠在對面牆上，櫃子上有著許多的小抽
屜，每一個抽屜的前面均有一標籤註明其所放置的藥材種類，本店
除了賣各種藥材供客人抓藥外，亦賣有尋常的刀傷藥和一些補品。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"v2-7.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/mer4.c" : 1,
]));
  set("light_up", 1);

  setup();
}
