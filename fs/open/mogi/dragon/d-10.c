//by Casey
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIB"地底湖中"NOR);
  set ("long", @LONG
潛進碧幽的湖中，暗而透明的藍色湖水深不
見底。一陣水流激盪 , 你一回頭看, 什麼東西都
沒有, 只是虛驚一場..

LONG);
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
 "up" : __DIR__"d-9",
 
 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

