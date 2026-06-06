// Room: /u/p/poloer/dragon/a11
inherit ROOM;

void create ()
{
  set ("short", "洞口內");
  set ("long", @LONG
一個非常矮小的通道，只能讓一個人通過的寬度，
    通道濕褡褡還滴著水呢。怎麼會有通道在這個地方
    呢? 不如往下看看有什麼東西吧。

LONG);

set("light_up", -1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"a11-1",
  "out" : __DIR__"a5",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
