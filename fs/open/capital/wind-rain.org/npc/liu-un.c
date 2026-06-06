// by roger

#include <ansi.h>
##include "castle.h"
inherit NPC;
void create() {
        
        set_name("楚流雲",({"liu-un"}));
        set("long",@LONG
長期跟在金風細雨樓樓主身邊接受指導, 
從一無是處的小毛頭蛻變成了絕世高手, 
他的身上還有許多的秘密.
LONG);
        set("age",17);
        set("str",30);
        set("int",30);
        set("spi",30);
        set("cor",30);
        set("kar",30);
        set("cps",30);
        set("race","人類");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("max_gin",3000);
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_force",5000);
        set("force",5000);
        set("force_factor",20);
        set("combat_exp",1000000);
        set_skill("blade",100);
        set_skill("dodge",100);
        set_skill("lo-steps",100);
        set_skill("move",100);
        set_skill("parry",100);
        set_skill("wind-rain",100);
        set_skill("literate",150);
        set_skill("sand-blade",100);
        set_skill("force",150);
        map_skill("blade","sand-blade");
        map_skill("dodge","lo-steps");
        map_skill("parry","wind-rain");
        map_skill("move","lo-steps");
        set("clan_kill",1);
        setup();
        carry_object(C_OBJ"/bird-blade")->wield();
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
 if( random(100) < 20)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
 for(j=0;j < i;j++){
    target=enemy[j];
    if( env == environment(target) )
    {
      message_vision(HIW"\n
$N亂舞手中長刀，刀氣開始颳起風沙石塵，黃色的霧逐漸瀰漫開來
將$N隱在其中，倏然一式"HIY"『駱行千步歸  風沙舞翩翩』"HIW"黃沙雜混著
激烈而灼熱的刀氣，毫無紋理可尋地向四處圍竄
\n"NOR,mob);
      target->receive_damage("kee",350);
      COMBAT_D->report_status(target, 1);
    }
                   }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}


