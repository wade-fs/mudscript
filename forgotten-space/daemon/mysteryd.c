// daemon/mysteryd.c
// 《遺忘的世界》史前奇遇、個人級事件與歷史拼圖守護進程 (MYSTERY_D)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

void create() {
    ::create();
}

// 查詢玩家是否已完成某項「個人級事件」(04 Personal-Level Event)
int has_completed_personal_event(object who, string event_id) {
    if (!who || !event_id || event_id == "") return 0;
    return (who->query("personal_event/" + event_id) ? 1 : 0);
}

// 記錄完成「個人級事件」，並給予經驗值與天命 (fate) 覺醒獎勵
int complete_personal_event(object who, string event_id, int exp_gain, int fate_gain) {
    if (!who || !event_id || event_id == "") return 0;
    if (has_completed_personal_event(who, event_id)) return 0;

    who->set("personal_event/" + event_id, 1);

    if (exp_gain > 0) {
        who->gain_exp(exp_gain);
    }

    if (fate_gain > 0) {
        int cur_fate = who->query(STAT_FATE);
        who->set(STAT_FATE, cur_fate + fate_gain);
        tell_object(who, HIY "【宿命共鳴】你觸及了一角被大清洗抹除的史前真相，體內沉睡的天命微幅覺醒（天命 +" +
                         sprintf("%d", fate_gain) + "，當前天命：" + sprintf("%d", cur_fate + fate_gain) + "）！\n" NOR);
    }
    return 1;
}

// 判定玩家是否能破除「大清洗認知封印 (Cognitive Filter)」
// 依據正典 §3.11 & 第1章：
// 凡夫俗子受認知鋼印所限，見古碑只當尋常磨刀頑石；
// 唯有滿足以下條件之一方能勘破認知盲區：
// 1. 天命已覺醒達標 (player_fate >= required_fate，例如完成身世奇遇後 fate >= 2)；
// 2. 具備潛伏天命 (fate >= 1) 且石板表面的青苔石垢已被物理外力（磨刀 sharpen 或山洪沖刷）震落顯露星紋；
// 3. 具備潛伏天命 (fate >= 1) 且先天靈性與悟性皆達極境 (spi >= 5 && int >= 5)。
int check_amnesia_breakthrough(object who, int required_fate) {
    if (!who) return 0;

    int player_fate = who->query(STAT_FATE);
    if (player_fate < 1) {
        return 0;
    }

    // 1. 天命已覺醒達標 (例如 required_fate == 2，玩家已透過奇遇提升至 fate >= 2)
    if (player_fate >= required_fate) {
        return 1;
    }

    // 2. 若天命尚處於潛伏期 (fate == 1 < required_fate)，需石垢青苔已被磨刀或洪水清除 (第1章正典途徑)
    object ws = find_object(WORLD_STATE_D);
    if (!ws) ws = load_object(WORLD_STATE_D);
    if (ws && ws->is_moss_cleared()) {
        return 1;
    }

    // 3. 或先天靈性與悟性皆達頂峰 (spi >= 5 && int >= 5)，可憑純粹靈覺感應逆行星軌
    if (who->query_stat("spi") >= 5 && who->query_stat("int") >= 5) {
        return 1;
    }

    return 0;
}
