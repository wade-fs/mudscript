inherit NPC;
void create()
{
  set_name("戒律堂弟子",({"rule trainee","trainee"}));
  set("long","在羅漢堂修行的弟子，以復興少林為己任。\n");
  set("gender","男性");
  set("combat_exp",500000);
  set("attitude","peaceful");
  set("age",26);
  set("class","bonze");
  set_skill("unarmed",90);
  set_skill("dodge",80);
  set_skill("parry",80);
  setup();
  add_money("silver",8);
}
