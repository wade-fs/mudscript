#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;
string ask_fish();
string ask_yao();
string ask_quest();
string ask_broken();
string ask_ball();
string ask_gball();
string ask_fireball();
string ask_waterball();
string ask_woodball();
string ask_soilball();
void create()
{
set_name("李夢枕",({"roger lee","lee","roger"}));
        set("age",33);
    set("long","傳說中金風細雨樓樓主，謎一般的神秘男子，似乎已經在武林中打滾多年，擁有無數迷團於一身，其武功\似乎和其身家一樣，無人知悉。\n");
        set("gender","男姓");
        set("str",50);
        set("cor",50);
        set("cps",50);
        set("int",50);
        set("con",50);
        set("spi",50);
        set("kar",50);
    set("class","swordsman");
    set("family/family_name","仙劍派");
        set("bellicosity",400);
        set("get_sha_sp",1);
        set("no_hire",1);
        set("max_kee",50000);
        set("kee",50000);
        set("max_gin",50000);
        set("gin",50000);
        set("max_sen",50000);
        set("sen",50000);
        set("combat_exp",10000000);
        set("max_force",50000);
        set("force",50000);
        set("force_factor",10);
        set_skill("dodge",200);
        set_skill("star-blade",200);
        set_skill("force",300);
        set_skill("sha-steps",100);
        set_skill("unarmed",120);
        set_skill("fireforce",100);
        map_skill("dodge","sha-steps");
        set_skill("stars-blade",150);
        set_skill("blade",120);
        map_skill("blade","stars-blade");
        map_skill("force","fireforce");
    set("chat_chance",100);
        set("chat_chance_combat",25);
        set_temp("apply/armor",500);
        set_temp("apply/damage",80);
        set_temp("armor_vs_force",1500);
        set_temp("no_die_soon",1);
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);
        set_temp("apply/dodge",50);
         set_temp("apply/parry",50);
set("inquiry",([
  "仙劍山腳下的娃娃魚" : (:ask_fish:),
  "血魔" : (:ask_quest:),
  "破解之道" : (:ask_broken:),
  "五行寶珠" : (:ask_ball:),
  "逍遙子" : (:ask_yao:),
   "金法珠" : (:ask_gball:),
   "火法珠" : (:ask_fireball:),
   "水法珠" : (:ask_waterball:),
   "木法珠" : (:ask_woodball:),
   "土法珠" : (:ask_soilball:),
]));
    setup();
        carry_object("/u/a/appo/kdblade.c")->wield();
        add_money("gold",10);

}
void heart_beat()
{
 object me,*target;
 int i,j;
 i=sizeof(target);
 me=this_object();
 if(me->is_fighting()||me->is_killing())
 {
  target=me->query_enemy();
 if (random(10)<=4)
   {
message_vision(HIY"$N運起身上無極刀氣，頓時刀芒充斥四周！

     "HIC"★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆"HIW"

            $N怒吼：看我的『破體無形刀』！！！

     "HIC"★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆"HIY"
      瞬間，由$N身上射出無數逐漸凝聚而成的刀芒！
          轉眼間，數百道刀芒已貫穿你的身體！！！
"NOR,me);
     me->delete_busy();
     me->clear_condition();
     for(j=0;j < i;j++)
     {
      target[j]->add("kee",-1500);
      target[j]->apply_condition("hellthunder",3);
       COMBAT_D->report_status(target[j]);
     }
   }
else
   {
 if ((random(2)+1)==1)
   {
    message_vision(HIM"李夢枕運起全身仙雲之氣，瞬間整個空間皆被紅光包圍，紅光消似李夢枕神色為之一亮。\n"NOR,me);
    me->receive_curing("gin",3000);
    me->receive_heal("gin",3000);
    me->receive_curing("kee",6000);
    me->receive_heal("kee",6000);
    me->receive_curing("sen",3000);
    me->receive_heal("sen",3000);
    me->delete_busy();
    me->add("force",4000);
    me->clear_condition();
   }
}
if((me->query("eff_kee") < 6000 || me->query("kee") < 6000) &&!me->query("dead"))
{
    message_vision(HIM"$N嘆道:真要逼我使出獨門刀法嗎??\n"NOR,me);
        me->set("force_factor",50);
        me->set("eff_kee",50000);
        me->set("kee",50000);
        me->set("eff_gin",50000);
        me->set("eff_sen",50000);
        me->set("gin",50000);
        me->set("sen",50000);
        me->set("force",100000);
        me->set("combat_exp",15000000);
        me->set("dead",1);
        map_skill("blade", "stars-blade");
        me->reset_action();
        me->delete_busy();
        me->clear_condition();
  }
}
else if( !is_fighting() ) {

                if( query("eff_kee") < query("max_kee") )
                        me->receive_curing("kee",100);
                if( query("eff_gin") < query("max_gin") )
                    me->receive_curing("gin",100);
                if( query("eff_sen") < query("max_sen") )
                    me->receive_curing("sen",100);
                if( query("gin") < query("eff_gin") )
                        me->receive_heal("gin",100);
                if( query("kee") < query("eff_kee") )
                        me->receive_heal("kee",100);
                if( query("sen") < query("eff_sen") )
                        me->receive_heal("sen",100);
}
        set_heart_beat(1);
        :: heart_beat();
}

string ask_yao()
{
  return ("你說師父，唉~他被血魔用五行封印，封印在仙劍山腳下的娃娃魚身上，對了，你的五行寶珠呢?");
 }
string ask_fish()
{
 if(!this_player()->query("quests/find_roger"))
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else
  {
  return ("那是師父靈識所在..最近血魔氣息翻動我想我要得加快腳步了");
  }
}
string ask_quest()
{
 if(!this_player()->query("quests/find_roger"))
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else
  {
  return ("我想,再過不了多久,血魔必重現江湖,我必須儘快找出破解之道");
  }
}

string ask_broken()
 {
 if(!this_player()->query("quests/find_roger"))
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else
  {
  return ("我曾找到過大破魔師於蘭天武,他說我需要找齊五行寶珠才能破陣.");
  }
}
string ask_ball()
{
  return ("我們一個一個來對吧..你一個一個問我﹐確認完之後﹐就往娃娃魚那去吧。");
 }


string ask_gball()
{
 if(!this_player()->query_temp("quests/findball1"))
 {
  new("/open/gsword/obj1/gball")->move(this_player());
  return ("這都辦不好﹐我已經幫你找到了金法珠了﹐給你。");
  }
 else
  {
  this_player()->add("quests/sunmoon",2);
  return ("嗯﹐做的好~還好你找到了..否則我還找不著呢!!");
  }
}
string ask_fireball()
{
 if(!this_player()->query_temp("quests/findball2"))
 {
  new("/open/gsword/obj1/fireball")->move(this_player());
  return ("這都辦不好﹐我已經幫你找到了火法珠了﹐給你。");
  }
 else
  {
   this_player()->add("quests/sunmoon",2);
  return ("嗯﹐做的好~還好你找到了..否則我還找不著呢!!");
  }
}
string ask_waterball()
{
 if(!this_player()->query_temp("quests/findball3"))
 {
  new("/open/gsword/obj1/waterball")->move(this_player());
  return ("這都辦不好﹐我已經幫你找到了水法珠了﹐給你。");
  }
 else
  {
   this_player()->add("quests/sunmoon",2);
  return ("嗯﹐做的好~還好你找到了..否則我還找不著呢!!");
  }
}
string ask_woodball()
{
 if(!this_player()->query_temp("quests/findball4"))
 {
  new("/open/gsword/obj1/woodball")->move(this_player());
  return ("這都辦不好﹐我已經幫你找到了木法珠了﹐給你。");
  }
 else
  {
   this_player()->add("quests/sunmoon",1);
  return ("嗯﹐做的好~還好你找到了..否則我還找不著呢!!");
  }
}
string ask_soilball()
{
 if(!this_player()->query_temp("quests/findball5"))
 {

  new("/open/gsword/obj1/soilball")->move(this_player());
  return ("這都辦不好﹐我已經幫你找到了木法珠了﹐給你。");
  }
 else
  {
  this_player()->add("quests/sunmoon",1);
  return ("嗯﹐做的好~還好你找到了..否則我還找不著呢!!");
  }
}
