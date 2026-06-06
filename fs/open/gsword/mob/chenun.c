inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("張乘雲", ({"chen un","un"}));
	set("long","鄭士欣二第子,與其兄乘風同時進入仙劍派,乘雲在劍法上雖已明顯
落後於乘風,但說到內力深厚,仙劍派中除了掌門人鄭士欣,無人能及
乘雲項背,兄弟兩因行俠於江湖,而並稱風雲雙俠.乘雲平時負責看管
藏經閣.\n");
	set("gender","男性");
	set("guild_master",1);
	set("combat_exp",500000);
        set("attitude","heroism");
	set("age",43);
	set("class","swordsman");
	set("nickname","風雲雙俠");
	set("title","仙劍派第四代二弟子");
	create_family("仙劍派",4,"弟子");
	set("score",100000);
	set("force",1800);
	set("max_force",1800);
	set("force_factor",10);
	set_skill("sword",80);
	set_skill("dodge",80);
	set_skill("move",40);
	set_skill("parry",80);
	set_skill("literate",60);
	set_skill("force",100);
	set_skill("array",90);
	set_skill("blade",40);
	set_skill("unarmed",90);
	set_skill("staff",40);
	set_skill("throwing",40);
	set_skill("cure",40);
        set("str", 30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	setup();
	carry_object("/u/w/wugi/obj/sword-2")->wield();
	add_money("gold",5);
}

 int accept_fight(object me)
 {
 if((int)me->query("combat_exp")<=80000)
  {
  command("say 刀劍無眼,傷了你就不好了");
  return 0;
  }
  command("say 出招吧!");
  return 1;
  }
void attempt_apprentice(object ob)
{
	if(!ob->query_temp("allow_2"))
	{
	command("say 沒有師父的同意,我不敢擅自收徒!");
	return 0;
	}
	command("smile");
	command("say 既然是師父的意思,以後你就跟我好好學吧!");
	command("recruit "+ob->query("id"));
	ob->set("marks/仙劍七俠",1);
	}
