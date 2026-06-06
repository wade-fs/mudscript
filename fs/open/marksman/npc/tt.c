// master_tor.c made by adam..
// 讓他死前會靠邀-by nike-
#include <ansi.h>
#include "marksman.h"
inherit NPC;
inherit F_MASTER;
string s_att();
string ask_rock();
void create()
{
        set("class", "marksman");
        set_name("李廣", ({ "master lee", "master", "lee" }) );
        set("title","射日派第二代掌門人");
        set("nickname",HIC + "心定穿石" + NOR);
        set("gender", "男性");
        set("max_kee",5000);
        set("age", 55);
        set("attitude", "heroism");
        set("long","李廣為朝廷名將，有「百步穿楊」的射箭技術，曾在一次打獵中，把箭射進石頭裡，天子為之讚嘆不已..\n");
        set("str", 18);
        set("cps", 30);
        set("per", 10);
set("cor",30);
set("int", 40);
set("kar", 16);
set("combat_exp",2000000);
set("bellicosity",5000);
set("force",8000);
set("max_force",8000);
set("max_atman",5000);
set("atman",5000);
set("force_factor",30);
set("score"       , 200000);
set_skill("force",80);
set_skill("archery",120);
set_skill("god-shooting",100);
set_skill("magic",20);
set_skill("move",70);
set_skill("parry",70);
set("functions/ten_kee/level",100);
set("functions/m-archery/level",100);
        set_skill("dodge",70);
        set_skill("literate",40);
        set_skill("unarmed",20);
        set_skill("iceforce",100);
        set("no_lyssa",1);
        set_skill("rain-steps",100);
        set_skill("riding",80);
        map_skill("force", "iceforce");
        map_skill("dodge", "rain-steps");
        map_skill("parry", "rain-steps");
        map_skill("archery","god-shooting");
        map_skill("move","rain-steps");
        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
             (: s_att :)
        }));
        create_family("射日派", 2, "掌門人");
        setup();
        carry_object(C_OBJ"/arrow-8");
        carry_object(C_OBJ"/dragon_bow")->wield();   
        set("inquiry", ([
            "百步穿楊":  (: ask_rock :),
        ]));
        add_money("gold",10);
}

void init()
{
 add_action("do_shoot","shoot");
}


void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="marksman")
        {
                command("sigh");
                command("say 你不是射手﹐我不能收你。\n");
                return;
        }
      if((int)ob->query_str() <16 )
{
          command("sigh");
          command("say 你的膂力不夠，拿起弓來一定會顫抖..\n敝人觀之"+ RANK_D->query_respect(ob) + "的資質似乎不宜！\n");

return;
        }

      command("hmm");
new(C_OBJ"/bow-1")->move(ob);
command("say 給你把弓，可不要用不見啦!");   
      command("pat" + ob->query("id"));
      command("recruit "+ob->query("id"));
message("system",HIR + "李廣笑道 :\n
      " + HIW + "" +this_player()->name()+ "" + NOR + "" + HIR + "拜入我門下 !\n
      他日必可成為一代神射手!\n
      成為武林至尊!!\n\n" + NOR,users());

}
int accept_kill(object ob)
{
 command("say 老夫最近沒練武了，那就來動一動吧!");
 command("say 納命來!!");
 command("cmd holdup arrow with bow");
 kill_ob(ob);
command("perform archery.ten_kee");
command("supershoot");
return 1;
}
int accept_fight(object ob)
{
command("say 那好吧!!老夫就來會會你");
command("cmd holdup arrow with bow");
 fight_ob(ob);
command("perform archery.ten_kee");
command("supershoot");
return 1;
}
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
if( me->is_fighting() && random(100) > 60 && !me->query_temp("fast-dest") )
{
message_vision(HIC + "\n李廣吃起藥丸補充血氣。\n" + NOR,me); 
me->receive_curing("kee",1500);
me->receive_heal("kee",1500);
me->delete_busy();
me->clear_condition();
   }
     ::heart_beat();
}
void greeting(object ob)
{
ob=this_player();
if(ob->query("family/family_name")=="射日派")
{


if(!present("bow",ob))
{
new(C_OBJ"/bow-1")->move(ob);
command("hmm");
command("say 弓怎麼不見啦!!");
command("say 再給你一把，不要弄丟啦!");
}
}
}
void die()                                                                 
{    
        object winner = query_temp("last_damage_from");

        tell_object(users(),HIW + "
    忽然自" + GRN + "長沙城" + HIW + "之中射出一道白光，映著朝日，直竄達天際～～～\n
        射日派掌門人－" + HIY + "李廣" + HIW + "臨死前喟然嘆道～～～\n
            「啊～～～罷了...想我堂堂一名" + HIC + "飛將軍" + HIW + "，居然是如此不堪一擊...」\n
                名動天下的" + HIC + "「飛將軍」" + HIY + "李廣" + HIW + "，竟被" + HIR + "『"+winner->name()+"』" + HIW + "給一招擊斃於" + HIY + "廣義堂" + HIW + "內...\n
\n\n" + NOR);
        ::die();
}
string s_att()
{
if(random(2)) {
command("perform archery.ten_kee");
command("supershoot");
} else {
command("perform archery.m-archery");
command("supershoot");
}
}

string ask_rock()
{
        object me = this_player();
        if(!me->query_temp("find_arrow") || me->query("marksman/punch_rock"))
        {
        me->set_temp("find_arrow",1);
        call_out("ask_rock1",10,me);
        return "嗯，那的確是值得自豪的功\夫，不過老夫最驕傲的，莫過於將箭射進石頭這件事了。";
        }else{
        return "射射射，你在這邊射什麼鳥啊  -___-||";
             }
}

int ask_rock1()
{
	object me = this_player();
        message_vision(HIR + "李廣指著前方二十步左右的石頭。\n" + NOR,me);
        call_out("ask_rock2",10,me);
        return 1;
}

int ask_rock2()
{
	object me = this_player();
        command("say 你若能像老夫當年一樣，將箭射(shoot)進石頭(rock)裡，老夫就傳你百步穿楊的功\夫。");
        me->set_temp("find_arrow",2);
        return 1;
}

int do_shoot(string arg)
{
	object me = this_player();
	if(arg == "rock")
	{
	  if(me->query_temp("find_arrow") == 2)
	  {
	    message_vision(HIW + "$N搭上箭，拉滿弓，「咻」的一聲射去，$N隱約見到石頭上插著一把箭。\n",me);
	    call_out("shoot_rock1",10,me);
	  }
	}else{
	     message_vision(CYN + "$N不要亂射啦，髒死了!!" + NOR,me);
	     }
	return 1;
}

int shoot_rock1()
{
	object me = this_player();
        message_vision(HIG + "$N跑到石頭旁邊一看，發現插在石頭上的箭並不是自己的，
而剛剛自己所射的箭已經撞斷了箭頭，掉落在一旁。\n" + NOR,me);
        message_vision(HIC + "猶豫了一會兒，$N將兩支箭都收了起來。\n" + NOR,me);
        new(C_OBJ"/good_arrow")->move(me);
        new(C_OBJ"/broken_arrow")->move(me);
        
	return 1;
}

int accept_object(object me,object obj)
{
   me = this_player();
   if(obj->query("id") == "broken arrow" && me->query_temp("find_arrow"))
   {
     command ("say 很好，你這個人非常誠實，我很喜歡，其實你射箭的技術已經爐火純青了，只是運勁功\夫尚未渾融而已。");
     command ("say 我這就傳你運勁發箭的法門，讓你的箭技更上一層樓。");
     message_vision(HIM + "李廣對著$N指點了一番，$N豁然頓悟箇中奧妙，學會了" + HIC + "虛空馭天箭" + HIC + "之術。\n" + NOR,me);
     message_vision("請以perform god-shooting.super-shooting使用並以help mark參考相關說明。" + NOR,me);
     me->set_function("super-shooting",1);
     me->set("marksman/punch_rock",1);
     me->delete_temp("find_arrow");
   }else if(obj->query("id") == "good arrow" && me->query_temp("find_arrow"))
           {
           command ("say 唉，這箭明明就是我射的，你根本沒射中對吧。");
           command ("say 不過這代表你真的很想學這們功\夫，好吧!!我就教你吧!!");
           message_vision(HIM + "李廣在$N面前演練了一遍架式，$N豁然頓悟箇中奧妙，學會了" + HIC + "虛空馭天箭" + HIC + "之術。" + NOR,me);	
           me->set_function("super-shooting",21);
           message_vision("請以perform god-shooting.super-shooting使用並以help mark參考相關說明。",me);
           me->set("marksman/punch_rock",2);
           me->delete_temp("find_arrow");
           }else{
                 command ("idle");
                }
    return 1;
}
