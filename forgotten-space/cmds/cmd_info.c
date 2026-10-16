// mudlib/cmds/cmd_info.c
// 資訊指令守護進程：score / status

#include "/include/ansi.h"
#include "/include/globals.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    string pk_str = select_lang((["en": "Normal", "zh-TW": "普通", "zh-CN": "普通"]));
    if (me->is_red_name()) {
        pk_str = select_lang((["en": "Red Name", "zh-TW": "紅名", "zh-CN": "红名"]));
    }

    string bg_key = me->query("background");
    string bg_name = "一般凡人";
    if (bg_key && BACKGROUND_DATA[bg_key]) {
        bg_name = BACKGROUND_DATA[bg_key]["name"];
    }

    // 1. 建立角色數值資料
    mapping data = ([
        "name" : me->query_name(),
        "background": bg_name,
        "level": me->query_level(),
        "exp"  : me->query_exp(),
        "exp_to_next": me->query_exp_to_next(),
        "hp"   : me->query_hp(),
        "max_hp": me->query_max_hp(),
        "mp"   : me->query_mp(),
        "max_mp": me->query_max_mp(),
        "sp"   : me->query_sp(),
        "max_sp": me->query_max_sp(),
        "money": me->query_money_plain(),
        "pk"   : pk_str,
        "atk"  : me->query_attack(),
        "def"  : me->query_defence(),
        "str"  : me->query_stat("str"),
        "con"  : me->query_stat("con"),
        "int"  : me->query_stat("int"),
        "spi"  : me->query_stat("spi"),
        "dex"  : me->query_stat("dex"),
        "per"  : me->query_stat("per"),
        "label_hp": _t("label_hp"),
        "label_mp": _t("label_mp"),
        "label_sp": _t("label_sp"),
        "label_wealth": _t("label_wealth"),
        "label_atk": _t("label_atk")
    ]);

    // 2. 建立指令清單 (從 command_d 動態取得，避免被截斷)
    object cmd_d = load_object("/secure/command_d");
    mapping cmds = ([]);
    if (cmd_d) {
        cmds = cmd_d->query_categorized_commands(me->query_lang());
        
        // 如果不是巫師，過濾掉管理類別
        if (me->query_role() != "god" && me->query_role() != "wizard") {
            object lang_d = load_object("/secure/language_d.c");
            string admin_cat = lang_d->translate("cat_admin", me->query_lang());
            m_delete(cmds, admin_cat);
        }
    } else {
        // 備援：若抓不到 daemon 則顯示簡易版
        cmds = ([
            _t("cat_basic") : ({ "look", "inventory", "score", "help" })
        ]);
    }

    // 3. 組合完整的 UI 更新封包或純文字輸出
    if (is_web_client(me)) {
        string score_payload = sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data));
        string cmd_payload = sprintf("{\"ui\": \"cmd_list\", \"title\": \"%s\", \"data\": %s}", _t("cmd_list"), json_encode(cmds));
        
        // 🚀 使用 tell_object 確保訊息發送給正確的玩家連線，
        // 且不會在背景更新時（沒有 player context）噴到 server console。
        tell_object(me, score_payload);
        tell_object(me, cmd_payload);
    } 
    
    // 只有當玩家主動輸入指令 (如 score, status) 時，才顯示文字版
    // 如果 verb 為空或 score_quiet (代表由 UI 背景刷新)，則不顯示文字
    if (verb && verb != "" && verb != "score_quiet") {
        write("\n" + "$HIW$【角色資訊】 " + data["name"] + "$NOR$" + "\n");
        write(sprintf("  %-10s : %s\n", "身世背景", bg_name));
        write(sprintf("  %-10s : %d (歷練經驗: %d / %d)\n", "等級", data["level"], data["exp"], data["exp_to_next"]));
        write(sprintf("  %-10s : %d / %d\n", data["label_hp"] + "(kee)", data["hp"], data["max_hp"]));
        write(sprintf("  %-10s : %d / %d\n", data["label_mp"] + "(sen)", data["mp"], data["max_mp"]));
        write(sprintf("  %-10s : %d / %d\n", data["label_sp"] + "(sp)", data["sp"], data["max_sp"]));
        write(sprintf("  %-10s : %s\n", data["label_wealth"], data["money"]));
        write(sprintf("  %-10s : %d  |  %-10s : %d\n", "攻擊力", data["atk"], "防禦力", data["def"]));
        write("$CYN$── 先天六維屬性 (鍛鍊進度) ──$NOR$\n");
        write(sprintf("  %-10s : 臂力 %-2d (%d/%d)   根骨 %-2d (%d/%d)\n", "【力之柱】",
            me->query_stat("str"), me->query_stat_train("str"), me->query_stat_train_req("str"),
            me->query_stat("con"), me->query_stat_train("con"), me->query_stat_train_req("con")));
        write(sprintf("  %-10s : 悟性 %-2d (%d/%d)   靈性 %-2d (%d/%d)\n", "【法之柱】",
            me->query_stat("int"), me->query_stat_train("int"), me->query_stat_train_req("int"),
            me->query_stat("spi"), me->query_stat_train("spi"), me->query_stat_train_req("spi")));
        write(sprintf("  %-10s : 靈巧 %-2d (%d/%d)   感知 %-2d (%d/%d)\n", "【物之柱】",
            me->query_stat("dex"), me->query_stat_train("dex"), me->query_stat_train_req("dex"),
            me->query_stat("per"), me->query_stat_train("per"), me->query_stat_train_req("per")));
        write("\n");
    }
    
    return 1;
}

string *query_verbs() {
    return ({ "info", "score", "status", "score_quiet" });
}

string query_category() {
    return select_lang(([ "en": "View", "zh-TW": "查看", "zh-CN": "查看" ]));
}

string help() {
    return select_lang(([
        "en": "【Status Commands】\n  score / status  View detailed character status, including HP, MP, level and attributes.\n",
        "zh-TW": "【狀態指令】\n  score / status  查看角色的詳細狀態資訊，包含 HP、MP、等級與屬性。\n",
        "zh-CN": "【状态指令】\n  score / status  查看角色的详细状态资讯，包含 HP、MP、等级与属性。\n"
    ]));
}
