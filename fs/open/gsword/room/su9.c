// Room: /open/gsword/room/su9.c

inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
走在寬闊的石板大道下,你來到了蜀中城的市區,蜀中城的一般居
民都居住在此,你可以感覺到蜀中城的寧靜與悠閒,來來往往的居民穿
梭在街上,這是一個平靜的城市.在你的東方有間旅店.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/man" : 1,
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/gsword/room/su8",
  "north" : "/open/gsword/room/su10",
  "east" : "/open/gsword/room/restroom",
]));

  setup();
}
