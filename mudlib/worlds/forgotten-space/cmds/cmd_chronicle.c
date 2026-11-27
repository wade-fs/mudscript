// cmds/cmd_chronicle.c
// 世界紀事與歷史回放指令（觀察者模式 / 小說幕次查閱）：chronicle | history | replay | 史碑 | 紀事

inherit "/std/object";

#include "/include/ansi.h"
#include "/include/globals.h"
#include "/include/world_event.h"

int main(object me, string verb, string arg) {
    object em = load_object(EVENT_MANAGER_D);
    if (!em) {
        write("事件守護進程尚未就緒。\n");
        return 1;
    }

    string target_ev = "";
    if (arg && arg != "") {
        string lc = lower_case(arg);
        if (lc == "beast" || lc == "beast_surge" || strsrch(arg, "煞潮") != -1 || strsrch(arg, "獸潮") != -1) {
            target_ev = EVENT_BEAST_SURGE;
        } else if (lc == "military" || lc == "military_crisis" || strsrch(arg, "黑石關") != -1 || strsrch(arg, "軍事") != -1) {
            target_ev = EVENT_MILITARY_CRISIS;
        } else if (lc == "tier2" || lc == "tier2_crisis" || strsrch(arg, "北荒") != -1 || strsrch(arg, "三宗") != -1) {
            target_ev = EVENT_TIER2_CRISIS;
        }
    }

    if (target_ev != "") {
        write(em->query_event_replay_summary(target_ev));
        return 1;
    }

    string *all_evs = ({ EVENT_BEAST_SURGE, EVENT_MILITARY_CRISIS, EVENT_TIER2_CRISIS });
    write(HIW "\n================【《遺忘的世界》歷史紀事與幕次總覽】================\n" NOR);
    foreach (string eid in all_evs) {
        mapping act = em->query_novel_act_info(eid);
        string st = em->query_event_stage(eid);
        mapping contribs = em->query_player_contributions(eid);
        write(sprintf(HIY "  ● %s (%s)\n" NOR, act["act_title"], act["chapter_span"]));
        write(sprintf("    階段：%s | 先行者署名人數：%d\n", st ? st : "未知", sizeof(contribs)));
        write(sprintf(CYN "    世局法則：%s\n" NOR, act["world_task_modifier"]));
    }
    write(WHT "----------------------------------------------------------------------\n"
              "  提示：輸入 `chronicle beast`、`chronicle military` 或 `chronicle tier2` 可查閱單一事件完整歷史回放與貢獻榜。\n"
              "======================================================================\n" NOR);
    return 1;
}

string *query_verbs() {
    return ({ "chronicle", "history", "replay", "史碑", "紀事", "回放" });
}

string query_category() {
    return select_lang(([ "en": "View", "zh-TW": "查看", "zh-CN": "查看" ]));
}

string help() {
    return "【歷史回放與幕次紀事指令】\n"
           "  chronicle                 查看世界當前所處小說卷幕與三大重大事件概要\n"
           "  chronicle beast|military|tier2  查看特定世界事件的歷史軌跡與先行者貢獻榜\n";
}
