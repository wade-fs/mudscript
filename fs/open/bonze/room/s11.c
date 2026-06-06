// Room: /open/bonze/npc//room/s11.c
inherit ROOM;

void create ()
{
  set ("short", "戒律堂走廊");
  set ("long", @LONG

這裡是少林寺中供弟子練功修行之地,在這裡可以看到相當多的少林弟子
正在忙碌著,若是被長老所罰的弟子也在這裡進行修行


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"s12.c",
  "west" : __DIR__"s10.c",
]));
  set("outdoors", "/open/bonze/npc//room");
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/bonze/npc/R_trainee" : 3,
]));
  

  setup();
}
