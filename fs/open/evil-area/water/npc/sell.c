inherit F_VENDOR;

void create()
{
	set_name("毛蠱",({"hair worm","worm"}));
	set("long","
它是琰揚湖內唯一一個能與人類溝通的蠱蟲，它精通各類煉丹之術，
你甚至於可以跟她進行買賣，聽說它有販賣一種能消除死去蟲子遺留
在你身上味道的丹藥。\n");
	set("age",1782);
	set_skill("unarmed",100);
	set_skill("move",100);
	set_skill("dodge",100);
	set_skill("force",100);
        set("gender", "中性" );
	set("kar",10);
	set("per",10);
	set("str",10);
	set("cor",10);
	set("int",30);
	set("combat_exp",100000);
	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);
	set("max_force",100000);
        set("force_factor",10);
        set("vendor_goods", ({
		"/open/evil-area/npc/obj/enemy_pill",
		"/open/evil-area/npc/obj/damage_pill",
		"/open/evil-area/water/npc/obj/d_pill",
        }) );
	setup();
}




void greeting(object ob)
{

        if( !ob || environment(ob) != environment() )
		return;
	if( ob->query_temp("evil/water/killed") )
		command("say 罪孽深重的人啊...你為何殘殺我類之族民ㄋ...。\n");
	else
		command("say 你來這作什麼...這裡沒有你想要的東西...\n");
	command("say 好吧...這裡也許\有些東西你想要...我對於人類那金黃色的東西還滿感興趣的。\n");
	command("say 如果你想跟我買東西，就拿那些黃金跟我交易吧...\n");
}
