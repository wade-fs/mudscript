#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"狂想空間指令入門房間"NOR);
  set ("long","狂想空間的指令集分成二大系統!!!
  1.一般指令系統(help cmds)       (所有的玩家都可以使用)
  2.幫派指令系統(help clancmds)   (部份有開放給一般玩家,除此之外限定幫派才能使用)
  你可以打help cmds就會列出所有指令集!!!
  若你對該指令集有不了解的地方,你可以打help <指令>
  例如::
         打 help look
  就會出現
  指令格式 : look [<物品>|<生物>|<方向>]
  指令說明 :
             這個指令讓你查看你所在的環境、
             某件物品、生物、或是方向。
  ps:指令是最基本的!!所以請新玩家在玩時一定要把指令看清楚!!
  \n");
  set("exits", ([
  "north" : __DIR__"newhand",
  "south" : __DIR__"newhand",
               ]));
  set("light_up", 1);
  setup();
}

