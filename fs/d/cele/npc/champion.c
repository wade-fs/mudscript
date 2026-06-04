// servant.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("於蘭天武", ({ "master champion", "champion", "master" }) );
	set("title", "水煙閣傳功\使");
	set("nickname", "大天邪");
	set("gender", "男性");
	set("age", 54);
        set("class","fighter");
	set("long",
		"於蘭天武是當今皇上的叔父﹐但是他畢生浸淫武學﹐甘願拋棄榮華富\n"
		"以換取水煙閣傳功\使一職﹐以便閱\讀水煙閣中所藏的武學典籍﹐無論\n"
		"你有什麼武學上的疑難﹐他都能為你解答。\n");

	set("attitude", "peaceful");
	set("combat_exp", 10000000);
	set("score", 200000);

	set("str", 40);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("force", 40000);
	set("max_force", 40000);
	set("force_factor", 50);
        set("max_kee", 30000);
        set("kee", 35000);
	set("inquiry", ([
		"武學": "武學之道....嗯....只可意會﹐不可言喻。\n",
		"水煙閣": "水煙閣乃是歷屆武林盟主的行館﹐你有什麼事要見武林盟主﹖\n",
		"拜師": "哦....老夫向來有個規矩﹐凡是想拜我為師的﹐得接我三招不死﹐你想試試(accept test)﹖\n"
	]) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: exert_function, "roar" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("天邪派", 15, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("sword", 80);
	set_skill("blade", 250);
	set_skill("parry", 200);
	set_skill("dodge", 80);
	set_skill("celestial", 200);
	set_skill("celestrike", 200);
	set_skill("spring-blade", 270);
	set_skill("pyrobat-steps", 200);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("dodge", "pyrobat-steps");

	setup();

	carry_object("/d/cele/obj/houndbane")->wield();
}

void init()
{
	::init();
	add_action("do_accept", "accept");
}


int do_accept(string arg)
{
	mapping guild;

	if( arg== "test" ) {
		say("\n於蘭天武點了點頭﹐說道﹕很好﹐這是第一招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於蘭天武嘆了口氣﹐說道﹕連第一招都撐不過﹐真是自不量力....\n");
			return 1;
		}
		say("\n於蘭天武說道﹕這是第二招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於蘭天武「哼」地一聲﹐說道﹕便是有這許\多不怕死的傢伙....\n");
			return 1;
		}
		say("\n於蘭天武說道﹕第三招來了....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("於蘭天武嘆道﹕可惜﹐難道老夫一身武功\竟無傳人....\n");
			return 1;
		}
		say("\n於蘭天武哈哈大笑﹐說道﹕今日老夫終於覓得一個可造之才﹗\n\n");
		command("recruit " + this_player()->query("id") );

                message("system",HIY + "一陣如雷吼般渾厚聲音破空而出
              就好似從遠古所傳來的訊息.....

       百年前的武林第一人 於蘭天武縱聲長笑著 :
       英雄出少年 ,"+this_player()->name()+"
       本\傳\功\使\會\將\所\知\的\武學全部好好傳授給你.\n" + NOR,users());
        }
		return 1;
	}

