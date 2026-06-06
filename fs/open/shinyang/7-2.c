// Room: /u/w/whatup/area/shinyang/7-2
inherit ROOM;

void create ()
{
  set ("short", "興隆客棧");
  set ("long", @LONG
人來人往的客棧，大廳上似乎坐滿了人，夥計四處來來去去忙碌
的穿梭在桌子間，掌櫃的正在劈哩啪啦打著算盤，看到人這麼想多不
經眉開眼笑的，店小二看到你一進來，便向你跑來高喊一聲，呦！客
倌，不知道您是要打尖的呢？還是要來用餐呢？
LONG);

  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/child" : 1,
  __DIR__"npc/woman" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"7-3.c",
]));
  set("no_auc", 1);
  set("light_up", 1);

  setup();
}
