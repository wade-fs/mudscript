#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIC"狂想空間小秘技天地"NOR);
  set ("long","這房間是介紹一些狂想的在玩時的一些小秘技!!
  提供給新玩家參考之用!!!
  秘技三：數量指令!!!
  有時候我們向師父學技能時要打learn dodge from master....
  這樣一直打很累..我們可以改成learn 30 dodge from master..
  就會等於learn dodge from master 三十次.....
  買東西也是buy 10 tea from vendor就是一次買十杯茶!!!!!
  或是利用do的指令也可以哦!!!!

  秘技四：解謎!!!
  例如：除了練功\之外狂想空間有些謎可以去解,打quests就知道了!!!
  若要詳細的解法可以到狂想的專屬討論區看看!!!!
  中原資管(140.135.112.2) 有fs_mud 的board

\n");
  set("exits", ([
  "north" : __DIR__"newhand4-1",
  "south" : __DIR__"newhand4-3",
               ]));
  set("light_up", 1);
  setup();
}

