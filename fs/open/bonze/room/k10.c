// Room: /open/bonze/room/k06
inherit ROOM;

void create ()
{
  set ("short", "柴房門口");
  set ("long", @LONG
往西北通往少林寺廚房，你看到相當多的伙房師父經常進出廚房的
繁忙模樣簡直就像是在打仗，這足以證明少林寺的人數相當的多。
　　往東通往柴房。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k09.c",
  "northwest" : __DIR__"k08.c",
  "east" : __DIR__"k12.c",
  "west" : __DIR__"k11.c",
]));
  setup();
}
