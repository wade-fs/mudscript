#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIC + "狂想空間小秘技天地" + NOR);
  set ("long","這房間是介紹一些狂想的在玩時的一些小秘技!!
  提供給新玩家參考之用!!!
  秘技一：善用alias指令,alias 指令是可以用來縮短指令的輸入。
  例如：buy water from vendor (像小販買水),我們可以用alias來設
  alias bw buy water from vendor 那以後打bw時就是代表這字串!!!
  可以打help alias來看!!!

  秘技二：善用do指令!!及配合alias 指令!!!
  例如：由於alias一次只能作一個動作,若我們要作很多的動作時.要怎麼設呢
  alias 1 do e,e,buy water from vendor
  我們可以用do指令來作,用逗點來分隔出指令........
 \n");
  set("exits", ([
   "north" : __DIR__"newhand",
  "south" : __DIR__"newhand4-2",
               ]));
  set("light_up", 1);
  setup();
}

