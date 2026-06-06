#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW + "狂想空間新手入門" + NOR);
  set ("long","當你選定要加入的門派(guild)之後,且看完 help 幫派簡介 之後再來就是前往
  你所選定的門派加入公會,拜師學藝.....展開大俠的心路歷程!!!!!!!
  目前來說有些門派並沒有完全完成所以不建議加入,以免以後後悔!!!!
  2.完成的門派但不是很完整：
    【 舞  者 】    夜夢小築        門派首領﹕月牙兒    (有屬性限制)
    【朝廷命官】    朝庭命官        門派首領﹕陳知衡    (提供二次轉派的門派)
    【 魔教徒 】    魔教            門派首領﹕莊靜柔
    【 方  士 】    天道            門派首領﹕陸清風
    \n");
  set("exits", ([
  "west" : __DIR__"newhand2-3",
  "east" : __DIR__"newhand2-5",
               ]));
  set("light_up", 1);
  setup();
}

