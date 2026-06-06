// master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

// 此 npc 為門派 master 請勿隨意更動  (fund)
void create()
{
        set_name("神秘老人",({"oldman"}));
	set("gender", "男性" );
	create_family("魔刀莫測",1," ");
            set("title","");
         set("age",70);
      set("str",30);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force",2000);
	set("force",2000);
           set("force_factor",10);


       set("long","一個看起來全身髒盻盻的老人﹐腳上還有一個腳銬﹐看起來像是被關在這裡的。\n");

	set_skill("force",70);
            set_skill("blade",100);
	set_skill("unarmed",60);
	set_skill("dodge",70);
             set_skill("literate",60);
	set_skill("powerforce",100);
	set_skill("dragon-blade",120);
	map_skill("blade","dragon-blade");
	map_skill("force","powerforce");

	set("combat_exp", 1000000);
	set("score", 200000);
	set("chat_chance_combat",60);
	set_temp("apply/armor",80);
	set_temp("apply/damage",80);
         set("chat_msg_combat",({
	(: perform_action, "blade.power-dest" :),
      }));




	set("inquiry", ([
	    "獨孤愁":  "這個老賊用暗招﹐把我關在這十幾年﹐這個仇....我一定要報！\n",
	    "腳銬": "這個腳銬是用千年寒鐵石打造的﹐一般兵器是砍不斷的。\n",
	    "千年寒鐵石": "這是經過千年孕育而成的堅硬石塊﹐除非有神兵利器﹐不然無法砍斷。\n",
	    "神兵利器": "聽說人間至寶「金鱗蟒邪」配上「天邪石」可以毀滅千年寒鐵石。\n",
	    "金鱗蟒邪":  "聽說金鱗蟒邪好像落在茅山派手上。\n",
	    "天邪石":   "天邪石在獨孤愁這個老賊手裡！！！\n",
	]) );

	setup();
	carry_object("/open/snow/obj/poor_blade")->wield();
}

void init()
{
     add_action("do_learn","learn");
}
void attempt_apprentice(object ob,string str)
{
         if(this_player()->query("can_apprentice")==2)
         {
             command("say 你我無緣﹐你走吧！");
             return;
         }
	if(this_player()->query("can_apprentice")!=1)
          {
          command("say 滾！你給我滾開！\n");
          return;
          }
           command("say 凡我門徒﹐不得將我絕學再傳他人。");
	command("recruit "+this_player()->query("id"));
              this_player()->set("family/master_name","莫測");
              this_player()->set("title","魔刀傳人");
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
            ob->set("class","blademan");
}
int accept_object(object who,object ob)
{
    string ob_id;
    ob_id=ob->query("id");
      if(this_player()->query("can_apprentice")!=0)
                  return 1;
      if(ob_id=="snake sword")
     {
        command("hmm");
             this_player()->set("give_1",1);
     }
        if(ob_id=="stone")
         {
             command("hmm");
            this_player()->set("give_2",1);
         }
       if(who->query("give_1")==1&&who->query("give_2")==1)
        {
            command("say 太好了！");
            message_vision(
             HIY + "$n將天邪石的神力注入金鱗蟒邪之中﹐然後運勁一砍﹐將腳銬砍斷。\n" + NOR,this_player(),this_object());
            shout(HIR + "遠處傳來魔刀莫測的大喝﹕\n\n我自由了！哈哈哈哈！！！\n\n獨孤愁！你這個老賊等者吧！我要一雪這十幾年禁錮之恨！\n" + NOR);
       if(who->query_kar()>25)  who->set("can_apprentice",1);
           else who->set("can_apprentice",2);
         command("say 非常感謝你幫我重獲自由。");
       if(this_player()->query("can_apprentice")==1)
             command("say 莫某願將畢生所學傳與你。\n");
      if(this_player()->query("can_appentice")==2||this_player()->query("id")=="per")
       {
           command("say 但莫某覺的我倆並不有緣");
           command("say 好吧！我將部分內力傳給你。");
           this_player()->add("max_force",100);
           this_player()->add("force",100);
        }
            }
          return 1;
}
