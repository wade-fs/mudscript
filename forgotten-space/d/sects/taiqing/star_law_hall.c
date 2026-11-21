// /d/sects/taiqing/star_law_hall.c
// 太清玄天宮・周天星律院 (Ch.86, Ch.91：星曆誤差對照與觀測主殿)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清玄天宮・周天星律院");
    set_long("大殿中央架著一座巨大的黃銅渾天儀，兩側紫檀長案上堆滿了羊皮星曆卷宗與\n"
             "近三十年雲津暴風雪誤差校對簿。空氣裡飄著淡淡松煙墨香，掌院宋知微正於案前\n"
             "靜靜核驗各觀測哨提交的原始讀數，案頭另押著準予限時查閱藏星秘閣與觀星台的批令。\n"
             "向南走出【太清外門雲舍】，向北進入天柱背陰山腹【藏星秘閣】，向東登上【天柱觀星台】，\n"
             "東北小徑蜿蜒通往後山【清修偏峰】。\n");

    set_exits(([
        "south":     "/d/sects/taiqing/outer_court.c",
        "north":     "/d/sects/taiqing/hidden_archive.c",
        "east":      "/d/sects/taiqing/outer_observatory.c",
        "northeast": "/d/sects/taiqing/quiet_peak.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/song_zhiwei.c");
}

void init() {
    ::init();
    add_action("do_publish", "publish");
}

int do_publish(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "addendum" && arg != "star" && arg != "補遺" && arg != "歲差") {
        notify_fail("你想公開校驗什麼星律文稿？試試：publish addendum\n");
        return 0;
    }
    message_vision(HIW "$N於周天星律院公開《逆星歲差實測補遺》，首頁題明「僅限近三百年北境校正、歡迎反例推翻」，\n"
                       "引導沈照塵將兩組氣流反例原樣補入公開觀測欄——在誠實承認二十八宿天羅法陣背後猶有\n"
                       "看不見之齒輪操縱者而徹底放下『完美絕對天道』執念的一瞬，心鏡澄澈窺見假天裂縫！\n" NOR, me);
    if (!present("reverse_star_addendum", me)) {
        object ob = clone_object("/clone/item/reverse_star_addendum.c");
        if (ob) {
            ob->move(me);
            tell_object(me, HIW "你完成核校並領存《逆星歲差實測補遺》。\n" NOR);
        }
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "publish", "target": "addendum" ]));
    }
    return 1;
}
