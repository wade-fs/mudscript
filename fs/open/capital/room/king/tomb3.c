//皇陵 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIY"皇陵"NOR);
  set ("long", @LONG
四週瀰漫著莊嚴肅穆的氣氛，這裡是皇朝歷代帝皇駕崩後的安葬
之地，此地不但不像一般墓園的陰森，反而還瀰漫著高貴優雅的氣息
，更因受人景仰的歷代明君在此長眠，久而久之使得這裡成為邪惡魔
物所避之唯恐不及的聖地。
LONG);

  set("exits", ([
  "north" : __DIR__"tomb4.c",
  "south" : __DIR__"tomb2.c",

               ]));
  set("outdoors", "/open/main");
  set("no_transmit",1);
  setup();
}

void init()
{
 object me = this_player();
 if(me->query("attribute") == "dark")
  {
    me->add("gin",-3*(me->query("max_gin"))/5);
    me->add("kee",-3*(me->query("max_kee"))/5);
    me->add("sen",-3*(me->query("max_sen"))/5);
  }
}
