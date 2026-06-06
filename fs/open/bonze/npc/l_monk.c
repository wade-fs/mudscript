inherit NPC;
void create()
{
  set_name("少林武僧",({"unarmed monk","monk"}));
  set("long","一個全身肌肉的和尚，看來經過相當程度的訓練 .\n");
  set("gender","男性");
  set("combat_exp",200000);
  set("attitude","peaceful");
  set("age",22);
  set("class","bonze");
  set_skill("unarmed",70);
  set_skill("dodge",50);
  set_skill("parry",50);
  setup();
  add_money("silver",5);
}
