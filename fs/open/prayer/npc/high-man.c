// 隱世高人

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
  object ob;
	set_name("于萬庭", ({"master uh","master","uh"}));
        set("nickname","刀神劍仙十三鞭");
	set("long",@LONG

	他在少年之時, 精通諸般武學, 尤其以刀, 劍, 鞭三
	者為最!!性情溫和, 喜歡將具有資質者調教成為武藝
	高強的菁英份子!!與聖火教的副教主是結義的兄弟!!
	隱居之後自成一派, 自稱為 [廣成派] !!

LONG);
	set("gender","男性");
        set("class","prayer");
        set("title","隱世高人");
	set("combat_exp",4500000);
        set("attitude","heroism");
	set("age",73);
        set("kee",9500);
        set("max_kee",9500);
	set("force",10000);
	set("max_force",10000);
	set("force_factor",35);
        set("max_gin",6800);
        set("max_sen",6800);
        set_skill("dodge", 60);
	set_skill("sword", 300);
	set_skill("blade", 300);
	set_skill("whip", 300);
	set_skill("cure",65);
	set_skill("literate",65);
	set_skill("force",90);
        set_skill("move", 70);
        set_skill("parry", 70);
        set_skill("stick",55);
        set_skill("unarmed", 90);
	setup();
	create_family("廣成派",1,"掌門");
}

int accept_kill(object ob)
{
        command("smile");
	command("say 老夫救了你, 你想要以怨報德嗎??\n");
        return 0;

}

void init()
{
	object ob;
	::init();
	if(interactive(ob =this_player()) && !is_fighting() )
	{
	remove_call_out("greeting");
        call_out("greeting",1,ob);
        add_action("do_nod","nod"); 
        add_action("do_thx","thx");
        }
}

void greeting(object ob)
{
        if (ob->query_temp("high-man") == 4 )
        {
        write("\n呵呵, 這位小兄弟醒了嬤??你的命真大!!幸虧是我路過此地!!否則你的小命就沒囉!!\n");
        write("\n你的傷勢頗重, 好好地休養吧!!\n");
        ob->set_temp("high-man", 5);
        return; 
        }
}

int do_thx()
{
	object ob=this_player();
	if ( ob->query_temp("high-man") == 5 )
        {
        write("\n老夫與你也算是有緣了, 看你的資質也不錯, 就傳你一些功\力以為防身之用吧!!不過你下山後, 可不要向人提任何隻字片語!!懂嗎(nod)??\n");
        ob->set_temp("high-man", 6);
        return 1;
        }
	else
        {
	return 0;
	}
}

int do_nod()
{
	object ob = this_player();
	int lv  = (int)ob->query_cor();
	int lv1 = (int)ob->query_con();

        if( ob->query_temp("high-man") < 6 && ob->query("quests/high-man") )
        {
	return 0;
	}
	else
        {
	write("\n嗯!!那老朽這就開始傳功\了!!,,,,,,,,,,,,,,\n");
	ob->add("max_force", (lv+lv1)*5);
	ob->add("combat_exp", (lv+lv1)*1200); 
	ob->set_skill("sword", 30);
	ob->set_skill("blade", 30);
	ob->set_skill("whip", 30);
	ob->set("quests/high-man",1);
	ob->delete_temp("high-man");
        return 1;
	}

}
