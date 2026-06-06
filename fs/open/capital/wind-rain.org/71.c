// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short",HIC + "蔚雲天" + NOR);
set ("long","忽見佳木蘢蓯奇花爛熳，淒沚之水從花木深處環瀉而過，一陣水氣
之香清流飄然，此亭由一天然巨岩雕鑿而成，鬼斧神工，兩旁龍柱
上寫著" + HIC + "「繞隄柳借三篙翠，隔岸花分一脈香」" + NOR + "，再上，西子青紗曲
幃成簷，薔薇紅綴，其頂刨成羅帳薄影，窺日伺月。
");



  set("exits", ([
            "north" : __DIR__"69",
            "south" : __DIR__"66",
                ]));

  set("objects", ([ 
  __DIR__"npc/liu-un" : 1,
                  ]));
       
        setup();
}
