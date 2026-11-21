// /d/sects/taiqing/sealed_observatory.c
// 太清偏峰・封存觀測室 (Ch.124-125：五器共振鎖定天道排斥劫雲、三掌門開示《祖師密錄》與臨時隔音陣)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清偏峰・封存觀測室");
    set_long("清修偏峰後方最貼近太清導星陣眼的高海拔石構密室，平日以三宗聯署玄鐵禁令封存、\n"
             "絕不對外人開放。室中中央擺設校驗太古遺物的玄岩測算盤，牆角置有封存千年《祖師密錄》\n"
             "的玄鐵舊木匣；抬首透過穹頂天窗正窺見雲海之上看似晴明、實則佈滿幾何交網之天穹。\n"
             "（當五件太古遺物並聚於此共鳴，恐將引動假天排斥劫雲——指令：resonate relics）\n"
             "西南石階退返【清修偏峰】，沿室角千年螺旋封閉黑岩深階向下（down）千餘丈直入\n"
             "三大名山交會地底的【太古破界方舟・主傳送室】。\n");

    set_exits(([
        "southwest": "/d/sects/taiqing/quiet_peak.c",
        "down":      "/d/sects/taiqing/ark_portal_chamber.c",
    ]));

    set("is_outdoor", 0);
}

void init() {
    ::init();
    add_action("do_resonate", "resonate");
}

int do_resonate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "relics" && arg != "cloud" && arg != "五器" && arg != "共鳴") {
        notify_fail("你想在此對照測試什麼？試試：resonate relics\n");
        return 0;
    }
    message_vision(MAG "$N取出逆星拓片、不融黑鐵齒輪、獵獸骨片、古礦晶核與天門引暨九城契版並肩對照——\n"
                       "「嗡————！！」十倍強烈的共鳴直衝太清導星陣眼並激動萬丈地底方舟主陣基！\n"
                       "十餘息內晴空化作紫黑機械排斥劫雲與冷漠暗紫雷弧鎖死百里！紫霄真人遂啟玄鐵舊木匣，\n"
                       "揭示十七位二階圓滿先輩單向遁入地下【桃花源古傳送陣】而無一歸返實錄之密傳！\n" NOR, me);
    if (!present("ancestor_secret_record", me)) {
        object ob = clone_object("/clone/item/ancestor_secret_record.c");
        if (ob) {
            ob->move(me);
            tell_object(me, HIY "你記下並抄錄了封存於匣中的《三宗祖師密錄（封存抄頁）》。\n" NOR);
        }
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "resonate", "target": "relics" ]));
    }
    return 1;
}
