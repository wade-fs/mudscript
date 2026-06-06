inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","紫光之扉");
set("long",@LONG
腳底冒出的地獄融岩把你嚇了一大跳，然而在龍炎鬥氣的加持之下，
漸漸的只覺得這股岩漿暖烘烘的在丹田裡運行，非常受用，正當心境空明
之時，一股渾厚沉重的震動由北方傳來，你警戒心立刻提升到最高點。

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "north"   : __DIR__"room33",
      ]));
        setup();
}
