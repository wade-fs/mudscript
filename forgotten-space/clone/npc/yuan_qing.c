// /clone/npc/yuan_qing.c
// 元青・太清清修偏峰早期晶化老弟子 (yuan_qing) - 清修偏峰 (Ch.111)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("元青");
    set_short(CYN "偏峰閉關老弟子" NOR " 元青");
    set_long("修為達二階七十三重的太清老弟子，半年前在觀星台輪值夜觀時不慎被九天星力滲透經絡。\n"
             "此刻他左臂兩根手指與半截小臂皮膚下隱見凝固般的青白微光，卻咬牙死守簡素真人清規，\n"
             "寧可在偏峰厚棉簾後靠柴火硬熬寒氣，也絕不肯吞下執法殿送來的半顆暗紅丸藥。\n");
    set_id(({ "yuan_qing", "yuan qing", "yuanqing", "元青", "老弟子" }));

    setup_archetype("G", 73);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "patient", "witness" }));
    set("home_room", "/d/sects/taiqing/quiet_peak.c");

    add_response(({ "晶絲", "小臂", "三元", "試治", "三日後" }),
        "元青伸出左臂掀起半截褪色袖口，指腹僵冷毫無溫度，苦笑嘆道：\n"
        "「兩指僵了半年，執法堂說只要簽字領一瓶暗紅丸藥就能重回雲頂……簡素長老說得對，\n"
        "那債還不起！簡素師叔既約定了會武前三日子時，若諸位真能帶齊針藥齒輪把這股陰冷晶絲抽出來\n"
        "而不傷我全臂性命，我元青這條老命便隨師叔親上問道天台作個證人！」");

    add_response(({ "簡素", "紅藥丸", "觀星台" }),
        "元青搖頭望向柴扉外枯松：「吃過那丸藥的幾位內門師弟，頭三月確實氣色紅潤，可後來夜裡連神識都不安生。\n"
        "我寧願就這麼僵著兩根指頭，等個光明正大、不用拿旁人血命來填的活法。」");
}
