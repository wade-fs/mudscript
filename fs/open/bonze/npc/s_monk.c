inherit NPC;
void create()
{
  set_name("少林小僧",({"soulin monk","monk"}));
  set("long","一個努力練功\的小和尚，看來肌肉頗為健壯。\n");
  set("gender","男性");
  set("combat_exp",100000);
  set("attitude","peaceful");
  set("age",20);
  set("class","bonze");
  set_skill("unarmed",45);
  set_skill("dodge",30);
  set_skill("parry",40);
  setup();
  add_money("silver",1);
}
