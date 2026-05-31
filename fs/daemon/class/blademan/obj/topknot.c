inherit EQUIP;

void create()
{
        set_name("五鳳掛珠釵",({"topknot"}) );
        set_weight(800);
        if( clonep() )
 set_default_object(__FILE__);
 else {
        set("long","
用金子打成的髮飾，一端掛著一顆珍珠，珍珠隱隱的散發迷人的光澤，隨
著身體的搖擺\而晃動著。
\n");
        set("unit","枝");
        set("gender_only", "女性");
	set("value", 4000);
        set("material","gold");
        set("armor_type","head");
	set("armor_prop/armor",6);
	set("armor_prop/dodge",1);
 }
        setup();
}
