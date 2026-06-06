// Room: /u/s/sueplan/newplan/area/groom1.c
inherit ROOM;

void create ()
{
  set ("short", "小路旁");
  set ("long", @LONG

天空泛著白雲, 看起來天氣是非常的和煦, 路上可以聽到鳥兒
高聲歌唱, 讓你的心情無比的愉快。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"groom2.c",
]));
  set("outdoors", "/u/s");
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/man_koo.c" : 1,
]));

  setup();
}
