inherit EQUIP;

void create()
{
         set_name("浴袍", ({"robe"}));
        set_weight(2800);
        set("long", "
 一件淋浴用的輕袍，看起來薄如蟬翼，若隱若現...。

\n");
        set("unit", "件");
     set("value", 5000);
        set("material", "cloth");
        set("armor_type", "cloth");
     set("armor_prop/armor", 10);
	set("dodge",3);
        setup();
}
