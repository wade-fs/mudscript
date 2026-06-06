// by roger
inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create() {
        
        set_name("花憶妍",({"hau-yi-yan","hau"}));
        set("title","金風細雨第二樓樓主");
        set("nickname",HIC + "百蕊千香" + NOR);
        set("long",@LONG
   冰肌玉膚唇紅齒白還不足以形容她的十分之一, 高貴典
   雅的氣質比起皇室更是有過之而無不及, 是金風細雨樓
   的第一美女.
LONG);
        set("age",30);
        set("str",30);
        set("int",30);
        set("spi",30);
        set("cor",30);
        set("kar",30);
        set("cps",30);
        set("race","人類");
        set("gender","女性");
        set("attitude","peaceful");
        set("max_gin",3000);
        set("max_kee",5000);
        set("max_sen",3000);
        set("max_force",6000);
        set("force",6000);
        set("force_factor",13);
        set("combat_exp",1500000);
        set_skill("dagger",100);
        set_skill("dodge",100);
        set_skill("lo-steps",100);
        set_skill("move",100);
        set_skill("parry",100);
        set_skill("wind-rain",100);
        set_skill("literate",170);
        set_skill("music-dagger",100);
        set_skill("force",150);
        map_skill("dagger","music-dagger");
        map_skill("dodge","lo-steps");
        map_skill("parry","wind-rain");
        map_skill("move","lo-steps");
        set("chat_chance", 10);

        setup();
        carry_object(C_OBJ"/flower-cape")->wear();
        carry_object(C_OBJ"/crane-finger")->wear();
        carry_object(C_OBJ"/fragant-dagger")->wield();
        add_money("gold",10);
 }


void heart_beat()
{
 object env,mob,*enemy,target;
 int i,j;

 mob = this_object(); 
 env = environment(mob);
 
 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 mob->delete_busy();
 if( random(100) < 25 && mob->is_fighting())
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);

      message_vision(HIM + "\n
       $N輕抖匕尖，迴舞拂袖，在空氣中開始響起微微的聲調，還瀰漫著一
       股淡淡的花香，敵人漸漸亂了方寸；忽然華瓣漫天，香煙茵茵，一式
      " + HIC + "『古香撲朔  今音迷離』" + HIM + "粼起華風旋旋，馥郁直接從皮膚沁如體內。
\n" + NOR,mob);
 for(j=0;j < i;j++){
    target=enemy[j];
    if( env == environment(target) )
    {
      target->receive_damage("kee",200);
      target->start_busy(2);
      target->apply_condition("rose_poison",10);
      COMBAT_D->report_status(target, 1);
    }
                   }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}



