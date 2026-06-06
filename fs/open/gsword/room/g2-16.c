// Room: /open/gsword/room/g2-16.c
inherit ROOM;

void create ()
{
  set ("short", "菜圃");
  set ("long", @LONG
一片廣大的菜圃 ,種滿了各式各樣種類的蔬菜 ,供應本派絕大部
份的菜類來源 ,這片菜圃每天為仙劍所節省之開銷 ,皆為一比可觀的
數字 ,開源結流 ,能省則省 ,這就是仙劍聚財之首道 .

LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc/oldfarmer" : 1,
  "/open/gsword/npc/farmer" : 2,
]));
  set("outdoors", "/open/gsword/room");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"g2-15",
]));

  setup();
}
