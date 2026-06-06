// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","走道");
set ("long",@LONG
猩紅氈毛纏地，還零散著一瓣一瓣粉色芬芳，樑柱下是象牙長几，
擺著翠玉琉璃花瓶，裡頭是綻放的觀音草，樑柱上是七彩玲瓏荷花
吊燈，牆上掛的，是唐代山水漢朝字墨。 
LONG);



  set("exits", ([
            "east" :  __DIR__"a14",
            "south" : __DIR__"a19",
                ]));

        setup();
}
