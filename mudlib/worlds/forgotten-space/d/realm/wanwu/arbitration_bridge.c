// /d/realm/wanwu/arbitration_bridge.c
// 萬物主機城・中央鋼鐵仲裁橋 (Ch.152 火種條款暫緩清零 / Ch.163 第六階段定名平權)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("萬物主機城・中央鋼鐵仲裁橋");
    set_long("橫跨深淵齒輪海之上的百丈青金鋼鐵長橋，橋心懸浮著三環同心的萬物仲裁子機。\n"
             "此處是三極與九城舊約對質的最高法理平台：既可呈遞火種補登清冊援引離艦總約第七條\n"
             "暫緩強制清零十日（invoke treaty），亦能於校準夜後公開核實平權核銷書（equalize charter）。\n"
             "向西退返【九號艙登錄廳】。\n");

    set_exits(([
        "west" : "/d/realm/wanwu/ark_registry_hall.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", HIW "橋欄由一整塊打磨平滑的青金太古鋼鑄成，手掌貼上能感到主機脈衝流過。" NOR);
    set_smell("default", CYN "高熱機房升騰上來的金屬氣息，夾著橋頭冷風帶來的鹽霜乾燥味。" NOR);
    set_listen("default", HIC "仲裁子機銅輪轉動時發出莊嚴整齊的金石共鳴，壓過橋下深淵齒輪雜響。" NOR);

    spawn_npc("/clone/npc/wanwu_arbiter_core.c");
}

void init() {
    ::init();
    add_action("do_invoke_treaty", "invoke");
    add_action("do_equalize_charter", "equalize");
}

int do_invoke_treaty(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "treaty" && arg != "條約" && arg != "火種") {
        notify_fail("你要援引什麼法理？試試：invoke treaty\n");
        return 0;
    }

    tell_object(me, HIY "你踏上鋼鐵談判橋，高舉《石堡在籍火種補登清冊》與天門引對質仲裁子機與陳楷！\n" NOR);
    tell_object(me, HIG
        "【離艦總約第七條生效・強制清零暫緩十日（EV414）】\n"
        "仲裁子機覆核在籍戶籍與實物抵扣帳後轉綠定案，裁定陳楷清零令違反『第一優先序：保全人類火種』！\n"
        "陳楷受迫於外環停工聯署底稿，只得鐵青著臉簽下十日緩衝停火令。\n" NOR);
    say(me->query_name() + " 以逐戶補登清冊對質萬物仲裁子機，當庭阻停強制清零令十日！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "invoke", "target": "treaty" ]));
    }
    return 1;
}

int do_equalize_charter(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "charter" && arg != "平權" && arg != "沈雲妮") {
        notify_fail("你要核銷哪份契書？試試：equalize charter\n");
        return 0;
    }

    tell_object(me, HIY "你在三方遺民代表面前核實『沈雲妮』法理繼承名分，隨即當庭廢除少數獨裁調度條款！\n" NOR);
    tell_object(me, HIW
        "【第六階段身世終章：名歸雲記，行仍沈泥（EV419）】\n"
        "資源權與議事權永久均分予凡間萬山泥途總號與洞天灰燼自治議會；三極被迫簽立百年停戰貨殖清單。\n" NOR);
    say(me->query_name() + " 公開簽署《九城跨界平權共治核銷書》，永久廢除九城總約獨裁條款！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "equalize", "target": "charter" ]));
    }
    return 1;
}
