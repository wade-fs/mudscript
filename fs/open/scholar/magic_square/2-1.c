// Room: /open/scholar/magic_square/1-1.c
#include "common.h"
inherit ROOM;

void create()
{
  set ("short", "魔方陣");
  set ("long", (: querylong:)
      );
  set("light_up", 1);
    set("no_transmit", 1);
    set("no_scale",1);

  setup();
}
