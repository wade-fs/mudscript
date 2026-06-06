// Room: /u/s/sueplan/newplan/area/get2.c
inherit ROOM;

void create ()
{
  set ("short", "小路旁");
  set ("long", @LONG

天空泛著白雲, 看起來天氣是非常的和煦, 路上可以聽到鳥兒
高聲歌唱, 讓你的心情無比的愉快。不過你看到一個白髮老人在你
面前嘆著氣, 不知道他是怎麼了?
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"groom2.c",
  "west" : __DIR__"groom4.c",
]));

  setup();
}
