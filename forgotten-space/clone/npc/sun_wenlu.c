// /clone/npc/sun_wenlu.c
// 孫聞露・丹鼎宗醫理院病案女掌記 (sun_wenlu) - 醫理院暨病案封存室 (Ch.89, Ch.97)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("孫聞露");
    set_short(HIW "醫理院病案掌記" NOR " 孫聞露");
    set_long("二十六歲的年輕女醫官，懷中總抱著一疊厚實硬皮病案冊子，神色警覺卻又極重醫理良心。\n"
             "三年來她暗中保存著十餘份服用延命丹後長期病變的原始紀錄，只願交給嚴守病人隱私的醫者。\n");
    set_id(({ "sun_wenlu", "sun wenlu", "wenlu", "孫聞露", "孫師姐", "病案掌記" }));

    setup_archetype("F", 58);
    set("class", "gong");
    set("faction", "danding");
    set("roles", ({ "recorder", "healer", "quest" }));
    set("home_room", "/d/sects/danding/medical_archive.c");

    add_response(({ "病案", "統計", "延命丹", "保管鏈", "隔離區", "照護紀錄" }),
        "孫聞露臉色煞白地將你拉到無人角落的病案櫃後面，壓低聲線：「不要問病人的姓名與牌號，\n"
        "這三年我暗中留存了『甲一、乙三』等十七份匿名病案統計——所有服過那類暗紅丹丸者，\n"
        "前三個月道化晶簇確實看似停滯，第四個月起肝腎急速硬化（血煞癌變），一旦停藥逾七日便在\n"
        "三日內全身晶化破裂暴斃！（可在室中指令：crosscheck cases 進行病案統計互核）」");

    add_response(({ "血精", "邊界", "急鎮丸" }),
        "孫聞露鄭重點頭：「你在筆記背面寫下『目前樣本不足，不可跨山輕斷八荒急鎮丸成分』才真正像個大夫。\n"
        "白師伯交代過，先守住病人隱私，也守住自己的命，把樣本帶到山下信得過處對照。」");
}
