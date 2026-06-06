#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR"雜貨店");
        set("long",@LONG
這裡是一間竹製的竹屋, 竹牆上掛滿了許許多多奇
怪的東西, 有些東西似乎看起來是可以食用的, 但是形
狀卻十分的古怪, 又有些看似防具之類的東西, 不過都
長的奇形怪狀, 讓你不由的懷疑, 這裡面的東西到底能
不能用...
LONG);
        set("exits",([
        "east":__DIR__"g-r04",
        ]));
        set("no_transmit",1);
        setup();
}
