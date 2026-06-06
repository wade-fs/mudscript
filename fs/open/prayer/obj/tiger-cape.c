inherit EQUIP;

void create()
{
        set_name("虎頭肩",({"tiger cape","cape"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","以邪虎的虎頭做為裝飾的護肩, 能增強身體上的防禦度 .\n");
        set("unit","件");
        set("value",6000);
        set("material","leather");
        set("armor_type","cape");
        set("armor_prop/armor", 1);
        }
        setup();
}                        
