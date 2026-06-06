inherit EQUIP;

void create()
{
        set_name("青絲軟甲", ({ "agraffe" }) );
        set_weight(3200);
        set("long", "
雖然是用金屬絲線打製成的，但是一點也不會影響身體的活動，能提供不
錯的保護能力。

\n");
        set("unit", "件");
	 set("value",10000);
        set("material", "steel");
        set("armor_type", "cloth");
	set("armor_prop/armor", 20);
	set("armor_prop/parry",2);
        setup();
}
