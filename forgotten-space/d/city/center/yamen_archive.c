// d/city/center/yamen_archive.c
// 府衙案卷庫 (沈泥身世線重要交涉場景)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("府衙後堂・案卷庫");
    set_long("這是一間終年陰涼乾燥的高大條石密室。\n"
             "四周數十座樟木書架直頂屋樑，整齊排列著數萬冊以黃皮紙抄錄的戶籍底單、\n"
             "歷年稅契與前朝舊案底宗。空氣中瀰漫著濃重的防蟲芸草與陳年墨香。\n"
             "案牘主簿文承敬正伏於長案前核對舊案底冊。\n"
             "南面推門可回到府衙正堂。\n");

    set_exits(([
        "south": "/d/city/center/yamen.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "樟木書架高冷乾燥，黃皮紙戶籍底冊與陳年稅契頁角微脆。" NOR);
    set_smell("default", CYN "濃重的防蟲芸草乾香、陳年松煙墨與條石密室獨有的清涼乾爽氣味。" NOR);
    set_listen("default", WHT "密室極靜之中只聞文承敬翻檢卷宗的沙沙紙聲，偶爾傳出外堂一兩聲模糊鼓響。" NOR);

    add_action_rule("register", ([
        "targets": ({ "prisoner" }),
        "quest_verb": "register",
        "quest_target": "prisoner",
        "usage_msg": "你想登錄什麼刑名案卷？試試：register prisoner",
        "sensory_msg": YEL "你將黑石關押解火漆原卷與趙德貴畫押簿頁一併編號歸入府衙刑名底冊，主簿隨即簽發收監照會！" NOR,
        "exp_gain": 10
    ]));
    add_action_rule("archive_dossier", ([
        "targets": ({ "six_gaps" }),
        "quest_verb": "archive_dossier",
        "quest_target": "six_gaps",
        "usage_msg": "你想裝訂歸檔哪份彙總案卷？試試：archive_dossier six_gaps",
        "sensory_msg": HIY "你攤開六大物證缺口底單逐頁校對索引編號，以紅絲線穿孔裝訂並重重烙上硃砂公印！" NOR,
        "exp_gain": 15
    ]));
    add_action_rule("seal", ([
        "targets": ({ "deed" }),
        "quest_verb": "seal",
        "quest_target": "deed",
        "usage_msg": "你想火漆封印哪份憑證？試試：seal deed",
        "sensory_msg": HIG "你取過銅匙壓熱火漆，將從暗渠奪回的血精交割正底單與騎縫存根雙雙封印，確保庭審取證鏈完整無缺！" NOR,
        "exp_gain": 15
    ]));

    spawn_npc("/clone/npc/center_wenchengjing.c");
}
