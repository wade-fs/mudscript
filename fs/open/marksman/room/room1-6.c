// Room: /u/f/fire/room/room1-6.c
//inherit ROOM;

#include <ansi.h>
#include "marksman.h"
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
  set ("short", YEL"宋家商店"NOR);
  set ("long", @LONG
這裡擺滿了各式各樣剛剛打造出來的防具和武器，屋裡到處是皮
革金屬布料和刀劍。你似乎看到在牆上及桌上看到零零散散的火把及
繩鉤可買。商店裏的老闆正親地招待你。
LONG); 

 set("exits", ([ /* sizeof() == 1 */
"north" : __DIR__"room1-4",
]));
set("outdoors","/open/marksman");

  setup();
}
