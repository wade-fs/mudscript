// /clone/npc/bai_henian.c
// 白鶴年・丹鼎宗外聘醫理師 (bai_henian) - 百毒試藥谷暨百草谷 (Ch.89)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("白鶴年");
    set_short(HIG "丹鼎外聘醫理師" NOR " 白鶴年");
    set_long("曾任金石府城杏林醫館館主的老大夫，如今受聘為丹鼎宗醫理院外聘醫理師。\n"
             "他身著銀邊深青客卿袍，性情公私分明，即便面對昔日得意弟子顧玄亦不開半分後門。\n");
    set_id(({ "bai_henian", "bai henian", "doctor bai", "白鶴年", "白先生" }));

    setup_archetype("F", 72);
    set("class", "gong");
    set("faction", "danding");
    set("roles", ({ "examiner", "doctor", "quest" }));
    set("home_room", "/d/sects/danding/herb_garden.c");

    add_response(({ "試藥", "辟煞散", "驗針", "藥牌" }),
        "白鶴年拔出光潔如新的試毒銀針，神情嚴正公允：「不毀原根、借雪線苔化煞的溫火冷萃法，\n"
        "保全生機七成半而無半分火毒殘留，確實比今年諸多霸道焚煉之方穩妥。按規矩領百草谷外門藥牌，日後隨我多跑腿記錄真實病案。」");

    add_response(({ "冷萃", "考核", "辨偽" }),
        "白鶴年指著面前的十盤寒髓草：「醫者辨藥不可只盯成丹結果。若要通過此試，\n"
        "須先仔細察看藥材根鬚共生微苔，並以文火冷萃提取生機（指令：extract moss）。」");
}
