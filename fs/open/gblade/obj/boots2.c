inherit EQUIP;

void create()
{
        set_name("飛雲靴",({"flt-steps boots","boots"}) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "
一雙輕便的靴子，似乎不能提供什麼保護能力，但是如果你練過金刀門的
獨門輕功\的話......
\n");
        set("unit","雙");
	set("value",2000);
        set("material","cloth");
        set("armor_type","boots");
        set("armor_prop/dodge",7);
        }
        setup();
}
int wear()
{
     if ((string)this_player()->query_skill_mapped("dodge") !="fly-steps")
           return notify_fail("你不會想要穿一雙什麼防護力都沒有的鞋子吧？\n");
     else {
           ::wear();
          
          }
     return 1;
}

