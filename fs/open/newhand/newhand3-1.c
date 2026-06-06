#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIY"狂想空間幫派入門房間"NOR);
  set ("long","狂想空間另外一項系統就是幫派的系統(clans),新玩家可以
  打help clans,看一下幫派的入門!!幫派及門派的主要不同!!!如下：
  1.幫派是由玩家所組成的!!!門派是由巫師(wizard)所創建的!!
  2.幫派可以寫自己的武器、幫眾、房間及可以發起戰爭!!!
  3.加入幫派的話得到照顧也比較多，練的會比較快!!!
  4.要是你可以的話.以後你自己也可以創自己的幫派!!!
  例如：help clans
    help creat_clan 如何創建一個幫派。
    help clan_rank  幫派的階級制度。
    help clan_money 錢的重要性。
    help clan_cmds  幫派的指令說明。
    help clan_room  如何建造自己的幫派。
    help clan_rules 幫派規定。
    help clan_war   幫派的戰爭。
    help clan_boss  幫主入門教學。
    help clan_tax   幫派稅率制度。
    help clan_dev   幫派發展制度。
    help clan_stat  幫派狀態說明。

               \n");
  set("exits", ([
  "east" : __DIR__"newhand",
  "west" : __DIR__"newhand3-2",
               ]));
  set("light_up", 1);
  setup();
}

