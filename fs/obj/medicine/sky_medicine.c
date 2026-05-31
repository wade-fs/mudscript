// 建議由醫生來製此項藥丸
inherit F_MEDICINE;
void create()
{
        set_name("天靈丹", ({"sky pill","pill"}) );
        set("long","一顆晶瑩剔透的藥珠, 摸上去有一股清涼的氣勁衝擊著你的手。\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("value", 1000);
        set("base_weight", 100);
        set("eat_msg","$N將$n服下後,$N看起來似乎更有精神。\n");
        set("cure_type","sick");
        set("medicine_power",90);
        set_amount(1);
        setup();
}


