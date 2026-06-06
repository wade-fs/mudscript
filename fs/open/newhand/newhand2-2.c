#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"狂想空間新手入門"NOR);
  set ("long","看完了新手入門文件(help newbie)之後,要了解一下狂想空間的門派!!
  一般來說在成為大俠之前總是要先找個門派拜師學藝!!在加入門派之前要先加入公會(class)
  新手第二步：先加入該門派的公會(join class)在加入該門派(apprentice master)
  你可以打guild,就會出現狂想空間的門派及職業!!!
  若你想對該門派有進一步的了解...可以打help 幫派簡介
  \n");
  set("exits", ([
  "west" : __DIR__"newhand2-1",
  "east" : __DIR__"newhand2-3",
               ]));
  set("light_up", 1);
  setup();
}

