inherit EQUIP;
void create()
{
set_name("殺手練習服",({"trainee cloth","cloth"}));
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","殺手的基本裝備，防禦力並不高");
        set("unit", "套");
        set("value",5000);
        set("material","steel");
        set("armor_type", "cloth");
        set("armor_prop/armor",10);
        set("armor_prop/dodge",6);
        set("armor_prop/parry",4);
        }
        setup();
}
