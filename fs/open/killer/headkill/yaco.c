#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string askwho();
string askcard();

void create() 
{
            object ob;
            set_name("神秘男子",({"special man","man"}));
            set("long","他是名震江湖的一代殺手﹐黑牙聯的頭目。\n");
            set("gender","男性");
            set("class","killer");
            set("combat_exp",6000000);
            set("attitude","heroism");
            set("age",50);
            set("str", 99);
            set("cor", 99);
            set("cps", 99);
            set("per", 99);
            set("int", 99);
	    set("kee",4000);
	    set("max_kee",4000);
	    set("gin",1200);
	    set("max_gin",1200);
	    set("sen",1200);
	    set("max_sen",1200);
	    set("atman",1300);
	    set("max_atman",1300);
	    set("mana",1400);
	    set("max_mana",1400);
            set("force",5000);
            set("max_force",5000);
            set_skill("force",100);
            set_skill("move",100);
            set_skill("throwing",100);
            set_skill("shade-steps",120);
            set_skill("rain-throwing",120);
	    set_skill("spells",50);
	    set_skill("magic",60);
            set_skill("dagger",120);
            set_skill("dodge",120);
	    set_skill("shadow-kill",100);
	    set_skill("blackforce",90);
            	map_skill("dagger","shadow-kill");
		map_skill("throwing","rain-throwing");
		map_skill("dodge","shade-steps");
		map_skill("force","blackforce");
		map_skill("move","shade-steps");
		set_temp("apply/armor",70);
		set("force_factor",10);
set("inquiry",([ 
    "你是誰" : (: askwho :),
    "藍鳳絕殺令" : (: askcard :),
]));

setup();
create_family("黑牙聯",2,"主席");
carry_object("/open/killer/obj/dagger")->wield();
}

string askwho()
{
	if (this_player()->query_temp("head") != 8)
		return "哼。。。作弊來到此處，也想問我是誰？";
	else
	{
		this_player()->set_temp("askwho",1);
		command("say 哈哈。。。我是誰？唉。。。這也難怪，我消失也已經有十來年了吧？");
		command("say 小子，看你的裝扮應該是新生代特級殺手吧！");
		command("say 難得你有辦法來到這裡，好吧，老夫就是葉孤城");
return "你有什麼事情找老夫呢？，是為了(藍鳳絕殺令)嗎？";
	}
}

string askcard()
{
	object obj;

	if (this_player()->query_temp("head") != 8)
		return "哼。。。作弊來到此處，也想找我要藍鳳絕殺令？";
	else
	{
		if (this_player()->query_temp("askwho") != 1)
			return "你又不知道他是誰，居然亂找人要藍鳳絕殺令";
		command("nod");
		command("say 難得你有辦法來到這裡，就給你藍鳳絕殺令吧！");
		obj = new("/open/killer/headkill/obj/bluekill.c");
		obj->move(this_player());
		message_vision("$N給$n一張"+obj->name()+"。\n",this_object(),this_player());
		command("say 利用藍鳳絕殺令去追殺<殺手全力追殺的人頭>，使用法就寫在它上面");
		command("say 既然來到這裡，就讓老夫助你一臂之力，讓你可以再次突破魔氣殺的限制吧!");
		message_vision("葉孤城迅速在你身上拍擊，送入內力，讓你體內魔氣殺限制再次突破");
		this_player()->set("upkee",1);
		this_player()->set_temp("head",9);
    return "打pass way就可以離開這裡！";
	}
}
		
int accept_fight(object ob)          
{
	command("say 你是真的要跟我挑戰嗎??\n");
	message_vision( this_object()->name()+"臉上一副鄙視的樣子。\n",ob);
	return 0;
}

int accept_kill(object ob)
{
	command("say 沒想到你真有勇氣, 敢跟我挑戰!!!\n");
	message_vision( this_object()->name()+"突然變臉﹐臉上出現殺氣。\n",ob);
	this_object()->set("bellicosity",5000);
	command("cmd bellup");
	return 1;
}
