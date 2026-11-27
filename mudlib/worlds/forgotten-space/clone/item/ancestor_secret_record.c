// /clone/item/ancestor_secret_record.c
// 《三宗祖師密錄（封存抄頁）》（第三卷 Ch.124：十七位先輩單向入陣與無歸返證明缺口）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("三宗祖師密錄", ({ "ancestor_secret_record", "secret_record", "祖師密錄", "密錄" }));
    set_short(HIR "三宗聯署封印・《祖師密錄》抄頁" NOR);
    set_long("紫霄真人自太清偏峰封存觀測室玄鐵舊木匣中取出的千年黃紙殘錄抄件：\n"
             "載明太古大清洗後凡間法則宛如薄冰牢籠，歷史上共十七位不服延命壓制、修至\n"
             "Lv.100 觸動二十八宿天羅排斥雲層的先輩，曾啟動三宗祖庭地下千丈唯一完好之\n"
             "【桃花源單向古傳送陣】遁入光門。然最後一頁赫然明書：無一檔案證明彼輩平安\n"
             "落地對面、無證據說明門後究竟是避難所抑或更深屠宰場，且從無一人活著回來半步。\n");
    set_weight(200);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "conclusive");
}
