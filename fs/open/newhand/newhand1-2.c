#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW + "狂想空間指令入門房間" + NOR);
  set ("long","狂想空間的指令集分成二大系統!!!
  1.一般指令系統(help cmds)       (所有的玩家都可以使用)
  2.幫派指令系統(help clancmds)   (部份有開放給非一般玩家,除此之外限定幫派才能使用)
  你可以打help cmds就會列出所有指令集!!!
  若你對該指令集有不了解的地方,你可以打help 指令
  例如::
         打 help kill

         指令格式 : kill <人物>
指令說明 :
           這個指令讓你主動開始攻擊一個人物﹐並且嚐試
         殺死對方﹐kill 和 fight 最大的不同在於雙方將
         會真刀實槍地打鬥﹐也就是說﹐會真的受傷。由於
          kill 只需單方面一廂情願就可以成立﹐因此你對
         任何人使用 kill 指令都會開始戰鬥﹐通常如果對
         方是 NPC 的話﹐他們也會同樣對你使用 kill。
           當有人對你使用 kill 指令時會出現紅色的字樣
         警告你﹐對於一個玩家而言﹐如果你沒有對一名敵
         人使用過 kill 指令﹐就不會將對方真的打傷或殺
         死( 使用法術除外 )。
其他參考 :
           fight
特別說明 :
           有關 fight 跟 kill 的區分請看 'help combat'。
           有關 pk的問題請看"help pk"。

  \n");
  set("exits", ([
  "north" : __DIR__"newhand1-2",
  "south" : __DIR__"newhand",
               ]));
  set("light_up", 1);
  setup();
}

