inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
	set_name("林靜詩", ({"lin chin-shin", "lin"}));
	set("long","
    她就是金風細雨樓副樓主，人稱江湖第一美人的林靜詩。
林靜詩的外表，迷倒了多少江湖俠士，他那一雙眼眸，比燈還亮
彷彿像一個深湖，浮漾著千古流雲的夢。\n");
	set("gender","女性");
	set("combat_exp",1000000);
        set("attitude","heroism");
	set("age",21);
	set("class","swordsman");
	set("title","仙劍派第四代女劍俠");
        set("nickname",HIW"東城飛雪"NOR);
	create_family("仙劍派",4,"弟子");
	set("score",100000);
        set("kee",3000);
        set("max_kee",3000);   
	set("force",13000);
    set("max_force",6000);
	set("force_factor",10);
	set_skill("literate",100);
	set_skill("parry",120);
	set_skill("dodge",90);
        set_skill("sha-steps",1000);
	set_skill("force",50);
	set_skill("sword",80);
	set_skill("move",80);
	set_skill("array",70);
	set_skill("cure",50);
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        map_skill("force","shaforce");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("array","sha-array");
	set("str",30);
        set("cor",30);
	set("per",30);
	set("int",40);
	set("cps",30);
	set("con",30);
	set("spi",35);
	set("kar",30);
	setup();
//carry_object("/open/capital/wind-rain/obj/butterfly-cloth")->wear();
        //carry_object("/open/gsword/obj/may_ring")->wear();
	add_money("gold",5);
}
int accept_fight(object me)
{
  if((int)me->query("combat_exp")<=60000)
 {
    command("say 身體髮膚,受之父母,要好好愛惜啊!");
    return 0;
 }
    command("say 點到為止唷...");
    return 1;
}
