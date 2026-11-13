// clone/item/stress_wedge.c
// 應力雙契木榫 - 盤木工藝特殊應力釋放工具

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("應力雙契木榫", ({ "stress wedge", "wedge", "muque", "木榫", "雙契木榫" }));
    set_short(HIW "【應力雙契木榫】" NOR);
    set_long("林鐵生依據盤木縣大木工匠應力平衡原理削製的雙向互鎖木榫。\n"
             "榫面平滑且具三十度斜切角，專門用於在高壓卡死的巨型絞盤與滑輪組中敲入受力點，\n"
             "利用槓桿與斜面機械原理安全釋放數千斤剪切應力，避免絞索與輪齒瞬間崩斷。\n");
    set_weight(200);
    set_value(50);
    set("is_stress_wedge", 1);
}
