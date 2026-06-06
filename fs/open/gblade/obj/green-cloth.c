inherit EQUIP;

void create()
{
        set_name("翠蘿衫", ({ "green cloth", "cloth" }) );
	set_weight(700);
        set("gender_only", "女性");
        set("long", "
翠綠質柔，女紅精巧，衣袖開口的地方，滾著淡淡的藍邊，拿在手裡讓你
有一種纖滑細膩的感覺。
\n");
        set("unit", "件");
        set("value",200);
        set("material", "cloth");
        set("armor_type", "cloth");
	set("armor_prop/armor", 3);
        setup();
}
