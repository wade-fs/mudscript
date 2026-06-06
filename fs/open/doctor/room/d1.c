#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short","道路");
  set ("long", @LONG
你正走在這條道路上，一路走來，人煙越來越稀少，蟲聲鳥鳴清脆悅耳，
路邊長滿了許多珍貴的草藥，仔細往北眺望，依稀可以看到【銀針門】三個大
字 。

LONG);

  set("light_up", 1);
        set("outdoors", 1);
        set("objects",([
        ]));
  set("exits", ([ /* sizeof() == 2 */
      "north" : __DIR__"d2",
      "south" :"/open/port/room/r3-4.c",
      ]));
  setup();
}


