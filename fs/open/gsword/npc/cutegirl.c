inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("何雙雙", ({"cute girl","girl"}));
	set("long","看到這天仙般的容貌 ,你簡直不敢相信 -- 她竟是仙劍六俠 .何雙
雙的身世除了鄭士欣外 ,無人知曉 ,只知道她四歲就入仙劍 .鄭士
欣一向對她言聽計從 .\n");
	set("gender","女性");
	set("combat_exp",500000);
        set("attitude","heroism");
	set("age",19);
	set("class","swordsman");
	set("title","仙劍派第四代六弟子");
	create_family("仙劍派",4,"弟子");
	set("score",100000);
	set("force",800);
	set("max_force",800);
	set("force_factor",10);
	set_skill("literate",60);
        set_skill("shasword",70);
        set_skill("shaforce",100);
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        map_skill("force","shaforce");
	set_skill("parry",70);
	set_skill("dodge",90);
	set_skill("sword",90);
	set_skill("move",100);
	set_skill("force",60);
	set_skill("array",80);
	set_skill("unarmed",40);
	set_skill("spells",60);
	set_skill("magic",60);
	set_skill("dagger",90);
	set("str",25);
        set("cor", 30);
	set("per", 40);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	setup();
	carry_object("/open/gsword/obj/sword-6")->wield();
	add_money("gold",5);
}

 int accept_fight(object me)
  {
  if((int)me->query("combat_exp")<=40000)
  {
   command("smile");
   command("say 不好吧 !");
   return 0;
  }
  command("say 好 ,我就領教你的高招 !");
  return 1;
  }
void attempt_apprentice(object ob)
{
	if(!ob->query_temp("allow_6"))
	{
	command("say 沒師父的同意,我不敢自做主張!");
	return 0;
	}
	command("blush");
	command("smile");
	command("say 以後可要乖乖聽師父的話喔 !");
	command("giggle");
	command("recruit "+ob->query("id"));
	ob->set("marks/仙劍七俠",1);
}
