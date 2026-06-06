#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIY"狂想空間歷史發展館"NOR);
  set( "long", "那時我正在狂想空間玩,在師大時期算後期時我才正式加入狂想空間
後來由於一直重開使我玩的很無力,(那時我正在當兵,因為狂玩狂想兵變..)
不知道有沒有人跟我一樣,後來我就加入了巫師群,因為玩的很無力,在師大
那時我的boss是kazuya,負責仙劍的雙十旋龍斬的謎,後來搬到中興後,因緣
際會,以前的老婆(sidewind)現在的(superobs)找了我去南站寫程式.所以我
就到南站去了,那時的南站正在如火如茶的發展,時間是一九九七年年底....
根據我的印象搬到中興是一九九七年年中的時候.....
" );
  set("exits", ([
  "north" : __DIR__"newhand6-9",
  "south" : __DIR__"newhand6-11",
               ]));
  set("light_up", 1);
  setup();
}

