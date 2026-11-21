// cmds/cmd_set.c
// 玩家個人體驗偏好設定指令：set <選項> <0|1> / toggle <選項>

inherit "/std/object";

#include "/include/ansi.h"
#include "/include/globals.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        int bn = me->query("brief_numeric") ? 1 : 0;
        int bs = me->query("brief_sensory") ? 1 : 0;
        write(HIW "\n【個人閱讀與感官體驗設定】\n" NOR);
        write(sprintf("  1. brief_numeric (純感官模式・隱藏經驗/鍛鍊數字跳字) : %s\n",
                      bn ? HIG "開啟 (1)" NOR : WHT "關閉 (0，預設顯示)" NOR));
        write(sprintf("  2. brief_sensory (簡潔房景・隱藏身世額外感官濾鏡行)   : %s\n",
                      bs ? HIG "開啟 (1)" NOR : WHT "關閉 (0，預設顯示)" NOR));
        write(WHT "  用法：set brief_numeric 1   或   toggle brief_numeric\n\n" NOR);
        return 1;
    }

    string key, val_str;
    int val = -1;
    if (sscanf(arg, "%s %s", key, val_str) == 2) {
        key = lower_case(key);
        if (val_str == "1" || lower_case(val_str) == "on" || lower_case(val_str) == "true") val = 1;
        else if (val_str == "0" || lower_case(val_str) == "off" || lower_case(val_str) == "false") val = 0;
    } else {
        key = lower_case(arg);
        val = me->query(key) ? 0 : 1;
    }

    if (key != "brief_numeric" && key != "brief_sensory") {
        write("可設定項目僅支援：brief_numeric、brief_sensory。\n");
        return 1;
    }
    if (val == -1) {
        write("數值請輸入 1（開啟）或 0（關閉）。\n");
        return 1;
    }

    me->set(key, val);
    if (key == "brief_numeric") {
        write(val ? HIG "【已開啟純感官模式】修煉與歷練將改以純文字體感為主，隱藏經驗與鍛鍊度數字提示。\n" NOR
                  : CYN "【已恢復數值提示】將同時顯示經驗值、潛能與屬性鍛鍊進度數字。\n" NOR);
    } else {
        write(val ? CYN "【已開啟簡潔房景】看房間時將略過身世專屬感官觀察行。\n" NOR
                  : HIG "【已恢復身世感官濾鏡】進入關鍵場景時將呈現你的身世專屬物質線索。\n" NOR);
    }
    return 1;
}

string *query_verbs() {
    return ({ "set", "toggle", "偏好", "設定" });
}

string query_category() {
    return select_lang(([ "en": "System", "zh-TW": "系統", "zh-CN": "系統" ]));
}

string help() {
    return "【偏好設定指令】\n"
           "  set                         查看當前體驗設定\n"
           "  set brief_numeric 1|0       開啟/關閉純感官模式（隱藏經驗與鍛鍊數字提示）\n"
           "  set brief_sensory 1|0       開啟/關閉簡潔房景（隱藏額外身世感官線索）\n";
}
