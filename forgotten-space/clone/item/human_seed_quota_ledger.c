// /clone/item/human_seed_quota_ledger.c
// 《石堡在籍火種補登清冊》 (Ch.142-143 Q1 核心因果憑證)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("石堡火種補登清冊", ({ "human_seed_quota_ledger", "quota ledger", "補登清冊", "配額總帳" }));
    set_short(HIY "九城鋼印・石堡在籍火種補登清冊" NOR);
    set_long("沈泥啟封九城離線補給總庫後，憑《平民避難配額總帳》逐戶核對並以三十斤高純鹽晶與\n"
             "十套活榫零件預押維護工時所補登之五十三戶在籍火種名冊，得於仲裁橋喚出『保全人類火種』條款。\n");
    set_weight(90);
    set_value(0);
    set("is_credential", 1);
    set("is_evidence", 1);
}
