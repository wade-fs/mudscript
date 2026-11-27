// clone/item/dao_mirror.c
// 渾天黃銅鏡 - 宣道司觀象考核法器

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("渾天黃銅鏡", ({ "dao mirror", "brass mirror", "mirror", "渾天黃銅鏡", "黃銅鏡", "銅鏡" }));
    set_short(HIY "渾天黃銅鏡" NOR);
    set_long("宣道司摘星觀象台觀星師星淵交託的測風窺天法器。\n"
             "鏡背鑄有二十四節氣與周天星度環軌，鏡面打磨得平滑如水，能折射出肉眼難見的青河微氣候山嵐流向。\n");
    set_weight(600);
    set_value(500);
    set("is_quest_item", 1);
}
