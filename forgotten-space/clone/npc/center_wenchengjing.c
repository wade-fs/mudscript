// clone/npc/center_wenchengjing.c
// 府衙案牘主簿 文承敬 - 沈泥身世暗線核心交涉人物

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("文承敬");
    set_short(WHT "府衙案牘主簿" NOR " 文承敬");
    set_long("一位身穿半舊青布官袍、面容清瘦沉穩的案卷主簿。\n"
             "他戴著一副玳瑁眼鏡，長年掌管金石府庫數十年的戶籍底單與舊案舊契，\n"
             "眼神中透著對前朝興廢與世道炎涼的深沉洞察。\n");
    set_id(({ "wenchengjing", "wen", "archivist", "文承敬", "主簿" }));

    set_level(20);
    set_stat("int", 35);
    set_stat("per", 30);
    recalc_stats();

    add_response(({ "舊案", "底單", "三十年前", "清洗" }),
        "文承敬推了推玳瑁鏡框，低語道：「三十年前大乾殘政崩解，金石舊商盟分崩離析……案卷庫積灰三尺，許多塵封舊事，莫要輕易驚動為妙。」");

    add_response(({ "沈泥", "沈雲妮", "玉佩", "天門引" }),
        "文承敬神色微變，警惕環視四周，壓低聲音：「雲妮？三十年前沈氏旁支的舊賬單……若持血親信物與古令，老夫或可暗中為你調取殘卷底單。」");
}
