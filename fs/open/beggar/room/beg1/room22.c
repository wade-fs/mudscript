// Room: /u/g/guetenr/beggar/room/beg1/room22.c
inherit ROOM;

void create ()
{
  set ("short", "悅來客棧");
  set ("long", @LONG
悅來客棧乃江南第一棧，不僅商旅不絕車馬絡繹，江湖好漢行經江南亦
多集於此，閒話武林軼事；店面收拾得乾淨不說，廚房不時拿出來的好酒好
菜更讓人食指大動不願離去呢；客棧的座席向東陳設，北邊是臨水的上座，
東北邊遠遠地掌櫃正忙著呢！
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room21.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man2.c" : 2,
]));

  setup();
}
