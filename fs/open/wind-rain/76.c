// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","迴翡小逕");
set ("long", @LONG
過竹蘺花障編就的月洞門，俄見粉桓環互，綠柳週垂，櫻樹繽紛，
釣蘭清芬，梨花春雨，桐翦秋風，荻蘆夜雪，百合鬱玉，鶯鳥枝頭
卿卿，蝶蜂蕊間嬝嬝，只見庭繚繞空，香屑布地，火樹琪花，麝腦
之香茵茵輕輕。
LONG);



  set("exits", ([
            "south" : __DIR__"79",
            "north" : __DIR__"75",
            "west"  : __DIR__"77",
                ]));
  set("objects", ([ 
  __DIR__"npc/boy" : 1,
                  ]));
        setup();
}
