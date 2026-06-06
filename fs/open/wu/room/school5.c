// Room: /u/d/devils/school5.c

inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
你看到兩位武師在此拆招,武師甲喊到:看我的"毀天滅地無極神拳",
武師乙大喝一聲:我用"天崩地裂無影神風腳"破你絕招!..........
正當你驚訝於世上竟有如此武功之時,一條大狼狗突然衝向武師,兩位武
師嚇得落荒而逃,只剩你愣在當場.......
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"school2",
  "east" : __DIR__"school6",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/trainee" : 2,
]));

  set("outdoors", "/open/wu");
  setup();
}
