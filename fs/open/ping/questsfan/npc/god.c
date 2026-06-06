inherit NPC;    //藏仙谷仙人 2000.5.12 by dhk
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;
string do_god();
string do_glaze();

void create()
{
  set_name("谷中仙",({"mountain god","mountain","god"}));
  set("long","藏仙谷谷中仙人，傳聞其長年居住在藏仙谷。但是從未有人見過\n"
        +"其真面目，一切的一切僅止於傳聞而已，謎一般的人物。今日有幸一\n"
        +"見，可謂三生有幸！\n");
  set("gender","男性");
  set("class","fighter");
  set("title",""HIM"谷中"HIG"仙人"NOR"");
  set("attitude","heroism");
  set("age",1435);
  set("max_kee",10000);
  set("kee",10000);
  set("max_force",10000);
  set("force",10000);
  set("force_factor",10);
  set("combat_exp",3500000);
  set_skill("seven-steps",200);
  set_skill("dodge",200);
  set_skill("move",200);
  map_skill("dodge","seven-steps");
  map_skill("dodge","seven-steps");
  setup();
}
void init()
{
//   add_action("do_answer","answer");
        set_heart_beat(1);
}
void heart_beat()
{
        if(query("kee")<0)
        die();
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        add("kee",200);
        }
                else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}

void die()
{
     object winner = query_temp("last_damage_from");
  object god=new("/open/ping/questsfan/npc/god.c");
     if(winner->query_temp("kick")!=1)
     {
     tell_object(winner,"\n\n"HIG"無知的凡人，你聽過仙人會死嗎???"NOR"\n");
     god->move("/open/ping/questsfan/rm34.c");
     winner->set_temp("kick",1);
     ::die();
     }
     tell_object(winner,"\n\n"HIM"唉!!!你三番兩次對仙人不敬，藏仙谷不歡迎你。你走吧!!!"NOR"\n");
     tell_object(winner,""HIY"咒語："HIG"比克士 尤亞爾 斯丟比 吉奧 "NOR"\n\n");
     winner->set_temp("stupid",1);
     winner->move("/open/ping/questsfan/rm24.c");
     :: die();
}

