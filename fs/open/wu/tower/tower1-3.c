// Room: /u/p/pokai/room/wu/tower1-3
inherit ROOM;

void create ()
{
  set ("short", "武威七殺塔一樓");
  set ("long", @LONG
一進到這兒，你就被突如其來的的敵人所攻擊。你定了定神後，注意到這間房間
到處都是乾掉的血漬，四周的牆壁也都佈滿了打鬥過的痕跡。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower1-2",
  "climb" : __DIR__"tower2-1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"killer1-1" : 4,
]));

  setup();
}

int valid_leave(object me, string dir) {
  if(dir=="climb"&&present("tower guard",environment(me))) {
  return notify_fail("塔底守衛大叫：想上去！先殺了我們再說！\n");
  } 
 return 1;
}
