inherit ROOM;
void create()
{
  set ("short","狼谷");
  set ("long", @LONG
這裡是半山谷的地方 ,仔細地看了一下 ,四周的狼仍然只是望著你
 ,而不攻擊 .谷底似乎有幾間房子正冒著煙 ,那裡應該就是飼養這些狼
兒的飼主所住的地方吧 ?

LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"wolf07.c",
  "southup" : __DIR__"wolf01.c",
  ]));

  set("objects", ([ /* sizeof() == 3 */
  "/open/badman/npc/wolf02.c" : 3,
]));
  setup();
}
