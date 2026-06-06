inherit ROOM;

void create ()
{
  set ("short", "西堂風");
  set ("long", @LONG
不知道是不是迷信的關係，總覺得站不太穩似的，搖搖欲墜的感
覺，是地板在搖晃嗎？還是自己頭昏？這裡空氣讓人想吐，是書放太
久的原因吧。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wind",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_wind.c" : 1,
]));

  setup();
}
