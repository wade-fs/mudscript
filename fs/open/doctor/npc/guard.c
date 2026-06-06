//增加greeting函數中 遇到的物件不存在導致出問題的判斷 by blazakira 2011/4/28

#include <ansi.h>
inherit NPC;
void create()
{
  set_name("銀針門侍衛",({"guard"}));
  set("long","
滿臉和善的笑容中隱含著一股不容侵犯的威嚴，望著他不怒自威的眼神，
使得你內心的作歹念頭，一掃而空。
");
  set("gender","男性");
  set("combat_exp",60000);
  set("attitude","heroism");
  set("age",30);
  set_skill("unarmed",20);
  set_skill("dodge", 30);
  set_skill("parry", 40);
  set_skill("force", 30);
  set_skill("move",40);
  set_skill("cure",30);
  set_skill("shinnoforce",30);
  set_skill("yu-needle",50);
  set("force",300);
  set("max_force",300);
  set("force_factor",5);
  set_skill("seven-steps",30);
  map_skill("force","shinnoforce");
  map_skill("unarmed","yu-needle");
  map_skill("dodge","seven-steps");
  map_skill("move","seven-steps");
  set("race","人類");
  setup();
  add_money("silver",70);
  carry_object("/open/doctor/obj/needle3.c")->wield();
}

void greeting(object who)
{
  if(!who) return;
  if( (who->query("id") == "cccc") )
  {
    command("say 歡迎銀針門的創教大神!!");
    command("bow "+who->query("name"));
  }
  else
  {
    command("say 歡迎來到銀針門!!有興趣加入銀針門嗎??");
  }
  return;
}
