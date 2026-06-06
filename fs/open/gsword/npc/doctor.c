#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("王藥師",({"doctor wang","doctor","wang"}));
	set("long","一個斯斯文文的中年人 ,王藥師於四 ,五年前於森林中遭遇
盜賊 ,幸逢張乘風經過 ,得以安然無恙 ,王藥師為報答救命
之恩 ,自願來到仙劍幫忙,你可以看看他有些甚麼藥(list).\n");
	set("gender","男性");
	set("combat_exp",6200);
	set("attitude","friendly");
	set("age",41);
	set("class","doctor");
	set("str",25);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
        set("vendor_goods", ({
                GS_OBJ"g_pill",
//              GS_OBJ"g_pill_10",
//  不用這個了..
        }) );
	set_skill("unarmed",50);
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("cure",40);
	set_skill("literate",40);
	setup();
	carry_object("/open/gsword/obj/robe_2")->wear();
	add_money("silver",5);
}
