// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","道路");
set ("long", @LONG
細觀足下卻是翠玉星子鏡水質地，以為一葦湖上漣漪不起，兩旁巨 
岩怪石，或似鬼魅或似猛獸，古木奇樹，如神靈如金剛，浩然正氣
撼然而生。又有芭蕉桃花崇光泛彩，紅香綠玉翠帶飄飄，淒沚之水 
溶溶蕩蕩，曲折瀅蕍，蘭風蕙露盡在眼底。
LONG);



  set("exits", ([
            "south" : __DIR__"51",
            "north" : __DIR__"49",
                ]));

        setup();
}
