// Room: /open/main/room/to_chun2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "狂風嶺");
  set ("long", @LONG
你登上此地, 一股狂風對你迎面吹來, 你站不住腳, 險些便要
摔倒, 只見一個青袍老人坐在山崖邊, 獨自望這遠方, 你看著這個
老人, 突然驚覺, 此人便是段延慶!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"to_chun1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/chun.c" : 1,
]));

  setup();
  replace_program(ROOM);
}
