#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIY"狂想空間歷史發展館"NOR);
  set( "long", "當時剛創建的狂想只有仙劍派一個門派,後來才出現了中央大陸的部份
聽Wade說他只有寫過中央大陸的房間,其他都沒有寫過,那時根據現在己知的
資料,幫忙架站的大神是Elon,還有一些高手級的巫師如：fund、ccat、bigcat
ice...等(歷史太久我也不知道了)。中央大陸完成後,其餘的門派才陸續建立..
...
" );
  set("exits", ([
  "north" : __DIR__"newhand6-1",
  "south" : __DIR__"newhand6-3",
               ]));
  set("light_up", 1);
  setup();
}

