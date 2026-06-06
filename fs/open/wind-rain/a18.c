// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short",HIC"夢樨殿"NOR);
	set( "build", 38 );
set ("long",@LONG
馨香撲鼻，華光刺目，一具巨大的水晶虹色琉璃燈垂掛於頂，光彩
奪目，槐木龍雕椅雙列對望，檜木雙燕細刻三腳几隔在椅間，如花  
似玉的婢女們則佇立在後，深紅紋繁地毯直直往裡鋪設到垂紗珠簾
之後，有兩個婢女正在服侍著一樓樓主。 
LONG);



  set("exits", ([
            "north"  : __DIR__"a17",
                ]));
  set("objects", ([ 
  __DIR__"npc/dau" : 1,
                  ]));
       
        setup();
}
