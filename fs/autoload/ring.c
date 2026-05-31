inherit EQUIP;

void create()
{
        set_name("[1m[37m結婚戒指[0m", ({ "wedding ring", "ring"  }) );


	set_weight(1200);
  if(clonep())
        set_default_object(__FILE__);
else {

        set("unit", "只");
        set("long", "象徵永恆堅定的結婚戒指，獻給這受上天祝福的兩人。\n");
	set("armor_type", "finger2");
	set("armor_prop/armor", 5 );
	set("material", "pearl");// 相當於 ??, 對重量跟價值有用
	set("no_drop",1);
	set("no_sell",1);
	set("no_give",1);
	set("no_put",1);
	set("no_get",1);
	set("light_up",-1);
	set("value",999);
}
	setup();
}

int query_autoload()
{
  return 1;
}
