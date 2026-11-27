// /clone/npc/yu_shouzhuo.c
// 余守拙・太清藏星秘閣守閣老吏 (yu_shouzhuo) - 藏星秘閣 (Ch.91, Ch.99)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("余守拙");
    set_short(CYN "藏星秘閣檔案老吏" NOR " 余守拙");
    set_long("六十八歲的駝背老吏，左眼微顯渾濁，手中總捏著一柄黃銅放大鏡，已在藏星秘閣守檔\n"
             "整整四十二年。他只認紙張織紋、松煙牛膠與檔案保管章程，不願妄談天機玄論。\n");
    set_id(({ "yu_shouzhuo", "yu shouzhuo", "shouzhuo", "余守拙", "檔案老吏", "老吏" }));

    setup_archetype("F", 64);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "archivist", "scholar", "quest" }));
    set("home_room", "/d/sects/taiqing/hidden_archive.c");

    add_response(({ "原始星圖", "紫微星官錄", "紙墨", "差異清單" }),
        "余守拙舉起黃銅放大鏡照過書脊，嗓音低得像砂紙摩擦：「三十年前紫霄殿曾下令重抄『校順』舊檔，\n"
        "說是原卷數字雜亂會讓外門弟子起疑動搖道心……三百年前那版定本用了百年後才流行的南境青檀宣紙與魚鰾膠，\n"
        "把整片甲子冬至星象都順時針『平推了一度半』。記住：紙墨差寫進草稿就好，千萬別寫進送去執法殿的彙報！」");

    add_response(({ "廢頁", "舊箱", "四禁", "蟲蛀舊箱" }),
        "余守拙朝門外張望一眼，指了指西邊最底層：「未經登錄的原測廢頁當年沒燒盡，按年份全塞在那只蟲蛀舊箱裡。\n"
        "只許用炭筆與分規抄數（指令：collate archive），不許點火折子、不許撕頁、不許動牆上的老祖宗星盤。」");
}
