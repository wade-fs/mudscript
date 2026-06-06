//紅姑
#include <command.h>
 
inherit NPC;

string ask_book();

void create()
{
    set_name("婦女",({"woman"}));
    set("gender", "女性");
    set("age",35);
    set("attitude","friendly");
    set("long",@LONG

	她是霞山派的女弟子, 長年喬裝躲在此地!!

LONG);
 
    set("combat_exp",522000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",500);
    set("kee",500);
    set("max_force",500);
    set("force_factor", 10);
    set("force",500);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("dodge",130);
    set_skill("move",130);
    set_skill("parry",130);
    set_skill("whip",130);
    set_skill("force",130);
    set_skill("sunwhip",130);
    set_skill("fireforce",130);
    map_skill("force", "fireforce");
    map_skill("whip", "sunwhip");
    map_skill("parry", "sunwhip");
    set("inquiry",([
    "霞山派":"霞山派的武學路數, 係師祖所創之[落日鞭法]!\n",
    "密笈":(: ask_book :),
    "燕十一":"他.....是我的同門師弟!!不過被周琇虔擄去了....\n",
    "周琇虔":"她就是現任聖火八天門之一--瑤光門的門主!!\n",
 ]));
    setup();
    carry_object("/open/prayer/obj/whip1")->wield();
    add_money("gold", 2);
}

void init()
{
	object who;
	::init();
	if(interactive(who =this_player()) && !is_fighting() )
	{
	remove_call_out("greeting");
        call_out("greeting",2,who);
        add_action("do_nod","nod"); 
        }
}

int do_nod()
{
	object who=this_player();
	if( who->query_temp("red") == 1  )
	{
	return 0;            
	}
	else
	{
	who->set_temp("help_red", 1);
        write("嗯!!那我等你的好消息!!萬事拜託了\n");
        return 1;
        }

}

void greeting(object who)
{
    if( who->query_temp("kill_red") >= 1 ) 
    {
      if( who->query_temp("red") >= 1 )
      {
      write("\n你一定是燕師弟派來的人吧!!希望你能助我一臂之力, 鏟除周琇虔
    這個惡毒的女人!!好嗎(nod)??\n");
      who->set_temp("red", 2);
      }
      else
      {
      write("\n我知道你是周琇虔那個忘恩負義的女人派來的!!還我師弟來!!\n");
      kill_ob(who);
      }
    }
    return;
}


string ask_book()
{
    object who=this_player();
    object ob3=new("/open/prayer/obj/whipbook");
    if( who->query("quests/sunwhip",1) && !present("whipbook",who) )
    {
    ob3->move(this_player());
    return "你自己好好地揣摩揣摩吧!!有朝一日可以用來防身殺敵\n";
    }
    else
    {
    return "本門武學密笈豈可輕易外洩藏匿之處!!\n";
    }
}   

void die()
{

    object who;
    who= this_object()->query_temp("last_damage_from");
    if( who && userp(who) ) 
    {
    who->delete_temp("kill_red");
    who->set_temp("kill_red", 2);
    write("我死了之後, 希望你能替我轉告師弟燕十一, 他會告訴你密笈的下落的!!\n");
    }
    ::die() ;
}


