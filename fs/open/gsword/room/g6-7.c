// Room: /open/gsword/room/g6-7.c
inherit ROOM;

void create ()
{
  set ("short", "山洞");
  set ("long", @LONG
一個空曠的大山洞，因洞口極小，只有少許陽光照射進來，顯的十分
昏暗，北方一片大壁，應該就是思過之所在吧！你隱約看到一個人坐在一
顆大石上，面向著牆壁，呆呆出神，對你的造訪毫無反應。不知他犯了什
過，何以被罰在此？

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room/g6-6",
]));

   set("objects",([
   "/open/gsword/npc/trainee-3.c":1,

  ]));

  set("light_up", 1);

  setup();
}
