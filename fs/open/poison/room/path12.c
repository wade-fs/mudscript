// Room: /open/poison/room/path12
inherit ROOM;

void create ()
{
  set ("short", "石洞");
  set ("long", @LONG
從這裡可聽到由東方傳來的陣陣哀嚎聲，陣陣哀嚎慘叫
聲令人渾身不舒服，想來此地便是魔教囚監刑犯之處，此地
竟是如此隱密，其內不知有何重要囚犯。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"path11",
  "eastdown" : __DIR__"path13",
]));

  setup();
}
