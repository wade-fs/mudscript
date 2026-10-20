// d/city/outer/graveyard.c
// 金石府外・城外亂葬義塚 (都城死傷歸宿地)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城外近郊・亂葬義塚");
    set_long("金石城北關數里外一片荒涼淒冷的亂墳崗。\n"
             "荒草漫過半截風化的無名木碑，四周瀰漫著淡淡的腐殖與夜煞氣息。\n"
             "凡在城中重傷身殞又無宗族贖領的流民孤魂，多於此處冷風中重聚殘魄甦醒。\n"
             "南面沿雜草土路可走回金石北關城門。\n");

    set_exits(([
        "southeast": "/d/city/gate/gate_north.c",
        "south":     "/d/city/gate/gate_north.c",
    ]));

    set("is_outdoor", 1);
    set("is_graveyard", 1);
}
