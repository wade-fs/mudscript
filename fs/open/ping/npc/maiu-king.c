// change from 平南將軍
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("苗人軍師",({"officer of maiu","officer","maiu"}));
	set("long","一位負責苗人軍政的軍師\n");
	set("gender","男性");
        set("attitude","heroism");
	set("functions/firefinger/level",10);
	set("age",32);
	set("str", 30);
	set("con", 30);
	set("force",1500);
	set("max_force",1500);
        set("combat_exp", 90000);
	set_skill("force",60);
        set_skill("dodge", 50);
        set_skill("whip",60);
        set_skill("nine-steps",60);
        set_skill("poisonforce",30);
        set_skill("coldpoison",25);
        set_skill("ming-snake",40);
        map_skill("force","poisonforce");
        map_skill("dodge","nine-steps");
        map_skill("poison","coldpoison");
        map_skill("whip","ming-snake");        
        set("force_factor", 3);
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
	(: perform_action,"poison.firefinger" :),
	}));
	setup();
        carry_object("open/poison/obj/snake_whip")->wield();
        carry_object("/obj/poison/five_poison")->set_amount(10);
	add_money("silver",50);
}
int accept_object(object who, object ob)
{
  object mid;
  if( ob->query("id") == "maiu_id" && !query("change") )
  { 
    who->set_temp("maiu",1);
    say("苗人軍師說:哦?你要見苗王?...MMM....這文件是怎麼拿到的?.\n"+
        "如果是正當手段得到的,怎麼不知道...我...就是苗王!!!\n"+
        "苗人軍師卸下了臉上的人皮面具\n");
    set("change",1);
    set_name("苗王",({"king of maiu","king","maiu"}));
    set("long","苗族之王,正為如何打敗漢軍而煩惱著\n");
    set("combat_exp", 140000);
    set("chat_chance_combat", 20);
    set("functions/firefinger/level",20);
    set("force_factor", 10);
    set_skill("coldpoison",30);
    set_skill("ming-snake",50);
//  mid=new("/open/ping/obj/maiu-head"); 
//  mid->move(this_object());
  }      
  if( ob->query("id") == "zhang-head" && who->query_temp("maiu") )
  { 
   say("苗王審視人頭一番,大笑曰: 你這奸臣也有今日...哈哈哈!!!\n"+
       "那...這是給你的謝禮.\n苗王給你一些藥丸.\n");  
   mid=new("/open/gsword/obj/ff_pill");
   mid->add_amount( who->query_per()+15 );
   mid->move(who);
   who->delete_temp("maiu");
   who->delete_temp("k_m"); 
  }
   destruct(ob);
   return 1;  
}
int accept_kill(object who)
{
  object head; 
  if( who->query_temp("maiu") && !query("change2") )
  { 
   if( query("k_m") )
   {
   say("苗王說: 你是執迷不悟了!!!\n苗王施展力量增強術!!!\n");
   set("title","- 妖氣 -");
   set("change2",1);
   set("combat_exp", 180000);
   set("max_kee",3000);
   set("kee",3000);
   set("chat_chance_combat", 25);
   set("functions/firefinger/level",30);
   set("force_factor", 15);     
   set_skill("ming-snake",60);
   setup();
   head=new("/open/ping/obj/maiu-head");
   head->move(this_object());
   }else{
   say("苗王說: 慢...你是職業殺手吧...不如替我方除掉平南將軍...\n我方願出比平"
      +"南更豐厚的酬金謝你!!\n");
   set("k_m",1);
   return 0;
   }
  } 
  return 1;
}
int accept_fight(object who)
{
  if( who->query_temp("maiu") && query("change") )
      return notify_fail("苗王說: 去殺平南將軍吧! 本朝的獎賞較豐厚呀!\n");
  return 1;
}                        
