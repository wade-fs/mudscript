// Room: /open/gsword/room/gsword6-1.c
inherit ROOM;

void create ()
{
  set ("short", "後花園");
  set ("long", @LONG
你正置身於一個極致的小花園中 ,紅梅綠竹 ,青松翠柏 ,布置的極具
匠心 ,池塘中數對鴛鴦悠游其間 ,池旁有四隻白鶴 .西邊一座小橋跨越池
塘而過 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/gsword/room/g2-9.c",
  "west" : "/open/gsword/room/g4-14.c",
]));

  setup();
}
