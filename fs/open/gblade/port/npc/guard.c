// /open/center/npc/vendor.c
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("楓林港守衛", ({ "guard" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long", @LONG
由京城千挑萬選的精良守衛 , 負責維護港口的治安
看他們個個虎臂熊腰 , 你還是別在此惹事為妙 ! 
LONG);
	set("attitude", "friendly");
	set("combat_exp",10000);
	set_skill("dodge",50);
	set_skill("blade",50);
	set_skill("parry",50);
	set("chat_chance",10);
	set("chat_msg",({
	"楓林港守衛得意洋洋的說道 : 哼 ! 老子一來 ,盜賊還不是乖乖的洗手收山 !\n",	
	}));
	set("greeting_msg", ({
 	    "楓林港守衛對你喝道 : 別想在此做些不良勾當 !\n",
	    "楓林港守衛以懷疑的眼光對著你看 !\n", 
	    	}) );
	set("pursuer",1);
	setup();
	carry_object("/open/gblade/port/obj/guard_blade")->wield();
	carry_object("/open/gblade/port/obj/guard_armor")->wear();
	carry_object("/open/gblade/port/obj/guard_boots")->wear();
        add_money("silver",5);        
	
}
