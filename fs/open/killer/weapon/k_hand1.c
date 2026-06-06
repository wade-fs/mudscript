inherit EQUIP;
void create()
{
set_name("專業殺手手套",({"killer hands","hands"}));
set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","特別製成的手套 , 能大量提高本身的作戰能力");
        set("unit", "雙");
set("value",4000);
        set("material","cloth");
set("armor_type", "hands");
        set("armor_prop/throwing",2);
        set("armor_prop/parry",2);
        set("armor_prop/armor",4);
        }
        setup();
}
