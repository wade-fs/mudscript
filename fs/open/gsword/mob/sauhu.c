inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("趙鶴", ({"sau hu", "hu"}));
	set("long","鄭士欣第四愛徒,趙鶴原是一名書生,曾中過舉人,在23歲時因考進士
落第,憤而盡毀其書,學劍於鄭士欣,趙鶴因入門較晚,因此年紀比師兄
們都大,平時趙鶴負責傳弟子們劍訣,因其學識淵博,仙劍派弟子往往能
很容易的理解其中函意,仙劍派近年來之所以如此興盛,趙鶴也貢獻良多.\n");
	set("gender","男性");
	set("combat_exp",500000);
        set("attitude","heroism");
	set("guild_master",1);
	set("age",52);
	set("class","swordsman");
	set("title","仙劍派第四代四弟子");
	create_family("仙劍派",4,"弟子");
	set("score",100000);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",10);
	set_skill("literate",100);
	set_skill("parry",60);
	set_skill("dodge",80);
	set_skill("force",90);
	set_skill("sword",80);
	set_skill("move",40);
	set_skill("array",80);
	set_skill("blade",40);
	set_skill("unarmed",40);
	set_skill("whip",60);
	set_skill("spells",40);
	set_skill("cure",60);
	set_skill("stabber",90);
	set("str",25);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	setup();
	carry_object("/u/w/wugi/obj/sword-4")->wield();
	add_money("gold",5);
}
  int accept_fight(object me)
  {
  if((int)me->query("combat_exp")<=60000)
   {
    command("say 身體髮膚,受之父母,要好好愛惜啊!");
    return 0;
    }
    command("say 領教高招");
    return 1;
    }
void attempt_apprentice(object ob)
{
	if(!ob->query_temp("allow_4"))
	{
	command("say 沒師父的允許\,我不敢自做主張!");
	return 0;
	}
	command("smile");
	command("say 既然是師父的意思,我就收你為徒!");
	command("recruit "+ob->query("id"));
	ob->set("marks/仙劍七俠",1);
}
