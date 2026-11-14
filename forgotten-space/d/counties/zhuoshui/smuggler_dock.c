// /d/counties/zhuoshui/smuggler_dock.c
// 濁水縣 (Zhuoshui County) 房間 15/15：溶洞地下暗埠・私梟扁舟渡口 (對應卷二 Ch.64-65)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("溶洞地下暗埠・私梟渡口");
    set_long("排石暗渠盡頭豁然接入一片天然喀斯特地下溶洞水潭，水面停泊著數艘塗滿\n"
             "黑桐油的尖頭無聲扁舟。這裡便是濁水縣黑市繞過東關稅卡、循 310 里地下溶洞暗河\n"
             "直通金石府城【城下暗渠・水網樞紐】的秘密起點。向北可退回【廢棄排石暗渠・鐵柵水門】，\n"
             "往西北登舟順暗河而上即入【地下溶洞暗河・鐘乳暗渦洞】。\n");

    set_exits(([
        "north":     "/d/counties/zhuoshui/old_canal_entry.c",
        "northwest": "/d/routes/under_whirlpool_cave.c",
    ]));

    set_is_outdoor(0);
    set("is_underground", 1);
    set_coordinate(6, 4, -1);
}
