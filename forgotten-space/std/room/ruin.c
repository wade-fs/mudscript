// std/room/ruin.c
// 《遺忘的世界》遺跡機關房基底類別

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

string relic_inscription; // 遺跡上的太古銘文內容
string relic_target;      // 可被研讀的物象標識 (例如: "stone", "slab", "wall")
int required_fate;        // 破除認知盲區所需之天命值
int required_int;         // 參悟其中星象奧秘所需之悟性值

void create() {
    ::create();
    required_fate = 1;
    required_int = 1;
    relic_target = "stone";
    relic_inscription = "一片模糊難辨的太古石痕，依稀記錄著逆行的古老星軌。";
}

void init() {
    ::init();
    add_action("do_study_ruin", "study");
    add_action("do_study_ruin", "參悟");
    add_action("do_tuoyin", "tuoyin");
    add_action("do_tuoyin", "拓印");
}

void set_relic_target(string target) {
    relic_target = target;
}

void set_inscription(string text) {
    relic_inscription = text;
}

void set_required_fate(int val) {
    required_fate = val;
}

void set_required_int(int val) {
    required_int = val;
}

int do_study_ruin(string arg) {
    object me = this_player();

    if (!arg || arg == "" || (arg != relic_target && arg != "stone" && arg != "stele" && arg != "石板" && arg != "斷碑" && arg != "ruin" && arg != "刻痕")) {
        return 0; // 交由後續指令處理
    }

    write(HIG "你凝視著眼前的古代殘痕，試圖沉澱雜念、細細推演...\n" NOR);

    object mys_d = load_object(MYSTERY_D);

    // 1. 認知盲區檢定 (統一由 MYSTERY_D 判定天命門檻、感知靈性與物理去垢條件)
    if (mys_d && !mys_d->can_discover_relic(me, "stream_stele")) {
        write(CYN "你看著這些被厚重青苔與泥垢掩蓋的斑駁凹槽，受限於世俗認知盲區，只覺得線條凌亂無章，宛如前人隨手塗鴉或磨刀留下的頑石。\n" NOR);
        write(WHT "（提示：需先以磨刀 sharpen 或待山洪沖去石垢，或具備足夠的感知/靈性/天命共鳴，方能勘破迷障）\n" NOR);
        return 1;
    }

    // 2. 神識檢定
    int my_sen = me->query(VITAL_SEN);
    if (my_sen < 10) {
        write(HIR "你此刻心神渙散，神識不足，強行參悟只覺大腦隱隱刺痛。\n" NOR);
        return 1;
    }

    me->add(VITAL_SEN, -10);

    write(HIY "【宿命感應】你的眉心忽有一絲神經突觸猛烈跳動，破除了長久以來的認知盲區！\n" NOR);
    write(WHT "你發現這些看似凌亂的凹槽，其夾角與周天星象完全相反，隱隱對應著太古大清洗前的失落星軌！\n" NOR);
    write(HIC "銘文殘意：" + relic_inscription + "\n" NOR);

    // 首次勘破斷碑天機：透過 MYSTERY_D 統一記錄個人級事件並覺醒天命 +1
    if (mys_d && !mys_d->is_relic_discovered(me, "stream_stele")) {
        mys_d->trigger_relic_discovery(me, "stream_stele", me);
    }

    // 鍛鍊悟性
    write(HIG "【你對天地星象的理解加深了，悟性微幅提升！】\n" NOR);
    me->train_stat(STAT_INT, 25);
    me->gain_exp(15);
    return 1;
}

int do_tuoyin(string arg) {
    object me = this_player();

    if (!arg || arg == "" || (arg != relic_target && arg != "stone" && arg != "stele" && arg != "石板" && arg != "斷碑")) {
        write("你想拓印什麼？（例如：tuoyin " + relic_target + "）\n");
        return 1;
    }

    object mys_d = load_object(MYSTERY_D);
    if (mys_d && !mys_d->can_discover_relic(me, "stream_stele")) {
        write(CYN "這塊石板表面覆滿青苔石垢，在你眼中只是一塊尋常洗衣磨刀石，看不出有何值得拓印的紋路。\n" NOR);
        write(WHT "（提示：需先以磨刀 sharpen 或掬水清洗 wash 去除石垢，並具備相應天命共鳴，方能勘破迷障）\n" NOR);
        return 1;
    }

    // 防止無限量產拓片：檢查身上是否已有拓片或已完成拓印事件
    string ev_key = "tuoyin_" + relic_target;
    if (present("stele rubbing", me) || (mys_d && mys_d->has_completed_personal_event(me, ev_key))) {
        write(YEL "你已經成功將石面上的【殘缺星圖拓片】完整拓印下來了，無需反覆拓印。\n" NOR);
        return 1;
    }

    object kit = present("rubbing kit", me);
    if (!kit) kit = present("kit", me);
    if (!kit) {
        object *inv = all_inventory(me);
        foreach (object ob in inv) {
            if (ob->query("is_rubbing_kit")) {
                kit = ob;
                break;
            }
        }
    }

    if (kit) {
        write(YEL "你取出隨身攜帶的【粗黃草紙與炭黑條】，就著水氣小心翼翼地敷在石刻凹槽上，均勻拓印...\n" NOR);
        destruct(kit);
    } else {
        write("你身邊未備專用拓具，只得撕下一角粗草紙，拾起半焦木炭，小心翼翼地敷在石刻凹槽上粗糙拓印...\n");
        write(WHT "（提示：若備有專用的【粗黃草紙與炭黑條】，拓印出的星宿流線將更加完整清晰）\n" NOR);
    }

    write(HIW "一柱香後，你成功將石面上的神秘星紋拓印了下來，獲得了一張【殘缺星圖拓片】！\n" NOR);

    object rubbing = clone_object("/clone/relic/stele_rubbing.c");
    if (rubbing) {
        rubbing->move(me);
    }

    if (mys_d) {
        if (!mys_d->is_relic_discovered(me, "stream_stele")) {
            mys_d->trigger_relic_discovery(me, "stream_stele", me);
        }
        mys_d->complete_personal_event(me, ev_key, 25, 0);
    }
    return 1;
}
