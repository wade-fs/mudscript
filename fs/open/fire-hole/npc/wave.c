//by frequency
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("浪清心",({"wave heart","wave","heart"}));
        set("long",@LONG

        聖火教皇--林宏昇所收的第一位弟子，傳說其與生俱來的天份
        遠遠超過包括林宏昇在內的歷代教皇，可惜在與夜夢雙妖之戰
        中殉教身亡。

LONG);
        set("gender","男性");
        set("clan_kill",1);
        set("class","prayer");
        set("family/family_name","聖火教");
        set("nickname",HIC"鬥心不滅"NOR);
        set("title",RED"教皇"HIY"御前第一傳人"NOR);
        set("combat_exp",6900000);
        set("attitude","friendly");
        set("score",1000000);
        set("age",47);
        set("max_kee",100000);
        set("str", 50);
        set("cor", 50);
        set("cps", 45);
        set("int", 42);
        set("marks/tengin",1);
        set("max_force",20000);
        set("force",90000);
        set("force_factor", 10);
        set("max_gin",90000);
        set("max_sen",90000);
        set_skill("superforce", 260);
        set_skill("dodge", 120);
        set_skill("force",150);
        set_skill("move", 120);
        set_skill("literate",120);
        set_skill("parry", 120);
        set_skill("unarmed",120);
        set_skill("canon",150);
        set_skill("literate",120);
        set_skill("shift-steps",150);
        set_skill("universe",140);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/white/level",50);
        set("functions/ice/level",50);
        set("functions/purple/level",50);
        set("functions/goldsun/level",150);
        set("functions/green/level",150);
        set("functions/gen/level",50);
        set("functions/nine/level",50);
        set("functions/blood/level",150);
        set("functions/tengin/level",100);
        set("functions/bluesea/level",100);
        set("functions/supertengin/level",120);
        set("env/天驚地動",5);
	set("env/superforce","blood");
	set("env/連擊","YES");
	set("advance_prayer",1);
        setup();

        carry_object("/open/prayer/obj/boris-boots")->wear();
        carry_object("/open/prayer/obj/boris-cloth")->wear();
        carry_object("/open/prayer/obj/boris-hat")->wear();
        carry_object("/open/prayer/obj/boris-hands")->wear();
        carry_object("/open/prayer/obj/kylin-belt")->wear();
        carry_object("/open/prayer/obj/dragon-icer")->wield();
}

void init()
{
  call_out("do_talk",5,this_object());
  ::init();
}

void greeting()
{
	object ob,me;
        ob = this_player();
        me = this_object();
        command("say 放心，師兄一定會保護你安全的!!");
}

void heart_beat()
{
   object me=this_object();
   if(me->is_busy())
   {
   	 message_vision(HIY"\n
   	 $N逆運渾天寶鑑心法，硬生生將周遭的阻礙全數震開!!
   	 \n"NOR,me);
   	 me->delete_busy();
   }
   command("perform force.supertengin");
   ::heart_beat();
}

void do_talk()
{
	object me = this_object();
	object ob = this_player();
	if(ob->query_temp("find_scroll") == 3)
	{
	command("say 想不到你們死後仍念念不忘要報復聖火教，甚至甘願觸犯天條，藉著附身重現人世。");
	call_out("do_talk2",5,ob);
        }
}

int do_talk2()
{
        object me = this_object();
	object ob = this_player();
	command("say 幸好陸道長以無上法力助我暫時還陽，讓我來得及回來保護本教遺產。");
	call_out("do_fight",5,ob);
	return 1;
}

int do_fight()
{
	int i,j;
	object me,enemy1,enemy2,ob;
        me = this_object();
        ob = this_player();
        i = sizeof(ob);
	enemy1 = present( "nightmare en",environment(me) );
        enemy2 = present( "nightmare lan",environment(me) );
        command("say 夜夢雙妖，我們的恩仇就在這裡一併了結吧!!");
        me->kill_ob(enemy1);
        me->kill_ob(enemy2);
        enemy1->kill_ob(ob);
        enemy2->kill_ob(ob);
        ob->delete_busy();

        return 1;
}
