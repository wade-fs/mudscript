// mudlib/std/corpse.c
// 屍體物件：所有生物死後產生的遺留物

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/container.c";

void create() {
    ::create();
    set_name("無名屍體");
    set_short("一具無名屍體");
    set_long("這是一具死後的屍體，看起來有些蒼白。\n");
    set_id(({"corpse", "corpse_id", "屍體", "死體"}));
    
    // 預設 10 秒後自動消失
    call_out("destruct_me", 10);
}

// 設定是誰的屍體
void set_owner(string owner_name) {
    set_name(owner_name + " 的屍體");
    set_short(owner_name + " 的" + RED("死體"));
    set_long("這是一具 " + owner_name + " 的屍體，隨著時間流逝正在漸漸變冷。\n");
}


void destruct_me() {
    object env = environment(this_object());
    if (env) {
        tell_room(env, "一陣微風吹過，" + query_short() + " 化作塵土消失了。\n");
    }
    destruct(this_object());
}

// 屍體不允許其他生物進入 (除非是寄生蟲？但目前不考慮)
int can_receive(object ob) {
    if (!ob) return 0;
    if (living(ob)) return 0;
    return ::can_receive(ob);
}
