// daemon/career_d.c
// 《遺忘的世界》三大道統鏈式閉合任務守護進程 (CAREER_D)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

void create() {
    ::create();
}

// 取得玩家在某道統 (fa / li / wu) 之當前鏈式任務階段
int query_chain_stage(object who, string path_type) {
    if (!who) return 0;
    return who->query("task_chain/" + path_type + "_stage");
}

// 推進玩家之鏈式任務
void advance_chain_stage(object who, string path_type) {
    if (!who) return;
    int current = who->query("task_chain/" + path_type + "_stage");
    current++;
    if (current > 4) {
        // 完成一整輪閉環，重置為 1，並發放傳承聲望
        current = 1;
        who->add("affinity/" + path_type, 10);
        tell_object(who, HIY "【恭喜完成一整輪生計閉環歷練，你對此道的領會更深了，傳承好感度提升！】\n" NOR);
    }
    who->set("task_chain/" + path_type + "_stage", current);
}
