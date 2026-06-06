
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","魔之右翼");
        set ("long","魔氣蕩繞晦明變化, 非比山間之朝暮霏霏, 髏\頭燭眼, 魅影參間, 滴聲間
斷, 不知是水是血. 突來陰風陣陣如魚龍吐息, 卻是混沌灼熱, 強烈的溫
差使你的身體如剮如裂, 若非內力深厚可能早已被盡碎五腑而亡. 魔界黑
石腥光粼粼, 炎炎邪氣急竄奔走, 魔歸而巖穴暝.  
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north" :  __DIR__"room78",
            "south"  : __DIR__"room76",
      ]));
        setup();
}
