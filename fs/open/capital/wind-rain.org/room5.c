// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","醉星樓");
set ("long", @LONG
    酒樓裡擠滿了人，這裡不但可以看到富賈權貴，風流文士，更可看
到江湖俠客，失意落魄之人。有道樓梯通往樓上雅座，牆上題有一首詩：

               颯 颯 東 風 細 雨 來，芙 蓉 塘 外 有 輕 雷。

               金 蟾 齧 鎖 燒 香 入，玉 虎 牽 絲 汲 井 迴。

               賈 氏 窺 簾 韓 掾 少，宓 妃 留 枕 魏 王 才。

               春 心 莫 共 花 爭 發，一 寸 相 思 一 寸 灰。
LONG);



  set("exits", ([
            "out"  : __DIR__"room4",
            "up"  : __DIR__"room6",
                ]));

       

        setup();
}
