// by roger
//排版與改錯字 by blazakira 2011/10/5

inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"

void create () {
  set ("short","牌樓前");
  set( "build", 12 );
  set ("long", @LONG
    這裡已到了湖的盡頭，眼前是「金風細雨樓」的牌樓，圍牆後面
有座巨大的樓，在湖畔霧氣迷濛下，外表濛濛晃晃，分不清是曙色、
黎明，還是醒的邊緣。金風細雨樓是京華第一大幫，總管黑白兩道，
三十八路星霜，七十一股烽煙，一百零八號連環鄔的武林第一大勢力
金風細雨樓總樓主向來被公認為是武林盟主。
LONG);
  set("exits", ([
    "east"  : __DIR__"room8",
    "enter"  : __DIR__"1",
  ]));

  set("objects", ([ 
    __DIR__"npc/rain-guard-door" : 3,
  ]));
  setup();
}

int valid_leave(object me, string dir)
{
  string wind_rain;
  if(dir=="enter" && present("wind_rain",me)) {
    message_vision(HIY"雨護衛說：既然閣下持有本樓的風雨令，就是本樓的人。\n"NOR,me);
    return 1;
  }

  if(dir=="enter" && present("rain guard",environment(me)))
  {
    message_vision(HIY"雨護衛說：對不起，這裡不准外人進出。\n"NOR,me);
    return 0;
  }
  return 1;
}
