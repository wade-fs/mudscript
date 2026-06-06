//礦坑 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW"遺忘"HIY""YEL"礦坑"NOR);
  set ("long", @LONG
這裡在從前曾是礦產豐富的淘金聖地，然而自從長白山出現四大
山精之後，所有的礦工及聚落一夕間全部消失，留下的只有代表過往
存在之證明、年久失修的老舊礦坑，由於長年密閉於地下的關係，礦
坑裡的空氣相當污濁，最好別冒險躁進。
LONG);

  set("exits", ([
  "up" : __DIR__"mon29.c",
  "northdown" : __DIR__"mine2.c",

               ]));
  set("outdoors", "/open/main");
  set("no_transmit",1);
  setup();
}

void init()
{
 object me = this_player();
 if(me->query("attribute") != "ground" && random(2) == 1)
  {
    message_vision(HIM"地底湧出的惡臭沼氣使$N感到一陣暈眩。\n"NOR,me);
    me->unconcious();
  }
}
