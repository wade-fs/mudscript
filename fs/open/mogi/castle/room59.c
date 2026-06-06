
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡三樓");
        set ("long","牆壁上點著青綠色的鬼火，仔細一看是由酷似骷髏\的銀器作成燈座，綠
光便由骷髏\的兩隻眼睛裡射出，豪華中透著恐怖的氣息。地上也鋪著厚
厚的地毯，令人不禁驚奇地東張西望。四周的妖魔似乎也都披金戴銀，
性情也溫和的多，但一身武藝看起來比樓下的是有過之而無不及，你不
禁懷疑自己真是在魔界？
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "west"  : __DIR__"room60",
            "east"  : __DIR__"room62",
      ]));
        setup();
}
