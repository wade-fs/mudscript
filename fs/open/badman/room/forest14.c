// Room: /open/badman/room/forest14.c
// written by powell 96.4.26@FS
inherit ROOM;

void create ()
{
  set ("short", "森林邊緣");
  set ("long", @LONG
突然你眼睛一亮，終於離開了這個鬼森林，這兒看起來荒涼的
很；西邊是片茂盛的竹林，北邊則是回到那個該死的惡人森林。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"forest15",
  "north" : __DIR__"forest13",
]));
  set("outdoors", "/open/badman");

  setup();
}
