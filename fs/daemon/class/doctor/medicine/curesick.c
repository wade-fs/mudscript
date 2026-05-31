// 建議由醫生來製此項藥丸
inherit F_MEDICINE;

void create()
{
        set_name("冰心露", ({"ice heart pill","pill"}) );
        set("long","一顆晶瑩剔透的藥珠, 摸上去有一股清涼的氣勁衝擊著你的手。\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("value", 120000);
        set("base_weight", 100);
        set("eat_msg","$N將$n服下後, 頭腦變的清醒多了, 似乎更有精神的樣子。\n");
        set("cure_type","sick");
        set("medicine_power",80);
        set_amount(1);
        setup();
}

