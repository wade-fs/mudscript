inherit EQUIP;
void create()
{
        set_name("幽冥臂環 ",({"ghost armband","armband"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","傳說此臂環，乃是葉秀殺在18歲時，進入煉妖壺中，所取得的\n");
        set("unit","個");
        set("value",10000);
        set("material","crimsonsteel");
        set("armor_type","armbands");
        set("armor_prop/armor",5);
        set("armor_prop/throwing",20);
        }
        setup();
}
