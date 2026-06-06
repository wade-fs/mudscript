// Room: /u/s/sueplan/newplan/area/groom.c
inherit ROOM;

void create ()
{
  set ("short", "小路旁");
  set ("long", @LONG

天空泛著白雲, 看起來天氣是非常的和煦, 路上可以聽到鳥兒
高聲歌唱, 讓你的心情無比的愉快。

LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"groom3.c",
  "east" : __DIR__"groom1.c",
]));

  setup();
}
