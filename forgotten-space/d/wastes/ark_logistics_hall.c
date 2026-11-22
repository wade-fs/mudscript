// /d/wastes/ark_logistics_hall.c
// 太古方舟・後勤石鋼廳室（Ch.108：九城古商盟總契銅版合璧、禁毀條例第七條與乙巳年雲記抄本）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太古方舟・後勤石鋼廳室");
    set_long("藏於八角核心圓台後方合金門廊內的石鋼拱頂廳室，四周嵌著多數震塌變形的\n"
             "金屬卷宗格柵。室中央立著半人高玄鐵主控台，台面右半邊死嵌著爬滿綠鏽的半塊\n"
             "太古銅版，左側缺口與一旁窄長「青金驗印槽」正待與商盟信物合璧驗證\n"
             "（嵌入青銅契版與天門引驗印：join treaty）。東側遠方地底隱約傳來重型鑽機轟鳴震動！\n"
             "向南走出門廊返回【八角形主陣基核心圓台】。\n");

    set_exits(([
        "south": "/d/wastes/ark_core_chamber.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "玄鐵主控台面與爬滿綠鏽的半塊太古銅版冷硬細膩，驗印槽內壁一塵不染。" NOR);
    set_smell("default", CYN "變形卷宗格柵裡封存著萬年不腐的金屬氧化物微塵與青金合金特有的冷淡氣味。" NOR);
    set_listen("default", HIR "拱頂廳室極靜之中，東側極深處地底不斷傳來重型鑽機微弱卻令人心悸的沉悶震動。" NOR);
}

void init() {
    ::init();
    add_action("do_join", "join");
}

int do_join(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "treaty" && arg != "plate" && arg != "契版" && arg != "銅版") {
        notify_fail("你想拼合驗證哪份舊約？試試：join treaty\n");
        return 0;
    }
    message_vision("$N將金石鬼市拍得之「史前商盟青銅契版殘片」卡入控台左側斷口，再插入莫三\n"
                   "保管三十年的青金古令「天門引」——捲軸盒彈出金屬箔片顯露《九城總約・禁毀條例第七條》：\n"
                   "原名「沈雲妮」的九城萬物商盟總調度使負護全九州避難火種與嚴禁抽毀北境冷卻安全閥之責！\n"
                   "旁側更起獲印有「雲記」暗章及「乙巳年舊盟未結轉帳：玄木」暨三宗採辦代號之皮紙抄頁！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "join", "target": "treaty" ]));
    }
    return 1;
}
