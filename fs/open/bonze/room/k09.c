// Room: /open/bonze/room/k06
inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
往西通往少林寺廚房，你看到相當多的伙房師父經常進出廚房的繁
忙模樣簡直就像是在打仗，這足以證明少林寺的人數相當的多。
　　往南通往柴房。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"k08.c",
  "south" : __DIR__"k10.c",
]));
  setup();
}
