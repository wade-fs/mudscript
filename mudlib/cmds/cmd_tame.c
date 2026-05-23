// /cmds/cmd_tame.c
// 馴服指令：將野外生物收為寵物

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("你要馴服什麼？用法：tame <對象>\n");
        return 1;
    }

    object here = environment(me);
    object target = present(arg, here);

    if (!target) {
        write("這裡沒有叫「" + arg + "」的東西。\n");
        return 1;
    }

    if (!living(target) || userp(target)) {
        write("你無法馴服這個對象。\n");
        return 1;
    }

    if (!target->query_tamable()) {
        write(target->query_name() + " 野性難馴，無法被收服。\n");
        return 1;
    }

    if (me->query_pet()) {
        write("你已經有一隻寵物了，請先解散當前的寵物。\n");
        return 1;
    }

    int skill = me->query_skill("taming");
    if (skill <= 0) {
        write("你完全不懂馴獸之道，根本無從下手。\n");
        return 1;
    }

    // 馴服難度：跟對方的血量百分比有關
    int hp_pct = target->query_hp() * 100 / target->query_max_hp();
    
    if (hp_pct > 30) {
        write(target->query_name() + " 體力充沛，正瘋狂反抗你的馴服！\n");
        write("提示：先削弱對方的生命力（低於 30%）會更容易成功。\n");
    }

    write("你開始嘗試馴服 " + target->query_name() + "...\n");
    say(me->query_name() + " 開始對 " + target->query_name() + " 進行馴服。\n");

    // 成功機率公式：(技能等級 / 2) + (30 - HP百分比)
    int chance = (skill / 2) + (30 - hp_pct);
    if (chance < 5) chance = 5; // 基本保底 5%
    if (chance > 95) chance = 95; // 最高 95%

    if (random(100) < chance) {
        write(HIG("成功了！") + target->query_name() + " 溫順地低下了頭，認你為主。\n");
        say(target->query_name() + " 認 " + me->query_name() + " 為主人了。\n");
        
        // 🚀 關鍵轉換：將 NPC 轉為 Pet 物件
        string base = base_name(target);
        object pet = clone_object("/std/pet.c");
        if (pet) {
            // 複製屬性 (這裡簡化處理，實際可能需要更複雜的屬性繼承)
            pet->set_name(target->query_name());
            pet->set_id(target->query_id());
            pet->set_level(target->query_level());
            pet->set_owner(me);
            me->set_pet(pet);
            
            // 銷毀原 NPC
            destruct(target);
            move_object(pet, here);
        }
        me->improve_skill("taming", 10);
    } else {
        write("馴服失敗了，" + target->query_name() + " 變得更加憤怒！\n");
        target->attacked_by(me);
        me->improve_skill("taming", 2);
    }

    me->save();
    return 1;
}

string help() {
    return "【指令】\n" +
           "  tame <對象>    嘗試收服虛弱的野外生物作為寵物。\n" +
           "  (提示：對象血量越低，成功率越高)\n";
}
