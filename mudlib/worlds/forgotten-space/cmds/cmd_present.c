// cmds/cmd_present.c
// 物證主動出示與互相印證指令：present <物證> to <NPC> | show <物證> to <NPC> | 出示 <物證> to <NPC>

inherit "/std/object";

#include "/include/ansi.h"
#include "/include/globals.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("你要出示什麼物證給誰？用法：present <物證> to <目標NPC>（或 show <物證> <目標NPC>）\n");
        return 1;
    }

    string item_id, npc_id;
    if (sscanf(arg, "%s to %s", item_id, npc_id) == 2 && item_id != "" && npc_id != "") {
        // present <item> to <npc>
    } else if (sscanf(arg, "%s %s", item_id, npc_id) == 2 && item_id != "" && npc_id != "") {
        // present <item> <npc>
    } else {
        write("請指定要出示的物證與對象，例如：present detonator_serial_ledger to qin_zhengming\n");
        return 1;
    }

    object here = environment(me);
    if (!here) {
        write("你身處虛空，無從出示物證。\n");
        return 1;
    }

    object ev_ob = present(item_id, me);
    if (!ev_ob) {
        write("你身上沒有「" + item_id + "」這件物證或物品。\n");
        return 1;
    }

    object npc = present(npc_id, here);
    if (!npc || !living(npc)) {
        write("這裡沒有「" + npc_id + "」這個人可以檢視你的物證。\n");
        return 1;
    }

    tell_object(me, sprintf(CYN "你慎重地取出 %s，呈遞到 %s 面前請求查驗……\n" NOR, ev_ob->query_short(), npc->query_name()));
    tell_room(here, sprintf("%s 取出 %s，呈遞給 %s 查驗。\n", me->query_name(), ev_ob->query_short(), npc->query_name()), ({ me }));

    object city_d = load_object(CITY_D);
    if (city_d) {
        mapping res = city_d->present_evidence_to_npc(me, ev_ob, npc);
        if (mapp(res) && res["msg"]) {
            tell_object(me, res["msg"] + "\n");
        }
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        string tid = npc->query("id");
        if (!tid || tid == "") tid = npc_id;
        qe->trigger_event(me, "present", ([
            "item": city_d ? city_d->normalize_evidence_id(ev_ob, item_id) : item_id,
            "npc": tid,
            "item_obj": ev_ob,
            "npc_obj": npc
        ]));
    }

    return 1;
}

string *query_verbs() {
    return ({ "present", "show", "出示", "呈遞" });
}

string query_category() {
    return select_lang(([ "en": "Social", "zh-TW": "社交", "zh-CN": "社交" ]));
}

string help() {
    return "【出示物證指令】\n"
           "  present <物證> to <NPC>   向特定人物主動出示手中的帳冊、地契或物證\n"
           "  show <物證> to <NPC>      同 present\n\n"
           "  說明：\n"
           "  - 單一孤證往往難以扳倒高層勢力；若連續出示可互相印證的多源物證（如雷管批號＋耐火泥／坩堝＋礦工血手印，或暗渠底單＋保管帳冊），將觸發【交叉印證・信任質變】！\n"
           "  - 若物證因落水或保管不當受污染 (contaminated)，須先出示給文承敬主簿或杏林白先生重新公證封存。\n";
}
