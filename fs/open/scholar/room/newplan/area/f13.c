// Room: /u/s/sueplan/newplan/area/f13.c
inherit ROOM;

void create ()
{
  set ("short", "吟風閣內");
  set ("long", @LONG

眼見一百歲人瑞端座於前，此人眼中迥然有神，氣勢亦有經人之感
，分毫不見其見逾百之態，閣內陳設鋪列簡單，無絲竹之亂耳，無案牘
之勞形。

LONG);

  set("light_up ",1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"f12",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/master_wone.c" : 1,
]));

  setup();
}
