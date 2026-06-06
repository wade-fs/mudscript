// 鑰匙, 有鎖的房間請到 /u/w/wade/workroom 參考
inherit ITEM;

void create()
{
        set_name("赤火令", ({ "firer" }) );
        set("unit", "隻");
        set("long", "這是一隻令牌，上面刻有聖火的圖樣。\n");
        set_weight(500);
        set("value",0);
}
