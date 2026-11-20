// /clone/npc/tiebei_shanzhu.c
// 鐵背山主・八荒武山掌門 (tiebei_shanzhu) - 問道天台 (Ch.112-120)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鐵背山主");
    set_short(HIY "八荒武山掌門" NOR " 鐵背山主");
    set_long("肩背闊如黑鐵岩礁、滿頭虎斑白髮的老武宗，坐鎮問道天台中央掌門席左側。\n"
             "十年會武後面對黑冰斷谷鐵證如山與北荒破關教訓，他當眾高舉八荒掌印認可停採封爐，\n"
             "戰後更親筆頒下五份《忠烈歸籍與撫恤憑證》予韓素及走山隊遺屬，將韓林刻上黑山烈士碑。\n");
    set_id(({ "tiebei_shanzhu", "tiebei", "八荒掌門", "鐵背山主" }));

    setup_archetype("K", 98);
    set("class", "wu");
    set("faction", "bahuang");
    set("roles", ({ "leader", "judge" }));
    set("home_room", "/d/yunjin/hearing_hall.c");

    add_response(({ "會武", "忠烈歸籍", "韓林", "燕山" }),
        "鐵背山主重拳砸在扶手青銅獅頭上，虎目含威卻無半點遮掩：\n"
        "「五年前黑冰斷谷之事，確有人從內部動了髒手，抹黑我八荒守軍『擅離職守』——這污名本山主今日親自刮掉！\n"
        "這五份加蓋八荒掌印之《忠烈歸籍與撫恤憑證》，先發還韓素與十幾戶遺屬、將韓林名字深鑿上黑山長城烈士碑！\n"
        "唯獨那位帶『燕』字護心鏡的大伯燕山尚未見骸骨，在查實前仍列在失蹤歸隊待尋欄裡。」");

    add_response(({ "長城缺口", "獸潮", "新約" }),
        "鐵背山主沉聲道：「黑山長城西側被冰獄骨龍撞毀的整整三十丈缺口必須趕在春融前重修——\n"
        "往後三宗共同簽署之《雲津萬山臨時互市與救濟協約》，亦准許商埠參與長城軍糧與材料公開透明查核！」");
}
