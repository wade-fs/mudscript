// Room: /open/gsword/room/su11.c

inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
走在寬闊的石板大道下,你來到了蜀中城的市區,蜀中城的一般居
民都居住在此,你可以感覺到蜀中城的寧靜與悠閒,來來往往的居民穿
梭在街上,這是一個平靜的城市.
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/gsword/room/su10",
  "north" : "/open/gsword/room/su12",
  "west" : "/open/gsword/room/suroom4",
  "east" : "/open/gsword/room/suroom2",
]));

  setup();
}
