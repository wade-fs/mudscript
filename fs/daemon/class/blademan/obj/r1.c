inherit EQUIP;

void create()
{
     set_name("魔刀袍",({"evil robe","robe"}));
   set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
以烏絲製成的黑袍,是魔刀門內弟子所穿之袍
\n");
        set("unit", "套");
	set("value",1000);
   set("material","cloth");
        set("armor_type", "cloth");
 set("armor_prop/armor",6);
         set("armor_prop/dodge", 2);
         set("armor_prop/blade", 1);
        }
        setup();
}
