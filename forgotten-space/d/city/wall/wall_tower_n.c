// d/city/wall/wall_tower_n.c
// 北城望荒箭樓 (嚴目瞭望長警戒北山煞潮)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北城・望荒箭樓");
    set_long("這座高達五丈的重石箭樓踞於都城最北端，視野極度遼闊。\n"
             "樓內架設著三具觀星透鏡與巨大的警鐘，瞭望長嚴目手持單筒風蝕石英鏡，\n"
             "日夜警惕地注視著北山地脈煞潮與外荒走獸的異動。\n"
             "南面推開沉重木門，可回到北段巡城步道。\n");

    set_exits(([
        "south": "/d/city/wall/wall_path_n.c",
    ]));

    set("is_outdoor", 0);
}
