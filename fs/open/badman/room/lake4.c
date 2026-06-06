// Room: /open/badman/room/lake4.c
// written by powell 96.4.26@FS
inherit ROOM;

void create ()
{
  set ("short", "湖中密道");
  set ("long", @LONG
這裏是惡人湖中的密秘通道，真想不到這湖裏還別有洞天，還
好這湖並不很深，湖水並未浸入到這兒來。北邊好像有通道，只是
不知道會通到哪？

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lake5",
  "down" : __DIR__"lake3",
]));

  setup();
}
